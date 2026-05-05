#!/usr/bin/env python3
# /* $NeuraBSD: neura-tools/scripts/new-file.py, v 1.0 2026/02/07 codeakrobat Exp $ */
# /*
#  * DE: Skript zum automatischen Erstellen von Dateien mit NeuraBSD-Header.
#  * EN: Script to automatically create files with the NeuraBSD header.
#  *
#  * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
#  * License: BSD 3-Clause
#  */

import sys
import os
from datetime import datetime

def create_file(filepath):
	filename = os.path.basename(filepath)
	ext = os.path.splitext(filename)[1]
	date_str = datetime.now().strftime("%Y/%m/%d")
	
	# Header-Logik basierend auf der Dateiendung
	if ext in ['.cpp', '.hpp', '.h', '.c']:
		header = f"""/* $NeuraBSD: {filepath}, v 1.0 {date_str} codeakrobat Exp $ */
/*
 * DE: [Beschreibung einfügen]
 * EN: [Insert description]
 *
 * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
 * License: BSD 3-Clause
 */

"""
	elif ext == '.py':
		header = f"""#!/usr/bin/env python3
# /* $NeuraBSD: {filepath}, v 1.0 {date_str} codeakrobat Exp $ */
# /*
#  * DE: [Beschreibung einfügen]
#  * EN: [Insert description]
#  *
#  * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
#  * License: BSD 3-Clause
#  */

"""
	else:
		print(f"Fehler: Dateityp {ext} wird nicht unterstützt.")
		return

	if os.path.exists(filepath):
		print(f"Fehler: Datei {filepath} existiert bereits!")
		return

	with open(filepath, 'w') as f:
		f.write(header)
	
	print(f"--> NeuraBSD: Datei {filepath} erfolgreich erstellt.")

if __name__ == "__main__":
	if len(sys.argv) < 2:
		print("Nutzung: new-file.py <pfad/zu/datei.ext>")
	else:
		create_file(sys.argv[1])
