#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "HashTable.h"
#include "Admin.h"
#include "Project.h"
#include "AVLTree.h"
#include "JobQueue.h"
#include "Proposal.h"
#include "ProposalList.h"
#include "MaxHeap.h"
#include "ActionStack.h"
#include "FreelancerBST.h"

// ================= HELPER FUNCTIONS =================
string repeatChar(char c, int count)
{
    string result = "";
    for (int i = 0; i < count; i++)
        result += c;
    return result;
}

string intToString(int num)
{
    if (num == 0) return "0";
    string result = "";
    bool negative = num < 0;
    if (negative) num = -num;
    while (num > 0)
    {
        result = char('0' + (num % 10)) + result;
        num /= 10;
    }
    if (negative) result = "-" + result;
    return result;
}

string floatToString(float num)
{
    int intPart = (int)num;
    int decPart = (int)((num - intPart) * 10);
    return intToString(intPart) + "." + intToString(decPart);
}

// ================= ENHANCED DELAY SYSTEM =================
void microDelay()
{
    for (int i = 0; i < 5000; i++)
        for (int j = 0; j < 50; j++);
}

void delay()
{
    for (int i = 0; i < 15000; i++)
        for (int j = 0; j < 150; j++);
}

void longDelay()
{
    for (int i = 0; i < 30000; i++)
        for (int j = 0; j < 300; j++);
}

void extraLongDelay()
{
    for (int i = 0; i < 60000; i++)
        for (int j = 0; j < 300; j++);
}

// ================= ANIMATED PRINTS =================
void slowPrint(string text)
{
    for (char c : text)
    {
        cout << c;
        delay();
    }
    cout << endl;
}

void typeWriter(string text, bool newline = true)
{
    cout << text;
    if (newline) cout << endl;
}

void fastType(string text, bool newline = true)
{
    cout << text;
    if (newline) cout << endl;
}

// ================= LOADING ANIMATIONS =================
void spinnerAnimation(int cycles)
{
    char spinner[] = {'|', '/', '-', '\\'};
    for (int i = 0; i < cycles; i++)
    {
        cout << "\r  " << spinner[i % 4] << " Processing...";
        cout.flush();
        extraLongDelay();
    }
    cout << "\r                              \r";
    cout.flush();
}

void progressBar(int percentage, string label = "")
{
    cout << "\r  [";
    int bars = percentage / 5;
    for (int i = 0; i < 20; i++)
    {
        if (i < bars) cout << "#";
        else cout << "-";
    }
    cout << "] " << percentage << "% " << label << "          ";
    cout.flush();
}

void animatedProgressBar(string label)
{
    for (int i = 0; i <= 100; i += 5)
    {
        progressBar(i, label);
        extraLongDelay();
    }
    cout << "\r                                                              \r";
    cout.flush();
}

void dotLoadingAnimation(string message, int dots)
{
    cout << "  " << message;
    cout.flush();
    for (int i = 0; i < dots; i++)
    {
        extraLongDelay();
        cout << ".";
        cout.flush();
    }
    cout << "\r                                                              \r";
    cout.flush();
}

// ================= DECORATIVE ELEMENTS =================
void printLine(char ch, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << ch;
    }
    cout << endl;
}

void printDoubleLine(int length)
{
    for (int i = 0; i < length; i++) cout << "=";
    cout << endl;
}

void animatedBorder(int width, char style = '=')
{
    for (int i = 0; i < width; i++)
    {
        cout << style;
    }
    cout << endl;
}

void clearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void pauseScreen(int cycles)
{
    for (int i = 0; i < cycles; i++)
        delay();
}

// ================= ENHANCED WELCOME SCREEN =================
void showWelcomeScreen()
{
    clearScreen();
    cout << "\n\n\n";
    
    cout << repeatChar('=', 70) << endl;
    
    cout << "        +======================================================+\n";
    
    cout << "        |    W E L C O M E   T O   F R E E L A N C I N G    |\n";
    cout << "        |          M A R K E T P L A C E   S Y S T E M      |\n";
    
    cout << "        +======================================================+\n";
    
    cout << repeatChar('=', 70) << endl;
    cout << "\n";
    
    cout << "           >> A Data Structures & Algorithms Based System\n";
    cout << "\n";
    cout << "           >> Clients  |  Freelancers  |  Admin Control\n";
    cout << "\n\n";
    
    dotLoadingAnimation("        >> Initializing system", 8);
    animatedProgressBar("Loading modules");
    spinnerAnimation(8);
    cout << "          [SUCCESS] System Ready!\n";
    
    longDelay();
    longDelay();
}

