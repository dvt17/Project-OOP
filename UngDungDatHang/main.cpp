#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DanhGiaSP.h"
#include "SanPham.h"
#include "User.h"
#include "TroChoi.h"
#include "MucGioHang.h"
#include "GioHang.h"
#include "DonHang.h"
#include "KhachHang.h"
using namespace std;

vector<SanPham> DocFile(const string tenFile = "SanPham.txt")
{
    ifstream file(tenFile);
    SanPham sp;
    vector<SanPham> ds;
    while (file >> sp)
    {
        ds.push_back(sp);
    }
    file.close();
    return ds;
}

void dangKi()
{
    string tk, mk;

    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    User u(tk, mk);
    u.ghiFile();
    cout << "Dang ky thanh cong!\n";
}

bool dangNhap()
{
    string tk, mk;

    cout << "Nhap tai khoan: ";
    cin >> tk;
    cout << "Nhap mat khau: ";
    cin >> mk;
    if (User::dangNhap(tk, mk))
    {
        cout << "Dang nhap thanh cong!\n";
        return true;
    }
    else
    {
        cout << "Sai tai khoan hoac mat khau!\n";
        return false;
    }
}
string chuyenKiTu(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

vector<DanhGia> docDanhGia(const string& fileName = "DanhGia.txt")
{
    vector<DanhGia> ds;
    ifstream file(fileName);
    if (!file.is_open())
        return ds;

    DanhGia dg;
    while (file >> dg)
    {
        ds.push_back(dg);
    }
    file.close();
    return ds;
}
void ghiDanhGia(const DanhGia& dg, const string& fileName = "DanhGia.txt")
{
    ofstream file(fileName, ios::app);
    file << dg;
    file.close();
}

int main()
{

    vector<SanPham> ds = DocFile();
    vector<MaGiam> ma;
    string s = "========= MENU =========\n"
        "[1]. Dang ky tai khoan\n"
        "[2]. Dang nhap\n"
        "[3]. Thoat\n"
        "========================\n";

    int c;
    bool ok;
    ok = true;
    TroChoi t;
    while (ok)
    {
        cout << s << endl;
        cout << "Nhap lua chon: ";
        cin >> c;
        if (c == 1)
        {
            dangKi();
        }
        else if (c == 2 && dangNhap())
        {
            GioHang gh;
            string lc, dsMua[50];
            vector<mucTrongGioHang> dsGH;
            bool ok2 = true;
            while (ok2)
            {
                string s = "========= MENU =========\n"
                    "[1]. Danh muc san pham\n"
                    "[2]. Game\n"
                    "[3]. Them san pham vao gio hang\n"
                    "[4]. Xem gio hang\n"
                    "[5]. Mua hang\n"
                    "[6]. Danh gia\n"
                    "[0]. Thoat\n"
                    "========================\n";
                cout << s << endl;
                char chon;
                cout << "Nhap lua chon: ";
                cin >> chon;
                if (chon == '1')
                {
                    string dm;
                    cout << "Chon danh muc san pham(ThucPham, ThucUong, CaNhan, GiaDung): ";
                    cin >> dm;
                    dm = chuyenKiTu(dm);
                    for (auto it : ds)
                    {
                        if (dm == it.getDanhMuc())
                        {
                            cout << it.getMa() << " " << it.getTen() << " " << it.getGia() << endl;
                        }
                    }
                }
                else if (chon == '2')
                {
                    string ten;
                    cout << "Nhap ten: ";
                    cin >> ten;
                    t.setTen(ten);
                    t.CapNhatLuotChoi();
                    t.BatDau();
                    ma.push_back(t.DoiThuong());
                }
                else if (chon == '3')
                {
                    cout << "=== Lua Chon San Pham Cho Gio Hang ===\n";
                    gh.nhap();
                    cout << "\nBan co muon xoa san pham nao? (y/n): ";
                    cin >> lc;
                    lc = chuyenKiTu(lc);
                    if (lc == "Y" || lc == "YES")
                    {
                        cin.ignore();
                        while (true) {
                            string tenXoa;
                            cout << "Nhap ten san pham muon xoa, muon dung bam [X]: ";
                            getline(cin, tenXoa);
                            tenXoa = chuyenKiTu(tenXoa);
                            if (tenXoa == "X") {
                                break;
                            }
                            else {
                                gh.xoaMuc(tenXoa);
                                cout << "Da xoa san pham " << tenXoa;
                            }
                        }
                    }
                    dsGH = gh.getMuc();
                }
                else if(chon == '4'){
                    cout << "==========Thong tin gio hang==========" << endl;
                    for (auto it : dsGH) {
                        it.displayInfo();
                    }
                    cout << "======================================" << endl;
                }
                else if (chon == '5') {
                    int n = 0;
                    while (true) {
                        cout << "Nhap ten san pham muon mua trong gio hang, muon dung bam [X]: ";
                        cin >> lc;
                        lc = chuyenKiTu(lc);
                        if (lc == "X") {
                            break;
                        }
                        else {
                            dsMua[n++] = lc;
                        }
                    }
                    if (dsMua->empty()) {
                    }
                    else {
                        float gt;
                        DiaChi dc;
                        KhachHang kh;
                        cout << "Nhap thong tin(HoTen, SoDienThoai, Email,DiaChi): ";
                        cin >> kh >> dc;
                        cout << "==========Thong tin don hang==========" << endl;
                        cout << kh;
                        DonHang d(dc);
                        d.ngayUocTinh();
                        cout << "TenSP x(So Luong): " << endl;
                        fstream file("ThongTinGiaoHang.txt", ios::app);
                        file << kh;
                        for (int i = 0; i < dsMua->size();i++) {
                            for (auto it : dsGH) {
                                if (dsMua[i] == it.getTen()) {
                                    cout << it.getTen() << " x" << it.getSoLuong() << endl;
                                    file << it.getTen() << " x" << it.getSoLuong() << endl;
                                }
                            }
                        }
                        file << dc << d;
                        cout << dc << d;
                        cout << "Tien ship: " << d.tinhPhiShip() * gh.tongGioHang() << endl;
                        cout << "Tong gio hang: " << gh.tongGioHang() << endl;
                        cout << "==========================================" << endl;
                        double tt = gh.tongGioHang() + (d.tinhPhiShip() * gh.tongGioHang());
                        for (int i = 0; i < dsMua->size(); i++) {
                            for (auto it : dsGH) {
                                if (dsMua[i] == it.getTen()) {
                                    gh.xoaMuc(dsMua[i]);
                                }
                            }
                        }
                        dsGH = gh.getMuc();
                        if (ma.empty())
                        {
                            cout << "Ban khong co ma giam gia nao!!!" << endl;
                            cout << "Thanh toan: " << tt << endl;
                        }
                        else
                        {
                            cout << "Ban co muon ap ma giam gia khong(y/n)? ";
                            cin >> lc;
                            lc = chuyenKiTu(lc);
                            if (lc == "Y" || lc == "YES")
                            {
                                cout << "Danh sach ma giam: " << endl;
                                for (auto x : ma)
                                {
                                    cout << x << endl;
                                }
                                cout << "Nhap ma can dung: ";
                                cin >> lc;
                                lc = chuyenKiTu(lc);
                                for (auto x : ma)
                                {
                                    if (lc == x.getTM() && x.HieuLuc())
                                    {
                                        gt = x.DungMa();
                                        cout << "Dung ma thanh cong" << endl;
                                        break;
                                    }
                                }
                            }
                            cout << "Thanh toan: " << tt - tt * gt << endl;
                        }
                    }
                }
                else if (chon == '6')
                {
                    int chonDG;
                    do
                    {
                        cout << "\n====== MENU DANH GIA SHOP ======\n";
                        cout << "1. Them danh gia\n";
                        cout << "2. Xem tat ca danh gia\n";
                        cout << "3. Quay lai\n";
                        cout << "====================================\n";
                        cout << "Nhap lua chon: ";
                        cin >> chonDG;
                        cin.ignore();

                        if (chonDG == 1)
                        {
                            string bl;
                            float d;
                            cout << "Nhap diem (1-5): ";
                            cin >> d;
                            cin.ignore();
                            cout << "Nhap binh luan: ";
                            getline(cin, bl);

                            DanhGia dg(d, bl);

                            ofstream file("DanhGia.txt", ios::app);
                            file << dg.getDiem() << "|"
                                << dg.getBinhLuan() << "\n";
                            file.close();
                            cout << "Them danh gia thanh cong!\n";
                        }
                        else if (chonDG == 2)
                        {
                            cout << "\n===== DANH SACH DANH GIA =====\n";
                            ifstream file("DanhGia.txt");
                            if (!file.is_open())
                            {
                                cout << "Chua co danh gia nao!\n";
                            }
                            else
                            {
                                string line;
                                while (getline(file, line))
                                {
                                    cout << line << endl;
                                }
                                file.close();
                            }
                        }
                    } while (chonDG != 3);
                }
                else if(chon == '0') break;
            }
        }
        else
        {
            cout << "Thoat thanh cong";
            ok = false;
        }
    }
    return 0;
}