#include<iostream>
#include<string>

using namespace std;

int solution(string s);

int main()
{
    
    string s;
    getline(cin, s);
    cout<<solution(s);
    
}

int solution(string s)
{
    int count = 0, c; 
    c = s.find("aaa");
    if (c != -1)
    {
        return -1;
    }
    else
    {
        for (int i=0;i<s.length();i++)
        {
            if(s[i]=='a'){
                if(s[i+1]=='a'){
                    i++;
                }
                else{
                    s.insert(i+1, "a");
                    count=count+1;
                    i++;
                }
            }
            else{
                if(s[i+1]=='a'){
                    if(s[i+2]=='a'){
                        i=i+2;
                    }
                    else{
                        s.insert(i+2, "a");
                        count=count+1;
                        i=i+2;
                    }
                }
                else{
                    s.insert(i+1, "aa");
                    count=count+2;
                    i = i+2;
                }
                
            }
        }
        string subsFront = s.substr(0, 2);
        string subsBack = s.substr(s.length()-2, 2);
        if(subsBack!="aa"){
            s.insert(s.length(), "aa");
            count = count + 2;
        }
        if(subsFront!="aa"){
            s.insert(0, "aa");
            count = count + 2;
        }
        return count;
    }
}
