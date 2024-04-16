#include <iostream>

int main()
{
  int sum = 0, val;

  std:: cout << "Enter a number: ";
  std::cin >> val;

  for(int i = 1; i <= val; i++)
  {
    sum +=i;

    std::cout << "The sum of 1 to " << val << " is " << sum << std::endl;
  }
  return 0;
}