#include <iostream>
using namespace std;
class Personality
{
protected:
	int Giatri;
public:
	Personality() {}
	void setGiatri(const int& _Giatri) { Giatri = _Giatri; }
	int getGiatri() { return Giatri; }
	virtual void Dacdiem() = 0;
	virtual void ChisoCao() = 0;;
	virtual void ChisoThap() = 0;
	~Personality(){}
};
class O :public Personality
{
public:
	O(){}
	O(int x) { Giatri = x; }
	void Dacdiem();
	void ChisoCao();
	void ChisoThap();
	~O(){}
};
void O::Dacdiem()
{
	cout << "San sang trai nghiem (O): ";
}
void O::ChisoCao()
{
	cout << "Nguoi co diem cao o yeu to nay thuong la nguoi thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thich bi rang buoc..." << endl;
}
void O::ChisoThap()
{
	cout << "Nguoi co diem thap o yeu to nay thuong kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh, quen thuoc va thuc te." << endl;
}
class C :public Personality
{
public:
	C(){}
	C(int x) { Giatri = x; }
	void Dacdiem();
	void ChisoCao();
	void ChisoThap();
	~C(){}
};
void C::Dacdiem()
{
	cout << "Tu chu tan tam (C): ";
}
void C::ChisoCao()
{
	cout << "Nguoi co diem cao o yeu to nay thuong la nguoi cham chi, co kha nang chiu ap luc tot. Ho thuong la nguoi gan bo, trung thanh voi to chuc." << endl;
}
void C::ChisoThap()
{
	cout << "Nguoi co diem thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, tuan thu ky luat cua to chuc kem." << endl;
}
class E :public Personality
{
public:
	E(){}
	E(int x) { Giatri = x; }
	void Dacdiem();
	void ChisoCao();
	void ChisoThap();
	~E(){}
};
void E::Dacdiem()
{
	cout << "Huong ngoai (E): ";
}
void E::ChisoCao()
{
	cout << "Nguoi co diem cao o yeu to nay thuong la nguoi nhiet tinh, nang dong, giao tiep tot, thich the hien ban than." << endl;
}
void E::ChisoThap()
{
	cout << "Nguoi co diem thap o yeu to nay thuong ngai giao tiep, khong thich su noi bat, thich duoc lam viec doc lao." << endl;
}
class A :public Personality
{
public:
	A(){}
	A(int x) { Giatri = x; }
	void Dacdiem();
	void ChisoCao();
	void ChisoThap();
	~A(){}
};
void A::Dacdiem()
{
	cout << "Hoa dong de chiu (A): ";
}
void A::ChisoCao()
{
	cout << "Nguoi co diem cao o yeu to nay thuong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi ''thieu chinh kien''." << endl;
}
void A::ChisoThap()
{
	cout << "Nguoi co diem thap o yeu to nay thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao." << endl;
}
class N :public Personality
{
public:
	N(){}
	N(int x) { Giatri = x; }
	void Dacdiem();
	void ChisoCao();
	void ChisoThap();
	~N(){}
};
void N::Dacdiem()
{
	cout << "Bat on cam xuc (N): ";
}
void N::ChisoCao()
{
	cout << "Nguoi co diem cao o yeu to nay thuong co cac cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va kha nang chiu ap luc kem." << endl;
}
void N::ChisoThap()
{
	cout << "Nguoi co diem thap o yeu to nay thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than." << endl;
}
class Person
{
protected:
	Personality *X[5];
public:
	Person(){}
	void Nhap();
	int Xacdinh(const int& x);
	void Xuat();
	bool NguyCo();
	~Person(){}
};
void Person::Nhap()
{
	int temp;
	cout << "Nhap chi so cua yeu to O: ";
	cin >> temp;
	X[0] = new O(temp);
	cout << "Nhap chi so cua yeu to C: ";
	cin >> temp;
	X[1] = new C(temp);
	cout << "Nhap chi so cua yeu to E: ";
	cin >> temp;
	X[2] = new E(temp);
	cout << "Nhap chi so cua yeu to A: ";
	cin >> temp;
	X[3] = new A(temp);
	cout << "Nhap chi so cua yeu to N: ";
	cin >> temp;
	X[4] = new N(temp);
}
int Person::Xacdinh(const int& x)
{
	if (x >= 70 && x <= 100)
		return 1;
	else if (x <= 30 && x >= 0)
		return 2;
	return 0;
}
void Person::Xuat()
{
	for (int i = 0; i < 5; i++)
	{
		cout << X[i]->getGiatri() << "---";
		X[i]->Dacdiem();
		if (Xacdinh(X[i]->getGiatri()) == 1)
			X[i]->ChisoCao();
		else if (Xacdinh(X[i]->getGiatri()) == 2)
			X[i]->ChisoThap();
		else
			cout << "Khong xac dinh ro" << endl;
	}
}
bool Person::NguyCo()
{
	if ((Xacdinh(X[1]->getGiatri()==2))||(Xacdinh(X[4]->getGiatri()==1))||(Xacdinh(X[2]->getGiatri()==2)&&Xacdinh(X[4]->getGiatri()==1)))
		return true;
	return false;
}
int main()
{
	Person A;
	cout << "--------YC1--------" << endl;
	A.Nhap();
	cout << "--------YC2--------" << endl;
	cout << "Nhap so luong nguoi danh gia tam ly: ";
	int n;
	cin >> n;
	Person** X = new Person * [n];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap nguoi thu " << i + 1 << " : " << endl;
		X[i] = new Person();
		X[i]->Nhap();
	}
	cout << "--------YC3--------" << endl;
	cout << "Chon thong tin cua nguoi thu: ";
	int t;
	cin >> t;
	X[t - 1]->Xuat();
	cout << "--------YC4--------" << endl;
	for (int i = 0; i < n; i++)
	{
		if (X[i]->NguyCo())
			cout << "Nguoi thu " << i + 1 << " ";
	}
	cout << "la nguoi co nguy co cao ma nha tuyen dung/ to chuc/ doanh nghiep can luu y!" << endl;
	return 0;
}