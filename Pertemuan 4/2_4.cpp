// Linked list double circular
#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
    node *prev;
};

node *head = NULL;
node *tail = NULL;

void insertFirst( int n ) {
    node *newNode = new node;
    newNode -> value = n;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head -> next = head;
        head -> prev = head;
    } else {
        newNode -> next = head;
        newNode -> prev = tail;
        head -> prev = newNode;
        tail -> next = newNode;
        head = newNode;
    }
}

void insertLast ( int n ) {
    node *newNode = new node;
    newNode -> value = n;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head -> next = head;
        head -> prev = head;
    } else {
        newNode -> next = head;
        newNode -> prev = tail;
        tail -> next = newNode;
        head -> prev = newNode;
        tail = newNode;
    }
}

void insertAfter ( int n, int check ) {
    if (head == NULL) {
        cout << "List Kosong!" << endl;
        return;
    } 
    
    node *newNode = new node;
    newNode -> value = n;

    node *p = head;
    bool found = false;

    do {
        if (p -> value == check) {
            found = true;
            break;
        }
        p = p -> next;
    } while (p != head);

    if (!found) {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
        delete newNode;
    } else {
        newNode -> next = p -> next;
        newNode -> prev = p;
        p -> next -> prev = newNode;
        p -> next = newNode;
        if (p == tail) {
            tail = newNode;
        }
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    node *temp = head;
    head = head -> next;
    head -> prev = tail;
    tail -> next = head;
    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    node *temp = tail;
    tail = tail -> prev;
    tail -> next = head;
    head -> prev = tail;
    delete temp;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    node *p = head;
    bool found = false;

    do {
        if (p -> value == value) {
            found = true;
            break;
        }
        p = p -> next;
    } while (p != head);

    if (!found) {
        cout << "Node dengan nilai " << value << " tidak ditemukan\n";
    } else {
        if (p == head) {
            deleteFirst();
        } else if (p == tail) {
            deleteLast();
        } else {
            p -> prev -> next = p -> next;
            p -> next -> prev = p -> prev;
            delete p;
        }
    }
}

void display() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }
    node *temp = head;
    cout << "Isi linked list : ";
    do {
        cout << temp -> value << " <-> ";
        temp = temp -> next;
    } while (temp != head);
    cout << "(head)" << endl;
}

int main () {
    system("cls");
    insertFirst(10);
    display();
    insertLast(20);
    display();
    insertLast(30);
    display();
    insertAfter(25, 20);
    display();
    insertFirst(3);
    display();

    deleteFirst();
    display();
    deleteLast();
    display();
    deleteMiddle(20);
    display();
    return 0;
}