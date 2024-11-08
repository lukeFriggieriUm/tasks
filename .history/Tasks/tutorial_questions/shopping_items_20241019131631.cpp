#include <iostream>
#include <fstream>
#include "items.h"

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
    
     

}

