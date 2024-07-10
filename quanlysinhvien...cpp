#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

// Define Student structure
struct SinhVien {
    int id;
    char ten[30];
    char gioiTinh[5];
    int tuoi;
    float diemToan;
    float diemLy;
    float diemHoa;
    float diemTB;
    char hocluc[15];
};

// Function declarations
void nhapThongTinSinhVien(SinhVien& sv);
void themSinhVien(SinhVien a[], int& n, const SinhVien& sv);
void capNhatThongTinSinhVien(SinhVien a[], int n, int id);
void xoaSinhVien(SinhVien a[], int& n, int id);
void timKiemSinhVienTheoTen(const SinhVien a[], int n, const char* ten);
void timKiemSinhVienTheoTenDau(const SinhVien a[], int n, char dau);
void sapXepTheoDTB_TangDan(SinhVien a[], int n);
void sapXepTheoTen(SinhVien a[], int n);
void hienThiDanhSach(const SinhVien a[], int n);
void ghiDanhSachVaoFile(const SinhVien a[], int n, const char* fileName);
void timKiemTenDauA(const SinhVien a[], int n);
void xemDanhSachSinhVienGioi(const SinhVien a[], int n);
void xemDanhSachSinhVienKha(const SinhVien a[], int n);
void xemDanhSachSinhVienYeu(const SinhVien a[], int n);
void danhDauHocSinhNghiHoc(SinhVien a[], int n);
void lietKeXuatSacDauTien(SinhVien a[], int n);
void danhSachHocBong(SinhVien a[], int n);
void lietKeYeuDauTienHocLai(SinhVien a[], int n);
void danhSachHocLai(SinhVien a[], int n);
void hocSinhDuDieuKienLenLop(SinhVien a[], int n);
void danhSachOaiLaiLop(SinhVien a[], int n);
void xoaToanBoSinhVien(SinhVien a[], int& n);
void nhapDanhSachTuFile(SinhVien a[], int& n, const char* fileName);
void sapXepTheoTuoiGiamDan(SinhVien a[], int n);
void xemDanhSachSinhVienTheoTuoi(const SinhVien a[], int n);
void tinhDiemTrungBinh(SinhVien& sv);
void inSinhVien(const SinhVien& sv);
void inThongTinSinhVien(const SinhVien& sv);

