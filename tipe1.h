#ifndef GERBONG_H_INCLUDED
#define GERBONG_H_INCLUDED

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) L.first
#define last(L) L.last
#define child(P) P->child

#include <iostream>
using namespace std;


struct gerbong {
    string Kode_Gerbong;
    int Kapasitas;
    int Jumlah_Penumpang;
};

struct penumpang {
    string ID_pnp;
    string No_kursi;
    string Harga_Tiket;
    string Nama;
};

typedef gerbong infotype;
typedef struct elemengerbong *adr_gerbongP;
typedef penumpang infotypeP;
typedef struct elemenpenumpang *adr_penumpangP;

struct ListGerbong {
    adr_gerbongP first;
    adr_gerbongP last;
};

struct ListPenumpang {
    adr_penumpangP first;
};

struct elemengerbong {
    infotype info;
    adr_gerbongP next;
    adr_gerbongP prev;
    ListPenumpang child;
};

struct elemenpenumpang {
    infotypeP info;
    adr_penumpangP next;
};


void createListGerbong(ListGerbong &L);
adr_gerbongP createElemenGerbong(infotype X);
void InsertLastG(ListGerbong &L, adr_gerbongP P);
void ShowGerbong(ListGerbong L);
void DeleteAfterG(ListGerbong &L,adr_gerbongP Prec, adr_gerbongP P);
adr_gerbongP SearchG(ListGerbong L, string kode);


void createListPenumpang(ListPenumpang &LPNP);
adr_penumpangP createElemenPenumpang(infotypeP X);
void InsertLastP(ListPenumpang &LPNP, adr_penumpangP P);
void ShowPenumpang(ListPenumpang LPNP);
void DeleteAfterP(ListPenumpang &LPNP,adr_penumpangP Prec, adr_penumpangP P);
adr_penumpangP SearchP(ListPenumpang LPNP, string ID);

void connect(ListGerbong G, infotypeP dataPNP);
int TotalPenumpang(ListPenumpang L);
int menuutama();
void showP(ListPenumpang L);



#endif // GERBONG_H_INCLUDED
