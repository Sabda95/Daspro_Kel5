#include <iostream>
using namespace std;

// Maksimal 100 barang
string namaBarang[100];
int hargaBarang[100];
int stokBarang[100];
int jumlahBarang = 0; // banyak barang yg tersimpan

// cari barang
int cariBarang(string nama) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (namaBarang[i] == nama) {
            return i;
        }
    }
    return -1;
}

// fitur transaksi
void transaksiPenjualan() {
    string nama;
    int jumlah;

    cout << "Nama barang: ";
    cin >> nama;

    int index = cariBarang(nama);

    if (index == -1) {
        cout << "Barang tidak ditemukan!\n";
        return;
    }

    cout << "Jumlah beli: ";
    cin >> jumlah;

    if (jumlah > stokBarang[index]) {
        cout << "Stok tidak cukup!\n";
        return;
    }

    int total = hargaBarang[index] * jumlah;

    stokBarang[index] -= jumlah; // kurangi stok

    cout << "Total harga: " << total << endl;
    cout << "Transaksi berhasil!\n";
}

// tambah barang (fitur naila)
void tambahBarang() {
    cout << "Nama barang: ";
    cin >> namaBarang[jumlahBarang];

    cout << "Harga: ";
    cin >> hargaBarang[jumlahBarang];

    cout << "Stok awal: ";
    cin >> stokBarang[jumlahBarang];

    jumlahBarang++;

    cout << "Barang ditambahkan!\n";
}

int main() {
    int pilih;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah barang\n";
        cout << "2. Transaksi penjualan\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) tambahBarang();
        else if (pilih == 2) transaksiPenjualan();
        else if (pilih == 3) break;
        else cout << "Menu tidak valid\n";
    }

    return 0;
}
