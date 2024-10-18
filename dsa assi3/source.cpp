#include <iostream>

using namespace std;

typedef struct Node* Nodeptr;

struct Node
{
    int info;
    Nodeptr next;
    Nodeptr pre;
};

class LinkedList
{
private:
    Nodeptr List;
public:
    LinkedList();
    void traverse();
    Nodeptr find(int);
    void iAS(int);
    int dAS();
    void iAE(int);
    int dAE();
    void iAM(int);
    int dAM(int);
};

LinkedList::LinkedList()
{
    List = NULL;
}

void LinkedList::iAS(int x)
{
    Nodeptr p = new Node;
    p->info = x;
    p->pre = NULL;
    p->next = List;
    if (List != NULL)
        List->pre = p;
    List = p;
}

int LinkedList::dAS()
{
    if (List == NULL)
        return -999;
    Nodeptr p = List->next;
    p->pre = NULL;
    int x = List->info;
    delete List;
    List = p;
    return x;
}

void LinkedList::traverse()
{
    for (Nodeptr p = List; p != NULL; p = p->next)
    {
        cout << p->info << " ";
    }
    cout << endl;
}
void LinkedList::iAE(int x)
{
    if (List == NULL)
        iAS(x);
    else
    {
        Nodeptr p = List;
        while (p->next != NULL)
        {
            p = p->next;
        }
        Nodeptr temp = new Node;
        temp->info = x;
        temp->pre = p;
        temp->next = NULL;
        p->next = temp;
    }
}


int LinkedList::dAE()
{
    if (List == NULL)
        return -999;

    if (List->next == NULL)
        return dAS();
    else
    {
        Nodeptr q = NULL;
        for (Nodeptr p = List; p->next != NULL; p = p->next)
        {
            q = p;
        }
        int x = q->next->info;
        delete q->next;
        q->next = NULL;
        return x;
    }
}

Nodeptr LinkedList::find(int x)
{
    for (Nodeptr p = List; p != NULL; p = p->next)
    {
        if (p->info == x)
        {
            return p;
        }
    }
    return NULL;
}

void LinkedList::iAM(int x)
{
    Nodeptr p = find(x);
    if (p == NULL || p->next == NULL)
        iAE(x);
    else
    {
        Nodeptr q = new Node;
        q->info = x;
        q->next = p->next;
        p->next = q;
        q->pre = p;
        p->next->pre = q;
    }
}

int LinkedList::dAM(int x)
{
    Nodeptr p = find(x);
    if (p == NULL)
        return -999;
    if (p->next == NULL)
        return dAE();
    else
    {
        Nodeptr q = p->pre;
        q->next = p->next;
        p->next->pre = q;
        delete p;
        return 1;
    }
}
int main()
{
    LinkedList list;

    cout << "Default constructor called. List is empty." << endl;

    int choice, value;
    Nodeptr found = NULL;
    do
    {
        cout << "\n1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a node" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete a node" << endl;
        cout << "7. Find a node" << endl;
        cout << "8. Traverse the list" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at the beginning: ";
            cin >> value;
            list.iAS(value);
            break;
        case 2:
            cout << "Enter the value to insert at the end: ";
            cin >> value;
            list.iAE(value);
            break;
        case 3:
            cout << "Enter the value to insert after: ";
            cin >> value;
            list.iAM(value);
            break;
        case 4:
            cout << "Deleted node: " << list.dAS() << endl;
            break;
        case 5:
            cout << "Deleted node: " << list.dAE() << endl;
            break;
        case 6:
            cout << "Enter the value of the node to delete: ";
            cin >> value;
            cout << "Deleted node: " << list.dAM(value) << endl;
            break;
        case 7:
            cout << "Enter the value of the node to find: ";
            cin >> value;
            found = list.find(value);
            if (found != NULL)
                cout << "Node with value " << value << " found." << endl;
            else
                cout << "Node with value " << value << " not found." << endl;
            break;
        case 8:
            cout << "List: ";
            list.traverse();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}

