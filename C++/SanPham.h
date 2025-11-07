#pragma once
#include<iostream>
#include<string>
using namespace std;
class SanPham
{
private:
	string maSanPham, tenSanPham, danhMuc;
	double gia, soLuongTon;
public:
	SanPham(string ma, string ten, string dm, double g, double t) : maSanPham(ma), tenSanPham(ten), danhMuc(dm), gia(g), soLuongTon(t){}
	friend istream& operator >>(istream& in, SanPham x) {
		in >> x.maSanPham >> x.tenSanPham >> x.danhMuc >> x.gia >> x.soLuongTon;
		return in;
	}
	friend ostream& operator <<(ostream& out, const SanPham& x) {
		out << "Ma San Pham: " << x.maSanPham << endl;
		out << "Ten San Pham: " << x.tenSanPham << endl;
		out << "Danh Muc: " << x.danhMuc << endl;
		out << "Gia San Pham: " << x.gia << endl;
		out << "so Luong Ton Kho: " << x.soLuongTon << endl;
		return out;
	}
	string getMa() const {
		return maSanPham;
	}
	string getTen() const{
		return tenSanPham;
	}
	double getSoLuongTon() const{
		return soLuongTon;
	}
	double getGia() const{
		return gia;
	}
	void updateSoLuongTon(int newSoLuongTon){
		soLuongTon = newSoLuongTon;
	}
	~SanPham(){}
};

