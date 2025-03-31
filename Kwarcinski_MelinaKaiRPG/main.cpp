#include <iostream>
#include <string>
#include "GameDecisionTree.h"
using namespace std;
int main() {
    GameDecisionTree<Story> myGame;

    string filename = "myStory.txt";  // Specify the input file
    char delimiter = '|';                // '|' is the delimiter, change if needed
    string test2 = "C:\\Users\\honuk\\CS210\\programming-assignment-2-himelinakai\\myStory.txt";
    string test = "C:\\Users\\honuk\\CS210\\programming-assignment-2-himelinakai\\story.txt";

    // Load the story data from the file
    myGame.loadStoryFromFile(test2, delimiter);

    // Start the game
   myGame.playGame();

    return 0;
}