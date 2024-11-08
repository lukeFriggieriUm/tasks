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
    for(const auto& item: list){
        item->display();
    }

    //play with the data
    char exit,choice;
    do{
        cout << "Would you like to enter a new item? (y/n)"; cin >> exit;

        cout << "Add item (g = Grocery, e = Electronics, c = clothes, t=toys, b=books): "; cin >> choice;

        Item* item = new Item();

        switch(choice){

        }
    }while(exit != 'y');

    cout << "Current Shopping List: "<< endl;
    for(const auto& item: list){
        item->display();
    }

    ofstream outFile("shopping_list.txt");
    for(const auto& item: list){
        item->persist(outFile);
        delete item;
    }
    

}