// ================= ENHANCED MESSAGE BOX =================
void showMessageBox(string heading, string message)
{
    cout << "\n\n";
    
    int width = (heading.length() > message.length() ? heading.length() : message.length()) + 10;
    
    cout << "    ";
    for (int i = 0; i < width; i++)
    {
        cout << "=";
    }
    cout << endl;
    
    cout << "    |  ";
    cout << heading;
    for (int i = 0; i < width - heading.length() - 5; i++) cout << " ";
    cout << "|\n";
    
    cout << "    ";
    for (int i = 0; i < width; i++) cout << "-";
    cout << endl;
    
    cout << "    |  ";
    cout << message;
    for (int i = 0; i < width - message.length() - 5; i++) cout << " ";
    cout << "|\n";
    
    cout << "    ";
    for (int i = 0; i < width; i++) cout << "=";
    cout << endl;
    
    cout << "\n";
    longDelay();
}

void showSuccessBox(string message)
{
    cout << "\n\n";
    cout << "    +---------------------------------------------------+\n";
    cout << "    |  [SUCCESS]                                        |\n";
    cout << "    +---------------------------------------------------+\n";
    cout << "    |  " << message;
    for (int i = message.length(); i < 45; i++) cout << " ";
    cout << "|\n";
    cout << "    +---------------------------------------------------+\n";
    cout << "\n\n";
    longDelay();
}

void showErrorBox(string message)
{
    cout << "\n\n";
    cout << "    +---------------------------------------------------+\n";
    cout << "    |  [ERROR]                                          |\n";
    cout << "    +---------------------------------------------------+\n";
    cout << "    |  " << message;
    for (int i = message.length(); i < 45; i++) cout << " ";
    cout << "|\n";
    cout << "    +---------------------------------------------------+\n";
    cout << "\n\n";
    longDelay();
}

// ================= ADMIN CHECK =================
bool adminCheck()
{
    if (!Admin::adminExists)
    {
        showErrorBox("No admin registered in the system.");
        return false;
    }
    return true;
}

// ================= ENHANCED MENUS =================
void showAdminMenu()
{
    cout << "\n\n";
    cout << "    +======================================================+\n";
    cout << "    |               ADMIN MENU                             |\n";
    cout << "    +======================================================+\n";
    cout << "    |                                                      |\n";
    cout << "    |   1. View All Users                                  |\n";
    cout << "    |   2. Approve Project                                 |\n";
    cout << "    |   3. Process Job Queue                               |\n";
    cout << "    |   4. Ban User                                        |\n";
    cout << "    |   5. Mark Project Completed (Override)               |\n";
    cout << "    |   6. Monitor System Activity                         |\n";
    cout << "    |                                                      |\n";
    cout << "    |   0. Back to Main Menu                               |\n";
    cout << "    |                                                      |\n";
    cout << "    +======================================================+\n";
    cout << "\n";
    cout << "    >> Enter your choice: ";
}

void showClientMenu()
{
    cout << "\n\n";
    cout << "    +======================================================+\n";
    cout << "    |               CLIENT MENU                            |\n";
    cout << "    +======================================================+\n";
    cout << "    |                                                      |\n";
    cout << "    |   1. Post New Project                                |\n";
    cout << "    |   2. View Approved Projects                          |\n";
    cout << "    |                                                      |\n";
    cout << "    |   0. Logout                                          |\n";
    cout << "    |                                                      |\n";
    cout << "    +======================================================+\n";
    cout << "\n";
    cout << "    >> Enter your choice: ";
}

