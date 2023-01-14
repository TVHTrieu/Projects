#include<iostream>
#include<string.h>

using namespace std;

struct Sinhvien{
    char hoten[100];
    int ngaysinh, thangsinh, namsinh;
};

int Age(Sinhvien a[], int n, int i);
void Sort(Sinhvien a[], int n, int age[]);

int main()
{
    Sinhvien a[1000];
    int n, age[1000];
    cout<<"Nhap so luong sinh vien: "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++ )
    {
        cin.ignore(1);
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        cout<<"Name: ";
        cin.getline(a[i].hoten, 99);
        cout<<"Birthday: ";
        cin>>a[i].ngaysinh>>a[i].thangsinh>>a[i].namsinh;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"Sinh vien thu "<<i+1<<": "<<a[i].hoten<<" "<<a[i].ngaysinh<<"/"<<a[i].thangsinh<<"/"<<a[i].namsinh;
        cout<<endl;
    }
    for ( int i = 0; i < n; i++)
    {
        age[i] = Age(a, n, i);
        cout<<"Tuoi cua sinh vien thu "<<i+1<<": "<<age[i]<<endl;
    }
    cout<<endl;
    Sort(a, n, age);
    
}

int Age(Sinhvien a[], int n, int i)
{
    int j, age[n];
    age[i] = 0;
    for (j = a[i].namsinh; j < 2022-1; j++)
    {
        age[i] = age[i] + 1;
    }
    if (a[i].thangsinh < 12 )
    {
        age[i] = age[i] + 1;
    }
    else
    {
        if (a[i].ngaysinh <= 29)
        {
            age[i] = age[i] + 1;
        }
    }
    return age[i];
    
}

void Sort(Sinhvien a[], int n, int age[])
{
    int i, j, r;
    Sinhvien temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (age[i] > age[j])
            {
                r = age[i];
                age[i] = age[j];
                age[j] = r;
               temp = a[i];
               a[i] = a[j];
               a[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        cout<<"Sinh vien thu "<<i+1<<": "<<a[i].hoten;
        cout<<endl;
    }
}