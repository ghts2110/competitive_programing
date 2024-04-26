#include<iostream>
using namespace std;

int main(){

    int l,h,r, primeiro,ultimo;
    bool p=true;
    int rua[10001]={0};
    while(scanf("%d %d %d",&l,&h,&r)==3){
        
        if(p){
            primeiro=l;
            ultimo=l;
            p=false;
        }
        for(int i=l;i<r;i++){
            if(rua[i]<h){
                rua[i]=h;
            }    
        }
        if(r>ultimo){
            ultimo=r;
        }
    }

    printf("%d %d ",primeiro,rua[primeiro]);
    for(int i=primeiro+1;i<ultimo;i++){
        if(rua[i]!=rua[i-1]){
            printf("%d %d ",i,rua[i]);
        }
    }
    printf("%d 0\n",ultimo);



    return 0;
}
