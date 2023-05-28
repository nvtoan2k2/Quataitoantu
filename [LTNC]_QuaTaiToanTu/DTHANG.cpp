#include<iostream>
#include<math.h>
using namespace std;

struct dThang {
	int a, b, c;
};
istream& operator>>(istream& is, dThang& d) {
	is >> d.a >> d.b >> d.c;
	return is;
}
ostream& operator<<(ostream& os, dThang d) {
	if (d.a != 0) {
		if (d.a == 1) {
			if (d.b > 0 && d.c > 0) os << "x + " << d.b << "y + " << d.c << " = 0";
			if (d.b < 0 && d.c > 0) os << "x - " << abs(d.b) << "y + " << d.c << " = 0";
			if (d.b > 0 && d.c < 0) os << "x + " << d.b << "y - " << abs(d.c) << " = 0";
			if (d.b < 0 && d.c < 0) os << "x - " << abs(d.b) << "y - " << abs(d.c) << " = 0";
			if (d.b == 0 && d.c > 0) os << "x + " << d.c << " = 0";
			if (d.b == 0 && d.c < 0) os << "x - " << abs(d.c) << " = 0";
			if (d.b > 0 && d.c == 0) os << "x + " << d.b << "y" << " = 0";
			if (d.b < 0 && d.c == 0) os << "x - " << abs(d.b) << "y" << " = 0";
			if (d.b == 1 && d.c == 0) os << "x - " << "y" << " = 0";
		}
		else{
			if (d.b > 0 && d.c > 0) os << d.a << "x + " << d.b << "y + " << d.c << " = 0";
			if (d.b < 0 && d.c > 0) os << d.a << "x - " << abs(d.b) << "y + " << d.c << " = 0";
			if (d.b > 0 && d.c < 0) os << d.a << "x + " << d.b << "y - " << abs(d.c) << " = 0";
			if (d.b < 0 && d.c < 0) os << d.a << "x - " << abs(d.b) << "y - " << abs(d.c) << " = 0";
			if (d.b == 0 && d.c > 0) os << d.a << "x + " << d.c << " = 0";
			if (d.b == 0 && d.c < 0) os << d.a << "x - " << abs(d.c) << " = 0";
			if (d.b > 0 && d.c == 0) os << d.a << "x + " << d.b << "y" << " = 0";
			if (d.b < 0 && d.c == 0) os << d.a << "x - " << abs(d.b) << "y" << " = 0";
		}
	}
	else {
		if (d.c > 0) os << d.b << "y + " << d.c << " = 0";
		if (d.c < 0) os << d.b << "y - " << abs(d.c) << " = 0";
		if (d.c == 0) os << d.b << "y" << " = 0";
	}
	return os;
}
bool operator==(dThang d1, dThang d2) {
	return d1.a == d2.a && d1.b == d2.b && d1.c == d2.c;
}
struct phanSo {
	int tu, mau;
	void operator = (phanSo p) {
		tu = p.tu;
		mau = p.mau;
	}
	void operator = (int x) {
		tu = x;
		mau = 1;
	}
	phanSo() {
		tu = 0;
		mau = 1;
	}
};
istream& operator>>(istream& is, phanSo& p) {
	is >> p.tu >> p.mau;
	return is;
}
ostream& operator<<(ostream& os, phanSo p) {
	if (p.mau == 1) {
		os << p.tu;
	}
	else if (p.tu > 0 && p.mau < 0) {
		os << -p.tu << "/" << -p.mau;
	}
	else if (p.tu < 0 && p.mau < 0) {
		os << p.tu<< "/" << -p.mau;
	}
	else if(p.mau > 0)
	{
		os << p.tu << "/" << p.mau;
	}
	return os;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
phanSo rutGon(phanSo p) {
	int x = gcd(p.tu, p.mau);
	p.tu /= x;
	p.mau /= x;
	
	return p;
}
void viTriTuongDoi(dThang d1, dThang d2) {
	int d, dx, dy;
	//if (d1.c < 0 || d2.c < 0) {
	//	d1.c = -d1.c;
	//	d2.c = -d2.c;
	//}
		d = d1.a * d2.b - d1.b * d2.a;
		dx = (-d1.c) * d2.b - d1.b * ( - d2.c);
		dy = d1.a * ( - d2.c) - ( - d1.c) * d2.a;
	//	cout << d <<" "<< dx <<" " << dy<<endl;
		if (d1.a * d2.a + d1.b * d2.b == 0) {
			cout << "V \n";
			phanSo kq1, kq2;
			kq1.tu = dx;
			kq1.mau = d;
			kq2.tu = dy;
			kq2.mau = d;
			cout << "(" << rutGon(kq1) << "," << rutGon(kq2) << ")";
		}
		else

			if (d != 0) {
				cout << "C \n";
				phanSo kq1, kq2;
				kq1.tu = dx;
				kq1.mau = d;
				kq2.tu = dy;
				kq2.mau = d;
				cout << "(" << rutGon(kq1) << "," << rutGon(kq2) << ")";
			}
	else if(d == 0)
	{
		cout << "T \n"<<0;

	}
	else if (dx != 0 && dy != 0) {
		cout << "S \n";
		double x, y;
		x = 0;
		y = -(float)d1.c / d1.b;
		double M = (abs(d2.a * x + d2.b * y + d2.c)) / (sqrt(d2.a * d2.a + d2.b * d2.b));
		cout << round(M * 1000) / 1000;

	}
	
}
int main() {
	dThang d1, d2;
	cin >> d1>>d2;
	cout << d1<<endl<<d2<<endl;
	viTriTuongDoi(d1, d2);

	return 0;
}