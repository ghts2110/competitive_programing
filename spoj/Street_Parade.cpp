#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }

        int mn = 1e9;
        deque<int> f;
        deque<int> p1, p2;

        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            f.push_back(num);
            mn = min(mn, num);
        }

        for(int i = 0; i != n; i++){
            while(p1.size() != 0 && p1.back() == mn){
                p2.push_back(p1.back());
                p1.pop_back();

                mn = 1e9;
                for(int j = 0; j != p1.size(); j++){
                    mn = min(mn, p1[j]);
                }

                for(int j = 0; j != f.size(); j++){
                    mn = min(mn, f[j]);
                }
            }
            
            if(f.size() != 0 && f.front() != mn){
                p1.push_back(f.front());
                f.pop_front();
                i--;
            }

            while(f.size() != 0 && f.front() == mn){
                p2.push_back(f.front());
                f.pop_front();

                mn = 1e9;

                for(int j = 0; j != p1.size(); j++){
                    mn = min(mn, p1[j]);
                }

                for(int j = 0; j != f.size(); j++){
                    mn = min(mn, f[j]);
                }

            }

        }

        if(p1.size() == 0){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }    
}
