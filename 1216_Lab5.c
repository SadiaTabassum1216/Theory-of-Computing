#include<stdio.h>
#include<string.h>

int top=-1;
char stack[100];


//push in stack
void push(char a)
{
    top++;
    stack[top]=a;
}

//pop in stack
char pop()
{
    char a;
    a=stack[top];
    top--;

    return a;
}

int main()
{
char input[100];
int i,len,j,state=0;

printf("Enter the string: ");
scanf("%s",input);

len=strlen(input);

for(j=1;j<len;j++){
    printf("\n\nPosition %d: \n",j);
    state=0;
    push('Z');
    for(i=0;i<j;i++){
        printf("(Q%d,%c,%c) -> (Q%d,%c%c)\n",state,input[i],stack[top],state,input[i],stack[top]);
        push(input[i]);
    }
    state++;
    for(i;i<len;i++){
        if(input[i]==stack[top]){
            printf("(Q%d,%c,%c) -> (Q%d,E)\n",state-1,input[i],stack[top],state);
            pop();
        }
        else{
            printf("Error.");
            break;
        }
    }
    state++;

    if(i==len && stack[top]=='Z' && state==2){
        printf("(Q%d,%c,%c) -> (Q%d,%c)\n",state,input[i-1],stack[top],state,stack[top]);
        printf("\nAccepted.\n");
        return 0;
        }
    else{
        while (top!=-1)
            pop();
    }
}
printf("\n\nNot Accepted.\n");
}
