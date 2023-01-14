#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char ch, *pc;
    pc = &ch;
    *pc = 'A';
    cout<<ch;

}