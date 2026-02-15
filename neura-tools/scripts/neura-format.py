#!/usr/bin/env python3
import os

def fix_format(filepath):
    try:
        with open(filepath, 'r') as f:
            lines = f.readlines()
        
        new_lines = []
        indent = 0
        for line in lines:
            line = line.strip()
            if not line:
                new_lines.append("\n")
                continue
            
            # Verringere Einrückung vor der Zeile, wenn sie mit } schließt
            if line.startswith('}') or line.startswith('};'):
                indent = max(0, indent - 1)
            
            #prefix = echter Tabulator \t
            prefix = "\t" * indent
            new_lines.append(prefix + line + "\n")
            
            # Erhöhe Einrückung für die NÄCHSTE Zeile
            if line.endswith('{') or line.endswith('public:') or line.endswith('private:'):
                indent += 1
                
        with open(filepath, 'w') as f:
            f.writelines(new_lines)
    except Exception as e:
        print(f"Fehler in {filepath}: {e}")

if __name__ == "__main__":
    # Alle relevanten Verzeichnisse scannen
    for root, dirs, files in os.walk("src"):
        for file in files:
            if file.endswith((".cpp", ".hpp")):
                fix_format(os.path.join(root, file))
    print("NeuraBSD: Formatierung abgeschlossen (Hard-Tabs angewendet).")
