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

    void fillTenFromRight() {
        int count = 0;
        for (int i = 1; i <= 10; i++) {
            if (isFullRight()) {
                std::cout << "Pengisian dihentikan karena penuh kanan" << std::endl;
                break;
            }
            insertRight(i);
            count++;
        }
        std::cout << "Mengisi " << count << " record dari kanan" << std::endl;
    }
};

int main() {
    Deque dq;
    dq.fillTenFromRight();
    return 0;
}
