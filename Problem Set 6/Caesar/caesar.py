# Program to encrypt a message using the Caesar cipher 

import sys 
from cs50 import get_string

def main():
    # Check key from command line argument
    while len(sys.argv) != 2:
        sys.exit("Usage: python sys.argv[1] key")
        
    # Check command line argument
    for c in sys.argv[1]:
        # Check argument to make sure all characters are digits
        if c.isalpha():
            sys.exit("Usage: python sys.argv[1] key")
    
    # Turn key into integer
    key = int(sys.argv[1])
    
    # Prompt user for plaintext
    plaintext = get_string("plaintext: ")
    
    # Create a list for ciphertext characters
    ciphertext = []
    
    # Encipher each character in the plaintext string
    for c in plaintext:
        if c.isalpha():
            ciphertext.append(cipher(c, key))
        else:
            ciphertext.append(c)
    
    # Print ciphertext
    print("ciphertext: ", end='')
    print("".join(ciphertext))

def cipher(c, key):
    if c.isupper():
        return chr(((ord(c) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(c) - 97 + key) % 26) + 97)

if __name__ == "__main__":
    main()