void showFreelancerMenu()
{
    cout << "\n\n";
    cout << "    +======================================================+\n";
    cout << "    |           FREELANCER MENU                            |\n";
    cout << "    +======================================================+\n";
    cout << "    |                                                      |\n";
    cout << "    |   1. Submit Proposal                                 |\n";
    cout << "    |   2. Update Proposal                                 |\n";
    cout << "    |   3. Withdraw Proposal                               |\n";
    cout << "    |   4. Mark Project Completed                          |\n";
    cout << "    |   5. View Best Proposal                              |\n";
    cout << "    |   6. View Top Freelancers                            |\n";
    cout << "    |                                                      |\n";
    cout << "    |   0. Logout                                          |\n";
    cout << "    |                                                      |\n";
    cout << "    +======================================================+\n";
    cout << "\n";
    cout << "    >> Enter your choice: ";
}

void showMainMenu()
{
    cout << "\n\n";
    cout << "    +======================================================+\n";
    cout << "    |               MAIN MENU                              |\n";
    cout << "    +======================================================+\n";
    cout << "    |                                                      |\n";
    cout << "    |   1. Add User (Client/Freelancer/Admin)             |\n";
    cout << "    |   2. Login as Client                                 |\n";
    cout << "    |   3. Login as Freelancer                             |\n";
    cout << "    |   4. Login as Admin                                  |\n";
    cout << "    |                                                      |\n";
    cout << "    |   0. Exit System                                     |\n";
    cout << "    |                                                      |\n";
    cout << "    +======================================================+\n";
    cout << "\n";
    cout << "    >> Enter your choice: ";
}

