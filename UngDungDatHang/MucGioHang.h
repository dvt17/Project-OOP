#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "SanPham.h"
using namespace std;

class mucTrongGioHang : public SanPham
{
private:
    int soLuong;
    vector<SanPham> s;

public:
    mucTrongGioHang(){}
    mucTrongGioHang(string ma , string ten, int quan)
        : SanPham(ma, ten), soLuong(quan) {}

    mucTrongGioHang nhapmuc()
    {

        ifstream file("SanPham.txt");
        SanPham sp;
        while (file >> sp)
        {
            s.push_back(sp);
        }
        file.close();

        cout << "Nhap ten san pham muon mua: ";
        cin >> tenSanPham;
        for (int i = 0; i < tenSanPham.size(); i++)
        {
            tenSanPham[i] = toupper(tenSanPham[i]);
        }
        cout << "Nhap so luong san pham: ";
        cin >> soLuong;
        mucTrongGioHang c("", tenSanPham, soLuong);
        return c;
    }

    int getSoLuong() const { return soLuong; }
    void setSoLuong(int qty) { soLuong = qty; }
    vector<SanPham> getSanPham() const
    {
        return s;
    }

    int tinhTong(string ten) const
    {

        for (auto x : s)
        {

            if (x.getTen() == ten)
            {
                return x.getGia() * soLuong;
            }
        }
        return 0;
    }

    void displayInfo() const
    {
        cout << "Ten san pham: " << tenSanPham << endl;
        cout << "So luong san pham: " << soLuong << endl;
        cout << "Thanh tien: " << tinhTong(tenSanPham) << endl;
    }

    ~mucTrongGioHang() {}
};
