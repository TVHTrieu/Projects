#include<iostream>

using namespace std;

void even(int arr[], int n);
void min(int arr[], int n);
void sort(int arr[], int n);
int del(int arr[], int n, int x);
int insert(int arr[], int n, int y);

int main(){

    int arr[50], n, x, y, d, m;
    x = 11;
    y = 13;
    cout<<"Nhap so phan tu cua mang"<<endl;
    cin>>n;
    while (n>50)
    {
        cin>>n;
    }
    for (int i = 0;i<=n-1; i++)
    {
        cout<<"arr["<<i<<"] = ";
        cin>>arr[i];
    }
    //Tìm giá trị chẵn > 30
    even(arr, n);
    //Tìm giá trị min và số luần xuất hiện
    min(arr, n);
    // Sắp xếp mảng tăng dần
    sort(arr, n);
    // Xuất ra mảng sau khi sắp xếp
    for (int i = 0;i<=n-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Xóa phần tử với giá trị x trả về số phần tử đã xóa
    d = del(arr, n, x);
    // Tính lại độ dài mảng
    m = n - d;
    // Xuất ra mảng sau khi xóa
    for (int i = 0;i<m; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Chèn vào phần tử y sao cho mảng vẫn tăng dần
    insert(arr, m, y);
    // Xuất ra phần tử sau khi chèn
    for (int i = 0;i<=m; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void even(int arr[], int n)
{
    int i, s = 0;
    for (i = 0; i<=n-1; i++)
    {
        if (arr[i] % 2 == 0 && arr[i] > 30)
        {
            s = s + 1;
        }
    }
    cout<<"So phan tu chan lon hon 30 trong mang la: "<<s<<endl;
}

void min(int arr[], int n)
{
    int i, min, s = 0;
    min = arr[0];
    for (i = 1; i<= n-1; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (i = 0 ; i <= n-1; i++)
    {
        if (arr[i] == min)
        {
            s = s + 1;
        }
    }
    cout<<"Gia tri nho nhat la "<<min<<" voi so lan xuat hien la "<<s<<endl;
}

void sort(int arr[], int n)
{
    int i, j, t;
    for (i = 0; i <= n-2; i++)
    {
        for ( j = i+1; j <= n- 1; j++)
        {
            if (arr[j]<arr[i])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int del(int arr[], int n, int x)
{
    int i, d = 0;
    for (i = 0; i <= n-1; i++)
    {
        while (arr[i] == x)
        {
            for (int j = i; j<=n-1; j++)
            {
                arr[j] = arr[j+1];
            }
            d  = d + 1;
        }
    }
    return d;
}

int insert(int arr[], int n, int y)
{
    int i;
    arr[n] = y; 
    sort(arr, n+1);
}
