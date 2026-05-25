/******************************************************************************
# Author:           Andy Joy
# Assignment:       Assignment 6
# Date:             05/23/2026
# Description:      This program 
# Input:            numPeople (int), avgSlices (double), costPizza (double),
#                   choice (char).
# Output:           numPizzas (int), costPizzas (double), costTax (double)
# Sources:          Sample 6 Code.
#******************************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Constants
const double DRINK_COST = 0.25;

int main() {
  
  // Declare variables
  int coinVal;
  double balance;
  char drinkChoice;
  int numDrinks;
  double totalCost;

  cout << "Welcome to my Coffee/Tea Vending Machine!" << endl;
  
  // Loop to accept coin input until the user enters 0
  do {
    cout << "\nEnter coins - 5, 10, or 25 only: ";
    cin >> coinVal;
  
    // Input validation for coinVal
    while(!cin)
    {
      cout << "\nInvalid value! Please try again!" << endl;
      cin.clear();
      cin.ignore(100, '\n');
      cout << "\nEnter coins - 5, 10, or 25 only: ";
      cin >> coinVal;
    }

    while(coinVal != 0 && coinVal != 5 && coinVal != 10 && coinVal != 25)
    {
      cout << "\nInvalid value! Please try again!" << endl;
      cout << "\nEnter coins - 5, 10, or 25 only: ";
      cin >> coinVal;

      while(!cin)
      {
        cout << "\nInvalid entry! Please try again!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nEnter coins - 5, 10, or 25 only: ";
        cin >> coinVal;
      }
    }

    if (coinVal == 5 || coinVal == 10 || coinVal == 25) {
      balance += coinVal / 100.0; // Convert cents to dollars
    }

  } while (coinVal != 0);

  cout << "\nYour balance is $" << fixed << setprecision(2) << balance << endl;

  // Display drink menu
  cout << "\nPlease pick an option ($0.25 each): " << endl;
  cout << "    C/c: Coffee" << endl;
  cout << "    T/t: Tea" << endl;
  cout << "    Q/q: Quit" << endl;

  // Drink choice input validation
  do {
  cin >> drinkChoice;

  if (drinkChoice != 'C' && drinkChoice != 'c' && drinkChoice != 'T' && drinkChoice != 't' && drinkChoice != 'Q' && drinkChoice != 'q') {
    cout << "\nInvalid Option! Please choose a valid option!" << endl;
  }
  } while (drinkChoice != 'C' && drinkChoice != 'c' && drinkChoice != 'T' && drinkChoice != 't' && drinkChoice != 'Q' && drinkChoice != 'q');

  switch (drinkChoice) {

    case 'C':
    case 'c':
      cout << "How many would you like?" << endl;
      cin >> numDrinks;
      while (!cin)
      {
        cout << "\nInvalid Option! Please try again!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nHow many would you like?" << endl;
        cin >> numDrinks;
      }
      while (numDrinks < 0)
      {
        cout << "\nInvalid Option! Please try again!" << endl;
        cout << "\nHow many would you like?" << endl;
        cin >> numDrinks;
      }
      if (balance >= numDrinks * DRINK_COST) {
        cout << "\nYour total: $" << fixed << setprecision(2) << numDrinks * DRINK_COST << endl;
        cout << "Your balance: $" << fixed << setprecision(2) << balance - (numDrinks * DRINK_COST) << endl;
        break;
      }
      else {
        cout << "\nInsufficient balance!" << endl;
        break;
      }

    case 'T':
    case 't':
      cout << "\nHow many would you like?" << endl;
      cin >> numDrinks;
      while (!cin)
      {
        cout << "\nInvalid Option! Please try again!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nHow many would you like?" << endl;
        cin >> numDrinks;
      }
      while (numDrinks < 0)
      {
        cout << "\nInvalid Option! Please try again!" << endl;
        cout << "\nHow many would you like?" << endl;
        cin >> numDrinks;
      }
      if (balance >= numDrinks * DRINK_COST) {
        cout << "\nYour total: $" << fixed << setprecision(2) << numDrinks * DRINK_COST << endl;
        cout << "Your balance: $" << fixed << setprecision(2) << balance - (numDrinks * DRINK_COST) << endl;
        break;
      }
      else {
        cout << "\nInsufficient balance!" << endl;
        break;
      }
    
    case 'Q':
    case 'q':
      break;
    }


  cout << "\nThank you for using my Vending Machine Program!" << endl;

  return 0;
}


/* sample run:
Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.80

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> k
Invalid Option! Please choose a valid option!
>> 9
Invalid Option! Please choose a valid option!
>> c
How many would you like?
>> f
Invalid Option!
How many would you like?
>> 2

Your total: $0.50
Your balance: $0.30

Thank you for using my Vending Machine Program!
*/