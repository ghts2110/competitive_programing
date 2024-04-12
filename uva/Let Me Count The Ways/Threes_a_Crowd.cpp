#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){

    vector <vector <int>> coor;
    int a,b,c,d,arvores=0;
    cin>>a>>b>>c;
    while(a+b+c>0){
        arvores++;
        vector <int> valores;
        valores.push_back(a);
        valores.push_back(b);
        valores.push_back(c);

        coor.push_back(valores);
        cin>>a>>b>>c;
    }

    int qtd[11]={0,0,0,0,0,0,0,0,0,0};
    int menor;
    for(int i=0;i<arvores;i++){
        for(int j=0;j<arvores;j++){
            if(i==j){
                continue;
            }

            a=abs(coor[i][0]-coor[j][0]);
            b=abs(coor[i][1]-coor[j][1]);
            c=abs(coor[i][2]-coor[j][2]);
            d=(a*a)+(b*b)+(c*c);
            if(j==0){
              menor=d;  
            }
            else if(d<menor){
                menor=d;
            }
        }

        for(int j=1;j<=10;j++){
            if(menor<j*j){
                qtd[j]++;
                break;
            }
        }
    }

    for(int i=1;i<=10;i++){
        printf("%4d",qtd[i]);
    }
    cout<<endl;

    return 0;
}
