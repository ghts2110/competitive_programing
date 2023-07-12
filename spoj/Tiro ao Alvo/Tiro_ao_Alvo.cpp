#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long dist;
vector<long long> raio;

int main(){
    int c, t;
    cin >> c >> t;

    for(int i = 0; i != c; i++){
        long long num;
        cin >> num;

        raio.push_back(num * num);
    }

    long long cont = 0, index;
    for(int i = 0; i != t; i++){
        long long x, y;
        cin >> x >> y;
        dist = pow(x,2)+pow(y,2);

        if(dist <= raio[0]){
            index = 0;
        }else if(dist > raio[c-1]){
            index = c;
        }else{
            index = lower_bound(raio.begin(), raio.end(), dist) - raio.begin(); 
        }

        cont += c - index;
    }

    cout << cont << endl;
}
