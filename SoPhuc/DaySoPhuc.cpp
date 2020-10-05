#include"SoPhuc.cpp"

class DaySoPhuc {
	friend ostream& operator<<(ostream&, DaySoPhuc&);
	friend istream& operator>>(istream&, DaySoPhuc&);
private:
	int size;
	SoPhuc *dsp;
public:
	DaySoPhuc();
	int find(SoPhuc a, DaySoPhuc& b);
	DaySoPhuc(const DaySoPhuc& obj);
	SoPhuc operator [](int);
};
DaySoPhuc::DaySoPhuc() {
	size = 0;
	dsp = NULL;
}
SoPhuc DaySoPhuc::operator [](int x) {
	if (x > size) {
		return -65536;
	}
	else {
		return dsp[x];
	}
}
DaySoPhuc::DaySoPhuc(const DaySoPhuc &a) {
	size = a.size;
	dsp = new SoPhuc[size];
	for (int i = 0; i < size; i++) {
		dsp[i] = a.dsp[i];
	}
}
ostream& operator<<(ostream& os, DaySoPhuc& a) {
	cout << "Cac phan tu cua day " << endl;
	for (int i = 0; i < a.size; i++) {
		os << a.dsp[i] << endl;
	}
	return os;
}
istream& operator>>(istream& is, DaySoPhuc& a) {
	cout << "Nhap so phan tu cua day";
	cin >> a.size;
	a.dsp = new SoPhuc[a.size];
	cout << "Nhap cac phan tu cua day";
	for (int i = 0; i < a.size; i++) {
		is >> a.dsp[i];
	}
	return is;
}
int DaySoPhuc::find(SoPhuc a, DaySoPhuc& b) {
	for (int i = 0; i < b.size; i++) {
		if (a == b.dsp[i]) {
			return i;
		}
	}
	return 0;
}
int main() {
	DaySoPhuc a;
	cin >> a;
	cout << a;
}