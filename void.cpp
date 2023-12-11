//DaySo
#include "Header.h"
void nhapds(dayso &a) {
	cout << "\nNhap phan tu :";
	cin >> a.n;
	for (int i = 0; i < a.n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a.list[i];
	}
}
void xuatds(dayso a) {
	for (int i = 0; i < a.n; i++)
		cout << a.list[i] << " ";
}
int timMin(dayso a)
{
	int min = a.list[0];
	for (int i = 0; i < a.n; i++)
		if (a.list[i] < min)
			min = a.list[i];
	return min;
}
int hamA(dayso a)
{
	int flag = 0;
	int kq;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] > 0)
			if (flag == 0) {
				kq = a.list[i];
				flag = 1;
			}
			else if (a.list[i]%3==0 && a.list[i] > kq)
				kq = a.list[i];
	return kq;
}
void sapBubbleSort(dayso &a) {
	int i, j, x;
	for( int i=0;i<a.n-1;i--)
		for ( int j=a.n-1;j<i;j--)
			if (a.list[i] < a.list[j - 1]) {
				x = a.list[j];
				a.list[j] = a.list[j - 1];
				a.list[j - 1] = x;
			}
}
dayso tronDS(dayso a, dayso b) {
	dayso c;
	int i = 0, j = 0, k = 0;
	c.n = a.n + b.n;
	while (i < a.n && j < b.n)
	{
		if (a.list[i] < b.list[j])
		{
			c.list[k] = a.list[i];
			i++;
		}
		else
		{
			c.list[k] = b.list[j];
			j++;
		}
		k++;
	}
	while (i < a.n)
	{
		c.list[k] = a.list[i];
		i++;
		k++;
	}
	while (j < b.n)
	{
		c.list[k] = b.list[j];
		j++;
		k++;
	}
	return c;
}
bool tachDS(dayso a, int index, dayso &b, dayso &c) {
	if (index<0 || index>a.n)
		return false;
	else
		b.n = 0;
	c.n = 0;
	for (int i = 0; i < index; i++) {
		a.list[i] = b.list[i];
		b.n++;  
	}
	for (int i = index; i < a.n; i++) {
		a.list[i] = c.list[i-1];
		c.n++;
	}
	return true;
}
//void xoatatca(dayso a, int &n)
//{
//	int max = a.list[MAX],i;
//	for (i = 1; i < a.n; i++)
//		if (a.list[i] > max)
//			max = a.list[i];
//	for (i = 0; i < a.n; i++)
//		if (a.list[i] == max)
//		{
//			for (int j = i; j < a.n; j++)
//
//				a.list[j] = a.list[j + 1];
//			n--;
//			i--;
//		}
//}
void ghep(dayso &a, dayso b, dayso c) {
	a.n = 0;
	for (int i = 0; i < b.n; i++) {
		a.list[a.n] = b.list[i];
		a.n++;
	}
	for (int i = 0; i < c.n; i++) {
		a.list[a.n] = c.list[i];
		a.n++;
	}
}
void daonguoc(dayso &a) {
	int n = a.n;
	for (int i = 0; i < n / 2; i++) {
		int tam = a.list[i];
		a.list[i] = a.list[n - i - 1];
		a.list[n - i - 1] = tam;
	}
}
__________________
#include "Header.h"
void main()
{
	dayso d;
	nhapds(d);
	xuatds(d);
	cout << "\nMin la: " << timMin(d);
	int kq = hamA(d);
	cout << "\nHamA la: " << kq;
	dayso a1, a2, a3;
	cout << "\nNhap day so thu 1:";
	nhapds(a1);
	xuatds(a1);
	cout << "\nNhap day so thu 2:";
	nhapds(a2);
	xuatds(a2);
	cout << "\nDay so thu 1 sap tang dan:";
	sapBubbleSort(a1);
	xuatds(a1);
	cout << "\nDay so thu 2 sap tang dan:";
	sapBubbleSort(a2);
	xuatds(a2);
	a3 = tronDS(a1, a2);
	cout << "\nDay so da duoc tron tang dan:";
	xuatds(a3);
	/*int index;
	cout << "";*/
	dayso a, b, c;
	cout << " day so sau khi ghep la : ";
	ghep(a, b, c);
	int n;
	/*cout << "day so sau khi xoa" << xoatatca(a, n);*/
	system("pause");
}
//Ma Tran Thuong
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX = 50;
struct MaTran {
	int list[MAX][MAX];
	int n;
	int m;

};
int docmatran(MaTran &a, const char *filename);
void inmatran(MaTran a);
int tinhtongle(MaTran a);
void thayThe(MaTran &a, int k);
void luumatran(MaTran &a, const char *filename);
int timmin(MaTran a);
int timduongmax(MaTran a);
void tongdong(MaTran a);
int maxdongk(MaTran a,int k);
int sumMAXdongk(MaTran a);
void swap(int &a, int &b);
void hoanvi(MaTran &a, int d1, int d2);
____________________
#include "Header.h"
int docmatran(MaTran &a, const char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		fscanf(fp, "%d", &a.n);
		fscanf(fp, "%d", &a.m);
		for (int i = 0; i < a.n; i++)
			for (int j = 0; j < a.m; j++)
				fscanf(fp, "%d", &a.list[i][j]);
		fclose(fp);
		return 1;
	}
	return 0;
}
void inmatran(MaTran a)
{
	for (int i = 0; i < a.n; i++)
	{
		cout << "\n";
		for (int j = 0; j < a.m; j++)
			cout << a.list[i][j] << "\t";
	}
}
int tinhtongle(MaTran a) {
	int tong = 0;
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.m; j++)
			if (a.list[i][j] % 2 != 0)
				tong += a.list[i][j];
	return tong;
}
void thayThe(MaTran &a, int k) {
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.m; j++)
			if (a.list[i][j] < 0) a.list[i][j] = k;
}
void luumatran(MaTran &a, const char *filename) {
	FILE *fp;
	fp = fopen(filename, "w");
	if (fp != NULL) {
		fprintf(fp, "%d", a.n); fprintf(fp, "\t");
		fprintf(fp, "%d", a.m);
		for (int i = 0; i < a.n; i++) {
			fprintf(fp, "\n");
			for (int j = 0; j < a.m; j++) {
				fprintf(fp, "%d", a.list[i][j]);
				fprintf(fp, "\t");
			}
		}
	}
}
int timmin(MaTran a) {
	int min = a.list[0][0];
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.m; j++)
			if (a.list[i][j] < min)
				min = a.list[i][j];
	return min;
}
int timduongmax(MaTran a) {
	bool flag = false;
	int max = a.list[0][0];
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.m; j++)
			if (a.list[i][j] > 0) {
				if (flag = false) {
					max = a.list[i][j];
					flag = true;
				}
				else if (a.list[i][j] > max)
					max = a.list[i][j];
			}
			
	return max;
}
void tongdong(MaTran a) {
	int tongdong = 0;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			tongdong += a.list[i][j];
		}
		cout << "\n Tong moi dong " << i << "la :" << tongdong;
	}

}
int maxdongk(MaTran a,int k) {
	int max = a.list[k][0];
	for (int i = 0; i < a.m; i++) {
			if (a.list[k][i]>max)
				max = a.list[k][i];
	}
	return max;

}
int sumMAXdongk(MaTran a)
{
	int sum = 0;
	for (int i = 0; i < a.n; i++)
		sum += maxdongk(a, i);
	return sum;
}
void swap(int &a, int &b) {
	int tam;
	tam = a;
	a = b;
	b = tam;
}
void hoanvi2dongbatky(MaTran &a, int d1, int d2)
{
	if (d1 == d2) {
		return;
	}
	if (d1 < 0 || d1 >= a.n || d2 < 0 || d2 >= a.n) {
		cout << "dong khong hop le :"<<endl;
		return;
	}
	for (int i = 0; i < a.n; i++)
		swap(a.list[d1][d2], a.list[d2][i]);
}
___________
#include"Header.h"
int main() {
	MaTran a;
	if (docmatran(a, "3_4.txt") == 1) {
		inmatran(a);
		cout << "\nTong Le:" << tinhtongle(a);
	}
	else cout << "khong doc duoc file"; 
	/*int k;
	cout << "\nNhap so k : ";
	cin >> k;*/
	thayThe(a, 19);
	luumatran(a, "text.txt");
	inmatran(a);
	int min = timmin(a);
	cout << "\n phan tu min sau khi tim la : " << min;
	cout << "\n phan tu duong ma sau khi tim la :" << timduongmax(a);
	tongdong(a);
	int k = 25;
	cout << "\n max dong k la :" << maxdongk(a, k);
	cout << "\n Tong max dong k la :" << sumMAXdongk(a);
	system("pause");
	return 0;
}
//Ma Tran Vuong
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const int MAX = 50;

