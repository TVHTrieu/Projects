#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Student{
    public:
        string hoten, gioitinh;
        string namsinh, diachi;
        string masv, lop;
        float tin1, tin2, tin3, tin4, anh1, anh2;
        float DTB;
        void nhap(){
            cout<<"Nhap ho ten sinh vien: ";getline(cin, hoten);
            cout<<"Nhap gioi tinh: ";getline(cin, gioitinh);
            cout<<"Nhap nam sinh: ";getline(cin, namsinh);
            cout<<"Nhap dia chi: ";getline(cin, diachi);
            cout<<"Nhap ma so sinh vien: ";cin>>masv;
            cout<<"Nhap lop: ";cin>>lop;
            cout<<"Nhap diem tin 1: ";cin>>tin1;
            cout<<"Nhap diem tin 2: ";cin>>tin2;
            cout<<"Nhap diem tin 3: ";cin>>tin3;
            cout<<"Nhap diem tin 4: ";cin>>tin4;
            cout<<"Nhap diem anh 1: ";cin>>anh1;
            cout<<"Nhap diem anh 2: ";cin>>anh2;
            DTB = (tin1+tin2+tin3+tin4+anh1+anh2)/6;
            cout<<endl;
        }

        void hienthi(){
            cout<<setw(11)<<hoten<<setw(15)<<gioitinh<<setw(11)<<namsinh; 
            cout<<endl;
            cout<<setw(11)<<diachi<<setw(15)<<masv<<setw(11)<<lop;
            cout<<endl;
            cout<<setw(11)<<tin1<<setw(15)<<tin2<<setw(10)<<tin3<<setw(10)<<tin4;
            cout<<endl;
            cout<<setw(11)<<anh1<<setw(15)<<anh2;

            cout<<" "<<setw(12)<<setprecision(3)<<DTB;

            if(DTB>=9)
            cout<<" Xep loai gioi"<<endl;
            else if(DTB>=7)
            cout<<" Xep loai kha"<<endl;
            else if(DTB>=5)
            cout<<" Xep loai trung binh"<<endl;
            else if(DTB<5)
            cout<<" Xep loai yeu"<<endl;
            cout<<endl;
        }

};

class QLSV : public Student{
    private:
        vector<Student> sv;
        Student temp;
        int n;
    public:
        void nhap(){
            cout<<"Nhap so luong sinh vien: ";cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Nhap sinh vien thu "<<i+1<<endl;
                cin.ignore(1);
                temp.nhap();
                sv.push_back(temp);
            }
        }
        void hienthi(){
            for(int i=0;i<sv.size();i++){
                sv[i].hienthi();
            }
        }
        void xeploaiHL(){
            cout<<"Sinh vien xep loai hoc luc gioi "<<endl;
            for(int i=0;i<sv.size();i++){
                if(sv[i].DTB>=9){
                    sv[i].hienthi();
                }
            }
            cout<<"Sinh vien xep loai hoc luc kha "<<endl;
            for(int i=0;i<sv.size();i++){
                if(sv[i].DTB>=7 && sv[i].DTB<9){
                    sv[i].hienthi();
                }
            }
            cout<<"Sinh vien xep loai hoc luc trung binh "<<endl;
            for(int i=0;i<sv.size();i++){
                if(sv[i].DTB>=5 && sv[i].DTB<7){
                    sv[i].hienthi();
                }
            }
            cout<<"Sinh vien xep loai hoc luc yeu "<<endl;
            for(int i=0;i<sv.size();i++){
                if(sv[i].DTB<5){
                    sv[i].hienthi();
                }
            }
        }
        void dssvDTBtd(){
            cout<<"Danh sach sinh vien diem trung binh tang dan "<<endl;
            Student td;
            for(int i=0;i<sv.size()-1;i++){
                for(int j=i+1;j<sv.size();j++){
                    if(sv[i].DTB>sv[j].DTB){
                        td = sv[i];
                        sv[i] = sv[j];
                        sv[j] = td;
                    }
                }
            }
            hienthi();
        }
        void dssvDTBgd(){
            cout<<"Danh sach sinh vien diem trung binh giam dan "<<endl;
            Student gd;
            for(int i=0;i<sv.size()-1;i++){
                for(int j=i+1;j<sv.size();j++){
                    if(sv[i].DTB<sv[j].DTB){
                        gd = sv[i];
                        sv[i] = sv[j];
                        sv[j] = gd;
                    }
                }
            }
            hienthi();
        }
        void timsvDTBMax(){
            cout<<"Sinh vien co diem trung binh cao nhat "<<endl;
            int max = 0;
            for(int i=0;i<sv.size();i++){
                if(sv[i].DTB>max){
                    max = sv[i].DTB;
                }
            }
            for(int i=0;i<sv.size();i++){
                if(sv[i].DTB==max){
                    sv[i].hienthi();
                }
            }
        }
        void timkiemSV(){
            string mssv;
            int flag = 0;
            cout<<"Nhap ma sinh vien can tim: ";fflush(stdin);getline(cin, mssv);
            for(int i=0;i<sv.size();i++){
                if(mssv == sv[i].masv){
                    sv[i].hienthi();
                    flag++;
                }
            }
            if(flag==0)
            cout<<"Khong tim thay sinh vien "<<endl;
        }
};

int main(){
    int n, option;
    QLSV *s = new QLSV;
    cout<<"--Day la chuong trinh quan li sinh vien--"<<endl;
    cout<<"Vui long nhap so nguyen duong de tiep tuc: ";cin>>n;
    while(n>0){
        cout<<"1. Nhap thong tin sinh vien"<<endl;
        cout<<"2. Hien thi thong tin sinh vien"<<endl;
        cout<<"3. Xep loai hoc luc sinh vien"<<endl;
        cout<<"4. Sap xep sinh vien theo diem trung binh tang dan"<<endl;
        cout<<"5. Sap xep sinh vien co diem trung giam dan"<<endl;
        cout<<"6. Thong tin sinh vien co diem trung binh cao nhat"<<endl;
        cout<<"7. Tim kiem sinh vien theo mssv"<<endl;
        cout<<"Moi ban chon so tuong ung: ";cin>>option;
        switch (option)
        {
        case 1:
            s->nhap();
            break;
        case 2:
            s->hienthi();
            break;
        case 3:
            s->xeploaiHL();
            break;
        case 4:
            s->dssvDTBtd();
            break;
        case 5:
            s->dssvDTBgd();
            break;
        case 6:
            s->timsvDTBMax();
            break;
        case 7:
            s->timkiemSV();
            break;
        default:
            break;
        }
    }
    
    /*
    s->nhap();
    s->xeploaiHL();
    s->hienthi();
    s->dssvDTBtd();
    s->dssvDTBgd();
    s->timsvDTBMax();
    s->timkiemSV();
    */

}