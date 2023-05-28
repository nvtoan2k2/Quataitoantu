#include<iostream>
using namespace std;

struct phanSo {
	int tu, mau;
	phanSo() {
		tu = 0;
		mau = 1;
	}
};
istream& operator >> (istream& is, phanSo& ps) {
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator << (ostream& os, phanSo ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator ==(phanSo ps1, phanSo ps2) {
	return ps1.tu * ps2.mau == ps1.mau * ps2.tu;
}
bool operator !=(phanSo ps1, phanSo ps2) {
	return ps1.tu * ps2.mau != ps1.mau * ps2.tu;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
phanSo Rutgon(phanSo ps) {
	int x = gcd(ps.tu, ps.mau);
	ps.tu /= x;
	ps.mau /= x;
	return ps;
}
phanSo operator+(phanSo ps1, phanSo ps2) {
	phanSo kq;
	kq.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
	kq.mau = ps1.mau * ps2.mau;
	return Rutgon(kq);
}
struct mang {
	int n; 
	phanSo a[100];
	phanSo& operator [] (int i) {
		return a[i];
	}
	void operator = (mang m) {
		n = m.n;
		for (int i = 0; i < n; i++)
			a[i] = m[i];
	}
	mang() {
		n = 0;
	}
};
istream& operator>>(istream& is, mang& m) {
	phanSo tmp;
	while (is >> tmp) m[m.n++] = tmp;
	return is;
}
ostream& operator<<(ostream& os, mang m) {
	for (int i = 0; i < m.n; i++) {
		os << m[i] << " ";
	}
	return os;
}
int main() {
	mang m;
	phanSo tong;
	cin >> m;
	//cout << m;
	for (int i = 0; i < m.n; i++) {
		tong = tong + m.a[i];
	}
	cout << Rutgon(tong);
	
	return 0;
}