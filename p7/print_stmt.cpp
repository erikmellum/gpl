#include "print_stmt.h"

void Print_stmt::execute()
{
	cout << output->eval_string();
}
