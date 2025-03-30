[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `[Jeffrey Huber]`  
### **Student ID:** `[130717623]`  

---

IF THE CODE DOES NOT WORK. INSTEAD OF "story.txt"  put R"((entire file directory ending with story.txt)) 
for example string (filename = R"(C:\Users\huber\CLionProjects\programming-assignment-2-Jeffrey-Huber\story.txt)";)
I have tried test file I have edited so much stuff, for the life of me it won't work with just story.txt
hopefully it is just a problem with my computer.

## **1. Project Overview**
THis project simulated a baseball at bat using a binary decision tree. The count starts at 0-0 and every pitch you get the decision to take the pitch or swing and the count
changes based on which decision you make. 

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → The main just sets the file and delimiter to use then calls the functions from GameDecisionTree  
- **`GameDecisionTree.h`** → GameDecisionTree.h has all the functions which creates the BTS from the file and plays the game  
- **`Node.h`** → Node.h creates a constructor for what a node is
- **`Story.h`** → Story.h creates a story class so it can be read and object of story can be created in other classes.
- **`story.txt`** → The GameDecisionTree.h file reads story.txt and breaks it into 4 parts. The first number is the event number
- after that there is the description which tells us what is happening in the at bat and then the last 2 are where it traverses to
- depending on if you take the pitch or swing. 

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?
- The loadStoryFromFile function access story.txt, reads it and then breaks it down into parts based on the delimiter.
- then each part is put into a newNode of object Story then it goes to the nextline and repeats the process creating moew newNodes.
- How are nodes linked based on left and right event numbers?
- The numbers at the end of each line in story.txt are where the nodes point to, with the first being left and the last being right
- unless there is a leaf node where it points to -1
- What happens if an event has `-1` as left or right children?
- Its set so if -1 is left it is also right so it can not be or. But if -1 is left or right then the code ends which means the at bat is over

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- If the input is an S then it goes right and if a T then it goes left.
- What happens when the player reaches a leaf node?  
- The at bat is over so the Code says "Your at bat is over" then it tells the user to play again
- Explain the special case where multiple events lead to the same outcome.
- Not much is different two pointers just point to the same memory location. This was easy in the context of baseball because
- different counts because the same count very easily ie 0-1 becomes 1-1 if there is a ball and 1-0 becomes
- 1-1 if there is a strike.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- The file is read line by line and broken into parts based on the delimiter. The four parts are name eventNumber, description
- leftEventNumber and rightEventNumber. Event number is the current node, description is the actual story of the game and left/right
- event numbers are the nodes you go to based on if you swing or take. 
- How do you ensure nodes are properly linked?
- I set left and right node to data.leftEventNumber (or right if its right of course)
- Any challenges faced while handling file input?
- I really was struggling with making the delimiter work. For the longest time the left was always a value in the negative millions
- and the right was always zero. I rewrote the delimiter more times than I would have liked.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
Like mentioned before I could not get the delimiter to work. I commented out a lot of the code and cout the value of left, right
and current node till I was able to write the delimiter in such a way that it outputted what I wanted.
Another problem that I still can't fix is on when I write "story.txt" the code doesn't work but when I put the actual file path
it does. I have determined that this is a punishment from a demon because AI and my friend with a masters in CS couldn't figure
it out either.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)It is a 0-0 count
Do you want to take the pitch (T) or swing at the pitch (S)
S
You swing and miss strike 1 count 0-1.
Do you want to take the pitch (T) or swing at the pitch (S)
T
You take called strike count 0-2
Do you want to take the pitch (T) or swing at the pitch (S)
T
You take called strike 3 your outPlay again!

Your at bat is over

Process finished with exit code 0
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(N)` It takes the run time of how many lines are in the file
- **Searching for an event in the tree** → `O(h)` the max amount of time it can take to find something is the height of the BST
- **Game traversal efficiency** → `O(h)` Its just based on the height of the BTS how long it takes to traverse. Unless this means how long to go to the next oen
- in which case it would be 0(1)

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

I originally had a lost of edge cases where I would make sure there was no white space in the story.txt file but I realized
since I am writing the story.txt file I can remove all whitespace from there and remove all edge cases.
I als did a lot of testing to make sure I was getting the right values in the left and right nodes by outputting there values.

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

I don't think this applies as an extra feature but I made an insertNode method which I don't even end up using
but created it for the first rendition of my code before I switched to mapping. 

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
