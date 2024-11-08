#include <iostream>
#include <fstream>
#include <memory>
#include "items.h"

using namespace std;

int main(){
    vector<unique_ptr<Item> > list;

    ifstream infile("shopping_list.txt");

    items.push_back(make_unique<Grocery>("Apple", "2025-12-31", 2.99));
    items.push_back(make_unique<Electronics>("Laptop", "2 years", 999.99));
    items.push_back(make_unique<Clothing>("T-shirt", "L", 19.99));
    items.push_back(make_unique<Book>("The Catcher in the Rye", "Fiction", 10.99));
    items.push_back(make_unique<Toys>("Lego Set", "1 year", 29.99));

    // Save the items to a file
    save(items, "shopping_list.txt");


    if (infile.is_open()) {
        unique_ptr<Item> item = nullptr;
        while (infile) {
            unique_ptr<Item> item = restore(infile);  
            if (item) {
                list.push_back(move(item));
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

        unique_ptr<Item> item = nullptr;

        switch(choice) {
        case 'g': 
            item = make_unique<Grocery>();
            item->input(); 
            break;
        case 'e': 
            item =  make_unique<Electronics>();
            item->input(); 
            break;
        case 'c':
            item = make_unique<Clothing>();
            item->input();
            break;
        case 't':
            item = make_unique<Toys>();
            item->input();
            break;
        case 'b':
            item = make_unique<Book>();
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
            list.push_back(move(item));
        }
        
        std::cout << "Do you want to add more items? (y/n): ";
        std::cin >> choice;
    }while(choice == 'y');

    cout << "Current Shopping List: "<< endl;
    for(const auto& item: list){
        item->display();
    }
    
    ofstream outFile("shopping_list.txt");
    for (const auto& item : list) {
        item->persist(outFile);
    }
    outFile.close();

}

