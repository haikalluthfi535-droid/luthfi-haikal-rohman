#include <iostream>
#define MAX_SIZE 100

class LinearQueue {
private:
    int queue[MAX_SIZE];
    int front;
    int rear;
    int max_size;

public:
    LinearQueue(int size) {
        front = -1;
        rear = -1;
        max_size = size;
    }

    void setQueueState(int f, int r) {
        if (f >= 0 && r < max_size && f <= r) {
            front = f;
            rear = r;
        } else {
            std::cout << "Kondisi antrian tidak valid!\n";
        }
    }

    int getUnservedCount() {
        if (front == -1 || rear == -1) {
            return 0;
        }
        return rear - front + 1;
    }

    int getAvailableSlots() {
        return max_size - 1 - rear;
    }

    void displayStatus() {
        std::cout << "Front: " << front << ", Rear: " << rear << "\n";
        std::cout << "Jumlah pengantri yang belum dilayani: " << getUnservedCount() << "\n";
        std::cout << "Jumlah kolom yang masih bisa diisi: " << getAvailableSlots() << "\n";
    }
};

int main() {
    LinearQueue q(MAX_SIZE);
    q.setQueueState(15, 37);
    q.displayStatus();
    return 0;
}
