#include<iostream>
#include<math.h>
using namespace std;

int main(){

    char name[50], sex[5];
    int age;
    cout<<"Nhập vào tên:"<<endl;
    cin.getline(name, 50);
    cout<<"Nhập vào giới tính:"<<endl;
    cin.getline(sex, 5);
    cout<<"Nhập vào tuổi:"<<endl;
    cin>>age;
    cout<<"Tên là: "<<name<<endl;
    cout<<"Giới tính là: "<<sex<<endl;
    cout<<"Năm sinh là: "<<2022-age<<endl;

}