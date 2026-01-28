#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Proposal.h"

class MaxHeap {
    Proposal* arr[20];
    int size;

public:
    MaxHeap() { size = 0; }

    void insert(Proposal* p) {
        arr[size++] = p;
    }

    Proposal* best() {
        Proposal* best = NULL;
        for (int i = 0; i < size; i++) {
            if (arr[i]->withdrawn) continue;
            if (!best || arr[i]->score() > best->score())
                best = arr[i];
        }
        if (best) best->selected = true;
        return best;
    }
};
#endif
