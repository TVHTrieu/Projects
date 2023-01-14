#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    float A, B, C, D, x, y, z, d;
    cout<<"Nhập vào tọa độ mặt phẳng: "<<endl;
    cin>>A>>B>>C>>D;
    cout<<"Nhập vào tọa độ điểm: "<<endl;
    cin>>x>>y>>z;
    d = fabs(A*x+B*y+C*z+D)/(sqrt(A*A+B*B+C*C));
    cout<<"Khoảng cách từ điểm tới mặt phẳng là:"<<endl<<round(d*1000)/1000;
}