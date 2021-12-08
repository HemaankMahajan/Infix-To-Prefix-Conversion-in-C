//Infix to Prefix Conversion
#include <stdio.h>
#include <stdlib.h>
#include<strings.h>

struct Node
{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
 
    if(t==NULL)
                printf("stack is full\n");
    else
        {
            t->data=x;
            t->next=top;
            top=t;
 }
 
}

char pop()
{
    struct Node *t;
    char x=-1;
 
    if(top==NULL)
                printf("Stack is Empty\n");
    else
        {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
        }
    return x;
}

void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    int i;
 
    for(i=0;exp[i]!='\0';i++){
        if(exp[i]=='(')
        push(exp[i]);
        else if(exp[i]==')')
        {
    if(top==NULL) return 0;
    pop();
        }
 }

    if(top==NULL) return 1;
    else return 0;
}
int pre(char x)
{
    if(x=='+' || x=='-')
                        return 1;
    else if(x=='*' || x=='/')
                        return 2;
 return 0;
}
 
int isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/') return 0;
    else return 1;
}
 
char * InToPre(char *infix)
{
    int i=0,j=0;
    char *prefix;
    int len=strlen(infix);
    prefix=(char *)malloc((len+2)*sizeof(char));
    i=len-1;
   for(;i>=0;){
        if(isOperand(infix[i])) prefix[j++]=infix[i--];
 else
 {
        if(pre(infix[i])>pre(top->data))
                push(infix[i--]);
        else{
                prefix[j++]=pop();
            }
 }
                        }
        while(top!=NULL) prefix[j++]=pop();
    prefix[j]='\0';
    int k =len-1;
    char *realprefix;
    realprefix=(char *)malloc((len+2)*sizeof(char));
    for(i=0;i<=k;i++){
        realprefix[i] = prefix[k-i];
    }
 return realprefix;
}

int PreCalc(char *prefix){
    int len = strlen(prefix);
    char *realprefix1;
    realprefix1=(char *)malloc((len+2)*sizeof(char));
    for(int i=0;i<len;i++){
        realprefix1[i] = prefix[len-1-i];
    }
    int ans = Eval(realprefix1);
    return ans;
} 
int Eval(char *postfix)
{
 int i=0;
 int x1,x2,r=0 ;
 
 for(i=0;postfix[i]!='\0';i++){
        if(isOperand(postfix[i])){
                push(postfix[i]-'0');}
 
 else{
        x2=pop();x1=pop();
        switch(postfix[i]){
                case '+':r=x1+x2; break;
                case '-':r=x2-x1; break;
                case '*':r=x1*x2; break;
                case '/':r=x2/x1; break;
                            }
        push(r);
    }
 }
 
 return top->data;

}
int main()
{
     char *infix="2/1";
    push('#');
 
    char *prefix=InToPre(infix);
 
    printf("%s \n",prefix);
    printf("%d\n",PreCalc(prefix));
    return 0;
}