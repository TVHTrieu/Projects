#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int N, i;
    float S;
    cout<<"Nhap N can: "<<endl;
    cin>>N;
    S = 0;
    for (i=1; i<=N; i++)
    {
        S = S + 3;
        S = sqrt(S);
    }
    cout<<"Tong can la: "<<S;

}