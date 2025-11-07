#pragma once
#include <string>
#include <ctime>
#include <iostream>
using namespace std;
class MaGiam
{
private:
	string TenMa;
	float GiaTri;
	bool SuDung;
	time_t NgayCap;
	tm n;
public:
	MaGiam(string _TenMa = "MAGIAM0", int _GiaTri = 0) {
		TenMa = _TenMa;
		SuDung = true;
		NgayCap = time(0);
		localtime_s(&n, &NgayCap);
		if (_GiaTri >= 0) {
			GiaTri = _GiaTri / 100.0;
		}
		else {
			GiaTri = 0;
		}
	}
	bool HieuLuc() {
		if (SuDung && (time(0) <= NgayCap + 7 * 24 * 60 * 60)) {
			return true;
		}
		else {
			return false;
		}
	}
	float DungMa() {
		if (HieuLuc()) {
			SuDung = false;
			return GiaTri;
		}
		else {
			return 0;
		}
	}
	friend ostream& operator<<(ostream& out, MaGiam& m) {
		out << m.TenMa << " " << m.GiaTri*100 << "% " << (m.SuDung ? "Chua Dung":"Da Dung") << " " << m.n.tm_hour << ":" << m.n.tm_min << ":" << m.n.tm_sec << " " << m.n.tm_mday << "/" << m.n.tm_mon + 1 << "/" << m.n.tm_year + 1900 << " " << (m.HieuLuc() ? "Con hieu luc":"Het hieu luc") << endl;
		return out;
	}
	~MaGiam(){}
};

