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
#include "DonHang.h"
#include "KhachHang.h"

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

bool dangNhap(){
    string tk, mk;
   
    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    // User u(tk, mk);
    if (User::dangNhap(tk, mk)) {
        cout << "Dang nhap thanh cong!\n";
       return true;
    }
    else {
        cout << "Sai tai khoan hoac mat khau!\n";
       return false;
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
    vector<MaGiam> ma;
    vector<SanPham> ds = DocFile();
    string s = "========= MENU =========\n"
        "[1]. Dang ky tai khoan\n"
        "[2]. Dang nhap\n"
        "[3]. Thoat\n"
        "========================\n";
    cout << s << endl;
    int c; bool ok;
    ok = true;
// //    string ten;
//     cin >> ten;
    TroChoi t;
    while (ok) {
        cout << "Nhap lua chon: ";
        cin >> c;
        if (c == 1) {
            dangKi();
        }
        else if (c == 2 && dangNhap() ) {
            
            string s = "========= MENU =========\n"
            "[1]. Danh muc san pham\n"
            "[2]. Game\n"
            "[3]. Mua hang\n"
            "[4]. Danh gia\n"
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
                    // string s;
                    // cout <<"Nhap ten nguoi choi: ";
                    // cin >>s;
                    // t(s);
                    t.CapNhatLuotChoi();
                    t.BatDau();
                    MaGiam m = t.DoiThuong();
                    ma.push_back(m);
                }
                else if(chon == '3'){
                    GioHang gh; 
                    cout << "=== CHUONG TRINH QUAN LY GIO HANG ===\n";

                    // Nhập sản phẩm vào giỏ
                    gh.nhap();

                    // Hiển thị thông tin giỏ hàng
                    gh.xuat();

                    // Xóa sản phẩm (tùy chọn)
                    char lc;
                    cout << "\nBan co muon xoa san pham nao? (y/n): ";
                    cin >> lc;
                    if (lc == 'y' || lc == 'Y') {
                        string tenXoa;
                        cout << "Nhap ten san pham muon xoa: ";
                        cin.ignore();
                        getline(cin, tenXoa);
                        gh.xoaMuc(tenXoa);
                        gh.xuat();
                    }
                    cout <<"Ban co muon toan bo san pham trong gio hang hay khong(y/n)? ";
                    cin >> lc;
                    lc = toupper(lc);
                    if(lc == 'Y'|| lc =='YES'){
                        float  gt;
                        DiaChi dc;
                        KhachHang kh;
                        cout <<"Nhap thong tin(HoTen, SoDienThoai, Email,DiaChi): ";
                        cin >> kh >> dc;
                    
                        cout << "==========Thong tin don hang==========" <<endl;
                        cout << kh << dc <<endl;
                        DonHang d(dc);
                        d.ngayUocTinh();
                        cout <<d;
                        cout <<"Tien ship: "<< d.tinhPhiShip() * gh.tongGioHang() << endl;
                        cout << "Tong gio hang: "<<gh.tongGioHang() <<endl;
                        cout <<"==========================================" <<endl;
                        double tt = gh.tongGioHang() + (d.tinhPhiShip() * gh.tongGioHang()) ;
                        if(ma.empty()){
                            cout << "Ban khong co ma giam gia nao!!!"<<endl;
                            cout << "Thanh toan: "<< tt<<endl;

                        }
                        else {
                            cout <<"Ban co muon ap ma giam gia khong(y/n)? ";
                            cin >>lc;
                            lc = toupper(lc);
                            if(lc == 'Y'|| lc =='YES'){
                                cout <<"Danh sach ma giam: " << endl;
                                for(auto x : ma){
                                    cout << x <<endl;
                                }
                                string s;
                                cout <<"Nhap ma can dung: ";
                                cin >> s;
                              
                                for(auto x: ma){
                                    if(s == x.getTM()&&x.HieuLuc()){
                                        gt = x.DungMa();
                                        cout << "Dung ma thanh cong" <<endl;
                                        break;
                                    }
                                    // else{
                                    //     cout <<"Ma khong the su dung" << endl;
                                    //     break;
                                        
                                    // } 
                                }
                            }

                           
                            cout << "Thanh toan: " << tt - tt*gt;
                        }
                       
                       
                        

                    }
                    else {
                        break;
                    }
                 


                }
                else if(chon == '4'){
                    
                    


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