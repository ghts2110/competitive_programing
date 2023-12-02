#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<pair<int, int> > v;
    v.push_back(make_pair(1, 1));
    int sum = 1;
    vector<pair<int, int> > absS;
    while((v.end()-1)->second < 1e9){
        absS.push_back(make_pair(sum, sum+2));
        v.push_back(make_pair((v.end()-1)->first+sum, (v.end()-1)->second+sum+2));
        sum += 2;
    }

    int t;
    cin >> t;

    for(int test = 0; test != t; test++){
        if(test){
           cout << endl;
        }

        int n, m;
        cin >> n >> m;

        if(n > m){
            int save = n;
            n = m;
            m = save;
        }

        int l1 = -1, l2 = -1;
        for(int i = 0; i != v.size(); i++){
            if(v[i].second >= n && l1 == -1){
                l1 = i+1;
            }
            if(v[i].second >= m && l2 == -1){
                l2 = i+1;
                break;
            }
        }

        int sum1 = absS[l1-1].first, sum2 = absS[l1-1].second;
        int n1 = n, n2 = n;

        while(n1 < m && n2 < m){
            n1 += sum1;
            n2 += sum2;
            sum1 += 2;
            sum2 += 2;
        }

        if(n1 <= m && n2 >= m){
            long long asw = (l2 - l1)*2;
            if(l1%2 != n%2 && l2%2 == m%2){
                asw++;
            }else if(l1%2 == n%2 && l2%2 != m%2){
                asw--;
            }
            cout << asw << endl;
        }else{
            long long asw = (l2 - l1)*2;
            if(v[l2-1].first <= n1 && v[l2-1].second >= n1){
                asw += n1 - m;
            }else{
                n2 -= sum2;
                n2 += 2;
                asw += m - n2;
            }

            cout << asw << endl;
        }
    }
}