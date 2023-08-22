#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        for(int i = 0; i != s.size(); i++){
            if(toupper(s[i])=='W'){
                cout << 'Q'; 
            }else if(toupper(s[i])=='E'){
                cout << 'W';
            }else if(toupper(s[i])=='R'){
                cout << 'E';
            }else if(toupper(s[i])=='T'){
                cout << 'R';
            }else if(toupper(s[i])=='Y'){
                cout << 'T';
            }else if(toupper(s[i])=='U'){
                cout << 'Y';
            }else if(toupper(s[i])=='I'){
                cout << 'U';
            }else if(toupper(s[i])=='O'){
                cout << 'I';
            }else if(toupper(s[i])=='P'){
                cout << 'O';
            }else if(toupper(s[i])=='['){
                cout << 'P';
            }else if(toupper(s[i])==']'){
                cout << '[';
            }else if(toupper(s[i])=="\\"[0]){
                cout << ']';
            }else if(toupper(s[i])=='S'){
                cout << 'A'; 
            }else if(toupper(s[i])=='D'){
                cout << 'S';
            }else if(toupper(s[i])=='F'){
                cout << 'D';
            }else if(toupper(s[i])=='G'){
                cout << 'F';
            }else if(toupper(s[i])=='H'){
                cout << 'G';
            }else if(toupper(s[i])=='J'){
                cout << 'H';
            }else if(toupper(s[i])=='K'){
                cout << 'J';
            }else if(toupper(s[i])=='L'){
                cout << 'K';
            }else if(toupper(s[i])==';'){
                cout << 'L';
            }else if(toupper(s[i])=="''"[0]){
                cout << ';';
            }else if(toupper(s[i])=='X'){
                cout << 'Z';
            }else if(toupper(s[i])=='C'){
                cout << 'X';
            }else if(toupper(s[i])=='V'){
                cout << 'C';
            }else if(toupper(s[i])=='B'){
                cout << 'V';
            }else if(toupper(s[i])=='N'){
                cout << 'B';
            }else if(toupper(s[i])=='M'){
                cout << 'N';
            }else if(toupper(s[i])==','){
                cout << 'M';
            }else if(toupper(s[i])=='.'){
                cout << ',';
            }else if(toupper(s[i])=='/'){
                cout << '.';
            }else if(toupper(s[i])=='1'){
                cout << "``"[0];
            }else if(toupper(s[i])=='2'){
                cout << '1';
            }else if(toupper(s[i])=='3'){
                cout << '2';
            }else if(toupper(s[i])=='4'){
                cout << '3';
            }else if(toupper(s[i])=='5'){
                cout << '4';
            }else if(toupper(s[i])=='6'){
                cout << '5';
            }else if(toupper(s[i])=='7'){
                cout << '6';
            }else if(toupper(s[i])=='8'){
                cout << '7';
            }else if(toupper(s[i])=='9'){
                cout << '8';
            }else if(toupper(s[i])=='0'){
                cout << '9';
            }else if(toupper(s[i])=='-'){
                cout << '0';
            }else if(toupper(s[i])=='='){
                cout << '-';
            }else{
                cout << s[i];
            }
        }

        cout << endl;
        
    }
}

