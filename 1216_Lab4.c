#include<stdio.h>
#include<string.h>

void replace(char from[], char to[4])
{
    int i,j;

    if(strlen(from)<=3)
        return;

    for(i=0;from[i+2]!='\0';i++){
        if(from[i]==to[0] && from[i+1]==to[1] && from[i+2]==to[2]){
            from[i]='E';
            for(j=i+1;from[j]!='\0';j++){
                from[j]=from[j+2];
            }
            from[j]='\0';
        }
    }
   // printf("%s\n",from);
}

int main()
{
    int i,j,n,count=0;
    char input[100];

    printf("Enter a string: ");
    scanf("%s",input);
    n=strlen(input);

    for(i=0;i<n;i++){
        if(input[i]=='0' || input[i]=='1')
            input[i]='E';
    }

    //E=(E)
    //E=E+E
    //E=E*E
    for(i=0;input[3]!='\0';i++){
        count++;
        if(count>=n*n)
            break;
        replace(input,"(E)");
        replace(input,"E+E");
        replace(input,"E*E");
    }

    if(strcmp(input,"(E)")==0 || strcmp(input,"E+E")==0 || strcmp(input,"E*E")==0)
        printf("Accepted.");
    else
        printf("Not Accepted.");
}
