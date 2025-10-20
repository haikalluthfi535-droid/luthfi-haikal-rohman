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

    int deleteRight() {
        if (isEmpty()) {
            std::cout << "Deque kosong" << std::endl;
            return -1;
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

    void emptyFromRight() {
        int count = 0;
        while (!isEmpty()) {
            int deleted = deleteRight();
            if (deleted != -1) {
                std::cout << "Deleted record: " << deleted << std::endl;
                count++;
            }
        }
        std::cout << "Antrian kosong setelah menghapus " << count << " record dari kanan" << std::endl;
    }
};

int main() {
    Deque dq;

    for (int i = 1; i <= 10; i++) {
        dq.insertRight(i);
    }

    dq.emptyFromRight();

    return 0;
}
