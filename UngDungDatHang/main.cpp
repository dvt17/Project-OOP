#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DanhGiaSP.h"
#include "SanPham.h"
#include "User.h"
#include "TroChoi.h"
#include "MucGioHang.h"
#include "GioHang.h"

using namespace std;
// vector<SanPham> ds;
extern vector <SanPham>  DocFile(const string tenFile = "SanPham.txt"){
    ifstream file(tenFile);
    SanPham sp;
    vector<SanPham> ds;
    while (file >> sp) {
        ds.push_back(sp);
    }
    file.close();
    return ds;
}
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

// int TinhTien(int n){


// }


int main() {
    // ifstream file("SanPham.txt");
    // vector<SanPham> ds;
    // SanPham sp;
    // while (file >> sp) {
    //     ds.push_back(sp);

    // }
 
    // file.close();

    vector<SanPham> ds = DocFile();
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
            "[3]. Gio hang\n"
            "========================\n";
            cout << s <<endl;
           
            bool ok2 = true;
            while(ok2){
                char chon; cin >>chon ;
                if(chon == '1'){
                    string dm;
                    cout <<"Chon danh muc san pham(ThucPham, ThucUong, CaNhan, GiaDung): ";
                    cin >> dm;
                    for(auto it : ds ){
                        if(dm == it.getDanhMuc()){
                            cout <<it.getMa()<<" "<<it.getTen()<<" "<<it.getGia()<<endl;
                        } 

                    }

                }
                else if(chon == '2' ){
                    string ten;
                    cin >> ten;
                    TroChoi c(ten);
                    c.CapNhatLuotChoi();
                    c.BatDau();
                    c.DoiThuong();
                }
                else if(chon == '3'){
                    // string tensp;
                    // cout <<"Nhap ten san pham muon mua: ";
                    // cin >>tensp;
                    
                    // int soluong;
                    // cout <<"Nhap so luong san pham: ";
                    // cin>> soluong;
                    
                    // m.nhapmuc();
                    // m.tinhTong(m.getTen());
                    // m.displayInfo();
                    // GioHang gh(m);

                    // gh.xemGioHang();

                }
                else if(chon == '4'){
                    mucTrongGioHang m;
                    
                    GioHang gh; 
                    cout << "=== CHUONG TRINH QUAN LY GIO HANG ===\n";

                    // Nhập sản phẩm vào giỏ
                    gh.nhap();

                    // Hiển thị thông tin giỏ hàng
                    gh.xuat();

                    // Xóa sản phẩm (tùy chọn)
                    char xoa;
                    cout << "\nBan co muon xoa san pham nao? (y/n): ";
                    cin >> xoa;
                    if (xoa == 'y' || xoa == 'Y') {
                        string tenXoa;
                        cout << "Nhap ten san pham muon xoa: ";
                        cin.ignore();
                        getline(cin, tenXoa);
                        gh.xoaMuc(tenXoa);
                        gh.xuat();
                    }
                }

            }
        }
        else {
            cout << "Thoat thanh cong";
            ok = false;
        }

    }

    return 0;
}