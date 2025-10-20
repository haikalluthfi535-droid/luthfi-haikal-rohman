#include <iostream>
#include <string>
using namespace std;

#define MAX 10  // Kapasitas maksimal queue

// Definisi struct Record
struct Record {
    string nama;
    int nilai;
};

// Struktur Queue
struct Queue {
    Record data[MAX];
    int front;
    int rear;
};

// a. Inisialisasi
void initQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

// Cek apakah queue kosong
bool isEmpty(Queue q) {
    return q.front == -1;
}

// Cek apakah queue penuh
bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

// b. Insert sebuah record (Enqueue)
void enqueue(Queue &q, Record r) {
    if (isFull(q)) {
        cout << "Queue penuh, tidak bisa menambah record." << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = 0;
    }
    q.data[++q.rear] = r;
    cout << "Record berhasil dimasukkan: Nama = " << r.nama << ", Nilai = " << r.nilai << endl;
}

// c. Delete sebuah record (Dequeue)
Record dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong, tidak bisa menghapus record." << endl;
        return {"", -1};  // Return dummy record
    }
    Record r = q.data[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front++;
    }
    cout << "Record berhasil dihapus: Nama = " << r.nama << ", Nilai = " << r.nilai << endl;
    return r;
}

// d. Reset
void resetQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
    cout << "Queue berhasil direset (kosong)." << endl;
}

// Contoh penggunaan
int main() {
    Queue q;
    
    // a. Inisialisasi
    initQueue(q);
    cout << "Queue diinisialisasi." << endl;
    
    // b. Insert beberapa record
    Record r1 = {"Alice", 85};
    Record r2 = {"Bob", 90};
    enqueue(q, r1);
    enqueue(q, r2);
    
    // c. Delete record
    dequeue(q);
    
    // d. Reset
    resetQueue(q);
    
    return 0;
}