struct MTV {
	int list[MAX][MAX];
	int n;
};
int docMaTran(MTV &a, const char *filename);
void inmatran(MTV a);
void xuatCheoChinh(MTV a);
int tinhTongCheoPhu(MTV a);
bool kiemTraLe(MTV a);
bool kiemTraBoi3(MTV a);
void TGTrenTrai(MTV a);
void TGDuoiPhaiCC(MTV a);
bool KiemTraAmTrenTrai(MTV a);
bool KiemTraChanTrenPhai(MTV a);
_______________________________________
#include "Header.h"
int docMaTran(MTV &a, const char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		fscanf(fp, "%d", &a.n);
		for (int i = 0; i < a.n; i++)
			for (int j = 0; j < a.n; j++)
				fscanf(fp, "%d", &a.list[i][j]);
		fclose(fp);
		return 1;
	}
	return 0;
}
void inmatran(MTV a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++)
			cout << a.list[i][j] << " " << endl;
	}
}
void xuatCheoChinh(MTV a) {
	cout << "\n Xuat cac phan tu tren cheo Chinh:";
	for (int i = 0; i < a.n; i++)
		cout << a.list[i][i] << " ";
}
int tinhTongCheoPhu(MTV a) {
	int tong = 0;
	for (int i = 0; i < a.n; i++)
		tong += a.list[i][a.n - i - 1];
	return tong;
}
bool kiemTraLe(MTV a) {
	bool flag = true;
	for (int i = 0; i < a.n; i++)
		for (int j = 0; j < a.n; j++)
			if (a.list[i][j] % 2 == 0)
				flag = false;
	return flag;
}
bool kiemTraBoi3(MTV a) {
	bool flag = false;
	for (int i = 0; i < a.n; i++)
		if (a.list[i][a.n - i - 1] % 3 == 0)
			flag = true;
	return flag;
}
void TGTrenTrai(MTV a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (i + j <= a.n - 1)
				cout << a.list[i][j] << "\t";
		}
		cout << endl;
	}
}
void TGDuoiPhaiCC(MTV a) {
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (i + j >= a.n - 1)
				cout << a.list[i][j] << "\t";
		}
		cout << endl;
	}
}
bool KiemTraAmTrenTrai(MTV a) {
	bool flag = false;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (i + j <= a.n - 1&& a.list[i][j]<0)
				flag = true;
		}
		
	}
	return flag;
}
bool KiemTraChanTrenPhai(MTV a) {
	bool flag = true;
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < a.n; j++) {
			if (i + j <= a.n - 1 && a.list[i][j] % 2 != 0) {
				flag = false;
				break;
			}
		}
	}
	return flag;
}
____________________________________
#include"Header.h"
int main() {
	MTV a;
	
	if (docMaTran(a, "mtv.txt") == 1) {
		inmatran(a);
		xuatCheoChinh(a);
		cout << "\nTong cac phan tu tren cheo phu:";
		cout << tinhTongCheoPhu(a);

	}
	else cout << "\n khong doc duoc ma tran";
	if (kiemTraLe(a) == true) {
		cout << "\n Ma tran hoan toan co so le" << endl;
	}
	else
		cout << "\n ma tran khong hoan toan co so le" << endl;
	if (kiemTraBoi3(a) == false) {
		cout << "\n cheo phu khong co boi 3" << endl;
	}
	else
		cout << "\ncheo phu co boi 3" << endl;

	cout << "\n TG tren ben trai la :" << endl;
	TGTrenTrai(a);
	cout << "\n TG tren ben trai la :" << endl;
	TGDuoiPhaiCC(a);
	if (KiemTraAmTrenTrai(a) == true) {
		cout << "\n ton tai phan tu am !" << endl;
	}
	else {
		cout << "\n khong ton tai phan tu am ! " << endl;
	}
	if (KiemTraChanTrenPhai(a) == true) {
		cout << "\n Tat ca cac phan tu la so chan";
	}
	else cout << "\n Khong ton tai phan tu chan";
	system("pause");
	return 0;
}
__________________________
//Con Tro
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 100;
void nhapChuoi(char *s);
char * daoChuoi(char *s);
char * chenchuoi(char *s,char *sub,int pos);
void hoanvi(char &x, char &y);
char * doichu(char *s);
void demchuoi(char *s);
char *doichu2(char *s);
void chuhoadau(char *s);
_________________________________
#include "Header.h"
void nhapChuoi(char *s) {
	cin.getline(s, MAX + 1);
}
char * daoChuoi(char *s) {
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		hoanvi(s[i], s[j]);
		i++;
		j--;
	}
	return s;
}

