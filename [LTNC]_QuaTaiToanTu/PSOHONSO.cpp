#include<iostream>

using namespace std;
struct PhanSo {
	int tu, mau;

};
istream& operator>>(istream& is, PhanSo& ps) {
	is >> ps.tu >> ps.mau;
	return is;
}
ostream& operator<<(ostream& os, PhanSo ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
bool operator !=(PhanSo ps1, PhanSo ps2) {
	return ps1.tu * ps2.mau != ps1.mau * ps2.tu;
}
struct honSo {
	int x;
	PhanSo p;
};
istream& operator>>(istream& is, honSo& hs) {
	is >> hs.x >> hs.p;
	return is;
}
ostream& operator<<(ostream& os, honSo hs) {
	os << hs.x << " " << hs.p;
	return os;
}
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
PhanSo rutGon(PhanSo ps) {
	int x = gcd(ps.tu, ps.mau);
	ps.tu /= x;
	ps.mau /= x;
	return ps;
}
PhanSo toiGianHSPS(honSo hs) {
	PhanSo ps;
	ps.tu = hs.x * hs.p.mau + hs.p.tu;
	ps.mau = hs.p.mau;
	return rutGon(ps);
}
honSo toiGianHSHS(honSo hs) {
	PhanSo ps = toiGianHSPS(hs);
	honSo s;
	s.x = ps.tu / ps.mau;
	s.p.tu = ps.tu % ps.mau;
	s.p.mau = ps.mau;
	return s;
}
bool operator !=(honSo hs1, honSo hs2) {
	return hs1.x != hs2.x && hs1.p.tu != hs2.p.tu && hs1.p.mau != hs2.p.mau;
}
int tongCacThanhPhan(honSo hs) {
	return hs.x + hs.p.tu + hs.p.mau;
}
bool operator >(honSo hs1, honSo hs2) {
	return tongCacThanhPhan(hs1) > tongCacThanhPhan(hs2);
}
int main() {
	honSo hs1, hs2;
	string x;
	cin >> hs1>>hs2;
	cin >> x;
	if (hs1 != hs2) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	cout << endl;
	if (hs1 > hs2) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	cout << endl;
	if (x == "true") {
		cout << toiGianHSHS(hs1);
		cout << endl;
		cout << toiGianHSHS(hs2);
	}
	else {
		cout << toiGianHSPS(hs1);
		cout << endl;
		cout << toiGianHSPS(hs2);
	}
	return 0;
}