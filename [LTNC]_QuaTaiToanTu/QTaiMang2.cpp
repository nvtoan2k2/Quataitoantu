#include <iostream>
using namespace std;

struct mang {
	int n;
	int a[100];
};
istream& operator>>(istream& is, mang& m) {
	is >> m.n;
	for (int i = 0; i < m.n; i++) {
		is >> m.a[i];
	}
	return is;
}
ostream& operator<<(ostream& os, mang m) {
	for (int i = 0; i < m.n; i++) {
		os << m.a[i]<< " ";
	}
	return os;
}
int Max(int a, int b) {
	if (a < b) return b;
	return a;
}
mang operator+(mang m1, mang m2) {
	mang kq;
	kq.n = Max(m1.n, m2.n);
	for (int i = 0; i < kq.n; i++) {
		if (i >= m1.n) {
			m1.a[i] = 0;
		}
		if (i >= m2.n) {
			m2.a[i] = 0;
		}
		kq.a[i] = m1.a[i] + m2.a[i];
	}
	return kq;
}

int main() {
	mang m1, m2;
	cin >> m1 >> m2;
	cout << m1 + m2;
	return 0;
}