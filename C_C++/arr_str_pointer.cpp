#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char *s, *p, *a, *dau, *q;
    int n=0;
    a = new char[100];
    s = new char[100];
    cout<<"Nhap vao chuoi ki tu: "<<endl;
    cin.getline(s, 99);
    cout<<"Chuoi vua nhap la: "<<s<<endl;
    for (p = s; p < s+strlen(s); p++)
    {
        if (*p >= 48 && *p <= 57)
        {
            cout<<"Co ki tu so trong chuoi"<<endl;
            break;
        }
    }
    dau = a;
    for (p = s; p < s+strlen(s); p++)
    {
        while (*p >= '0' && *p <= '9')
        {
            if (*(p+1) >= '0' && *(p+1) <= '9')
            {
                *dau = *p;
                dau++;
                n = n+1;
                for(q = p; q < s + strlen(s); q++)
                {
                    *q = *(q+1);
                }
            }
            else
            {
            *dau = *p;
            dau++;
            *p = 32;
            n = n+1; //Số lượng phần tử của mảng a
            }
        }
    }
    
    for(dau = a; dau < a+n; dau++)
    {
        cout<<*dau<<" ";
    }
    cout<<endl;
    cout<<"Chuoi cuoi cung la: "<<s;
}