#include <iostream>
#include <cctype>
#include <string>
#include <thread>
#include <cstdlib> 
#include <cstdlib> 

using namespace std;

class player{
    private:
        string username;
        int health = 100;
        int inventorySpace = 100;

    public:
        //Constructor 
        player(std::string username): username(username){}

        void takeDamage(int damage){
            this->health -= damage;
            std::cout << "eug" << std::endl;
        }    

        void heal(string type, int amount){
            for(int i=amount; i >= 0; i--){
                if(this->health == 100){
                    break;
                }else{
                    if(type == "bandages"){
                        this->health += 20;
                    }else if(type == "first-aid"){
                        this->health += 50;
                    }
                }
            }
        }

        void loot(string item) {
            if (item == "gun") {
                this->inventorySpace -= 20;
                displayStats();
            }else if (item == "bandages") {
                this->inventorySpace -= 5;
                displayStats();
            }else if (item == "first-aid") {
                this->inventorySpace -= 20;
                displayStats();
            }else if (item == "ammo") {
                this->inventorySpace -= 5; 
                displayStats();
            }
        }

        void displayStats(){
            std::cout << "----------------------" << std::endl;
            std::cout << "------Player Info-----" << std::endl;
            std::cout << "Username: " <<  this->username << std::endl;
            std::cout << "Health: " << this->health << std::endl;
            std::cout << "Inventory Space: " << this->inventorySpace << std::endl;
            std::cout << "----------------------" << std::endl;
        }

        int getHealth(){
            return this->health;
        }

        int getSpace(){
            return this->inventorySpace;
        }
};

int main(){
    system("clear");
    player player1("Frigg31");
    std::srand(std::time(0));


    string guns[5] = {"AKM", "KAR-98K", "SMG", "HANDGUN","DROGONOV"};
    string heals[2] = {"BANDAGE","FIRST-AID"};
    string ammo[3] = {"5.56","7.64","0.32"};
    char choice = 0;
    char input = ' ';
    char inputMaster = ' ';
    int length = 0;
    

    while(player1.getHealth() > 0){
        int randomNum = std::rand() % 5;

        if(randomNum == 1){
            length = sizeof(guns)/ sizeof(guns[0]);
            randomNum = std::rand() % length;
            std::cout << "YOU FOUND A: " << guns[randomNum] << std::endl;

            if(player1.getSpace() <= 0){
                std::cout << "INVENTORY FULL" << std::endl;
            }else{
                std::cout << "PICK-UP? [F]"; cin >> input;
                choice = std::tolower(input);

                if(input == 'f'){   
                    player1.loot("gun");
                }
            }
        }else if(randomNum == 2){
            length = sizeof(heals)/sizeof(heals[0]);
            randomNum = std::rand() % length;
            std::cout << "YOU FOUND A: " << heals[randomNum] << std::endl;
            if(player1.getSpace() <= 0){
                std::cout << "INVENTORY FULL" << std::endl;
            }else{
                string type = heals[randomNum];

                for(char &c : type){
                    c = std::tolower(c);
                }

                std::cout << "PICK-UP? [F]"; cin >> input;
                choice = std::tolower(input);

                if(input == 'f'){  
                    if(type == "bandages"){
                        player1.loot("bandages");
                    }else if(type == "first-aid"){
                        player1.loot("first-aid");
                    }
                }
            }
            player1.displayStats();
        }else if(randomNum == 3){
            int randomNum = std::rand() % 5;

            if(randomNum == 1){
                int length = sizeof(ammo)/sizeof(ammo[0]);
                randomNum = std::rand() % length;
                std::cout << "YOU FOUND A: " << ammo[randomNum] << std::endl;
                if(player1.getSpace() <= 0){
                    std::cout << "INVENTORY FULL" << std::endl;
                }else{
                    std::cout << "PICK-UP? [F]"; cin >> input;
                    choice = std::tolower(input);

                    if(input == 'f'){   
                        player1.loot("ammo");
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(2)); 

        std::cout << "DAMAGE PLAYER ? [X]"; cin >> inputMaster;
        
        inputMaster = std::tolower(inputMaster);

        if(inputMaster == 'x'){
            player1.takeDamage(20);
            player1.displayStats();
            std::this_thread::sleep_for(std::chrono::seconds(2)); //sleep code
        }else{
            std::this_thread::sleep_for(std::chrono::seconds(1)); //sleep code
        }

        system("clear");
    }
    std::cout << "Game Over!" << std::endl;
}