#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for a product
struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

// Function to add a new product to the inventory
void addProduct(vector<Product>& inventory) {
    Product p;
    cout << "Enter product ID: ";
    cin >> p.id;
    cin.ignore();  // to clear the input buffer
    cout << "Enter product name: ";
    getline(cin, p.name);
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;
    inventory.push_back(p);
    cout << "Product added successfully!" << endl;
}

// Function to display all products in the inventory
void displayInventory(const vector<Product>& inventory) {
    cout << "\nInventory Details:" << endl;
    cout << "ID\tName\t\tQuantity\tPrice" << endl;
    for (const auto& product : inventory) {
        cout << product.id << "\t" << product.name << "\t" << product.quantity << "\t\t" << product.price << endl;
    }
}

// Function to search for a product by ID
void searchProductById(const vector<Product>& inventory, int id) {
    bool found = false;
    for (const auto& product : inventory) {
        if (product.id == id) {
            cout << "Product Found!" << endl;
            cout << "ID: " << product.id << "\nName: " << product.name << "\nQuantity: " << product.quantity << "\nPrice: " << product.price << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product with ID " << id << " not found!" << endl;
    }
}

// Function to update product quantity
void updateQuantity(vector<Product>& inventory, int id, int quantity) {
    bool found = false;
    for (auto& product : inventory) {
        if (product.id == id) {
            product.quantity = quantity;
            cout << "Quantity updated successfully!" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Product with ID " << id << " not found!" << endl;
    }
}

// Main function
int main() {
    vector<Product> inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Inventory\n";
        cout << "3. Search Product by ID\n";
        cout << "4. Update Product Quantity\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
                break;
            case 2:
                displayInventory(inventory);
                break;
            case 3: {
                int id;
                cout << "Enter product ID to search: ";
                cin >> id;
                searchProductById(inventory, id);
                break;
            }
            case 4: {
                int id, quantity;
                cout << "Enter product ID to update: ";
                cin >> id;
                cout << "Enter new quantity: ";
                cin >> quantity;
                updateQuantity(inventory, id, quantity);
                break;
            }
            case 5:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice, please try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
