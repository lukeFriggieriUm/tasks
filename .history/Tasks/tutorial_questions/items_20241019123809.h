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
    string type;
    in >> type;

    if(type == "Grocery"){
        string name,expiry_Date;
        float price;

        Grocery* grocery = new Grocery();
        grocery->name = name;
        grocery -> expiry_Date = expiry_Date;
        grocery->price = price;
        return grocery;
    }else if(type == "Electronics"){
        string name,warranty;
        float price;

        Electronics* electronic = new Electronics();
        electronic->name = name;
        electronic->warranty = warranty;
        electronic->price = price;
        return electronic;
        return Electroni
    }else if(type == "Clothing"){
        string type,size;
        float price;
        
        Clothing* clothing = new Clothing();
        clothing->type = type;
        clothing->size = size;
        clothing->price = price;
    }else if(type == "Toys"){
        string type,warranty;
        float price;

        Toys* toy = new Toys();
        toy->type = type;
        toy->warranty = warranty;
        toy->price = price;
    }
};