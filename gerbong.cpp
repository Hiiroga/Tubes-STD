#include <iostream>
#include "gerbong.h"
using namespace std;

void createListGerbong(ListGerbong &L) {
    first(L) = NULL;
}

adr_gerbongP createElemenGerbong(infotype X) {
    adr_gerbongP P = new elmlistgerbong;
    info(P) = X;
    next(P) = NULL;
    return P;
}

void InsertLastG(ListGerbong &L, adr_gerbongP P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_gerbongP last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

void ShowGerbong(ListGerbong L) {
    adr_gerbongP P = first(L);
    while (P != NULL) {
        cout << "Kode Gerbong: " << info(P).Kode_Gerbong << endl;
        cout << "Kapasitas: " << info(P).Kapasitas << endl;
        cout << "Jumlah Penumpang: " << info(P).Jumlah_Penumpang << endl;
        P = next(P);
    }
}

adr_gerbongP SearchG(ListGerbong L, string kode) {
    adr_gerbongP P = first(L);
    while (P != NULL) {
        if (info(P).Kode_Gerbong == kode) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void DeleteParentAndChild(ListGerbong &L, ListPenumpang &LPNP, string kodeGerbong) {
    adr_gerbongP P = SearchG(L, kodeGerbong);
    if (P != NULL) {
        adr_penumpangP Q = first(LPNP);
        while (Q != NULL) {
            if (parent(Q) == P) {
                parent(Q) = NULL;
            }
            Q = next(Q);
        }
        if (P == first(L)) {
            first(L) = next(P);
        } else {
            adr_gerbongP prec = first(L);
            while (next(prec) != P) {
                prec = next(prec);
            }
            next(prec) = next(P);
        }
        cout << "Data gerbong dan penumpang berhasil dihapus." << endl;
    } else {
        cout << "Gerbong tidak ditemukan!" << endl;
    }
}


void createListPenumpang(ListPenumpang &LPNP) {
    first(LPNP) = last(LPNP) = NULL;
}

adr_penumpangP createElemenPenumpang(infotypeP X) {
    adr_penumpangP P = new elmlistpenumpang;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    parent(P) = NULL;
    return P;
}

void InsertLastP(ListPenumpang &LPNP, adr_penumpangP P) {
    if (first(LPNP) == NULL) {
        first(LPNP) = last(LPNP) = P;
    } else {
        next(last(LPNP)) = P;
        prev(P) = last(LPNP);
        last(LPNP) = P;
    }
}

void ShowPenumpang(ListPenumpang LPNP, adr_gerbongP G) {
    adr_penumpangP P = first(LPNP);
    while (P != NULL) {
        if (parent(P) == G) {
            cout << "ID Penumpang: " << info(P).ID_pnp << endl;
            cout << "Nama: " << info(P).Nama << endl;
            cout << "Nomor Kursi: " << info(P).No_kursi << endl;
            cout << "Harga Tiket: " << info(P).Harga_Tiket << endl;
        }
        P = next(P);
    }
}

adr_penumpangP SearchP(ListPenumpang LPNP, string ID) {
    adr_penumpangP P = first(LPNP);
    while (P != NULL) {
        if (info(P).ID_pnp == ID) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void UpdateGerbong(ListGerbong &L, string kodeGerbong) {
    adr_gerbongP P = SearchG(L, kodeGerbong);
    if (P != NULL) {
        cout << "Data Gerbong: " << endl;
        cout << "Kode Gerbong: " << info(P).Kode_Gerbong << endl;
        cout << "Kapasitas: " << info(P).Kapasitas << endl;
        cout << "Jumlah Penumpang: " << info(P).Jumlah_Penumpang << endl;

        cout << "Update Kode Gerbong: ";
        cin >> info(P).Kode_Gerbong;
        cout << "Update Kapasitas: ";
        cin >> info(P).Kapasitas;
    } else {
        cout << "Gerbong tidak ditemukan!" << endl;
    }
}

void UpdatePenumpang(ListPenumpang &LPNP, string IDPenumpang) {
    adr_penumpangP P = SearchP(LPNP, IDPenumpang);
    if (P != NULL) {
        cout << "Data Penumpang: " << endl;
        cout << "ID Penumpang: " << info(P).ID_pnp << endl;
        cout << "Nama: " << info(P).Nama << endl;
        cout << "Nomor Kursi: " << info(P).No_kursi << endl;
        cout << "Harga Tiket: " << info(P).Harga_Tiket << endl;

        cout << "Update Nama: ";
        cin >> info(P).Nama;
        cout << "Update Nomor Kursi: ";
        cin >> info(P).No_kursi;
        cout << "Update Harga Tiket: ";
        cin >> info(P).Harga_Tiket;
    } else {
        cout << "Penumpang tidak ditemukan!" << endl;
    }
}

void DeleteChildInParent(ListPenumpang &LPNP, string IDPenumpang, adr_gerbongP G) {
    adr_penumpangP P = SearchP(LPNP, IDPenumpang);
    if (P != NULL && parent(P) == G) {
        if (P == first(LPNP)) {
            first(LPNP) = next(P);
        } else {
            adr_penumpangP prec = first(LPNP);
            while (next(prec) != P) {
                prec = next(prec);
            }
            next(prec) = next(P);
        }
        parent(P) = NULL;
        cout << "Penumpang berhasil dihapus." << endl;
    } else {
        cout << "Penumpang atau Gerbong tidak ditemukan!" << endl;
    }
}

int CountChildInParent(ListPenumpang LPNP, adr_gerbongP G) {
    int count = 0;
    adr_penumpangP P = first(LPNP);
    while (P != NULL) {
        if (parent(P) == G) {
            count++;
        }
        P = next(P);
    }
    return count;
}

void DeleteAfterP(ListPenumpang &LPNP, adr_penumpangP Prec) {
    if (next(Prec) != NULL) {
        adr_penumpangP P = next(Prec);
        next(Prec) = next(P);
        parent(P) = NULL;
    }
}

void connect(ListGerbong &G, adr_penumpangP &C) {
    string kodegerbong;
    cout << "Kode Gerbong: "; cin >> kodegerbong;
    adr_gerbongP Q = SearchG(G, kodegerbong);
    if (Q != NULL) {
        parent(C) = Q;
        info(Q).Jumlah_Penumpang++;
        cout << "Data Tersimpan." << endl;
    } else {
        cout << "Kode gerbong tidak ditemukan." << endl;
        connect(G, C);
    }
}

void disconnect(adr_penumpangP &C) {
    parent(C) = NULL;
}

int menuutama() {
    int pilihan;
    cout << "\nMenu Utama: ";
    cout << "\n1. Input Data Gerbong";
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
    cout << "\n0. Exit\n";
    cout << "Pilih Menu: ";
    cin >> pilihan;
    return pilihan;
}


void showP(ListPenumpang LPNP) {
    adr_penumpangP P = first(LPNP);
    if (P == NULL) {
        cout << "Tidak ada penumpang." << endl;
        return;
    }
    cout << "Daftar Penumpang: " << endl;
    while (P != NULL) {
        cout << "ID Penumpang: " << info(P).ID_pnp << endl;
        cout << "Nama: " << info(P).Nama << endl;
        cout << "Nomor Kursi: " << info(P).No_kursi << endl;
        cout << "Harga Tiket: " << info(P).Harga_Tiket << endl;
        cout << "----------------------------" << endl;
        P = next(P);
    }
}

void deletePenumpang(ListPenumpang &LPNP, adr_penumpangP P) {
    if (P == NULL) {
        cout << "Penumpang tidak ditemukan." << endl;
        return;
    }

    if (first(LPNP) == P) {
        first(LPNP) = next(P);
    } else {
        adr_penumpangP prev = first(LPNP);
        while (next(prev) != P) {
            prev = next(prev);
        }
        next(prev) = next(P);
    }
    next(P) = NULL;
    cout << "Penumpang berhasil dihapus." << endl;
}
