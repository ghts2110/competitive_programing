#include <stdio.h>
#include <vector>

using namespace std;

vector<int> v;
int num;

int bs(int start, int end){
    int mid = (end + start)/2;
   
    if(end < start){
        return -1;
    }

    if(v[mid] == num){
        if(mid == 0 || v[mid-1] != num){
            return mid;
        }else{
            return bs(start, mid - 1);
        }

    }else if(v[mid] < num){
        return bs(mid+1, end);
    }else{
        return bs(start, mid-1);
    }

}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    
    while(n--){
        scanf("%d", &num);
        v.push_back(num);
    }

    while(q--){
        scanf("%d", &num);
        printf("%d\n", bs(0, v.size()-1));
    }
}