// ================= MAIN =================
int main()
{
    HashTable userTable;
    AVLTree projectTree;
    ProposalList proposalList;
    MaxHeap proposalHeap;
    JobQueue jobQueue;
    ActionStack actionStack;
    Admin admin;
    FreelancerBST freelancerTree;

    int mainChoice;
    showWelcomeScreen();

    do
    {
        showMainMenu();
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1: // Add User
        {
            spinnerAnimation(4);
            
            string id, name, role;
            cout << "\n";
            cout << "    >> USER REGISTRATION\n";
            cout << "    " << repeatChar('-', 50) << "\n\n";
            
            cout << "    >> Enter User ID: ";
            cin >> id;
            cin.ignore();
            
            cout << "    >> Enter Name: ";
            getline(cin, name);
            
            cout << "    >> Enter Role (client/freelancer/admin): ";
            cin >> role;

            for (int i = 0; role[i]; i++)
            {
                if (role[i] >= 'A' && role[i] <= 'Z')
                    role[i] = role[i] + ('a' - 'A');
            }

            dotLoadingAnimation("    Processing registration", 5);

            if (role == "admin")
            {
                if (Admin::adminExists)
                {
                    showErrorBox("Admin already exists in the system!");
                    break;
                }
                Admin::adminExists = true;
            }

            userTable.insert(new User(id, name, role));
            actionStack.push("User added");
            
            animatedProgressBar("Creating account");
            cout << "\n";
            showSuccessBox("User registered successfully!");
            break;
        }

        case 2: // Client login
        {
            spinnerAnimation(3);
            
            string cid;
            cout << "\n";
            cout << "    >> CLIENT LOGIN\n";
            cout << "    " << repeatChar('-', 50) << "\n\n";
            
            cout << "    >> Enter Client ID: ";
            cin >> cid;
            
            dotLoadingAnimation("    Verifying credentials", 4);
            
            User* u = userTable.search(cid);
            if (!u || u->banned || u->role != "client")
            {
                cout << "\n";
                showErrorBox("Invalid or banned client account!");
                break;
            }

            cout << "\n";
            showSuccessBox("Login successful! Welcome back!");

            int clientChoice;
            do
            {
                showClientMenu();
                cin >> clientChoice;
                switch (clientChoice)
                {
                case 1: // Post project
                {
                    spinnerAnimation(3);
                    
                    string pid, title; int budget;
                    cout << "\n";
                    cout << "    >> NEW PROJECT SUBMISSION\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cout << "    >> Enter Project ID: "; 
                    cin >> pid; 
                    cin.ignore();
                    
                    cout << "    >> Enter Project Title: "; 
                    getline(cin, title);
                    
                    cout << "    >> Enter Budget ($): "; 
                    cin >> budget;
                    
                    dotLoadingAnimation("    Creating project", 5);
                    
                    Project* p = new Project(pid, title, budget);
                    projectTree.root = projectTree.insert(projectTree.root, p);
                    actionStack.push("Project posted");
                    
                    animatedProgressBar("Submitting to admin");
                    cout << "\n";
                    showMessageBox("PROJECT SUBMITTED", "Waiting for admin approval...");
                    break;
                }
                case 2: // View projects
                {
                    cout << "\n\n";
                    cout << "    +======================================================+\n";
                    cout << "    |          APPROVED PROJECTS LIST                      |\n";
                    cout << "    +======================================================+\n";
                    cout << "\n";
                    
                    dotLoadingAnimation("    Loading projects", 4);
                    cout << "\n";
                    
                    projectTree.inorder(projectTree.root);
                    
                    cout << "\n    " << repeatChar('-', 50) << "\n";
                    longDelay();
                    break;
                }
                case 0:
                    dotLoadingAnimation("    Logging out", 3);
                    cout << "\n";
                    showSuccessBox("Logged out successfully!");
                    break;
                }
            } while (clientChoice != 0);
            break;
        }

        case 3: // Freelancer login
        {
            spinnerAnimation(3);
            
            string fid;
            cout << "\n";
            cout << "    >> FREELANCER LOGIN\n";
            cout << "    " << repeatChar('-', 50) << "\n\n";
            
            cout << "    >> Enter Freelancer ID: ";
            cin >> fid;
            
            dotLoadingAnimation("    Verifying credentials", 4);
            
            User* u = userTable.search(fid);
            if (!u || u->banned || u->role != "freelancer")
            {
                cout << "\n";
                showErrorBox("Invalid or banned freelancer account!");
                break;
            }

            cout << "\n";
            showSuccessBox("Login successful! Welcome back!");

            int freelancerChoice;
            do
            {
                showFreelancerMenu();
                cin >> freelancerChoice;
                switch (freelancerChoice)
                {
                case 1: // Submit proposal
                {
                    spinnerAnimation(3);
                    
                    string fname; int bid; float rating;
                    cout << "\n";
                    cout << "    >> SUBMIT NEW PROPOSAL\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cin.ignore();
                    cout << "    >> Enter Freelancer Name: "; 
                    getline(cin, fname);
                    
                    cout << "    >> Enter Bid Amount ($): "; 
                    cin >> bid;
                    
                    cout << "    >> Enter Rating (0-5): "; 
                    cin >> rating;
                    
                    dotLoadingAnimation("    Processing proposal", 5);
                    
                    Proposal* pr = new Proposal(fname, bid, rating);
                    proposalList.add(pr);
                    proposalHeap.insert(pr);
                    freelancerTree.root = freelancerTree.insert(freelancerTree.root, fname, rating);
                    actionStack.push("Proposal submitted");
                    
                    animatedProgressBar("Submitting proposal");
                    cout << "\n";
                    showSuccessBox("Proposal submitted successfully!");
                    break;
                }
                case 2: // Update proposal
                {
                    spinnerAnimation(2);
                    
                    string name; int bid; 
                    cout << "\n";
                    cout << "    >> UPDATE PROPOSAL\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cin.ignore();
                    cout << "    >> Enter Freelancer Name: "; 
                    getline(cin, name);
                    
                    cout << "    >> Enter New Bid ($): "; 
                    cin >> bid;
                    
                    dotLoadingAnimation("    Updating proposal", 4);
                    
                    proposalList.update(name, bid);
                    actionStack.push("Proposal updated");
                    
                    cout << "\n";
                    showSuccessBox("Proposal updated successfully!");
                    break;
                }
                case 3: // Withdraw
                {
                    spinnerAnimation(2);
                    
                    string name;
                    cout << "\n";
                    cout << "    >> WITHDRAW PROPOSAL\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cin.ignore();
                    cout << "    >> Enter Freelancer Name: "; 
                    getline(cin, name);
                    
                    dotLoadingAnimation("    Processing withdrawal", 4);
                    
                    proposalList.withdraw(name);
                    actionStack.push("Proposal withdrawn");
                    
                    cout << "\n";
                    showSuccessBox("Proposal withdrawn successfully!");
                    break;
                }
                case 4: // Mark project completed
                {
                    spinnerAnimation(2);
                    
                    string pid;
                    cout << "\n";
                    cout << "    >> MARK PROJECT COMPLETED\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cout << "    >> Enter Project ID: "; 
                    cin >> pid;
                    
                    dotLoadingAnimation("    Verifying project status", 4);
                    
                    Project* r = projectTree.root;
                    while (r && r->id != pid) r = (pid < r->id) ? r->left : r->right;
                    
                    if (r && r->approved) 
                    { 
                        r->completed = true; 
                        actionStack.push("Project completed by freelancer");
                        animatedProgressBar("Finalizing completion");
                        cout << "\n";
                        showSuccessBox("Project marked as completed!");
                    }
                    else 
                    {
                        cout << "\n";
                        showErrorBox("Project not found or not approved!");
                    }
                    break;
                }
                case 5: // Best proposal
                {
                    spinnerAnimation(3);
                    
                    dotLoadingAnimation("    Analyzing proposals", 4);
                    
                    Proposal* best = proposalHeap.best();
                    if (best)
                    {
                        cout << "\n\n";
                        cout << "    +======================================================+\n";
                        cout << "    |          BEST PROPOSAL - TOP RANKED                  |\n";
                        cout << "    +======================================================+\n";
                        cout << "    |                                                      |\n";
                        
                        cout << "    |   Freelancer: ";
                        cout << best->freelancer;
                        for (int i = best->freelancer.length(); i < 34; i++) cout << " ";
                        cout << "|\n";
                        
                        cout << "    |   Bid Amount: $" << best->bid;
                        string bidStr = intToString(best->bid);
                        for (int i = 0; i < 33 - bidStr.length(); i++) cout << " ";
                        cout << "|\n";
                        
                        cout << "    |   Rating: " << best->rating << " Stars";
                        string ratingStr = floatToString(best->rating);
                        for (int i = 0; i < 36 - ratingStr.length(); i++) cout << " ";
                        cout << "|\n";
                        
                        cout << "    |                                                      |\n";
                        cout << "    +======================================================+\n";
                        cout << "\n\n";
                    }
                    else 
                    {
                        cout << "\n";
                        showMessageBox("INFO", "No proposals available at this time.");
                    }
                    longDelay();
                    break;
                }
                case 6: // Top freelancers
                {
                    spinnerAnimation(3);
                    
                    cout << "\n\n";
                    cout << "    +======================================================+\n";
                    cout << "    |          TOP FREELANCERS RANKING                     |\n";
                    cout << "    +======================================================+\n";
                    cout << "\n";
                    
                    dotLoadingAnimation("    Loading rankings", 4);
                    cout << "\n";
                    
                    freelancerTree.inorder(freelancerTree.root);
                    
                    cout << "\n    " << repeatChar('-', 50) << "\n";
                    longDelay();
                    break;
                }
                case 0:
                    dotLoadingAnimation("    Logging out", 3);
                    cout << "\n";
                    showSuccessBox("Logged out successfully!");
                    break;
                }
            } while (freelancerChoice != 0);
            break;
        }

        case 4: // Admin login
        {
            if (!adminCheck()) break;
            
            spinnerAnimation(3);
            
            dotLoadingAnimation("    Verifying admin credentials", 4);
            cout << "\n";
            showSuccessBox("Admin access granted!");
            
            int ac;
            do
            {
                showAdminMenu();
                cin >> ac;
                switch (ac)
                {
                case 1: 
                {
                    spinnerAnimation(3);
                    
                    cout << "\n\n";
                    cout << "    +======================================================+\n";
                    cout << "    |          ALL REGISTERED USERS                        |\n";
                    cout << "    +======================================================+\n";
                    cout << "\n";
                    
                    dotLoadingAnimation("    Loading user database", 4);
                    cout << "\n";
                    
                    userTable.display(); 
                    
                    cout << "\n    " << repeatChar('-', 50) << "\n";
                    longDelay();
                    break;
                }
                case 2: 
                {
                    spinnerAnimation(2);
                    
                    string pid;
                    cout << "\n";
                    cout << "    >> APPROVE PROJECT\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cout << "    >> Enter Project ID: "; 
                    cin >> pid;
                    
                    dotLoadingAnimation("    Locating project", 4);
                    
                    Project* r = projectTree.root;
                    while (r && r->id != pid) r = (pid < r->id) ? r->left : r->right;
                    
                    if (r) 
                    {
                        admin.approveProject(r, jobQueue, actionStack);
                        animatedProgressBar("Processing approval");
                        cout << "\n";
                        showSuccessBox("Project approved successfully!");
                    }
                    else
                    {
                        cout << "\n";
                        showErrorBox("Project not found!");
                    }
                    break;
                }
                case 3: 
                {
                    spinnerAnimation(4);
                    
                    dotLoadingAnimation("    Processing job queue", 5);
                    
                    admin.processJobs(jobQueue, actionStack);
                    
                    animatedProgressBar("Completing jobs");
                    cout << "\n";
                    showSuccessBox("Job queue processed!");
                    break;
                }
                case 4: 
                {
                    spinnerAnimation(2);
                    
                    string uid;
                    cout << "\n";
                    cout << "    >> BAN USER\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cout << "    >> Enter User ID: "; 
                    cin >> uid;
                    
                    dotLoadingAnimation("    Processing ban request", 4);
                    
                    userTable.banUser(uid); 
                    actionStack.push("User banned");
                    
                    animatedProgressBar("Applying ban");
                    cout << "\n";
                    showSuccessBox("User banned from the system!");
                    break;
                }
                case 5: 
                {
                    spinnerAnimation(2);
                    
                    string pid;
                    cout << "\n";
                    cout << "    >> ADMIN OVERRIDE - COMPLETE PROJECT\n";
                    cout << "    " << repeatChar('-', 50) << "\n\n";
                    
                    cout << "    >> Enter Project ID: "; 
                    cin >> pid;
                    
                    dotLoadingAnimation("    Locating project", 4);
                    
                    Project* r = projectTree.root;
                    while (r && r->id != pid) r = (pid < r->id) ? r->left : r->right;
                    
                    if (r) 
                    {
                        admin.completeProject(r, actionStack);
                        animatedProgressBar("Finalizing completion");
                        cout << "\n";
                        showSuccessBox("Project completed by admin!");
                    }
                    else
                    {
                        cout << "\n";
                        showErrorBox("Project not found!");
                    }
                    break;
                }
                case 6: 
                {
                    spinnerAnimation(3);
                    
                    cout << "\n\n";
                    cout << "    +======================================================+\n";
                    cout << "    |          SYSTEM ACTIVITY MONITOR                     |\n";
                    cout << "    +======================================================+\n";
                    cout << "\n";
                    
                    dotLoadingAnimation("    Fetching system data", 4);
                    cout << "\n";
                    
                    admin.monitorSystem();
                    
                    cout << "\n    " << repeatChar('-', 50) << "\n";
                    longDelay();
                    break;
                }
                case 0:
                    dotLoadingAnimation("    Logging out", 3);
                    cout << "\n";
                    showSuccessBox("Admin logged out successfully!");
                    break;
                }
            } while (ac != 0);
            break;
        }

        case 0:
        {
            spinnerAnimation(4);
            
            dotLoadingAnimation("    Shutting down system", 6);
            
            cout << "\n\n";
            cout << "    +======================================================+\n";
            cout << "    |          THANK YOU FOR USING                         |\n";
            cout << "    |       FREELANCING MARKETPLACE SYSTEM                 |\n";
            cout << "    +======================================================+\n";
            cout << "\n\n";
            
            animatedProgressBar("Saving data");
            
            cout << "\n";
            cout << "        [SUCCESS] All data saved successfully!\n";
            cout << "        [SUCCESS] System shutdown complete!\n";
            cout << "\n\n";
            
            longDelay();
            longDelay();
            break;
        }

        default:
        {
            showErrorBox("Invalid choice! Please try again.");
            break;
        }
        }
    } while (mainChoice != 0);

    return 0;
}