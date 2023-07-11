#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

int main(){
    int n, k;
    cin >> n >> k;

    int g = 0;
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        g = gcd(g, num);
    }

    set<long long> s;
    long long sum = 0;
    for(int i = 0; i != k; i++){
        s.insert(sum%k);
        sum += g;
    }

    cout << s.size() << endl;
    set<long long>::iterator it = s.begin();
    for(int i = 0; i != s.size(); i++){
        if(i == s.size() - 1){
            cout << *(it) << endl;
            break;
        }
        cout << *(it) << " ";
        it++;
    }
}
