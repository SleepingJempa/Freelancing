#include <iostream>

using namespace std;

class Node
{
public:
    string data;
    Node *prev;
    Node *next;
    Node(string data) : data(data), prev(nullptr), next(nullptr) {};
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    void insert(string label);
    void remove(string label);
    void show();
    LinkedList() : head(nullptr), tail(nullptr) {};
};

void LinkedList::insert(string label) {
    Node* node = new Node(label);
    if (head == nullptr) {
        tail = head = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    cout << "Book Inserted: " << label << endl;
}

void LinkedList::remove(string label) {
    Node* trav = tail;

    if (head->data == label) {
        Node* temp = head->next;
        temp->prev = nullptr;
        delete head;
        head = temp;
        cout << "Book Deleted: " << label << endl;
        return;
    }
    
    if (tail->data == label) {
        Node* temp = tail->prev;
        temp->next = nullptr;
        delete tail;
        tail = temp;
        cout << "Book Deleted: " << label << endl;
        return;
    }

    while(trav != nullptr && label != trav->data) {
        trav = trav->prev;
    }

    if (trav == nullptr) {
        cout << "Book Not Founded: " << label << endl;
        return;
    } else {
        Node* theNext = trav->next;
        Node* thePrev = trav->prev;
        thePrev->next = theNext;
        theNext->prev = thePrev;
        delete trav;
        cout << "Book Deleted: " << label << endl;
    }
}

void LinkedList::show() {
    cout << "List of Books: ";
    Node *trav = tail;
    while (trav != nullptr) {
        cout << trav->data << " ";
        trav = trav->prev;
    }
    cout << endl;
}



int main() {
    string cmd, label;

    LinkedList* ll = new LinkedList();

    while(true) {
        cin >> cmd;

        if (cmd == "insert") {
            cin >> label;
            ll->insert(label);
        }

        if (cmd == "show") {
            ll->show();
        }

        if (cmd == "delete") {
            cin >> label;
            ll->remove(label);
        }

        if (cmd == "exit") {
            break;
        }
    }
}