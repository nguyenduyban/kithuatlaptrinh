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
