#include<iostream>

using namespace std;

int main(){

    float x, sin, lt, gt;
    int n, a;
    cout<<"Nhap x: "<<endl;
    cin>>x;
    sin = 0;
    lt = x;
    gt = 1;
    n = 1;
    for (a = 1; lt/gt >= 1e-6; n++)
    {
        sin = sin + a*(lt/gt);
        a = (-1)*a;
        lt = lt*(x*x);
        gt = gt * (2*n) * (2*n + 1);
    }
    cout<<sin;

}