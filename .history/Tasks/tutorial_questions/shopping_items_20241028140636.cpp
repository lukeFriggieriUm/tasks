#include <iostream>
#include <fstream>
using namespace std;

class Item {
    public:
        virtual void display() = 0; 
        virtual void persist(ofstream& out) = 0;  
        virtual void input() = 0;
        virtual ~Item() = default;
};

class Grocery : public Item {
    public:
        string name, expiry_Date;
        float price;

        void display() override {
            cout << "Grocery: " << name << ", Price: " << price << ", Expiry Date: " << expiry_Date << endl;
        };

        void persist(ofstream& out) override {
            out << "Grocery " << name << " " << price << " " << expiry_Date << endl;
        };

        void input() override{
            cout << "Enter the name"; cin >> name;
            cout << "Enter the expiry_date"; cin >> expiry_Date;
            cout << "Enter the price"; cin >> price;
        };
};

class Electronics : public Item {
    public:
        string name, warranty;
        float price;

        void display() override {
            cout << "Electronics: " << name << ", Price: " << price << ", Warranty: " << warranty << endl;
        };

        void persist(ofstream& out) override {
            out << "Electronics " << name << " " << price << " " << warranty << endl;
        };

         void input() override{
            cout << "Enter the name"; cin >> name;
            cout << "Enter the warranty"; cin >> warranty;
            cout << "Enter the price"; cin >> price;
        };
};

class Clothing : public Item {
    public:
        string type, size;
        float price;
        
        void display() override {
            cout << "Clothing: " << type << ", Price: " << price << ", Size: " << size << endl;
        };

        void persist(ofstream& out) override {
            out << "Clothing " << type << " " << price << " " << size << endl;
        };

         void input() override{
            cout << "Enter the type"; cin >> type;
            cout << "Enter the size"; cin >> size;
            cout << "Enter the price"; cin >> price;
        };
};

class Book : public Item {
    public:
        string name, genre;
        float price;

        void display() override {
            cout << "Book: " << name << ", Price: " << price << ", Genre: " << genre << endl;
        };

        void persist(ofstream& out) override {
            out << "Book " << name << " " << price << " " << genre << endl;
        };

         void input() override{
            cout << "Enter the name"; cin >> name;
            cout << "Enter the genre"; cin >> genre;
            cout << "Enter the price"; cin >> price;
        };
};

class Toys : public Item {
    public:
        string type, warranty;
        float price;

        void display() override {
            cout << "Toys: " << type << ", Price: " << price << ", Warranty: " << warranty << endl;
        };

        void persist(ofstream& out) override {
            out << "Toys " << type << " " << price << " " << warranty << endl;
        };

         void input() override{
            cout << "Enter the type"; cin >> type;
            cout << "Enter the warranty"; cin >> warranty;
            cout << "Enter the price"; cin >> price;
        };
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
};

int main(){
    vector<Item*> list;

    ifstream infile("shopping_list.txt");
    if (infile.is_open()) {
        Item* item = nullptr;
        while (infile) {
            item = restore(infile);  // Use the restore function to recreate items
            if (item) {
                list.push_back(item);
            }
        }
        infile.close();
    }

    cout << "Current Shopping List: "<< endl;
    for(const auto& item: list){
        item->display();
    }

    //play with the data
    char choice;
    do{
        cout << "Add item (g = Grocery, e = Electronics, c = clothes, t=toys, b=books): "; cin >> choice;

        Item* item = nullptr;

        switch(choice) {
        case 'g': 
            item = new Grocery();
            item->input(); 
            break;
        case 'e': 
            item = new Electronics();
            item->input(); 
            break;
        case 'c':
            item = new Clothing();
            item->input();
            break;
        case 't':
            item = new Toys();
            item->input();
            break;
        case 'b':
            item = new Book();
            item->input();
            break;        
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }

        if(item){
            list.push_back(item);
        }
        
        std::cout << "Do you want to add more items? (y/n): ";
        std::cin >> choice;
    }while(choice == 'y');

    cout << "Current Shopping List: "<< endl;
    for(const auto& item: list){
        item->display();
    }

    ofstream outFile("shopping_list.txt");
    for(const auto& item: list){
        item->persist(outFile);
        delete item;
    }
    outFile.close();
}

