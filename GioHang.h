#pragma once
#include <vector>
#include <iostream>
#include "MucGioHang.h"
#include "SanPham.h"   

class GioHang {
private:
    std::vector<MucGioHang> danhMuc;
    std::vector<MucGioHang>::iterator findItem(const SanPham& sanPham) {
        for (auto it = danhMuc.begin(); it != danhMuc.end(); ++it) {
            if (it->getSanPham().getmaSanPham() == sanPham.getmaSanPham()) {
                return it;
            }
        }
        return danhMuc.end();
    }
public:
    void addItem(const SanPham& sanPham, int quantity) {
        auto it = findItem(sanPham);
        if (it != danhMuc.end()) {
            int oldQuantity = it->getSoLuong();
            it->setSoLuong(oldQuantity + quantity);
            std::cout << "Cap nhat so luong cho " << sanPham.gettenSanPham() << std::endl;
        } else {
            danhMuc.push_back(MucGioHang(sanPham, quantity));
            std::cout << "Da them " << sanPham.getTenSP() << " vao gio hang" << std::endl;
        }
    }

    void removeItem(const SanPham& sanPham) {
        auto it = findItem(sanPham);
        if (it != danhMuc.end()) {
            danhMuc.erase(it);
            std::cout << "Da xoa " << sanPham.gettenSanPham() << " khoi gio hang" << std::endl;
        } else {
            std::cout << "Khong tim thay " << sanPham.gettenSanPham() << " trong gio" << std::endl;
        }
    }

    void updateQuantity(const SanPham& sanPham, int newQuantity) {
        auto it = findItem(sanPham);
        if (it != danhMuc.end()) {
            if (newQuantity > 0) {
                it->setSoLuong(newQuantity);
                std::cout << "Cap nhat so luong " << sanPham.gettenSanPham() << " thanh " << newQuantity << std::endl;
            } else {
                danhMuc.erase(it);
                std::cout << "So luong it hon bang 0, da xoa '" << sanPham.gettenSanPham() << " khoi gio hang" << std::endl;
            }
        } else {
            std::cout << "Khong tim thay " << sanPham.gettenSanPham() << " trong gio hang" << std::endl;
        }
    }

    double tinhTongTien() {
        double total = 0.0;
        for (const auto& muc : danhMuc) {
            total += muc.tinhThanhTien();
        }
        return total;
    }

    void hienThiGioHang() {
        std::cout << "\nGIO HANG CUA BAN\n";
        if (danhMuc.empty()) {
            std::cout << "Gio hang dang trong!\n" << std::endl;
            return;
        }

        std::cout << std::left
                  << std::setw(10) << "Ma San Pham"
                  << std::setw(20) << "Ten San Pham"
                  << std::setw(10) << "So Luong"
                  << std::setw(15) << "Gia San Pham"
                  << std::setw(15) << "Thanh Tien" << std::endl;

        for (const auto& muc : danhSachMuc) {
            muc.hienThi();
        }

        std::cout << std::right << std::setw(55) << "TONG CONG: "
                  << std::fixed << std::setprecision(0)
                  << tinhTongTien() << " VND" << std::endl;
    }

    void xoaTatCa() {
        danhMuc.clear();
        std::cout << "Da xoa toan bo gio hang." << std::endl;
    }

    bool kiemTraRong() const {
        return danhMuc.empty();
    }
};