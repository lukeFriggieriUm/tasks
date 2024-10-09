#include <iostream>

using namespace std;

class MyClass {

    private:
        string field1;
        int field2;

    public: 

        //default constructor
        MyClass() {
            cout << "Default constructor called" << endl;
        }

        //parametrized constructor
        MyClass(string field1arg, int field2arg) : field1(field1arg), field2(field2arg) {
            cout << "Parametrized constructor called" << endl;
        }

        //destructor
        ~MyClass() {
            cout << "Destructor called" << endl;
        }

        //Setters
        void setField1(const string& field1) {
            this->field1=field1; //this ptr
        }

        void setField2(const int field2) {
            this->field2=field2; //this ptr
        }

        //Getters
        const string& getField1() {
            return field1;
        }

        int getField2() { //not const because this is a copy so it being changed does not affect original
            return field2;
        }
};

int main(int, char**) {
    string name;
    int age;
    cout << "Hello, from cdemo2!\n";

    //on stack
    MyClass* myObj1 = new MyClass();
    MyClass* myObj2 = new MyClass();

    myObj1->setField1("Luke");
    myObj1->setField2(5);

    name = myObj1->getField1();
    age = myObj1->getField2();

    cout << myObj1->getField1() << endl;

    delete myObj1;
    delete myObj2;
}  