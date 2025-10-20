#include <iostream>
#define MAX_SIZE 100

class Deque {
private:
    int deque[MAX_SIZE];
    int front;
    int rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFullRight() {
        return (rear == MAX_SIZE - 1);
    }

    bool isFullLeft() {
        return (front == 0);
    }

    bool isFullTotal() {
        return (front == 0 && rear == MAX_SIZE - 1);
    }

    bool hasTenElements() {
        if (front == -1) return false;
        return (rear - front + 1 == 10);
    }

    void displayStatus() {
        if (isEmpty()) {
            std::cout << "a. Deque kosong (tidak ada isinya): front = " << front << ", rear = " << rear << std::endl;
        }
        if (isFullRight()) {
            std::cout << "b. Deque penuh kanan (tak bisa diisi dari kanan): rear = " << rear << std::endl;
        }
        if (isFullLeft()) {
            std::cout << "c. Deque penuh kiri (tak bisa diisi dari kiri): front = " << front << std::endl;
        }
        if (isFullTotal()) {
            std::cout << "d. Deque penuh total (tak bisa diisi dari kiri maupun kanan): front = " << front << ", rear = " << rear << std::endl;
        }
        if (hasTenElements()) {
            std::cout << "e. Deque hanya diisi 10 pengantri: jumlah elemen = " << (rear - front + 1) << std::endl;
        }
    }

    void insertRight(int element) {
        if (isFullRight()) return;
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = rear + 1;
        }
        deque[rear] = element;
    }

    void insertLeft(int element) {
        if (isFullLeft()) return;
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front = front - 1;
        }
        deque[front] = element;
    }
};

int main() {
    Deque dq;

    dq.displayStatus(); // Ciri a: Kosong

    for (int i = 1; i <= 10; i++) {
        dq.insertRight(i);
    }
    dq.displayStatus(); // Ciri e: 10 pengantri

    Deque dq2;
    for (int i = 0; i < MAX_SIZE; i++) {
        dq2.insertRight(i);
    }
    dq2.displayStatus(); // Ciri b: Penuh kanan

    Deque dq3;
    for (int i = 0; i < MAX_SIZE; i++) {
        dq3.insertLeft(i);
    }
    dq3.displayStatus(); // Ciri c: Penuh kiri

    Deque dq4;
    dq4.insertLeft(1);
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        dq4.insertRight(i);
    }
    dq4.displayStatus(); // Ciri d: Penuh total

    return 0;
}
