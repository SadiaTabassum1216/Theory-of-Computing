#include<stdio.h>
#include<math.h>
#include<string.h>


void sort(char size, char a[size])
{
    int i,j;
    char temp;
    for(i=0;i<size;i++){
        for(j=i;j<size;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void replace(char size,char a[size])
{
    int i,j,k;
    for(i=0;i<size;i++){
       for(j=i+1;j<size;j++){
            if(a[i]==a[j]){
                for(k=j;k<size-1;k++)
                    a[k]=a[k+1];
                size--;
                j--;
            }
       }
    }
    a[size]='\0';
}

int main()
{
    int q,i,j,k,len=0,x;
    char a[2]={'0','1'}, string[100],current;


    printf("Number of states:");
    scanf("%d",&q);

    char s[q];
    printf("Enter states:\n");
    for(i=0;i<q;i++){
        scanf("\n%c",&s[i]);
        }

    char start;
    printf("Enter start state: ");
    scanf("\n%c",&start);

    printf("Enter the number of final state: ");
    scanf("%d",&x);

    printf("Enter final state: \n");
    char f[x];
    for(i=0;i<x;i++)
        scanf("\n%c",&f[i]);

    char NFA_table[q+1][3][q+1];

    for(i=0;i<=q;i++){
        for(j=0;j<=2;j++){
            for(k=0;k<=q;k++){
                NFA_table[i][j][k]='0';
            }
        }
    }

    for(i=1;i<=2;i++)
        NFA_table[0][i][0]=a[i-1];
    for(i=1;i<=q;i++){
        NFA_table[i][0][0]=s[i-1];
        NFA_table[i][0][1]='\0';
    }

    printf("Enter the transition NFA table: \n");

    for(i=1;i<=q;i++){
        for(j=1;j<=2;j++){
            scanf("\n%s",&NFA_table[i][j]);
        }
    }

    for(i=0;i<x;i++)
    printf(" %c",f[i]);
    printf("\n");

    NFA_table[q+1][0][0]=NFA_table[q+1][1][0]=NFA_table[q+1][2][0]='#';

    for(i=0;i<x;i++)
    printf(" %c",f[i]);
    printf("\n");

    for(i=1;i<=q;i++){
        for(j=1;j<=2;j++){
            sort(strlen(NFA_table[i][j]), NFA_table[i][j]);
        }
    }
    printf("NFA transition table:\n");
    printf("%c\t0\t1\n",235);
    for(i=1;i<=q;i++){
        printf("%c",NFA_table[i][0][0]);
        for(j=1;j<=2;j++){
            printf("\t%s",NFA_table[i][j]);
        }
        printf("\n");
    }


int l,m,n,p,r;
char DFA_table[100][100][100];

for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            for(k=0;k<100;k++){
                DFA_table[i][j][k]='\0';
            }
        }
    }

    for(i=1;i<=2;i++)
        DFA_table[0][i][0]=a[i-1];


strcpy(DFA_table[1][0],NFA_table[1][0]);

int flag,rownum=1;


for(i=1;i<=rownum;i++){
    for(j=1;j<=2;j++){
        for(k=0;k<strlen(DFA_table[i][0]);k++){
            for(l=0;l<q+1;l++){
                if(DFA_table[i][0][k]==NFA_table[l][0][0]){
                    strcat(DFA_table[i][j],NFA_table[l][j]);
                }
            }
        }

        sort(strlen(DFA_table[i][j]), DFA_table[i][j]);
        if(strlen(DFA_table[i][j])>1 && DFA_table[i][j][0]=='#'){
                char* substr=DFA_table[i][j]+1;
                strcpy(DFA_table[i][j],substr);
            }
        replace(strlen(DFA_table[i][j]), DFA_table[i][j]);

           //adding new state
           flag=0;
        for(r=1;r<=rownum;r++){
            if(strcmp(DFA_table[i][j],DFA_table[r][0])==0)
                    flag++;
        }

            if(flag==0){    //new state exists
                ++rownum;
                strcpy(DFA_table[rownum][0],DFA_table[i][j]);
            }
        }
    }


    for(i=1;i<=rownum;i++){
        for(j=1;j<=2;j++){
            sort(strlen(DFA_table[i][j]), DFA_table[i][j]);
        }
    }

    printf("\n\nDFA transition table:\n");
    printf("%c\t0\t1\n",235);
    for(i=1;i<=rownum;i++){
        for(j=0;j<=2;j++){
            printf("%s\t",DFA_table[i][j]);
        }
        printf("\n");
    }

printf("\nX= %d\n",x);
printf("\nFinal states are:\n");
for(i=1;i<=rownum;i++){
        for(k=0;k<strlen(DFA_table[i][0]);k++){
            for(l=0;l<x;l++){
                if(DFA_table[i][0][k]==f[l])
                    printf("%s\n",DFA_table[i][0]);
            }
        }
}
}
