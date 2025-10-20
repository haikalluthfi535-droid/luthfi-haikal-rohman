#include <iostream>
#include <vector>
#include <limits>   // penting: untuk numeric_limits
using namespace std;

struct Buku {
    string judul, penulis;
    int jumlah;
};

vector<Buku> perpustakaan;

void readLine(string &out) {
    // bersihkan sisa baris sampai newline lalu baca satu baris penuh
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, out);
}

void tampil() {
    if (perpustakaan.empty()) {
        cout << "Perpustakaan kosong!\n";
        return;
    }
    for (size_t i = 0; i < perpustakaan.size(); ++i) {
        cout << i + 1 << ". " << perpustakaan[i].judul << " | "
             << perpustakaan[i].penulis << " | Stok: "
             << perpustakaan[i].jumlah << '\n';
    }
}

void tambah() {
    Buku b;
    cout << "Masukkan judul: ";
    readLine(b.judul);
    cout << "Masukkan penulis: ";
    readLine(b.penulis);
    cout << "Masukkan jumlah: ";
    cin >> b.jumlah;
    // Bersihkan sisa input setelah cin >> (termasuk newline)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    perpustakaan.push_back(b);
    cout << "Buku berhasil ditambahkan.\n";
}

// Contoh menu utama (ditambahkan untuk kelengkapan, asumsikan ini yang hilang)
int main() {
    int pilihan;
    do {
        cout << "\nMenu Perpustakaan:\n";
        cout << "1. Tampilkan buku\n";
        cout << "2. Tambah buku\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan newline setelah input menu
        switch (pilihan) {
            case 1:
                tampil();
                break;
            case 2:
                tambah();
                break;
            case 3:
                cout << "Keluar...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);
    return 0;
}
