#include <iostream>
#include "tubes.h"

using namespace std;

void menu(list_d &LD, list_c &LC, list_h &LH);

void splashScreen();

void splashScreen(){
    system("cls");
    cout<<endl;
    cout<<"                                         =========================                                          "<<endl;
    cout<<"                                         | Aplikasi Jasa Laundry |                                          "<<endl;
    cout<<"                                         =========================                                          "<<endl;
    cout<<endl;
    cout<<"                                              Press Any Key ...                                              "<<endl;
    getch();
//    break;
}

int main(){
    list_c LC;
    list_d LD;
    list_h LH;
    cListC(LC);
    cListD(LD);
    cListH(LH);
    splashScreen();
    menu(LD, LC, LH);
}
void menu(list_d &LD, list_c &LC, list_h &LH){
    customer c;
    string d;
    tipe_cucian t;
    mergelist m;
    address prec;
    address_c prec1;
    address_hub prec2;
    address PC;
    address_c PT;
    address_hub PH;
    int x;
    do{
        system("cls");
        cout<< "== Menu ==================================================" << endl;
        cout<< "|                                                        |" << endl;
        cout<< "| 1. Input Customer                                      |" << endl;
        cout<< "| 2. Input Jenis Barang Cucian                           |" << endl;
        cout<< "| 3. Input Jenis Cucian yang akan Dipilih oleh Customer  |"<< endl;
        cout<< "| 4. View                                                |"<<endl;
        cout<< "| 5. Delete                                              |" << endl;
        cout<< "| 0. Exit                                                |" << endl;
        cout<< "|                                                        |" << endl;
        cout<< "==========================================================" << endl;
        cout<<endl;
        cout<< "Input menu : ";
        cin >> x;
        switch(x){
            case 1:
                system("cls");
                cout<< "=== Input Pemilik ==="<< endl;
                cout<<endl;
                //cout<<"=== Data Customer ============================="<<endl;
                cout<<endl;
                c = createcust();
                PC = alokasi(c);
                i_customer(LD, PC);
                cout << endl;
                cout << "Data Berhasil Disimpan " << endl;
                system("cls");
                cout << "Input Data Baru (Y/N)" << endl;
                cin >> d;
                while (d == "y"){
                    system("cls");
                    cout<< "=== Input Pemilik ==="<< endl;
                    cout<<endl;
                    cout<<endl;
                    c = createcust();
                    PC = alokasi(c);
                    i_customer(LD, PC);
                    cout << endl;
                    cout << "Data Berhasil Disimpan " << endl;
                    system("cls");
                    cout << "Input Data Baru (Y/N)" << endl;
                    cin >> d;
                }
                if(d == "n"){
                    //getch();
                    break;
                    //system("cls");
                    //cout<<"Maaf Inputan anda salah .. "<< endl;
                }
                //getch();
                //cout << endl;
               // break;


            case 2:
                system("cls");
                cout<< "=== Input Jenis Barang Cucian ===" << endl;
                t = createtype();
                PT = alokasi(t);
                i_tipe(LC, PT);
                cout << endl;
                //cout<< "Data Berhasil Disimpan " << endl;
                getch();
                break;
            case 3:
                system("cls");
                cout<< "=== Input Jenis Cucian yang Akan Dipilih Customer"<< endl;
                m = createhub(LD, LC);
                if ((m.D != nil) && (m.C != nil)){
                    //m = createhub(LD, LC);
                    PH = alokasi(m);
                    hub(LH, PH);
                    cout << endl;
                    cout << "Data Berhasil Disimpan ..." << endl;
                    //cout << m.C << endl;
                    //cout << m.D;
                }
                else{
                    cout<< "Data Tidak Berhasil Disimpan" << endl;
                }
                getch();
                break;
            case 4:
                do{
                    system("cls");
                    cout << "-- View --" << endl;
                    cout << endl;
                    cout << "====================================================================" << endl;
                    cout << "|                                                                  |"<<endl;
                    cout << "| 1. View Data Customer                                            |" << endl;
                    cout << "| 2. View Data Cucian                                              |" << endl;
                    cout << "| 3. View Data cucian yang diambil oleh customer                   |" << endl;
                    cout << "| 4. View Data Customer yang mengambil salah satu jenis cucian     |" << endl;
                    cout << "|                                                                  |" << endl;
                    cout << "====================================================================" << endl;
                    cout << endl;
                    cout << "Input menu : ";
                    cin >> x;
                    switch(x){
                        case 1:
                            system("cls");
                            cout<< "=== Data Customer === " << endl;
                            v_cust(LD);
                            getch();
                            break;
                        case 2:
                            system("cls");
                            cout<< "=== Data Barang Cucian ===" << endl;
                            cout << endl;
                            v_type(LC);
                            getch();
                            break;
                        case 3:
                            system("cls");
                            cout<< "=== Data Cucian yang telah diambil oleh customer ==="<< endl;
                            cout    <<endl;
                            PC = findCust(LD);
                            v_hubcust(LH, PC);
                            getch();
                            break;
                        case 4:
                            system("cls");
                            cout << "=== Data customer yang mengambil salah satu jenis cucian ===" << endl;
                            cout << endl;
                            PT = findType(LC);
                            v_hubtype(LH, PT);
                            getch();
                            break;
                        default:
                            break;
                    }
                }while(x != 0);
            /*case 5:
                system("cls");
                cout<< "=== Data Barang Cucian ===" << endl;
                cout << endl;
                v_type(LC);
                getch();
                break;
            case 6:
                system("cls");
                cout<< "View Cucian yang telah diambil oleh customer"<< endl;
                cout<<endl;
                PC = findCust(LD);
                v_hubcust(LH, PC);
                getch();
                break;*/
            case 5:
                do{
                    system("cls");
                    cout<< "-- Delete --"<< endl;
                    cout << "====================================================" << endl;
                    cout << "| 1. Delete Customer                               |" << endl;
                    cout << "| 2. Delete Jenis Cucian                           |" << endl;
                    cout << "| 3. Delete cucian yang diambil oleh customer      |" << endl;
                    cout << "| 0. Main Menu                                     |" << endl;
                    cout << "====================================================" << endl;
                    cout << "Pilih Menu : ";
                    cin >> x;
                    switch(x){
                        case 1:
                            PC = findCust(LD);
                            if(PC == first(LD)){
                                delfir_cust(LD, PC);
                            }
                            else if(PC == last(LD)){
                                delast_cust(LD, PC);
                            }
                            else{
                                prec = first(LD);
                                while (next(prec) != PC){
                                    prec = next(prec);
                                }
                                delaf_cust(LD, prec);
                            }
                            getch();
                            break;
                        case 2:
                            PT = findType(LC);
                            if(PT == first(LC)){
                                delfir_cuci(LC, PT);
                            }
                            else if(PT == last(LC)){
                                delast_cuci(LC, PT);
                            }
                            else{
                                prec1 = first(LC);
                                while (next(prec1) != PT){
                                    prec1 = next(prec1);
                                }
                                delaf_cuci(LC, prec1);
                            }
                            getch();
                            break;
                        case 3:
                            int x;
                            cout << "Nomor Pesanan : ";
                            cin >> x;
                            PH = findHub(LH, x);
                            if(PH == nil){
                                cout<<endl;
                                cout << "Data tidak ditemukan .. ";
                            }
                            else if(PH != nil){
                                if(PH == first(LH)){
                                    delfir_hub(LH, PH);
                                }
                                else if(PH ==  last(LH)){
                                    delast_hub(LH, PH);
                                }
                                else{
                                    prec2 = first(LH);
                                    while (next(prec2) != PH){
                                        prec2 = next(prec2);
                                    }
                                    delaf_hub(LH, prec2);
                                }
                            }
                            getch();
                            break;
                        default:
                            break;
                    }
                }while(x != 0);
            default:
                break;
        }
    }while (x != 0);
}
