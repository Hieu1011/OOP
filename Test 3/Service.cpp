#include<iostream>
#include<string>
using namespace std;
class Package
{
protected:
	int CMND, Loai, Thang, Phicoban;
	string Name;
	bool PT;
public:
	Package() { Loai = 0; }
	virtual void Nhap();
	virtual void Xuat();
	void setPhicoban(const int& _Phicoban) { Phicoban = _Phicoban; }
	int getPhicoban() { return Phicoban; }
	virtual int getPT() { return 0; }
	virtual int TinhTong() { return 0; }
	string getName() { return Name; }
};
void Package::Nhap()
{
	cin.ignore();
	cout << "Nhap ho ten khach hang: ";
	getline(cin, Name);
	cout << "Nhap CMND: ";
	cin >> CMND;
	cout << "Nhap so thang dang ki: ";
	cin >> Thang;
} 
void Package::Xuat()
{
	cout << "Ho ten khach hang: " << Name << endl;
	cout << "CMND: " << CMND << endl;
	cout << "So thang dang ki dich vu: " << Thang << endl;
}
class Premium :public Package
{
protected:
	int Solop;
	bool Xonghoi;
public:
	Premium() { Loai = 1; Phicoban = 1000; }
	void Nhap();
	void Xuat();
	int getChiphi();
	int getXonghoi();
	int TinhTong();
};
void Premium::Nhap()
{
	Package::Nhap();
	cout << "Nhap so lop dang ki: ";
	cin >> Solop;
	cout << "Chon dich vu xong hoi:\t 1.Co \t0.Khong" << endl;
	cin >> Xonghoi;
	cout << "Chon ho tro PT:\t 1.Co \t0.Khong" << endl;
	cin >> PT;
}
void Premium::Xuat()
{
	Package::Xuat();
	cout << "Goi dich vu: Premium" << endl;
	cout << "So lop dang ki: " << Solop << endl;
	if (Xonghoi)
		cout << "Dich vu xong hoi: Co" << endl;
	else cout << "Dich vu xong hoi: Khong" << endl;
	if (PT)
		cout << "Ho tro PT: Co" << endl;
	else cout << "Ho tro PT: Khong" << endl;
	cout << "Tong tien: " << TinhTong()<<" nghin dong" << endl;
}
int Premium::getChiphi() { return 0; }
int Premium::getXonghoi() { return 0; }
int Premium::TinhTong() { return (getPhicoban() + getChiphi() + getXonghoi() + getPT()) * Thang; }
class Basic :public Package
{
protected:
	int Solop;
public:
	Basic() { Loai = 2; Phicoban = 500; }
	void Nhap();
	void Xuat();
	int getChiphi();
	int getPT();
	int TinhTong();
};
void Basic::Nhap()
{
	Package::Nhap();
	cout << "Nhap so lop dang ki: ";
	cin >> Solop;
	cout << "Chon ho tro PT:\t 1.Co \t0.Khong" << endl;
	cin >> PT;
}
void Basic::Xuat()
{
	Package::Xuat();
	cout << "Goi dich vu: Basic" << endl;
	cout << "So lop dang ki: " << Solop << endl;
	if (PT)
		cout << "Ho tro PT: Co" << endl;
	else cout << "Ho tro PT: Khong" << endl;
	cout << "Tong tien: " << TinhTong() << " nghin dong" << endl;
}
int Basic::getChiphi() { return 100 * Solop; }
int Basic::getPT() { return 100; }
int  Basic::TinhTong() { return (getPhicoban() + getChiphi() + getPT()) * Thang; }
class Non_member :public Package
{
public:
	Non_member() { Loai = 3; Phicoban = 200; }
	void Nhap();
	void Xuat();
	int getPT();
	int TinhTong();
};
void Non_member::Nhap()
{
	Package::Nhap();
	cout << "Chon ho tro PT:\t 1.Co \t0.Khong" << endl;
	cin >> PT;
}
void Non_member::Xuat()
{
	Package::Xuat();
	cout << "Goi dich vu: Non_member" << endl;
	if (PT)
		cout << "Ho tro PT: Co" << endl;
	else cout << "Ho tro PT: Khong" << endl;
	cout << "Tong tien: " << TinhTong() << " nghin dong" << endl;
}
int Non_member::getPT() { return 200; }
int Non_member::TinhTong() { return (getPhicoban() + getPT()) * Thang; }
int main()
{
	cout << "--------YC1--------" << endl;
	cout << "Nhap so luong khach hang dang ki: ";
	int n;
	cin >> n;
	Package** A = new Package * [n];
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap lua chon goi:\t 1.Premium \t2.Basic \t3.Non_member" << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:
			A[i] = new Premium();
			A[i]->Nhap();
			break;
		case 2:
			A[i] = new Basic();
			A[i]->Nhap();
			break;
		case 3:
			A[i] = new Non_member();
			A[i]->Nhap();
			break;
		default:
			break;
		}
	}
	int max = A[0]->TinhTong();
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		A[i]->Xuat();
		cout << "___________________" << endl;
		if (max < A[i]->TinhTong())
		{
			max = A[i]->TinhTong();
			j = i;
		}
	}
	cout << "--------YC2--------" << endl;
	cout << "___Thong tin khach hang chi tieu nhieu nhat___ " << endl;
	A[j]->Xuat();
	return 0;
}