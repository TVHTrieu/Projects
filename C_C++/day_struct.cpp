#include<iostream>

using namespace std;

struct day{
    int thu;
    int ngay;
};

int main()
{
    day n;
    cout<<"Nhap ngay bat ki: "<<endl;
    cin>>n.ngay;
    switch (n.ngay%7)
    {
    case 0:
        cout<<"Thu 5"<<endl;
        break;
    case 1:
        cout<<"Thu 6"<<endl;
        break;
    case 2:
        cout<<"Thu 7"<<endl;
        break;
    case 3:
        cout<<"Chu nhat"<<endl;
        break;
    case 4:
        cout<<"Thu 2"<<endl;
        break;
    case 5:
        cout<<"Thu 3"<<endl;
        break;
    case 6:
        cout<<"Thu 4"<<endl;
        break;
    default:
        break;
    }
}