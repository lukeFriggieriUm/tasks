#include <iostream>
#include <fstream>
using namespace std;

class Item {
public:
    virtual void display() noexcept = 0;
    virtual void persist(ofstream& out) noexcept = 0;
    virtual void input() noexcept = 0;
    virtual ~Item() = default;
};

class Grocery : public Item {
public:
    string name, expiry_Date;
    float price;

    void display() override noexcept {
        cout << "Grocery: " << name << ", Price: " << price << ", Expiry Date: " << expiry_Date << endl;
    }

    void persist(ofstream& out) override noexcept {
        out << "Grocery " << name << " " << price << " " << expiry_Date << endl;
    }

    void input() override noexcept {
        cout << "Enter the name: "; cin >> name;
        cout << "Enter the expiry date: "; cin >> expiry_Date;
        cout << "Enter the price: "; cin >> price;
    }
};

class Electronics : public Item {
public:
    string name, warranty;
    float price;

    void display() override noexcept {
        cout << "Electronics: " << name << ", Price: " << price << ", Warranty: " << warranty << endl;
    }

    void persist(ofstream& out) override noexcept {
        out << "Electronics " << name << " " << price << " " << warranty << endl;
    }

    void input() override noexcept {
        cout << "Enter the name: "; cin >> name;
        cout << "Enter the warranty: "; cin >> warranty;
        cout << "Enter the price: "; cin >> price;
    }
};

class Clothing : public Item {
public:
    string type, size;
    float price;

    void display() override noexcept {
        cout << "Clothing: " << type << ", Price: " << price << ", Size: " << size << endl;
    }

    void persist(ofstream& out) override noexcept {
        out << "Clothing " << type << " " << price << " " << size << endl;
    }

    void input() override noexcept {
        cout << "Enter the type: "; cin >> type;
        cout << "Enter the size: "; cin >> size;
        cout << "Enter the price: "; cin >> price;
    }
};

class Book : public Item {
public:
    string name, genre;
    float price;

    void display() override noexcept {
        cout << "Book: " << name << ", Price: " << price << ", Genre: " << genre << endl;
    }

    void persist(ofstream& out) override noexcept {
        out << "Book " << name << " " << price << " " << genre << endl;
    }

    void input() override noexcept {
        cout << "Enter the name: "; cin >> name;
        cout << "Enter the genre: "; cin >> genre;
        cout << "Enter the price: "; cin >> price;
    }
};

class Toys : public Item {
public:
    string type, warranty;
    float price;

    void display() override noexcept {
        cout << "Toys: " << type << ", Price: " << price << ", Warranty: " << warranty << endl;
    }

    void persist(ofstream& out) override noexcept {
        out << "Toys " << type << " " << price << " " << warranty << endl;
    }

    void input() override noexcept {
        cout << "Enter the type: "; cin >> type;
        cout << "Enter the warranty: "; cin >> warranty;
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

    return nullptr;  
}

int main() {
    // Example code for adding items and restoring them from a file
    ofstream out("shopping_list.txt");

    Grocery grocery;
    grocery.name = "Milk";
    grocery.expiry_Date = "2024-12-31";
    grocery.price = 1.99;
    grocery.persist(out);
    out.close();

    ifstream in("shopping_list.txt");
    Item* item = restore(in);
    item->display();
    delete item;
    return 0;
}