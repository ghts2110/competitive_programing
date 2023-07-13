#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, k;
    string s, newS;
    vector<int> v;

    cin >> n >> k;
    cin >> s;

    int contA = 0, contB = 0;
    for(int i = 0; i != n; i++){
        if(s[i] == 'a'){
            contA++;
        }else{
            contB++;
        }

        if(s[i] == 'a' && contB != 0){
            v.push_back(contB);
            contB = 0;
        }else if(s[i] == 'b' && contA != 0){
            v.push_back(contA);
            contA = 0;
        }
    }

    if(contA != 0){
        v.push_back(contA);
    }else{
        v.push_back(contB);
    }

    int mx = 0;
    for(int i = 0; i != v.size(); i++){
        int convert = k, cont = 0;
        for(int j = i; convert >= 0 && j < v.size(); j++){
            cont += v[j];

            if(j < v.size()-1 && v[j+1] <= convert){
                cont += v[j+1];
                convert -= v[j+1];
                j++;
            }else if(j < v.size()-1 && convert != 0){
                cont += convert;
                convert = -1;
                j++;
            }else{
                break;
            }
        }
        if(convert > 0 && i > 0){
        
            cont += min(v[i-1], convert);
        }
   
        mx = max(mx, cont);
    }

    cout << mx << endl;
}
