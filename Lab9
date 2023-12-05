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
	if (i % 2 != 0) return a.list[i] + tongLe(a, i + 1);
	else return tongLe(a, i + 1);
}
int demChanDuong (DAYSO a, int i) {
	if (i >= a.n) return 0;
	if (a.list[i] % 2 != 0 && a.list[i] > 0) return a.list[i] + demChanDuong(a, i + 1);
	else return demChanDuong(a, i + 1);
}
int timMax(DAYSO a, int n) {
	if (n == 1) return a.list[0];
	if (a.list[n-1] > timMax(a,n-1)) return a.list[n-1];
	else return timMax(a, n - 1);

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
	cout << "\dem cac phan tu chan trong day so :" << demChanDuong(a, 0);
	return 0;
}
