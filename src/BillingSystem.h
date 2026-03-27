#ifndef BILLING_SYSTEM_H
#define BILLING_SYSTEM_H

#include <vector>
#include <string>

struct Bill {
    std::string name;
    double amount;
};

class BillingSystem {
private:
    std::vector<Bill> data;        // Original data
    std::vector<Bill> buffer;      // Temporary transaction data
    std::string filename;

public:
    BillingSystem(const std::string& file);

    void loadFromFile();
    void saveToFile();

    void showBills();
    void addBill(const std::string& name, double amount);

    void commit();     // Save changes
    void rollback();   // Undo changes
};

#endif
