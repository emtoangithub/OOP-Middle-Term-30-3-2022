#include <bits/stdc++.h>
using namespace std;
void xoa()
{
    system("cls");
}
void dungroixoa()
{
    cout<<endl;
    system("pause");
    xoa();
}
void menu()
{
    xoa();
    cout<<"\nHay chon yeu cau cua ban";
    cout<<"\n1.Khoi tao n voi gia tri mac dinh (n = 1) ";
    cout<<"\n2.Nhap gia tri cua n";
    cout<<"\n3.Lay gia tri cua n";
    cout<<"\n4.Thay doi gia tri cua n";
    cout<<"\n5.Xuat gia tri cua n";
    cout<<"\n6.Kiem tra so nguyen to";
    cout<<"\n7.Kiem tra so chinh phuong";
    cout<<"\n8.Kiem tra so hoan thien";
    cout<<"\n9.Kiem tra so doi xung";
    cout<<"\n10.Kiem tra tat ca";
    cout<<"\n0.Thoat chuong trinh";
    cout<<"\nYeu cau cua ban la: ";
}
class SoDB
{
    private: 
    int n;
    public:
    SoDB(int = 1);
    int GetN();
    void SetN(int);
    void nhap();
    int checksont();
    void xuat();
    void xuatcheck();
    int checksocp();
    void xuatcp();
    void checksohoanthien();
    void checksodoixung();
};
void SoDB :: xuatcp()
{

    if (this->checksocp()) cout<<n<<" la so chinh phuong ";
    else cout<<n<<" khong la so chinh phuong";
}
void SoDB :: checksodoixung()
{
    int sodaonguoc=0;
	int x=n;
	while (x!=0)
	{
		int temp=x%10;
		sodaonguoc = sodaonguoc*10+temp;
		x/=10;
	}
	cout<<"\n";
	if (sodaonguoc==n) cout<<n<<" la so doi xung";
	else cout<<n<<" khong la so doi xung";
}
void SoDB :: checksohoanthien()
{
	int temp = 0;
	for (int i=1;i<n;i++) 
	{
		if (n%i==0) temp+=i; //cout<<i<<" "; 
	}
	if (temp==n) cout<<"\n"<<n<<" la so hoan thien"; else cout<<"\n"<<n<<" khong la so hoan thien";
}
int SoDB :: checksocp()
{
    if (n<0) return 0;
    int temp=sqrt(n);
    if ((temp*temp) == n) return 1;
    else return 0;
}
void SoDB :: xuat()
{
    cout<<"\nn: "<<this->n;
}
int SoDB :: checksont()
{
    int sum=0;
    if (n < 2) return 1;
	if (n==2 || n==3  )
	{
		sum=0;
		return 0;
	}
    else if (n<0) return 1;
	else 
	{
		for (int i=2;i<=sqrt(n);i++)
		{
			if (n%i==0)
			{
			    sum++;
			}
		}
	}
	return sum;
}
SoDB :: SoDB(int n)
: n(n)
{}
int SoDB :: GetN()
{
    return this->n;
}
void SoDB :: SetN(int n )
{
    this->n = n;
}
void SoDB :: nhap()
{
    do 
    {
        cout<<"Nhap n ( n > 0 ): ";
        cin>>this->n;
    } while (this->n <= 0);
}
int main()
{
    xoa();
    SoDB n;
    int a = n.GetN();
    while(1)
    {
    menu();
    int lc;
    cin>>lc;
    xoa();
    switch (lc)
    {
    case 1 : cout<<"Da khoi tao!";
    dungroixoa();
    break;
    case 2 : n.nhap();
    cout<<"Da luu gia tri!";
    dungroixoa(); 
    break;
    case 3 : cout<<"Da lay gia tri cua n!";
    dungroixoa();
    break;
    case 4 : 
    int x;
    do
    {
    cout<<"Nhap gia tri muon thay doi ( mot so lon hon 0 ) : "; 
    cin>>x;
    } while (x <= 0);
    n.SetN(x);
    cout<<"Da thay doi gia tri!";
    dungroixoa();
    break;
    case 5 :
    a = n.GetN();
    cout<<"n : "<<a;
    dungroixoa();
    break;
    case 6 : 
    a = n.GetN();
    if (n.checksont()==0)
	{
		cout<<a<<" la so nguyen to"<<endl;
        dungroixoa();
	}
	else 
	{
		cout<<a<<" khong la so nguyen to"<<endl;
        dungroixoa();	
	}
    break;
    case 7 : 
    n.xuatcp();
    dungroixoa();
    break;
    case 8 :
    n.checksohoanthien();
    dungroixoa();
    break;
    case 9 :
    n.checksodoixung();
    dungroixoa();
    break;
    case 10 : 
    a = n.GetN();
    if (n.checksont()==0)
	{
		cout<<a<<" la so nguyen to"<<endl;
	}
	else 
	{
		cout<<a<<" khong la so nguyen to"<<endl;	
	}
    if (n.checksocp()) cout<<a<<" la so chinh phuong ";
    else cout<<a<<" khong la so chinh phuong";
    n.checksohoanthien();
    n.checksodoixung();
    dungroixoa();
    break;
    case 0 : 
    cout<<"Thoat chuong trinh!";
    dungroixoa();
    return 0;
    default:
        break;
    }
    }
}