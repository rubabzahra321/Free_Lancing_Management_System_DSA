#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>
using namespace std;

class Project {
public:
    string id, title;
    int budget;
    bool approved;
    bool completed;      
    Project* left;
    Project* right;

    Project(string i="", string t="", int b=0) {
        id = i;
        title = t;
        budget = b;
        approved = false;
        completed = false; 
        left = right = nullptr;
    }
};

#endif
