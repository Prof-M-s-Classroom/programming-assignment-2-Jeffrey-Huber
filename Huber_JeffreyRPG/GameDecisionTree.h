#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

#include "Node.h"
#include "Story.h"

template<typename T>
class GameDecisionTree {
private:
    Node<T> *root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {
    }

    explicit GameDecisionTree(Node<T> *root) : root(root) {
    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string &filename, char delimiter) {
        std::ifstream file(filename);
        std::string line;
        std::map<int, Node<Story>*> gameMap;

        while (std::getline(file, line)) {
            size_t delimiterOne = line.find(delimiter);
            size_t delimiterTwo = line.find(delimiter, delimiterOne + 1);
            size_t delimiterThree = line.find(delimiter, delimiterTwo + 1);

            std::string eventNumber = line.substr(0, delimiterOne);
            std::string description = line.substr(delimiterOne + 1, delimiterTwo - delimiterOne - 1);
            std::string leftEventNumber = line.substr(delimiterTwo + 1, delimiterThree - delimiterTwo - 1);
            std::string rightEventNumber = line.substr(delimiterThree + 1);

            int currentEvent = std::stoi(eventNumber);
            int leftEvent = std::stoi(leftEventNumber);
            int rightEvent = std::stoi(rightEventNumber);


            Node<Story>* newNode = new Node<Story>(Story(description, currentEvent, leftEvent, rightEvent));
            gameMap[currentEvent]= newNode;

            if (currentEvent == 1) {
                root = newNode;
            }
        }

        for (auto& pair : gameMap) {
            Node<Story>* node = pair.second;
            int leftNode = node -> data.leftEventNumber;
            int rightNode = node -> data.rightEventNumber;

            if (leftNode != -1 && gameMap.find(leftNode) != gameMap.end()) {
                node->left = gameMap[leftNode];
            }
            if (rightNode != -1 && gameMap.find(rightNode) != gameMap.end()) {
                node->right = gameMap[rightNode];
            }
        }

    }


    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        Node<Story> *currentNode = root;

        while (currentNode != nullptr) {

            std::cout << currentNode->data.description << std::endl;

            if (currentNode->data.leftEventNumber != -1 && currentNode->data.rightEventNumber != -1) {
                std::cout << "Do you want to take the pitch (T) or swing at the pitch (S)";
                char selection;
                std::cin >> selection;

                if (selection == 't' || selection == 'T') {
                    currentNode = currentNode->left;
                } else if (selection == 's' || selection == 'S') {
                    currentNode = currentNode->right;
                } else {
                    std::cout << "Please enter a valid selection" << std::endl;
                }
            } else {
                std::cout << "Your at bat is over" << std::endl;
                std::cerr << "Play again!" <<std::endl;
                std::exit(0);
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H
