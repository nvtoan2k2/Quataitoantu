#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct soChanLe {
	string n;
};
int tachSo(soChanLe so) {
	int tmp = 0;
	for (int i = 0; i < so.n.size(); i++) {
		if (i % 2 == 0) {
			tmp = tmp * 10 + (int)so.n[i] - 48;
		}
	}
	return tmp;
}
bool operator<(soChanLe so1, soChanLe so2) {
	return tachSo(so1) < tachSo(so2);
}
istream& operator>>(istream& is, soChanLe& s) {
	is >> s.n;
	return is;
}
ostream& operator<<(ostream& os, soChanLe s) {
	os << tachSo(s);
	return os;
}
int tongThanhPhan(soChanLe so, int x) {
	int tmp = 0;
	if (x == 0) {
		for (int i = 0; i < so.n.size(); i++) {
			if (i % 2 == 0) {
				tmp += (int)so.n[i] - 48;
			}
		}
	}
	else
	{
		for (int i = 0; i < so.n.size(); i++) {
			if (i % 2 != 0) {
				tmp += (int)so.n[i] - 48;
			}
		}
	}
	return tmp;
}
int main() {
	soChanLe so1, so2;
	int x;
	cin >> so1>>so2>>x;
	cout<<so1<<endl<<so2<<endl;
	if (so1 < so2) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	cout << endl;
	cout << tongThanhPhan(so1,x);
	cout << endl;
	cout << tongThanhPhan(so2, x);
	return 0;
}