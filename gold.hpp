/*
* Author: Lauren Bell
* Description: 
*/

#ifndef GOLD_HPP
#define GOLD_HPP


#include "event.hpp"

class Gold : public Event {
    public: 
        void percept() const override;
        bool encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won) override;
        char get_symbol() const override;
        Event* clone() const override;
};


#endif
