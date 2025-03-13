/*
* Author: Lauren Bell
* Description: 
*/

#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP

#include "event.hpp"

class Escape_Rope : public Event {
    public: 
        void percept() const override;
        bool encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
                        int& num_arrows, bool& game_won) override;
        char get_symbol() const override;
        Event* clone() const override;
};


#endif
