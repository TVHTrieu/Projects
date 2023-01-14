#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int x, i, n, a;
    float e, b, lt;
    cout<<"Nhap x "<<endl;
    cin>>x;
    e = 1 + x;
    a = 2;
    lt = x*x;
    for ( n = 2; lt/a >= 1e-6; a = a*n)
    {
       e = e + lt/a;
       n++;
       lt = lt*x;
    }
    cout<<"Ket qua la: "<<e<<endl;

}