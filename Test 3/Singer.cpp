#include<iostream>
#include<string>
using namespace std;
class CaSi
{
protected:
    string Name;
    int Sonam, Sodia, Sobuoi;
    long long Luong;
public:
    CaSi() {}
    virtual void Nhap();
    virtual void Xuat();
    virtual long long TinhLuong() { return 0; }
    void setName(const string& _Name) { Name = _Name; }
    void setLuong(const long long& _Luong) { Luong = _Luong; }
    string getName() { return Name; }
    long long getLuong() { return Luong; }
    ~CaSi() {}
};
void CaSi::Nhap()
{
    cin.ignore();
    cout << "Nhap ten ca si: ";
    getline(cin, Name);
    cout << "Nhap so nam lam viec: ";
    cin >> Sonam;
    cout << "Nhap so dia da ban: ";
    cin >> Sodia;
    cout << "Nhap so buoi trinh dien: ";
    cin >> Sobuoi;
}
void CaSi:: Xuat()
{
    cout << "Ho ten ca si la: " << Name << endl;
    cout << "So nam lam viec la: " << Sonam << endl;
    cout << "So sodia da ban: " << Sodia << endl;
    cout << "So buoi trinh dien: " << Sobuoi << endl;
}
class CaSiNoiTieng :public CaSi
{
protected:
    int Gameshow;
public:
    CaSiNoiTieng() {}
    void Nhap();
    void Xuat();
    long long TinhLuong();
    ~CaSiNoiTieng() {}
};
void CaSiNoiTieng:: Nhap()
{
    CaSi::Nhap();
    cout << "Nhap so game show da tham gia: ";
    cin >> Gameshow;
}
void CaSiNoiTieng:: Xuat()
{
    CaSi::Xuat();
    cout << "So Gameshow da tham gia: " << Gameshow << endl;
    cout << "So luong: " << TinhLuong() << endl;
    cout << "______________________" << endl;
}
long long CaSiNoiTieng:: TinhLuong()
{
    return (5000000 + 500000 * Sonam + 1200 * Sodia + 500000 * Sobuoi + 500000 * Gameshow);
}
class CaSiChuaNoiTieng : public CaSi
{
public:
    CaSiChuaNoiTieng() {}
    long long TinhLuong();
    void Xuat();
    ~CaSiChuaNoiTieng() {}
};
long long CaSiChuaNoiTieng:: TinhLuong()
{
    return (3000000 + 500000 * Sonam + 1000 * Sodia + 200000 * Sobuoi);
}
void CaSiChuaNoiTieng:: Xuat()
{
    CaSi::Xuat();
    cout << "So luong: " << TinhLuong() << endl;
    cout << "______________________" << endl;
}
class Danhsach :public CaSiNoiTieng, public CaSiChuaNoiTieng
{
private:
    int n;
    CaSi** p;
public:
    Danhsach() { n = 0; p = NULL; }
    void Nhap();
    void Xuat();
    ~Danhsach()
    {
        delete[]p;
    }
};
void Danhsach::Nhap()
{
    cout << "Nhap so ca si can quan li: ";
    cin >> n;
    p = new CaSi * [n];
    for (int i = 0; i < n; i++)
    {
        cout << "1. Ca si noi tieng \n2. Ca si khong noi tieng" << endl;
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
        {
            p[i] = new CaSiNoiTieng();
            p[i]->Nhap();
            break;
        }
        case 2:
        {
            p[i] = new CaSiChuaNoiTieng();
            p[i]->Nhap();
            break;
        }
        default: break;
        }
    }
}
void Danhsach::Xuat()
{
    float max = p[0]->TinhLuong();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < p[i]->TinhLuong())
        {
            max = p[i]->TinhLuong();
            j = i;
        }
    }
    cout << "Ca si luong cao nhat la: " << p[j]->getName();
}
int main()
{
    Danhsach a;
    cout << "--------YC1--------" << endl;
    a.Nhap();
    cout << "--------YC2--------" << endl;
    a.Xuat();
    return 0;
}