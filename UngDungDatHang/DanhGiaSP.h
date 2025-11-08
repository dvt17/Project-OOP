// #pragma once
// #include <iostream>
// #include "KhachHang.h"
// #include "SanPham.h"
// using namespace std;

// class DanhGia : public KhachHang, public  SanPham{
// private:
//     string  MaDanhGia;
//     float Diem;
//     string BinhLuan;
//     int DanhGiaTichCuc;
//     int DanhGiaTieuCuc;
// public:
//     DanhGia(string maKH = "", string tenKH, string dt, string e, string tenSP, string dm, double g, double t, string maSP = "", string MaDG = "", string binhluan = "")
//         : KhachHang(maKH,tenSP,dt,e),SanPham(maSP,tenSP,dm,g,t), BinhLuan(binhluan), MaDanhGia(MaDG) {}
//     float getDiem() const {
//         return Diem;
//     }
//     string getBinhLuan() const {
//         return BinhLuan;
//     }
//     void setDiem(float d) {
//         if(d > 0) Diem = d;
//         else Diem = 1;   
//     }
//     void setBinhLuan(string b){
//         BinhLuan = b;
//     }

//     void TichCuc(){
//         if(Diem >= 2.5 )
//             DanhGiaTichCuc++;
//     }
//     void TieuCuc(){
//         if(Diem < 2.5)
//             DanhGiaTieuCuc++;
//     }

//     void displayy() {
//         cout << "Đánh giá #" << MaDanhGia << " -Mã sản phẩm " << SanPham::getMa()<< endl;
//         cout << "Người dùng: " <<KhachHang::getMa() << " | Điểm: " << Diem << "/5 sao\n";
//         cout << "Bình luận: " << BinhLuan << endl;
//         // cout << "Ngày: " << reviewDate << " | Thích: " << likes
//         //      << " | Không thích: " << dislikes << endl;

//     }
// };

#pragma once
#include <iostream>
#include <string>
using namespace std;

class DanhGia {
private:
    string maDanhGia;
    string maKhachHang;
    string maSanPham;   
    float diem; 
    string binhLuan;   
public:
    DanhGia(string maDG = "", string maKH = "", string maSP = "", float d = 0, string bl = "")
        : maDanhGia(maDG), maKhachHang(maKH), maSanPham(maSP), diem(d), binhLuan(bl) {}

    string getMaDanhGia() const { return maDanhGia; }
    string getMaKhachHang() const { return maKhachHang; }
    string getMaSanPham() const { return maSanPham; }
    float getDiem() const { return diem; }
    string getBinhLuan() const { return binhLuan; }

    void setDiem(float d) {
        if(d >= 1 && d <= 5) diem = d;
        else diem = 1;   
    }
    void setBinhLuan(string b){
        binhLuan = b;
    }

    void display() const {
        cout << "\n Danh Gia " << maDanhGia << endl;
        cout << "Nguoi dung (Ma KH): " << maKhachHang << endl;
        cout << "San pham (Ma SP): " << maSanPham << endl;
        cout << "Diem: " << diem << "/5 sao" << endl;
        cout << "Binh luan: " << binhLuan << endl;
    }
};