int main() {
    SinhVien dsSV[100];
    int soLuongSV = 0;
    int luaChon;

    do {
        cout << "\n===================== MENU =====================\n";
        cout << "1. Nhap danh sach sinh vien\n";
        cout << "2. Them sinh vien\n";
        cout << "3. Cap nhat thong tin sinh vien\n";
        cout << "4. Xoa sinh vien\n";
        cout << "5. Tim kiem sinh vien theo ten\n";
        cout << "6. Sap xep sinh vien theo DTB tang dan\n";
        cout << "7. Sap xep sinh vien theo ten\n";
        cout << "8. Hien thi danh sach sinh vien\n";
        cout << "9. Ghi danh sach sinh vien vao file\n";
        cout << "10. Tim kiem sinh vien ten bat dau bang 'A'\n";
        cout << "11. Xem danh sach sinh vien gioi\n";
        cout << "12. Xem danh sach sinh vien kha\n";
        cout << "13. Xem danh sach sinh vien yeu\n";
        cout << "14. Danh dau hoc sinh nghi hoc\n";
        cout << "15. Liet ke 5 sinh vien xuat sac dau tien\n";
        cout << "16. Danh sach sinh vien dat hoc bong\n";
        cout << "17. Liet ke 5 sinh vien yeu dau tien de hoc lai\n";
        cout << "18. Danh sach sinh vien phai hoc lai\n";
        cout << "19. Sinh vien du dieu kien len lop\n";
        cout << "20. Danh sach sinh vien phai o lai lop\n";
        cout << "21. Nhap danh sach sinh vien tu file\n";
        cout << "22. Sap xep danh sach sinh vien theo tuoi giam dan\n";
        cout << "23. Xem danh sach sinh vien duoi 18 tuoi\n";
        cout << "24. Tim kiem sinh vien theo ten dau 'B'\n";
        cout << "25. Tim kiem sinh vien theo ten dau 'C'\n";
        cout << "26. Tim kiem sinh vien theo ten dau 'D'\n";
        cout << "27. Tim kiem sinh vien theo ten dau 'E'\n";
        cout << "28. Tim kiem sinh vien theo ten dau 'F'\n";
        cout << "29. Tim kiem sinh vien theo ten dau 'G'\n";
        cout << "30. Tim kiem sinh vien theo ten dau 'H'\n";
        cout << "31. Tim kiem sinh vien theo ten dau 'J'\n";
        cout << "32. Tim kiem sinh vien theo ten dau 'K'\n";
        cout << "33. Tim kiem sinh vien theo ten dau 'L'\n";
        cout << "34. Tim kiem sinh vien theo ten dau 'M'\n";
        cout << "35. Tim kiem sinh vien theo ten dau 'N'\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "================================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                cout << "Nhap so luong sinh vien can nhap: ";
                cin >> soLuongSV;
                for (int i = 0; i < soLuongSV; ++i) {
                    nhapThongTinSinhVien(dsSV[i]);
                }
                break;
            }
            case 2: {
                SinhVien sv;
                nhapThongTinSinhVien(sv);
                themSinhVien(dsSV, soLuongSV, sv);
                break;
            }
            case 3: {
                int id;
                cout << "Nhap ID sinh vien can cap nhat thong tin: ";
                cin >> id;
                capNhatThongTinSinhVien(dsSV, soLuongSV, id);
                break;
            }
            case 4: {
                int id;
                cout << "Nhap ID sinh vien can xoa: ";
                cin >> id;
                xoaSinhVien(dsSV, soLuongSV, id);
                break;
            }
            case 5: {
                char tenTim[30];
                cout << "Nhap ten sinh vien can tim: ";
                cin.ignore();
                cin.getline(tenTim, 30);
                timKiemSinhVienTheoTen(dsSV, soLuongSV, tenTim);
                break;
            }
            case 6: {
                sapXepTheoDTB_TangDan(dsSV, soLuongSV);
                cout << "Da sap xep danh sach sinh vien theo DTB tang dan.\n";
                break;
            }
            case 7: {
                sapXepTheoTen(dsSV, soLuongSV);
                cout << "Da sap xep danh sach sinh vien theo ten.\n";
                break;
            }
            case 8: {
                hienThiDanhSach(dsSV, soLuongSV);
                break;
            }
            case 9: {
                char tenFile[50];
                cout << "Nhap ten file de ghi danh sach sinh vien: ";
                cin.ignore();
                cin.getline(tenFile, 50);
                ghiDanhSachVaoFile(dsSV, soLuongSV, tenFile);
                break;
            }
            case 10: {
                timKiemTenDauA(dsSV, soLuongSV);
                break;
            }
            case 11: {
                xemDanhSachSinhVienGioi(dsSV, soLuongSV);
                break;
            }
            case 12: {
                xemDanhSachSinhVienKha(dsSV, soLuongSV);
                break;
            }
            case 13: {
                xemDanhSachSinhVienYeu(dsSV, soLuongSV);
                break;
            }
            case 14: {
                danhDauHocSinhNghiHoc(dsSV, soLuongSV);
                cout << "Da danh dau hoc sinh nghi hoc.\n";
                break;
            }
            case 15: {
                lietKeXuatSacDauTien(dsSV, soLuongSV);
                break;
            }
            case 16: {
                danhSachHocBong(dsSV, soLuongSV);
                break;
            }
            case 17: {
                lietKeYeuDauTienHocLai(dsSV, soLuongSV);
                break;
            }
            case 18: {
                danhSachHocLai(dsSV, soLuongSV);
                break;
            }
            case 19: {
                hocSinhDuDieuKienLenLop(dsSV, soLuongSV);
                break;
            }
            case 20: {
                danhSachOaiLaiLop(dsSV, soLuongSV);
                break;
            }
            case 21: {
                char tenFile[50];
                cout << "Nhap ten file de nhap danh sach sinh vien: ";
                cin.ignore();
                cin.getline(tenFile, 50);
                nhapDanhSachTuFile(dsSV, soLuongSV, tenFile);
                break;
            }
            case 22: {
                sapXepTheoTuoiGiamDan(dsSV, soLuongSV);
                cout << "Da sap xep danh sach sinh vien theo tuoi giam dan.\n";
                break;
            }
            case 23: {
                xemDanhSachSinhVienTheoTuoi(dsSV, soLuongSV);
                break;
            }
            case 24: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'B');
                break;
            }
            case 25: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'C');
                break;
            }
            case 26: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'D');
                break;
            }
            case 27: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'E');
                break;
            }
            case 28: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'F');
                break;
            }
            case 29: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'G');
                break;
            }
            case 30: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'H');
                break;
            }
            case 31: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'J');
                break;
            }
            case 32: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'K');
                break;
            }
            case 33: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'L');
                break;
            }
            case 34: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'M');
                break;
            }
            case 35: {
                timKiemSinhVienTheoTenDau(dsSV, soLuongSV, 'N');
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh.\n";
                break;
            }
            default: {
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
            }
        }
    } while (luaChon != 0);

    return 0;
}

