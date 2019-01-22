from cs50 import get_float, get_int

def main():
    # Define variables
    coins = 0
    quarter = 25
    dime = 10
    nickel = 5
    penny = 1
    
    # Prompt user for an amount of change
    while True:
        dollars = get_float("Change: ")
        if dollars > 0:
            break
    
    # Convert amount: dollars to cents in an interger, and round amount
    amount = round(dollars * 100)
    
    # Use the largest coin possible and keep in track of coins used
    while (amount >= quarter):
        coins += 1
        amount -= quarter
    while (amount >= dime):
        coins += 1
        amount -= dime
    while (amount >= nickel):
        coins += 1
        amount -= nickel
    while (amount >= penny):
        coins += 1
        amount -= penny
    
    # Print the final number of coins
    print(f"I have {coins} coin(s).")

if __name__ == "__main__":
    main()
