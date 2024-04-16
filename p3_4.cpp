#include <iostream>

int main(){
    int num= 0;

    std::cout << "Enter a number: ";
    std:: cin >> num;

    if(num % 2 == 0)
    {
        std::cout << "The number " << num << " is even." << std::endl;
    }
    else
    {
        std::cout << "The number " << num << " is odd." << std::endl;
    }

    return 0;
}