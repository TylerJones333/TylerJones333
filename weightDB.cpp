//
//     Created by Tyler Jones
//     CS38 Data Structures
//     12 March 2017
//

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;


class Node {
    
public:
    string name;
    int weight;
    Node* n_next;
    Node* n_prev;
    Node* w_next;
    Node* w_prev;
    //Declare Each node
    Node(string name, int weight) {
    this->name = name;
    this->weight = weight;
}

};


class WeightDB {
    
public:
    int length;
    Node* n_head;
    Node* w_head;
    //Call the Public and private fucntions
    WeightDB() {
        int length = 0;
        Node* n_head;
        Node* w_head;
    }
    
    void insert(string, int);
    void print_DB_by_name();
    void print_DB_by_weight();
    
private:
    Node* find_target_name(Node*);
    Node* find_target_weight(Node*);
};



void WeightDB::insert(string name, int weight) {
    Node* newNode = new Node(name, weight);
    
    //if the list is empty
    if (length == 0) {
        n_head = newNode;
        w_head = newNode;
    }
    //if the list has 1 item
    else if (length == 1) {
        //sorted isert by name
        if (newNode->name.compare(n_head->name) <= 0) {
            newNode->n_next = n_head;
            n_head->n_prev = newNode;
            n_head = newNode;
        }
        else {
            n_head->n_next = newNode;
            newNode->n_prev = n_head;
        }
        
        //sorted insert by weight
        if (newNode->weight <= w_head->weight) {
            newNode->w_next = w_head;
            w_head->w_prev = newNode;
            w_head = newNode;
        }
        else {
            w_head->w_next = newNode;
            newNode->w_prev = w_head;
        }
    }
    //all other cases
    else {
        //sorted insert by name. The newNode will be placed after the target
        Node* n_target = this->find_target_name(newNode);
        
        //if newNode's name is alphabetically higher than the entire list's
        if (n_target == NULL) {
            newNode->n_next = n_head;
            n_head->n_prev = newNode;
            n_head = newNode;
        }
        //if the target is the last element
        else if (n_target->n_next == NULL) {
            n_target->n_next = newNode;
            newNode->n_prev = n_target;
        }
        //if the target is in the middle somewhere
        else {
            newNode->n_next = n_target->n_next;
            newNode->n_prev = n_target;
            n_target->n_next->n_prev = newNode;
            n_target->n_next = newNode;
        }
        
        //sorted insert by weight. The newNode will be placed after the target
        Node* w_target = this->find_target_weight(newNode);
        
        //if newNode's weight is smaller than the entire list's
        if (w_target == NULL) {
            newNode->w_next = w_head;
            w_head->w_prev = newNode;
            w_head = newNode;
        }
        //if the target is the last element
        else if (w_target->w_next == NULL) {
            w_target->w_next = newNode;
            newNode->w_prev = w_target;
        }
        //if the target is in the middle somewhere
        else {
            newNode->w_next = w_target->w_next;
            newNode->w_prev = w_target;
            w_target->w_next->w_prev = newNode;
            w_target->w_next = newNode;
        }

    }
    
    length++;
}

void WeightDB::print_DB_by_name() {
    cout << "Here is the database sorted by Name:" << endl;
    Node* temp = this->n_head;
    
    while (temp != NULL) {
        cout << temp->name << " - " << temp->weight << endl;
        temp = temp->n_next;
    }
}

void WeightDB::print_DB_by_weight() {
    cout << "Here is the databse sorted by weight:" << endl;
    Node* temp = this->w_head;
    
    while (temp != NULL) {
        cout << temp->name << " - " << temp->weight << endl;
        temp = temp->w_next;
    }
}

Node* WeightDB::find_target_name(Node* newNode) {
    if (newNode->name.compare(this->n_head->name) <= 0) {
        return NULL;
    }
    
    Node* target = this->n_head;
    
    while (target->n_next != NULL) {
        if (newNode->name.compare(target->n_next->name) <= 0) {
            break;
        }
        
        target = target->n_next;
    }

    return target;
}

Node* WeightDB::find_target_weight(Node* newNode) {
    if (newNode->weight <= this->w_head->weight) {
        return NULL;
    }
        
    Node* target = this->w_head;
    
    while (target->w_next != NULL) {
        if (newNode->weight <= target->w_next->weight) {
            break;
        }
        
        target = target->w_next;
    }
    
    return target;
}

int main(int argc, char** argv) {
    WeightDB* myDB = new WeightDB();
    
        
        std::ifstream file("./Names.txt");
        std::string str;
        
        int isFirstEntry = 1;
        while (std::getline(file, str))
        {
            
            std::string name = str;
            std::getline(file, str);
            int weight;
            weight = std::atoi(str.c_str());
            
            myDB->insert(name, weight);
        }
    
    myDB->print_DB_by_name();;
    myDB->print_DB_by_weight();;
}

/*
 Here is the database sorted by Name:
 Abe - 199
 Annabelle - 99
 April - 117
 Bob - 156
 Bobby - 109
 Brian - 150
 Chris - 175
 Claire - 124
 Jason - 182
 Jim - 150
 Kevin - 145
 Michael - 174
 Richard - 200
 Steven - 164
 Tom - 212
 
 Here is the databse sorted by weight:
 Annabelle - 99
 Bobby - 109
 April - 117
 Claire - 124
 Kevin - 145
 Brian - 150
 Jim - 150
 Bob - 156
 Steven - 164
 Michael - 174
 Chris - 175
 Jason - 182
 Abe - 199
 Richard - 200
 Tom - 212
*/
