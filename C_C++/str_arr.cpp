#include<iostream>
#include<string.h>

using namespace std;

void Output(char str[]);
void Number(char str[], int n);
void remove(char str[], int n);
void upper(char str[], int n);
void insert(char str[], char str2[], int n, int x);

int main(){

    char str[100], str2[100];
    int n, x;
    cout<<"Nhap xau: "<<endl;
    cin.getline(str, 99);
    Output(str);
    n = strlen(str);
    Number(str, n);
    remove(str, n);
    upper(str, n);
    cout<<"Nhap xau muon chen va vi tri chen: "<<endl;
    cin.getline(str2, 99);
    cin>>x;
    insert(str, str2, n, x);


}

void Output(char str[])
{
    cout<<"Xau da nhap la: "<<str<<endl;
}

void Number(char str[], int n)
{
    int i, count = 0, m=0;
    for ( i = 0; i < n; i++)
    {
        if (str[i]>=48 && str[i]<=57)
        {
            m = m + 1;
        }
        count = count + 1;
    }
    cout<<"So ki tu la so la: "<<m<<endl;
    cout<<"So ki tu la: "<<count<<endl;
}

void remove(char str[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        while ((str[i]>=33 && str[i]<=64) || (str[i]>=91 && str[i]<=96) || (str[i]>=123 && str[i]<=126))   //33<=str[i]<=64 || 91<=str[i]<=96 || 123<=str[i]<=126
        {
            for (int j = i; j < n; j++)
            {
                str[j] = str[j+1];
            }
        }
    }
    cout<<str<<endl;
}

void upper(char str[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if (97<=str[i] && str[i]<=122)
        {
            str[i] = str[i] - 32;
        }
    }
    cout<<str<<endl;
}

void insert(char str[], char str2[], int n, int x)
{
    int i, p, j, g;
    char s[100];
    strcpy(s, str + x);
    p = strlen(str2);
    for (i = 0; i < n; i++)
    {
        if ( i == x)
        {
            strcpy(str + x, str2);
        }
    }
    strcat(str, s);
    cout<<str<<endl;
}