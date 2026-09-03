#include <iostream>
#include <iomanip>
#include <string>

// Item struct
struct Item {
    std::string slotCode;
    std::string name;
    int priceCents;
    int quantity;
};

// Function prototypes
void displayInventory(const Item inventory[], int num_Items);
int getCoins();
void printChangeBreakCode(int changeCents);
void processSelection(Item inventory[], int num_Items, int user_credit);

int main() {
    const int NUM_ITEMS = 6;

    Item inventory[NUM_ITEMS] = {
        {"A1", "Pretzels", 125, 10},
        {"A2", "Trail Mix", 100, 5},
        {"A3", "Cola", 75, 8},
        {"B1", "Water", 150, 12},
        {"B2", "Juice", 200, 6},
        {"B3", "Gum", 50, 20}
    };

    bool running = true;

    while (running) {
        displayInventory(inventory, NUM_ITEMS);

        int user_credit = getCoins();

        if (user_credit > 0) {
            processSelection(inventory, NUM_ITEMS, user_credit);
        } else {
            std::cout << "Payment cancelled.\n";
        }

        std::cout << "\nServe another customer? (y/n): ";
        char again;
        std::cin >> again;
        if (again == 'n' || again == 'N') {
            running = false;
        }
    }

    return 0;
}

// Display inventory
void displayInventory(const Item inventory[], int num_Items) {
    std::cout << "\n=== VENDING MACHINE ===\n";
    std::cout << std::left;

    for (int i = 0; i < num_Items; ++i) {
        std::cout << std::setw(4) << inventory[i].slotCode
                  << std::setw(12) << inventory[i].name
                  << "$" << std::fixed << std::setprecision(2)
                  << (inventory[i].priceCents / 100.0) << "   ";

        if (inventory[i].quantity > 0)
            std::cout << inventory[i].quantity << " left\n";
        else
            std::cout << "SOLD OUT\n";
    }
    std::cout << std::endl;
}

// Coin insertion
int getCoins() {
    int user_credit = 0;
    int coinInput = -1;

    while (true) {
        std::cout << "Insert coin (5/10/25/100) or 0 to stop: ";
        if (!(std::cin >> coinInput)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (coinInput == 0)
            break;

        if (coinInput == 5 || coinInput == 10 || coinInput == 25 || coinInput == 100) {
            user_credit += coinInput;
            std::cout << "Credit: $" << std::fixed << std::setprecision(2)
                      << (user_credit / 100.0) << "\n";
        } else {
            std::cout << "Invalid coin.\n";
        }
    }

    return user_credit;
}

// Change breakdown
void printChangeBreakCode(int changeCents) {
    int quarters = changeCents / 25;
    changeCents %= 25;

    int dimes = changeCents / 10;
    changeCents %= 10;

    int nickels = changeCents / 5;
    changeCents %= 5;

    if (quarters > 0) std::cout << "Quarters: " << quarters << "\n";
    if (dimes > 0) std::cout << "Dimes: " << dimes << "\n";
    if (nickels > 0) std::cout << "Nickels: " << nickels << "\n";
}

// Selection processing
void processSelection(Item inventory[], int num_Items, int user_credit) {
    std::string selectedSlot;
    std::cout << "Select slot: ";
    std::cin >> selectedSlot;

    bool itemFound = false;

    for (int i = 0; i < num_Items; ++i) {
        if (inventory[i].slotCode == selectedSlot) {
            itemFound = true;

            if (inventory[i].quantity == 0) {
                std::cout << "Sorry — " << selectedSlot << " is SOLD OUT.\n";
                std::cout << "Refunding $" << std::fixed << std::setprecision(2)
                          << (user_credit / 100.0) << ":\n";
                printChangeBreakCode(user_credit);
                return;
            }

            if (user_credit < inventory[i].priceCents) {
                std::cout << "Insufficient funds.\n";
                std::cout << "Refunding $" << std::fixed << std::setprecision(2)
                          << (user_credit / 100.0) << ":\n";
                printChangeBreakCode(user_credit);
                return;
            }

            // Successful purchase
            inventory[i].quantity--;
            int change = user_credit - inventory[i].priceCents;

            std::cout << "\n=== RECEIPT ===\n";
            std::cout << "Item:   " << inventory[i].name << "\n";
            std::cout << "Price:  $" << std::fixed << std::setprecision(2)
                      << (inventory[i].priceCents / 100.0) << "\n";
            std::cout << "Paid:   $" << std::fixed << std::setprecision(2)
                      << (user_credit / 100.0) << "\n";
            std::cout << "Change: $" << std::fixed << std::setprecision(2)
                      << (change / 100.0) << "\n";

            printChangeBreakCode(change);
            std::cout << "Thank you!\n";
            return;
        }
    }

    if (!itemFound) {
        std::cout << "Invalid slot code.\n";
        std::cout << "Refunding $" << std::fixed << std::setprecision(2)
                  << (user_credit / 100.0) << ":\n";
        printChangeBreakCode(user_credit);
    }
}