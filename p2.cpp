#include <iostream>

int main()
{
    int count = 1, sum = 0, val;

    std:: cout << "Enter a number: ";

    std::cin >> val;

    while (count <= val)
    {
        sum += count;
        ++count;
    }

    std::cout<< " The sum of 1 to " << val << " is " << sum << std::endl;




}