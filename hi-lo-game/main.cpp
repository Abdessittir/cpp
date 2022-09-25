#include <iostream>
#include <random>
#include <limits>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// note : input validation should be added
int getGuess(int time){
    std::cout << "Guess  #" << time << ':';
    int x {};
    std::cin >> x;
    return x;
}

bool playAgain(){
    while(true){
        std::cout << "Would you like to play again (y/n)? ";
        char ch{};
        std::cin >> ch;

        if (!std::cin){
            std::cin.clear();
            ignoreLine();
        }
        else{
            ignoreLine();

            switch(ch){
                case 'n':
                   return false;
                case 'y':
                   return true;
            }
        }
    }
}

void startMessage(){
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. ";
    std::cout << "You have 7 tries to guess what it is.\n";
}

void endMessage(){
    std::cout << "Thank you for playing.";
}

bool playMore(){
    const bool play{playAgain()};
    if (play){
        return true;
    }
    else{
        endMessage();
        return false;
    }
}

int main(){
    std::random_device rd;
    // get 8 integers of random numbers from std::random_device for our seed
    std::seed_seq ss {rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt {ss};// initialize our Mersenne Twister with the std::seed_seq
    /*
     **Create a reusable random number generator that generates uniform numbers 
     **between 1 and 100
    */
    std::uniform_int_distribution die100{ 1, 100 };
    

    while(true){

        int correctGuess {die100(mt)};
        int timeOfGuesses {1};
        constexpr int maxGuessesAllowed {7};

        startMessage();
        while (true){

            if(timeOfGuesses > maxGuessesAllowed){
                std::cout << "Sorry, you lose. The correct number was " << correctGuess << '\n';
                break;
            }

            int userGuess{getGuess(timeOfGuesses)};

            if (userGuess > correctGuess){
                std::cout << "Your guess is too high.\n";
            }
            else if (userGuess < correctGuess){
                std::cout << "Your guess is too low.\n";
            }
            else{
                std::cout << "Correct! You win!\n";
                break;
            }
            ++timeOfGuesses;
        }

        if(!playMore()) break;

    }

    return 0;
}