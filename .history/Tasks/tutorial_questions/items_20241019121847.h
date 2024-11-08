#include <iostream>
#include <fstream>
using namespace std;

class Item{
    public:
        virtual void display(){};
        virtual void persist(std::ofstream& out){}; //write to a file
        virtual ~Item() = default;
};

class Grocery: public Item{
    public:
        string name,expiry_Date;
        float price;

        void display() override{
            
        }

        void persist(std::ofstream& out) override{
            out << "Grocery" << name << " " << price << " " << expiry_Date << endl;
        }
};

class Electronics: public Item{
    public:
        string name,warranty;
        float price;


        void display() override{
            
        }

        void persist(std::ofstream& out) override{
            out << "Electronics" << name << " " << price << " " << warranty << endl;
        }
};


class Clothing: public Item{
    public:
        string type,size;
        float price;
        
        void display() override{
            
        }

        void persist(std::ofstream& out) override{
            out << "Clothing" << type << " " << price << " " << size << endl;
        }
};

class Book: public Item{
    public:
        string name,genre;
        float price;

        void display() override{
            
        }

        void persist(std::ofstream& out) override{
            out << "Book" << name << " " << price << " " << genre << endl;
        }
};

class Toys: public Item{
    public:
        string type,warranty;
        float price;
        void display() override{
            
        }

        void persist(std::ofstream& out) override{
            out << "Toys" << type << " " << price << " " << warranty << endl;
        }
};

Item* restore(ifstream& in){
    std::string
};