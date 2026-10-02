// Soal modul 3
#include <iostream>
#include <string>
using namespace std;

struct node {
    char data;
    node *next;
};

node *top = NULL;

void push(char c) {
    node *newNode = new node;
    newNode -> data = c;
    newNode -> next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return '\0';
    }
    node *temp = top;
    char poppedValue = temp -> data;
    top = top -> next;
    delete temp;
    return poppedValue;
}

bool isEmpty() {
    return top == NULL;
}

int main() {
    string kata;
    cout << "Masukkan kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        push(kata[i]);
    }

    string kataTerbalik = "";
    while (!isEmpty()) {
        kataTerbalik += pop();
    }

    cout << "Hasil dibalik: " << kataTerbalik << endl;

    return 0;
}