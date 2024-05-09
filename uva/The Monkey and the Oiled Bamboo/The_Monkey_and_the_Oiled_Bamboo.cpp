#include<istream>
#include<vector>
using namespace std;

int main(){

    int t, r,a;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int menor,onde;
        scanf("%d %d",&r,&menor);
        vector<int> rungs;
        onde=menor-1;
        rungs.push_back(menor);
        for(int j=1;j<r;j++){
            scanf("%d",&a);
            rungs.push_back(a);
            int pulo=a-rungs[j-1];

            if(pulo>menor){
                menor=pulo;
                onde=menor-1;
            }
            else if(pulo==onde){
                onde--;
            }
            else if(pulo>onde){
                menor++;
                onde=menor;
            }

            if(onde<1 && j<t){
                menor++;
                onde=menor;
            }
        }

        printf("Case %d: %d\n",i,menor);
    }

    return 0;
}