#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> v;

    for(int i = 0; i != t; i++){
        int num;
        cin >> num;
        v.push_back(num);    
    } 

    int s = 0, d = 0, start = 0, end = t-1, i = -1;
    while(1){
        i++;
        if(i % 2 == 0){
            int mx;
            if(v[start] > v[end]){
                mx = start;
                start++;
            }else{
                mx = end;
                end--;
            }

            s += v[mx];
        }else{
            int mx;
            if(v[start] > v[end]){
                mx = start;
                start++;
            }else{
                mx = end;
                end--;
            }

            d += v[mx];
        }

        if(start > end){
            break;
        }
    }

    cout << s << " " << d << endl;

}
