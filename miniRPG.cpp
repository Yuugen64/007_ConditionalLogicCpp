#include <string>
#include <iostream>

#include <stdio.h> /* printf, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */

using namespace std;

int main()
{
    //Variables
    int attackChance;
    string playerName;
    int playerClass;


    //Initialize the random number generation by seeding with system. Not sure about the NULL pointer here, but will likely learn later when exposed to pointers.
    srand(time(NULL));

    cout << "Welcome to the dungeon! May I have your name traveller?" << endl;
    getline (cin, playerName);
    cout << "Which class would you like to play?" << endl;
    cout << "[ 1 - Warrior | 2 - Mage | 3 - Assassin ]" << endl;
    //Input Validation is an issue here.
    cin >> playerClass;

    //Loose validation of correct playerClass choice.
    if ( playerClass == 1 || playerClass == 2 || playerClass == 3 )
    {
        switch(playerClass){
            case 1:
                cout << "You have chosen to be a courageous Warrior!" << endl;
                break;
            case 2:
                cout << "You have chosen to be a clever Mage!" << endl;
                break;
            case 3:
                cout << "You have chosen to be a sneaky Assassin!" << endl;
                break;
            default:
                cout << "Uh-oh, error at class confirmation!";
        }
    }
    else
    {
        cout << "Uh-oh, error at class validation!";
        //Just here to hold the window open.
        cin >> playerClass;
        return 0;
    }

    //Just here to hold the window open.
    cin >> playerClass;

    return 0;
}