#pragma once
#include <iostream>
#include "MucGioHang.h"
#include "SanPham.h" 

class GioHang : public mucTrongGioHang {
private:
    int soLuongHienTai; 
    int timViTri(const SanPham& sanPham) {
        for (int i=0; i<soLuongHienTai; i++) {
            if (danhMuc[i].getSanPham().getMaSP() == sanPham.getMaSP()) {
                return i;
            }
        }
        return -1;
    }
public:
    GioHang() {
        soLuongHienTai= 0;
    }
    void addItem(const SanPham& sanPham, int quantity) {
        int viTri= timViTri(sanPham); 
        if (viTri != -1) {
            int soLuongCu = danhMuc[viTri].getSoLuong();
            danhMuc[viTri].setSoLuong(soLuongCu + quantity);
            std::cout << "Cap nhat so luong cho " << sanPham.getTenSP() << std::endl;
        } else {
            if (soLuongHienTai >= MAX_ITEMS) {
                std::cout << "Gio hang da day!" << std::endl;
                return;
            }
            danhMuc[soLuongHienTai] = MucGioHang(sanPham, quantity);
            soLuongHienTai++;
            std::cout << "Da them " << sanPham.getTenSP() << " vao gio hang" << std::endl;
        }
    }

    void removeItem(const SanPham& sanPham) {
        int viTri = timViTri(sanPham);
        if (viTri != -1) {
            for (int i=viTri; i<soLuongHienTai - 1; i++) {
                danhMuc[i] = danhMuc[i + 1];
            }
            soLuongHienTai--; 
            std::cout << "Da xoa " << sanPham.getTenSP() << " khoi gio hang" << std::endl;
        } else {
            std::cout << "Khong tim thay " << sanPham.getTenSP() << " trong gio hang" << std::endl;
        }
    }

    void updateQuantity(const SanPham& sanPham, int newQuantity) {
        int viTri = timViTri(sanPham);

        if (viTri != -1) {
            if (newQuantity > 0) {
                danhMuc[viTri].setSoLuong(newQuantity);
                std::cout << "Cap nhat so luong " << sanPham.getTenSP() << " thanh " << newQuantity << std::endl;
            } else {
                removeItem(sanPham);
            }
        } else {
            std::cout << "Khong tim thay " << sanPham.getTenSP() << " trong gio" << std::endl;
        }
    }

    double tinhTongTien() {
        double total = 0.0;
        for (int i=0; i<soLuongHienTai; i++) {
            total += danhMuc[i].tinhThanhTien();
        }
        return total;
    }

    void hienThiGioHang() {
        std::cout << "\n GIO HANG CUA BAN \n";
        if (soLuongHienTai == 0) {
            std::cout << "Gio hang dang trong!\n" << std::endl;
            return;
        }

        std::cout << std::left
                  << std::setw(10) << "Ma SP"
                  << std::setw(20) << "Ten San Pham"
                  << std::setw(10) << "So Luong"
                  << std::setw(15) << "Don Gia"
                  << std::setw(15) << "Thanh Tien" << std::endl;
        for (int i = 0; i < soLuongHienTai; i++) {
            danhMuc[i].hienThi();
        }

        std::cout << std::right << std::setw(55) << "\n TONG CONG: "
                  << std::fixed << std::setprecision(0)
                  << tinhTongTien() << " VND\n" << std::endl;
    }

    void xoaTatCa() {
        soLuongHienTai = 0;
        std::cout << "> Da xoa toan bo gio hang." << std::endl;
    }

    bool kiemTraRong() const {
        return (soLuongHienTai == 0);
    }
};