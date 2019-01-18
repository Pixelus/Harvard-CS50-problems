#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    float dollars;
    int coins = 0, quarter = 25, dime = 10, nickel = 5, penny = 1;

    // Prompt user for an amount of change
    do
    {
        dollars = get_float("Change: ");
    } 
    while (dollars < 0);

    // Convert amount: dollars to cents in an interger, and round amount
    int amount = round(dollars * 100);

    // Use the largest coin possible and keep in track of coins used
    // While quarters can be used
    while (amount >= quarter)
    {
        // Increase count
        coins += 1;
        // Decrease amount by a quarter
        amount -= quarter;
    }
    // While dimes can be used
    while (amount >= dime)
    {
        coins += 1;
        amount -= dime;    
    }
    // While nickels can be used
    while (amount >= nickel)
    {
        coins += 1;
        amount -= nickel;    
    }
    // While pennies can be used
    while (amount >= penny)
    {
        coins += 1;
        amount -= penny;    
    }

    // Print the final number of coins
    printf("I have %i coin(s).\n", coins);
}
