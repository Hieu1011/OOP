#include<iostream>
#include<string>
using namespace std;
class SinhVien
{
protected:
	int Loai, MSSV, Tinchi;
	string Hoten, Diachi;
	float DTB;
public:
	SinhVien() { Loai = 0; }
	virtual void Nhap();
	virtual void Xuat();
	void setMSSV(const int& _MSSV) { MSSV = _MSSV; }
	void setTinchi(const int& _Tinchi) { Tinchi = _Tinchi; }
	void setDTB(const int& _DTB) { DTB = _DTB; }
	int getLoai() { return Loai; }
	int getMSSV() { return MSSV; }
	int getTinchi() { return Tinchi; }
	float getDTB() { return DTB; }
};
void SinhVien::Nhap()
{
	cout << "Nhap MS cua sinh vien: ";
	cin >> MSSV;
	cout << "Nhap ho ten cua sinh vien: ";
	cin.ignore();
	getline(cin, Hoten);
	cout << "Nhap dia chi cua sinh vien: ";
	getline(cin, Diachi);
	cout << "Nhap tong so tin chi: ";
	cin >> Tinchi;
	cout << "Nhap diem trung binh cua sinh vien: ";
	cin >> DTB;
}
void SinhVien::Xuat()
{
	cout << "Ma so sinh vien: " << MSSV << endl;
	cout << "Ho ten sinh vien: " << Hoten << endl;
	cout << "Dia chi sinh vien: " << Diachi << endl;
	cout << "Tong so tin chi cua sinh vien: " << Tinchi << endl;
	cout << "Diem trunng binh cua sinh vien: " << DTB << endl;
}
class HeCaoDang :public SinhVien
{
protected:
	float DTN;
public:
	HeCaoDang() { Loai = 1; }
	void Nhap();
	void Xuat();
	float getDTN() { return DTN; }
};
void HeCaoDang::Nhap()
{
	SinhVien::Nhap();
	cout << "Nhap diem tot nghiep cua sinh vien: ";
	cin >> DTN;
}
void HeCaoDang::Xuat()
{
	SinhVien::Xuat();
	cout << "Diem tot nghiep cua sinh vien: " << DTN << endl;
}
class HeDaiHoc :public SinhVien
{
protected:
	string Luanvan;
	float DLV;
public:
	HeDaiHoc() { Loai = 2; }
	void Nhap();
	void Xuat();
	float getDLV() { return DLV; }
};
void HeDaiHoc::Nhap()
{
	SinhVien::Nhap();
	cin.ignore();
	cout << "Nhap ten luan van: ";
	getline(cin, Luanvan);
	cout << "Nhap diem luan van cua sinh vien: ";
	cin >> DLV;
}
void HeDaiHoc::Xuat()
{
	SinhVien::Xuat();
	cout << "Ten luan van: " << Luanvan << endl;
	cout << "Diem luan van cua sinh vien: " << DLV << endl;
}
int main()
{
	cout << "--------YC1--------" << endl;
	cout << "Nhap so luong sinh vien: ";
	int n;
	cin >> n;
	SinhVien** A = new SinhVien * [n];
	for (int i = 0; i < n; i++)
	{
		cout << "--> Nhap he sinh vien: \t1. He Cao Dang \t2.He Dai Hoc" << endl;
		int temp;
		cin >> temp;
		switch (temp)
		{
		case 1:
			A[i] = new HeCaoDang();
			A[i]->Nhap();
			break;
		case 2:
			A[i] = new HeDaiHoc();
			A[i]->Nhap();
			break;
		default:
			break;
		}
	}
	cout << "--------YC2--------" << endl;
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i]->getLoai() == 1)
		{
			if (A[i]->getTinchi() > 120 && A[i]->getDTB() > 5 && ((HeCaoDang*)A[i])->getDTN() > 5)
				dem++;
		}
		else
		{
			if (A[i]->getTinchi() > 170 && A[i]->getDTB() > 5 && ((HeDaiHoc*)A[i])->getDLV() > 5)
				dem++;
		}
	}
	cout << "So sinh vien du dieu kien tot nghiep la: " << dem << endl;
	cout << "--------YC3--------" << endl;
	float max = A[0]->getDTB();
	int iMax = 0;
	for (int i = 1; i < n; i++)
	{
		if (max < A[i]->getDTB())
		{
			max = A[i]->getDTB();
			iMax = i;
		}
	}
	cout << "Sinh vien co diem trung binh cao nhat la: " << endl;
	A[iMax]->Xuat();
	return 0;
}