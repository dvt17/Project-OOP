#pragma once
#include <iostream>
#include <iomanip>
#include "MucGioHang.h"
#include <map>
#include "SanPham.h"
#include <vector>
using namespace std;
class GioHang
{
protected:
    vector<mucTrongGioHang> dsMuc;

public:
    GioHang() {}

    void nhap()
    {
        int n = 1;
        string x;

        while (true)
        {

            cout << "\nSan pham thu " << n << ":\n";
            mucTrongGioHang item;
            item.nhapmuc();
            dsMuc.push_back(item);
            n++;
            cout << "Ban co muon tiep tuc mua them san pham khong(y/n)? ";
            cin >> x;
            for (int i = 0; i < x.size(); i++)
            {
                x[i] = toupper(x[i]);
            }
            if (x == "N" || x == "NO")
            {
                break;
            }
            else
            {
                continue;
            }
        }
    }
    void xuat() const
    {
        cout << "\n=== DANH SACH SAN PHAM TRONG GIO ===\n";

        for (auto it : dsMuc)
        {

            it.displayInfo();
        }

        cout << "Tong tien: " << tongGioHang() << endl;
    }

    int tongGioHang() const
    {
        int tong = 0;
        for (auto it : dsMuc)
        {

            tong += it.tinhTong(it.getTen());
        }

        return tong;
    }

    void xoaMuc(const string &ten)
    {
        for (auto it = dsMuc.begin(); it != dsMuc.end(); ++it)
        {
            if (it->getTen() == ten)
            {
                dsMuc.erase(it);
                cout << " Da xoa san pham " << ten << endl;
                return;
            }
        }
        cout << "Khong tim thay san pham!\n";
    }
    vector<mucTrongGioHang> getMuc() {
        return dsMuc;
    }
};