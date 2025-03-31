#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H


#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <vector>

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
        //std::ifstream file("C:\\Users\\honuk\\CS210\\programming-assignment-2-himelinakai\\story.txt");
        ifstream file(filename);
        if(!file.is_open()) {
            cerr << "Error opening the story file." << endl;
            return;
        }

        string line, desc, eventID, right, left;
        int eventNum, rightNum, leftNum;
        vector<int> eventIDs;

        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, eventID, delimiter);
            eventNum = stoi(eventID);
            eventIDs.push_back(eventNum);

            getline(ss, desc, delimiter);

            getline(ss, left, delimiter);
            leftNum = stoi(left);

            getline(ss, right, delimiter);
            rightNum = stoi(right);

            Story newStory(desc, eventNum, leftNum, rightNum);
            if (eventList.find(eventNum) == eventList.end()) {
                Node<T>* newEvent = new Node<T>(newStory);
                eventList[eventNum] = newEvent;
            }

            cout << eventList[eventNum]->data.leftEventNumber << endl;

            if (root == nullptr) {
                root = eventList[eventNum];
            }

            cout << root->data.leftEventNumber << endl;

        }

        Node<T> *curr;
        for (int i = 0; i < eventIDs.size(); i++) {
            curr = eventList[eventIDs.at(i)];
            if (eventList.find(curr->data.leftEventNumber) != eventList.end()) {
                curr->left = eventList[curr->data.leftEventNumber];
            }

            if (eventList.find(curr->data.rightEventNumber) != eventList.end()) {
                curr->right = eventList[curr->data.rightEventNumber];
            }
        }

        file.close();

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (root == nullptr) {
            cerr << "Cannot start yet, Game DecisionTree is empty." << endl;
            return;
        }

        Node<T>* curr = root;
        while (curr) {
            int userChoice = -1;
            cout << curr->data.description << endl;

            if (!curr->left && !curr->right) {
                cout << "\nGame is over!" << endl;
                return;
            }

            cout << "Please pick an option: " << endl;
            cin >> userChoice;

            if (userChoice == 1) {
                curr = curr->left;
            }
            else if (userChoice == 2) {
                curr = curr->right;
            }
            else {
                cerr << "Invalid choice, exiting the game." << endl;
                return;
            }

        }
    }
};

#endif // GAMEDECISIONTREE_H