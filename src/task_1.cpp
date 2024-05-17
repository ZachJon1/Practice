#include <iostream>
#include <random>

void GuessNumber() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 99);

  int random_num = distrib(gen);

  int guess;

  do {
    std::cout << "Enter your guess {0 - 99 inclusive}: ";
    std::cin >> guess;

    if (std::cin.fail() || guess < 0 || guess > 99) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
    } else {
      break;
    }
  } while (true);
  if (guess == random_num) {
    std::cout << "Congrats! You guessed the number " << random_num << std::endl;
  } else if (guess < random_num) {
    std::cout << "Sorry, your number " << guess
              << " is smaller than the target number " << random_num
              << std::endl;
  } else {
    std::cout << " Sorry, your number " << guess
              << " is larger than the target number " << random_num
              << std::endl;
  }
}

int main() {
  GuessNumber();
  return 0;
}
