#pragma once
#include <string>
#include <ctime>
#include <vector>
#include <iostream>
#include "GioHang.h"
#include "SanPham.h"
#include "DiaChi.h"
#include "TroChoi.h"
using namespace std;
class DonHang: public GioHang{
    private:
        // int maDon;
        tm ngayDatHang ;
        time_t od;
        tm duTinhNgayGiaoHang;
        //vector <mucTrongGioHang> donHang;
        DiaChi diaChi;
        double phiShip;
        double tongDonHang;
        string trangThai;
    public:
        //DonHang(){}
        DonHang (DiaChi d)
       {
            // tinhNgayGiaoHang();
            od = time(0);
            localtime_s (&ngayDatHang, &od);
            diaChi = d;
        } 
        friend ostream& operator<<(ostream& out, const DonHang &d){
           
            out <<"Ngay bat dau: "<< d.ngayDatHang.tm_mday <<'/'<<d.ngayDatHang.tm_mon + 1 <<'/'<<d.ngayDatHang.tm_year + 1900<<endl;
            out <<"Ngay du kien: " << d.duTinhNgayGiaoHang.tm_mday <<'/'<<d.duTinhNgayGiaoHang.tm_mon + 1 <<'/'<<d.duTinhNgayGiaoHang.tm_year +1900<<endl;
            return out;
        }
        void ngayUocTinh(){
            if(diaChi.getTP() == "HOCHIMINH"){ 
                time_t tg = od + 48 * 3600;
                localtime_s (&duTinhNgayGiaoHang,&tg);
            }
           else {
                time_t tg = od +96 * 3600;
                localtime_s (&duTinhNgayGiaoHang,&tg);
            }
        }
        double tinhPhiShip()// cho phi giao hang = 10% tong don hang
        {

            if(diaChi.getTP() == "HOCHIMINH"){
                phiShip = 0;
            }
           else {
                phiShip =  0.1 ;
            }
           return phiShip;
        }

        tm getNgayDH()const {
            return ngayDatHang;
        }
        tm getNgayDT() const {
            return duTinhNgayGiaoHang;
        }
       /* double tinhTongDonHang(){
            tongDonHang = 0;
            for (mucTrongGioHang& item : dsMuc){
                tongDonHang += item.tinhTong(item.getTen());
            }
            char x;
            cout <<"Ban co muon ap ma giam gia hay khong?(y/n) ";
            cin >>x;
            x = toupper(x);
            if(x == 'Y'|| x == 'YES' ){

                cout << "Ma FreeShip an [F] hay Ma Giam Gia an [G]?  ";
                cin >>x;
                x = toupper(x);
                if(x == 'F'){
                   
                }
                tongDonHang ;


            }
            tongDonHang += phiShip;
            
            return tongDonHang;
        };
        void xacNhanDatHang(){
            trangThai = "Dang giao";
            for (mucTrongGioHang& item : donHang){
                SanPham product = item;
                double newQuantity = product.getSoLuongTon() - item.getSoLuong();
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
            // cout << "Ma don hang: " << maDon;
            cout << "Ngay dat hang: " << asctime(&ngayDatHang);
            cout << "Trang thai don hang: " << trangThai <<endl;
            cout << "Thong tin ve san pham trong don hang:" << endl;
            for (mucTrongGioHang& item : donHang){
                item.displayInfo();
            }
            cout << "Tong so tien cua don hang: " << tongDonHang << endl;
        };

*/
};
