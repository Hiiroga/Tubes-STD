#ifndef GERBONG_H_INCLUDED
#define GERBONG_H_INCLUDED

#include <iostream>
using namespace std;
#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) L.first


struct gerbong {
    string Kode_Gerbong;
    int Kapasitas;
};

typedef gerbong infotype;
typedef struct elemengerbong *adr_gerbongP;



struct elemengerbong {
    infotype info;
    adr_gerbongP next;
} ;

struct ListGerbong {
    adr_gerbongP first;
};

void createListGerbong_103012330085(ListGerbong &L);
adr_gerbongP createElemenGerbong_103012330085(infotype X);
void InsertLastG_103012330085(ListGerbong &L, adr_gerbongP P);
void ShowGerbong_103012330085(ListGerbong L);
void DeleteFirstG_103012330085(ListGerbong &L, adr_gerbongP P);
adr_gerbongP SearchG_103012330085(ListGerbong L, string dari, string ke, string tanggal);


struct penumpang {
    string No_kursi;
    string Harga_Tiket;
    string Nama;
};

typedef penumpang infotype;
typedef struct elemenpenumpang *adr_penumpangP;



struct elemenpenumpang {
    infotype info;
    adr_penumpangP next;
} ;

struct ListPenumpang {
    adr_penumpangP first;
};

void createListPenumpang_103012330085(ListPenumpang &L);
adr_penumpangP createElemenPenumpang_103012330085(infotype X);
void InsertLastP_103012330085(ListPenumpang &L, adr_gerbongP P);
void ShowAll_103012330085(ListPenumpang L);
void DeleteFirstP_103012330085(ListPenumpang &L, adr_gerbongP P);
adr_penumpangP SearchP_103012330085(ListPenumpang L, string dari, string ke, string tanggal);



#endif // GERBONG_H_INCLUDED
