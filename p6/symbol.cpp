#include "symbol.h"

Symbol::Symbol(string newName, int value)
{
    name = newName;
    type = INT;
    int_value = value;
}
Symbol::Symbol(string newName, double value)
{
    name = newName;
    type = DOUBLE;
    double_value = value;
}
Symbol::Symbol(string newName, string value)
{
    name = newName;
    type = STRING;
    string_value = value;
}
Symbol::Symbol(string newName, Game_object* value)
{
    name = newName;
    type = GAME_OBJECT;
    game_object_value = value;
}
Symbol::Symbol(string newName, Animation_block* value)
{
    name = newName;
    type = ANIMATION_BLOCK;
    animation_block_value = value;
}
string Symbol::getName()
{
    return name;
}
void Symbol::setName(string newName)
{
    name = newName;
}
Gpl_type Symbol::getType()
{
    return type;
}
void Symbol::setType(Gpl_type newType)
{
    type = newType;
}
int Symbol::getInt()
{
    return int_value;
}
void Symbol::setInt(int newInt)
{
    int_value = newInt;
}
string Symbol::getString()
{
    return string_value;
}
void Symbol::setString(string newString)
{
    string_value = newString;
}
double Symbol::getDouble()
{
    return double_value;
}
void Symbol::setDouble(double newDouble)
{
    double_value = newDouble;
}
Game_object* Symbol::getGameObject()
{
    return game_object_value;
}
void Symbol::setGameObject(Game_object* newGameObject)
{
    game_object_value = newGameObject;
}
Animation_block* Symbol::getAnimationBlock()
{
    return animation_block_value;
}
void Symbol::setAnimationBlock(Animation_block* newAnimationBlock)
{
    animation_block_value = newAnimationBlock;
}
void Symbol::print(ostream &out)
{
    switch(type)
    {
        case INT:
            out << "int" << " " << name << " " << int_value;
            break;
        case DOUBLE:
            out << "double" << " " << name << " " << double_value;
            break;
        case STRING:
            out << "string" << " " << name << " \"" << string_value << "\"";
            break;
        case GAME_OBJECT:
            indent++;
            out << "game_object" << " " << name << endl << *game_object_value << indent;
            indent--;
            break;
        case ANIMATION_BLOCK:
            out << "animation_block" << " " << name << " " << *animation_block_value;
            break;
    }
    out << endl;
}
ostream& Symbol::operator<<(ostream& os)
{
    print(os);
    return os;
}
