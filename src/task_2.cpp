#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char * argv[]){
    if(argc !=3){
        std::cerr << "Error: Only 2 arguments can be provided" << "\n";
        return 1;
    }

    std::string arg1(argv[1]);
    std::string arg2(argv[2]);

    std::string ext1 = arg1.substr(arg1.find_last_of(".")+1);
    std::string ext2 = arg2.substr(arg1.find_last_of(".")+1);

    double num1 = stod(arg1.substr(0, arg1.find_last_of(".")));
    double num2 = stod(arg2.substr(0, arg2.find_last_of(".")));

    if (ext1 =="txt" && ext2 == "txt"){
        double mean = (num1+num2)/2;
        std::cout << "The mean value is: " << mean << "\n";
    }else if(ext1 =="png" && ext2 == "png"){
        double sum = (num1+num2);
        std::cout << "The sum of the values is: " << sum << "\n";
    }else if(ext1 == "txt" && ext2 == "png"){
        if(num2 == 0){
            std::cerr << "Divison by zero";
            return 1;
        }else{
            double mod = std::fmod(num1,num2);
            std::cout << "The modulo value is: " << mod << "\n";
        }

    }else{
        std::cerr << "Error: invalid file extensions" << "\n";
        return 1;
    }
    return 0;
}