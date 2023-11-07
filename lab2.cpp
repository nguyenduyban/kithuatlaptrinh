#include <iostream>
using namespace std;
const int MAX = 50;
struct Dayso {
	int list[MAX];
	int n;
	int x;
};
void nhapds(Dayso &a);
void xuatds(Dayso a);
int tinhtongds(Dayso a);

int tichds(Dayso a);
int demptduong(Dayso a);
int tongchan(Dayso a);
int tinhTichPTChiSoChan(Dayso a);
int demPTChiaHet3Va5(Dayso a);
bool KTSNT(int x);
int TongPTSNT(Dayso a);
int demam(Dayso a);
int demduong(Dayso a);
int soluongbang0(Dayso a);
bool KiemTraSHT(int x);
int demPTSHT(Dayso a);
bool tangdan(Dayso a, int n);
void check(Dayso a, int n);
__________________________
#include "Header.h"
void nhapds(Dayso &a) {

		cout << "\n Nhap so phan tu :";
		cin >> a.n;
		for (int i = 0; i < a.n; i++) {
			cout << "\na[" << i << "]=";
		cin >> a.list[i];
	}
}
void xuatds(Dayso a) {
	for (int i = 0; i < a.n; i++)
	cout << a.list[i] << " ";

}
int tinhtongds(Dayso a) {
	int tong = 0;
	for (int i = 0; i < a.n; i++)
		tong = tong + a.list[i];
	return tong;
}
int tichds(Dayso a) {
	int tich = 1;
	for (int i = 1; i < a.n; i++)
		tich = tich * a.list[i];
	return tich;
}
int demptduong(Dayso a) {
	int dem = 0;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] > 0)
			dem++;
	return dem;
}
int tongchan(Dayso a) {
	int s = 0;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] % 2 == 0)
			s = s + a.list[i];
			return s;
}
int tinhTichPTChiSoChan(Dayso a) {
	int t = 1;
	for (int i = 1; i < a.n; i++)
		if (a.list[i] % 2 == 0)
			t = t * a.list[i];
	return t;
}
int demPTChiaHet3Va5(Dayso a) {
	int dem = 0;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] % 3 == 0 && a.list[i] % 5 == 0)
			dem++;
	return dem;
}
bool KTSNT(int x)
{

	if (x < 2)
		return false;
	for (int i = 2; i <= x / 2; i++)
		if (x%i == 0)
			return false;
	return true;
}

int TongPTSNT(Dayso a)
{
	int tong = 0;
	for (int i = 0; i < a.n; i++)
		if (KTSNT(a.list[i]) == true)
			tong = tong + a.list[i];
	return tong;
	return -1;
}
int demam(Dayso a) {
	int demam = 0;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] < 0)
			demam ++;
	return demam;
}
int demduong(Dayso a) {
	int demduong = 0;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] > 0)
			demduong++;
	return demduong;
}
int soluongbang0(Dayso a) {
	int soluong = 0;
	for (int i = 0; i < a.n; i++)
		if (a.list[i] == 0)
			soluong ++;
	return soluong;
}
bool KiemTraSHT(int x)
{
	int i, tong = 0;
	for (i = 1; i < x; i++)
		if (x%i == 0)
			tong = tong + i;
	if (tong == x)
		return true;
	return false;
}

int demPTSHT(Dayso a)
{
	int dem = 0;
	for (int i = 0; i < a.n; i++)
	{
		if (KiemTraSHT(a.list[i]) == true)
			dem++;
	}
	return dem;
	return -1;
}
bool tangdan(Dayso a)
{
	for (int i = 0; i < a.n - 1; i++)
	{
		if (a.list[i] > a.list[i + 1])
			return false;
	}
	return true;
}
void check(Dayso a) {
	if (tangdan(a)) {
		cout << "\n Day la day so tang dan";
	}
	else
		cout << "\n Day khong phai la day so tang dan";
}
_________________________
#include "header.h"
void main() {
	Dayso a;
	nhapds(a);
	xuatds(a);
	cout << "\ntong day so la : " << tinhtongds(a);
	cout << "\ntich day so la : " << tichds(a);
	cout << "\nDem phan tu duong :" << demptduong(a);
	cout << "\nTong chan :" << tongchan(a);
	cout << "\n tich phan tu chan : " << tinhTichPTChiSoChan(a);
	cout << "\n dem pt chia het 3va5 " << demPTChiaHet3Va5(a);
	int kq;
	kq = TongPTSNT(a);
	cout << "\nTong cac phan tu la so nguyen to co trong mang la: " << kq;
	cout << "\n dem am : " << demam(a);
	cout << "\n dem am : " << demduong(a);
	cout << "\n so luong = 0  : " << soluongbang0(a);
	int kqq;
	kqq = demPTSHT(a);
	cout << "\n cac phan tu la so hoan thien co trong mang la: " << kqq;
	
}

_____________________
