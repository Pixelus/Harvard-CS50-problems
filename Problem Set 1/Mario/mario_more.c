#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do 
    {
        height = get_int("Height: ");
    } 
    while (height < 1 || height > 8);
    for (int line = 0; line < height; line++) 
    {
        for (int space = (height - line); space > 1; space--) 
        {
            printf("%c", 32); // caractère espace    
        } 
        for (int hash = 0; hash <= line; hash++) 
        {
            printf("#");
        }
        printf("  ");
        for (int hash = 0; hash <= line; hash++) 
        {
            printf("#");
        }
        printf("\n");
    }
}
