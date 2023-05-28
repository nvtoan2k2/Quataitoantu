#include<iostream>
using namespace std;

struct BacNhat {
	int a, b;
};
istream& operator>>(istream& is, BacNhat& bn) {
	is >> bn.a >> bn.b;
	return is;
}
ostream& operator<<(ostream& os, BacNhat bn) {
	os << bn.a << "x+" << bn.b;
	return os;
}
int tinhGiaTri(BacNhat bn, int x) {
	return bn.a * x + bn.b;
}
BacNhat operator+(BacNhat bn1, BacNhat bn2) {
	BacNhat kq;
	kq.a = bn1.a + bn2.a;
	kq.b = bn1.b + bn2.b;
	return kq;
}
bool operator ==(BacNhat bn1, BacNhat bn2) {
	return bn1.a + bn1.b == bn2.a + bn2.b;
}
int main() {
	BacNhat bn1, bn2;
	int x;
	cin >> bn1 >> bn2;
	cin >> x;
	cout << bn1 << endl << bn2 << endl;
	cout << bn1 << "+" << bn2 << "=" << bn1 + bn2 << endl;
	cout << tinhGiaTri(bn1, x);
	cout << endl;
	cout << tinhGiaTri(bn2, x);
	cout << endl;
	if (bn1 == bn2) {
		cout << "TRUE";
	}
	else {
		cout << "FALSE";
	}

	return 0;
}