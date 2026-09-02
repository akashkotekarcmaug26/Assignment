#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    void acceptDetails() {
        cout << "Product ID: ";
        cin >> productId;
        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const {
        cout << left << setw(10) << productId << setw(10) << name << setw(10) << fixed << setprecision(2) << price << setw(10) << quantity << setw(10) << totalValue();
        if (isLowStock(10))
            cout << " <- LOW STOCK";
        cout << endl;
    }

    double totalValue() const {
        return price * quantity;
    }

    bool isLowStock(int threshold) const {
        return quantity < threshold;
    }

    string getName() const { return name; }
};

double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate) {
    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100);
}

double applyDiscount(double price, double discountPercent = 10.0) {
    return price - (price * discountPercent / 100);
}

int main() {
    const int SIZE = 5;
    Product products[SIZE];

    cout << "===ENTER PRODUCT DETAILS===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "\n-- Product " << (i + 1) << " --" << endl;
        products[i].acceptDetails();
    }

    cout << "\n====INVENTORY REPORT====" << endl;
    cout << left << setw(10) << "ID" << setw(10) << "Name" << setw(10) << "Price" << setw(10) << "Qty" << setw(10) << "Total Value" << endl;
    for (int i = 0; i < SIZE; i++) {
        products[i].displayDetails();
    }

    
    int highestIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (products[i].totalValue() > products[highestIndex].totalValue())
            highestIndex = i;
    }
    cout << "\nHighest Value Product : " << products[highestIndex].getName() << " (Rs. " << fixed << setprecision(2) << products[highestIndex].totalValue() << ")" << endl;

    
    int threshold;
    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "Low Stock (threshold: " << threshold << ") : ";
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (products[i].isLowStock(threshold)) {
            if (found) cout << ", ";
            cout << products[i].getName();
            found = true;
        }
    }
    if (!found) cout << "None";
    cout << endl;

    // ---------------- Part B ----------------
    cout << "\n=====REORDER COST CALCULATIONS=====" << endl;
    cout << "reorderCost(int, double) = " << reorderCost(50, 20.0) << endl;
    cout << "reorderCost(double, double) = " << reorderCost(12.5, 8.0) << endl;
    cout << "reorderCost(int, double, double) = " << reorderCost(50, 20.0, 18.0) << endl;

    cout << "\napplyDiscount(1000) = " << applyDiscount(1000) << endl;

    
    cout << "applyDiscount(1000, 25) = " << applyDiscount(1000, 25) << endl;

    return 0;
}
