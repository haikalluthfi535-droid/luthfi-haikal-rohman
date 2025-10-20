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

// Inisialisasi queue
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

// Enqueue record ke queue
void enqueue(Queue &q, Record r) {
    if (isFull(q)) {
        cout << "Queue penuh, tidak bisa menambah record." << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = 0;
    }
    q.data[++q.rear] = r;
}

// Dequeue record dari queue
Record dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong, tidak bisa menghapus record." << endl;
        return {"", -1};  // Return dummy record jika kosong
    }
    Record r = q.data[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front++;
    }
    return r;
}

// Algoritma utama: Mendelete queue sebanyak 10 record atau sampai kosong
void deleteQueue(Queue &q) {
    cout << "Memulai proses delete antrian sebanyak 10 record..." << endl;
    for (int i = 1; i <= 10; i++) {
        if (isEmpty(q)) {
            cout << "Antrian kosong, proses delete dihentikan pada record ke-" << (i-1) << "." << endl;
            break;
        }
        Record deletedRecord = dequeue(q);
        cout << "Record ke-" << i << " berhasil dihapus: Nama = " << deletedRecord.nama 
             << ", Nilai = " << deletedRecord.nilai << endl;
    }
    cout << "Proses delete selesai." << endl;
}

// Contoh penggunaan
int main() {
    Queue q;
    initQueue(q);
    
    // Isi queue dengan beberapa record untuk contoh
    Record r1 = {"Alice", 85};
    Record r2 = {"Bob", 90};
    Record r3 = {"Charlie", 78};
    enqueue(q, r1);
    enqueue(q, r2);
    enqueue(q, r3);
    
    deleteQueue(q);
    
    return 0;
}
