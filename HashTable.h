#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "User.h"

class HashTable
{
    User *table[10];

    int hash(string id)
    {
        return id[0] % 10;
    }

public:
    HashTable()
    {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    void insert(User *u)
    {
        int idx = hash(u->id);
        u->next = table[idx];
        table[idx] = u;
    }

    User *search(string id)
    {
        int idx = hash(id);
        User *cur = table[idx];
        while (cur)
        {
            if (cur->id == id)
                return cur;
            cur = cur->next;
        }
        return NULL;
    }

    void banUser(string id)
    {
        User *u = search(id);
        if (u)
        {
            u->banned = true;
            cout << "User banned successfully.\n";
        }
        else
        {
            cout << "User not found.\n";
        }
    }

    void display()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "| ID       | Name               | Role      | Status       |" << endl;
        cout << "-----------------------------------------------------------" << endl;

        for (int i = 0; i < 10; i++)
        {
            User *cur = table[i];
            while (cur)
            {
                // ID
                cout << "| " << cur->id;
                for (int j = cur->id.length(); j < 9; j++)
                    cout << " ";

                // Name
                cout << "| " << cur->name;
                for (int j = cur->name.length(); j < 18; j++)
                    cout << " ";

                // Role
                cout << "| " << cur->role;
                for (int j = cur->role.length(); j < 9; j++)
                    cout << " ";

                // Status
                string status = cur->banned ? "BANNED" : "ACTIVE";
                cout << "| " << status;
                for (int j = status.length(); j < 13; j++)
                    cout << " ";

                cout << "|" << endl;
                cur = cur->next;
            }
        }

        cout << "-----------------------------------------------------------" << endl;
    }
};
#endif
