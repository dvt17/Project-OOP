#pragma once
#include <string>
#include<iostream>
using namespace std;
class DiaChi
{
private:
	string soNha, tenDuong, tenPhuong, tenQuan, tenTP;
public:
	DiaChi(string sn, string d, string p, string q, string tp) : soNha(sn), tenDuong(d), tenPhuong(p), tenQuan(q), tenTP(tp){}
	friend istream& operator >> (istream& in, DiaChi& s) {
		in >> s.soNha >> s.tenDuong >> s.tenPhuong >> s.tenQuan >> s.tenTP;
		return in;
	}
	friend ostream& operator <<(ostream& out, DiaChi& s) {
		out << "So Nha: " << s.soNha << endl;
		out << "Duong: " << s.tenDuong << " | " << "Phuong: " << s.tenPhuong << " | " << "Quan: " << s.tenQuan << " | " << "Thanh Pho: " << s.tenTP;
		return out;
	}
	string getSN() {
		return soNha;
	}
	string getDuong() {
		return tenDuong;
	}
	string getPhuong() {
		return tenPhuong;
	}
	string getQuan() {
		return tenQuan;
	}
	string getTP() {
		return tenTP;
	}
	void setSN(string sn) {
		soNha = sn;
	}
	void setDuong(string d) {
		tenDuong = d;
	}
	void setPhuong(string p) {
		tenPhuong = p;
	}
	void setQuan(string q) {
		tenQuan = q;
	}
	void setTP(string tp) {
		tenTP = tp;
	}
	~DiaChi(){}
};

