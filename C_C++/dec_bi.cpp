#include<iostream>

using namespace std;

int main(){

    int N, i, a, b, n;
    float p, r;
    cout<<"Nhap so nguyen N: "<<endl;
    cin>>N;
    a = N;
    b = N%2;
    r = b;
    p = 0;
    n = 1;
    while (a != 0)
    {
        a = a/2;
        r = r/10 + p/10;
        n = n+1;
        p = a%2;

    }
    for (i = 1; i < n; i++)
    {
        r = r*10;
    }
    /*r = r/10 + p/10;
    n += 1;*/
    
    cout<<"So nhi phan la: "<<r;

}