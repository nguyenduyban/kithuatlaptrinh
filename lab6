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
