#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    double nilai;
    Mahasiswa* next;
};

class CircularLinkedList {
private:
    Mahasiswa* head;

public:
    CircularLinkedList() {
        head = new Mahasiswa;
        head->next = head;
    }

    void insertData() {
        Mahasiswa* baru = new Mahasiswa;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n=== INSERT DATA MAHASISWA ===\n";

        cout << "Nama   : ";
        getline(cin, baru->nama);

        cout << "NIM    : ";
        getline(cin, baru->nim);

        cout << "Gender : ";
        getline(cin, baru->gender);

        cout << "Nilai  : ";
        cin >> baru->nilai;

        Mahasiswa* bantu = head;

        while (bantu->next != head &&
               bantu->next->nim < baru->nim) {
            bantu = bantu->next;
        }

        if (bantu->next != head &&
            bantu->next->nim == baru->nim) {
            cout << "\nNIM sudah terdaftar!\n";
            delete baru;
            return;
        }

        baru->next = bantu->next;
        bantu->next = baru;

        cout << "\nData berhasil ditambahkan!\n";
    }

    void hapusData() {
        if (head->next == head) {
            cout << "\nLinked List masih kosong!\n";
            return;
        }

        string cariNIM;

        cout << "\nMasukkan NIM yang akan dihapus: ";
        cin >> cariNIM;

        Mahasiswa* bantu = head;

        while (bantu->next != head &&
               bantu->next->nim != cariNIM) {
            bantu = bantu->next;
        }

        if (bantu->next == head) {
            cout << "\nData dengan NIM tersebut tidak ditemukan!\n";
            return;
        }

        Mahasiswa* hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;

        cout << "\nData berhasil dihapus!\n";
    }

    void cetakData() {
        if (head->next == head) {
            cout << "\nLinked List masih kosong!\n";
            return;
        }

        Mahasiswa* bantu = head->next;

        cout << "\n========== DATA MAHASISWA ==========\n";

        cout << "---------------------------------------------\n";
        cout << "NIM\t\tNama\t\tGender\tNilai\n";
        cout << "---------------------------------------------\n";

        while (bantu != head) {
            cout << bantu->nim << "\t"
                 << bantu->nama << "\t\t"
                 << bantu->gender << "\t"
                 << bantu->nilai << endl;

            bantu = bantu->next;
        }

        cout << "---------------------------------------------\n";
    }

    void keluar() {
        Mahasiswa* bantu = head->next;

        while (bantu != head) {
            Mahasiswa* hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }

        delete head;
    }
};

int main() {
    CircularLinkedList data;
    int pilihan;

    do {
        cout << "\n";
        cout << "================================\n";
        cout << "       CIRCULAR LINKED LIST     \n";
        cout << "================================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "================================\n";
        cout << "Pilihan (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                data.insertData();
                break;

            case 2:
                data.hapusData();
                break;

            case 3:
                data.cetakData();
                break;

            case 4:
                data.keluar();
                cout << "\nProgram selesai. Terima kasih!\n";
                break;

            default:
                cout << "\nPilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}

