#include <iostream>
#include<string>
using namespace std;
struct Ngay
{
	int Ngay, Thang, Nam;
};
class Nguoisohuu
{
protected:
	string Hoten, CMND, Diachi;
	int Namsinh;
public:
	Nguoisohuu(){}
	void Nhap();
	void Xuat();
};
void Nguoisohuu::Nhap()
{
	cout << "\tNhap ho ten : ";
	getline(cin, Hoten);
	cout << "\tNhap nam sinh: ";
	cin >> Namsinh;
	cin.ignore();
	cout << "\tNhap CMND: ";
	getline(cin, CMND);
	cout << "\tNhap dia chi thuong tru: ";
	getline(cin, Diachi);
}
void Nguoisohuu::Xuat()
{
	cout << "\tHoten: " << Hoten << endl;
	cout << "\tNam sinh: " << Namsinh << endl;
	cout << "\tSo CMND: " << CMND << endl;
	cout << "\tDia chi thuong tru: " << Diachi << endl;
}
class Sohong
{
protected:
	string Sgcn;
	Nguoisohuu *Nguoi;
	int Songuoi,Sothua, Sotobando;
	string Diachidat;
	double Dientich;
	Ngay Ngaycap;
	double Thue;
public:
	Sohong(){}
	virtual void Nhap();
	virtual void Xuat();
	virtual double Tinhthue();
	virtual int getLoai() = 0;
};

void Sohong::Nhap()
{
	cin.ignore();
	cout << "Nhap so giay chung nhan: ";
	getline(cin, Sgcn);
	cout << "Nhap so nguoi so huu: ";
	cin >> Songuoi;
	Nguoi = new Nguoisohuu[Songuoi];
	cin.ignore();
	for (int i = 0; i < Songuoi; i++)
	{
		cout << "Nguoi thu " << i + 1 << " :" << endl;
		Nguoi[i].Nhap();
	}
	cout << "Nhap so thua dat: ";
	cin >> Sothua;
	cout << "Nhap so to ban do: ";
	cin >> Sotobando;
	cin.ignore();
	cout << "Nhap dia chi thua dat: ";
	getline(cin, Diachidat);
	cout << "Nhap dien tich dat: ";
	cin >> Dientich;
	cout << "Nhap ngay cap: ";
	cin >> Ngaycap.Ngay >> Ngaycap.Thang >> Ngaycap.Nam;
	cout << "Nhap don gia thue: ";
	cin >> Thue;
}
void Sohong::Xuat()
{
	cout << "So giay chung nhan: " << Sgcn << endl;
	for (int i = 0; i < Songuoi; i++)
	{
		cout << "Thong tin nguoi thu " << i + 1 << ": " << endl;
		Nguoi[i].Xuat();
	}
	cout << "So thua dat: " << Sothua << endl;
	cout << "So to ban do: " << Sotobando << endl;
	cout << "Dia chi dat: " << Diachidat << endl;
	cout << "Dien tich dat: " << Dientich << endl;
	cout << "Ngay cap: " << Ngaycap.Ngay << "/" << Ngaycap.Thang << "/" << Ngaycap.Nam << endl;
	cout << "Don gia thue: " << Thue << endl;
}
double Sohong::Tinhthue()
{
	return Dientich * Thue;
}
class Datnongnghiep :public Sohong
{
protected:
	int Thoihan;
public:
	void Nhap();
	void Xuat();
	int getNam();
	int getLoai();
};
void Datnongnghiep::Nhap()
{
	Sohong::Nhap();
	cout << "Nhap thoi han su dung: ";
	cin >> Thoihan;
}
void Datnongnghiep::Xuat()
{
	Sohong::Xuat();
	cout << "Thoi han su dung: " << Thoihan << endl;
	cout << "Tien thue phai dong: " << Tinhthue() << endl;
}
int Datnongnghiep::getNam()
{
	return Thoihan;
}
int Datnongnghiep::getLoai()
{
	return 1;
}
class Datphinongnghiep :public Sohong
{
public:
	void Xuat();
	int getLoai();
};
void Datphinongnghiep::Xuat()
{
	Sohong::Xuat();
	cout << "Tien thue phai dong: " << Tinhthue() << endl;
}
int Datphinongnghiep::getLoai()
{
	return 2;
}
int main()
{
	int n;
	Sohong** a;
	cout << "--------YC1--------" << endl;
	cout << "Nhap so luong So Hong can cap: ";
	cin >> n;
	a = new Sohong*[n];
	for (int i = 0; i < n; i++)
	{
		int temp;
		cout << "1. Thua dat nong nghiep \t2. Thua dat phi nong nghiep" << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:
			a[i] = new Datnongnghiep();
			a[i]->Nhap();
			break;
		case 2:
			a[i] = new Datphinongnghiep();
			a[i]->Nhap();
			break;
		default:
			break;
		}
	}
	cout << "--------DANH SACH SO HONG--------" << endl;
	for (int i = 0; i < n; i++)
	{
		a[i]->Xuat();
	}
	cout << "--------YC2--------" << endl;
	double max = a[0]->Tinhthue();
	int vt = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i]->Tinhthue() > max)
			vt = i;
	}
	cout << "Thua dat co thue cao nhat la: " << endl;
	a[vt]->Xuat();
	cout << "--------YC3--------" << endl;
	for (int i = 0; i < n; i++)
	{
		if (a[i]->getLoai() == 1)
			if (((Datnongnghiep*)a[i])->getNam() < 2020)
				a[i]->Xuat();
	}
	return 0;
}