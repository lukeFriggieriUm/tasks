#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
    public:
        virtual void display() = 0;
        virtual void persist(ofstream& out) = 0;
        virtual void input() = 0;
        
        virtual ~Item() noexcept {}
};

class Grocery : public Item {
    private:
        string name, expiryDate;
        float price;

    public:
        // Constructors
        Grocery() : name(""), expiryDate(""), price(0.0f) {}
        Grocery(const string& n, const string& expDate, float p) : name(n), expiryDate(expDate), price(p) {}

        Grocery(Grocery&& other) noexcept
        : name(move(other.name)), expiryDate(move(other.expiryDate)), price(other.price) {
        other.price = 0.0f; 
    }   

    Grocery& operator=(Grocery&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            expiryDate = move(other.expiryDate);
            price = other.price;
            other.price = 0.0f;  
        }
        return *this;
    }

        // Getters
        string getName() const { return name; }
        string getExpiryDate() const { return expiryDate; }
        float getPrice() const { return price; }

        // Setters
        void setName(const string& n) { name = n; }
        void setExpiryDate(const string& expDate) { expiryDate = expDate; }
        void setPrice(float p) { price = p; }

        void display() override {
            cout << "Grocery: " << name << ", Price: " << price << ", Expiry Date: " << expiryDate << endl;
        }

        void persist(ofstream& out) override {
            out << "Grocery " << name << " " << price << " " << expiryDate << endl;
        }

        void input() override {
            cout << "Enter the name: "; cin >> name;
            cout << "Enter the expiry date: "; cin >> expiryDate;
            cout << "Enter the price: "; cin >> price;
        }

        ~Grocery() override = default;
};

class Electronics : public Item {
    private:
        string name, warranty;
        float price;

    public:
        // Constructors
        Electronics() : name(""), warranty(""), price(0.0f) {}
        Electronics(const string& n, const string& w, float p) : name(n), warranty(w), price(p) {}

        // Getters
        string getName() const { return name; }
        string getWarranty() const { return warranty; }
        float getPrice() const { return price; }

        // Setters
        void setName(const string& n) { name = n; }
        void setWarranty(const string& w) { warranty = w; }
        void setPrice(float p) { price = p; }

        void display() override {
            cout << "Electronics: " << name << ", Price: " << price << ", Warranty: " << warranty << endl;
        }

        void persist(ofstream& out) override {
            out << "Electronics " << name << " " << price << " " << warranty << endl;
        }

        void input() override {
            cout << "Enter the name: "; cin >> name;
            cout << "Enter the warranty: "; cin >> warranty;
            cout << "Enter the price: "; cin >> price;
        }

        ~Electronics() override = default;
};

class Clothing : public Item {
    private:
        string type, size;
        float price;

    public:
        // Constructors
        Clothing() : type(""), size(""), price(0.0f) {}
        Clothing(const string& t, const string& s, float p) : type(t), size(s), price(p) {}

        // Getters
        string getType() const { return type; }
        string getSize() const { return size; }
        float getPrice() const { return price; }

        // Setters
        void setType(const string& t) { type = t; }
        void setSize(const string& s) { size = s; }
        void setPrice(float p) { price = p; }

        void display() override {
            cout << "Clothing: " << type << ", Price: " << price << ", Size: " << size << endl;
        }

        void persist(ofstream& out) override {
            out << "Clothing " << type << " " << price << " " << size << endl;
        }

        void input() override {
            cout << "Enter the type: "; cin >> type;
            cout << "Enter the size: "; cin >> size;
            cout << "Enter the price: "; cin >> price;
        }

        ~Clothing() override = default;
};

class Book : public Item {
    private:
        string name, genre;
        float price;

    public:
        // Constructors
        Book() : name(""), genre(""), price(0.0f) {}
        Book(const string& n, const string& g, float p) : name(n), genre(g), price(p) {}

        // Getters
        string getName() const { return name; }
        string getGenre() const { return genre; }
        float getPrice() const { return price; }

        // Setters
        void setName(const string& n) { name = n; }
        void setGenre(const string& g) { genre = g; }
        void setPrice(float p) { price = p; }

        void display() override {
            cout << "Book: " << name << ", Price: " << price << ", Genre: " << genre << endl;
        }

        void persist(ofstream& out) override {
            out << "Book " << name << " " << price << " " << genre << endl;
        }

        void input() override {
            cout << "Enter the name: "; cin >> name;
            cout << "Enter the genre: "; cin >> genre;
            cout << "Enter the price: "; cin >> price;
        }

        ~Book() override = default;
};

class Toys : public Item {
    private:
        string type, warranty;
        float price;

    public:
        // Constructors
        Toys() : type(""), warranty(""), price(0.0f) {}
        Toys(const string& t, const string& w, float p) : type(t), warranty(w), price(p) {}

        // Getters
        string getType() const { return type; }
        string getWarranty() const { return warranty; }
        float getPrice() const { return price; }

        // Setters
        void setType(const string& t) { type = t; }
        void setWarranty(const string& w) { warranty = w; }
        void setPrice(float p) { price = p; }

        void display() override {
            cout << "Toys: " << type << ", Price: " << price << ", Warranty: " << warranty << endl;
        }

        void persist(ofstream& out) override {
            out << "Toys " << type << " " << price << " " << warranty << endl;
        }

        void input() override {
            cout << "Enter the type: "; cin >> type;
            cout << "Enter the warranty: "; cin >> warranty;
            cout << "Enter the price: "; cin >> price;
        }

        ~Toys() override = default;
};

// Restoration function to reconstruct Item objects from file input
unique_ptr_Item>* restore(ifstream& in) {
    string type;
    in >> type;

    if (type == "Grocery") {
        string name, expiryDate;
        float price;
        in >> name >> price >> expiryDate;
        return new Grocery(name, expiryDate, price);
    }
    else if (type == "Electronics") {
        string name, warranty;
        float price;
        in >> name >> price >> warranty;
        return new Electronics(name, warranty, price);
    }
    else if (type == "Clothing") {
        string type, size;
        float price;
        in >> type >> price >> size;
        return new Clothing(type, size, price);
    }
    else if (type == "Book") {
        string name, genre;
        float price;
        in >> name >> price >> genre;
        return new Book(name, genre, price);
    }
    else if (type == "Toys") {
        string type, warranty;
        float price;
        in >> type >> price >> warranty;
        return new Toys(type, warranty, price);
    }
    
    return nullptr;
}

#endif 
