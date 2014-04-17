/***
    This file is a placeholder for the Animation_block class you will write in 
    the next assignment p7.

    You will have to make only small modifications in p6.

    You may use it as a starting point for your Animation_block class for p7.

    I have put in just enough for it to work in p6.

***/

#ifndef ANIMATION_BLOCK_H
#define ANIMATION_BLOCK_H

#include <string>
#include <vector>

#include "statement_block.h"
class Symbol;

class Animation_block : public Statement_block
{
    public:
        Animation_block(int forward_line, Symbol *parameter, std::string name);
        void execute(Game_object *argument);

        Symbol *get_parameter_symbol() {return m_parameter_symbol;}
        std::string name() {return m_name;}

        std::ostream &print(std::ostream &os) const;

    private:

        int m_forward_line;
        std::string m_name;
        Symbol *m_parameter_symbol;

        // disable default copy constructor and default assignment
        // done as a precaution, they should never be called
        Animation_block(const Game_object &); 
        const Animation_block &operator=(const Game_object &); 
};

std::ostream &
operator<<(std::ostream &os, const Animation_block &animation_block);

std::ostream &
operator<<(std::ostream &os, const Animation_block *animation_block);

#endif // #ifndef ANIMATION_BLOCK_H
