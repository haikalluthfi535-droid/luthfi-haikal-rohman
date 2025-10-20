#include <iostream>
using namespace std;

#define MAX 5 

struct DoubleStack {
    int stack1[MAX];
    int stack2[MAX];
    int top1;
    int top2;
};

void init(DoubleStack &s) {
    s.top1 = -1;
    s.top2 = -1;
}

bool isFull1(DoubleStack s) { return s.top1 == MAX - 1; }
bool isEmpty1(DoubleStack s) { return s.top1 == -1; }
bool isFull2(DoubleStack s) { return s.top2 == MAX - 1; }
bool isEmpty2(DoubleStack s) { return s.top2 == -1; }

// Fungsi untuk mengecek kondisi double stack
bool isBothFull(DoubleStack s) {
    return isFull1(s) && isFull2(s);
}

bool canBothPush(DoubleStack s) {
    return !isFull1(s) && !isFull2(s);
}

bool isBothEmpty(DoubleStack s) {
    return isEmpty1(s) && isEmpty2(s);
}

// a. Mengisi Stack1 (PUSH1)
void push1(DoubleStack &s, int val) {
    if (isFull1(s)) {
        cout << "Stack1 is full" << endl;
        return;
    }
    s.stack1[++s.top1] = val;
}

// b. Menghapus isi Stack1 (POP1)
int pop1(DoubleStack &s) {
    if (isEmpty1(s)) {
        cout << "Stack1 is empty" << endl;
        return -1; // Sentinel value for error
    }
    return s.stack1[s.top1--];
}

// c. Mengisi Stack2 (PUSH2)
void push2(DoubleStack &s, int val) {
    if (isFull2(s)) {
        cout << "Stack2 is full" << endl;
        return;
    }
    s.stack2[++s.top2] = val;
}

// d. Menghapus isi Stack2 (POP2)
int pop2(DoubleStack &s) {
    if (isEmpty2(s)) {
        cout << "Stack2 is empty" << endl;
        return -1; // Sentinel value for error
    }
    return s.stack2[s.top2--];
}

// Contoh penggunaan untuk mengecek kondisi
int main() {
    DoubleStack s;
    init(s);

    // Kondisi awal: kedua stack kosong
    cout << "Kondisi awal:" << endl;
    cout << "a. Penuh (kedua stack tak bisa diisi lagi): " << (isBothFull(s) ? "Ya" : "Tidak") << endl;
    cout << "b. Bisa diisi lagi (kedua stack bisa diisi): " << (canBothPush(s) ? "Ya" : "Tidak") << endl;
    cout << "c. Kosong (kedua stack tak ada isinya): " << (isBothEmpty(s) ? "Ya" : "Tidak") << endl;
    cout << endl;

    // Isi beberapa elemen
    push1(s, 10);
    push1(s, 20);
    push1(s, 30);
    push1(s, 40);
    push1(s, 50); // Stack1 penuh

    push2(s, 100);
    push2(s, 200);
    push2(s, 300);
    push2(s, 400);
    push2(s, 500); // Stack2 penuh

    cout << "Setelah mengisi hingga penuh:" << endl;
    cout << "a. Penuh (kedua stack tak bisa diisi lagi): " << (isBothFull(s) ? "Ya" : "Tidak") << endl;
    cout << "b. Bisa diisi lagi (kedua stack bisa diisi): " << (canBothPush(s) ? "Ya" : "Tidak") << endl;
    cout << "c. Kosong (kedua stack tak ada isinya): " << (isBothEmpty(s) ? "Ya" : "Tidak") << endl;
    cout << endl;

    // Kosongkan kedua stack
    while (!isEmpty1(s)) pop1(s);
    while (!isEmpty2(s)) pop2(s);

    cout << "Setelah mengosongkan kedua stack:" << endl;
    cout << "a. Penuh (kedua stack tak bisa diisi lagi): " << (isBothFull(s) ? "Ya" : "Tidak") << endl;
    cout << "b. Bisa diisi lagi (kedua stack bisa diisi): " << (canBothPush(s) ? "Ya" : "Tidak") << endl;
    cout << "c. Kosong (kedua stack tak ada isinya): " << (isBothEmpty(s) ? "Ya" : "Tidak") << endl;

    return 0;
}
