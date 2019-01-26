#include "tubes.h"

address alokasi(customer c){
    address d = new elmlist;
    info(d) = c;
    next(d) = nil;
    return d;
}

address_c alokasi(tipe_cucian t){
    address_c d = new elmlist_c;
    info(d) = t;
    next(d) = nil;
    prev(d) = nil;
    return d;
}

address_hub alokasi(mergelist h){
    address_hub d = new elmlist_d;
    info(d) = h;
    next(d) = nil;
    return d;
}

customer createcust(){
    customer c;
    //cout<<endl;
    //cout<< "==================================================" << endl;
    //cout<< "               === List Customer ===              " << endl;
    //cout<<endl;
    cout << "ID Customer : ";
    cin >> c.id;
    cout << "Masukan Nama Customer : ";
    cin >> c.nama;
    cout << "Nomor Telepon: ";
    cin >> c.telp;
    cout << "Alamat : ";
    cin >> c.alamat;
    cout << "Berat cucian (gram) : ";
    cin >> c.beratcucian;
    return c;
}
tipe_cucian createtype(){
    tipe_cucian t;
    cout<<endl;
    cout << "== Input Jenis Cucian ===================================="<< endl;
    cout<<endl;
    cout << "Jenis barang yang akan di cuci : " << endl;
    cin >> t.jenis;
    cout << "Layanan yang diinginkan (kilat/regular) : " << endl;
    cin >> t.layanan;
    cout << "Berat barang max (gram) : " << endl;
    cin >> t.berat;
    if((t.layanan != "kilat") && (t.layanan != "regular")){
        cout << "Input anda salah .. " << endl;
    }

    //cout<<endl;
    //cout << "=========================================================="<< endl;
    //d = t.layanan;
    /*if((t.layanan != "kilat") || (t.layanan != "regular")){
        system("cls");
        d = "Input yang anda masukan salah .. ";
        cout<<d<<endl;
    }
    if(d != "Input yang anda masukan salah"){
        cout<< "Data Berhasil Diterima"<<endl;
    }*/
    return t;
}
mergelist createhub(list_d LC, list_c LD){
    mergelist m;
    address PC;
    address_c PT;
    cout << "--------" << endl;
    PC = findCust(LC);
    PT = findType(LD);
    if ((PC == nil) && (PT == nil)){
        cout << "Data tidak ditemukan" << endl;
        m.C = nil;
        m.D = nil;
    }
    else if ((PC != NULL) && (PT != NULL)) {
        m.C = PT;
        m.D = PC;
    }
    return m;
}

void cListD(list_d &l){
    first(l) = nil;
    last(l) = nil;
}
void cListC(list_c &l){
    first(l) = nil;
    last(l) = nil;
}
void cListH(list_h &l){
    first(l) = nil;
    last(l) = nil;
}

void i_customer(list_d &l, address p){
    if (first(l) == nil){
        first(l) = p;
        last(l) = p;
    }
    else{
        next(last(l)) = p;
        last(l) = p;
    }
}
void i_tipe(list_c &l, address_c p){
    if (first(l) == nil){
        last(l) = p;
    }
    else{
        next(p) = first(l);
        prev(first(l)) = p;
    }
    first(l) = p;
}
void hub(list_h &l, address_hub p){
    if (first(l) == nil){
        first(l) = p;
        last(l) = p;
        id(p) = 1;
    }
    else{
        next(last(l)) = p;
        id(p) = id(last(l)) + 1;
        last(l) = p;
    }
}

