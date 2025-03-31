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
    unordered_map<int, Node<T>*> eventList; // Will hold and keep track of all possible events in the story

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        // Opening the story file and remembering to check that it successfully opened
        ifstream file(filename);
        if(!file.is_open()) {
            cerr << "Error opening the story file." << endl;
            return;
        }

        // Declaring all element variables
        string line, desc, eventID, right, left;
        int eventNum, rightNum, leftNum;
        // This vector will keep track of all of the event numbers
        vector<int> eventIDs;

        while (getline(file, line)) {
            stringstream ss(line);

            // Parsing through each line of the text file and collecting the needed elements (event number, description, left child and right child)
            getline(ss, eventID, delimiter);
            eventNum = stoi(eventID);
            //cout << eventNum << endl;
            eventIDs.push_back(eventNum);

            getline(ss, desc, delimiter);
            //cout << desc << endl;

            getline(ss, left, delimiter);
            leftNum = stoi(left);
            //cout << leftNum << endl;

            getline(ss, right, delimiter);
            rightNum = stoi(right);
            //cout << rightNum << endl;

            // Adding each story event as a new node to the unordered map
            // Only adds if the event does not already exist since there are some duplicate situations that need to be accounted for
            Story newStory(desc, eventNum, leftNum, rightNum);
            if (eventList.find(eventNum) == eventList.end()) {
                Node<T>* newEvent = new Node<T>(newStory);
                eventList[eventNum] = newEvent;
            }

            if (root == nullptr) {
                root = eventList[eventNum];
            }
        }

        // Traverse through the unordered map so that the respective left and right children can be linked
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

        // Remember to free the vector memory and close the file
        eventIDs.clear();
        file.close();

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        // Ensure to check that a valid game can be played
        if (root == nullptr) {
            cerr << "Cannot start yet, Game DecisionTree is empty." << endl;
            return;
        }

        // Traverse through the decision tree based on the choices that the player makes
        Node<T>* curr = root;
        while (curr) {
            int userChoice = -1;
            cout << curr->data.description << endl;

            // Game ends when the player reaches a leaf on the tree
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