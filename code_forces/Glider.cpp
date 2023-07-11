#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> start, end;

    for (int i = 0; i != n; i++){
        int nm;

        cin >> nm;
        start.push_back(nm);

        cin >> nm;
        end.push_back(nm);
    }

    vector<long long> isflows, notflows;
    for (int i = 0; i <= n; i++){
        if(i == 0){
            notflows.push_back(0);
            isflows.push_back(0);
            continue;
        }
        isflows.push_back(end[i - 1] - start[i - 1] + isflows[i - 1]);
    
        if(i == n){
            notflows.push_back(1e15);
            break;
        }

        notflows.push_back(start[i] - end[i - 1] + notflows[i - 1]);
    }

    int j = 0;
    long long value = 0;
    for (int i = 0; i <= n; i++) {
        while (notflows[j] - notflows[i] < h && j != n){
            j++;
        }
        
        value = max(value, h + isflows[j] - isflows[i]);
    }

    cout << value << endl;
}
