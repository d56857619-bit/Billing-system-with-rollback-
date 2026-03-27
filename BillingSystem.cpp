#include "BillingSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>

BillingSystem::BillingSystem(const std::string& file) {
    filename = file;
    loadFromFile();
}

// =======================
// Load from file
// =======================
void BillingSystem::loadFromFile() {
    data.clear();
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "No existing file found. Starting fresh.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string name, amountStr;

        getline(ss, name, ',');
        getline(ss, amountStr);

        if (!name.empty() && !amountStr.empty()) {
            Bill b;
            b.name = name;
            b.amount = std::stod(amountStr);
            data.push_back(b);
        }
    }

    file.close();

    // Copy to buffer
    buffer = data;
}

// =======================
// Save to file
// =======================
void BillingSystem::saveToFile() {
    std::ofstream file(filename);

    for (const auto& bill : buffer) {
        file << bill.name << "," << bill.amount << "\n";
    }

    file.close();
}

// =======================
// Show bills
// =======================
void BillingSystem::showBills() {
    if (buffer.empty()) {
        std::cout << "No bills available.\n";
        return;
    }

    std::cout << "\n--- Bills ---\n";
    for (const auto& bill : buffer) {
        std::cout << bill.name << " - " << bill.amount << "\n";
    }
}

// =======================
// Add bill
// =======================
void BillingSystem::addBill(const std::string& name, double amount) {
    buffer.push_back({name, amount});
}

// =======================
// Commit (Save)
// =======================
void BillingSystem::commit() {
    saveToFile();
    data = buffer;
    std::cout << "Changes saved to billing.txt\n";
}

// =======================
// Rollback
// =======================
void BillingSystem::rollback() {
    buffer = data;
    std::cout << "Changes rolled back.\n";
}
