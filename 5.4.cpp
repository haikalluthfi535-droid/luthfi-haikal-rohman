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

// Fungsi untuk mengambil dan mencetak isi Stack1 satu persatu sampai kosong
void printAndEmptyStack1(DoubleStack &s) {
    cout << "Mengambil dan mencetak isi Stack1 satu persatu:" << endl;
    while (!isEmpty1(s)) {
        int val = pop1(s);
        if (val != -1) {  // Pastikan pop berhasil
            cout << val << " ";
        }
    }
    cout << endl << "Stack1 sekarang kosong." << endl;
}

// Contoh penggunaan
int main() {
    DoubleStack s;
    init(s);

    // Isi Stack1 dengan beberapa elemen
    push1(s, 10);
    push1(s, 20);
    push1(s, 30);
    push1(s, 40);

    // Jalankan algoritma untuk mengambil dan mencetak isi Stack1
    printAndEmptyStack1(s);

    return 0;
}
