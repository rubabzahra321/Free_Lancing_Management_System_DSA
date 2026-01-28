#ifndef PROPOSAL_H
#define PROPOSAL_H
#include <iostream>
using namespace std;

class Proposal {
public:
    string freelancer;
    int bid;
    float rating;
    bool withdrawn;
    bool selected;
    Proposal* next;

    Proposal(string f="", int b=0, float r=0) {
        freelancer = f;
        bid = b;
        rating = r;
        withdrawn = false;
        selected = false;
        next = NULL;
    }

    float score() {
        return rating * 10 - bid;
    }
};
#endif
