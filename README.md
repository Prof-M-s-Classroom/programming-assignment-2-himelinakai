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

The first step in building the decision tree from the text file is gathering all of the needed information about each individual story event. The text file is opened and each line is read one by one. Each line is parsed into the event number, event description, left child and right child (this format was previously established). Since all of this information is stored as a string, 3 of the 4 elements must be casted to integers so that they can be worked with easily. As the elements for each story event is gathered, they are used to declare a Story object since they serve as parameters. Once the Story object is created, a new node is declared and the Story element is stored as that node's data. All of the nodes are put into an unordered map. It must be checked that a node does not already exist for that particular story event since there are some story events that share ancestors, but there cannot be duplicate nodes. A node for each story element is created and stored in the map before linking them all. To link all of the events, we traverse through the unordered map, setting the left and right child of the node to the appropriate following event, checking that the node exists. For example, if the two pathways from the first event are Event 2 and Event 3, the left child of the first node is set to the node for Event 2 and the right child is set to the node for Event 3. If the event has -1 as its left or right child, it means that it is a leaf and a potential ending to the story. In this case, the children remain set to null.  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

The game begins by setting the current node to the root node, which is story Event 1. It also remembers to check that the tree is not empty and that a valid game can be played. It is checked that the current node is not a leaf, and that the game is not over. The user is then prompted to make their choice for the path to take. They can either enter a (1) to indicate going left or a (2) to indicate going right. If they decide to go left, the current node is updated to be the left child of previous current and vice versa if the player decides to go right, current will be set to the right child. If the player enters an invalid choice, the game will end. The game will also end if the player reaches a leaf node since there is no longer a path to take. There are also some events that can be reached by taking different paths to get there. This is a result of nodes pointing to the same children.   

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

To begin reading the text file, it is first opened. It is then read line by line using the getline() function. The delimiter makes parsing easier since it allows us to declare markers of where we want to break the line of text up. The delimiter character of our choice is entered into the getline() function as a parameter. This function call returns the chunk of text that we were looking for as a string. For elements such as the event number, the stoi() function is used to cast the string of integers into actual integers. 

I ensured that nodes were properly linked by doing frequent checks that the output was as expected and by printing information along the way so that I could check that the code was functioning as intended at various points.

One challenge that I faced while handling file input was that I could not properly link nodes in the beginning. It seemed that some were being mishandled and that children were null when they shouldn't be. I fixed this by creating a vector of the different event numbers so that I could more accurately traverse through the unordered map. 

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

One issue I had was that the provided story.txt would run as intended but that the story file I originally wrote threw an error. After some searching and troubleshooting, I figured out that it was probably a memory issue. I went back to my story and made it more concise to see if it was just too wordy. Once I stripped down the amount of text, the game ran as intended. 

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

>On your 18th birthday, you receive a letter about your missing mother. Do you (1) open the letter or (2) ignore it?

 Player chooses 1

>The letter reveals your mother went into hiding and only you can find her. Will you accept the quest? (1) Yes or (2) No

Player chooses 1

>You pack and leave secretly. Your friend Finn catches you. Do you (1) bring him or (2) go alone?

Player chooses 2

>You hear a whisper calling your mother's name. Do you (1) follow it or (2) ignore it?

Player chooses 1

>The whisper now says "home." Do you (1) go to your old home or (2) return home from here?

Player chooses 1

>You arrive at your old home. Your mother is there, smiling and waiting for you. She explains the secrets she knows abou
t the king. Together, you'll face whatever comes next.

Game is over!

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n) where n is the number of possible story events`  
- **Searching for an event in the tree** → `O(log n) since the potential outcomes are cut in half each time`  
- **Game traversal efficiency** → `O(log n) since the starting point is the top of the tree and you must go to the bottom to complete the game (that will roughly be half of the elements if the tree is balanced) 
*Can note that if the tree is just one long chain than it could be O(n)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

I tested the scenario in which the player only goes left and if they only go right. The story went as planned and appropriate story outcomes resulted. 

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

No additonal features were implemented. I did create another text file called myStory.txt which includes the story that I wrote.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
