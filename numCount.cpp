#include <iostream>

int main()
{
    int currVal = 0, newVal = 0;

    if(std::cin >> currVal){
        int count = 1;
        while(std::cin >> newVal)
        {
            if(newVal == currVal)
            {
                ++count;
            }else{
                std::cout << currVal << " occurs " << count << " times" << std::endl;
                currVal = newVal;
                count = 1;
            }
        }
        std::cout << currVal << "occurs " << count << " times" << std::endl;
    }
    return 0;

}