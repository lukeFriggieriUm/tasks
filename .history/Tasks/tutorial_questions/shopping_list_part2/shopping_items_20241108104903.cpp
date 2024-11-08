#include <iostream>
#include <fstream>
#include "items.h"

int main(){
    vector<unique> list;

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
   
    char choice;
    do{
        cout << "Add item (g = Grocery, e = Electronics, c = clothes, t=toys, b=books, x=exit): "; cin >> choice;

        Item* item = nullptr;

        switch(choice) {
        case 'g': 
            item = new Grocery();
            item->input(); 
            break;
        case 'e': 
            item = new Electronics();
            item->input(); 
            break;
        case 'c':
            item = new Clothing();
            item->input();
            break;
        case 't':
            item = new Toys();
            item->input();
            break;
        case 'b':
            item = new Book();
            item->input();
            break;
        case 'x':
            choice = 'n';
            break;   
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }

        if(item){
            list.push_back(item);
        }
        
        std::cout << "Do you want to add more items? (y/n): ";
        std::cin >> choice;
    }while(choice == 'y');

    cout << "Current Shopping List: "<< endl;
    for(const auto& item: list){
        item->display();
    }

    ofstream outFile("shopping_list.txt");
    for(const auto& item: list){
        item->persist(outFile);
        delete item;
    }
    outFile.close();
}

