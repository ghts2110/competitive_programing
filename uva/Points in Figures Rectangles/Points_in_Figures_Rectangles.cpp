#include<iostream>
using namespace std;

int main(){

    char r;
    int qtd=0, point=0;
    double x,y, ret[11][4];
    while(cin>>r && r!='*'){
        qtd++;
        cin>> ret[qtd][0]>> ret[qtd][1]>> ret[qtd][2]>> ret[qtd][3];
    }

    while(cin>>x>>y){
        if(x==9999.9 && y==9999.9){
            break;
        }

        bool isContained=false;
        point++;
        for(int i=1;i<=qtd;i++){
            if(x>ret[i][0] && x<ret[i][2]){
                if(y>ret[i][3] && y<ret[i][1]){
                    printf("Point %d is contained in figure %d\n",point,i);
                    isContained=true;
                }
            }
        }

        if(!isContained){
            printf("Point %d is not contained in any figure\n",point);
        }

    }

    return 0;
}
