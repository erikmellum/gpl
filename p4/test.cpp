#include "symbol_table.h"
#include "symbol.h"
#include <iostream>
// should it say anything when you try to put an identical symbol in the table?

using namespace std;
int global_counter = 42;






int
main()
{
  Symbol_table *Symbol_table = Symbol_table::instance();
  Symbol_table->insert(new Symbol("a", "abc"));
  Symbol_table->insert(new Symbol("c", 43));
  Symbol_table->insert(new Symbol("a", 4.3));
  Symbol_table->print(cout);
}





