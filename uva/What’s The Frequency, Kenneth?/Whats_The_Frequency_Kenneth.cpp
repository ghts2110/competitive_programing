#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;
int main(){
    string a;
    int t,maior;

    while(getline(cin,a)){
        if(a==""){break;}
        maior=0;
        map <char, int> letras;
        vector <char> v;
        t=a.size();
        for (int i=0; i<t; i++){
            if(a[i]<65 || a[i]>122){
                continue;
            }
            if(a[i]>90 && a[i]<97){
                continue;
            }

            letras[a[i]]++;
        }
        for(auto it:letras){
            if(it.second>maior){
                v.clear();
                maior=it.second;
                v.push_back(it.first);
            }
            else if(it.second==maior){v.push_back(it.first);}
        }

        for(int i=0;i<v.size();i++)
        {
            printf("%c",v[i]);
        }
        printf(" %d\n",maior);
    }

    return 0;
}
