#ifndef GERBONG_H_INCLUDED
#define GERBONG_H_INCLUDED

#include <iostream>
using namespace std;


struct gerbong {
    string Kode_Gerbong;
    int Kapasitas;
};

typedef gerbong infotype;
typedef struct elemengerbong *adr_gerbongP;

struct elemengerbong {
    infotype info;
    adr_gerbongP next;
    adr_gerbongP prev;
    ListPenumpang *penumpangList;  
};

struct ListGerbong {
    adr_gerbongP first;
};


void createListGerbong(ListGerbong &L);
adr_gerbongP createElemenGerbong(infotype X);
void InsertLastG(ListGerbong &L, adr_gerbongP P);
void ShowGerbong(ListGerbong L);
void DeleteFirstG(ListGerbong &L);
adr_gerbongP SearchG(ListGerbong L, string kode);


struct penumpang {
    string No_kursi;
    string Harga_Tiket;
    string Nama;
};

typedef penumpang infotypeP;
typedef struct elemenpenumpang *adr_penumpangP;

struct elemenpenumpang {
    infotypeP info;
    adr_penumpangP next;
};

struct ListPenumpang {
    adr_penumpangP first;
};

void createListPenumpang(ListPenumpang &L);
adr_penumpangP createElemenPenumpang(infotypeP X);
void InsertLastP(ListPenumpang &L, adr_penumpangP P);
void ShowAll(ListPenumpang L);
void DeleteFirstP(ListPenumpang &L);
adr_penumpangP SearchP(ListPenumpang L, string kursi);


int TotalPenumpang(ListPenumpang L);
int TotalPendapatan(ListPenumpang L);

#endif // GERBONG_H_INCLUDED
