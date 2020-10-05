#include<iostream>
using namespace std;

class SoPhuc {
	friend ostream& operator<<(ostream&, SoPhuc&);
	friend istream& operator>>(istream&, SoPhuc&);
	private:
		int thuc;
		int ao;
	public:
		SoPhuc(int = 0, int = 0);
		SoPhuc operator+(SoPhuc a);
		SoPhuc operator-(SoPhuc a);
		SoPhuc operator*(SoPhuc a);
		SoPhuc operator/(SoPhuc a);
		int operator == (SoPhuc a);
		int operator != (SoPhuc a);
};
SoPhuc::SoPhuc(int _thuc, int _ao) {
	thuc = _thuc;
	ao = _ao;
}
SoPhuc SoPhuc::operator+(SoPhuc a) {
	SoPhuc kq;
	kq.thuc = thuc + a.thuc;
	kq.ao = ao + a.ao;
	return kq;
}
SoPhuc SoPhuc::operator-(SoPhuc a) {
	SoPhuc kq;
	kq.thuc = thuc - a.thuc;
	kq.ao = ao - a.ao;
	return kq;
}
SoPhuc SoPhuc::operator*(SoPhuc a) {
	SoPhuc kq;
	kq.thuc = thuc * a.thuc - ao * a.ao;
	kq.ao = thuc * a.ao + ao * a.thuc;
	return kq;
}
SoPhuc SoPhuc::operator/(SoPhuc a) {
	SoPhuc kq;
	kq.thuc = thuc * a.thuc + ao * a.ao / (a.thuc * a.thuc + a.ao * a.ao);
	kq.ao = ao * a.thuc - thuc * a.ao / (a.thuc * a.thuc + a.ao * a.ao);
	return kq;
}
int SoPhuc::operator==(SoPhuc a) {
	if ((thuc == a.thuc) && (ao == a.ao)) {
		return 1;
	}
	else return 0;
}
int SoPhuc::operator!=(SoPhuc a) {
	if ((thuc != a.thuc)||(ao != a.ao)) {
		return 1;
	}
	return 0;
}
ostream& operator<<(ostream& os, SoPhuc &a) {
	if (a.thuc == 0 && a.ao == 0) {
		os << "0" << endl;
	}
	else if (a.thuc == 0 && a.ao != 0) {
		os << a.ao << "i" << endl;
	}
	else if (a.thuc != 0 && a.ao == 0) {
		os << a.thuc << endl;
	}
	else if (a.thuc != 0 && a.ao < 0) {
		os << a.thuc << " " << a.ao << "i" << endl;
	}
	else os << a.thuc << " + " << a.ao << "i" << endl;
	return os;
}
istream& operator>>(istream& is, SoPhuc &a) {
	cout << "Nhap phan thuc : ";
	is >> a.thuc;
	cout << "Nhap phan ao : ";
	is >> a.ao;
	return is;
}
int main() {
	int luachon;
	int k = 0;
	SoPhuc a1, a2;
	SoPhuc c;
	cout << "1.Cong 2 so phuc\n2.Tru 2 so phuc\n2.Nhan 2 so phuc\n4.Chia 2 so phuc\n5.Toan tu so sanh\n6.Thoat\n";
	while (k == 0) {
		cout << "Hay nhap lua chon : ";
		cin >> luachon;
		switch (luachon) {
			case 1: {
				cin >> a1;
				cin >> a2;
				c = a1 + a2;
				cout << "Tong : " <<c;
				break;
			}
			case 2: {
				cin >> a1;
				cin >> a2;
				c = a1 - a2;
				cout << "Tong : " <<c;
				break;
			}
			case 3: {
				cin >> a1;
				cin >> a2;
				c = a1 * a2;
				cout << "Tong : " <<c;
				break;
			}
			case 4: {
				cin >> a1;
				cin >> a2;
				c = a1 / a2;
				cout << "Tong : " <<c;
				break;
			}
			case 5: {
				cin >> a1;
				cin >> a2;
				if (a1 == a2) {
					cout << "2 so phuc bang nhau" << endl;
				}
				if (a1 != a2) {
					cout << "2 so phuc khong bang nhau" << endl;
				}
				break;
			}
			case 6: {
				k = 1;
				break;
			}
		}
	}
}