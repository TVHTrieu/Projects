#include<iostream>
#include<vector>
#include <algorithm>


using namespace std;

int main()
{
    int n, a;
    do
    {
    cout<<"Enter the number of intergers: ";
    cin>>n;
    }
    while(n < 1 && n >= 100*100);
    vector<int> v;
    cout<<"Enter the numbers in the vector: ";
    for (int i = 0; i < n; i++)
    {
        cin.ignore(1);
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for (const int& i : v)
    cout<<i<<" ";
}