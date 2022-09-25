#include <iostream>
#include <limits>

#include "contants.h"

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getInitialHeight(){
    while(true){
        std::cout << "Enter the height of the tower in meters: ";
        double intialHeight {};
        std::cin >> intialHeight;

        if(!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
        else{
            ignoreLine();
            return intialHeight;
        }
    }
}

double calculateHeight(double initialHeight, int seconds){
    return initialHeight - (myCanstants::gravity * seconds * seconds / 2);
}

void printHeight(double height, int seconds){

    if(height <= 0) {
        std::cout << "At " << seconds << " seconds, the ball hits the ground";
    }else {
        std::cout << "At " << seconds << " seconds, the ball is at height: " << height << "meters\n";
    }
}

int main(){
    const double initialHeight {getInitialHeight()};
    int seconds {0};

    std::cout << calculateHeight(initialHeight, 3);

    while(true) {
        double height { calculateHeight(initialHeight, seconds) };
        printHeight(height, seconds);

        if(height <= 0) break;

        seconds++;
    }

    return 0;
}