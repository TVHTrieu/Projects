#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int N, Sum, i;
    float S;
    //Nhập số phần tử cần tính tổng
    cout<<"Nhap N";
    cin>>N;
    Sum = 0;
    //Tính tổng N phần tử bình phương
    for (i=0;i<=N;i++)
    {
       Sum = Sum + i*i;
    }
    //Lấy căn của tổng
    S = sqrt(Sum);
    cout<<"Tong la: "<<S<<endl;


}