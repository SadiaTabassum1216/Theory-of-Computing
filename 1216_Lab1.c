#include<stdio.h>

int main()
{
int n=0,i;
char a[200],state,value;
printf("Enter the string: ");
scanf("%s",a);
//n=strlen(a);
for(i=0;a[i]!='\0';i++)
    n++;

printf("\nQ={A,B,C}\nAlphabet={0,1}\nStart State: A\nF={C}\n");
printf("\nTransition Table:\n\nState\t|\t0\t1\n--------------------------\n->A\t|\tA\tB\n  B\t|\tA\tC\n *C\t|\tA\tC\n");

state='A';
printf("\nThe transition is: A");

for(i=0;i<n;i++){
        value= a[i];
        printf(" --(%c) ",a[i]);
    if(state=='A' && value=='0'){state='A';}
    else if(state=='A' && value=='1'){state='B';}
    else if(state=='B' && value=='0'){state='A';}
    else if(state=='B' && value=='1'){state='C';}
    else if(state=='C' && value=='0'){state='A';}
    else if(state=='C' && value=='1'){state='C';}
    printf("--> %c",state);
}
if(state=='C')
    printf("\nAccepted.\n");
else
    printf("\nNot accepted.\n");

}
