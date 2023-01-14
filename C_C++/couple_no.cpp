#include<iostream>

using namespace std;

int main(){

    int i, j, n, m;
    for (i=2; i<1000; i++)
    {
        n = 0;
        for (j = 1; j<=i; j++)
        {
            if (i%j==0)
            {
                n = n+1;
            }
        }
        if ( n== 2)
        {
            if (i - m == 2)
            {
                cout<<"("<<m<<","<<i<<")"<<" ";
            }
            m = i;
        }
    }

}