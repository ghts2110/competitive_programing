#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

bool validate(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2, 
        pair<int, pair<int, int>> p3, pair<int, pair<int, int>> p4){

    int a1 = p2.first - p1.first;
    int b1 = p2.second.first - p1.second.first;
    int c1= p2.second.second - p1.second.second;
    int a2 = p3.first - p1.first;
    int b2 = p3.second.first - p1.second.first;
    int c2 = p3.second.second - p1.second.second;

    int a = b1*c2-b2*c1;
    int b = a2*c1-a1*c2;
    int c = a1*b2-a2*b1;
    int d = -a*p1.first-b*p1.second.first-c*p1.second.second;

    if(a * p4.first + b * p4.second.first + c * p4.second.second + d == 0)
        return true;

    return false;
}

bool validate2(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2,
        pair<int, pair<int, int>> p3){

    p1.first -= p3.first;
    p1.second.first -= p3.second.first;
    p1.second.second -= p3.second.second;

    p2.first -= p3.first;
    p2.second.first -= p3.second.first;
    p2.second.second -= p3.second.second;

    int a = p1.second.first * p2.second.second - p1.second.second * p2.second.first;
    int b = p1.second.second * p2.first - p1.first * p2.second.second;
    int c = p1.first * p2.second.first - p1.second.first * p2.first;

    return a == 0 && b == 0 && c == 0;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector<pair<int, pair<int, int>>> v(n);
        set<pair<int, pair<int, int>>> st;
        for(int i = 0; i != n; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);

            v[i].first = x;
            v[i].second.first = y;
            v[i].second.second = z;

            st.insert(make_pair(x, make_pair(y, z)));
        }

        if(st.size() <= 3){
            cout << n << endl;
            continue;
        }

        int asw = 3;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(v[i] == v[j] || v[i] == v[k] || v[j] == v[k]){
                        continue;
                    }
                    int cont = 0;

                    if(validate2(v[i], v[j], v[k])){
                        for(int w = 0; w != n; w++){
                            if(validate2(v[i], v[j], v[w])){
                                cont++;
                            }
                        }
                    }else{
                        for(int w = 0; w != n; w++){
                            if(validate(v[i], v[j], v[k], v[w])){
                                cont++;
                            }                         
                        }
                    }

                    asw = max(asw, cont);
                }
            }
        }
        printf("%d\n", asw);
    }
}
