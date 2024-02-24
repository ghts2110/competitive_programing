#include <iostream>
#include <vector>
#include <string>
using namespace std;

void st(vector<vector<vector<int>>>&mem,int i, int j){
    if(mem[i+1][j].size() > mem[i+1][j+1].size()){
        mem[i+1][j+1] = mem[i+1][j];
    }else if(mem[i+1][j].size() != 0 && mem[i+1][j].size() == mem[i+1][j+1].size() && *(mem[i+1][j+1].end()-1) > *(mem[i+1][j].end()-1)){
        mem[i+1][j+1] = mem[i+1][j];
    }

     if(mem[i][j+1].size() > mem[i+1][j+1].size()){
        mem[i+1][j+1] = mem[i][j+1];
    }else if(mem[i][j+1].size() != 0 && mem[i][j+1].size() == mem[i+1][j+1].size() && *(mem[i+1][j+1].end()-1) > *(mem[i][j+1].end()-1)){
        mem[i+1][j+1] = mem[i][j+1];
    }

}

int main(){
    int t;
    cin >> t; 
    
    int cont = 0;
    string s;
    getline(cin,s);
    getline(cin,s);
    while(t--){

        if(cont != 0){
            cout << endl;
        }

        cont = 1;
        vector<int>v;
        while(getline(cin,s)){

            if(s == ""){
                break;
            }

            int num = stoi(s);
            v.push_back(num);
        }

        int size = v.size();
        vector<vector<vector<int>>>mem(size+1,vector<vector<int>>(size+1));
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(mem[i][j].size() == 0 || v[j] > *(mem[i][j].end()-1)){
                    mem[i+1][j+1] = mem[i][j];
                    mem[i+1][j+1].push_back(v[j]);
                }

                st(mem,i,j);
            }
        }
            
        cout << "Max hits: ";
        cout << mem[size][size].size() << endl;
            
        for(auto it : mem[size][size]){
            cout << it << endl;
        }
        
    }
}
