#include<iostream>
using namespace std;
class Loai
{
protected:
	int Nhom;
	bool Rh;
public:
	bool Rhesus[8];
	Loai() { Nhom = 0; Rh = true; };
	Loai(const int& _Nhom) { Nhom = _Nhom; }
	Loai(const bool& _Rh) { Rh = _Rh; }
	void setNhom(const int& _Nhom);
	void setRh(const int& _Rh);
	int getNhom();
	int getRh();
	int getIRhesus();
	virtual bool KiemtraCM(Loai* Cha, Loai* Me);
	virtual void Xuat();
};
void Loai::setNhom(const int& _Nhom)
{
	Nhom = _Nhom;
}
void Loai::setRh(const int& _Rh)
{
	Rh = _Rh;
}
int Loai::getNhom()
{
	return Nhom;
}
int Loai::getRh()
{
	return Rh;
}
int Loai::getIRhesus()
{
	if (Nhom == 1)
	{
		if (Rh)
			return 1;
		else return 0;
	}
	else if (Nhom == 2)
	{
		if (Rh)
			return 3;
		else return 2;
	}
	else if (Nhom==3)
	{
		if (Rh)
			return 5;
		else return 4;
	}
	else if (Nhom == 4)
	{
		if (Rh)
			return 7;
		return 6;
	}
}
bool Loai::KiemtraCM(Loai* Cha, Loai* Me)
{
	return true;
}
void Loai::Xuat()
{
	return;
}
class O :public Loai
{
public:
	O()
	{ 
		Nhom = 1; 
		if (Rh==true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
	}
	O(int _Rh)
	{
		Nhom = 1;
		Rh = _Rh;
		if (Rh == true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
	}
	bool KiemtraCM(Loai* Cha, Loai* Me);
	void Xuat();
	~O(){}
};
void O::Xuat()
{
	if (Rh)
		cout << " co nhom mau: O+";
	else
		cout << " co nhom mau: O-";
}
bool O::KiemtraCM(Loai* Cha, Loai* Me)
{
	if (Cha->getNhom() == 4 || Me->getNhom() == 4)
		return false;
	return true;
}
class A :public Loai
{
public:
	A() 
	{
		Nhom = 2;
		if (Rh==true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = true;
			Rhesus[3] = true;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = true;
			Rhesus[3] = false;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
	}
	A(int _Rh)
	{
		Nhom = 2;
		Rh = _Rh;
		Nhom = 2;
		if (Rh == true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = true;
			Rhesus[3] = true;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = true;
			Rhesus[3] = false;
			Rhesus[4] = false;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
	}
	bool KiemtraCM(Loai* Cha, Loai* Me);
	void Xuat();
	~A() {}
};
void A::Xuat()
{
	if (Rh)
		cout << " co nhom mau: A+";
	else
		cout << " co nhom mau: A-";
}
bool A::KiemtraCM(Loai* Cha, Loai* Me)
{
	if ((Cha->getNhom() == 1 && Me->getNhom() == 1) || (Cha->getNhom() == 1 && Me->getNhom() == 3))
		return false;
	if ((Me->getNhom() == 1 && Cha->getNhom() == 3) || (Me->getNhom() == 3 && Cha->getNhom() == 3))
		return false;
	return true;
}
class B :public Loai
{
public:
	B() 
	{ 
		Nhom = 3;
		if (Rh==true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = true;
			Rhesus[5] = true;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = true;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
	}
	B(int _Rh)
	{
		Nhom = 3;
		Rh = _Rh;
		if (Rh == true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = true;
			Rhesus[5] = true;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = false;
			Rhesus[3] = false;
			Rhesus[4] = true;
			Rhesus[5] = false;
			Rhesus[6] = false;
			Rhesus[7] = false;
		}
	}
	bool KiemtraCM(Loai* Cha, Loai* Me);
	void Xuat();
	~B() {}
};
void B::Xuat()
{
	if (Rh)
		cout << " co nhom mau: B+";
	else
		cout << " co nhom mau: B-";
}
bool B::KiemtraCM(Loai* Cha, Loai* Me)
{
	if ((Cha->getNhom() == 1 && Me->getNhom() == 1) || (Cha->getNhom() == 1 && Me->getNhom() == 2))
		return false;
	if ((Me->getNhom()==1&&Cha->getNhom()==2)||(Me->getNhom()==2&&Cha->getNhom()==2))
		return false;
	return true;
}
class AB :public Loai
{
public:
	AB() 
	{
		Nhom = 4;
		if (Rh==true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = true;
			Rhesus[3] = true;
			Rhesus[4] = true;
			Rhesus[5] = true;
			Rhesus[6] = true;
			Rhesus[7] = true;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = true;
			Rhesus[3] = false;
			Rhesus[4] = true;
			Rhesus[5] = false;
			Rhesus[6] = true;
			Rhesus[7] = false;
		}
	}
	AB(int _Rh)
	{
		Nhom = 4;
		Rh = _Rh;
		if (Rh == true)
		{
			Rhesus[0] = true;
			Rhesus[1] = true;
			Rhesus[2] = true;
			Rhesus[3] = true;
			Rhesus[4] = true;
			Rhesus[5] = true;
			Rhesus[6] = true;
			Rhesus[7] = true;
		}
		else
		{
			Rhesus[0] = true;
			Rhesus[1] = false;;
			Rhesus[2] = true;
			Rhesus[3] = false;
			Rhesus[4] = true;
			Rhesus[5] = false;
			Rhesus[6] = true;
			Rhesus[7] = false;
		}
	}
	bool KiemtraCM(Loai* Cha, Loai* Me);
	void Xuat();
	~AB() {}
};
void AB::Xuat()
{
	if (Rh)
		cout << " co nhom mau: AB+";
	else
		cout << " co nhom mau: AB-";
}
bool AB::KiemtraCM(Loai* Cha, Loai* Me)
{
	if (Cha->getNhom() == 1 || Me->getNhom() == 1)
		return false;
	if ((Cha->getNhom() == 3 && Me->getNhom() == 3) || (Cha->getNhom() == 2 && Me->getNhom() == 2))
		return false;
	return true;
}
int main()
{
	int n;
	cout << "____YC1____" << endl;
	cout << "Nhap so nguoi: ";
	cin >> n;
	Loai* Nhom[100];
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cout << "Nhap nhom mau (1. O, 2. A, 3. B, 4. AB): ";
     	cin >> temp;
		int rh;
		cout << "Nhap loai Rh (1. Rh+, 0.Rh-): ";
		cin >> rh;
		switch (temp)
		{
		case 1:
			Nhom[i] = new O(rh);
			break;
		case 2:
			Nhom[i] = new A(rh);
			break;
		case 3:
			Nhom[i] = new B(rh);
			break;
		case 4:
			Nhom[i] = new AB(rh);
			break;
		default:
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "Nguoi thu " << i;
		Nhom[i]->Xuat();
		cout << endl;
	}
	cout << "____YC2____" << endl;
	int stt[3];
	cout << "Nhap so thu tu cua nguoi cha: ";
	cin >> stt[0];
	cout << "Nhap so thu tu cua nguoi me: ";
	cin >> stt[1];
	cout << "Nhap so thu tu cua nguoi con: ";
	cin >> stt[2];
	if (Nhom[stt[2]]->KiemtraCM(Nhom[stt[0]], Nhom[stt[1]]))
		cout << "Con la con cha me!" << endl;
	else
		cout << "Con ong hang xom =))" << endl;
	cout << "____YC3____" << endl;
	int x;
	cout << "So thu tu nguoi can chon: ";
	cin >> x;
	for (int i = 1; i <= n; i++)
	{
		if (i != x)
		{
			if (Nhom[x]->Rhesus[Nhom[i]->getIRhesus()])
				cout << "Nguoi thu " << i << " ";
		}
	}
	cout << "co the cho mau nguoi ban chon.";
	return 0;
}