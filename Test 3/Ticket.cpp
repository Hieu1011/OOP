#include<iostream>
#include<string>
using namespace std;
class Ticket
{
protected:
	string Ma, Hoten;
	int Loai, Namsinh, Sotrochoi, Gia;
public:
	Ticket() { Loai = 0; }
	virtual void Nhap();
	virtual void Xuat();
	void setLoai(const int& _Loai) { Loai = _Loai; }
	void setNamsinh(const int& _Namsinh) { Namsinh = _Namsinh; }
	void setGia(const int& _Gia) { Gia = _Gia; }
	int getLoai() { return Loai; }
	int getNamsinh() { return Namsinh; }
	int getGia() { return Gia; }
};
void Ticket::Nhap()
{
	cout << "Nhap ma ve: ";
	cin.ignore();
	getline(cin, Ma);
	cout << "Nhap ho ten nguoi chu ve: ";
	getline(cin, Hoten);
	cout << "Nhap nam sinh nguoi chu ve: ";
	cin >> Namsinh;
	cout << "Nhap so tro choi nguoi tham gia: ";
	cin >> Sotrochoi;
	while (Sotrochoi < 0 || Sotrochoi>30)
	{
		cout << "So tro choi khong hop le!. Nhap lai!" << endl;
		cin >> Sotrochoi;
	}
}
void Ticket::Xuat()
{
	cout << "Ma ve: " << Ma << endl;
	cout << "Ho ten chu ve: " << Hoten << endl;
	cout << "Nam sinh chu ve: " << Namsinh << endl;
	cout << "So tro choi tham gia: " << Sotrochoi << endl;
}
class PackageTicket :public Ticket
{
public:
	PackageTicket() { Loai = 1; Gia = 200000; }
};
class PartialTicket :public Ticket
{
public:
	PartialTicket() { Loai = 2; Gia = 70000; }
	int Tongtien();
};
int PartialTicket::Tongtien()
{
	return Gia + 20000 * Sotrochoi;
}
int main()
{
	cout << "--------YC1--------" << endl;
	cout << "Nhap so ve da ban: ";
	int n;
	cin >> n;
	Ticket** A = new Ticket * [n];
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << "--> Nhap loai ve:\t 1. Ve tron goi \t2. Ve tung phan" << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:
			A[i] = new PackageTicket();
			A[i]->Nhap();
			break;
		case 2:
			A[i] = new PartialTicket();
			A[i]->Nhap();
			break;
		default:
			break;
		}
	}
	cout << "--------YC2--------" << endl;
	int S = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i]->getLoai() == 1)
			S += A[i]->getGia();
		else
			S += ((PartialTicket*)A[i])->Tongtien();
	}
	cout << "Tong tien ve cong vien thu duoc: "<<S << endl;
	cout << "--------YC3--------" << endl;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i]->getLoai() == 2)
			dem++;
	}
	cout << "So ve ban duoc la ve tung phan la: " << dem << endl;
	return 0;
}