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

    int getCount() {
        if (isEmpty()) {
            return 0;
        }
        if (rear >= front) {
            return rear - front + 1;
        }
        return max_size - front + rear + 1;
    }

    int getAvailableSlots() {
        return max_size - getCount();
    }

    void setQueueState(int f, int r) {
        if (f >= 0 && r < max_size) {
            front = f;
            rear = r;
        } else {
            std::cout << "Kondisi antrian tidak valid!\n";
        }
    }

    void displayStatus() {
        std::cout << "Front: " << front << ", Rear: " << rear << "\n";
        std::cout << "Jumlah elemen: " << getCount() << "\n";
        std::cout << "Sisa tempat: " << getAvailableSlots() << "\n";
    }
};

int main() {
    CircularQueue q(MAX_SIZE);

    // a. Kosong
    std::cout << "Kondisi a (Kosong):\n";
    q.setQueueState(-1, -1);
    q.displayStatus();

    // b. Penuh (contoh: front = 0, rear = max_size - 1)
    std::cout << "\nKondisi b (Penuh):\n";
    q.setQueueState(0, MAX_SIZE - 1);
    q.displayStatus();

    // c. Bisa diisi (contoh: front = 10, rear = 20)
    std::cout << "\nKondisi c (Bisa diisi):\n";
    q.setQueueState(10, 20);
    q.displayStatus();

    // d. Ada isinya (contoh: front = 5, rear = 15)
    std::cout << "\nKondisi d (Ada isinya):\n";
    q.setQueueState(5, 15);
    q.displayStatus();

    // e. Hanya berisi 10 record (contoh: front = 0, rear = 9)
    std::cout << "\nKondisi e (Berisi 10 record):\n";
    q.setQueueState(0, 9);
    q.displayStatus();

    // f. Tempat kosong hanya 10 tempat (contoh: 90 elemen, front = 0, rear = 89)
    std::cout << "\nKondisi f (Sisa 10 tempat):\n";
    q.setQueueState(0, 89);
    q.displayStatus();

    return 0;
}
