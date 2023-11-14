#include <iostream>
using namespace std;

void nhapDaySo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

void xuatDaySo(int a[], int n) {
    cout << "Day so vua nhap la: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
bool kiemTraDaySoDuong(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) {
            return false;
        }
    }
    return true;
}
void tachDS(int a[], int n, int b[], int &nb, int c[], int &nc) {
    nb = 0;
    nc = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            b[nb] = a[i];
            nb++;
        } else {
            c[nc] = a[i];
            nc++;
        }
    }
}
_______________________________
#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 50;

struct MaTran {
    int list[MAX][MAX];
    int n, m; // Số dòng số cột của ma trận
};

// Viết hàm đọc ma trận
void docMaTran(MaTran &matran) {
    cout << "Nhap so hang cua ma tran: ";
    cin >> matran.n;
    cout << "Nhap so cot cua ma tran: ";
    cin >> matran.m;

    cout << "Nhap cac phan tu cua ma tran:" << endl;
    for (int i = 0; i < matran.n; i++) {
        for (int j = 0; j < matran.m; j++) {
            cout << "Nhap phan tu tai vi tri [" << i << "][" << j << "]: ";
            cin >> matran.list[i][j];
        }
    }
}

// Viết hàm ghi (lưu) ma trận
void ghiMaTran(MaTran matran) {
    cout << "Ma tran vua nhap la:" << endl;
    for (int i = 0; i < matran.n; i++) {
        for (int j = 0; j < matran.m; j++) {
            cout << matran.list[i][j] << " ";
        }
        cout << endl;
    }
}

// Viết hàm đảo (hoán vị) dòng thứ k1 và k2 trong ma trận
void daoDong(MaTran &matran, int k1, int k2) {
    for (int j = 0; j < matran.m; j++) {
        int temp = matran.list[k1][j];
        matran.list[k1][j] = matran.list[k2][j];
        matran.list[k2][j] = temp;
    }
}

// Viết hàm xuất ra phần tử ở dòng thứ k
void xuatPhanTuDong(MaTran matran, int k) {
    cout << "Cac phan tu cua dong " << k << " la: ";
    for (int j = 0; j < matran.m; j++) {
        cout << matran.list[k][j] << " ";
    }
    cout << endl;
}

// Viết hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Viết hàm đếm xem ma trận có bao nhiêu số nguyên tố
int demSoNguyenTo(MaTran matran) {
    int count = 0;
    for (int i = 0; i < matran.n; i++) {
        for (int j = 0; j < matran.m; j++) {
            if (laSoNguyenTo(matran.list[i][j])) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    MaTran matran;
    docMaTran(matran);
    ghiMaTran(matran);

    int k1, k2;
    cout << "Nhap dong k1 can dao: ";
    cin >> k1;
    cout << "Nhap dong k2 can dao: ";
    cin >> k2;
    daoDong(matran, k1, k2);
    ghiMaTran(matran);

    int k;
    cout << "Nhap dong k can xuat: ";
    cin >> k;
    xuatPhanTuDong(matran, k);

    int soLuongNguyenTo = demSoNguyenTo(matran);
    cout << "So luong so nguyen to trong ma tran la: " << soLuongNguyenTo << endl;

    return 0;
}
