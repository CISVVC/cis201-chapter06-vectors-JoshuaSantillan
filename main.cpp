#include <iostream>
#include "statement.h"
#include "transactions.h"

int main()
{
   Statement bank_statement;

   bank_statement.read();
   bank_statement.print();
   return 0;
}
