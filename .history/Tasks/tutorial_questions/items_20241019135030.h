#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Item {
public:
    virtual void display() noexcept = 0;  // No exception specification
    virtual void persist(ofstream& out) noexcept = 0;  // No exception specification
    virtual void input() noexcept = 0;  // No exception specification
    virtual ~Item() = default;
};

class Grocery : public Item {
public:
    string name, expiry_Date;
    float price;

    void display() noexcept override {
        cout << "Grocery: " << name << ", Price: " << price << ", Expiry Date: " << expiry_Date << endl;
    }

    void persist(ofstream& out) noexcept override {
        out << "Grocery " << name << " " << price << " " << expiry_Date << endl;
    }

    void input() noexcept override {
        cin.ignore();  // Clear input buffer
        cout << "Enter the name: "; getline(cin, name);
        cout << "Enter the expiry date: "; getline(cin, expiry_Date);
        cout << "Enter the price: "; cin >> price;
    }
};

class Electronics : public Item {
public:
    string name, warranty;
    float price;

    void display() noexcept override {
        cout << "Electronics: " << name << ", Price: " << price << ", Warranty: " << warranty << endl;
    }

    void persist(ofstream& out) noexcept override {
        out << "Electronics " << name << " " << price << " " << warranty << endl;
    }

    void input() noexcept override {
        cin.ignore();  // Clear input buffer
        cout << "Enter the name: "; getline(cin, name);
        cout << "Enter the warranty: "; getline(cin, warranty);
        cout << "Enter the price: "; cin >> price;
    }
};

class Clothing : public Item {
public:
    string type, size;
    float price;

    void display() noexcept override {
        cout << "Clothing: " << type << ", Price: " << price << ", Size: " << size << endl;
    }

    void persist(ofstream& out) noexcept override {
        out << "Clothing " << type << " " << price << " " << size << endl;
    }

    void input() noexcept override {
        cin.ignore();  // Clear input buffer
        cout << "Enter the type: "; getline(cin, type);
        cout << "Enter the size: "; getline(cin, size);
        cout << "Enter the price: "; cin >> price;
    }
};

class Book : public Item {
public:
    string name, genre;
    float price;

    void display() noexcept override {
        cout << "Book: " << name << ", Price: " << price << ", Genre: " << genre << endl;
    }

    void persist(ofstream& out) noexcept override {
        out << "Book " << name << " " << price << " " << genre << endl;
    }

    void input() noexcept override {
        cin.ignore();  // Clear input buffer
        cout << "Enter the name: "; getline(cin, name);
        cout << "Enter the genre: "; getline(cin, genre);
        cout << "Enter the price: "; cin >> price;
    }
};

class Toys : public Item {
public:
    string type, warranty;
    float price;

    void display() noexcept override {
        cout << "Toys: " << type << ", Price: " << price << ", Warranty: " << warranty << endl;
    }

    void persist(ofstream& out) noexcept override {
        out << "Toys " << type << " " << price << " " << warranty << endl;
    }

    void input() noexcept override {
        cin.ignore();  // Clear input buffer
        cout << "Enter the type: "; getline(cin, type);
        cout << "Enter the warranty: "; getline(cin, warranty);
        cout << "Enter the price: "; cin >> price;
    }
};

Item* restore(ifstream& in) {
    string type;
    in >> type;

    if (type == "Grocery") {
        Grocery* grocery = new Grocery();
        in >> grocery->name >> grocery->price >> grocery->expiry_Date;
        return grocery;
    }
    else if (type == "Electronics") {
        Electronics* electronics = new Electronics();
        in >> electronics->name >> electronics->price >> electronics->warranty;
        return electronics;
    }
    else if (type == "Clothing") {
        Clothing* clothing = new Clothing();
        in >> clothing->type >> clothing->price >> clothing->size;
        return clothing;
    }
    else if (type == "Book") {
        Book* book = new Book();
        in >> book->name >> book->price >> book->genre;
        return book;
    }
    else if (type == "Toys") {
        Toys* toy = new Toys();
        in >> toy->type >> toy->price >> toy->warranty;
        return toy;
    }

    return nullptr;  // If no matching type found
}

int main() {
    vector<Item*> shoppingList;

    // Step 1: Read the shopping list from a file
    ifstream infile("shopping_list.txt");
    if (infile.is_open()) {
        Item* item = nullptr;
        while (infile) {
            item = restore(infile);  // Use restore to recreate items
            if (item) {
                shoppingList.push_back(item);
            }
        }
        infile.close();
    }

    // Step 2: Add new items (could use a loop here to get input)
    // For now, just add one item manually:
    Grocery* newItem = new Grocery();
    newItem->input();
    shoppingList.push_back(newItem);

    // Step 3: Display all items
    cout << "Shopping List:" << endl;
    for (const auto& item : shoppingList) {
        item->display();
    }

    // Step 4: Persist the updated shopping list to the file
    ofstream outfile("shopping_list.txt");
    for (const auto& item : shoppingList) {
        item->persist(outfile);
    }
    outfile.close();

    // Clean up memory
    for (auto& item : shoppingList) {
        delete item;
    }

    return 0;
}
