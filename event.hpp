/*
* Author: Lauren Bell
* Description: 
*/

#ifndef EVENT_HPP
#define EVENT_HPP

class Event {
public:
	//default destructor
	virtual ~Event() = default;

	//percept functions (to be overridden by all derived classes)
	virtual void percept() const;

	//encounter func will be overridden by all derived classes, but 
	//takes some params to work
	virtual bool encounter(bool& has_gold, bool& is_alive, bool& is_confused, 
						int& num_arrows, bool& game_won);
	//if the arrow hits the wumpus the game should end
	virtual void arrow_hit(bool& wumpus_killed, bool& game_won);

	//getter for debugger mode
	virtual char get_symbol() const;

	//deep copies the event 
	virtual Event* clone() const = 0;
};

#endif
