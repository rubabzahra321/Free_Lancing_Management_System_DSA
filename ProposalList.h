#ifndef PROPOSALLIST_H
#define PROPOSALLIST_H
#include "Proposal.h"

class ProposalList {
public:
    Proposal* head;

    ProposalList() {
        head = NULL;
    }

    void add(Proposal* p) {
        p->next = head;
        head = p;
    }

    void withdraw(string freelancer) {
        Proposal* cur = head;
        while (cur) {
            if (cur->freelancer == freelancer) {
                cur->withdrawn = true;
                cout << "Proposal withdrawn\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Proposal not found\n";
    }

    void update(string freelancer, int newBid) {
        Proposal* cur = head;
        while (cur) {
            if (cur->freelancer == freelancer && !cur->withdrawn) {
                cur->bid = newBid;
                cout << "Proposal updated\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Proposal not found\n";
    }

    void show() {
        Proposal* c = head;
        while (c) {
            if (!c->withdrawn) {
                cout << c->freelancer
                     << " Bid:" << c->bid
                     << " Score:" << c->score()
                     << (c->selected ? " [SELECTED]" : "") << endl;
            }
            c = c->next;
        }
    }
};
#endif
