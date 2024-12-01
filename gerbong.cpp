#include "gerbong.h"

void createListGerbong(ListGerbong &L) {
    first(L) = NULL;
}

adr_gerbongP createElemenGerbong(infotype X) {
    adr_gerbongP P = new elemengerbong;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    P->penumpangList = new ListPenumpang;
    createListPenumpang(*P->penumpangList);  
    return P;
}

void InsertLastG(ListGerbong &L, adr_gerbongP P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_gerbongP temp = first(L);
        while (next(J) != NULL) {
            J = next(J);
        }
        next(J) = P;
        prev(P) = J;
    }
}

void ShowGerbong(ListGerbong L) {
    adr_gerbongP P = first(L);
    while (P != NULL) {
        cout << "Kode Gerbong: " << info(P).Kode_Gerbong << endl;
        cout << "Kapasitas: " << info(P).Kapasitas << endl;
        cout << "Jumlah Penumpang: " << info(P).Kapasitas << endl; //new
        ShowAll(*P->penumpangList);  
        P = next(P);
    }
}

