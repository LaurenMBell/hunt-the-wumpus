/*
* Author: Lauren Bell
* Description: 
*/

#include "arrow.hpp"
#include <iostream>

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Arrow::percept() const {
    std::cout << "";
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Arrow::encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won){
    std::cout << "Hark! The adventurer hath laid eyes on an arrow!" << std::endl;
    num_arrows++;
    std::cout << "You tuck it in your quiver, increasing your arrow count to " << num_arrows << std::endl;

    return false;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
char Arrow::get_symbol() const {
    return 'A';
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Arrow::clone() const {
    return new Arrow(*this);
}