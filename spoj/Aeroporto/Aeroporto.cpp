#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a, v, test = 1;
    while(1){
        cin >> a >> v;
        vector<int> vec(101), index;

        if(a == 0 && v == 0){
            break;
        }
        
        while(v--){
            int x, y;
            cin >> x >> y;

            vec[x]++;
            vec[y]++;
        }

        int mx = -1;
        for(int i = 1; i <= a; i++){
            if(mx < vec[i]){
                mx = vec[i];
                index.clear();
                index.push_back(i);
            }else if(mx == vec[i]){
                index.push_back(i);
            }
        }

        cout << "Teste " << test << endl;
        test++;

        for(int i = 0; i <= index.size(); i++){
            if(i == index.size() -1){
                cout << index[i] << endl;
                break;
            }
            cout << index[i] << " ";
        }
        cout << endl;
        
    }
}
