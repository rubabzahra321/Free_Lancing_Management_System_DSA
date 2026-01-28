#ifndef JOBQUEUE_H
#define JOBQUEUE_H
#include "Project.h"

class JobQueue {
    Project* arr[20];
    int front, rear;
public:
    JobQueue() { front=rear=0; }

    void enqueue(Project* p) {
        arr[rear++] = p;
    }

    void process() {
        if(front==rear) {
            cout<<"No jobs" <<endl; return;
        }
        cout<<"Processing: "<<arr[front++]->title<<endl;
    }
};
#endif
