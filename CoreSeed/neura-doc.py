#!/usr/bin/env python3
# $NeuraBSD: CoreSeed/neura-doc.py, v 1.3 2026/02/16 CodeAkrobat Exp $
#
# DE: Automatisierungstool für Doxygen-Dokumentation und Projekt-Cleanup.
# EN: Automation tool for Doxygen documentation and project cleanup.
#
# Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
# License: BSD 3-Clause

import os
import subprocess

# DE: Projekt-Wurzelverzeichnis
# EN: Project root directory
PROJECT_ROOT = "/home/codeakrobat/NeuraBSD/CoreSeed"

def cleanup():
    """
    DE: Entfernt Binär-Reste (.o, .moc.o) aus den Quellcode-Ordnern.
    EN: Removes binary artifacts (.o, .moc.o) from source directories.
    """
    print("--- [ Neura-Cleanup ] ---")
    src_path = os.path.join(PROJECT_ROOT, "src")
    count = 0
    
    if not os.path.exists(src_path):
        print(f"DE: Pfad nicht gefunden: {src_path}")
        return

    for root, dirs, files in os.walk(src_path):
        for file in files:
            # DE: Wir entfernen Objekt-Dateien, um saubere Builds zu garantieren
            # EN: We remove object files to guarantee clean builds
            if file.endswith((".o", ".moc.o", ".obj")):
                full_path = os.path.join(root, file)
                try:
                    os.remove(full_path)
                    print(f"Deleted: {file}")
                    count += 1
                except OSError as e:
                    print(f"Error: {e}")
    
    print(f"DE: {count} Dateien bereinigt. / EN: {count} files cleaned.")

def run_doxygen():
    """
    DE: Startet den Doxygen-Prozess zur Generierung der Website-Doku.
    EN: Starts the Doxygen process for generating website documentation.
    """
    print("\n--- [ Neura-Doxygen ] ---")
    doxyfile_path = os.path.join(PROJECT_ROOT, "Doxyfile")
    
    if not os.path.exists(doxyfile_path):
        print(f"DE: Fehler: Doxyfile fehlt in {PROJECT_ROOT}")
        return

    os.chdir(PROJECT_ROOT)
    try:
        # DE: Führt Doxygen mit der konfigurierten Doxyfile aus
        # EN: Executes Doxygen with the configured Doxyfile
        subprocess.run(["doxygen", "Doxyfile"], check=True)
        print("DE: Doxygen-Dokumentation wurde erfolgreich erstellt.")
        print("EN: Doxygen documentation created successfully.")
    except FileNotFoundError:
        print("DE: Fehler: 'doxygen' nicht im Pfad. (pkg_add doxygen?)")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    cleanup()
    run_doxygen()
    print("\n--- [ Status ] ---")
    print("DE: Dokumentation bereit unter: documentation/html/index.html")
    print("EN: Documentation ready at: documentation/html/index.html")
