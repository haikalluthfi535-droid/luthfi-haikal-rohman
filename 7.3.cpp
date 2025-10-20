#include <iostream>
#define MAX_SIZE 100

class CircularQueue {
private:
    int queue[MAX_SIZE];
    int front;
    int rear;
    int max_size;

public:
    CircularQueue(int size) {
        front = -1;
        rear = -1;
        max_size = size;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % max_size == front);
    }

    void insert(int data) {
        if (isFull()) {
            std::cout << "Antrian penuh, tidak bisa menambah elemen!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max_size;
        }
        queue[rear] = data;
        std::cout << "Elemen " << data << " ditambahkan.\n";
    }

    void fillQueue() {
        int count = 0;
        int data = 1;
        while (count < 10 && !isFull()) {
            insert(data);
            count++;
            data++;
        }
        if (isFull()) {
            std::cout << "Antrian penuh, pengisian dihentikan.\n";
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Antrian kosong.\n";
            return;
        }
        std::cout << "Isi antrian: ";
        int i = front;
        while (i != rear) {
            std::cout << queue[i] << " ";
            i = (i + 1) % max_size;
        }
        std::cout << queue[rear] << "\n";
    }
};

int main() {
    CircularQueue q(MAX_SIZE);
    q.fillQueue();
    q.display();
    return 0;
}
