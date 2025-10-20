#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertLast(int value) {
    Node* baru = new Node;
    baru->data = value;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }
    Node* hapus = head;
    head = head->next;
    delete hapus;
}

void tampil() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }
    Node* bantu = head;
    while (bantu != NULL) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << "NULL\n";
}

int main() {
    insertLast(10);
    insertLast(20);
    insertLast(30);
    tampil();
    deleteFirst();
    tampil();
    return 0;
}
