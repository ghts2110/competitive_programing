#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    string v1,v2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v1>>v2;
        int j=0;
        /*vector <char> v1,v2;
        while(s[j]!=' '){
            v1.push_back(s[j]);
            j++;
        }
        j++;
        while(j<s.size()){
            v2.push_back(s[j]);
        }*/

        int n,aux,printar, res=0;
        bool primeiro=true;
        while(true){
            if(j>=v1.size() && j>=v2.size()){
                break;
            }

            if(j>=v1.size()){
               n=v2[j]-'0';
               n+=res;
               printar=n%10;
               res=n/10;
            }
            else if(j>=v2.size()){
                n=v1[j]-'0';
                n+=res;
                printar=n%10;
                res=n/10;
            }
            else{
                int n1=v1[j]-'0';
                int n2=v2[j]-'0';
                n=n1+n2+res;
                printar=n%10;
                res=n/10;
            }


            if(printar==0 && primeiro==true){
                j++;
            }
            else{
                j++;
                primeiro=false;
                cout<<printar;
            }
        }


        while(res>0){
            printar=res%10;
            cout<<printar;
            res/=10;
        }

        cout<<endl;
    }


}
