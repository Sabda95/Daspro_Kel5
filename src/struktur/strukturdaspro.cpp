#include <iostream>
#include <string>
using namespace std;

int main() {
    // ========================
    // STRUKTUR DATA
    // ========================
    string barang[100];      // List nama barang
    int harga[100];          // List harga barang
    int stok[100];           // List stok barang
    int totalBarang = 0;     // Counter
    
    string jualTanggal[50];  // Dictionary-like untuk penjualan
    string jualBarang[50];
    int jualJumlah[50];
    int jualTotal[50];
    int totalJual = 0;
    
    // ========================
    // MENU UTAMA 
    // ========================
    cout << "=== TOKO GROSIRAN ===\n";
    cout << "1. Menu Gudang:\n";
    cout << "2. Menu Transaksi:\n";
    cout << "3. Menu Laporan:\n";
    cout << "4. Keluar:\n";
    cout << "============================\n";
    
    return 0;
}