// Function implementations

void nhapThongTinSinhVien(SinhVien& sv) {
    cout << "Nhap ID: ";
    cin >> sv.id;
    cout << "Nhap ten: ";
    cin.ignore();
    cin.getline(sv.ten, 30);
    cout << "Nhap gioi tinh: ";
    cin.getline(sv.gioiTinh, 5);
    cout << "Nhap tuoi: ";
    cin >> sv.tuoi;
    cout << "Nhap diem Toan: ";
    cin >> sv.diemToan;
    cout << "Nhap diem Ly: ";
    cin >> sv.diemLy;
    cout << "Nhap diem Hoa: ";
    cin >> sv.diemHoa;
    tinhDiemTrungBinh(sv);
    inThongTinSinhVien(sv);
}

void themSinhVien(SinhVien a[], int& n, const SinhVien& sv) {
    a[n] = sv;
    n++;
}

void capNhatThongTinSinhVien(SinhVien a[], int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (a[i].id == id) {
            cout << "Nhap thong tin moi cho sinh vien co ID " << id << ":\n";
            nhapThongTinSinhVien(a[i]);
            cout << "Da cap nhat thong tin sinh vien co ID " << id << ".\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ID " << id << ".\n";
}

void xoaSinhVien(SinhVien a[], int& n, int id) {
    for (int i = 0; i < n; ++i) {
        if (a[i].id == id) {
            for (int j = i; j < n - 1; ++j) {
                a[j] = a[j + 1];
            }
            n--;
            cout << "Da xoa sinh vien co ID " << id << ".\n";
            return;
        }
    }
    cout << "Khong tim thay sinh vien co ID " << id << ".\n";
}

void timKiemSinhVienTheoTen(const SinhVien a[], int n, const char* ten) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].ten, ten) == 0) {
            inSinhVien(a[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ten " << ten << ".\n";
    }
}

void timKiemSinhVienTheoTenDau(const SinhVien a[], int n, char dau) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (a[i].ten[0] == dau) {
            inSinhVien(a[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien co ten bat dau bang chu cai " << dau << ".\n";
    }
}

void sapXepTheoDTB_TangDan(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].diemTB > a[j].diemTB) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void sapXepTheoTen(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(a[i].ten, a[j].ten) > 0) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void hienThiDanhSach(const SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        inSinhVien(a[i]);
    }
}

