// Linked list double non circular
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
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

void insertLast ( int n ) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail -> next = newNode;
        newNode -> prev = tail;
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
    newNode -> next = NULL;
    newNode -> prev = NULL;

    node *p = head;
    while (p != NULL && p -> value != check) {
        p = p -> next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ditemukan!" << endl;
        delete newNode;
    } else {
        newNode -> next = p -> next;
        newNode -> prev = p;
        if (p -> next != NULL) {
            p -> next -> prev = newNode;
        } else {
            tail = newNode;
        }
        p -> next = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    node *temp = head;
    head = head -> next;
    if (head == NULL) {
        tail = NULL;
    } else {
        head -> prev = NULL;
    }
    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    node *temp = tail;
    tail = tail -> prev;
    if (tail == NULL) {
        head = NULL;
    } else {
        tail -> next = NULL;
    }
    delete temp;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    node *p = head;
    while (p != NULL && p -> value != value) {
        p = p -> next;
    }

    if (p == NULL) {
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
    node *temp = head;
    cout << "Isi linked list : ";
    while (temp != NULL) {
        cout << temp -> value << " <-> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
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