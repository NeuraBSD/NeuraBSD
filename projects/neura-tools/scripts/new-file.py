# $NeuraBSD: scripts/new-file.py,v 1.1 2026/02/05 19:45:00 CodeAkrobat Exp $
#
# Author: Daniel Hilbert <lead@neurabsd.org>
# Copyright (c) 2026 NeuraBSD Project
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.

import sys
import os
from datetime import datetime

def create_header(filename):
	"""
	Generates the NeuraBSD compliant header based on file extension.
	Uses Hard Tabs (8 chars) for alignment.
	"""
	extension = filename.split('.')[-1].lower()
	now = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
	
	# User & Project Info
	user = "CodeAkrobat"
	author_name = "Daniel Hilbert"
	author_email = "lead@neurabsd.org"
	
	# RCS Tag Line
	rcs_tag = f"$NeuraBSD: {filename},v 1.0 {now} {user} Exp $"
	
	# License Template
	license_text = (
		f"Author: {author_name} <{author_email}>\n"
		"Copyright (c) 2026 NeuraBSD Project\n\n"
		"Permission to use, copy, modify, and distribute this software for any\n"
		"purpose with or without fee is hereby granted, provided that the above\n"
		"copyright notice and this permission notice appear in all copies."
	)

	# C / C++ Style (Block comments)
	if extension in ['c', 'cpp', 'h', 'hpp']:
		commented_license = license_text.replace('\n', '\n * ')
		return f"/*\n * {rcs_tag}\n *\n * {commented_license}\n */\n\n"
	
	# Python / Shell Style (Hash comments)
	elif extension in ['py', 'sh']:
		commented_license = license_text.replace('\n', '\n# ')
		return f"# {rcs_tag}\n#\n# {commented_license}\n\n"
	
	# Default / Markdown
	else:
		return f"# {rcs_tag}\n\n"

def main():
	if len(sys.argv) < 2:
		print("Usage: python3 new-file.py <filename.ext>")
		sys.exit(1)

	target_file = sys.argv[1]
	
	if os.path.exists(target_file):
		print(f"Error: File '{target_file}' already exists!")
		sys.exit(1)

	header_content = create_header(target_file)
	
	try:
		with open(target_file, 'w') as f:
			f.write(header_content)
			
			# Add basic boilerplate for development speed
			if target_file.endswith('.py'):
				f.write("def main():\n\t# TODO: Implementation\n\tpass\n\n"
						"if __name__ == '__main__':\n\tmain()\n")
			
			elif target_file.endswith(('.c', '.cpp')):
				f.write("#include <stdio.h>\n\n"
						"int\nmain(int argc, char *argv[])\n{\n"
						"\t/* Code starting with Hard Tabs */\n"
						"\treturn (0);\n}\n")
				
			elif target_file.endswith('.sh'):
				# Adding Shebang for shell scripts
				content = "#!/bin/sh\n" + header_content
				f.seek(0)
				f.write(content)

		print(f"Successfully created: {target_file}")
		print(f"Standard: NeuraBSD Hybrid (Hard Tabs 8)")

	except Exception as e:
		print(f"Failed to create file: {e}")

if __name__ == "__main__":
	main()