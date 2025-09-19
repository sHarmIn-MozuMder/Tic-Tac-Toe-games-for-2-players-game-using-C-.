#include <iostream>
#include <vector>
using namespace std;
int main(){
    cout<<"=== Tic-Tac-Toe ===\n"; bool play=1;
    while(play){
        vector<char> b(9); for(int i=0;i<9;i++) b[i]='1'+i;
        char p='X',r=0; int m;
        while(1){
            cout<<"\n "<<b[0]<<"|"<<b[1]<<"|"<<b[2]<<"\n-+-+-\n "<<b[3]<<"|"<<b[4]<<"|"<<b[5]
                <<"\n-+-+-\n "<<b[6]<<"|"<<b[7]<<"|"<<b[8]<<"\n";
            cout<<"Player "<<p<<" (1-9): "; cin>>m; m--;
            if(m<0||m>8||b[m]=='X'||b[m]=='O'){cout<<"Invalid!\n"; continue;}
            b[m]=p;
            int w[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
            for(auto &x:w) if(b[x[0]]==b[x[1]]&&b[x[1]]==b[x[2]]) r=b[x[0]];
            bool full=1; for(char c:b) if(c!='X'&&c!='O') full=0;
            if(r||full){
                cout<<"\n "<<b[0]<<"|"<<b[1]<<"|"<<b[2]<<"\n-+-+-\n "<<b[3]<<"|"<<b[4]<<"|"<<b[5]
                    <<"\n-+-+-\n "<<b[6]<<"|"<<b[7]<<"|"<<b[8]<<"\n";
                cout<<(r?("Player "+string(1,r)+" wins!"): "Tie!")<<"\n"; break;
            }
            p=(p=='X')?'O':'X';
        }
        cout<<"Play again? (y/n): "; char a; cin>>a; play=(a=='y'||a=='Y');
    }
}


