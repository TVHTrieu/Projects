#include<iostream>

using namespace std;

int main(){

    int a, b;
    cout<<"Nhap ngay cua thang hien tai"<<endl;
    cin>>a;
    b = a%7;
    switch (b)
    {
    case 0:
        cout<<"Thu tu";
        break;
    case 1:
        cout<<"Thu nam";
        break;
    case 2:
        cout<<"Thu sau";
        break;
    case 3:
        cout<<"Thu bay";
        break;
    case 4:
        cout<<"Chu nhat";
        break;
    case 5:
        cout<<"Thu hai";
        break;
    case 6:
        cout<<"Thu ba";
        break;
    default:
        break;
    }
}