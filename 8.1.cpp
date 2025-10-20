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

    bool isFullRight() {
        return (rear == MAX_SIZE - 1);
    }

    bool isFullLeft() {
        return (front == 0);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertRight(int element) {
        if (isFullRight()) {
            std::cout << "Deque penuh dari kanan" << std::endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = rear + 1;
        }
        deque[rear] = element;
    }

    void insertLeft(int element) {
        if (isFullLeft()) {
            std::cout << "Deque penuh dari kiri" << std::endl;
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            front = front - 1;
        }
        deque[front] = element;
    }

    int deleteRight() {
        if (isEmpty()) {
            std::cout << "Deque kosong" << std::endl;
            return -1; // Nilai error
        }
        int element = deque[rear];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = rear - 1;
        }
        return element;
    }

    int deleteLeft() {
        if (isEmpty()) {
            std::cout << "Deque kosong" << std::endl;
            return -1; // Nilai error
        }
        int element = deque[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
        return element;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque kosong" << std::endl;
            return;
        }
        std::cout << "Elemen deque: ";
        for (int i = front; i <= rear; i++) {
            std::cout << deque[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Deque dq;

    // Contoh penggunaan
    dq.insertRight(10);
    dq.insertRight(20);
    dq.insertLeft(5);
    dq.insertLeft(1);
    dq.display(); // Output: 1 5 10 20

    dq.deleteRight(); // Hapus 20
    dq.deleteLeft(); // Hapus 1
    dq.display(); // Output: 5 10

    return 0;
}
