#include<iostream>

using namespace std;
void Inverse(int *dau, int *q, int n);
void Max(int *dau, int *q, int n);
void Arrange(int *dau, int *q, int n);
void ArrangeAd(int *dau, int *q, int n);

int main()
{
    int n, *dau, *q;
    cout<<"Nhap so phan tu cho mang: "<<endl;
    cin>>n;
    dau = new int[n];
    for (q = dau; q < dau+n; q++)
    {
        cout<<"Nhap phan tu thu "<<q-dau+1<<" "<<endl;
        cin>>*q;
    }
    Inverse(dau, q, n);
    Max(dau, q, n);
    Arrange(dau, q, n);
    ArrangeAd(dau, q, n);
    
}

void Inverse(int *dau, int *q, int n)
{
    cout<<"Nguoc "<<endl;
    for (q = dau + (n-1); q >= dau; q--)
    {
        cout<<"Phan tu thu "<<q - dau+1<<" la "<<*q<<endl;
    }
}

void Max(int *dau, int *q, int n)
{
    int max;
    max = *dau;
    for (q = dau; q < dau+n; q ++)
    {
        if (*q > max)
        {
            max = *q;
        }
    }
    cout<<"Phan tu co gia tri lon nhat la: "<<max<<endl;
    cout<<"Vi tri la: "<<&max<<endl;
}

void Arrange(int *dau, int *q, int n)
{
    int *k, tam;
    for (q = dau; q < dau+n-1; q++ )
    {
        for (k = q+1; k< dau+n; k++)
        {
            if (*k < *q)
            {
                tam = *k;
                *k = *q;
                *q = tam;
            }
        }
    }
    cout<<"Day sap xep tang dan: "<<endl;
    for (q = dau; q < dau+n; q++ )
    {
        cout<<"Phan tu thu "<<q-dau+1<<" la "<<*q<<endl;
    }
}

void ArrangeAd(int *dau, int *q, int n)
{
    int count1, count2, *k, tam;
    count1 = 0;
    count2 = 0;
    for (q = dau; q<dau+n; q++)
    {
        if(*q<0)
        {
            count1 = count1 + 1;
        }
        else
        {
            count2 = count2 + 1;
        }
    }
    for (q = dau; q < dau+count1 - 1; q++ )
    {
        for (k = q + 1; k < dau + count1; k++)
        {
            if (*k > *q)
            {
                tam = *q;
                *q = *k;
                *k = tam;
            }
        }
    }
    for (q = dau + count1; q < dau+count1+count2-1; q++)
    {
        for ( k = q + 1; k < dau+count1+count2; k++)
        {
            if (*k < *q)
            {
                tam = *k;
                *k = *q;
                *q = tam;
            }
        }
    }
    cout<<"Sau khi sap xep: "<<endl;
    for (q = dau; q < dau + n; q++)
    {
        cout<<*q<<" ";
    }
}