void ghiDanhSachVaoFile(const SinhVien a[], int n, const char* fileName) {
    ofstream outFile(fileName);
    if (!outFile) {
        cout << "Khong the mo file de ghi.\n";
        return;
    }
    for (int i = 0; i < n; ++i) {
        outFile << a[i].id << "\n"
                << a[i].ten << "\n"
                << a[i].gioiTinh << "\n"
                << a[i].tuoi << "\n"
                << a[i].diemToan << "\n"
                << a[i].diemLy << "\n"
                << a[i].diemHoa << "\n"
                << a[i].diemTB << "\n"
                << a[i].hocluc << "\n";
    }
    outFile.close();
    cout << "Da ghi danh sach sinh vien vao file " << fileName << ".\n";
}

void timKiemTenDauA(const SinhVien a[], int n) {
    timKiemSinhVienTheoTenDau(a, n, 'A');
}

void xemDanhSachSinhVienGioi(const SinhVien a[], int n) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].hocluc, "Gioi") == 0) {
            inSinhVien(a[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co sinh vien gioi trong danh sach.\n";
    }
}

void xemDanhSachSinhVienKha(const SinhVien a[], int n) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].hocluc, "Kha") == 0) {
            inSinhVien(a[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co sinh vien kha trong danh sach.\n";
    }
}

void xemDanhSachSinhVienYeu(const SinhVien a[], int n) {
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].hocluc, "Yeu") == 0) {
            inSinhVien(a[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co sinh vien yeu trong danh sach.\n";
    }
}

void danhDauHocSinhNghiHoc(SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].hocluc, "Yeu") == 0) {
            cout << "Sinh vien " << a[i].ten << " nghi hoc vi hoc luc yeu.\n";
        }
    }
}

void nhapDanhSachTuFile(SinhVien a[], int& n, const char* fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cout << "Khong the mo file de doc.\n";
        return;
    }
    n = 0;
    while (inFile >> a[n].id) {
        inFile.ignore();
        inFile.getline(a[n].ten, 30);
        inFile.getline(a[n].gioiTinh, 5);
        inFile >> a[n].tuoi;
        inFile >> a[n].diemToan;
        inFile >> a[n].diemLy;
        inFile >> a[n].diemHoa;
        inFile >> a[n].diemTB;
        inFile.ignore();
        inFile.getline(a[n].hocluc, 10);
        n++;
    }
    inFile.close();
    cout << "Da nhap danh sach sinh vien tu file " << fileName << ".\n";
}

void sapXepTheoTuoiGiamDan(SinhVien a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].tuoi < a[j].tuoi) {
                SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void xemDanhSachSinhVienTheoTuoi(const SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        inSinhVien(a[i]);
    }
}

void tinhDiemTrungBinh(SinhVien& sv) {
    sv.diemTB = (sv.diemToan + sv.diemLy + sv.diemHoa) / 3.0;
    if (sv.diemTB >= 8.0) {
        strcpy(sv.hocluc, "Gioi");
    } else if (sv.diemTB >= 6.5) {
        strcpy(sv.hocluc, "Kha");
    } else {
        strcpy(sv.hocluc, "Yeu");
    }
}

void inThongTinSinhVien(const SinhVien& sv) {
    cout << "Thong tin sinh vien:\n";
    cout << "ID: " << sv.id << "\n";
    cout << "Ten: " << sv.ten << "\n";
    cout << "Gioi tinh: " << sv.gioiTinh << "\n";
    cout << "Tuoi: " << sv.tuoi << "\n";
    cout << "Diem Toan: " << sv.diemToan << "\n";
    cout << "Diem Ly: " << sv.diemLy << "\n";
    cout << "Diem Hoa: " << sv.diemHoa << "\n";
    cout << "Diem trung binh: " << sv.diemTB << "\n";
    cout << "Hoc luc: " << sv.hocluc << "\n";
}

void inSinhVien(const SinhVien& sv) {
    cout << "ID: " << sv.id << ", Ten: " << sv.ten << ", Gioi tinh: " << sv.gioiTinh << ", Tuoi: " << sv.tuoi
         << ", Diem Toan: " << sv.diemToan << ", Diem Ly: " << sv.diemLy << ", Diem Hoa: " << sv.diemHoa
         << ", Diem TB: " << sv.diemTB << ", Hoc luc: " << sv.hocluc << "\n";
}

