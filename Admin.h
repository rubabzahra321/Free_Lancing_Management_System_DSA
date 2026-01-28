#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

#include "HashTable.h"
#include "AVLTree.h"
#include "JobQueue.h"
#include "ActionStack.h"
#include "Project.h"

class Admin
{
public:
    static bool adminExists;
    int approvedCount;   // ✅ ADDED

    Admin() {
        approvedCount = 0;
    }

    void viewUsers(HashTable &h)
    {
        h.display();
    }

    void approveProject(Project *p, JobQueue &q, ActionStack &s)
    {
        if (p->approved)
        {
            cout << "Project already approved.\n";
            return;
        }

        p->approved = true;
        approvedCount++;           // ✅ COUNT TRACKING
        q.enqueue(p);

        s.push("Admin approved project: " + p->title);
        cout << "Project approved and added to job queue.\n";
    }

    void processJobs(JobQueue &q, ActionStack &s)
    {
        q.process();
        s.push("Admin processed a job");
    }

    void completeProject(Project *p, ActionStack &s)
    {
        if (!p->approved)
        {
            cout << "Project is not approved yet." << endl;
            return;
        }

        if (p->completed)
        {
            cout << "Project already completed." << endl;
            return;
        }

        p->completed = true;
        s.push("Project completed: " + p->title);
        cout << "Project marked as completed." << endl;
    }

    // ✅ ADMIN MONITORING (Proposal Requirement)
    void monitorSystem()
    {
        cout << "================ SYSTEM STATUS ================" << endl;
        cout << "Total Approved Projects: " << approvedCount << endl;
        cout << "================================================" << endl;
    }
};

bool Admin::adminExists = false;

#endif
