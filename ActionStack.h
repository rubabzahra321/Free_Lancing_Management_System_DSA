#ifndef ACTIONSTACK_H
#define ACTIONSTACK_H
#include <iostream>
using namespace std;

class ActionStack {
    string undoStack[20];
    string redoStack[20];
    int utop, rtop;

public:
    ActionStack() {
        utop = -1;
        rtop = -1;
    }

    void push(string action) {
        undoStack[++utop] = action;
        rtop = -1; // clear redo
    }

    void undo() {
        if (utop < 0) {
            cout << "Nothing to undo\n";
            return;
        }
        string action = undoStack[utop--];
        redoStack[++rtop] = action;
        cout << "Undo: " << action << endl;
    }

    void redo() {
        if (rtop < 0) {
            cout << "Nothing to redo\n";
            return;
        }
        string action = redoStack[rtop--];
        undoStack[++utop] = action;
        cout << "Redo: " << action << endl;
    }
};
#endif
