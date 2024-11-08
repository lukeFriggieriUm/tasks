#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
    public:
        virtual void display() = 0;
        virtual void persist(ofstream& out) = 0;
        virtual void input() = 0;
        virtual ~Item() = default;
};

class Grocery : public Item {
    private:
        string name, expiryDate;
        float price;

    public:
        // Constructors
        Grocery() : name(""), expiryDate(""), price(0.0f) {}
        Grocery(const string& n, const string& expDate, float p) : name(n), expiryDate(expDate), price(p) {}

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
            out
        }
}

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

