#include<iostream>
using namespace std;

struct diem {
	int x, y;
	diem() {
		x = 0;
		y = 0;
	}
};
istream& operator>>(istream& is, diem& d) {
	is >> d.x >> d.y;
	return is;
}
ostream& operator<<(ostream& os, diem d) {
	os << "(" << d.x << "," << d.y << ")";
	return os;
}
bool operator==(diem d1, diem d2) {
	return d1.x == d2.x && d1.y == d2.y;
}
bool operator<(diem d1, diem d2) {
	return d1.x < d2.x || (d1.x == d2.x && d1.y < d2.y);
}

diem operator+(diem d1, diem d2) {
	diem kq;
	kq.x = d1.x + d2.x;
	kq.y = d1.y + d2.y;
	return kq;
}
struct mangDiem {
	int n;
	diem a[100];
	diem& operator[](int i) {
		return a[i];
	}
	void operator = (mangDiem md) {
		n = md.n;
		for (int i = 0; i < n; i++)
			a[i] = md[i];
	}
	mangDiem() {
		n = 0;;
	}
};
istream& operator>>(istream& is, mangDiem& md) {
	diem d;
	while (is >> d) md[md.n++] = d;
	return is;
}
ostream& operator<<(ostream& os, mangDiem md) {
	for (int i = 0; i < md.n; i++) {
		os << md[i];
	}
	return os;
}
int diemCong(diem d) {
	return d.x + d.y;
}
diem timMax(mangDiem m) {
	diem max = m[0];
	
	for (int i = 0; i < m.n; i++) {
		if (max< m[i]) {
			max= m[i];
		}
	}
	return max;
}
diem tong(mangDiem m) {
	diem d;
	for (int i = 0; i < m.n; i++) {
		d.x += m[i].x;
		d.y += m[i].y;
	}
	return d;
}
int main() {
	mangDiem m;
	cin >> m;
	cout << timMax(m);
	cout << endl;
	cout << tong(m);
	return 0;
}