/* Program to encrypt a message using the Vigenere cipher */

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string keyword = argv[1];
    
    // Check key from command line argument
    while (argc != 2)
    {
        printf("Usage: %s keyword\n", argv[0]);   
        return 1;
    }
    
    // Check command line argument
    for (int i = 0; i < strlen(keyword); i++)
    {
        // Check argument to make sure all characters are alphabetical
        if (!isalpha(keyword[i]))
        {
            printf("Usage: %s keyword\n", argv[0]);   
            return 1; 
        }
    }
    
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encipher each character in the plaintext string
    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        // Get key for the current letter
        int key = tolower(keyword[j % strlen(keyword)]) - 97;
        
        // If character is an uppercase character
        if (isupper(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] + key - 65) % 26) + 65);
            j++;
        }
        // If character is a lowercase character
        if (islower(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] + key - 97) % 26) + 97);
            j++;
        }
        // If character is symbol character
        if (ispunct(plaintext[i]))
        {
            plaintext[i] = plaintext[i];
        }
    }
    
    // Print ciphertext
    printf("ciphertext: %s\n", plaintext);
}
