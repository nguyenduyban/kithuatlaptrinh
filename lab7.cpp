#include <iostream>
using namespace std;

struct NhanVien
{ 
	char maNhanVien[10];
	char hoTen[50];
	float luongCanBan;
	float heSoLuong;
};
void nhapNhanVien(NhanVien &nhanVien);
void xuatNhanVien(NhanVien nhanVien);
float tinhLuong(NhanVien nhanVien);
char* tachTen(NhanVien nhanVien);
const int MAX = 100;
struct CongTy
{
	int soNhanVien;
	NhanVien danhSach[MAX];
};
void nhapCongTy(CongTy &cTy);
void xuatCongTy(CongTy cTy);
float tinhTongLuong(CongTy cTy);
float timLuongCaoNhat(CongTy cTy);
CongTy timNhanVienCoLuongCaoNhat(CongTy cTy);
bool timNhanVienTheoMa(CongTy cTy, NhanVien &nhanVien);
bool timNhanVienTheoTen(CongTy cTy, CongTy &dsKetQua);
CongTy sapXepTangDanTheoLuong(CongTy cTy);
CongTy sapXepTangDanTheoTen(CongTy cTy);
void hienThiMenu();
_____________________________________________
#include "Header.h"

void nhapNhanVien(NhanVien &nhanVien)
{
	fflush(stdin);
	cout << "Ma nhan vien:";
	cin.ignore();
	cin.getline(nhanVien.maNhanVien, 10);
	cout << "Ho ten:";
	cin.getline(nhanVien.hoTen, 50);
	cout << "Luong can ban:";
	cin >> nhanVien.luongCanBan;
	cout << "He so luong:";
	cin >> nhanVien.heSoLuong;
}
void xuatNhanVien(NhanVien nv)
{
	cout << "Ma nhan vien:" << nv.maNhanVien << endl;
	cout << "Ho ten:" << nv.hoTen << endl;
	cout << "Luong can ban:" << nv.luongCanBan << endl;
	cout << "He so luong:" << nv.heSoLuong << endl;
}
float tinhLuong(NhanVien nhanVien)
{
	return nhanVien.luongCanBan*nhanVien.heSoLuong;
}
char *tachTen(NhanVien nhanVien)
{
	std::string hoTen(nhanVien.hoTen);
	int viTriKhoangTrangCuoi = hoTen.find_last_of(" ");
	std::string ten = hoTen.substr(viTriKhoangTrangCuoi + 1);
	char *tenNhanVien = new char[ten.length() + 1];
	strcpy_s(tenNhanVien, ten.length() + 1, ten.c_str());
	return tenNhanVien;
}
void nhapCongTy(CongTy &cTy)
{
	cout << "Nhap so luong nhan vien:";
	cin >> cTy.soNhanVien;
	cout << "Nhap danh sach nhan vien:" << endl;
	for (int i = 0; i < cTy.soNhanVien; i++)
	{
		cout << "Nhap nhan vien thu " << i << endl;
		nhapNhanVien(cTy.danhSach[i]);
	}
}
void xuatCongTy(CongTy cTy)
{
	cout << "\nSo luong nhan vien:" << cTy.soNhanVien <<
		endl;
	cout << "Danh sach nhan vien:" << endl;
	for (int i = 0; i < cTy.soNhanVien; i++)
		xuatNhanVien(cTy.danhSach[i]);
}
float tinhTongLuong(CongTy cTy)
{
	float tongLuong = 0;
	for (int i = 0; i < cTy.soNhanVien; i++)
	{
		tongLuong = tongLuong + tinhLuong(cTy.danhSach[i]);
	}
	return tongLuong;
}
bool timNhanVienTheoMa(CongTy cTy, NhanVien &nhanVien)
{
	bool ketQua = false;
	char maCanTim[10];
	fflush(stdin);
	cout << "Nhap ma can tim:";
	cin.getline(maCanTim, 10);
	for (int i = 0; i < cTy.soNhanVien; i++)
	{
		if (strcmp(maCanTim, cTy.danhSach[i].maNhanVien) ==
			0)
		{
			ketQua = true;
			nhanVien = cTy.danhSach[i];
			break;
		}
	}
	return ketQua;
}
bool timNhanVienTheoTen(CongTy cTy, CongTy &dsKetQua)
{
	char tenTim[50];
	cout << "Nhap ten nhan vien can tim: ";
	cin.getline(tenTim, 50);
	dsKetQua.soNhanVien = 0;
	for (int i = 0; i < cTy.soNhanVien; i++)
	{
		if (strstr(cTy.danhSach[i].hoTen, tenTim) != NULL)
		{
			dsKetQua.danhSach[dsKetQua.soNhanVien] = cTy.danhSach[i];
			dsKetQua.soNhanVien++;
		}
	}
	return dsKetQua.soNhanVien > 0;
}
float timLuongCaoNhat(CongTy cTy)
{
	float maxLuong = tinhLuong(cTy.danhSach[0]);
	for (int i = 1; i < cTy.soNhanVien; i++)
	{
		float luong = tinhLuong(cTy.danhSach[i]);
		if (luong > maxLuong)
		{
			maxLuong = luong;
		}
	}
	return maxLuong;
}
CongTy timNhanVienCoLuongCaoNhat(CongTy cTy)
{
	CongTy ketQua;
	ketQua.soNhanVien = 0;
	float luongMax = timLuongCaoNhat(cTy);
	for (int i = 0; i < cTy.soNhanVien; i++)
	{
		if (tinhLuong(cTy.danhSach[i]) == luongMax)
		{
			ketQua.danhSach[ketQua.soNhanVien] = cTy.danhSach[i];
			ketQua.soNhanVien++;
		}
	}
	return ketQua;
}

