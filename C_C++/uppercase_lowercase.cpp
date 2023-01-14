#include<iostream>

using namespace std;

int main(){
    
    char a;
    int b;
    cout<<"Nhap mot ki tu: ";
    cin.get(a);
    if (65<=a && a<=90){
        cout<<"Ki tu hoa";
    }
    else if (97<=a && a<=122){
        cout<<"Ki tu thuong";
    }
    else{
        cout<<"Khong phai chu cai";
    }
}