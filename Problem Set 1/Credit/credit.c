#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cc_number, card_number;
    int second_last_digit, second_digit_sum, first_digit_sum, last_digit;
    int digit = 0, sum = 0, second_sum = 0, final_sum = 0, count = 0;
    
    // Prompt for user input's number card
    do 
    { 
        cc_number = get_long("Number: ");
    }
    while (cc_number <= 13 && cc_number > 16);
    
    // Copy the credit card number
    card_number = cc_number;
    
    // Checksum number card with Luhn's Algorithm
    for (int i = 1; i <= card_number; i++)
    {
        // Multiply every one in two digit by 2, starting at second to last digit
        second_last_digit = ((card_number % 100) - (card_number % 10)) / 10;
        card_number /= 100;
        // Count the digits
        count++;
            
        // Add digits of product > 10
        if (second_last_digit < 5)
        {
            digit = second_last_digit * 2; 
            count++;
        }
        else
        {
            first_digit_sum = (second_last_digit * 2) / 10;
            second_digit_sum = (second_last_digit * 2) % 10;
            digit = first_digit_sum + second_digit_sum;    
            count++;
        }
        
        // Add those product digits together
        sum += digit;
            
        // Add the sum to the sum of the digits that weren't multiplied by 2
        last_digit = card_number % 10; 
        second_sum += last_digit;
    }
    
    // Validate checksum
    final_sum = sum + second_sum + cc_number % 10;  
    
    // Find the card's first number
    for (int i = 1; i <= cc_number; i++)
    {
        while (cc_number > 100) 
        {
            cc_number /= 10;
        }
    }
    
    // If the last digit is 0, number is valid
    if ((final_sum % 10 == 0) && (count >= 12 && count <= 16))
    {
        // Validate number's length and company's identifier
        if ((count == 14) && (cc_number == 34 || cc_number == 37))
        {
            printf("AMEX\n");    
        }
        if ((count == 12 || count == 16) && (cc_number / 10 == 4))
        {
            printf("VISA\n");    
        }
        if ((count == 16) && (cc_number == 51 || cc_number == 52 || cc_number == 53 || cc_number == 54 || cc_number == 55))
        {
            printf("MASTERCARD\n"); 
        } 
        else 
        {
            printf("INVALID\n");    
        }
    } 
    else 
    {
        printf("INVALID\n");    
    }
}
