#!/usr/bin/env python3
# /* $NeuraBSD: neura-tools/scripts/neura-doc.py, v 1.0 2026/02/07 codeakrobat Exp $ */
# /*
#  * DE: Automatisiert den Doxygen-Build und startet einen lokalen Preview-Server.
#  * EN: Automates the Doxygen build and starts a local preview server.
#  *
#  * Copyright (c) 2026, NeuraBSD / Daniel Hilbert (CodeAkrobat)
#  * License: BSD 3-Clause
#  */

import os
import subprocess
import http.server
import socketserver
import sys

# DE: Pfad-Konfiguration (Tabs = 8)
# EN: Path configuration (Tabs = 8)
BASE_DIR	= os.path.expanduser("~/neurabsd/documentation/doxygen")
HTML_DIR	= os.path.join(BASE_DIR, "html")
PORT		= 8080

def build_docs():
	print("--> NeuraBSD: Generating documentation...")
	try:
		os.chdir(BASE_DIR)
		subprocess.run(["doxygen", "Doxyfile"], check=True)
	except Exception as e:
		print(f"ERROR: Doxygen failed: {e}")
		sys.exit(1)

def serve_docs():
	try:
		if not os.path.exists(HTML_DIR):
			print(f"ERROR: {HTML_DIR} does not exist.")
			sys.exit(1)
			
		os.chdir(HTML_DIR)
		handler = http.server.SimpleHTTPRequestHandler
		socketserver.TCPServer.allow_reuse_address = True
		
		with socketserver.TCPServer(("", PORT), handler) as httpd:
			url = f"http://localhost:{PORT}"
			print(f"--> NeuraBSD: Preview available at {url}")
			print("--> Press Ctrl+C to stop the server.")
			
			# Iridium Start
			subprocess.Popen(["iridium", url], 
					 stdout=subprocess.DEVNULL, 
					 stderr=subprocess.DEVNULL)
			
			httpd.serve_forever()
	except KeyboardInterrupt:
		print("\n--> NeuraBSD: Documentation server stopped.")
		sys.exit(0)

if __name__ == "__main__":
	build_docs()
	serve_docs()
