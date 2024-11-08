#include <iostream>
#include <fstream>

class Item{
    public:
        virtual void display(){};
        virtual void persist(std::ofstream& out){};
        virtual ~Item() = default;
};
