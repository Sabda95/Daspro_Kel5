#include <iostream>
#include <string>
using namespace std;

// Deklarasi global (maksimal 100 barang)
string namaBarang[100];
int hargaBarang[100];
int stokBarang[100];
int jumlahBarang = 0;

// Deklarasi fungsi
void tambahBarang();
void lihatBarang();
void updateStok();
void transaksi();

int main() {
    int pilihan;
    
    // Contoh data awal (bisa dihapus)
    namaBarang[0] = "Beras 5kg";
    hargaBarang[0] = 50000;
    stokBarang[0] = 100;
    jumlahBarang = 1;
    
    namaBarang[1] = "Minyak Goreng 2L";
    hargaBarang[1] = 25000;
    stokBarang[1] = 50;
    jumlahBarang = 2;
    
    do {
        system; // Untuk clear screen (Windows)
        
        cout << "================================" << endl;
        cout << "     TOKO GROSIR     " << endl;
        cout << "================================" << endl;
        cout << "1. Tambah Barang Baru" << endl;
        cout << "2. Lihat Semua Barang" << endl;
        cout << "3. Update Stok Barang" << endl;
        cout << "4. Transaksi Penjualan" << endl;
        cout << "5. Keluar" << endl;
        cout << "================================" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: tambahBarang(); break;
            case 2: lihatBarang(); break;
            case 3: updateStok(); break;
            case 4: transaksi(); break;
            case 5: cout << "Program selesai!" << endl; break;
            default: cout << "Pilihan salah!" << endl;
        }
        
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        
    } while(pilihan != 5);
    
    return 0;
}

// Implementasi fungsi-fungsi
void tambahBarang() {
    cout << "\n-- TAMBAH BARANG --" << endl;
    
    if(jumlahBarang >= 100) {
        cout << "Gudang sudah penuh!" << endl;
        return;
    }
    
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, namaBarang[jumlahBarang]);
    
    cout << "Harga: ";
    cin >> hargaBarang[jumlahBarang];
    
    cout << "Stok: ";
    cin >> stokBarang[jumlahBarang];
    
    jumlahBarang++;
    cout << "Barang berhasil ditambahkan!" << endl;
}

void lihatBarang() {
    cout << "\n-- DAFTAR BARANG --" << endl;
    
    if(jumlahBarang == 0) {
        cout << "Tidak ada barang di gudang." << endl;
        return;
    }
    
    for(int i = 0; i < jumlahBarang; i++) {
        cout << "Barang ke-" << (i+1) << endl;
        cout << "  Nama: " << namaBarang[i] << endl;
        cout << "  Harga: Rp" << hargaBarang[i] << endl;
        cout << "  Stok: " << stokBarang[i] << endl;
        cout << endl;
    }
}

void updateStok() {
    string nama;
    int indeks = -1;
    
    cout << "\n-- UPDATE STOK --" << endl;
    cout << "Nama barang: ";
    cin.ignore();
    getline(cin, nama);
    
    for(int i = 0; i < jumlahBarang; i++) {
        if(namaBarang[i] == nama) {
            indeks = i;
            break;
        }
    }
    
    if(indeks == -1) {
        cout << "Barang tidak ditemukan!" << endl;
        return;
    }
    
    cout << "Stok sekarang: " << stokBarang[indeks] << endl;
    cout << "Stok baru: ";
    cin >> stokBarang[indeks];
    cout << "Stok berhasil diupdate!" << endl;
}

void transaksi() {
    string nama;
    int indeks = -1;
    int jumlah;
    
    cout << "\n-- TRANSAKSI --" << endl;
    cout << "Nama barang: ";
    cin.ignore();
    getline(cin, nama);
    
    for(int i = 0; i < jumlahBarang; i++) {
        if(namaBarang[i] == nama) {
            indeks = i;
            break;
        }
    }
    
    if(indeks == -1) {
        cout << "Barang tidak ditemukan!" << endl;
        return;
    }
    
    cout << "Harga: Rp" << hargaBarang[indeks] << endl;
    cout << "Stok: " << stokBarang[indeks] << endl;
    cout << "Jumlah beli: ";
    cin >> jumlah;
    
    if(jumlah > stokBarang[indeks]) {
        cout << "Stok tidak cukup!" << endl;
        return;
    }
    
    int total = hargaBarang[indeks] * jumlah;
    stokBarang[indeks] -= jumlah;
    
    cout << "\n-- STRUK --" << endl;
    cout << namaBarang[indeks] << " x " << jumlah << endl;
    cout << "Total: Rp" << total << endl;
    cout << "Stok sisa: " << stokBarang[indeks] << endl;
}