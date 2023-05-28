#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

struct diem {
	int x, y;
};
istream& operator>>(istream& is, diem& d) {
	is >> d.x >> d.y;
	return is;
}
ostream& operator<<(ostream& os, diem d) {
	os << "(" << d.x << "," << d.y<<")";
	return os;
}
double khoangCach(diem d1, diem d2) {
	return sqrt((d2.x - d1.x) * (d2.x - d1.x) + (d2.y - d1.y) * (d2.y - d1.y));
}
bool operator==(diem d1, diem d2) {
	return d1.x == d2.x && d1.y == d2.y;
}
struct tamGiac {
	diem d1, d2, d3;
};
istream& operator>>(istream& is, tamGiac& tg) {
	is >> tg.d1 >> tg.d2 >> tg.d3;
	return is;
}
ostream& operator<<(ostream& os, tamGiac tg) {
	os << tg.d1 << tg.d2 << tg.d3;
	return os;
}
double chuVi(tamGiac tg) {
	return khoangCach(tg.d1, tg.d2) + khoangCach(tg.d2, tg.d3) + khoangCach(tg.d1, tg.d3);
}
double operator +(tamGiac tg1, tamGiac tg2) {
	return chuVi(tg1) + chuVi(tg2);
}
bool operator < (tamGiac tg1, tamGiac tg2) {
	return chuVi(tg1) < chuVi(tg2);
}
bool operator==(tamGiac tg1, tamGiac tg2) {
	return chuVi(tg1) == chuVi(tg2);
}
int main() {
	tamGiac  tg1, tg2;
	cin >> tg1>>tg2;
	cout << tg1 << endl << tg2 << endl;
	if (tg1 < tg2) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	cout << endl;
	if (tg1 == tg2) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}
	return 0;
}