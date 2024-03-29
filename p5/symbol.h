#include <sstream>
#include "gpl_type.h"

#pragma once

using namespace std;

class Symbol
{
    public:
        string getName();
        void setName(string newName);
        Gpl_type getType();
        void setType(Gpl_type newType);
        int getInt();
        void setInt(int newInt);
        string getString();
        void setString(string newString);
        double getDouble();
        void setDouble(double newDouble);
        //Game_Object getGameObject();
        //void setGameObject(Game_Object newGameObject);
        //Animation_Block getAnimationBlock();
        //void setAnimationBlock(Animation_Block newAnimationBlock);
        Symbol(string name, int value);
        Symbol(string name, double value);
        Symbol(string name, string value);
        //Symbol(string name, Game_Object value);
        //Symbol(string name, Animation_Block value);
        void print(ostream &out);
        ostream& operator<<(ostream& os);
    private:
        string name;
        Gpl_type type;
        string string_value;
        double double_value;
        int int_value;
        //Game_Object game_object_value;
        //Animation_Block animation_block_value;        
       
        /**
        union {
         string string_value;
         double double_value;
         int int_value;
         Game_Object game_object_value;
         Animation_Block animation_block_value;
        }
        **/
};
