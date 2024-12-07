#include <iostream>
#include "gerbong.h"
using namespace std;

int main() {
    int pilihan;
    ListGerbong G;
    ListPenumpang LPNP;

    createListGerbong(G);
    createListPenumpang(LPNP);
    infotype datagerbong;
    infotypeP datapenumpang;

    pilihan = menuutama();
    while (pilihan != 0) {
        switch (pilihan) {
            case 1: { // Input Data Gerbong
                cout << "----------------------" << endl;
                cout << "  Input Data Gerbong  " << endl;
                cout << "----------------------" << endl;
                cout << "Kode Gerbong: "; cin >> datagerbong.Kode_Gerbong;
                cout << "Kapasitas: "; cin >> datagerbong.Kapasitas;
                datagerbong.Jumlah_Penumpang = 0; // Inisiasi Jumlah Penumpang
                adr_gerbongP P = createElemenGerbong(datagerbong);
                InsertLastG(G, P);
                break;
            }

            case 2: { // Tampilkan Data Gerbong
                cout << "----------------------" << endl;
                cout << "     Data Gerbong     " << endl;
                cout << "----------------------" << endl;
                ShowGerbong(G);
                break;
            }

            case 3: { // Update Data Gerbong
                string kodeGerbong;
                cout << "Masukkan kode gerbong yang ingin diupdate: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbongUpdate = SearchG(G, kodeGerbong);
                if (gerbongUpdate != NULL) {
                    cout << "Masukkan Kapasitas Baru: ";
                    cin >> info(gerbongUpdate).Kapasitas;
                    cout << "Kapasitas gerbong berhasil diupdate." << endl;
                } else {
                    cout << "Gerbong tidak ditemukan." << endl;
                }
                break;
            }

            case 4: { // Cari Gerbong
                string kodeGerbong;
                cout << "Masukkan kode gerbong yang ingin dicari: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbongFound = SearchG(G, kodeGerbong);
                if (gerbongFound != NULL) {
                    cout << "Gerbong ditemukan: " << endl;
                    cout << "Kode Gerbong: " << info(gerbongFound).Kode_Gerbong << endl;
                    cout << "Kapasitas: " << info(gerbongFound).Kapasitas << endl;
                    cout << "Jumlah Penumpang: " << info(gerbongFound).Jumlah_Penumpang << endl;
                } else {
                    cout << "Gerbong tidak ditemukan." << endl;
                }
                break;
            }

            case 5: { // Input Penumpang
                cout << "----------------------" << endl;
                cout << " input data penumpang " << endl;
                cout << "----------------------" << endl;
                cout << "ID Penumpang: "; cin >> datapenumpang.ID_pnp;
                cout << "Nama: "; cin >> datapenumpang.Nama;
                cout << "Nomor Kursi: "; cin >> datapenumpang.No_kursi;
                cout << "Harga Tiket: "; cin >> datapenumpang.Harga_Tiket;

                adr_penumpangP P = createElemenPenumpang(datapenumpang);
                InsertLastP(LPNP, P);
                connect(G, P);
                break;
            }

            case 6: { // Update Penumpang
                string idPenumpang;
                cout << "Masukkan ID Penumpang yang ingin diupdate: ";
                cin >> idPenumpang;
                adr_penumpangP penumpangUpdate = SearchP(LPNP, idPenumpang);
                if (penumpangUpdate != NULL) {
                    cout << "Masukkan Nama Baru: ";
                    cin >> info(penumpangUpdate).Nama;
                    cout << "Masukkan Nomor Kursi Baru: ";
                    cin >> info(penumpangUpdate).No_kursi;
                    cout << "Masukkan Harga Tiket Baru: ";
                    cin >> info(penumpangUpdate).Harga_Tiket;
                    cout << "Data Penumpang berhasil diupdate." << endl;
                } else {
                    cout << "Penumpang tidak ditemukan." << endl;
                }
                break;
            }

            case 7: { // Tampilkan Semua Gerbong dan Penumpang
                cout << "------------------------------------" << endl;
                cout << " Data seluruh Gerbong dan Penumpang " << endl;
                cout << "------------------------------------" << endl;
                adr_gerbongP P = first(G);
                while (P != NULL) {
                    cout << "Kode Gerbong: " << info(P).Kode_Gerbong << endl;
                    cout << "Kapasitas: " << info(P).Kapasitas << endl;
                    cout << "Jumlah Penumpang: " << info(P).Jumlah_Penumpang << endl;
                    cout << "Daftar Penumpang: " << endl;
                    ShowPenumpang(LPNP, P); // Menampilkan penumpang di gerbong
                    P = next(P);
                }
                break;
            }

            case 8: { // Menghapus data Penumpang tertentu
                string idPenumpang;
                cout << "Masukkan ID Penumpang yang ingin dihapus: ";
                cin >> idPenumpang;
                adr_penumpangP penumpangHapus = SearchP(LPNP, idPenumpang);
                if (penumpangHapus != NULL) {
                    deletePenumpang(LPNP, penumpangHapus);
                    cout << "Penumpang berhasil diputus." << endl;
                } else {
                    cout << "Penumpang tidak ditemukan." << endl;
                }
                break;
            }

            case 9: { // Menghapus data penumpang pada gerbong tertentu
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbong = SearchG(G, kodeGerbong);
                if (gerbong != NULL) {
                    string idPenumpang;
                    cout << "Masukkan ID Penumpang yang ingin dihapus: ";
                    cin >> idPenumpang;
                    adr_penumpangP penumpangHapus = SearchP(LPNP, idPenumpang);
                    if (penumpangHapus != NULL && parent(penumpangHapus) == gerbong) {
                        deletePenumpang(LPNP, penumpangHapus);
                        cout << "Penumpang berhasil diputus dari gerbong." << endl;
                    } else {
                        cout << "Penumpang tidak ditemukan di gerbong ini." << endl;
                    }
                } else {
                    cout << "Gerbong tidak ditemukan." << endl;
                }
                break;
            }

            case 10: { // Menghitung jumlah penumpang pada gerbong tertentu
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbong = SearchG(G, kodeGerbong);
                if (gerbong != NULL) {
                    int jumlahPenumpang = 0;
                    adr_penumpangP P = first(LPNP);
                    while (P != NULL) {
                        if (parent(P) == gerbong) {
                            jumlahPenumpang++;
                        }
                        P = next(P);
                    }
                    cout << "Jumlah penumpang di gerbong " << kodeGerbong << ": " << jumlahPenumpang << endl;
                } else {
                    cout << "Gerbong tidak ditemukan." << endl;
                }
                break;
            }

            case 11: { // Menampilkan semua penumpang
                cout << "------------------------" << endl;
                cout << " Data Seluruh Penumpang " << endl;
                cout << "------------------------" << endl;
                showP(LPNP);
                break;
            }

            case 12: { // Menghapus Data Parent dan Child-nya
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong yang ingin dihapus: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbongHapus = SearchG(G, kodeGerbong);
                if (gerbongHapus != NULL) {
                    DeleteParentAndChild(G, LPNP, kodeGerbong); 
                } else {
                    cout << "Gerbong tidak ditemukan." << endl;
                }
                break;
            }

            default: {
                cout << "Pilihan tidak valid! Silakan pilih lagi." << endl;
                break;
            }
        }
        pilihan = menuutama();
    }

    return 0;
}
