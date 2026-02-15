import PIL.Image as Image
import sys
import os

def convert_to_header(input_png, output_h):
    img = Image.open(input_png).convert('RGB')
    width, height = img.size
    
    if width != 800 or height != 600:
        print(f"Warnung: Bildgröße ist {width}x{height}, erwartet wurde 800x600!")

    with open(output_h, 'w') as f:
        f.write("/* Auto-generated splash screen for DaemonPath */\n")
        f.write("#include <stdint.h>\n\n")
        f.write(f"#define SPLASH_WIDTH {width}\n")
        f.write(f"#define SPLASH_HEIGHT {height}\n\n")
        f.write("const uint32_t splash_data[] = {\n")
        
        for y in range(height):
            line = "    "
            for x in range(width):
                r, g, b = img.getpixel((x, y))
                # Packen in 0xRRGGBB Format
                pixel = (r << 16) | (g << 8) | b
                line += f"0x{pixel:06x}, "
            f.write(line + "\n")
        
        f.write("};\n")

if __name__ == "__main__":
    convert_to_header('boot_splash_800x600.png', 'splash_data.h')
    print("splash_data.h erfolgreich erstellt.")