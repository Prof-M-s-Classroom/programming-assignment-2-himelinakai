[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name: Melina Kai Kwarcinski  
### **Student ID: 130039946  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

> This project uses a binary decision tree in order to implement a text-based RPG. Each of the possible story events is represented by a node. Both the left and right children represent the two next possible events/pathways. The path that the story follows is determined by the choices that the player makes. The story events are loaded from an external text file, and each of the lines in the file is parsed to gather the necessary information about each story event, including the event number, description and the event number of both children. The game will terminate once a leaf node (a node with -1 as both children) is reached, or if the player enters an invalid story choice while playing. 

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → This file calls the two main functions in the GameDecisionTree.h file, effectively running the game itself. It declares a GameDecisionTree object, chooses the text file to read from and sets the desired delimiter chatacter.  
- **`GameDecisionTree.h`** → This file defines the GameDecisionTree class. It holds the two elements, the root node and unordered map that tracks each story event, the class constructor and the two class functions, loadStoryFromFile() and playGame().These two functions combine elements from all other files and are responsible for the implementation of the decision tree and game play.  
- **`Node.h`** → This file contains the definition of the Node class. It includes its elements (data, left child and right child) and its constructor.  
- **`Story.h`** → This file contains the declaration of the Story class, including its elements, default constructor and parameteried constructor. The implementation of the class is done in Story.cpp.
- **`story.txt`** → This file contains the entire storyline. It has each of the possible story events, which includes the description, its event number as well as the two potential paths from that event. This file is opened and then read line by line. Each line is parsed into the previously mentioned elements and stored in later-used variables. Each of the story events is represented by a node that is stored in an unordered map. Each of the event nodes is then linked based on the defined story pathways. Once all information is collected, the file is closed.

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  
- **Searching for an event in the tree** → `O(?)`  
- **Game traversal efficiency** → `O(?)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
