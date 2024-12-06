#ifndef GERBONG_H_INCLUDED
#define GERBONG_H_INCLUDED

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) L.first
#define last(L) L.last
#define parent(P) P->parent

#include <iostream>
using namespace std;


struct gerbong {
    string Kode_Gerbong;
    int Kapasitas;
    int Jumlah_Penumpang; //new
};

typedef gerbong infotype;
typedef struct elemengerbong *adr_gerbongP;

struct elemengerbong {
    infotype info;
    adr_gerbongP next;
};

struct ListGerbong {
    adr_gerbongP first;
};


void createListGerbong(ListGerbong &L);
adr_gerbongP createElemenGerbong(infotype X);
void InsertLastG(ListGerbong &L, adr_gerbongP P);
void ShowGerbong(ListGerbong L);
void DeleteFirstG(ListGerbong &L, adr_gerbongP P);
adr_gerbongP SearchG(ListGerbong L, string kode);


struct penumpang {
    string ID_pnp;
    string No_kursi;
    string Harga_Tiket;
    string Nama;
};

typedef penumpang infotypeP;
typedef struct elemenpenumpang *adr_penumpangP;

struct elemenpenumpang {
    infotypeP info;
    adr_penumpangP next;
    adr_penumpangP prev;
    adr_gerbongP parent;
};

struct ListPenumpang {
    adr_penumpangP first;
    adr_penumpangP last;
};

void createListPenumpang(ListPenumpang &L);
adr_penumpangP createElemenPenumpang(infotypeP X);
void InsertLastP(ListPenumpang &L, adr_penumpangP P);
void ShowPenumpang(ListPenumpang L, adr_gerbongP G);
void DeleteFirstP(ListPenumpang &L, adr_penumpangP P);
adr_penumpangP SearchP(ListPenumpang L, string ID);

void connect(ListGerbong G, adr_penumpangP &C);
void disconnect(adr_penumpangP &C);
int TotalPenumpang(ListPenumpang L);
int TotalPendapatan(ListPenumpang L);
int menuutama();
void showP(ListPenumpang L);

#endif // GERBONG_H_INCLUDED
