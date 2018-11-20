/*
File: statement.cpp
Description: Statementclass functin that uses vectors to push back user read infromation which are numers and used math equations to solve problems
Email: santj96@gmail.com
Date: Nov 9, 2018
*/
#include<iostream>
#include<vector>
#include<string>
#include "statement.h"
#include "transactions.h"
// statement class functions

//constructor
Statement::Statement() 
{

}

// creates the assumed initial balance and reads additional data calling the transactions class storing info a vector
void Statement::read() 
{

   Transactions initial(1, 1143.24, "Initial Balance");
   transactions.push_back(initial);
   bool more = true;
   while (more)
   {
      Transactions t;
      t.read();
      transactions.push_back(t);
      std::cout << "Enter another (Y/N)";
      char response;
      std::cin >> response;
      if (response != 'y' && response != 'Y')
      {
         more = false;
      }
   }

   balance(transactions);
}
//finds the balance for each day and uses pushback to store it
void Statement::balance(std::vector<Transactions> &v) 
{
 // std::vector<double> daily_balance;
     m_balance = 0;

   for (int i = 0; i < MAX_DAY; i++)
   {
      m_balance += v[i].get_transaction(); //v[i] is the same as v.at(i)
   
      daily_balance.push_back(m_balance);
   }
}

// prints statement with the data from transaction classes and the balance
void Statement::print() 
{
   for (int i = 0; i < transactions.size(); i++)
   {
      std::cout << "Day: " << transactions[i].get_day() << " ";
      std::cout << transactions[i].get_transaction() << " ";
      std::cout << transactions[i].get_description() << std::endl;
      std::cout << "Total: " << daily_balance[i] << std::endl;
   }
   std::cout << "Minimum interest: " << min_daily_balance(daily_balance) << std::endl;
   std::cout << "Montly Interest: " << average_daily_balance(daily_balance) << std::endl;
}

double Statement::min_daily_balance(const std::vector<double> &v) // The lowest monthly interest
{
      double m_min_balance = v[0]; 

   for (int i = 0; i < MAX_DAY; i++)
   {
      if (v[i] < m_min_balance )
        {
         m_min_balance = v[i];
          // if min balance is greater than v at i then its new minumum balance
       }
   }
   return m_min_balance * RATE;
}

double Statement::average_daily_balance(const std::vector<double> &v) // balance divided by 30 (max days) to find the average interest of the month
{
   double sum = 0.0;

   for (int i = 0; i < MAX_DAY; i++)
   {
      sum += v[i];
   // Iterate through the daily ammount to test to see if its work
 //  std::cout << v[i] << "\n" << '\t';
   }
    // adds vector up divides it by the month and then multilies it by the interest
   return (sum / MAX_DAY) * RATE;

}
