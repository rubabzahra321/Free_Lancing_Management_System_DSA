#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include "Project.h"
using namespace std;

class AVLTree
{
public:
    Project *root;

    AVLTree() { root = nullptr; }

    Project *insert(Project *r, Project *p)
    {
        if (!r)
            return p;
        if (p->id < r->id)
            r->left = insert(r->left, p);
        else
            r->right = insert(r->right, p);
        return r;
    }

    void inorder(Project *r)
{
    if(!r) return;
    inorder(r->left);

    if(r->approved)
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "| Project ID | Title                 | Budget  | Status       |" << endl;
        cout << "-----------------------------------------------------------" << endl;

        // Project ID
        cout << "| " << r->id;
        for(int j=r->id.length(); j<11; j++) cout << " ";

        // Title
        cout << "| " << r->title;
        for(int j=r->title.length(); j<22; j++) cout << " ";

        // Budget
        string budgetStr = to_string(r->budget);
        cout << "| $" << budgetStr;
        for(int j=budgetStr.length(); j<7; j++) cout << " ";

        // Status
        string status = r->completed ? "COMPLETED" : "IN PROGRESS";
        cout << "| " << status;
        for(int j=status.length(); j<13; j++) cout << " ";

        cout << "|" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }

    inorder(r->right);
}

};

#endif
