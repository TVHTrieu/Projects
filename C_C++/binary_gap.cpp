#include<iostream>
#include<vector>

using namespace std;

int solution(int N){
    int a;
    vector<int> v, m;
    while(N/2!=0){
        a=N%2;
        v.push_back(a);
        N=N/2;
    }
    a=N%2;
    v.push_back(a);
    int no_ones = 0;
    for(int i=0;i<v.size();i++){
        int count = 0;
        if(v[i]==1){
            for(int j=i+1;j<v.size();j++){
                if(v[j]==0){
                    count++;
                }
                else{
                    m.push_back(count);
                    break;
                }
            }
        }
    }
   if(m.size()==0){
    return 0;
   }
   else{
    int max=m[0];
    for(int i=0;i<m.size();i++){
        if(m[i]>max){
            max=m[i];
        }
    }
    return max;
   }
}

int main(){

    int N;
    cin>>N;

    cout<<solution(N);

}