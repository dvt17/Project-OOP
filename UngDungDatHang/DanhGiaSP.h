#pragma once
#include <iostream>
#include "KhachHang.h"
#include "SanPham.h"
using namespace std;

class DanhGia : public KhachHang, public  SanPham{
private:
    string  MaDanhGia;
    float Diem;
    string BinhLuan;
    int DanhGiaTichCuc;
    int DanhGiaTieuCuc;
public:
    DanhGia(string maKH = " ", string maSP = " ", string MaDG = " ", string binhluan = " ")
        : MaDanhGia(MaDG), SanPham(maSP), BinhLuan(binhluan){

    }
    float getDiem() const {
        return Diem;
    }
    string getBinhLuan() const {
        return BinhLuan;
    }
    void setDiem(float d) {
        if(d > 0) Diem = d;
        else Diem = 1;   
    }
    void setBinhLuan(string b){
        BinhLuan = b;
    }

    // void TichCuc(){
    //     if(Diem >= 2.5 )
    //         DanhGiaTichCuc++;
    // }
    // void TieuCuc(){
    //     if(Diem < 2.5)
    //         DanhGiaTieuCuc++;
    // }

    void displayy() {
        cout << "Đánh giá #" << MaDanhGia << " -Mã sản phẩm " << SanPham::getMa()<< endl;
        cout << "Người dùng: " <<KhachHang::getMa() << " | Điểm: " << Diem << "/5 sao\n";
        cout << "Bình luận: " << BinhLuan << endl;
        // cout << "Ngày: " << reviewDate << " | Thích: " << likes
        //      << " | Không thích: " << dislikes << endl;

    }
};
