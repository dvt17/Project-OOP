#pragma once
#include <cstdlib>
#include <fstream>
#include <map>
#include "MaGiam.h"

class TroChoi
{
private:
    string tenNguoiChoi;
    int diem;
    int luotTro1, luotTro2, luotTro3;
    int chonTro;
    time_t thoiGianBatDau;

public:
    TroChoi(string ten = "Khach")
    {
        tenNguoiChoi = ten;
        diem = 0;
        luotTro1 = 3;
        luotTro2 = 3;
        luotTro3 = 3;
        chonTro = 0;
        thoiGianBatDau = 0;
    }
    friend istream& operator>>(istream& in, TroChoi& p)
    {
        in >> p.tenNguoiChoi >> p.diem >> p.luotTro1 >> p.luotTro2 >> p.luotTro3 >> p.thoiGianBatDau;
        return in;
    }
    friend ostream& operator<<(ostream& out, const TroChoi& p)
    {
        out << p.tenNguoiChoi << " " << p.diem << " " << p.luotTro1 << " " << p.luotTro2 << " " << p.luotTro3 << " " << p.thoiGianBatDau;
        return out;
    }
    void CapNhatLuotChoi()
    {
        TroChoi dulieu;
        map<string, TroChoi> dsDuLieu;
        fstream file("TroChoi.txt", ios::in);
        while (file >> dulieu)
        {
            dsDuLieu[dulieu.tenNguoiChoi] = dulieu;
        }
        for (auto& it : dsDuLieu)
        {
            if (tenNguoiChoi == it.first)
            {
                dulieu = it.second;
            }
            else
            {
                dulieu = dsDuLieu["Khach"];
            }
        }
        file.close();
        time_t thoiGianTroiQua = time(0) - dulieu.thoiGianBatDau;
        double luotHoiLai;
        if (dulieu.thoiGianBatDau == 0)
        {
            luotHoiLai = 0;
        }
        else
        {
            luotHoiLai = thoiGianTroiQua / 60.0;
        }
        luotTro1 = (luotHoiLai + dulieu.luotTro1 > 3) ? 3 : (int)(luotHoiLai + dulieu.luotTro1);
        luotTro2 = (luotHoiLai + dulieu.luotTro2 > 3) ? 3 : (int)(luotHoiLai + dulieu.luotTro2);
        luotTro3 = (luotHoiLai + dulieu.luotTro3 > 3) ? 3 : (int)(luotHoiLai + dulieu.luotTro3);
    }
    void BatDau()
    {
        while (true) {
            cout << "=== Xin chao, " << tenNguoiChoi << " ===\n";
            cout << "Chon tro choi:\n";
            cout << "1. Doan so\n2. Vong xoay man may\n3. Quy luat day so\n4. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> chonTro;
            thoiGianBatDau = time(0);
            switch (chonTro)
            {
            case 1:
                Game1();
                break;
            case 2:
                Game2();
                break;
            case 3:
                Game3();
                break;
            case 4:
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
            }
            fstream file("TroChoi.txt", ios::out | ios::app);
            file << *this << endl;
            file.close();
            if (chonTro >= 4) {
                break;
            }
        }
    }

