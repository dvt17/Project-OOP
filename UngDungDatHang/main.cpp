#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DanhGiaSP.h"
#include "SanPham.h"
#include "User.h"
#include "TroChoi.h"
using namespace std;

void dangKi(){
    string tk, mk;
    
    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    User u(tk, mk);
    u.ghiFile();
    cout << "Dang ky thanh cong!\n";
}

void dangNhap(){
    string tk, mk;
   
    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    User u(tk, mk);
    if (u.dangNhap(tk, mk)) {
        cout << "Dang nhap thanh cong!\n";
    }
    else {
        cout << "Sai tai khoan hoac mat khau!\n";
    }
}


int main() {
    ifstream file("SanPham.txt");
    vector<SanPham> ds;
    SanPham sp;
    while (file >> sp) {
        ds.push_back(sp);

    }
    string s = "========= MENU =========\n"
        "[1]. Dang ky tai khoan\n"
        "[2]. Dang nhap\n"
        "[3]. Thoat\n"
        "========================\n";
    cout << s << endl;
    int c; bool ok;
    ok = true;
   
    while (ok) {
        cout << "Nhap lua chon: ";
        cin >> c;
        if (c == 1) {
            dangKi();
        }
        else if (c == 2) {
            dangNhap();
            string s = "========= MENU =========\n"
            "[1]. Danh muc san pham\n"
            "[2]. Game\n"
            "[3]. \n"
            "========================\n";
            cout << s <<endl;
            char chon; cin >>chon ;
            if(chon == '1'){
                string dm;
                cout <<"Chon danh muc san pham(ThucPham, ThucUong, CaNhan, GiaDung): ";
                cin >> dm;
                for(auto it : ds ){
                    if(dm == it.getDanhMuc()){
                        cout << it.getTen()<<" "<<it.getGia()<<endl;
                    
                    } 
                }

            }
            else if(chon == '2' ){
                string ten;
                cin >> ten;
                TroChoi c(ten);
                c.BatDau();
            }
        
            
        }
        else {
            cout << "Thoat thanh cong";
            ok = false;
        }

    }

    return 0;
}