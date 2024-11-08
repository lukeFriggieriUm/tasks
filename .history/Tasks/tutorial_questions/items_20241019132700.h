#include <iostream>
#include <fstream>
using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Item {
    public:
        virtual void display() = 0;  
        virtual void persist(ofstream& out) = 0;  
        virtual ~Item() = default;
};

class Grocery : public Item {
    public:
        string name, expiry_Date;
        float price;

        void display() override {
            cout << "Grocery: " << name << ", Price: " << price << ", Expiry Date: " << expiry_Date << endl;
        }

        void persist(ofstream& out) override {
            out << "Grocery " << name << " " << price << " " << expiry_Date << endl;
        }

        void input(){
            cout << "Enter the name"  cin >> name; 
        }
};

class Electronics : public Item {
    public:
        string name, warranty;
        float price;

        void display() override {
            cout << "Electronics: " << name << ", Price: " << price << ", Warranty: " << warranty << endl;
        }

        void persist(ofstream& out) override {
            out << "Electronics " << name << " " << price << " " << warranty << endl;
        }
};

class Clothing : public Item {
    public:
        string type, size;
        float price;
        
        void display() override {
            cout << "Clothing: " << type << ", Price: " << price << ", Size: " << size << endl;
        }

        void persist(ofstream& out) override {
            out << "Clothing " << type << " " << price << " " << size << endl;
        }
};

class Book : public Item {
    public:
        string name, genre;
        float price;

        void display() override {
            cout << "Book: " << name << ", Price: " << price << ", Genre: " << genre << endl;
        }

        void persist(ofstream& out) override {
            out << "Book " << name << " " << price << " " << genre << endl;
        }
};

class Toys : public Item {
    public:
        string type, warranty;
        float price;

        void display() override {
            cout << "Toys: " << type << ", Price: " << price << ", Warranty: " << warranty << endl;
        }

        void persist(ofstream& out) override {
            out << "Toys " << type << " " << price << " " << warranty << endl;
        }
};

Item* restore(ifstream& in) {
    string type;
    in >> type;  // Read the type of the item

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
