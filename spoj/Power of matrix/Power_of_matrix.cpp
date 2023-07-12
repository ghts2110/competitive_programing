#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long> > mult(vector<vector<long long> > A, vector<vector<long long> > B, int n){
    vector<vector<long long> > C(A.size(), vector<long long> (A.size()));

    for (int i = 0; i != n; i++){
        for (int j = 0; j != n; j++){
            long long sum = 0;
            for (int k = 0; k != n; k++){
                sum += ((A[i][k] * B[k][j]) % 1000000007);
            }

            C[i][j] = sum % 1000000007;
        }    
    }

    return C;
}

vector<vector<long long> > pow(int n, int p, vector<vector<long long> > mat){
    int fist = 1;
    vector<vector<long long> > answer(n, vector<long long> (n));

    while(p != 0){
        if(p % 2 == 0){
            mat = mult(mat, mat, n);
            p /= 2;
        }else{
            if(fist == 1){
                fist = 0;
                answer = mat;
            }else{
                answer = mult(answer, mat, n);
            }

            p--;
        }
    }

    return answer;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, p;
        cin >> n >> p;

        vector<vector<long long> > mat(n, vector<long long> (n));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cin >> mat[i][j]; 
            }
        }

        mat = pow(n, p, mat);

        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                if(j == n-1){
                    cout << mat[i][j] << endl;
                    break;
                }
                cout << mat[i][j] << " ";
            }
        }
    }
}
