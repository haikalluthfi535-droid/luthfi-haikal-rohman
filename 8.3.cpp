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

    void fillFromRight() {
        int record = 1;
        while (!isFullRight()) {
            insertRight(record);
            record++;
        }
        std::cout << "Antrian penuh dari kanan setelah mengisi " << (rear - front + 1) << " record" << std::endl;
    }
};

int main() {
    Deque dq;
    dq.fillFromRight();
    return 0;
}
