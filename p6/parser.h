/*
  ALWAYS include parser.h instead of y.tab.h

  Here is why:

    Since the union created by bison contains several gpl objects,
    a forward class declaration, or including the .h file must be 
    done before the union is created.

    Bison generates y.tab.h where the union is created. 
    I can't find a way to get bison to generate a y.tab.h that includes 
    forward class declarations and #include's, so I created this file.


*/

#ifndef PARSER_H
#define PARSER_H

// for each type used in the union, you will need to 
// put the appropriate include here
// since it is bad programming practive to include "using namespace std"
// in a .h file, you will have to put "std::string" in the union instead
// of "string"
#include "gpl_type.h"
#include "symbol.h"
#include "game_object.h"
#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "textbox.h"
#include "pixmap.h"
#include "symbol_table.h"
#include <string>
#include "expr.h"
#include "variable.h"
#include "y.tab.h"
#include "animation_block.h"

#endif // #ifndef PARSER_H
