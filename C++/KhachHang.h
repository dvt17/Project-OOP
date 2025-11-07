#pragma once
#include<iostream>
#include<string>
using namespace std;

class KhachHang {
private:
	string maKhachHang, hoTen, soDienThoai, email;
public:
	KhachHang(string ma, string ten, string dt, string e) : maKhachHang(ma), hoTen(ten), soDienThoai(dt), email(e){}
	friend istream& operator >>(istream& in, KhachHang x) {
		in >> x.maKhachHang >> x.hoTen >> x.soDienThoai >> x.email;
		return in;
	}
	friend ostream& operator <<(ostream& out, const KhachHang& x) {
		out << "Ma Khach Hang: " << x.maKhachHang << endl;
		out << "Ho Ten: " << x.hoTen << endl;
		out << "So Dien Thoai: " << x.soDienThoai << endl;
		out << "Email: " << x.email << endl;
		return out;
	}
	void setMa(string ma) {
		maKhachHang = ma;
	}
	void setTen(string ten) {
		hoTen = ten;
	}
	void setsoDT(string dt) {
		soDienThoai = dt;
	}
	void setEmail(string e) {
		email = e;
	}
	string getMa() const{
		return maKhachHang;
	}
	string getTen() const {
		return hoTen;
	}
	string getSoDT() const {
		return soDienThoai;
	}
	string getEmail() const {
		return email;
	}
	~KhachHang(){}
};