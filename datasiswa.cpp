#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tabel {
    string nama;
    int nis;
    string ibu;
    int nik;
    string tk = "";
    string sd = "";
    int noSd = 0;
    string smp = "";
    int noSmp = 0;
};

void inputData(Tabel &s){
    cout << "Masukkan Nama Siswa: ";
    getline(cin, s.nama);
    cout << "Masukkan NIS: ";
    cin >> s.nis;
    cin.ignore();
    cout << "Masukkan Nama Ibu: ";
    getline(cin, s.ibu);
    cout << "Masukkan NIK: ";
    cin >> s.nik;
    cin.ignore();
}

int main() {
    vector<Tabel> daftarSiswa;

    string nama, ibu, tk, sd, smp;
    int nis, nik, noSd, noSmp;

    while (true){
        cout << "\n=== PROGRAM INPUT DATA SISWA ===\n"
             << endl;
        cout << "1. Masukkan Data Siswa" << endl;
        cout << "2. Lihat Data Siswa" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih opsi (1-3): ";
        int opsi;
        cin >> opsi;
        cin.ignore();

        if (opsi == 1) {
            cout << "\nPilih Tingkat Sekolah:" << endl;
            cout << "1. TK" << endl;
            cout << "2. SD" << endl;
            cout << "3. SMP" << endl;
            cout << "4. SMA" << endl;

            int pilihan;
            int JumlahData;
            cout << "Masukkan pilihan (1-4): ";
            cin >> pilihan;
            cin.ignore();
            if (pilihan < 1 || pilihan > 4) {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                continue;
            } else {
                cout << "Masukkan jumlah data yang ingin diinput: ";
                cin >> JumlahData;
                cin.ignore();
                if (JumlahData <= 0) {
                    cout << "Jumlah data harus lebih dari 0. Silakan coba lagi." << endl;
                    continue;
                }
            }

            for (int i = 0; i < JumlahData; i++) {
                Tabel siswa;
                cout << "\n=== Data ke-" << (i + 1) << " ===" << endl;

                switch (pilihan) {
                case 1:
                    inputData(siswa);
                    break;
                case 2:
                    inputData(siswa);
                    cout << "Nama TK sebelumnya: ";
                    getline(cin, siswa.tk);
                    break;
                case 3:
                    inputData(siswa);
                    cout << "Nama TK sebelumnya: ";
                    getline(cin, siswa.tk);
                    cout << "Nama SD sebelumnya: ";
                    getline(cin, siswa.sd);
                    cout << "Nomor Ijazah SD: ";
                    cin >> siswa.noSd;
                    cin.ignore();
                    break;
                case 4:
                    inputData(siswa);
                    cout << "Nama TK sebelumnya: ";
                    getline(cin, siswa.tk);
                    cout << "Nama SD sebelumnya: ";
                    getline(cin, siswa.sd);
                    cout << "Nomor Ijazah SD: ";
                    cin >> siswa.noSd;
                    cin.ignore();
                    cout << "Nama SMP sebelumnya: ";
                    getline(cin, siswa.smp);
                    cout << "Nomor Ijazah SMP: ";
                    cin >> siswa.noSmp;
                    cin.ignore();
                    break;
                }
                daftarSiswa.push_back(siswa);
            }
            continue;
        }

        else if (opsi == 2) {
            cout << "\nPilih Data Siswa Dari Tingkat Sekolah:" << endl;
            cout << "1. TK" << endl;
            cout << "2. SD" << endl;
            cout << "3. SMP" << endl;
            cout << "4. SMA" << endl;
            int PilihData;
            string NamaTingkat;
            cout << "Masukkan pilihan (1-4): ";
            cin >> PilihData;
            cin.ignore();
            switch (PilihData) {
            case 1:
                NamaTingkat = "TK";
                break;
            case 2:
                NamaTingkat = "SD";
                break;
            case 3:
                NamaTingkat = "SMP";
                break;
            case 4:
                NamaTingkat = "SMA";
                break;
            default:
                cout << "Tidak ada pilihan " << PilihData << ". Ulangi." << endl;
                continue;
            }

            cout << "\n=== DAFTAR SISWA " << NamaTingkat << " ===" << endl;
            bool AdaData = false;
            for (int i = 0; i < daftarSiswa.size(); i++) {
                const Tabel &s = daftarSiswa[i];
                bool tampilkan = false;
                switch (PilihData) {
                case 1:
                    if (s.tk == "" && s.sd == "" && s.smp == "") tampilkan = true;
                    break;
                case 2:
                    if (!s.tk.empty() && s.sd.empty() && s.smp.empty()) tampilkan = true;
                    break;
                case 3:
                    if (!s.sd.empty() && s.smp.empty()) tampilkan = true;
                    break;
                case 4:
                    if (!s.smp.empty()) tampilkan = true;
                    break;
                }
                if (tampilkan) {
                    AdaData = true;
                    cout << "\nData Siswa ke-" << i + 1 << ": " << endl;
                    cout << "Nama: " << s.nama << endl;
                    cout << "NIS: " << s.nis << endl;
                    cout << "Nama Ibu: " << s.ibu << endl;
                    cout << "NIK: " << s.nik << endl;
                    if (!s.tk.empty()) {
                        cout << "TK: " << s.tk << endl;
                    }
                    if (!s.sd.empty()) {
                        cout << "SD: " << s.sd << endl;
                    }
                    if (s.noSd != 0) {
                        cout << "Nomor Ijazah SD: " << s.noSd << endl;
                    }
                    if (!s.smp.empty()) {
                        cout << "SMP: " << s.smp << endl;
                    }
                    if (s.noSmp != 0) {
                        cout << "Nomor Ijazah SMP: " << s.noSmp << endl;
                    }
                }
            }
            if (!AdaData) {
                cout << "\nTidak ada data siswa untuk tingkat sekolah " << NamaTingkat << endl;
            }
            continue;
        }
        
        else if (opsi == 3) {
            cout << "Keluar dari program." << endl;
            break;
        }

        else if (opsi < 1 || opsi > 3) {
            cout << "Opsi tidak valid. Silakan coba lagi." << endl;
            continue;
        }
        // break;
    }
    return 0;
}
