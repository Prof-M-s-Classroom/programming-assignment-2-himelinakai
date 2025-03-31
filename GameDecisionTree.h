#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H


#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening the story file." << std::endl;
            return;
        }

        string line, desc, eventID, right, left;
        int eventNum, rightNum, leftNum;

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){}
};

#endif // GAMEDECISIONTREE_H