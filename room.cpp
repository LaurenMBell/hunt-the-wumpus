/*
* Author: Lauren Bell
* Description: 
*/

#include "room.hpp"


/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Room::Room() : event_ptr(nullptr) {}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Room::Room(const Room& other) : event_ptr(nullptr) {
    if (other.event_ptr != nullptr) {
        event_ptr = other.event_ptr->clone();
    }
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Room::~Room() {
    delete event_ptr;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Room& Room::operator=(const Room& other) {
    if (this != &other) {
        delete event_ptr;
        event_ptr = nullptr;

        if (other.event_ptr != nullptr) {
            event_ptr = other.event_ptr->clone();
        }
    }
    return *this;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
Event* Room::get_event() const {
    return event_ptr;
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Room::set_event(Event* new_event) {
    delete event_ptr;
    event_ptr = (new_event != nullptr) ? new_event->clone() : nullptr;
}


/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Room::trigger_percept() const {
    if (event_ptr != nullptr) {
        event_ptr->percept();
    }
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
bool Room::enter_room(bool& has_gold, bool& is_alive, bool& is_confused,
                    int& num_arrows, bool& game_won) {
    if (event_ptr != nullptr) {
        return event_ptr->encounter(has_gold, is_alive, is_confused, 
                num_arrows, game_won);
        } else {
            return true;
        }
}

/*
* Function: 
* Description: 
* Parameters:
* Returns: 
*/
void Room::arrow_entered(bool& wumpus_killed, bool& game_won) {
    if (event_ptr != nullptr) {
        event_ptr->arrow_hit(wumpus_killed, game_won);
    }
    
}