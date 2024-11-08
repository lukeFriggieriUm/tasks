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
class binOps
{
    private:
        float op1;
        float op2;
        char op;

        public:
        float evaluate()
        {
            switch (op)
            {
            case '+':
                return op1 + op2;
                break;
            case '-':
                return op1 - op2;
                break;
            case '*':
                return op1 * op2;    
                break;
            case '/':
                return op1/op2;
                break;
            default:
                cout <<  "Please enter a valid operand" << endl;      
            }
        }

        void setOp1(float op1){
            this->op1 = op1;
        }

        void setOp2(float op2){
            this->op2 = op2;
        }

        void setOperand(char op){
            this->op = op;
        }
};


int main(){ 
    try{
    binOps* arr = new binOps[5];

    ofstream outFile;

    outFile.open("Output.txt");

    for(int i=0; i <= 2; i++){
        char choice;
        float op1,op2,result;

        cout << "Enter the Operation (Operand operator Operand)";
        cin >> op1 >> choice  >> op2; 
        
        arr[i].setOp1(op1);
        arr[i].setOp2(op2);
        arr[i].setOperand(choice);

        result = arr[i].evaluate();
        outFile << op1 << choice << op2 << "->" << result << "\n"; 
    }

    delete[] arr;
    }catch(exception e1){
        cout << "please enter a valid input" << endl;
    }
}