from cs50 import get_string, get_int

def main():
    # Prompt and validate user input
    while True:
        height = get_int("Height: ")
        if (height > 0 and height <= 8):
            break
    
    # Draw the half pyramid
    for line in range(height):
        space = height - line
        while (space > 1):
            print(" ", end="")
            space -= 1
        for hash in range(line + 1):
            print("#", end="")
        print("  ", end="")
        for hash in range(line + 1):
            print("#", end="")
        print()

if __name__ == "__main__":
    main()
