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
    unordered_map<int, Node<T>*> eventList;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        std::ifstream file;
        file.open(filename);
        if(!file.is_open()) {
            cerr << "Error opening the story file." << endl;
            return;
        }

        string line, desc, eventID, right, left;
        int eventNum, rightNum, leftNum;

        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, eventID, delimiter);
            eventNum = stoi(eventID);
            getline(ss, desc, delimiter);
            getline(ss, left, delimiter);
            leftNum = stoi(left);
            getline(ss, right, delimiter);
            rightNum = stoi(right);

            Story newStory(desc, eventNum, leftNum, rightNum);
            if (eventList.find(eventNum) == eventList.end()) {
                Node<T>* newEvent = new Node<T>(newStory);
                eventList.insert({eventNum, newEvent});
            }

            /*
            else {
                eventList[eventNum]->data = newStory;
            }
            */

            Node<T> *curr = eventList[eventNum];
            if (root == nullptr) {
                root = curr;
            }

            if (leftNum != -1) {
                if (eventList.find(leftNum) == eventList.end()) {
                    eventList[leftNum] = new Node<T>(T());
                }
                else {
                    curr->left = eventList[leftNum];
                }
            }

            if (rightNum != -1){
                if (eventList.find(rightNum) == eventList.end()) {
                    eventList[rightNum] = new Node<T>(T());
                }
                else {
                    curr->right = eventList[rightNum];
                }
            }
        }

        file.close();

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {

    }
};

#endif // GAMEDECISIONTREE_H