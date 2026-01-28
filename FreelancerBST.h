#ifndef FREELANCERBST_H
#define FREELANCERBST_H
#include <iostream>
using namespace std;

class FreelancerNode {
public:
    string name;
    float rating;
    FreelancerNode* left;
    FreelancerNode* right;

    FreelancerNode(string n, float r) {
        name = n;
        rating = r;
        left = right = NULL;
    }
};

class FreelancerBST {
public:
    FreelancerNode* root;

    FreelancerBST() { root = NULL; }

    FreelancerNode* insert(FreelancerNode* r, string name, float rating) {
        if (!r) return new FreelancerNode(name, rating);
        if (rating < r->rating)
            r->left = insert(r->left, name, rating);
        else
            r->right = insert(r->right, name, rating);
        return r;
    }

    void inorder(FreelancerNode* r) {
        if (!r) return;
        inorder(r->right);
        cout << r->name << " Rating: " << r->rating << endl;
        inorder(r->left);
    }
};
#endif
