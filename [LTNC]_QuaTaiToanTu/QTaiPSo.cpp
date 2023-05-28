#include<iostream>
using namespace std;

struct phanSo {
	int tu, mau;
};
istream& operator >>(istream& is, phanSo& p) {
	is >> p.tu >> p.mau;
	return is;
}
ostream& operator <<(ostream& os, phanSo p) {
	os << p.tu << "/" << p.mau;
	return os;
}
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
phanSo rutGon(phanSo p){
	int x = gcd(p.tu, p.mau);
	p.tu /= x;
	p.mau /= x;
	return p;

}
phanSo operator +(phanSo ps1, phanSo ps2) {
	phanSo kq;
	kq.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
	kq.mau = ps1.mau * ps2.mau;
	return rutGon(kq);
}

bool operator ==(phanSo ps1, phanSo ps2) {
	return ps1.tu * ps2.mau == ps1.mau * ps2.tu;
}
bool operator !=(phanSo ps1, phanSo ps2) {
	return ps1.tu * ps2.mau != ps1.mau * ps2.tu;
}
int main() {
	phanSo ps1, ps2, ps3;
	cin >> ps1 >> ps2;
	ps3 = ps1 + ps2;
	cout << ps3;
	return 0;
}