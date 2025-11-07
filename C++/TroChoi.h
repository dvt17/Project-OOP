#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "MaGiam.h"
using namespace std;

class TroChoi {
private:
    string tenNguoiChoi;
    int diem;
    int luotTro1, luotTro2, luotTro3;
    int chonTro;
    time_t thoiGianBatDau;
public:
    TroChoi(string ten = "Khach") {
        tenNguoiChoi = ten;
        diem = 0;
        luotTro1 = 3;
        luotTro2 = 3;
        luotTro3 = 3;
        chonTro = 0;
    }

    void BatDau() {
        cout << "=== Xin chao, " << tenNguoiChoi << " ===\n";
        cout << "Chon tro choi:\n";
        cout << "1. Doan so\n2. Vong xoay man may\n3. Oan tu ti\n";
        cout << "Nhap lua chon: ";
        cin >> chonTro;
        thoiGianBatDau = time(0);
        switch (chonTro) {
        case 1: Game1(); break;
        case 2: Game2(); break;
        case 3: Game3(); break;
        default: cout << "Lua chon khong hop le.\n"; break;
        }
    }

    void Game1() {
        srand(time(NULL));
        int so = rand() % 30 + 1;
        while(luotTro1 > 0){
            int chon;
            cout << "Nhap 1 so (1-30): ";
            cin >> chon;
            luotTro1--;
            if (chon == so) {
                diem += 200;
                cout << "Chinh xac! +200 diem thuong" << endl;
                break;
            }
            else if (chon < so) {
                cout << "So bi mat lon hon so ban chon!" << endl;
                continue;
            }
            else{
                cout << "So bi mat nho hon so ban chon!" << endl;
                continue;
            }           
        }
        if (luotTro1 == 0) {
            cout << "Ban da het luoc choi!" << endl;
        }
    }
    void Game2() {
        char dsKitu[3] = { '%','@','*' };
        char Kitu[3], q;
        srand(time(NULL));
        cin.ignore();
        while (luotTro2 > 0) {
            cout << "An [Enter] de quay hoac an [X] de thoat: ";
            cin.get(q);
            if (q == '\n') {
                for (int i = 0; i < 3; i++) {
                    int so = rand() % 3;
                    Kitu[i] = dsKitu[so];
                }
                for (int j = 0; j < 3; j++) {
                    cout << Kitu[j] << " | ";
                }
                if (Kitu[0] == Kitu[1] && Kitu[1] == Kitu[2]) {
                    diem += 500;
                    cout << " ====> JACKPOT! +500 diem thuong" << endl;
                }
                else if (Kitu[0] == Kitu[1] || Kitu[1] == Kitu[2] || Kitu[0] == Kitu[2]) {
                    diem += 200;
                    cout << " ====> Lucky! +200 diem thuong" << endl;
                }
                else {
                    cout << " ====> Unlucky!" << endl;
                }
                luotTro2--;
            }
            else if (q == 'X' || q == 'x') {
                break;
            }
        }
        if (luotTro2 == 0) {
            cout << "Ban da het 3 luot choi! " << endl;
        }
    }
    void Game3(); // logic trò 3

    MaGiam DoiThuong() {
        int thuong;
        cout << "\nNguoi choi: " << tenNguoiChoi << endl;
        cout << "Tong diem: " << diem << endl;
        cout << "\n1. 500 diem = 1 FREESHIP" << endl;
        cout << "2. 1000 diem = 1 MAGIAM5" << endl;
        cout << "3. 1500 diem = 1 MAGIAM10" << endl;
        cout << "4. 2000 diem = 1 MAGIAM15" << endl;
        cout << "5. 2500 diem = 1 MAGIAM20" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon: ";
        cin >> thuong;
        switch (thuong) {
        case 1: 
            if (diem >= 500) {
                diem -= 500;
                return MaGiam("FREESHIP", 100);
            }
            else {
                cout << " So diem cua ban khong du (" << diem << " < 500)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 2:
            if (diem >= 1000) {
                diem -= 1000;
                return MaGiam("MAGIAM5", 5);
            }
            else {
                cout << " So diem cua ban khong du (" << diem << " < 1000)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 3: 
            if (diem >= 1500) {
                diem -= 1500;
                return MaGiam("MAGIAM10", 10);
            }
            else {
                cout << " So diem cua ban khong du (" << diem << " < 1500)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 4: 
            if (diem >= 2000) {
                diem -= 2000;
                return MaGiam("MAGIAM15", 15);
            }
            else {
                cout << " So diem cua ban khong du (" << diem << " < 2000)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 5: 
            if (diem >= 2500) {
                diem -= 2500;
                return MaGiam("MAGIAM20", 20);
            }
            else {
                cout << " So diem cua ban khong du (" << diem << " < 2500)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        default: return MaGiam("MAGIAM0",0);
        }
    }
    ~TroChoi() {}
};
