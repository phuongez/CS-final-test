#include <iostream>
using namespace std;

class Vemaybay {
public:
    char tenchuyen[50];
    char ngaybay[20];
    int giave;

    Vemaybay() {
        tenchuyen[0] = '\0';
        ngaybay[0] = '\0';
        giave = 0;
    }

    void nhap() {
        cout << "  Nhap ten chuyen bay: ";
        cin.ignore();
        nhapChuoi(tenchuyen, 50);
        cout << "  Nhap ngay bay: ";
        nhapChuoi(ngaybay, 20);
        do {
            cout << "  Nhap gia ve: ";
            cin >> giave;
            if (giave < 0) cout << "    Gia ve khong hop le. Nhap lai.\n";
        } while (giave < 0);
    }

    void xuat() {
        cout << "Ten chuyen: " << tenchuyen << ", Ngay bay: " << ngaybay << ", Gia: " << giave << " VND\n";
    }

    static void nhapChuoi(char* s, int maxlen) {
        char ch;
        int i = 0;
        while (i < maxlen - 1 && (ch = cin.get()) != '\n') {
            s[i++] = ch;
        }
        s[i] = '\0';
    }
};

class Nguoi {
public:
    char hoten[50];
    char gioitinh[10];
    int tuoi;

    Nguoi() {
        hoten[0] = '\0';
        gioitinh[0] = '\0';
        tuoi = 0;
    }

    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        Vemaybay::nhapChuoi(hoten, 50);
        cout << "Nhap gioi tinh: ";
        Vemaybay::nhapChuoi(gioitinh, 10);
        do {
            cout << "Nhap tuoi: ";
            cin >> tuoi;
            if (tuoi <= 0) cout << "  Tuoi khong hop le. Nhap lai.\n";
        } while (tuoi <= 0);
    }

    void xuat() {
        cout << "Ho ten: " << hoten << ", Gioi tinh: " << gioitinh << ", Tuoi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi {
private:
    int* chisoChuyenBay;
    int soluong;
    int tong;

public:
    Hanhkhach() {
        chisoChuyenBay = NULL;
        soluong = 0;
        tong = 0;
    }

    ~Hanhkhach() {
        delete[] chisoChuyenBay;
    }

    void nhap(int soChuyenBay, Vemaybay* dsChuyenBay) {
        Nguoi::nhap();

        do {
            cout << "Nhap so luong ve muon mua: ";
            cin >> soluong;
            if (soluong <= 0) cout << "  So luong khong hop le. Nhap lai.\n";
        } while (soluong <= 0);

        chisoChuyenBay = new int[soluong];

        for (int i = 0; i < soluong; ++i) {
            int chon;
            cout << "Chon chuyen bay " << i + 1 << " (nhap chi so tu 1 den " << soChuyenBay << "): ";
            do {
                cin >> chon;
                if (chon < 1 || chon > soChuyenBay)
                    cout << "  Lua chon khong hop le. Nhap lai: ";
            } while (chon < 1 || chon > soChuyenBay);

            chisoChuyenBay[i] = chon - 1; 
            tong += dsChuyenBay[chon - 1].giave;
        }
    }

    int tongtien() const {
        return tong;
    }

    void xuat(Vemaybay* dsChuyenBay) {
        Nguoi::xuat();
        cout << "  Danh sach ve da mua:\n";
        for (int i = 0; i < soluong; ++i) {
            cout << "   + ";
            dsChuyenBay[chisoChuyenBay[i]].xuat();
        }
        cout << "  Tong tien: " << tong << " VND\n";
    }
};

void sapxep(Hanhkhach* ds, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (ds[i].tongtien() < ds[j].tongtien()) {
                Hanhkhach temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
}

int main() {
    int soChuyen;
    do {
        cout << "Nhap so chuyen bay: ";
        cin >> soChuyen;
        if (soChuyen <= 0) cout << "  So luong khong hop le. Nhap lai.\n";
    } while (soChuyen <= 0);

    Vemaybay* dsChuyenBay = new Vemaybay[soChuyen];
    for (int i = 0; i < soChuyen; ++i) {
        cout << "\n== Nhap chuyen bay thu " << i + 1 << " ==\n";
        dsChuyenBay[i].nhap();
    }

    cout << "\nDanh sach chuyen bay:\n";
    for (int i = 0; i < soChuyen; ++i) {
        cout << "Chuyen " << i + 1 << ": ";
        dsChuyenBay[i].xuat();
    }

    int n;
    do {
        cout << "\nNhap so hanh khach: ";
        cin >> n;
        if (n <= 0) cout << "  So luong khong hop le. Nhap lai.\n";
    } while (n <= 0);

    Hanhkhach* dsHK = new Hanhkhach[n];
    for (int i = 0; i < n; ++i) {
        cout << "\n== Nhap hanh khach thu " << i + 1 << " ==\n";
        dsHK[i].nhap(soChuyen, dsChuyenBay);
    }

    sapxep(dsHK, n);

    cout << "\n=========== DANH SACH HANH KHACH (sap theo tong tien giam dan) ===========\n";
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Hanh khach thu " << i + 1 << " ---\n";
        dsHK[i].xuat(dsChuyenBay);
    }

    delete[] dsChuyenBay;
    delete[] dsHK;

    return 0;
}
