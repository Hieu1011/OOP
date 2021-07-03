#include<iostream>
using namespace std;
class Gate
{
protected:
	int Loai;
public:
	Gate() {}
	virtual void Nhap() = 0;
	virtual int Return() = 0;
	int getLoai();
};
int Gate::getLoai()
{
	return Loai;
}
class BGate:public Gate
{
protected:
	int price, number;
public:
	BGate() { Loai = 1; }
	void Nhap();
	int Return();
};
void BGate::Nhap()
{
	cout << "Nhap so hang cua cong: ";
	cin >> number;
	cout << "Nhap don gia cua hang: ";
	cin >> price;
}
int BGate::Return ()
{
	return price * number;
}
class AGate :public Gate
{
protected:
	int iMind;
public:
	AGate() { Loai = 2; }
	void Nhap();
	int Return();
};
void AGate::Nhap()
{
	cout << "Nhap tri tue cau hoi cua nha hien triet: ";
	cin >> iMind;
}
int AGate::Return()
{
	return iMind;
}
class PGate :public Gate
{
protected:
	int iPower;
public:
	PGate() { Loai = 3; }
	void Nhap();
	int Return();
};
void PGate::Nhap()
{
	cout << "Nhap chi so suc manh cua dung sy: ";
	cin >> iPower;
}
int PGate::Return()
{
	return iPower;
}
int main()
{
	int n;
	cout << "--------YC1--------" << endl;
	cout << "Nhap so cong cua lau dai: ";
	cin >> n;
	Gate** A = new Gate * [n];
	for (int i = 0; i < n; i++)
	{
		cout << "---> Chon loai cong: \t1. Cong giao thuong \t2. Cong hoc thuat \t3. Cong suc manh" << endl;
		int temp;
		cin >> temp;
		switch (temp)
		{
		case 1:
			A[i] = new BGate();
			A[i]->Nhap();
			break;
		case 2:
			A[i] = new AGate();
			A[i]->Nhap();
			break;
		case 3:
			A[i] = new PGate();
			A[i]->Nhap();
			break;
		default:
			break;
		}
	}
	cout << "--------YC2--------" << endl;
	int Sotien, Tritue, Sucmanh;
	cout << "Nhap so tien ban dau cua Hoang Tu: ";
	cin >> Sotien;
	cout << "Nhap chi so tri tue cua Hoang Tu: ";
	cin >> Tritue;
	cout << "Nhap chi so suc manh ban dau cua Hoang Tu: ";
	cin >> Sucmanh;
	int i = 0;
	cout << "-------------------" << endl;
	while (Sotien > 0 && Tritue > 0 && Sucmanh > 0 && i < n)
	{
		if (A[i]->getLoai() == 1)
			Sotien -= A[i]->Return();
		else if (A[i]->getLoai() == 2)
		{
			if (A[i]->Return() > Tritue)
			{
				cout << "Hoang Tu da khong cuu duoc Cong Chua! Hoang Tu non vai =))" << endl;
				return 0;
			}
		}
		else Sucmanh -= A[i]->Return();
		i++;
	}
	if (Sotien <= 0 || Sucmanh <= 0)
	{
		cout << "Hoang Tu da khong cuu duoc Cong Chua! Hoang Tu non vai =))" << endl;
	}
	else
	{
		cout << "Hoang Tu simp chua da cuu duoc Cong Chua <3" << endl;
		cout << "So tien con lai cua Hoang Tu: " << Sotien << endl;
		cout << "Chi so tri tue con lai cua Hoang Tu: " << Tritue << endl;
		cout << "Chi so suc manh con lai cua Hoang Tu: " << Sucmanh << endl;
	}
	return 0;
}