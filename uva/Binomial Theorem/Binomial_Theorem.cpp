#include<iostream>
#include<string>
#include<vector>
using namespace std;

unsigned long int c[51][51];

void calcular(){
    c[1][0]=1;
    c[1][1]=1;
    for(int i=2;i<=50;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++){

            c[i][j]=c[i-1][j-1]+c[i-1][j];

            //cout<<c[i][j]<<" ";
        }
        //cout<<endl;
    }
}

int main(){

    calcular();

    string x;
    //string a,b;

    int caso,potencia;
    scanf("%d",&caso);
    for(int i=1;i<=caso;i++){
        vector <char> nome;
        char onde=1;
        cin>>x;
        //scanf("%c",&x);
        while(x[onde]!='+'){
            nome.push_back(x[onde]);
            onde++;
        }

        string a(nome.begin(), nome.end());

        nome.clear();
        onde++;
        while(x[onde]!=')'){
            nome.push_back(x[onde]);
            onde++;
        }

        string b(nome.begin(),nome.end());

        //scanf("%c",&x);
        //scanf("%d",&potencia);
        
        onde+=2;
        if(x.size()-onde==1){
            potencia=x[onde]-'0';
        }
        else{
            int aux=(x[onde]-'0')*10;
            potencia=x[onde+1]-'0';
            potencia+=aux;
        }
        
        //cout<<potencia<<"***"<<endl;

        printf("Case %d: ",i);

        if(potencia==1){
            cout<<a<<"+"<<b<<endl;
            continue;
        }

        int pa=potencia, pb=0;
        for(int j=0;j<=potencia;j++){
            if(pb==0){
                cout<<a<<"^"<<pa<<"+";
                pa--;pb++;
                continue;
            }
            if(pa==0){
                cout<<b<<"^"<<pb<<endl;
                pa--;pb++;
                continue;
            }

            cout<<c[potencia][j]<<"*";
            //printf("%d*",c[potencia][j]);

            if(pa==1){
                cout<<a<<"*";
            }
            else{
                cout<<a<<"^"<<pa<<"*";
            }

            if(pb==1){
                cout<<b<<"+";
            }
            else{
                cout<<b<<"^"<<pb<<"+";
            }

            pa--;pb++;

        }
    }

    return 0;
}
