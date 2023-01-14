#include<iostream>

using namespace std;

struct fraction{
    int tu;
    int mau;
} ;

int compact(fraction z);
fraction tong(fraction a, fraction b);
fraction hieu(fraction a, fraction b);
fraction tich(fraction a, fraction b);
fraction thuong(fraction a, fraction b);
void compet(fraction a, fraction b);

int main()
{
    fraction a, b, sum, minus, product, quotient;
    int ucln;
    cout<<"Nhap vao so a ";
    cin>>a.tu>>a.mau;
    cout<<"Nhap vao so b ";
    cin>>b.tu>>b.mau;
    cout<<"So a la: "<<a.tu<<"/"<<a.mau<<endl;
    cout<<"So b la: "<<b.tu<<"/"<<b.mau<<endl;
    sum = tong(a, b);
    minus = hieu(a, b);
    ucln = compact(sum);
    if (sum.mau/ucln == 1 || minus.mau/ucln == 1 ){
        cout<<"Tong dang toi gian la: "<<sum.tu/ucln<<endl;
        cout<<"Hieu dang toi gian la: "<<minus.tu/ucln<<endl;
    }
    else{
        cout<<"Tong dang toi gian la: "<<sum.tu/ucln<<"/"<<sum.mau/ucln<<endl;
        cout<<"Hieu dang toi gian la: "<<minus.tu/ucln<<"/"<<minus.mau/ucln<<endl;
    }
    product = tich(a, b);
    ucln = compact(product);
    cout<<"Tich dang toi gian la: "<<product.tu/ucln<<"/"<<product.mau/ucln<<endl;
    quotient = thuong(a, b);
    ucln = compact(quotient);
    cout<<"Thuong dang toi gian la: "<<quotient.tu/ucln<<"/"<<quotient.mau/ucln<<endl;
    compet(a, b);
}

int compact(fraction z)
{
    int n, ucln;
    if (z.mau < z.tu)
    {
        n = z.mau;
    }
    else{
        n = z.tu;
    }
    for (int i = n; i >= 1; i--)
    {
        if ((z.tu % i == 0) && (z.mau % i == 0))
        {    
            ucln = i;
            break;
        }
    }
    return ucln;
}

fraction tong(fraction a, fraction b)
{
    fraction tong;
    if (a.mau == b.mau)
    {
        tong.mau = a.mau;
        tong.tu = a.tu + b.tu;
    }
    else
    {
        tong.mau = a.mau*b.mau;
        tong.tu = a.tu*b.mau + b.tu*a.mau;
    }
    return tong;
}

fraction hieu(fraction a, fraction b)
{
    fraction hieu;
    if (a.mau = b.mau)
    {
        hieu.mau = a.mau;
        hieu.tu = a.tu - b.tu;
    }
    else
    {
        hieu.mau = a.mau*b.mau;
        hieu.tu = a.tu*b.mau - b.tu*a.mau;
    }
    return hieu;
}

fraction tich(fraction a, fraction b)
{
    fraction tich;
    tich.tu = a.tu*b.tu;
    tich.mau = a.mau*b.mau;
    return tich;
}

fraction thuong(fraction a, fraction b)
{
    fraction thuong;
    thuong.tu = a.tu*b.mau;
    thuong.mau = a.mau*b.tu;
    return thuong;
}

void compet(fraction a, fraction b)
{
    if (a.mau == b.mau)
    {
        if (a.tu > b.tu)
        cout<<a.tu<<"/"<<a.mau<<" > "<<b.tu<<"/"<<b.mau<<endl;
        else
        cout<<a.tu<<"/"<<a.mau<<" < "<<b.tu<<"/"<<b.mau<<endl;
    }
    else
    {
        a.tu = a.tu*b.mau;
        b.tu = b.tu*a.mau;
        a.mau = b.mau = a.mau*b.mau;
        if (a.tu > b.tu)
        cout<<a.tu<<"/"<<a.mau<<" > "<<b.tu<<"/"<<b.mau<<endl;
        else
        cout<<a.tu<<"/"<<a.mau<<" < "<<b.tu<<"/"<<b.mau<<endl;
        
    }
}