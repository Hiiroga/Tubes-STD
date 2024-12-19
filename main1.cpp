#include <iostream>
#include "gerbong.h"
using namespace std;

int main() {
    int pilihan;
    ListGerbong G;
    ListPenumpang PNP;

    createListGerbong(G);
    createListPenumpang(PNP);
    infotype datagerbong;
    infotypeP datapenumpang;
    pilihan = menuutama();

    while (pilihan != 0) {
        switch (pilihan) {
            case 1: { // Input Data Gerbong
                cout << "----------------------" << endl;
                cout << "  input data gerbong  " << endl;
                cout << "----------------------" << endl;
                cout << "Kode Gerbong: "; cin >> datagerbong.Kode_Gerbong;
                cout << "Kapasitas: "; cin >> datagerbong.Kapasitas;
                datagerbong.Jumlah_Penumpang = 0; // Inisiasi Jumlah Penumpang
                adr_gerbongP idgerbong = SearchG(G, datagerbong.Kode_Gerbong);
                if (idgerbong == NULL) {
                    adr_gerbongP P = createElemenGerbong(datagerbong);
                    InsertLastG(G, P);
                    cout << "Data tersimpan." << endl;
                } else {
                    cout << "ID Gerbong sudah ada." << endl;
                }

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
                string cari;
                cout << "-----------------------" << endl;
                cout << "   Cari Data Gerbong   " << endl;
                cout << "-----------------------" << endl;
                cout << "Input kode gerbong: "; cin >> cari;
                adr_gerbongP found = SearchG(G, cari);
                if (found != NULL) {
                    cout << "Gerbong ditemukan: " << endl;
                    cout << "Kode Gerbong: " << info(found).Kode_Gerbong << endl;
                    cout << "Kapasitas: " << info(found).Kapasitas << endl;
                    cout << "Jumlah penumpang: " << info(found).Jumlah_Penumpang << endl;
                } else {
                    cout << "Gerbong tidak ditemukan: " << endl;
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
                adr_gerbongP P = first(G);
                adr_penumpangP idpnp;
                while (P != NULL) {
                    if (P != NULL) {
                        idpnp = SearchP(child(P), datapenumpang.ID_pnp);
                    }
                    P = next(P);
                }
                if (idpnp == NULL) {
                    connect(G, datapenumpang);
                } else {
                    cout << "ID Penumpang sudah ada." << endl;
                }

                break;
            }

            case 6: { // Update Penumpang
                string idPenumpang;
                cout << "Masukkan ID Penumpang yang ingin diupdate: ";
                cin >> idPenumpang;
                adr_gerbongP P = first(G);
                adr_penumpangP penumpangUpdate;
                while (P != NULL) {
                    penumpangUpdate = SearchP(child(P), idPenumpang);
                    if (penumpangUpdate != NULL) {
                        break;
                    }
                    P = next(P);
                }
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
                    cout << "Jumlah Penumpang: " << info(P).Jumlah_Penumpang << endl; //new
                    cout << "Daftar Penumpang: " << endl;
                    if (P != NULL) {
                        ShowPenumpang(child(P));
                    } else {
                        cout << "Tidak ada penumpang di gerbong ini." << endl;
                    }
                    cout << "-----------------------" << endl;
                    P = next(P);
                }
                break;
            }

           case 8: { //Hapus Data Penumpang Pada Gerbong Tertentu
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbong = SearchG(G, kodeGerbong);
                if (gerbong != NULL) {
                    string idPenumpang;
                    cout << "Masukkan ID Penumpang yang ingin dihapus: ";
                    cin >> idPenumpang;
                    adr_penumpangP penumpangHapus = SearchP(child(gerbong), idPenumpang);
                    if (penumpangHapus != NULL) {
                        if (penumpangHapus == first(child(gerbong))) {
                            first(child(gerbong)) = next(penumpangHapus);
                            next(penumpangHapus) = NULL;
                            info(gerbong).Jumlah_Penumpang--;
                        } else {
                        adr_penumpangP Prec = first(child(gerbong));
                        while (next(Prec) != penumpangHapus) {
                            Prec = next(Prec);
                        }
                        DeleteAfterP(child(gerbong), Prec, penumpangHapus);
                        info(gerbong).Jumlah_Penumpang--;
                    }
                    cout << "Penumpang dengan ID " << idPenumpang << " berhasil dihapus dari gerbong " << kodeGerbong << "." << endl;
                    } else {
                        cout << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan di gerbong ini." << endl;
                    }
                } else {
                    cout << "Gerbong dengan kode " << kodeGerbong << " tidak ditemukan." << endl;
                }
                break;
            }


            case 9: { //Menghitung penumpang pada gerbong tertentu
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong : ";
                cin >> kodeGerbong;
                adr_gerbongP gerbong = SearchG(G, kodeGerbong);
                if (gerbong != NULL) {
                    int jumlahPenumpang = 0;
                    adr_penumpangP penumpang = first(child(gerbong));
                    while (penumpang != NULL) {
                        jumlahPenumpang++;
                        penumpang = next(penumpang);
                    }
                    cout << "Jumlah penumpang di gerbong " << kodeGerbong << " adalah: " << jumlahPenumpang << endl;
                } else {
                    cout << "Gerbong dengan kode " << kodeGerbong << " tidak ditemukan." << endl;
                }
                break;
            }



            case 10: { // Menampilkan semua penumpang
                cout << "------------------------" << endl;
                cout << " Data Seluruh Penumpang " << endl;
                cout << "------------------------" << endl;
                adr_gerbongP P = first(G);
                while (P != NULL) {
                    if (P != NULL) {
                        ShowPenumpang(child(P));
                    } else {
                        cout << "Tidak ada penumpang di gerbong ini." << endl;
                    }
                    P = next(P);
                }
                break;
            }

            case 11: { //Menghapus data parent dan childnya
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong yang ingin dihapus: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbongHapus = SearchG(G, kodeGerbong);
                if (gerbongHapus != NULL) {
                    if (gerbongHapus == first(G)) {
                        adr_gerbongP temp = first(G);
                        first(G) = next(gerbongHapus);
                        adr_penumpangP penumpang = first(child(temp));
                        while (penumpang != NULL) {
                            adr_penumpangP tempPenumpang = penumpang;
                            penumpang = next(penumpang);
                            tempPenumpang = NULL;
                        }
                        next(temp) = NULL;
                    } else {
                        adr_gerbongP Prec = first(G);
                        while (next(Prec) != gerbongHapus) {
                            Prec = next(Prec);
                        }
                        DeleteAfterG(G, Prec, gerbongHapus);
                    }
                    cout << "Gerbong dengan kode " << kodeGerbong << " beserta penumpangnya berhasil dihapus." << endl;
                } else {
                    cout << "Gerbong dengan kode " << kodeGerbong << " tidak ditemukan." << endl;
                }
                break;
        }



            case 12: { // Mencari penumpang pada gerbong tertentu
                string kodeGerbong;
                cout << "Masukkan Kode Gerbong: ";
                cin >> kodeGerbong;
                adr_gerbongP gerbong = SearchG(G, kodeGerbong);
                if (gerbong != NULL) {
                    string idPenumpang;
                    cout << "Masukkan ID Penumpang yang ingin dicari: ";
                    cin >> idPenumpang;
                    adr_penumpangP penumpangCari = SearchP(child(gerbong), idPenumpang);
                    if (penumpangCari != NULL) {
                        cout << "Penumpang ditemukan di gerbong: " << kodeGerbong << endl;
                        cout << "ID Penumpang: " << info(penumpangCari).ID_pnp << endl;
                        cout << "Nama: " << info(penumpangCari).Nama << endl;
                        cout << "Nomor Kursi: " << info(penumpangCari).No_kursi << endl;
                        cout << "Harga Tiket: " << info(penumpangCari).Harga_Tiket << endl;
                    } else {
                        cout << "Penumpang dengan ID " << idPenumpang << " tidak ditemukan di gerbong ini." << endl;
                    }
                } else {
                    cout << "Gerbong dengan kode " << kodeGerbong << " tidak ditemukan." << endl;
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
