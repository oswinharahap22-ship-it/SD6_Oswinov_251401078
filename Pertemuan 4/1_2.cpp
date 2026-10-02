#include <iostream>
using namespace std;

// Menambahkan nilai baru di akhir array
void tambahData(int*& arr, int& n, int nilai) {
    int* newArr = new int[n + 1];      // alokasi array baru ukuran n+1
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[i];            // salin data lama
    }
    newArr[n] = nilai;                 // tambahkan data baru di akhir
    delete[] arr;                      // bebaskan array lama
    arr = newArr;                      // arahkan arr ke array baru
    n++;                               // update jumlah elemen
}

// Menghapus elemen pada indeks tertentu
void hapusData(int*& arr, int& n, int indeks) {
    if (n == 0) {
        cout << "Array kosong, tidak ada yang dihapus.\n";
        return;
    }
    if (indeks < 0 || indeks >= n) {
        cout << "Indeks tidak valid!\n";
        return;
    }

    if (n == 1) {
        delete[] arr;
        arr = nullptr;
        n = 0;
        cout << "Data pada indeks " << indeks << " dihapus. Array sekarang kosong.\n";
        return;
    }

    int* newArr = new int[n - 1];      // alokasi array baru ukuran n-1
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i != indeks) {             // lewati indeks yang dihapus
            newArr[j] = arr[i];
            j++;
        }
    }
    delete[] arr;
    arr = newArr;
    n--;
    cout << "Data pada indeks " << indeks << " berhasil dihapus.\n";
}

// Mencari nilai dalam array, mengembalikan indeks atau -1 jika tidak ditemukan
int cariData(int* arr, int n, int nilai) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == nilai) {
            return i;
        }
    }
    return -1;
}

// Menampilkan isi array
void tampilkanData(int* arr, int n) {
    if (n == 0 || arr == nullptr) {
        cout << "Array kosong.\n";
        return;
    }
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 0;
    int* arr = nullptr;

    // Contoh penggunaan
    tambahData(arr, n, 10);
    tambahData(arr, n, 20);
    tambahData(arr, n, 30);
    tambahData(arr, n, 40);
    tampilkanData(arr, n);              // 10 20 30 40

    int cari = 30;
    int pos = cariData(arr, n, cari);
    if (pos != -1) cout << "Nilai " << cari << " ditemukan pada indeks " << pos << endl;
    else cout << "Nilai " << cari << " tidak ditemukan\n";

    hapusData(arr, n, 1);               // hapus indeks 1 (nilai 20)
    tampilkanData(arr, n);              // 10 30 40

    cari = 20;
    pos = cariData(arr, n, cari);
    if (pos != -1) cout << "Nilai " << cari << " ditemukan pada indeks " << pos << endl;
    else cout << "Nilai " << cari << " tidak ditemukan\n";

    delete[] arr;                       // bebaskan memori terakhir
    return 0;
}