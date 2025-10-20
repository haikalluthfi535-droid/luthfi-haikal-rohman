#include <iostream>
using namespace std;

#define MAX 5 

struct Stack {
    int data[MAX];
    int top; 
};

void init(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int value) {
    if (isFull(s))
        cout << "Stack penuh, tidak bisa menambah data!\n";
    else {
        s.top++;
        s.data[s.top] = value;
        cout << value << " ditambahkan ke stack.\n";
    }
}

void pop(Stack &s) {
    if (isEmpty(s))
        cout << "Stack kosong, tidak bisa menghapus data!\n";
    else {
        cout << s.data[s.top] << " dihapus dari stack.\n";
        s.top--;
    }
}

void cekKondisi(Stack s) {
    cout << "\n=== Kondisi Stack ===\n";
    if (isEmpty(s))
        cout << "a. Kosong: YA\n";
    else
        cout << "a. Kosong: TIDAK\n";

    if (isFull(s))
        cout << "b. Penuh: YA\n";
    else
        cout << "b. Penuh: TIDAK\n";

    if (!isFull(s))
        cout << "c. Bisa diisi: YA\n";
    else
        cout << "c. Bisa diisi: TIDAK\n";

    if (!isEmpty(s))
        cout << "d. Ada isinya: YA\n";
    else
        cout << "d. Ada isinya: TIDAK\n";
}

int main() {
    Stack s;
    init(s);

    cekKondisi(s); 

    push(s, 10);
    cekKondisi(s);

    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    cekKondisi(s); 

    pop(s);
    cekKondisi(s); 

    return 0;
}
