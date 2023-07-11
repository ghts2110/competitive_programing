#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int t;
    bitset<10000> bt(0);

    while(1){
        int cont = 0;
        char lt, fistlt;
        cin >> t;

        if(t== 0){
            break;
        }

        int pre, end, start;
        cin >> start >> end;
        if(start > end){
            fistlt = 'l';
            lt = 'l';
            cont++;
        }else if(start < end){
            lt = 't';
            fistlt = 't';
            cont++;
        }
        
        pre = end;
        t -= 2;

        while(t--){
            cin >> end;
            if(pre > end && lt == 't'){
                lt = 'l';
                cont++;
            }else if(pre < end && lt == 'l'){
                lt = 't';
                cont++;
            }

            pre = end;
        }

        if(end > start && lt == 't' && fistlt == 't'){
            cont++;
        }else if(end < start && lt == 'l' && fistlt == 'l'){
            cont++;
        }

        cout << cont << endl;
    }
}
