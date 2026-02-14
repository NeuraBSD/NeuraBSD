import os

def fix_file(filepath):
    with open(filepath, 'r') as f:
        lines = f.readlines()
    
    indent = 0
    new_lines = []
    for line in lines:
        line = line.strip()
        if not line:
            new_lines.append("\n")
            continue
            
        # Verringere Einrückung bei schließenden Klammern VOR der Zeile
        if line.startswith('}') or line.startswith(']'):
            indent -= 1
            
        new_lines.append("\t" * max(0, indent) + line + "\n")
        
        # Erhöhe Einrückung bei öffnenden Klammern NACH der Zeile
        if line.endswith('{') or line.endswith('[') or line.endswith('public:') or line.endswith('protected:') or line.endswith('private:'):
            indent += 1
            
    with open(filepath, 'w') as f:
        f.writelines(new_lines)

# Verzeichnisse scannen
for root, dirs, files in os.walk('CoreSeed/src'):
    for file in files:
        if file.endswith(('.cpp', '.hpp')):
            print(f"Fixing tabs in: {file}")
            fix_file(os.path.join(root, file))
