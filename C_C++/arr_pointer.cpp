#include<iostream>

using namespace std;

int main()
{
    int a[100], i, j, *p, m, n;
    int b[100], *dau, *q, k ;
    int *c[2] = {a, b};
    dau = new int[100];
    cout<<"Nhap so luong phan tu cua mang a: "<<endl;
    cin>>m;
    cout<<"Nhap so luong phan tu cua mang b: "<<endl;
    cin>>n;
    for(i = 0; i < m; i++)
    {
        cout<<"Phan tu a["<<i<<"] = ";
        cin>>a[i];
    }
    cout<<endl;
    for(i = 0; i < n; i++)
    {
        cout<<"Phan tu b["<<i<<"] = ";
        cin>>b[i];
    }
    cout<<endl;
    p = dau;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; *c[i]++, j++)
        {
            if(*c[i] == 0)
            continue;
            cout<<*c[i]<<" ";
            *p = *c[i];
            p++;
        }
    }
    cout<<endl;
    for (p = dau; p < dau+m+n-1; p++)
    {
       for (q = p+1; q < dau+m+n; q++)
       {
        if (*p==0 || *q==0)
        continue;
        if (*q<*p)
        {
            k = *q;
            *q = *p;
            *p = k;
        }
       }
    }
    for (p = dau; p < dau+m+n; p++)
    {
        cout<<*p<<" ";
    }

}