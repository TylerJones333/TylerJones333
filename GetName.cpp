//
//  main.cpp
//  Program 4
//
//  Created by Tyler Jones on 5/1/17.
//  Copyright © 2017 Tyler Jones. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <fstream>
#include <math.h>

using namespace std;

class node
{
    public:
    node();
    node* next;
    string getName();
    int getNum();
    int getScope();
    void setName(string);
    void setNum(int);
    void setScope(int);
    private:
    string name;
    int number;
    int scoping;
};
node::node(){
    next = 0;
    name = "";
    number = 0;
    scoping = 0;
}
string node::getName(){
    return name;
}
int node::getNum(){
    return number;
}
int node::getScope(){
    return scoping;
}
void node::setName(string s){
    name = s;
}
void node::setScope(int x){
    scoping = x;
}
void node::setNum(int x){
    number = x;
}
int hashString(string s){
    int hash=0,size = s.size();
    for(int i= 0;i<size+1;i++)
    {
        hash += (int) s[i] * i;
    }
    return hash % 7;
}
//int hashString(string s);
int main()
{
    int curr_scope=0,num_line=0;
    node ht;
    node table[7];
    //node hashString;
    ifstream myfile ("/Users/Tyler/Desktop/Program4.txt");
    if (myfile.is_open()){
        string s;
        while (getline (myfile,s))
        {
            num_line++;
            stringstream line(s);
            line >> s;
            if(s == "START")
            {
                curr_scope++;
                while(line >> s);
            }
            else if(s == "FINISH")
            {
                curr_scope--;
                while(line >> s);
            }
            else if(s == "COM")
            {
                while(line >> s);
            }
            else if(s == "VAR")
            {
                node temp;
                line >> s;
                cout << s << endl;
                temp.setName(s);
                line >> s;
                if(s == "=")
                {
                    line >> s;
                    cout << "IS ";
                    cout << s << endl;
                    temp.setNum(atoi(s.c_str()));
                    temp.setScope(curr_scope);
                    // if(table[hashString(temp.getName())] != 0)
                    // {
                    temp.next = &table[hashString(temp.getName())];
                    table[hashString(temp.getName())] = temp;
                    while(line >> s);
                    // }
                    // else if(table[hashString(temp.getName())] == 0)
                    // {
                    // table[hashString(temp.getName())] = temp;
                    // while(line >> s);
                    // }
                    //else
                    //{
                    // cout << "UNABLE TO ADD " << temp.getName() << "TO THE TABLE" << endl;
                    // while(line >> s);
                    // }
                }
            }
            else if(s == "PRINT")
            {
                line >> s;
                node temp = table[hashString(s)];
                if(temp.getScope() == curr_scope)
                {
                    if(line >> s)
                    {
                        if(s == "++")
                        {
                            cout << temp.getName() << " IS " << temp.getNum() + 1 << endl;
                            while(line >> s);
                        }
                        else if(s == "--")
                        {
                            cout << temp.getName() << " IS " << temp.getNum() - 1 << endl;
                            while(line >> s);
                        }
                        else if(s == "+")
                        {
                            line >> s;
                            cout << temp.getName() << " IS " << temp.getNum() + atoi(s.c_str()) << endl;
                            while(line >> s);
                        }
                        else if(s == "-")
                        {
                            line >> s;
                            cout << temp.getName() << " IS " << temp.getNum() - atoi(s.c_str()) << endl;
                            while(line >> s);
                        }
                        else if(s == "/")
                        {
                            line >> s;
                            cout << temp.getName() << " IS " << temp.getNum() / atoi(s.c_str()) << endl;
                            while(line >> s);
                        }
                        else if(s == "*")
                        {
                            line >> s;
                            cout << temp.getName() << " IS " << temp.getNum() * atoi(s.c_str()) << endl;
                            while(line >> s);
                        }
                        else if(s == "%")
                        {
                            line >> s;
                            cout << temp.getName() << " IS " << temp.getNum() % atoi(s.c_str()) << endl;
                            while(line >> s);
                        }
                        else if(s == "^")
                        {
                            line >> s;
                            cout << temp.getName() << " IS " << pow(temp.getNum(),atoi(s.c_str())) << endl;
                            while(line >> s);
                        }
                    }
                }
                else
                {
                    cout << s << "IS UNDEFINED" << endl;
                    cout << "ERROR HAS OCCURED ON LINE " << num_line << endl;
                    while(line >> s);
                }
            }
            else
            {
                if(table[hashString(s)].getName() == s)
                {
                    node temp = table[hashString(s)];
                    line >> s;
                    if(s == "=")
                    {
                        if(temp.getScope() == curr_scope){
                            line >> s;
                            temp.setNum(atoi(s.c_str()));
                            while(line >> s);
                        }
                    }
                    else if(s == "++")
                    {
                        //table[hash(temp)].setNum(table[hash(temp)].getNum()+1);
                        while(line >> s);
                    }
                    else if(s == "--")
                    {
                        //table[hash(temp)].setNum(table[hash(temp)].getNum()-1);
                        while(line >> s);
                    }
                }
                else
                cout << s << " IS UNDEFINED" << endl;
            }
        }
        myfile.close();
    }
    return 0;
}
