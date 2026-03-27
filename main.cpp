#include <iostream>
#include "BillingSystem.h"

int main() {
    BillingSystem system("billing.txt");

    int choice;
    std::string name;
    double amount;

    do {
        std::cout << "\n===== Billing System =====\n";
        std::cout << "1. View Bills\n";
        std::cout << "2. Add Bill\n";
        std::cout << "3. Save Changes\n";
        std::cout << "4. Rollback\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.showBills();
                break;

            case 2:
                std::cout << "Enter bill name: ";
                std::cin >> name;
                std::cout << "Enter amount: ";
                std::cin >> amount;
                system.addBill(name, amount);
                break;

            case 3:
                system.commit();
                break;

            case 4:
                system.rollback();
                break;

            case 5:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
