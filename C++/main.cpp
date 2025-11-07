#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DanhGiaSP.h"
#include "SanPham.h"
#include "User.h"
using namespace std;

int main(){
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
    User u(tk, mk);
    while (ok) {
        cout << "Nhap lua chon: ";
        cin >> c;
       
        if (c == 1) {
            string tk, mk;
            cout << "Nhap tai khoan: ";
            cin >> tk;
            cout << "Nhap mat khau: ";
            cin >> mk;
            u.ghiFile();
            cout << "Dang ky thanh cong!\n";
        }else if(c == 2){
            string tk, mk;
            cout << "Nhap tai khoan: ";
            cin >> tk;
            cout << "Nhap mat khau: ";
            cin >> mk;
            if (u.dangNhap(tk, mk)) {
                cout << "Dang nhap thanh cong!\n";
            }
            else {
                cout << "Sai tai khoan hoac mat khau!\n";
            }
        }
        else {
            cout << "Thoat thanh cong";
            ok = false;
        }
    }
    return 0;
}