#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Buku {
    string judul;
    int stok;
};

int main() {
    int pilihan, loop = 0;
    string username;
    string password;
    vector<Buku> koleksiBuku;
    string cari;  // Deklarasi variabel 'cari'

    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;

    if (username == "admin" && password == "1234") {
        do {
            system("cls");
            cout << "Menu:" << endl;
            cout << "1. Input buku" << endl;
            cout << "2. Tampilkan semua buku" << endl;
            cout << "3. Cari buku" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            switch (pilihan) {
                case 1: {
                    Buku buku;
                    cout << "Masukkan judul buku: ";
                    cin.ignore();
                    getline(cin, buku.judul);
                    cout << "Masukkan stok buku: ";
                    cin >> buku.stok;
                    if (buku.stok >= 0) {
                        koleksiBuku.push_back(buku);
                        cout << "Buku berhasil ditambahkan." << endl;
                    } else {
                        cout << "Stok buku tidak valid." << endl;
                    }
                    system("pause");
                    break;
                }
                case 2:
                    if (koleksiBuku.empty()) {
                        cout << "Tidak ada buku." << endl;
                    } else {
                        for (const auto &buku : koleksiBuku) {
                            cout << "Judul: " << buku.judul << ", Stok: " << buku.stok << endl;
                        }
                    }
                    system("pause");
                    break;
                case 3: {
                    cout << "Masukkan judul buku: ";
                    cin.ignore();
                    getline(cin, cari);
                    bool found = false;
                    for (const auto &buku : koleksiBuku) {
                        if (buku.judul == cari) {
                            cout << "Stok buku: " << buku.stok << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Buku tidak ditemukan." << endl;
                    }
                    system("pause");
                    break;
                }
                default:
                    cout << "Pilihan tidak valid." << endl;
                    system("pause");
            }
            loop++;
            if (loop >= 5) {
                cout << "Anda telah melakukan 5 kali pilihan. Program akan keluar." << endl;
                break;
            }
        } while (true);
    } else {
        cout << "Login gagal. Program akan keluar." << endl;
    }

    return 0;
}
