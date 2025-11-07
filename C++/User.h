#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    string taiKhoan;
    string matKhau;

public:
    User() {}
    User(string tk, string mk) {
        taiKhoan = tk;
        matKhau = mk;
    }

    string getTaiKhoan() { return taiKhoan; }
    string getMatKhau() { return matKhau; }
    void setTaiKhoan(string tk) { taiKhoan = tk; }
    void setMatKhau(string mk) { matKhau = mk; }

    void ghiFile() {
        ofstream file("users.txt", ios::app);
        if (file.is_open()) {
            file << taiKhoan << " " << matKhau << "\n";
            file.close();
        }
        else {
            cout << "Khong mo duoc file!\n";
        }
    }

    static bool dangNhap(string tk, string mk) {
        ifstream file("users.txt");
        string tkFile, mkFile;

        if (!file.is_open()) {
            cout << "Khong mo duoc file!\n";
            return false;
        }

        while (file >> tkFile >> mkFile) {
            if (tk == tkFile && mk == mkFile) {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }
    ~User(){}
};
