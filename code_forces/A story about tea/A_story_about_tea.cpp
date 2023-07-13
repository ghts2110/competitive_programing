#include <iostream>

using namespace std;

int boat;

void hanoi(int n, char start, char apoio, char objetivo){
    if(n == 0){
        return;
    }
    hanoi(n-1, start, objetivo, apoio);
    printf("%c %c\n", start, objetivo);
    hanoi(n-1, apoio, start, objetivo);
}

int main(){
    int k;
    cin >> boat >> k;

    if(k < (1<<boat)-1 || k == (1<<boat)){
        cout << "N" << endl;
        return 0;
    }else{
        cout << "Y" << endl;
    }

    hanoi(boat, 'A', 'B', 'C');
    k -= (1<<boat)-1;

    for(int i = 0; i != k; i++){
        if(i == 0){
            printf("C A\n");
            continue;
        }

        if(i == k-1){
            if(i % 2 == 1){
                printf("A C\n");
            }else{
                printf("B C\n");
            }
            break;
        }
        
        if(i % 2 == 1){
            printf("A B\n");
        }else{
            printf("B A\n");
        }
    }
}
