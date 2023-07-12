#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, c, m, mx = -1, turma = 1;
    vector<int> v;

    while(1){
        cin >> n;
    
        if(n == 0){
            break;
        }

        while(n--){
            cin >> c >> m;
            if(m > mx){
                v.clear();
                mx = m;
                v.push_back(c);
            }else if(m == mx){
                v.push_back(c);
            }
        }

        cout << "Turma " << turma << endl;
        for(int i = 0; i != v.size(); i++){
            if(i == v.size() - 1){
                cout << v[i] << endl;
                break;
            }
            cout << v[i] << " ";
        }
        cout << endl; 
        turma++;
        mx = -1;
    }
}
