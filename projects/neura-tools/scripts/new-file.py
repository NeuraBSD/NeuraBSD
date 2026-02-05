# $NeuraBSD: scripts/new-file.py,v 1.0 2026/02/05 19:15:00 akrobat Exp $
#
# Copyright (c) 2026 Your Name <your@email.com>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.

import sys
import os
from datetime import datetime

def create_header(filename):
	extension = filename.split('.')[-1]
	now = datetime.now().strftime("%Y/%m/%d %H:%M:%S")
	user = "akrobat" # Dein Dev-Kürzel
	
	# Header template
	header_line = f"$NeuraBSD: {filename},v 1.0 {now} {user} Exp $"
	
	license_text = (
		"Copyright (c) 2026 Your Name <your@email.com>\n"
		"Permission to use, copy, modify, and distribute this software for any\n"
		"purpose with or without fee is hereby granted, provided that the above\n"
		"copyright notice and this permission notice appear in all copies."
	)

	if extension in ['c', 'cpp', 'h', 'hpp']:
		return f"/*\n * {header_line}\n *\n * {license_text.replace('\\n', '\\n * ')}\n */\n\n"
	elif extension == 'py':
		return f"# {header_line}\n#\n# {license_text.replace('\\n', '\\n# ')}\n\n"
	else:
		return f"# {header_line}\n\n"

def main():
	if len(sys.argv) < 2:
		print("Usage: python3 new-file.py <filename.ext>")
		return

	target_file = sys.argv[1]
	
	if os.path.exists(target_file):
		print(f"Error: {target_file} already exists!")
		return

	header = create_header(target_file)
	
	with open(target_file, 'w') as f:
		f.write(header)
		# Fügen wir direkt ein Boilerplate für C/Python ein
		if target_file.endswith('.py'):
			f.write("def main():\n\tpass\n\nif __name__ == '__main__':\n\tmain()\n")
		elif target_file.endswith(('.c', '.cpp')):
			f.write("#include <stdio.h>\n\nint main(int argc, char *argv[])\n{\n\treturn 0;\n}\n")

	print(f"Successfully created {target_file} with NeuraBSD header.")

if __name__ == "__main__":
	main()