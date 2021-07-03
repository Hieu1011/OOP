#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class ThanhPhan
{
protected:
	string Text;
	int BKDCol; int TextCol;
public:
	ThanhPhan() { BKDCol = 0; TextCol = 0; }
	virtual void Nhap();
	void setBKDCol(const int& _BKDCol) { BKDCol= _BKDCol; }
	void setTextCol(const int& _TextCol) { TextCol = _TextCol; }
	virtual int getBKDCol() { return BKDCol; }
	virtual int getTextCol() { return TextCol; }
};
void ThanhPhan::Nhap()
{
	cout << "Chon mau trong bang: " << endl;
	cout << "1.Red\t 2.Orange\t 3.Yellow\t 4.Spring Green" << endl;
	cout << "5.Green\t 6.Turquoise\t 7.Cyan \t 8.Ocean" << endl;
	cout << "9.Blue\t 10.Violet\t 11.Magenta\t 12.Raspberry" << endl;
	cout << "Chon mau nen: ";
	cin >> BKDCol;
	cout << "Chon mau text: ";
	cin >> TextCol;
	cin.ignore();
	cout << "Nhap noi dung Text: ";
	getline(cin, Text);
}
class Label :public ThanhPhan
{
public:
	Label () {}
	void Nhap();
};
void Label::Nhap()
{
	cout << "___Tao Label___ " << endl;
	ThanhPhan::Nhap();
}
class Button :public ThanhPhan
{
public:
	Button(){}
	void Nhap();
};
void Button::Nhap()
{
	cout << "___Tao Button___" << endl;
	cout << "Chon kieu:\t 1.Hinh anh \t2.Button text" << endl;
	int temp;
	cin >> temp;
	switch (temp)
	{
	case 1:
		cout << "Hinh anh...." << endl;
		cout << "...Xong!" << endl;
		break;
	case 2:
		ThanhPhan::Nhap();
		break;
	default:
		break;
	}
}
bool PMbotuc(int x, int y)
{
	return abs(x - y) == 6;
}
bool PMtuongdong(int x, int y, int z)
{
	int data[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,1,2 };
	return (data[x + 1] == y && data[x + 2] == z);
}
int main()
{
	cout << "--------YC1--------" << endl;
	cout << "Nhap so luong thanh phan tren web: ";
	int n;
	cin >> n;
	ThanhPhan** A = new ThanhPhan * [n];
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << "Chon loai thanh phan:\t 1.Label \t2.Button " << endl;
		cin >> temp;
		switch (temp)
		{
		case 1:
			A[i] = new Label();
			A[i]->Nhap();
			break;
		case 2:
			A[i] = new Button();
			A[i]->Nhap();
			break;
		default:
			break;
		}
	}
	cout << "--------YC2--------" << endl;
	if (PMbotuc(A[0]->getBKDCol(), A[0]->getTextCol()))
		cout << "Thanh phan dau tien trong danh sach phu hop voi phoi mau bo tuc" << endl;
	else
		cout << "Thanh phan dau tien trong danh sach khong phu hop voi phoi mau bo tuc" << endl;
	cout << "--------YC3--------" << endl;
	int dd[13];
	for (int i = 0; i <= 12; i++)
		dd[i] = 0;
	for (int i = 0; i < n; i++)
		dd[A[i]->getBKDCol()]++;
	int spt = 0;
	int mau[13];
	for (int i = 1; i <= 12; i++)
	{
		if (dd[i] != 0)
			mau[spt++] = i;
	}
	cout << "Mau nen cac thanh phan: ";
	if (spt == 1)
		cout << "theo nguyen tac MAU DON SAC" << endl;
	else
		if (spt == 2 && PMbotuc(mau[0], mau[1]))
			cout << "theo nguyen tac MAY BO TUC" << endl;
		else
			if (spt == 3 && PMtuongdong(mau[0], mau[1], mau[2]))
				cout << "theo nguyen tac MAU TUONG DONG" << endl;
			else
				cout << "khong theo nguyen tac nao" << endl;
	return 0;
}