char * chenchuoi(char *s, char *sub, int pos) {
	if (pos < 0)pos = 0;
	if (pos > strlen(s))pos = strlen(s);
	char*t = new char[strlen(s + pos) + 1];
	strcpy(t, s + pos);
	s[pos] = '\0';
	strcat(s, sub);
	strcat(s, t);
	delete t;
	return s;
}
void hoanvi(char &x, char &y) {
	char temp = x;
	x = y;
	y = temp;
}
char * doichu(char *s){
	for (int i = 0; i < strlen(s); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
		s[i] = s[i] - 32;
	}
	}
	return s;
}
void demchuoi(char *s) {
	int demHoa=0, demThuong =0, demSo = 0;
	for (int i = 0; i < strlen(s); i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			demHoa++;
		else if ('a' <= s[i] && s[i] <= 'z')
			demThuong++;
		else if ('0' <= s[i] && s[i] <= '9')
			demSo++;
	}
	cout << "\nSo ky tu hoa :" << demHoa;
	cout << "\nSo ky tu thuong :" << demThuong;
	cout << "\nSo ky tu so la :"<< demSo;
}
char *doichu2(char *s) {
	for (int i = 0; i < strlen(s); i++) {
		if ('a' <= s[i] && s[i] <= 'z') 
			s[i] = s[i] - 32;
		else if ('A' <= s[i] && s[i] <= 'Z') 
			s[i] = s[i] + 32;
		}return s;
}
void chuhoadau(char *s) { 
	s[0] = toupper(s[0]); 
	while (strstr(s, " ") != NULL) { 
		s = strstr(s, " ") + 1; 
		s[0] = toupper(s[0]); 
	} 
	cout << "\nChu hoa dau sau khi doi :" << toupper;
}
_________________________________
#include "Header.h"
int main() {
	char s[MAX];
	cout << "\nNhap chuoi :";
	nhapChuoi(s);
	cout << "\nChuoi vua nhap:'" << s << "'";
	daoChuoi(s);
	cout << "\n\nChuoi dao nguoc :'" << s << "'";
	char s1[MAX], sub[MAX];
	int pos;
	cout << "\n\nNhap chuoi s:";
	nhapChuoi(s1);
	cout << "\nNhap chuoi con:";
	nhapChuoi(sub);
	cout << "\nNhap vi tri can chen :";
	cin >> pos;
	chenchuoi(s1, sub, pos);
	cout << "\nChuoi da chen :" << s1;
	cout << "\nChuoi sau khi doi thanh chu HOA la :"<<doichu(s);
	demchuoi(s);
	cout << "\nChuoi sau khi doi la :" << doichu2(s);
	chuhoadau(s);
	cout << endl << endl;
	return 0;
}
//Con tro 2
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
//De Qui
#include<iostream>
using namespace std;
const int MAX = 50;
struct DAYSO {
	int n;
	int list[MAX];
};
int Fibonaci(int n);
int GiaiThua(int n);
void xuatDaySo(DAYSO a);
int tongDaySo(DAYSO a, int i);
int tongViTriLe(DAYSO a, int i);
int tongLe(DAYSO a, int i);
int demChanDuong(DAYSO a, int i);
int timMax(DAYSO a, int n);
___________________________________
#include"Header.h"
void xuatDaySo(DAYSO a) {
	cout << endl;
	for (int i = 0; i < a.n; i++)
		cout << " " << a.list[i];
}
int Fibonaci(int n) {
	if (n == 1 || n == 2) return 1;
	return Fibonaci(n - 1) + Fibonaci(n - 2);
}
int GiaiThua(int n) {
	if (n == 0 || n == 1) return 1;
	return  n * GiaiThua(n- 1);
}
int tongDaySo(DAYSO a, int i) {
	if (i >= a.n) return 0;
	return a.list[i] + tongDaySo(a, i + 1);
}
int tongViTriLe(DAYSO a, int i) {
	if (i >= a.n) return 0;
	if (i % 2 != 0) return a.list[i] + tongViTriLe(a, i + 1);
	else return tongViTriLe(a, i + 1);
}
int tongLe(DAYSO a, int i) {
	if (i >= a.n) return 0;
	if (a.list[i] % 2 != 0) return a.list[i] + tongLe(a, i + 1);
	else return tongLe(a, i + 1);
}
int demChanDuong (DAYSO a, int i) {
	if (i >= a.n) return 0;
	if (a.list[i] % 2 != 0 && a.list[i] > 0) return 1 + demChanDuong(a, i + 1);
	else return demChanDuong(a, i + 1);
}
int timMax(DAYSO a, int n) {
	if (n == 1) return a.list[0];
	if (a.list[n-1] > timMax(a,n-1)) return a.list[n-1];
	else return timMax(a, n - 1);

}
int timMin(DAYSO a, int n) {
	if (n == 1) return a.list[0];
	if (a.list[n - 1] < timMin(a, n - 1)) return a.list[n - 1];
	else return timMin(a, n - 1);

}
bool KiemTra_ToanChan(DAYSO a, int n)
{
	while (n > 0)
	{
		int t = n % 10; 
		if (a.list[t] % 2 != 0)
			return false;
		n = n / 10;
	}
	return true;
}
bool KiemTra_ToanLe(DAYSO a, int n)
{
	while (n > 0)
	{
		int t = n % 10;
		if (a.list[t] % 2 == 0)
			return true;
		n = n / 10;
	}
	return false;
}
__________________________________
#include"Header.h"
int main() {
	int n;
	cout << "\nNhap n nguyen duong :";
	cin >> n;
	cout << n << "!=" << GiaiThua(n);
	cout << "\nSo thu" << n << "cua day Fibonaci la :" << Fibonaci(n);
	// khoi tao day so
	DAYSO a = { 10,{4,23,5,8,7,9,12,16,11,17} };
	cout << "\nDay so ban dau :";
	xuatDaySo(a);
	cout << "\nTong cac phan tu trong day so :" << tongViTriLe(a, 0);
	demChanDuong(a,0);
	cout << "\ndem cac phan tu chan trong day so :" << demChanDuong(a, 0);
	cout << "\nChu so max :" << timMax(a, n);
	cout << "\nChu so min :" << timMin(a, n);
	bool toanChan = KiemTra_ToanChan(a,n);
	if (toanChan == true)
		cout << "\nToan Chan";
	else
		cout << "\nKhong toan chan" << endl;
	bool toanLe = KiemTra_ToanLe(a, n);
	if (toanLe == false)
		cout << "\nToan Le";
	else
		cout << "\nKhong toan Le" << endl;
	return 0;
}
