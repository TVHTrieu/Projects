#include<iostream>

using namespace std;

int main(){

    int i, k, a, b, c, d;
    for (i = 1000; i<=9999; i++)
    {
        a = (i/100)/10;
        b = (i/100)%10;
        c = (i%100)/10;
        d = (i%100)%10;
        if ((a+b)%2 == 0 && (c+d)%2 != 0)
        {
            cout<<i<<" ";
        }
    }




}