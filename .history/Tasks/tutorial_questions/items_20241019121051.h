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
            out << "Grocery" << name << " " << expiry_Date
        }
};

class Clothing: public Item{
    public:
        void display() override{
            
        }

        void persist(std::ofstream& out) override{

        }
};

class Book: public Item{
    public:
        void display() override{
            
        }

        void persist(std::ofstream& out) override{

        }
};

class Toys: public Item{
    public:
        void display() override{
            
        }

        void persist(std::ofstream& out) override{

        }
};