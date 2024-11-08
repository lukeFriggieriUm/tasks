 #include <iostream>
#include <fstream>

using namespace std;
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
}