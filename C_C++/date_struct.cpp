#include<iostream>

using namespace std;

struct date{
    int ngay;
    int thang;
    int nam;
};

int main()
{
    date inDay;
    int s = 0;
    cout<<"Nhap ngay thang nam bat ki: "<<endl;
    cin>>inDay.ngay>>inDay.thang>>inDay.nam;
    
    for (int i = 1; i < inDay.nam; i++)
    {
        if ((i%4 == 0 && i%100 != 0) || (i%400 == 0 && i%100 == 0))
        {
            s = s + 366;
        }
        else
        {
            s = s + 365;
        }
    }
    for (int i = 1; i < inDay.thang; i++ )
    {
        if (( i%2 == 0 && i < 7 && i != 2) || ( i > 7 && i%2 != 0))
        {
            s = s + 30;
        }
        else if (( i%2 != 0 && i <= 7) || ( i > 7 && i%2 == 0))
        {
            s = s + 31;
        }
        else
        {
            if ((inDay.nam%4 == 0 && inDay.nam%100 != 0) || (inDay.nam%400 == 0 && inDay.nam%100 == 0))
            {
                s = s + 29;
            }
            else
            {
                s = s + 28;
            }
        }
    }
    s = s + (inDay.ngay-1);
    cout<<s;
}