address findCust(list_d l){
    address D;
    bool x = false;
    string n;
    if(first(l) == nil){
        cout << "Belum ada customer" << endl;
        D = nil;
        return D;
    }
    else{
        cout << "ID Customer : " << endl;
        cin >> n;
        D = first(l);
        do{
            if (n == info(D).id){
                x = true;
            }
            else{
                D = next(D);
            }
        }while ((D != nil) && (x == false));
        if (x == true){
            cout << n << " Ditemukan" << endl;
        }
        else{
            cout << n << " Tidak ditemukan" << endl;
            D = nil;
        }
        return D;
    }
}
address_c findType(list_c l){
    address_c D, a;
    bool x = false;
    string n;
    if (first(l) == nil){
        cout << " Error Empty List .. " << endl;
        a = nil;
    }
    else{
        cout << "Jenis Cucian : " << endl;
        cin >> n;
        D = first(l);
        while ((D != nil) && (x == false)){
            if (n == info(D).jenis){
                x = true;
            }
            else{
                D = next(D);
            }
        }
        if (x == true){
            cout << n << " Data cucian ditemukan" << endl;
            a = D;
        }
        else{
            cout << n << " Tidak ada data cucian yang ditemukan" << endl;
            a = nil;
        }
    }
    return a;
}
address_hub findHub(list_h l, int n){
    address_hub X;
    address_hub p;
    if (first(l) == nil){
        cout << "Tidak ada customer yang mengambil cucian" << endl;
        p = nil;
    }
    //X = nil;
    //return X;
    else{
        X = first(l);
        while((X != nil) && (n != id(X))){
            X = next(X);
        }
        if (n == id(X)){
            p = X;
        }
        else{
            p = nil;
        }
    }
    return p;
}

void delfir_cust(list_d &l, address p){
    if(first(l) == nil){
        cout << "Error Empty List" << endl;
    }
    else{
        p = first(l);
        first(l) = next(p);
        next(p) = nil;
        delete p;
    }
}

void delast_cust(list_d &l, address p){
    address q;
    if(first(l) == nil){
        cout<< "Error Empty List"<< endl;
    }
    else if(first(l) != nil){
        q = first(l);
        while(next(q) != last(l)){
            q = next(q);
        }
        p = next(q);
        next(q) = nil;
        last(l) = q;
        delete p;
    }
}

void delaf_cust(list_d &l, address prec){
    address p;
    if(first(l) == nil){
        cout << "Error Empty List .. " << endl;
    }
    else if(first(l) != nil){
        if(next(first(l)) == nil){
            cout << "Tidak ada data .. " << endl;
        }
        else if(next(prec) == last(l)){
            p = last(l);
            next(prec) = nil;
            last(l) = prec;
            delete p;
        }
        else if(next(prec) != nil){
            p = next(prec);
            next(prec) = next(p);
            next(p) = nil;
            delete p;
        }
    }
}

void delfir_cuci(list_c &l, address_c p){
    if(first(l) == nil){
        cout << "Error Empty List .. " << endl;
    }
    else if (first(l) != nil){
        p = first(l);
        first(l) = next(p);
        next(p) = nil;
        prev(first(l)) = nil;
        delete p;
    }
}

void delast_cuci(list_c &l, address_c p){
    if(first(l) == nil){
        cout << "Error empty list .. " << endl;
    }
    else if (next(first(l)) == nil){
        p = first(l);
        first(l) = next(p);
        next(p) = nil;
        prev(next(p)) = nil;
        delete p;
    }
    else{
        p = last(l);
        last(l) = prev(p);
        prev(p) = nil;
        next(last(l)) = nil;
        delete p;
    }
}

void delaf_cuci(list_c &l, address_c prec){
    address_c p;
    if(first(l) == nil){
        cout << "Error Empty List .. " << endl;
    }
    else if(first(l) != nil){
        if(next(first(l)) == nil){
            cout << "Tidak ada data .. " << endl;
        }
        else if(next(prec) == last(l)){
            p = last(l);
            last(l) = prec;
            next(prec) = nil;
            next(p) = nil;
            prev(p) = nil;
            delete p;
        }
        else{
            p = next(prec);
            prev(next(p)) = prec;
            next(prec) = next(p);
            next(p) = nil;
            prev(p) = nil;
            delete p;
        }
    }
}

void delfir_hub(list_h &l, address_hub p){
    if(first(l) == nil){
        cout << "Error Empty List" << endl;
    }
    else{
        p = first(l);
        info(p).D = nil;
        info(p).C = nil;
        first(l) = next(p);
        next(p) = nil;
        delete p;
    }
}

void delast_hub(list_h &l, address_hub p){
    address_hub q;
    if(first(l) == nil){
        cout<< "Error Empty List"<< endl;
    }
    else if(first(l) != nil){
        q = first(l);
        while(next(q) != last(l)){
            q = next(q);
        }
        p = next(q);
        info(p).D = nil;
        info(p).C = nil;
        next(q) = nil;
        last(l) = q;
        delete p;
    }
}

