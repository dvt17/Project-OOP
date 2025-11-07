#pragma once 
#include <iostream>
#include <string>
#include "SanPham.h"
using namespace std;
class mucTrongGioHang: public SanPham {
    friend class DonHang;
    private: 
        int soLuong;
    public:
        mucTrongGioHang (string ma, string ten, string dm, double g, double t, int quan = 0) : SanPham(ma, ten, dm, g, t), soLuong(quan){}
        friend istream& operator>> (istream& in, mucTrongGioHang& c);
        friend ostream& operator<< (istream& out, mucTrongGioHang& c);
        int getSoLuong() const { return soLuong;}
        void setSoLuong(int qty) { soLuong = qty;}
        double tinhTong(){return getGia() * soLuong;}
        void displayInfo(){
            cout << "Ten san pham: " << getTen() << endl;
            cout << "So luong san pham: " << soLuong << endl;
            cout << "Thanh tien: " << tinhTong << endl;
        }
        ~mucTrongGioHang();
        
};
