#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    int n, a[10000], b[10000], temp, i;
    fstream file;
    file.open("1.txt", ios::out);
    cout<<"Nhap so phan tu: ";
    cin>>n;
    for ( int i = 0; i < n; i++)
    {
        cout<<"Nhap phan tu thu "<<i+1<<endl;
        cin>>a[i];
        file<<a[i]<<" ";
    }
    file.close();
    
    file.open("1.txt", ios::in);    
    i = 0;
    while(file>>b[i])
    {
        i = i + 1;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[j] < b[i])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    
    for ( int i = 0; i < n; i++)
    {
        cout<<b[i]<<" ";
    }
    file.close();
   
    file.open("2.txt", ios::out);
    for ( int i = 0; i < n; i++)
    {
        file<<b[i]<<" ";
    }
    file.close();
    

}
