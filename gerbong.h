#ifndef GERBONG_H_INCLUDED
#define GERBONG_H_INCLUDED


#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last
#define parent(P) (P)->parent


#include <string>
using namespace std;

struct infotype {
    string Kode_Gerbong;
    int Kapasitas;
    int Jumlah_Penumpang;
};

struct infotypeP {
    string ID_pnp;
    string Nama;
    int No_kursi;
    int Harga_Tiket;
};

typedef struct elmlistgerbong *adr_gerbongP;
typedef struct elmlistpenumpang *adr_penumpangP;

struct elmlistgerbong {
    infotype info;
    adr_gerbongP next;
};

struct elmlistpenumpang {
    infotypeP info;
    adr_penumpangP next;
    adr_penumpangP prev;
    adr_gerbongP parent;
};

struct ListGerbong {
    adr_gerbongP first;
};

struct ListPenumpang {
    adr_penumpangP first;
    adr_penumpangP last;
};

void createListGerbong(ListGerbong &L);
adr_gerbongP createElemenGerbong(infotype X);
void InsertLastG(ListGerbong &L, adr_gerbongP P);
void ShowGerbong(ListGerbong L);
adr_gerbongP SearchG(ListGerbong L, string kode);
void DeleteParentAndChild(ListGerbong &L, ListPenumpang &LPNP, string kodeGerbong);
void UpdateGerbong(ListGerbong &L, string kodeGerbong);


void createListPenumpang(ListPenumpang &LPNP);
adr_penumpangP createElemenPenumpang(infotypeP X);
void InsertLastP(ListPenumpang &LPNP, adr_penumpangP P);
void ShowPenumpang(ListPenumpang LPNP, adr_gerbongP G);
adr_penumpangP SearchP(ListPenumpang LPNP, string ID);
void UpdatePenumpang(ListPenumpang &LPNP, string IDPenumpang);
void DeleteChildInParent(ListPenumpang &LPNP, string IDPenumpang, adr_gerbongP G);
int CountChildInParent(ListPenumpang LPNP, adr_gerbongP G);
void DeleteAfterP(ListPenumpang &LPNP, adr_penumpangP Prec);
void connect(ListGerbong &G, adr_penumpangP &C);
void disconnect(adr_penumpangP &C);
void deletePenumpang(ListPenumpang &LPNP, adr_penumpangP P);

int menuutama();
void showP(ListPenumpang LPNP);

#endif // GERBONG_H_INCLUDED
