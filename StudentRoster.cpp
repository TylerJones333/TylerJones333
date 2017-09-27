// Example program
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

/*
 Program Specification:
 1. Read data for names and weights for 15 people from the console where there is a name on a line followed by a weight on the next line, like in names.txt.
 2. Your program will build a list for the data maintained in ascending order based on both name and weight via a doubly linked list.
 3. This dll will use one pointer to keep weights in sorted order, and use the other link to keep names on sorted order.
 4. You need to build the list as you go maintaining this ordering, so at any time a print method was called it would print the related field in order.
 **(This means nodes are added to the list in sorted order, elements are not added to the list followed by a sort called on the list.)
 */

class Node
{
public:
    std::string name;
    int weight;
    Node *n_Next;
    Node *n_Prev;
    Node *w_Next;
    Node *w_Prev;
    
    Node(std::string newName, int newWeight)
    {
        this->name = newName;
        this->weight = newWeight;
        this->n_Next = NULL;
        this->n_Prev = NULL;
        this->w_Next = NULL;
        this->w_Prev = NULL;
    }
    
    void toString() {
        printf("Node = %s\n", this->name.c_str());
        
        if (this->n_Next == NULL) {
            printf("Node->n_Next = NULL\n");
        }
        else {
            printf("Node->n_Next = %s\n", this->n_Next->name.c_str());
        }
        
        if (this->w_Next == NULL) {
            printf("Node->w_Next = NULL\n");
        }
        else {
            printf("Node->w_Next = %s\n", this->w_Next->name.c_str());
        }
        
        if (this->n_Prev == NULL) {
            printf("Node->n_Prev = NULL\n");
        }
        else {
            printf("Node->n_Prev = %s\n", this->n_Prev->name.c_str());
        }
        
        if (this->w_Prev == NULL) {
            printf("Node->w_Prev = NULL\n");
        }
        else {
            printf("Node->w_Prev = %s\n", this->w_Prev->name.c_str());
        }
    }
};

class DLL
{
public:
    
    Node* n_Head;
    Node* w_Head;
    
    DLL() {
        n_Head = NULL;
        w_Head = NULL;
    }
    
    void insert(std::string name, int weight) {
        Node *newNode = new Node(name, weight);
        
        if(n_Head == NULL)
        {
            this->n_Head = newNode;
            this->w_Head = newNode;
        }
        else
        {
            this->insert_name(newNode);
            this->insert_weight(newNode);
        }
    }
    
    void printNames()
    {
        Node *temp = n_Head;
        std::cout << "\nNames & weights sorted(ascending) by name:\n";
        while (temp != NULL)
        {
            std::cout << temp->name << " - " << temp->weight << std::endl;
            temp = temp->n_Next;
        }
    }
        
    void printWeights()
    {
        Node *temp = w_Head;
        std::cout << "\nNames & weights sorted(ascending) by weight:\n";
        while (temp != NULL)
        {
            std::cout << temp->name << " - " << temp->weight << std::endl;
            temp = temp->w_Next;
        }
    }

private:
        
        void insert_name(Node * newNode) {
            Node* n_Target = n_Head;
            bool targetFound = false;
            
            while(n_Target->n_Next != NULL && targetFound == false)
            {
                if (n_Target->name.compare(newNode->name) >= 0) {
                    targetFound = true;
                }
                
                if (n_Target == n_Head && n_Target->n_Next == NULL) {
                    break;
                }
                
                n_Target = n_Target->n_Next;
                //printf("Debug name\n");
                //newNode->toString();
                //n_Target->toString();
                //n_Head->toString();
            }
            
            if (n_Target == this->n_Head) {
                if (n_Target->name.compare(newNode->name) >= 0) {
                    n_Head = newNode;
                    newNode->n_Next = n_Target;
                    n_Target->n_Prev;
                }
                else {
                    n_Target->n_Next = newNode;
                    newNode->n_Prev = n_Target;
                }
            } else if (!targetFound) {
                n_Target->n_Next = newNode;
                newNode->n_Prev = n_Target;
            } else {
                newNode->n_Prev = n_Target->n_Prev;
                n_Target->n_Prev = newNode;
                newNode->n_Next = n_Target;
                newNode->n_Prev->n_Next = newNode;
            }
        }
        
        void insert_weight(Node * newNode) {
            Node* w_Target = w_Head;
            bool targetFound = false;
            
            while(w_Target->w_Next != NULL && targetFound == false)
            {
                if (w_Target->weight >= newNode->weight) {
                    targetFound = true;
                }

                if (w_Target == w_Head && w_Target->w_Next == NULL) {
                    break;
                }
                
                w_Target = w_Target->w_Next;
            }
            
            if (w_Target == this->w_Head) {
                if (w_Target->weight >= newNode->weight) {
                    w_Head = newNode;
                    newNode->w_Next = w_Target;
                    w_Target->w_Prev;
                } else {
                    w_Target->w_Next = newNode;
                    newNode->w_Prev = w_Target;
                }
            } else if (!targetFound) {
                w_Target->w_Next = newNode;
                newNode->w_Prev = w_Target;
            } else {
                newNode->w_Prev = w_Target->w_Prev;
                w_Target->w_Prev = newNode;
                newNode->w_Next = w_Target;
                newNode->w_Prev->w_Next = newNode;
            }
        }
};


int main()
{
    DLL *roster = new DLL();
    
    std::ifstream file("./Names.txt");
    std::string str;
    
    int isFirstEntry = 1;
    while (std::getline(file, str))
    {
        
        std::string name = str;
        std::getline(file, str);
        int weight;
        weight = std::atoi(str.c_str());
        
        roster->insert(name, weight);
        roster->printNames();
        roster->printWeights();
    }
    
    /*
    std::cout << "Enter first name: ";
    std::cin >> name;
    std::cout << "And first weight: ";
    std::cin >> weight;
    std::cout << std::endl;
    roster->makeList(name, weight);
    
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Enter next name: ";
        std::cin >> name;
        std::cout << "And next weight: ";
        std::cin >> weight;
        std::cout << std::endl;
        roster->insertion(name, weight);
    }*/
    
    roster->printNames();
    roster->printWeights();
    return 0;
}