void delaf_hub(list_h &l, address_hub prec){
    address_hub p;
    if(first(l) == nil){
        cout << "Error Empty List .. " << endl;
    }
    else if(first(l) != nil){
        if(next(first(l)) == nil){
            cout << "Tidak ada data .. " << endl;
        }
        else if(next(prec) == last(l)){
            p = last(l);
            info(p).D = nil;
            info(p).C = nil;
            next(prec) = nil;
            last(l) = prec;
            delete p;
        }
        else if(next(prec) != nil){
            p = next(prec);
            next(prec) = next(p);
            info(p).D = nil;
            info(p).C = nil;
            next(p) = nil;
            delete p;
        }
    }
}

void v_cust(list_d l){
    address P;
    P = first(l);
    cout<<endl;
    cout<<"--- List Customer ---"<<endl;
    //cout<<endl;
    if (first(l) == NULL) {
        cout<<"List Kosong...";
    }
    //else if (P == last(l)) {
      //  cout<<"- Info Customer -"<<endl;
      //  cout<<" Nama : "<<info(P).nama<<endl;
 //       cout<<" Alamat : "<<info(P).alamat<<endl;
   //     cout<<" Nomor Telepon : "<<info(P).telp<<endl;
    //}
    else {
        do {
            cout << endl;
            cout<<"== Info Customer ==============="<<endl;
            cout<<endl;
            cout<<" ID Customer : " <<info(P).id<<endl;
            cout<<" Nama Customer : "<<info(P).nama<<endl;
            cout<<" Alamat : "<<info(P).alamat<<endl;
            cout<<" Nomor Telepon : "<<info(P).telp<<endl;
            cout<<" Berat Cucian : "<<info(P).beratcucian<<endl;
            cout<< endl;
            cout<<"================================"<<endl;
            cout << endl;
            cout << endl;
            P = next(P);
        } while (P != NULL);
    }
}

void v_type(list_c l){
    address_c P;
    P = first(l);
    cout<<endl;
    cout << "=== List cucian ===" << endl;
    if (first(l) == nil){
        cout << endl;
        cout << "List Kosong....";
    }
    else{
        if (P == last(l)){
            cout<<endl;
            cout << "=== Info Cucian ==================" << endl;
            cout<<endl;
            cout << "Jenis barang yang dicuci : " << info(P).jenis<< endl;
            cout << "Berat Max : " << info(P).berat<< endl;
            cout << "Jenis layanan yang digunakan : " << info(P).layanan << endl;
            cout<<endl;
            cout << "==================================" << endl;
            cout<<endl;
        }
        else{
            do{
                cout << "=== Info Cucian ==================" << endl;
                cout<<endl;
                cout << "Jenis barang yang dicuci : " << info(P).jenis<< endl;
                cout << "Berat Max : " << info(P).berat<< endl;
                cout << "Jenis layanan yang digunakan : " << info(P).layanan << endl;
                cout<<endl;
                cout << "==================================" << endl;
                cout<<endl;
                P = next(P);
            }while (P != nil);
        }
    }
}
void v_hubcust(list_h l, address P){
    address_hub H;
    //address C;
    //address_c F;
    H = first(l);
    if (first(l) == nil){
        cout << endl;
        cout << "Maaf data tidak ada .. ";
    }
    else{
        cout<<endl;
        cout << "Cucian yang diambil oleh "<< info(P).id <<endl;
        do{
            if (info(H).D == P){
                //C = info(H).D;
                cout<<endl;
                cout << "No Pesanan : " << id(H) << endl;
                cout << "- "<<info(info(H).C).jenis <<endl;
            }
            H = next(H);
        }while (H != nil);
    }
}
void v_hubtype(list_h l, address_c P){
    address_hub H;
    //address C;
    //address_c F;
    H = first(l);
    if (first(l) == nil){
        cout << endl;
        cout << "Maaf data tidak ada .. ";
    }
    else{
        cout<<endl;
        cout << "Customer yang mengambil jenis cucian "<< info(P).jenis <<endl;
        do{
            if (info(H).C == P){
                //C = info(H).D;
                cout<<endl;
                cout << "No Pesanan : " << id(H) << endl;
                cout << "- "<<info(info(H).D).id << ", " << info(info(H).D).nama<<endl;
            }
            H = next(H);
        }while (H != nil);
    }
}
