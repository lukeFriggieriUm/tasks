#include <iostream>
#include <string>

class Animal {
    public:
      virtual void sound() = 0;

      virtual void info() = 0;
};

class Dog: public Animal {
    public:
        std::string name;
        int age;
        
        //Constructor 
        Dog(std::string n, int a): name(n), age(a) {}

    void sound() override{
        std::cout << "woof" << std::endl;
    }

    void info(){
        std::cout << "Name: " << this->name << "Age: " << this->age << std::endl;
    }

    int getAge(){
        return this->age;
    }
};

class Cat: public Animal{
    public:
        std::string name;
        int age;

        Cat(std::string n,int a): name(n), age(a) {}

        void sound() override{
            std::cout << "Meow!" << std::endl;
        }

        void info() override{
        std::cout << "Name: " << this->name << "Age: " << this->age << std::endl;
    }
};

void makeSound(Animal* animal){
    animal->sound();
}

void getInfo(Animal* animal){
    animal->info();
}

int main(){
    Dog myDog("henry",5);
    Cat myCat("Millie",8);

    makeSound(&myCat);
    getInfo(&myCat);

    return 0;
}