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
