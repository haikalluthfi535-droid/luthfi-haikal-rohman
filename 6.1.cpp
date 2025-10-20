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

// Fungsi untuk membuat record baru (dengan input pengguna)
Record createRecord(int index) {
    Record r;
    cout << "Masukkan data untuk record ke-" << index << ":" << endl;
    cout << "Nama: ";
    cin >> r.nama;
    cout << "Nilai: ";
    cin >> r.nilai;
    return r;
}

// Algoritma utama: Mengisi queue sebanyak 10 record atau sampai penuh
void fillQueue(Queue &q) {
    cout << "Memulai pengisian antrian dengan 10 record..." << endl;
    for (int i = 1; i <= 10; i++) {
        if (isFull(q)) {
            cout << "Antrian penuh, pengisian dihentikan pada record ke-" << (i-1) << "." << endl;
            break;
        }
        Record newRecord = createRecord(i);
        enqueue(q, newRecord);
        cout << "Record ke-" << i << " berhasil dimasukkan." << endl;
    }
    cout << "Proses pengisian selesai." << endl;
}

// Contoh penggunaan
int main() {
    Queue q;
    initQueue(q);
    
    fillQueue(q);
    
    return 0;
}
