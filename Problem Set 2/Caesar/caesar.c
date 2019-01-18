/* Program to encrypt a message using the Caesar cipher */

#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string argument = argv[1];
    int key;
    
    // Check key from command line argument
    while (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);   
        return 1;
    }
    
    // Check command line argument
    for (int i = 0; i < strlen(argument); i++)
    {
        // Check argument to make sure all characters are digits
        if (isalpha(argument[i]))
        {
            printf("Usage: %s key\n", argv[0]);   
            return 1;
        }
        else
        {
            // Turn key into integer
            key = atoi(argument); 
        }
    }
        
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    
    // Encipher each character in the plaintext string
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // If character is an uppercase character
        if (isupper(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] + key - 65) % 26) + 65);
        }
        // If character is a lowercase character
        if (islower(plaintext[i]))
        {
            plaintext[i] = (((plaintext[i] + key - 97) % 26) + 97);
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
