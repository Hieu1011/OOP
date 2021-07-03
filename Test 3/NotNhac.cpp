#include <iostream>
#include<string>
using namespace std;
class Kyhieu //Lop ky hieu 
{
protected:
	char Caodo;
	float Truongdo;
public:
	Kyhieu() {}
	virtual void Nhap();
	virtual void Xuat();
	char getCaodo();
	float getTruongdo();
	void setCaodo(const char& _cao);
	void setTruongdo(const float& _truong);
	~Kyhieu(){}
};
void Kyhieu::Nhap()
{
	cout << "Nhap gia tri truong do (1/16.Not moc tu  1/8.Not moc tam  1/4.Not moc doi  1/2.Not moc don  1.Not den  2.Not trang  4.Not tron): ";
	cin >> Truongdo;
}
void Kyhieu::Xuat()
{
	if (Truongdo == 0.5)
		cout << Caodo << "1/2";
	else if (Truongdo == 0.25)
		cout << Caodo << "1/4";
	else if (Truongdo == 0.125)
		cout << Caodo << "1/8";
	else if (Truongdo == 0.0625)
		cout << Caodo << "1/16";
	else
		cout << Caodo << Truongdo;
}
char Kyhieu::getCaodo()
{
	return Caodo;
}
float Kyhieu::getTruongdo()
{
	return Truongdo;
}
void Kyhieu::setCaodo(const char& _cao)
{
	Caodo = _cao;
}
void Kyhieu::setTruongdo(const float& _truong)
{
	Truongdo = _truong;
}
class Notnhac:public Kyhieu // Lop not nhac
{
public:
	Notnhac(){}
	void Nhap();
	~Notnhac(){}
};
void Notnhac:: Nhap()
{
	cin.ignore();
	cout << "Nhap cao do not nhac (C.Do  D.Re  E.Mi  F.Fa  G.Sol  A.La  B.Si): ";
	cin >> Caodo;
	Kyhieu::Nhap();
}
class Daulang :public Kyhieu // Lop dau lang
{
public:
	Daulang() { Caodo = 'Z'; }
	~Daulang(){}
};
class Bannhac :public Notnhac,public Daulang // Lop ban nhac
{
protected:
	int n, dem = 0;
	Kyhieu* *a ;
public:
	~Bannhac() { n = 0; a = NULL; }
	void Nhap();
	void Timvadem();
	bool Timnot(const char&_not);
	void Notcaonhat();
	void Xuat();
};
void Bannhac::Nhap()
{
	cout << "Nhap so luong not nhac: ";
	cin >> n;
	a = new Kyhieu * [n];
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap loai ky hieu (1.Not nhac  2.Dau lang): ";
		cin >> temp;
		switch (temp)
		{
		case 1:
			a[i] = new Notnhac();
			a[i]->Nhap();
			if (a[i])
				break;
		case 2:
			a[i] = new Daulang();
			a[i]->Nhap();
			break;
		default:
			break;
		}
	}
}
void Bannhac::Timvadem()
{
	for (int i = 0; i < n; i++)
		if (a[i]->getCaodo() == 'Z' && a[i]->getTruongdo() == 1)
			dem++;
	cout << "So dau lang den trong ban nhac: " << dem << endl;
}
bool Bannhac::Timnot(const char& _not)
{
	for (int i = 0; i < n; i++)
		if (a[i]->getCaodo() == _not)
			return true;
	return false;
}
void Bannhac::Notcaonhat()
{
	for (int i = 0; i < n; i++)
	{
		if (Timnot('B'))
		{
			cout << "Not cao nhat la: Si " << endl;
			break;
		}
		else if (Timnot('A'))
		{
			cout << "Not cao nhat la: La " << endl;
			break;
		}
		else if (Timnot('G'))
		{
			cout << "Not cao nhat la: Sol " << endl;
			break;
		}
		else if (Timnot('F'))
		{
			cout << "Not cao nhat la: Fa " << endl;
			break;
		}
		else if (
			not('E'))
		{
			cout << "Not cao nhat la: Mi " << endl;
			break;
		}
		else if (Timnot('D'))
		{
			cout << "Not cao nhat la: Re " << endl;
			break;
		}
		else if (Timnot('C'))
		{
			cout << "Not cao nhat la: Do " << endl;
			break;
		}
	}
}
void Bannhac::Xuat()
{
	cout << "Ban nhac la: ";
	for (int i = 0; i < n - 1; i++)
	{
		a[i]->Xuat();
		cout << " - ";
	}
	a[n - 1]->Xuat();
	cout << endl;
}
int main() 
{
	Bannhac a;
	cout << "--------Menu--------" << endl;
	cout << "1. Soan mot ban nhac" << endl;
	cout << "2. Tim va dem co bao nhieu dau lang den" << endl;
	cout << "3. Cho biet not nhac co cao do cao nhat trong ban nhac" << endl;
	cout << "-1. Thoat" << endl;
	cout << "--------------------" << endl;
	int x;
	cout << "Nhap lua chon: ";
	cin >> x;
	while (x != -1)
	{
		switch (x)
		{
		case 1:
			a.Nhap();
			a.Xuat();
			break;
		case 2:
			a.Timvadem();
			break;
		case 3:
			a.Notcaonhat();
			break;
		}
		cout << "Nhap lua chon: ";
		cin >> x;
	}
	return 0;
}