    void Game1()
    {
        srand(time(NULL));
        int so = rand() % 30 + 1;
        while (luotTro1 > 0)
        {
            int chon;
            cout << "[" << luotTro1 << "/3 luot] Nhap 1 so (1-30): ";
            cin >> chon;
            luotTro1--;
            if (chon == so)
            {
                diem += 200;
                cout << "Chinh xac! +200 diem thuong" << endl;
                break;
            }
            else if (chon < so)
            {
                cout << "So bi mat lon hon so ban chon!" << endl;
                continue;
            }
            else
            {
                cout << "So bi mat nho hon so ban chon!" << endl;
                continue;
            }
        }
        if (luotTro1 == 0)
        {
            cout << "Ban da het luot choi!" << endl;
        }
    }
    void Game2()
    {
        char dsKitu[3] = { '%', '@', '*' };
        char Kitu[3], quay;
        srand(time(NULL));
        cin.ignore();
        while (luotTro2 > 0)
        {
            cout << "[" << luotTro2 << "/3 luot] An [Enter] de quay hoac an [X] de thoat: ";
            cin.get(quay);
            if (quay == '\n')
            {
                for (int i = 0; i < 3; i++)
                {
                    int so = rand() % 3;
                    Kitu[i] = dsKitu[so];
                }
                for (int j = 0; j < 3; j++)
                {
                    cout << Kitu[j] << " | ";
                }
                if (Kitu[0] == Kitu[1] && Kitu[1] == Kitu[2])
                {
                    diem += 500;
                    cout << " ====> JACKPOT! +500 diem thuong" << endl;
                }
                else if (Kitu[0] == Kitu[1] || Kitu[1] == Kitu[2] || Kitu[0] == Kitu[2])
                {
                    diem += 200;
                    cout << " ====> Lucky! +200 diem thuong" << endl;
                }
                else
                {
                    cout << " ====> Unlucky!" << endl;
                }
                luotTro2--;
            }
            else if (quay == 'X' || quay == 'x')
            {
                break;
            }
        }
        if (luotTro2 == 0)
        {
            cout << "Ban da het luot choi! " << endl;
        }
    }
    void Game3()
    {
        srand(time(NULL));
        int soBatDau = rand() % 5 + 1;
        int k = rand() % 9 + 2;
        int quyLuat = rand() % 5 + 1;
        int daySo[5], soDoan;
        daySo[0] = soBatDau;
        switch (quyLuat)
        {
        case 1:
            for (int i = 1; i < 5; i++)
            {
                daySo[i] = daySo[i - 1] * k;
            }
            break;
        case 2:
            for (int i = 1; i < 5; i++)
            {
                daySo[i] = daySo[i - 1] + k;
            }
            break;
        case 3:
            for (int i = 1; i < 3; i++)
            {
                daySo[i] = daySo[i - 1] * 2;
            }
            for (int i = 3; i < 5; i++)
            {
                daySo[i] = daySo[i - 1] / 2;
            }
            break;
        case 4:
            daySo[1] = daySo[0];
            for (int i = 2; i < 5; i++)
            {
                daySo[i] = daySo[i - 1] + daySo[i - 2];
            }
            break;
        case 5:
            for (int i = 1; i < 5; i++)
            {
                daySo[i] = (i % 2 == 1) ? daySo[i - 1] + k : daySo[i - 1] - (k + 1);
            }
            break;
        }
        cout << "Hay tim quy luat va doan ra so tiep theo trong day so sau: " << endl;
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                cout << daySo[i] << " , ?\n";
            }
            else
            {
                cout << daySo[i] << " , ";
            }
        }
        while (luotTro3 > 0)
        {
            string thuLai;
            cout << "[" << luotTro3 << "/3 luot] Nhap so: ";
            cin >> soDoan;
            luotTro3--;
            if (daySo[4] == soDoan)
            {
                diem += 500;
                cout << "Chinh xac! +500 diem thuong" << endl;
                break;
            }
            else
            {
                cout << "Ban muon thu lai khong ? (Y/N): ";
                cin >> thuLai;
                for (int i = 0; i < thuLai.size(); i++)
                {
                    if (thuLai[i] >= 'a' && thuLai[i] <= 'z')
                    {
                        thuLai[i] -= 32;
                    }
                }
                if (thuLai == "YES" || thuLai == "Y")
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        if (luotTro3 == 0)
        {
            cout << "Ban da het luot choi! " << endl;
            cout << "Day so: ";
            for (int i = 0; i < 5; i++)
            {
                if (i == 4)
                {
                    cout << daySo[i] << endl;
                }
                else
                {
                    cout << daySo[i] << " , ";
                }
            }
        }
    }

    MaGiam DoiThuong()
    {
        int thuong;
        cout << "\nNguoi choi: " << tenNguoiChoi << endl;
        cout << "Tong diem: " << diem << endl;
        cout << "\n1. 1000 diem = 1 MAGIAM5" << endl;
        cout << "2. 1500 diem = 1 MAGIAM10" << endl;
        cout << "3. 2000 diem = 1 MAGIAM15" << endl;
        cout << "4. 2500 diem = 1 MAGIAM20" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon: ";
        cin >> thuong;
        switch (thuong)
        {
        case 1:
            if (diem >= 1000)
            {
                diem -= 1000;
                cout << "Doi thuong thanh cong" << endl;
                return MaGiam("MAGIAM5", 5);
            }
            else
            {
                cout << " So diem cua ban khong du (" << diem << " < 1000)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 2:
            if (diem >= 1500)
            {
                diem -= 1500;
                cout << "Doi thuong thanh cong" << endl;
                return MaGiam("MAGIAM10", 10);
            }
            else
            {
                cout << " So diem cua ban khong du (" << diem << " < 1500)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 3:
            if (diem >= 2000)
            {
                diem -= 2000;
                cout << "Doi thuong thanh cong" << endl;
                return MaGiam("MAGIAM15", 15);
            }
            else
            {
                cout << " So diem cua ban khong du (" << diem << " < 2000)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        case 4:
            if (diem >= 2500)
            {
                diem -= 2500;
                cout << "Doi thuong thanh cong" << endl;
                return MaGiam("MAGIAM20", 20);
            }
            else
            {
                cout << " So diem cua ban khong du (" << diem << " < 2500)!" << endl;
                return MaGiam("MAGIAM0", 0);
            }
        default:
            return MaGiam("MAGIAM0", 0);
        }
    }
    void setTen(string ten) {
        tenNguoiChoi = ten;
    }
};
