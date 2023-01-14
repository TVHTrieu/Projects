#include<iostream>
#include<string.h>

using namespace std;

void Output(char A[][100], int n);
void Find(char A[][100], int n, char S[]);
void Sort(char A[][100], int n);
void Upper(char A[][100], int n);

int main()
{
    char A[50][100], S[] = "Nguyen";
    int n, i;
    cout<<"Nhap so luong sinh vien"<<endl;
    cin>>n;
    while (n>50)
    {
        cin>>n;
    }
    cin.ignore(1);
    for ( i = 0; i < n; i++)
    {
        cout<<"Nhap sinh vien thu "<<i+1<<endl;
        cin.getline(A[i], 99);
    }
    Output(A, n);
    Find(A, n, S);
    Sort(A, n);
    Upper(A, n);

}

void Output(char A[][100], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        cout<<"A["<<i<<"] = "<<A[i]<<endl;
    }
}

void Find(char A[][100], int n, char S[])
{
    int i, count, k = 0;
    for ( i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < strlen(A[i]); j++)
        {
            if (A[i][j] != 32)
            {
                count = count + 1;
            }
            else
            {
                break;
            }

        }
        if (strncmp(S, A[i], count) == 0)
        {
            k = k + 1;
        }

    }
    cout<<"So nguoi co ho "<<S<<" la "<<k<<endl;
    
}

void Sort(char A[][100], int n)
{
    int i;
    char H[100];
    for (i = 0; i<n-1; i++)
    {
        for (int j = i + 1; j<n; j++)
        {
            if(strncmp(A[i], A[j], 1) > 0)
            {
                strcpy(H, A[i]);
                strcpy(A[i], A[j]);
                strcpy(A[j], H);
            }
        }
    }
    Output(A, n);
}

void Upper(char A[][100], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j<strlen(A[i]); j++)
        {
            if (A[i][j] >= 65 && A[i][j] <= 90)
            {
                continue;
            }
            else if (A[i][j] >= 97 && A[i][j] <= 122)
            {
                A[i][j] = A[i][j] - 32;
            }
        }
    }
    cout<<"Cau d: "<<endl;
    Output(A, n);
}
