/*
* Author: Lauren Bell
* Description: 
*/

#include "gold.hpp"
#include <iostream>


/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Gold::percept() const {
    std::cout << "The adventurer stubs thy toe on something delightfully heavy..." << std::endl;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Gold::encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won) {
    std::cout << "Hearken! The adventurer hath found the gold of the Wumpus!" << std::endl;
    std::cout << "Rejoice and be merry!" << std::endl;
    std::cout << "However, thy task is not yet complete. The escape rope is yet to be found..." << std::endl;

    has_gold = true;
    return false;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Gold::get_symbol() const {
    return 'G';
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Gold::clone() const {
    return new Gold(*this);
}