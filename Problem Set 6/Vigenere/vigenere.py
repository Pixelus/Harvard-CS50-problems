# Program to encrypt a message using the Caesar cipher 

import sys 
from cs50 import get_string

def main():
    # Check keyword from command line argument
    while len(sys.argv) != 2:
        sys.exit("Usage: python sys.argv[1] keyword")
            
    # Check argument to make sure all characters are alphabetical
    if sys.argv[1].isalpha() == False:
        sys.exit("Usage: python sys.argv[1] keyword")
        
    # Prompt user for plaintext
    plaintext = get_string("plaintext: ")
        
    # Create a list for ciphertext characters
    ciphertext = []
    key_index = 0
        
    # Encipher each character in the plaintext string
    for c in plaintext:
        if c.isalpha():
            key = ord(sys.argv[1][key_index % len(sys.argv[1])].lower()) - 97
            key_index += 1
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
