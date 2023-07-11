#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, d, l, r, c;
    char s = 'Y';
    cin >> t;
    vector<vector<int> > v(t);

    for(int i = 0; i != t; i++){
        cin >> d >> l >> r >> c;

        if(d == 0){
            v[i].push_back(r);
            v[i].push_back(r);
            v[i].push_back(c);
            v[i].push_back(c + l - 1);
            
            if(c + l - 1 > 10){
                s = 'N';
            }
        }else{
            v[i].push_back(r);
            v[i].push_back(r + l - 1);
            
            if(r + l - 1 > 10){
                s = 'N';
            }

            v[i].push_back(c);
            v[i].push_back(c);
        }

        for(int j = 0; j != v.size() && j != i; j++){
            if(((v[i][0] <= v[j][0] && v[i][0] >= v[j][1]) || (v[i][1] <= v[j][0] && v[i][1] >= v[j][1]) ||
                    (v[j][0] <= v[i][1] && v[j][1] >= v[i][0])) && ((v[i][2] <= v[j][2] && v[i][2] >= v[j][3]) ||
                    (v[i][3] <= v[j][2] && v[i][3] >= v[j][3]) || (v[j][2] <= v[i][3] && v[j][3] >= v[i][2]))){
                s = 'N';
            }
        } 
    }

    cout << s << endl;
}
