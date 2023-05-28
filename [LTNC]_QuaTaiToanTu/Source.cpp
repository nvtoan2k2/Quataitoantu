#include<iostream>
#include<vector>
using namespace std;

void tachSo(int x) {
	vector<int> so;
	while (x > 0) {
		int a = x % 10;
	
		x /= 10;
		so.push_back(a);
	}
	
	
	for (int i = (so.size()-1); i >= 0; i--) {
		if (i % 2 == 0) {
			cout << so[i];
		}
	}
}
int main() {
	int x;
	cin >> x;
	tachSo(x);
	return 0;
}