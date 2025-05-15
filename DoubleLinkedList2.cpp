#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class Doublelinkedlist
{
private:
    Node *START;

public:
    Doublelinkedlist()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Allocate memory for new node
        Node *newNode = new Node();

        // Step 2: Assign value to the data fields
        newNode->noMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if(START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // Step 4: newNode.next = START
            newNode->next = START;

            // Step 5: Start.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            // Step 6: newNode.prev = NULL
            newNode->prev = NULL;

            // Step 7: START = newNode
            START= newNode;
            return;
        }
        // Insert in between mode
        // Step 8: Locate position for insertion
        Node *current = START;
        while(current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }
        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }
        // Step 9: Insert between current and current->next
        newNode->next = current->next; // Step 9a: newNode.next = current.next
        newNode->prev = current;       // Step 9b: newNode.prev = current
        
    }
}
