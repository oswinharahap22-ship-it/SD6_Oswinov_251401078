// Binary tree
#include <iostream>
using namespace std;

struct node {
    int data;
    node* kiri;
    node* kanan;
};

node* akar = NULL;

node* addNode(node* akar, int value) {
    if (akar == NULL) {
        node* baru = new node;
        baru -> data = value;
        baru -> kiri = NULL;
        baru -> kanan = NULL;
        akar = baru;
    } else if (value < akar -> data) {
        akar -> kiri = addNode(akar -> kiri, value);
    } else if (value > akar -> data) {
        akar -> kanan = addNode(akar -> kanan, value);
    }
    return akar;
}

void preOrder(node* akar) {
    if (akar != NULL) {
        cout << akar -> data << " -> ";
        preOrder(akar -> kiri);
        preOrder(akar -> kanan);
    }
}

int main() {
    system("cls");
    akar = addNode(akar, 25);
    akar = addNode(akar, 11);
    akar = addNode(akar, 56);
    akar = addNode(akar, 12);
    akar = addNode(akar, 30);

    preOrder(akar);
}