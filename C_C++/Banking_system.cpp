#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User{
    private:
        string name;
        int age;
        string gender;
    public:
        User(const string &ten, int tuoi, const string &gioitinh)
        : name(ten), age(tuoi), gender(gioitinh)
        {}

        void show_details()
        {
            cout << name << " " << age << " " << gender << endl;
        }
};

class Bank : public User{
    private:
        int amount, balance;
    public:
        Bank(const string &ten, int tuoi, const string &gioitinh)
        : User(ten, tuoi, gioitinh)
        {balance = 0;}

        void deposit(int soluong){
            amount = soluong;
            balance = balance + amount;
            cout<<balance<<endl;
        }
        
        void withdraw(int soluong){
            amount = soluong;
            if(amount>balance){
            cout<<"Insufficient"<<endl;
            }
            else{
            balance = balance - amount;
            cout<<balance<<endl;
            }  
        }

        void view_balance(){
            show_details();
            cout<<balance;
        }


    
};

int main(){
    Bank *johan = new Bank("johan", 20, "male");
    johan->deposit(100);
    johan->deposit(400);
    johan->withdraw(1000);
    johan->view_balance();
}