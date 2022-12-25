#include<stdio.h>

char states(int n,int q,char table[q+1][n+1],char input,char state){
int i,j;

for(i=0;i<=q;i++){
    for(j=0;j<=n;j++){
        if(table[0][j]==input && table[i][0]==state){
            printf("--(%c)-->%c ",input,table[i][j]);
            return table[i][j];
            }
    }
}
}

int main()
{
    int n,q,i,j,len=0,x,count=0;

    printf("Enter number of letter/digits: ");
    scanf("%d",&n);

    char a[n],string[100],current;

    printf("Enter alphabet:\n");

    for(i=0;i<n;i++){
        scanf("\n%c",&a[i]);
        }

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





    char table[q+1][n+1];

    for(i=1;i<=n;i++)
        table[0][i]=a[i-1];
    for(i=1;i<=q;i++)
        table[i][0]=s[i-1];

    printf("Enter the transition table: \n");

    for(i=1;i<=q;i++){
        for(j=1;j<=n;j++){
            scanf("\n%c",&table[i][j]);
        }
    }
    printf("The transition table:\n ");
    for(i=0;i<=q;i++){
        for(j=0;j<=n;j++){
            printf("  %c",table[i][j]);
        }
        printf("\n");
    }


    printf("Input a string: ");
    scanf("%s",&string);
    //n=strlen(a);
    for(i=0;string[i]!='\0';i++)
        len++;
    current=start;
    printf("Path: %c",start);
    for(i=0;i<len;i++){
       current=states(n,q,table,string[i],current);
    }

    for(i=0;i<x;i++){
        if(f[i]==current){
            count++;
            break;
        }
    }
    if(count!=0)
        printf("\nAccepted\n");
    else
        printf("\nNot accepted.\n");


}
