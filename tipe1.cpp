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
    //child(P) = new ListPenumpang;
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

void DeleteFirstG(ListGerbong &L, adr_gerbongP P){
    if (next(first(L)) != NULL) {
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    } else {
        P = first(L);
        first(L) = NULL;
    }
}

adr_gerbongP SearchG(ListGerbong L, string kode){
    adr_gerbongP P = first(L);
    while (P != NULL) {
        if (info(P).Kode_Gerbong == kode) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


void createListPenumpang(ListPenumpang &L){
    first(L) = NULL;
}

adr_penumpangP createElemenPenumpang(infotypeP X){
    adr_penumpangP P = new elemenpenumpang;
    info(P) = X;
    next(P) = NULL;
    return P;
}

void InsertLastP(ListPenumpang &L, adr_penumpangP P){
    adr_penumpangP Q = first(L);
    if (Q == NULL) {
        first(L) = P;
    } else {
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void ShowPenumpang(ListPenumpang L){
    adr_penumpangP P = first(L);
    if (first(L) == NULL) {
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

void DeleteFirstP(ListPenumpang &L, adr_penumpangP P){
    //if (next(first(L)) == NULL) {
       // P = first(L);
       // first(L) = NULL;
       // last(L) = NULL;
    //} else {
       // P = first(L);
       // first(L) = next(P);
       // next(P) = NULL;
       // prev(first(L)) = NULL;
   // }
}

adr_penumpangP SearchP(ListPenumpang L, string ID){
    adr_penumpangP P = first(L);
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
        adr_penumpangP P = createElemenPenumpang(dataPNP);
        InsertLastP(child(Q),P);
        info(Q).Jumlah_Penumpang++;
        cout << "Data Tersimpan." << endl;
    } else {
        cout << "Kode gerbong tidak ditemukan." << endl;
        connect(G, dataPNP);
    }
}

void disconnect(adr_penumpangP &C) {
    //parent(C) = NULL;
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
    cout << "\n8. Hapus Data Penumpang Setelah Tertentu";
    cout << "\n9. Hapus Data Penumpang Pada Gerbong Tertentu";
    cout << "\n10. Hitung Jumlah Penumpang dalam Gerbong Tertentu";
    cout << "\n11. Tampilkan Semua Penumpang";
    cout << "\n12. Hapus Data Gerbong dan Penumpangnya";
    cout << "\n13. Cari Penumpang dalam Gerbong Tertentu";
    cout << "\n0. Exit\n";
    cout << "Pilih Menu: ";
    int input = 0;
    cin >> input;
    return input;
}

void showP(ListPenumpang L){
    adr_penumpangP P = first(L);
    if (first(L) == NULL) {
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
