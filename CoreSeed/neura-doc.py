#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $NeuraBSD: scripts/neura-doc.py, v 1.3 2026/02/19 codeakrobat Exp $

import os
import re
from datetime import datetime

def fix_content(filepath):
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            lines = f.readlines()
    except Exception:
        return

    # 1. Hard-Tabs (8 Zeichen) für die Ziel-Datei erzwingen
    processed_lines = []
    for line in lines:
        # Erst auf 8 Spaces normieren, dann 8 Spaces durch 1 Tab ersetzen
        temp_line = line.expandtabs(8)
        new_line = temp_line.replace('        ', '\t')
        processed_lines.append(new_line)

    content = "".join(processed_lines)
    
    # 2. Header-Logik
    filename = os.path.basename(filepath)
    rel_path = filepath.split("CoreSeed/")[-1] if "CoreSeed/" in filepath else filepath
    current_date = datetime.now().strftime("%Y/%m/%d")
    
    is_py = filepath.endswith('.py')
    comment_char = "#" if is_py else "/*"
    comment_end = "" if is_py else " */"
    
    header_pattern = r"(\#|/\*) \$NeuraBSD: .* \$ (\*/|)"
    header_template = f"{comment_char} $NeuraBSD: {rel_path}, v 1.0 {current_date} codeakrobat Exp ${comment_end}"
    
    # Clause (8-Tab-kompatibel eingerückt)
    clause_text = f"{comment_char}\n * DE: Modul des NeuraBSD Projekts.\n * EN: Module of the NeuraBSD project.\n *\n * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)\n * License: BSD 3-Clause\n{comment_end}"

    # 3. Header ersetzen oder einfügen
    if re.search(header_pattern, content):
        content = re.sub(header_pattern, header_template, content)
    else:
        content = header_template + "\n" + clause_text + "\n\n" + content

    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)
    print(f"[*] {filename}: Standard angewendet.")

def walk_tree(root_dir):
    extensions = ('.cpp', '.hpp', '.h', '.py')
    for root, dirs, files in os.walk(root_dir):
        # Verzeichnisse wie .git oder build-Ordner ignorieren
        dirs[:] = [d for d in dirs if not d.startswith('.')]
        for file in files:
            if file.endswith(extensions):
                # Das Skript selbst nicht während des Laufs verändern, 
                # um Schreibkonflikte zu vermeiden
                if file != "neura-doc.py":
                    fix_content(os.path.join(root, file))

if __name__ == "__main__":
    print("--- NeuraBSD Doc-Fixer v1.3 (Hard-Tab 8) ---")
    walk_tree('.')
    print("--- Fertig: Alle Dateien normiert. ---")
