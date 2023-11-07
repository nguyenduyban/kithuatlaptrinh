
#include <iostream>
using namespace std;
int giaiptbat1(int a, int b, double &x1);
double tinh2muN(int n);
int giaiPTB2(int a, int b, int c, double &x1, double &x2);

______________
#include "Header.h"

//viet lai pt bat 1
int giaiptbat1(int a, int b, double &x1) {
	if (a == 0) return 0;
	else
	x1 = 1.0*-b / a;
	
}
// viet so mu am
double tinh2muN(int n) {
	double s = 1;
	int i = 1;
	if (n < 0) 
		while (i <= n)
			s *= 1.0 / 2;
		i++;
		return s;

}
int giaiPTB2(int a, int b, int c, double &x1, double &x2) {
	if (a == 0, b == 0, c == 0)
		return 3;
	else {
		double delta = b * b - 4 * a*c;
		if (delta < 0) {
			x1 = x2 = 0.0;
			return 0;
		}
		else if (delta == 0) {
			x1 = x2 = -b / (2 * a);
			return 1;
		}
		else {
			delta = sqrt(delta);
			x1 = (-b + delta) / (2 * a);
			x2 = (-b - delta) / (2 * a);
			return 2;
		}
	}
}
_______________________
#include "Header.h"
void main() {
	int a, b,c;
	double x1,x2;
	do {
	cout << "nhap a :";
	cin >> a;
	cout << "nhap b : ";
	cin >> b;
	cout << "nhap c : ";
	cin >> c;
	} while (!a);
	int ptbat1 = giaiptbat1(a, b, x1);
	if (ptbat1 == 0) cout << "\nkhong chia cho so 0 !";
	else { cout << "\nnghiem cua pt bat 1 la :" << x1; }
	int n;
	double s=1;
	cout << "\n nhap n :";
	cin >> n;
	cout << "\n mu la : " << s << tinh2muN(n);
	int ptbat2 = giaiPTB2(a, b, c, x1, x2);
	if (ptbat2 == 0) {
		cout << "\nPhuong trinh da vo nghiem";
	}
	else if (ptbat2 == 1) {
		cout << "\nPhuong trinh da cho co nghiem kep x=" << x1;
	}
	else {
		cout << "\nPhuong trinh da cho co hai nghiem phan biet" << endl;
		cout << "\nx1=" << x1 << endl;
		cout << "\nx2=" << x2 << endl;
	}
}
