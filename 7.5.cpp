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

    void setQueueState(int f, int r) {
        if (f >= 0 && r < max_size) {
            front = f;
            rear = r;
        } else {
            std::cout << "Kondisi antrian tidak valid!\n";
        }
    }

    int getElementCount() {
        if (front == -1 && rear == -1) {
            return 0;
        }
        if (rear >= front) {
            return rear - front + 1;
        }
        return max_size - front + rear + 1;
    }

    void displayCount() {
        std::cout << "Jumlah elemen yang ada isinya: " << getElementCount() << "\n";
    }
};

int main() {
    CircularQueue q(MAX_SIZE);
    q.setQueueState(15, 37);
    q.displayCount();
    return 0;
}
