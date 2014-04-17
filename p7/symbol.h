#include <sstream>
#include "gpl_type.h"
#include "game_object.h"
#include "animation_block.h"
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
        Game_object* getGameObject();
        void setGameObject(Game_object* newGameObject);
        Animation_block* getAnimationBlock();
        void setAnimationBlock(Animation_block* newAnimationBlock);
        Symbol(string name, int value);
        Symbol(string name, double value);
        Symbol(string name, string value);
        Symbol(string name, Game_object* value);
        Symbol(string name, Animation_block* value);
        void print(ostream &out);
        ostream& operator<<(ostream& os);
    private:
        string name;
        Gpl_type type;
        string string_value;
        double double_value;
        int int_value;
        Game_object* game_object_value;
        Animation_block* animation_block_value;        
       
        /**
        union {
         string string_value;
         double double_value;
         int int_value;
         Game_object Game_object_value;
         Animation_block Animation_block_value;
        }
        **/
};
