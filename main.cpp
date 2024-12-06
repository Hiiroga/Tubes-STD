#include <iostream>
#include "gerbong.h"
using namespace std;

int main(){
    int pilihan;
    ListGerbong G;
    ListPenumpang PNP;

    createListGerbong(G);
    createListPenumpang(PNP);
    infotype datagerbong;
    infotypeP datapenumpang;
    pilihan = menuutama();
    while (pilihan != 0) {
        switch(pilihan){
        case 1: {
            cout << "----------------------" << endl;
            cout << "  input data gerbong  " << endl;
            cout << "----------------------" << endl;
            cout << "Kode Gerbong: "; cin >> datagerbong.Kode_Gerbong;
            cout << "Kapasitas: "; cin >> datagerbong.Kapasitas;
            adr_gerbongP P = createElemenGerbong(datagerbong);
            InsertLastG(G,P);
            break;
        }

        case 2: {
            cout << "----------------------" << endl;
            cout << "     Data Gerbong     " << endl;
            cout << "----------------------" << endl;
            ShowGerbong(G);
            break;
        }

        case 3: {


            break;
        }

        case 4: {
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

        case 5: {
            cout << "----------------------" << endl;
            cout << " input data penumpang " << endl;
            cout << "----------------------" << endl;
            cout << "ID Penumpang: "; cin >> datapenumpang.ID_pnp;
            cout << "Nama: "; cin >> datapenumpang.Nama;
            cout << "Nomor Kursi: "; cin >> datapenumpang.No_kursi;
            cout << "Harga Tiket: "; cin >> datapenumpang.Harga_Tiket;

            adr_penumpangP P = createElemenPenumpang(datapenumpang);
            InsertLastP(PNP,P);
            connect(G,P);
            break;
            }

        case 6: {

            break;
        }

        case 7: {
            cout << "------------------------------------" << endl;
            cout << " Data seluruh Gerbong dan Penumpang " << endl;
            cout << "------------------------------------" << endl;
            adr_gerbongP P = first(G);
            while (P != NULL) {
                cout << "Kode Gerbong: " << info(P).Kode_Gerbong << endl;
                cout << "Kapasitas: " << info(P).Kapasitas << endl;
                cout << "Jumlah Penumpang: " << info(P).Jumlah_Penumpang << endl; //new
                cout << "Daftar Penumpang: " << endl;
                ShowPenumpang(PNP, P);
                P = next(P);
            }
            break;
        }

        case 8: {
            //cout << "Alamat: " << shortestName_103012330085(L) << endl;
            //cout << "Nama: " << info(shortestName_103012330085(L)) << endl;
            //cout << "Kembali ke menu utama? (Y/N) :";
            //cin >> opsi;
            break;
        }

        case 9: {
            //cout << "Alamat: " << shortestName_103012330085(L) << endl;
            //cout << "Nama: " << info(shortestName_103012330085(L)) << endl;
            //cout << "Kembali ke menu utama? (Y/N) :";
            //cin >> opsi;
            break;
        }

        case 10: {
            //cout << "Alamat: " << shortestName_103012330085(L) << endl;
            //cout << "Nama: " << info(shortestName_103012330085(L)) << endl;
            //cout << "Kembali ke menu utama? (Y/N) :";
            //cin >> opsi;
            break;
        }

        case 11: {
            cout << "------------------------" << endl;
            cout << " Data Seluruh Penumpang " << endl;
            cout << "------------------------" << endl;
            showP(PNP);
            break;
        }

        }
        pilihan = menuutama();
    }
    return 0;
}
