#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n], b[n], c[n], d[n];
    for(int i = 0; i < n; ++i)
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

    vector<int> ab, cd;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cd.push_back(c[i] + d[j]);
			ab.push_back(a[i] + b[j]);
        }
    }
    
	sort(ab.begin(), ab.end());

	pair<vector<int>::iterator, vector<int>::iterator> have;
	int cont = 0;
	for(int i = 0; i < ab.size(); ++i){
        have = equal_range(ab.begin(), ab.end(), -cd[i]);
		cont += have.second - have.first;
	}

    cout << cont << endl;

    return 0;
}
