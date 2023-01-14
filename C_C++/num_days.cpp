#include<iostream>

using namespace std;

struct date{
    int ngay, thang;
};

int main()
{
    date day;
    int s = 0;
    cout<<"Nhap ngay thang hien tai: ";
    cin>>day.ngay>>day.thang;
    for (int i = 1; i < day.thang; i++)
    {
        if ((i%2 == 0 && i < 7 && i != 2) || (i%2 != 0 && i > 7))
        {
            s = s + 30;
        }
        else if ((i%2 != 0 && i <= 7) || (i%2 == 0 && i > 7))
        {
            s = s + 31;
        }
        else
        {
            if ((2022%4 == 0 && 2022%100 !=0) || (2022%400 == 0))
            {
                s = s + 29;
            }
            else
            {
                s = s + 28;
            }
        }
    }
    cout<<s + day.ngay - 1;
}