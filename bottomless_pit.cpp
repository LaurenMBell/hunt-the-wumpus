/*
* Author: Lauren Bell
* Description: 
*/

#include "bottomless_pit.hpp"
#include <iostream>

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Bottomless_Pit::percept() const {
    std::cout << "The adventurer feeleth a breeze..." << std::endl;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Bottomless_Pit::encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                                int& num_arrows, bool& game_won) {
    std::srand(std::time(nullptr));
    int falling_chance = std::rand() % 4 + 1;
    std::cout << "Your leather-booted foot slips..." << std::endl;

    if (falling_chance == 4) {
        std::cout << "The adventurer hath fallen into the bottomless pit!!" << std::endl;
        std::cout << "You fall forever. Years pass." << std::endl;
        std::cout << "The adventurer hath died. " << std::endl;

        is_alive = false;
    
        return false;
        return false;
    } else {
        std::cout << "You pull yourself up with strength unknown!" << std::endl;
        std::cout << "As if blessed by the Lady of the Lake herself, \nthe adventurer has been narrowly saved from the bottomless pit." << std::endl;
    }
    return true;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Bottomless_Pit::get_symbol() const {
    return 'P';
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Bottomless_Pit::clone() const {
    return new Bottomless_Pit(*this);
}