CongTy sapXepTangDanTheoLuong(CongTy cTy)
{
	CongTy ketQua = cTy;
	for (int i = 0; i < ketQua.soNhanVien - 1; i++)
	{
		for (int j = i + 1; j < ketQua.soNhanVien; j++)
		{
			if (tinhLuong(ketQua.danhSach[i]) > tinhLuong(ketQua.danhSach[j]))
			{
				NhanVien temp = ketQua.danhSach[i];
				ketQua.danhSach[i] = ketQua.danhSach[j];
				ketQua.danhSach[j] = temp;
			}
		}
	}
	return ketQua;
}

CongTy sapXepTangDanTheoTen(CongTy cTy)
{
	CongTy ketQua = cTy;
	for (int i = 0; i < ketQua.soNhanVien - 1; i++)
	{
		for (int j = i + 1; j < ketQua.soNhanVien; j++)
		{
			if (strcmp(tachTen(ketQua.danhSach[i]), tachTen(ketQua.danhSach[j])) > 0)
			{
				NhanVien temp = ketQua.danhSach[i];
				ketQua.danhSach[i] = ketQua.danhSach[j];
				ketQua.danhSach[j] = temp;
			}
		}
	}
	return ketQua;
}
void hienThiMenu()
{
	int chon = 0;
	NhanVien nhanVien;
	CongTy cTy;
	CongTy dsKetQua;
	float tongLuong = 0;
	float luongCaoNhat = 0;
	bool ketQuaTimTheoMa = false;
	bool ketQuaTimTheoTen = false;
	do
	{
		cout << "\n0 - Thoat chuong trinh";
		cout << "\n1 - Nhap danh sach nhan vien";
		cout << "\n2 - Xuat danh sach nhan vien";
		cout << "\n3 - Tinh tong luong";
		cout << "\n4 - Tim luong cao nhat";
		cout << "\n5 - Tim nhan vien co luong cao nhat";
		cout << "\n6 - Tim nhan vien theo ma";
		cout << "\n7 - Tim nhan vien theo ten";
		cout << "\nVui long chon: ";
		cin >> chon;
		cin.ignore(); // Clear the input buffer
		switch (chon)
		{
		case 0:
			break;
		case 1:
			nhapCongTy(cTy);
			break;
		case 2:
			xuatCongTy(cTy);
			break;
		case 3:
			tongLuong = tinhTongLuong(cTy);
			cout << "Tong luong cong ty: " << tongLuong << endl;
			break;
		case 4:
			luongCaoNhat = timLuongCaoNhat(cTy);
			cout << "Luong cao nhat: " << luongCaoNhat << endl;
			break;
		case 5:
			timNhanVienCoLuongCaoNhat(cTy);
			break;
		case 6:
			ketQuaTimTheoMa = timNhanVienTheoMa(cTy, nhanVien);
			if (ketQuaTimTheoMa)
			{
				xuatNhanVien(nhanVien);
			}
			else
			{
				cout << "Khong tim thay!" << endl;
			}
			break;
		case 7:
			ketQuaTimTheoTen = timNhanVienTheoTen(cTy, dsKetQua);
			if (ketQuaTimTheoTen)
			{
				xuatCongTy(dsKetQua);
			}
			else
			{
				cout << "Khong tim thay!" << endl;
			}
			break;
		default:
			cout << "Ban chon sai, vui long chon lai!" << endl;
			break;
		}
	} while (chon != 0);
}

________________________________
#include "Header.h"

void main() {
	hienThiMenu();
}
