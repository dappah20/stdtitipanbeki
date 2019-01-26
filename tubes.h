#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
//#include <>

#define nil NULL
#define info(P) (P)->info
#define id(P) (P)->id
#define next(P) (P)->next
#define first(l) ((l).first)
#define last(l) ((l).last)
#define prev(p) (p)->prev

using namespace std;

struct customer {
    string id;
    string nama;
    string alamat;
    string telp;
    int beratcucian;
};


typedef customer infotype;
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address next;
};
struct list_d {
    address first;
    address last;
};

struct tipe_cucian{
    int berat;
    string jenis;
    string layanan;
    //string harga;
};

typedef tipe_cucian infotype_c;
typedef struct elmlist_c *address_c;
struct elmlist_c{
    infotype_c info;
    address_c next;
    address_c prev;
};
struct list_c{
    address_c first;
    address_c last;
};

struct mergelist{
    address_c C;
    address D;
};
typedef struct elmlist_d *address_hub;
struct elmlist_d{
    mergelist info;
    int id;
    address_hub next;
    //address_hub next;
};
struct list_h{
    address_hub first;
    address_hub last;
};

void cListD(list_d &l);
void cListC(list_c &l);
void cListH(list_h &l);

address alokasi(customer c);
address_c alokasi(tipe_cucian t);
address_hub alokasi(mergelist m);

customer createcust();
tipe_cucian createtype();
mergelist createhub(list_d LD, list_c LC);

void i_customer(list_d &l, address p);
void i_tipe(list_c &l, address_c p);
void hub(list_h &l, address_hub p);

address findCust(list_d l);
address_c findType(list_c l);
address_hub findHub(list_h l, int n);

void delfir_cust(list_d &l, address p);
void delaf_cust(list_d &l, address prec);
void delast_cust(list_d &l, address p);

void delfir_cuci(list_c &l, address_c p);
void delaf_cuci(list_c &l, address_c prec);
void delast_cuci(list_c &l, address_c p);

void delfir_hub(list_h &l, address_hub p);
void delaf_hub(list_h &l, address_hub prec);
void delast_hub(list_h &l, address_hub p);

void v_cust(list_d l);
void v_type(list_c l);
void v_hubcust(list_h l, address P);
void v_hubtype(list_h l, address_c P);

void del_cust(list_d l, address p);


#endif // TUBES_H_INCLUDED
