#include <iostream>
#define MAX_SIZE 5 // Kapasitas maksimum antrian

class LinearQueue {
private:
    int queue[MAX_SIZE];
    int front; // Indeks elemen pertama
    int rear;  // Indeks elemen terakhir

public:
    LinearQueue() {
        front = -1; // Inisialisasi antrian kosong
        rear = -1;
    }

    // Fungsi untuk memeriksa kondisi antrian
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Antrian penuh, tidak bisa menambah elemen!\n";
            return;
        }
        if (isEmpty()) {
            front = 0; // Jika kosong, set front ke 0
        }
        rear++;
        queue[rear] = data;
        std::cout << "Elemen " << data << " ditambahkan ke antrian.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Antrian kosong, tidak bisa menghapus elemen!\n";
            return;
        }
        std::cout << "Elemen " << queue[front] << " dihapus dari antrian.\n";
        if (front == rear) {
            front = -1; // Jika hanya satu elemen, reset antrian
            rear = -1;
        } else {
            front++;
        }
    }

    void reset() {
        front = -1;
        rear = -1;
        std::cout << "Antrian telah direset.\n";
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Antrian kosong.\n";
            return;
        }
        std::cout << "Isi antrian: ";
        for (int i = front; i <= rear; i++) {
            std::cout << queue[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    LinearQueue q;

    // a. Kosong
    std::cout << "Kondisi awal:\n";
    q.display(); // Output: Antrian kosong.

    // c. Bisa diisi
    std::cout << "\nMenambah elemen:\n";
    q.enqueue(10); // Output: Elemen 10 ditambahkan ke antrian.
    q.enqueue(20); // Output: Elemen 20 ditambahkan ke antrian.
    q.display();   // Output: Isi antrian: 10 20

    // d. Ada isinya
    std::cout << "\nMenambah elemen lagi:\n";
    q.enqueue(30); // Output: Elemen 30 ditambahkan ke antrian.
    q.display();   // Output: Isi antrian: 10 20 30

    // b. Penuh
    std::cout << "\nMengisi hingga penuh:\n";
    q.enqueue(40); // Output: Elemen 40 ditambahkan ke antrian.
    q.enqueue(50); // Output: Elemen 50 ditambahkan ke antrian.
    q.enqueue(60); // Output: Antrian penuh, tidak bisa menambah elemen!

    // e. Penuh tapi belum ada yang keluar
    std::cout << "\nKondisi penuh, belum ada yang keluar:\n";
    q.display();   // Output: Isi antrian: 10 20 30 40 50

    // d. Mengeluarkan elemen (ada isinya)
    std::cout << "\nMengeluarkan elemen:\n";
    q.dequeue();   
    q.display();  
    // f. Reset
    std::cout << "\nMereset antrian:\n";
    q.reset();     // Output: Antrian telah direset.
    q.display();   // Output: Antrian kosong.

    return 0;
}
