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
