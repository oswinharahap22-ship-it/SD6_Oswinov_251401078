//Linked list single circular
#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

void insertFirst( int n ) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail -> next = head;
    } else {
        newNode -> next = head;
        head = newNode;
        tail -> next = head;
    }
}

void insertLast ( int n ) {
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        tail -> next = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
        tail -> next = head;
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

    node *p = head;
    while (p -> next != tail) {
        p = p -> next;
    }

    delete tail;
    tail = p;
    tail -> next = head;
}

void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head -> value == value) {
        deleteFirst();
        return;
    }
    
    node *p = head;
    bool found = false;

    while (p -> next != head) {
        if (p -> next -> value == value) {
            found = true;
            break;
        }
        p = p -> next;
    }

    if (!found) {
        cout << "Node dengan nilai " << value << " tidak ditemukan\n";
    } else {
        node *temp = p -> next;
        p -> next = temp -> next;
        if (temp == tail) tail = p;
        delete temp;
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
        cout << temp -> value << " -> ";
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