#include <iostream>
using namespace std;
#include "gerbong.h"

void createListGerbong(ListGerbong &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_gerbongP createElemenGerbong(infotype X) {
    adr_gerbongP P = new elemengerbong;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    createListPenumpang(child(P));
    return P;
}

void InsertLastG(ListGerbong &L, adr_gerbongP P) {
    if (first(L) == NULL && last(L) == NULL) {
        first(L) = P;
        last(L) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void ShowGerbong(ListGerbong L) {
    adr_gerbongP P = first(L);
    if (first(L) == NULL && last(L) == NULL) {
        cout << "Tidak ada data gerbong." << endl;
    } else {
        while (P != NULL) {
        cout << "Kode Gerbong: " << info(P).Kode_Gerbong << endl;
        cout << "Kapasitas: " << info(P).Kapasitas << endl;
        cout << "Jumlah Penumpang: " << info(P).Jumlah_Penumpang << endl; //new
        cout << "    " << endl;
        P = next(P);
        }
    }

}

void DeleteAfterG(ListGerbong &L,adr_gerbongP Prec, adr_gerbongP P) {
    if (Prec == NULL || next(Prec) == NULL) {
        cout << "Gerbong tidak ditemukan" <<endl;
        P = NULL;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
        cout << "Gerbong berhasil dihapus dari list" <<endl;
    }
}

adr_gerbongP SearchG(ListGerbong LPNP, string kode){
    adr_gerbongP P = first(LPNP);
    while (P != NULL) {
        if (info(P).Kode_Gerbong == kode) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


void createListPenumpang(ListPenumpang &LPNP){
    first(LPNP) = NULL;
}

adr_penumpangP createElemenPenumpang(infotypeP X){
    adr_penumpangP P = new elemenpenumpang;
    info(P) = X;
    next(P) = NULL;
    return P;
}

void InsertLastP(ListPenumpang &LPNP, adr_penumpangP P){
    adr_penumpangP Q = first(LPNP);
    if (Q == NULL) {
        first(LPNP) = P;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void ShowPenumpang(ListPenumpang LPNP){
    adr_penumpangP P = first(LPNP);
    if (first(LPNP) == NULL) {
        cout << "Tidak ada data penumpang." << endl;
    } else {
        while (P != NULL) {
            cout << "ID Penumpang: " << info(P).ID_pnp << endl;
            cout << "Nama: " << info(P).Nama << endl;
            cout << "Nomor Kursi: " << info(P).No_kursi << endl;
            cout << "Harga Tiket: " << info(P).Harga_Tiket << endl; //new
            cout << "    " << endl;
            P = next(P);
        }
    }
}


void DeleteAfterP(ListPenumpang &LPNP,adr_penumpangP Prec, adr_penumpangP P) {
    if (Prec == NULL || next(Prec) == NULL) {
        cout << "Penumpang tidak ditemukan" <<endl;
        P = NULL;
    } else {
        P = next(Prec);
        next(Prec) = next(P);
        next(P) = NULL;
        cout << "Penumpang berhasil dihapus dari list" <<endl;
    }
}

adr_penumpangP SearchP(ListPenumpang LPNP, string ID){
    adr_penumpangP P = first(LPNP);
    while (P != NULL) {
        if (info(P).ID_pnp == ID) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void connect(ListGerbong G, infotypeP dataPNP) {
    string kodegerbong;
    cout << "Kode Gerbong: "; cin >> kodegerbong;
    adr_gerbongP Q = SearchG(G, kodegerbong);
    if (Q != NULL) {
        if (info(Q).Jumlah_Penumpang < info(Q).Kapasitas) {
        adr_penumpangP P = createElemenPenumpang(dataPNP);
        InsertLastP(child(Q),P);
        info(Q).Jumlah_Penumpang++;
        cout << "Data Tersimpan." << endl;
        } else {
            cout << "Kapasitas gerbong sudah penuh, penumpang tidak bisa ditambahkan." << endl;
        }
    } else {
        cout << "Kode gerbong tidak ditemukan." << endl;
        connect(G, dataPNP);
    }
}

int menuutama() {
    cout << "------------------------------------------" << endl;
    cout << "                MENU UTAMA                " << endl;
    cout << "------------------------------------------" << endl;
    cout << "1. Input Data Gerbong";
    cout << "\n2. Tampilkan Data Gerbong";
    cout << "\n3. Update Data Gerbong";
    cout << "\n4. Cari Data Gerbong";
    cout << "\n5. Input Data Penumpang";
    cout << "\n6. Update Data Penumpang";
    cout << "\n7. Tampilkan Semua Data Gerbong dan Penumpang";
    cout << "\n8. Hapus Data Penumpang Pada Gerbong Tertentu";
    cout << "\n9. Hitung Jumlah Penumpang dalam Gerbong Tertentu";
    cout << "\n10. Tampilkan Semua Penumpang";
    cout << "\n11. Hapus Data Gerbong dan Penumpangnya";
    cout << "\n12. Cari Penumpang dalam Gerbong Tertentu";
    cout << "\n0. Exit\n";
    cout << "Pilih Menu: ";
    int input = 0;
    cin >> input;
    return input;
}

void showP(ListPenumpang LPNP){
    adr_penumpangP P = first(LPNP);
    if (first(LPNP) == NULL) {
        cout << "Tidak ada data Penumpang." << endl;
    } else {
        while (P != NULL) {
            cout << "ID Penumpang: " << info(P).ID_pnp << endl;
            cout << "Nama: " << info(P).Nama << endl;
            cout << "Nomor Kursi: " << info(P).No_kursi << endl;
            cout << "Harga Tiket: " << info(P).Harga_Tiket << endl; //new
            cout << "    " << endl;
            P = next(P);
        }
    }
}

