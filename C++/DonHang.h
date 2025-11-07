#pragma once
#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include "MucGioHang.h"
#include "SanPham.h"
using namespace std;
class DonHang {
    private:
        string maDon;
        tm ngayDatHang ;
        tm duTinhNgayGiaoHang;
        vector <mucTrongGioHang> donHang;
        double phiShip;
        double tongDonHang;
        string trangThai;
    public:
        DonHang (string id, tm od, tm estimate, vector<CartItem> item, double fee, double sum)
        : maDon(id), ngayDatHang(od), duTinhNgayGiaoHang(estimate), donHang(item), phiShip(fee),
        tongDonHang(sum), trangThai("Cho xac nhan"){
            tinhNgayGiaoHang();
        } 
        double tinhPhiShip()// cho phi giao hang = 10% tong don hang
        {
           phiShip =  0.1 *  tongDonHang;
           return phiShip;
        }
        double tinhTongDonHang(){
            tongDonHang = 0;
            for (mucTrongGioHang& item : donHang){
                tongDonHang += item.tinhTong();
            }
            tongDonHang += phiShip;
            return tongDonHang;
        };
        void xacNhanDatHang(){
            trangThai = "Dang giao";
            for (mucTrongGioHang& item : donHang){
                SanPham product = item;
                double newQuantity = product.getSoLuongTon() - item.getQuantity();
                product.updateSoLuongTon(newQuantity);
            }
        };
         void calculateEstimatedDeliveryDate(){
            duTinhNgayGiaoHang.tm_mday = ngayDatHang.tm_mday + 3;
            mktime(&duTinhNgayGiaoHang);
        };
         void hoanThanhDatHang(){
            if (trangThai == "Dang giao" && duTinhNgayGiaoHang.tm_mday == ngayDatHang.tm_mday + 3){
                trangThai = "Da giao don hang thanh cong";
            }
        };
        string getTrangThai() {return trangThai;};
        void displayOrderDetails(){
            cout << "Ma don hang: " << maDon;
            cout << "Ngay dat hang: " << asctime(&ngayDatHang);
            cout << "Trang thai don hang: " << trangThai <<endl;
            cout << "Thong tin ve san pham trong don hang:" << endl;
            for (mucTrongGioHang& item : donHang){
                item.displayInfo();
            }
            cout << "Tong so tien cua don hang: " << tongDonHang << endl;
        };


};
