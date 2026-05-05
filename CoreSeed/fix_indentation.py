# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/20 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


# $NeuraBSD: ./fix_indentation.py, v 1.0 2026/02/19 codeakrobat Exp $
#
 * DE: Modul des NeuraBSD Projekts.
 * EN: Module of the NeuraBSD project.
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause


#!/usr/bin/env python3
# $NeuraBSD: scripts/fix_indentation.py, v 1.0 2026/02/19 CodeAkrobat Exp $
# DE: Korrigiert Einrückungen auf Hard Tabs (8 Zeichen) gemäß OpenBSD-Standard.
# EN: Corrects indentation to Hard Tabs (8 characters) per OpenBSD standard.

import os

def fix_file(filepath):
    with open(filepath, 'r') as f:
	lines = f.readlines()
    
    with open(filepath, 'w') as f:
	for line in lines:
	    # Ersetzt 4 oder 8 Spaces am Anfang durch einen/zwei Tabs
	    # und stellt sicher, dass Hard Tabs genutzt werden.
	    new_line = line.replace('    ', '\t').replace('     ', '\t\t')
	    f.write(new_line)
    print(f"[Neura-Fix] {filepath} angepasst.")

for root, dirs, files in os.walk('src'):
    for file in files:
	if file.endswith(('.cpp', '.hpp', '.qml')):
	    fix_file(os.path.join(root, file))
