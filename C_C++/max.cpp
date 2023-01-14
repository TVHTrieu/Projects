#include<iostream>

using namespace std;

int main(){

    float a, b, c, d, e, max1, max2;
    cout<<"Nhap vao 5 so"<<endl;
    cin>>a>>b>>c>>d>>e;
    max1 = a;
    max2 = b;
    if (c>max1){
        max1 = c;
        max2 = a;
        if (d>max2){
            max2 = d;
        }
        if (e>max2){
            max2 = e;
        }
    }
    if (d>max1){
        max1 = d;
        max2 = a;
        if (c>max2){
            max2 = c;
        }
        if (e>max2){
            max2 = e;
        }
    }
    if (e>max1){
        max1 = e;
        max2 = a;
        if (c>max2){
            max2 = c;
        }
        if (d>max2){
            max2 = d;
        }
    }
    cout<<max1<<" la so lon nhat"<<endl;
    cout<<max2<<" la so lon thu hai";

}