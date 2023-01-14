#include<iostream>

using namespace std;

int main(){

    int N, i, j, s;
    cout<<"Nhap so N "<<endl;
    cin>>N;
    
    for (i = 1; i<N; i++)
    {
        s = 0;
        for (j = 1; j < i; j++)
        {
            if (i%j == 0)
            {
                s = s + j;
            }
        }

        if (s == i)
        {
            cout<<i<<' ';
        }
    }
}