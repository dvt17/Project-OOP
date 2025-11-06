#pragma once
#include "DonHang.h"
#include <iostream>

class QuanLyDonHang {
private:
    #define MAX_ORDERS 2025
    DonHang danhSachDonHang[MAX_ORDERS];
    int soLuongHienTai;
public:
    QuanLyDonHang() {
        soLuongHienTai = 0;
    }
    void themDonHang(const DonHang& donHang) {
        if (soLuongHienTai < MAX_ORDERS) {
            danhSachDonHang[soLuongHienTai] = donHang;
            soLuongHienTai++; 
            std::cout << "Da luu don hang " << donHang.getMaDonHang() << " vao he thong" << std::endl;
        } else {
            std::cout << "He thong da day, khong the luu them don hang!" << std::endl;
        }
    }

    void hienThiTatCaDonHang() const {
        std::cout << "\n DANH SACH DON HANG DA DAT \n";
        if (soLuongHienTai == 0) {
            std::cout << "Chua co don hang nao trong he thong\n" << std::endl;
            return;
        }
        for (int i = 0; i < soLuongHienTai; i++) {
            danhSachDonHang[i].hienThiDonHang();
        }
    }
};