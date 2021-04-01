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
    int combatChoice;
    int attackStyle;
    int combatResults;


    //Initialize the random number generation by seeding with system. Not sure about the NULL pointer here, but will likely learn later when exposed to pointers.
    srand(time(NULL));

    cout << "Welcome to the dungeon! May I have your name traveller?" << endl;
    getline (cin, playerName);
    cout << endl << endl << endl;
    cout << "Which class would you like to play " << playerName << "?" << endl;
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
    


    cout << endl << endl << endl << endl;
    cout << "+==========================================+" << endl;
    cout << "You enter the dungeon " << playerName << ". A slime blocks your path. What will you do?" << endl;
    cout << "[ 1 - Frontal Assault | 2 - Focused Strike | 3 - Counter ]" << endl << endl;

    cin >> combatChoice;

    cout << endl << endl << endl << endl << endl;

    //Flavor text based on playerClass and choice above.
    if ( combatChoice == 1 || combatChoice == 2 || combatChoice == 3 )
    {
        switch(combatChoice){
            case 1: //Frontal Assault
                switch(playerClass){
                    case 1: //Warrior
                        cout << "You jump in the air with your hammer poised for a thunderous blow!" << endl;
                        combatResults = rand() % 100 + 50;
                        break;
                    case 2: //Mage
                        cout << "A ball of rolling fire throbs above your palm!" << endl;
                        combatResults = rand() % 100 + 50;
                        break;
                    case 3: //Assassin
                        cout << "You dash forward, a shadowy blur!" << endl;
                        combatResults = rand() % 60 + 1;
                        break;
                    default:
                        cout << "You slipped on a banana peel and died. Tragic!" << endl;
                }
                break;
            case 2: //Focused Strike
                switch(playerClass){
                    case 1: //Warrior
                        cout << "You drop your should and roll to the right, dagger singing from its sheath!" << endl;
                        combatResults = rand() % 60 + 1;
                        break;
                    case 2: //Mage
                        cout << "A dagger of ice splits the air!" << endl;
                        combatResults = rand() % 70 + 1;
                        break;
                    case 3: //Assassin
                        cout << "You twitch briefly; a single throwing star curves towards your unsuspecting opponent!" << endl;
                        combatResults = rand() % 100 + 40;
                        break;
                    default:
                        cout << "You slipped on a banana peel and died. Tragic!" << endl;
                }
                break;
            case 3: //Counter
                switch(playerClass){
                    case 1: //Warrior
                        cout << "You huddle behind your shield!" << endl;
                        combatResults = rand() % 100 + 1;
                        break;
                    case 2: //Mage
                        cout << "A prism of magical barriers forms around you!" << endl;
                        combatResults = rand() % 100 + 1;
                        break;
                    case 3: //Assassin
                        cout << "A cloud of smoke explodes to conceal you!" << endl;
                        combatResults = rand() % 100 + 50;
                        break;
                    default:
                        cout << "You slipped on a banana peel and died. Tragic!" << endl;
                }
                break;
            default:
                cout << "Uh-oh, error at combat phase!";
                cin >> playerClass;
                return 0;
        }
    }

    if(combatResults > 50)
    {
        cout << endl << "Your blow was sufficient! The slime has been vanquished." << endl;
        cout << "You gain 1 gold." << endl;
    }
    else
    {
        cout << endl << "Somehow... you died to a slime..." << endl;
        cout << "You gain 0 gold." << endl;
    }

    cout << endl << endl << endl << "Thanks for playing! Type a number to exit!" << endl;

    //Just here to hold the window open.
    cin >> playerClass;

    return 0;
}