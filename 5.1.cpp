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

void push1(DoubleStack &s, int val) {
    if (isFull1(s)) {
        cout << "Stack1 is full" << endl;
        return;
    }
    s.stack1[++s.top1] = val;
}

int pop1(DoubleStack &s) {
    if (isEmpty1(s)) {
        cout << "Stack1 is empty" << endl;
        return -1; // Return a sentinel value indicating error
    }
    return s.stack1[s.top1--];
}

void push2(DoubleStack &s, int val) {
    if (isFull2(s)) {
        cout << "Stack2 is full" << endl;
        return;
    }
    s.stack2[++s.top2] = val;
}

int pop2(DoubleStack &s) {
    if (isEmpty2(s)) {
        cout << "Stack2 is empty" << endl;
        return -1; // Return a sentinel value indicating error
    }
    return s.stack2[s.top2--];
}

// Example main function to demonstrate usage
int main() {
    DoubleStack s;
    init(s);

    // Push some values to stack1
    push1(s, 10);
    push1(s, 20);
    push1(s, 30);

    // Push some values to stack2
    push2(s, 100);
    push2(s, 200);

    // Pop from stack1
    cout << "Popped from stack1: " << pop1(s) << endl;
    cout << "Popped from stack1: " << pop1(s) << endl;

    // Pop from stack2
    cout << "Popped from stack2: " << pop2(s) << endl;

    return 0;
}
