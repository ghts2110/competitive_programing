#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    vector<int> p(2);

    for(int i = 0; i != n; i++){
      int num;
      cin >> num;

      if(num % 2 == 0){
        p[0]++;
      }else{
        p[1]++;
      }
    }

    int m;
    cin >> m;

    long long asw = 0;
    for(int i = 0; i != m; i++){
      int num;
      cin >> num;

      if(num % 2 == 0){
        asw += p[0];
      }else{
        asw += p[1];
      }
    }

    cout << asw << endl;
  }
}