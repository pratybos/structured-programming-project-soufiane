#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    int soldThisMonth;
    double price; // price per unit
};

void updateInventory(vector<Product>& products) {
    for (Product& product : products) {
        product.quantity -= product.soldThisMonth;
    }
}

double calculateTotalSales(const vector<Product>& products) {
    double totalSales = 0.0;
    for (const Product& product : products) {
        totalSales += product.soldThisMonth * product.price;
    }
    return totalSales;
}

void displayInventory(const vector<Product>& products) {
    cout << "Product ID | Name     | Quantity | Sold This Month" << endl;
    cout << string(50, '-') << endl;

    for (const Product& product : products) {
        cout << setw(10) << product.productID << " | "
             << setw(8) << product.name << " | "
             << setw(8) << product.quantity << " | "
             << setw(15) << product.soldThisMonth << endl;
    }
}

void displayRemainingInventory(const vector<Product>& products) {
    for (const Product& product : products) {
        cout << "Remaining Inventory for Product " << product.productID << ": " << product.quantity << endl;
    }
}

int main() {
    vector<Product> products = {
        {101, "Laptops", 50, 30, 100.0},
        {102, "Phones", 75, 50, 50.0}
    };

    // Update inventory based on sales
    updateInventory(products);

    // Display inventory
    displayInventory(products);

    // Calculate and display total sales
    double totalSales = calculateTotalSales(products);
    cout << "\nTotal Sales: $" << fixed << setprecision(2) << totalSales << endl;

    // Display remaining inventory for each product
    displayRemainingInventory(products);

    return 0;
}
