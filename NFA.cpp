#include<bits/stdc++.h>
#include<string.h>

using namespace std;

void duplicate(int n,char a[100]){
    int i,j,k;
    for(i=0;i<n;i++){
       for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(k=j;k<n-1;k++)
                    a[k]=a[k+1];
                n--;
                j--;
            }
        }
    }
    a[n]='\0';
}

int main(){
    int i,j,k,l,m,n,p,q,r,x,flag,DFArow=1;
    char alpha[2]={'0','1'},start,NFA_table[100][100][100],DFA_table[100][100][100];

    freopen("NFA.txt", "r", stdin);
    cin>>q;
    char states[q];
    for(i=0;i<q;i++)
        cin>>states[i];
    cin>>start;
    cin>>x;

    char f[x];
    for(i=0;i<x;i++)
        cin>>f[i];

    for(i=0;i<=q;i++){
        for(j=0;j<=2;j++){
            for(k=0;k<=q;k++){
                NFA_table[i][j][k]='\0';
            }
        }
    }

    for(i=1;i<=2;i++)
        NFA_table[0][i][0]=alpha[i-1];
    for(i=1;i<=q;i++)
        NFA_table[i][0][0]=states[i-1];

    for(i=1;i<=q;i++){
        for(j=1;j<=2;j++)
            cin>>NFA_table[i][j];
    }

    for(i=1;i<=q;i++){
        for(j=1;j<=2;j++)
           sort(NFA_table[i][j],NFA_table[i][j]+strlen(NFA_table[i][j]));
    }

    char finalState[x];
    for(i=0;i<x;i++)
        finalState[i]=f[i];

    NFA_table[q+1][0][0]=NFA_table[q+1][1][0]=NFA_table[q+1][2][0]='#';

    cout<<"NFA transition table:"<<endl;
    cout<<" \t0\t1"<<endl;
    for(i=1;i<=q;i++){
        cout<<NFA_table[i][0][0];
        for(j=1;j<=2;j++)
            cout<<"\t"<<NFA_table[i][j];
        cout<<endl;}

    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            for(k=0;k<100;k++)
                DFA_table[i][j][k]='\0';
        }
    }

    for(i=1;i<=2;i++)
        DFA_table[0][i][0]=alpha[i-1];

strcpy(DFA_table[1][0],NFA_table[1][0]);

for(i=1;i<=DFArow;i++){
    for(j=1;j<=2;j++){
        for(k=0;k<strlen(DFA_table[i][0]);k++){
            for(l=0;l<=q;l++){
                if(DFA_table[i][0][k]==NFA_table[l][0][0])
                    strcat(DFA_table[i][j],NFA_table[l][j]);
            }
        }

        sort(DFA_table[i][j],DFA_table[i][j]+strlen(DFA_table[i][j]));
        if(strlen(DFA_table[i][j])>1 && DFA_table[i][j][0]=='#'){
                char* substr=DFA_table[i][j]+1;
                strcpy(DFA_table[i][j],substr);}
        duplicate(strlen(DFA_table[i][j]), DFA_table[i][j]);

        flag=0;
        for(r=1;r<=DFArow;r++){
            if(strcmp(DFA_table[i][j],DFA_table[r][0])==0)
                flag++;
        }

            if(flag==0){
                ++DFArow;
                strcpy(DFA_table[DFArow][0],DFA_table[i][j]);
            }
        }
    }


    cout<<"\nDFA transition table:"<<endl;
    cout<<"\t0\t1"<<endl;
    for(i=1;i<=DFArow;i++){
        for(j=0;j<=2;j++){
            if(strcmp(DFA_table[i][j],"\0"))
                cout<<DFA_table[i][j]<<"\t";
            else
                cout<<"#\t";}
        cout<<endl;}

cout<<"\nFinal states:"<<endl;
for(i=1;i<=DFArow;i++){
        for(k=0;k<strlen(DFA_table[i][0]);k++){
            for(l=0;l<x;l++){
                if(DFA_table[i][0][k]==finalState[l]){
                    cout<<DFA_table[i][0]<<endl;
                    break;
                }
            }
        }
    }
}
