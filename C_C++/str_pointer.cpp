#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char *s, *t;
    int m, n, i;
    s = new char[30];
    t = new char[30];
    cout<<"Nhap xau s: "<<endl;
    cin.getline(s, 29);
    cout<<"Nhap vi tri va do dai can sao chep: "<<endl;
    cin>>m>>n;
    strncpy(t, s+m, n);
    t[n] = '\0';
    cout<<t<<endl;
    for (i = 0; i<strlen(s); i++)
    {
        if (s[i] == 32 )
        {
            if (s[i+1] >= 65 && s[i+1] <= 90)
            continue;
            else
            s[i+1] = s[i+1] - 32;
        }
    }
    cout<<s;
}