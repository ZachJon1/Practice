#include <iostream>

int main()
{
   std::cout << "Enter two numbers:" << std::endl;
   int val1 = 0, val2 = 0;

   std::cin >> val1 >> val2;

   std::cout << "The sum of " << val1 << " and " << val2<< " is " << val1 + val2 << std::endl;
   return 0;
}