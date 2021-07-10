#include<iostream>
#include<string>
using namespace std;
class Culi
{
protected:
	int He, Level;
	double Dame;
public:
	Culi() {}
	virtual void Nhap();
	virtual void Xuat();
	bool TuongKhac(Culi &b);
	void setHe(const int& _He) { He = _He; }
	void setLevel(const int& _Level) { Level = _Level; }
	void setST(const int& _Dame) { Dame = _Dame; }
	int getHe() { return He; }
	int getLevel() { return Level; }
	virtual double getST() { return Dame; }
	~Culi(){}
};
void Culi::Nhap()
{
	cout << "-> Nhap he (1.Kim  2.Moc  3.Thuy  4.Hoa  5.Tho): ";
	cin >> He;
}
bool Culi::TuongKhac(Culi &b)
{
	double stAB = this->getST();
	double stBA = b.getST();
	if ((this->He == 1 && b.getHe() == 2) || (this->He == 2 && b.getHe() == 5) ||
		(this->He == 3 && b.getHe() == 4) || (this->He == 4 && b.getHe() == 1) ||
		(this->He == 5 && b.getHe() == 3))
	{
		stAB = this->getST() * 120 / 100;
		stBA = b.getST() * 80 / 100;
	}
	else {
		if ((b.getHe() == 1 && this->He == 2) || (b.getHe() == 2 && this->He == 5) ||
			(b.getHe() == 3 && this->He == 4) || (b.getHe() == 4 && this->He == 1) ||
			(b.getHe() == 5 && this->He == 3))
		{
			stBA = b.getST() * 120 / 100;
			stAB = this->getST() * 80 / 100;
		}
	}
	if ((this->He == 1 && b.getHe() == 3) || (this->He == 2 && b.getHe() == 4) ||
		(this->He == 3 && b.getHe() == 2) || (this->He == 4 && b.getHe() == 5) ||
		(this->He == 5 && b.getHe() == 1))
	{
		stAB = this->getST() * 110 / 100;
	}
	else
	{
		if ((b.getHe() == 1 && this->He == 3) || (b.getHe() == 2 && this->He == 4) ||
			(b.getHe() == 3 && this->He == 2) || (b.getHe() == 4 && this->He == 5) ||
			(b.getHe() == 5 && this->He == 1))
		{
			stBA =b.getST() * 110 / 100;
		}
		if (stAB > stBA)
			return true;
		return false;
	}
}
void Culi::Xuat()
{
	switch (He)
	{
	case 1:
		cout << "He: Kim" << endl;
		break;
	case 2:
		cout << "He: Moc" << endl;
		break;
	case 3:
		cout << "He: Thuy" << endl;
		break;
	case 4:
		cout << "He: Hoa" << endl;
		break;
	case 5:
		cout << "He: Tho" << endl;
		break;
	default:
		break;
	}
}
class Character :public Culi 
{
protected:
	string MonPhai;
public:
	Character() {}
	void Nhap();
	double getST();
	void Xuat();
	~Character(){}
};
void Character::Nhap()
{
	int chose;
	cout << "Nhap thong tin nhan vat:" << endl;
	Culi::Nhap();
	switch (He)
	{
	case 1:
		cout << "---> Chon mon phai:\t 1.Thieu Lam \t2.Thien Vuong" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
			MonPhai = "Thieu Lam";
			break;
		case 2:
			MonPhai = "Thien Vuong";
			break;
		default:
			break;
		}
		break;
	case 2:
		cout << "---> Chon mon phai:\t 1.Ngu Doc giao \t2.Duong Mon" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
			MonPhai = "Ngu Doc giao";
			break;
		case 2:
			MonPhai = "Duong Mon";
			break;
		default:
			break;
		}
		break;
	case 3:
		cout << "---> Chon mon phai:\t 1.Nga My \t2.Thuy Yen mon" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
			MonPhai = "Nga My";
			break;
		case 2:
			MonPhai = "Thuy Yen mon";
			break;
		default:
			break;
		}
		break;
	case 4:
		cout << "---> Chon mon phai:\t 1.CaiBang \t2.Thien Nhan giao" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
			MonPhai = "Cai Bang";
			break;
		case 2:
			MonPhai = "Thien Nhan giao";
			break;
		default:
			break;
		}
		break;
	case 5:
		cout << "---> Chon mon phai:\t 1.Con Lon \t2.Vo Dang" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
			MonPhai = "Con Lon";
			break;
		case 2:
			MonPhai = "Vo Dang";
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	cout << "-> Nhap cap do nhan vat: ";
	cin >> Level;
}
double Character::getST()
{
	Dame = Level * 5;
	return Dame;
}
void Character::Xuat()
{
	cout << "Thong tin Nhan vat:" << endl;
	Culi::Xuat();
	cout << "Mon phai: " << MonPhai << endl;
	cout << "Level: " << Level << endl;
	cout << "Sat thuong: " << getST() << endl;
}
class Creep :public Culi
{
protected:
	int chose;
public:
	Creep() {}
	void Nhap();
	double getST();
	void Xuat();
	~Creep(){}
};
void Creep::Nhap()
{
	cout << "Nhap thong tin quai vat: " << endl;
	Culi::Nhap();
	cout << "---> Nhap loai quai:\t 1.Quai thuong \t2.Quai boss" << endl;
	cin >> chose;
	cout << "-> Nhap cap do quai vat: ";
    cin >> Level;
}
double Creep::getST()
{
	switch (chose)
	{
	case 1:
		Dame = Level * 3;
		return Dame;
		break;
	case 2:
		Dame = Level * 7;
		return Dame;
	default:
		break;
	}
}
void Creep::Xuat()
{
	cout << "Thong tin Quai vat: " << endl;
	switch (chose)
	{
	case 1:
		cout << "Loai: Quai thuong" << endl;
		break;
	case 2:
		cout << "Loai: Quai boss" << endl;
		break;
	default:
		break;
	}
	Culi::Xuat();
	cout << "Level: " << Level << endl;
	cout << "Sat thuong: " << getST() << endl;
}
class Quanli :public Character, public Creep
{
protected:
	int n;
	Culi** A;
public:
	Quanli() { n = 0; A = NULL; }
	void Nhap();
	void Xuat();
	void STLN();
	void TK();
	~Quanli(){}
};
void Quanli::Nhap()
{
	cout << "--------YC1--------" << endl;
	cout << "Nhap so luong nguoi va quai: ";
	cin >> n;
	A = new Culi * [n];
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << "+ Nhap lua chon:\t 1.Nhan vat \t2.Quai vat" << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:
			A[i] = new Character();
			A[i]->Nhap();
			break;
		case 2:
			A[i] = new Creep();
			A[i]->Nhap();
			break;
		default:
			break;
		}
	}
}
void Quanli::Xuat()
{
	for (int i = 0; i < n; i++)
		A[i]->Xuat();
}
void Quanli::STLN()
{
	cout << "--------YC2--------" << endl;
	int max = A[0]->getST();
	int iMax = 0;
	for (int i = 1; i < n; i++)
	{
		if (max < A[i]->getST())
		{
			max = A[i]->getST();
			iMax = i;
		}
	}
	cout << "==> Phan tu co muc sat thuong cao nhat: " << iMax + 1 << endl;
	A[iMax]->Xuat();
}
void Quanli::TK()
{
	cout << "--------YC3--------" << endl;
	int x,y;
	cout << "Chon phan tu tuong tac: ";
	cin >> x >> y;
	bool flag = A[x - 1]->TuongKhac(*A[y - 1]);
	if (flag)
		cout << x << " co sat thuong cao hon " << y << endl;
	else
		cout << y << " co sat thuong cao hon " << x << endl;
}
int main()
{
	Quanli a;
	a.Nhap();
	a.Xuat();
	a.STLN();
	a.TK();
	return 0;
}