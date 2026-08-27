#include <iostream>
#include <iomanip>
#include <string>


//Declare a struct to hold the slotCode, name, priceCents, and quantity of an item

struct Item {
    std::string slotCode;
    std::string name;
    int priceCents;
    int quantity; 
};

//Declare the Prototype functions for the menu and the display of items, getCoins,  printChangeBreakCode, and processSelection
void displayInventory (const Item inventory[], int num_Items);
int getCoins();
void printChangeBreakCode(int changeCents);
void processSelection(Item inventory[], int num_Items, int user_credit);



int main() {
    CONST int NUM_ITEMS = 6;
    item inventory[NUM_ITEMS] = {
        {"A1", "Soda", 125, 10},
        {"A2", "Chips", 100, 5},
        {"A3", "Candy", 75, 8},
        {"B1", "Water", 150, 12},
        {"B2", "Juice", 200, 6},
        {"B3", "Gum", 50, 20}
    }

    displayInventory(inventory, NUM_ITEMS);

    int user_credit = getCoins();
    if (user_credit > 0) {
        processSelection(inventory, NUM_ITEMS, user_credit);
    } else {
        std::cout << "Payment cancelled" << std::endl;
    }
    return 0;
}

//Dislplay the VENDING MACHINE inventory in a table format with the slotCode, name, price, and quantity of each item
void displayInventory (Const Item inventory[], int num_Items) {
    std::cout << "===VENDING MACHINE" << std::endl;
    for 0(int i = 0; i < num_Items; ++i) {
    std::cout << std::left << std::setw(4) << inventory[i].slotCode
              << std::setw(12) << inventory[i].name
              "$" << std::fixed << std::setprecision(2) << (inventory[i].priceCents / 100.0)
              << " ";
                
              if(inventory[i].quantity > 0) {
                  std::cout << inventory[i].quantity << "left \n";
              } else {
                  std::cout << "SOLD OUT" << std::endl;
              }

        }
        std::cout << std::endl;
    }


int getCoins() {
    int user_credit = 0;
    int coinInput = -1;
    do{
        std::cout << "Please insert coin (5/10/25/100) or 0 to stop: ";
        std::cin >> coinInput;
        if (coinInput == 5 || coinInput == 10 || coinInput == 25 || coinInput == 100) {
            user_credit += coinInput;
            std::cout << "Credit $" std::fixed << std::setprecision(2) << (user_credit / 100.0) << std::endl;
        } else if (coinInput != 0) {
            std::cout << "Invalid coin. Please try again." << std::endl;
        }
        while (coinInput != 0);

        return user_credit;
    }

}

void printChangeBreakCode(int changeCents) {
    int quarters = changeCents / 25;
    changeCents %= 25;
    int dimes = changeCents / 10;
    changeCents %= 10;
    int nickels = changeCents / 5;      
    changeCents %= 5;

    if (quarters >0) {
        std::cout << "Quarters: " << quarters << std::endl;
    }
    if (dimes > 0) {
        std::cout << "Dimes: " << dimes << std::endl;
    }
    if (nickels > 0) {
        std::cout << "Nickels: " << nickels << std::endl;
    }
}

void ProcessSelection(Item inventory[], int num_Items, int user_credit) {
std::string selectedSlot;
std::cout << "Please select slot: ";
std::cin >> slectedSlot;
bool itemFound = false;

for (int i = 0 < numItems; ++i) {
if (inventory[i].slotCode == selectedSlot) {
itemFound = true;
if (inventory[i].quantity > 0) {
    std::cout << "Sorry - " << selectedSlot << " is SOLD OUT" << std::endl;
    std::cout << "Refunding $" << std::fixed << std::setprecision(2) << (user_credit / 100.0) << ":\n";
    printChangeBreakCode(user_credit);
} else if (user_credit < inventory[i].priceCents) {
    std::cout << "Insufficient funds." << ":\n";
    std::cout << "Refunding $" << std::fixed << std::setprecision(2) << (user_credit / 100.0) << ":\n";
    printChangeBreakCode(user_credit);
} else {
    int change = user_credit - inventory[i].priceCents;
    inventory[i].quantity--;
}

    //Display the Receipt with the item name, price, and change returned
std::cout << "Item:       " << inventory[i].name << "\n";
std::cout << "Price:      $" << std::fixed << std::setprecision(2) << (inventory[i].priceCents / 100.0) << "\n";
std::cout << "Amount:     $" << std::fixed << std::setprecision(2) << (change / 100.0) << "\n";
std::cout << "Change:     $" << std::fixed << std::setprecision(2) << (change / 100.0) << "\n";
    printChangeBreakCode(change);
    std::cout << "Thank you!" << std::endl;
    }
    break;
}
    if (!itemdfound){
        std::cout << "Invalid slot code" << "\n";
        std::cout << "Refunding $" << std::fixed << std::setprecision(2) << (user_credit / 100.0) << ":\n";
        printChangeBreakCode(user_credit);
        }
    } 







    
