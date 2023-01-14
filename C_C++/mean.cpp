#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){

    float a, b, c, m;
    cout<<"Nhập vào 3 số bất kì: ";
    cin>>a>>b>>c;
    m = (a + b + c)/3;
    cout<<"Trung bình của ba số là: "<<round(m*10000)/10000;

}