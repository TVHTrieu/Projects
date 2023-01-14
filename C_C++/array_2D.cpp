#include<iostream>

using namespace std;

int sum(int A[][100], int B[][100], int m, int n);
int max(int A[][100], int B[][100], int m, int n);
int summax(int A[][100], int B[][100], int m, int n);
int sort(int A[][100], int B[][100], int m, int n);

int main(){

    int A[100][100], B[100][100];
    int i, j, m ,n;
    cout<<"Nhap so hang va so cot cua ma tran: "<<endl;
    cin>>m>>n;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout<<"A["<<i<<"]["<<j<<"] = ";
            cin>>A[i][j];
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout<<"B["<<i<<"]["<<j<<"] = ";
            cin>>B[i][j];
        }
    }
    sum(A, B, m, n);
    max(A, B, m, n);
    summax(A, B, m, n);
    sort(A, B, m, n);

}

int sum(int A[][100], int B[][100], int m, int n)
{
    int C[100][100], i, j;
    cout<<"Ma tran A: "<<endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            
            cout<<"A["<<i<<"]["<<j<<"] = "<<A[i][j]<<" ";
        }
    }
    cout<<endl<<"Ma tran B: "<<endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            
            cout<<"B["<<i<<"]["<<j<<"] = "<<B[i][j]<<" ";
        }
    }
    cout<<endl<<"Ma tran tong: "<<endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            cout<<"A["<<i<<"]["<<j<<"] = "<<C[i][j]<<" ";
        }
    }
    cout<<endl;
}

int max(int A[][100], int B[][100], int m, int n)
{
    int maxA, maxB, i, j;
    maxA = A[0][0];
    maxB = B[0][0];
    for (i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (A[i][j] > maxA)
            {
                maxA = A[i][j];
            }
        }
    }
    cout<<"Gia tri lon nhat cua ma tran A: "<<maxA<<endl;
    for (i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (B[i][j] > maxB)
            {
                maxB = B[i][j];
            }
        }
    }
    cout<<"Gia tri lon nhat cua ma tran B: "<<maxB<<endl;
    if(maxA > maxB)
    {
        cout<<"Gia tri lon nhat tren ca hai ma tran la: "<<maxA<<endl;
    }
    else
    {
        cout<<"Gia tri lon nhat tren ca hai ma tran la: "<<maxB<<endl;
    }
}

int summax(int A[][100], int B[][100], int m, int n)
{
    int i, j, sA, sB;
    sA = 0;
    sB = 0;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            sA = sA + A[i][j];
        }
    }
    cout<<"Tong phan tu ma tran A: "<<sA<<endl;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            sB = sB + B[i][j];
        }
    }
    cout<<"Tong phan tu ma tran B: "<<sB<<endl;
    if (sA>sB)
    {
        cout<<"Tong phan tu ma A lon hon "<<endl;
    }
    else
    {
        cout<<"Tong phan tu ma tran B lon hon "<<endl;
    }
}

int sort(int A[][100], int B[][100], int m, int n)
{
    int i, j, c, d, t;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for( c = 0; c < m; c++)
            {
                for ( d = 0; d < n; d++)
                {
                    if (A[c][d]>A[i][j])
                    {
                        t = A[i][j];
                        A[i][j] = A[c][d];
                        A[c][d] = t;
                    }
                }
            }
        }
    }
    cout<<endl<<"Ma tran A: "<<endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            
            cout<<"A["<<i<<"]["<<j<<"] = "<<A[i][j]<<" ";
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for( c = 0; c < m; c++)
            {
                for ( d = 0; d < n; d++)
                {
                    if (B[c][d]<B[i][j])
                    {
                        t = B[i][j];
                        B[i][j] = B[c][d];
                        B[c][d] = t;
                    }
                }
            }
        }
    }
    cout<<endl<<"Ma tran B: "<<endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            
            cout<<"B["<<i<<"]["<<j<<"] = "<<B[i][j]<<" ";
        }
    }
}