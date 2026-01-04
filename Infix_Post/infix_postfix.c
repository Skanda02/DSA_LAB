/*
4. Develop a program in c for converting an infix expression to postfix expression 
    Program should support for both parenthesized and free parenthesized expression with the operators: +, -, *, /, %, $, ^ and alphanumeric operands.
*/

#include<stdio.h>
#include<string.h>

int pre(char symbol){
    switch(symbol){
        case'+':
        case'-':return 2;
        case'*':
        case'/':
        case'%':return 4;
        case'^':
        case'$':return 5;
        case'(':return 0;
        case'#':return -1;
        default:return 8;
    }
}

int inpre(char symbol){
    switch(symbol){
        case'+':
        case'-':return 1;
        case'*':
        case'/':
        case'%':return 3;
        case'^':
        case'$':return 6;
        case'(':return 3;
        case')':return 0;
        default:return 7;
    }
}

void infixpostfix(char infix[], char postfix[]){
    int top = -1, j = 0, i;
    char s[30], symbol;
    s[++top] = '#';
    for(i=0; i<strlen(infix); i++){
        symbol = infix[i];
        while(pre(s[top]) > inpre(symbol)){
            postfix[j] = s[top--];
            j++;
        }
        if(pre(s[top]) != inpre(symbol))
            s[++top] = symbol;
        else
            top--;
    }
    while(s[top] != '#')
    postfix[j++] = s[top--];
    postfix[j] = '\0';
}

int main()
{
    char infix[20], postfix[20];
    printf("Enter a valid infix expression:\n");
    scanf("%s", infix);
    infixpostfix(infix,postfix);
    printf("\n The postfix expression is:\n");
    printf("%s",postfix);
}

/*
#include<stdio.h>
#include<string.h>
#include<ctype.h>   // ✅ ADDED: for isalnum()

int pre(char symbol){
    switch(symbol){
        case'+':
        case'-':return 2;
        case'*':
        case'/':
        case'%':return 4;
        case'^':
        case'$':return 5;
        case'(':return 0;
        case'#':return -1;
        default:return 8;   // operand
    }
}

int inpre(char symbol){
    switch(symbol){
        case'+':
        case'-':return 1;
        case'*':
        case'/':
        case'%':return 3;
        case'^':
        case'$':return 6;
        // case'(':return 3;      ❌ WRONG
        case'(':return 7;        // ✅ FIXED: '(' must have highest input precedence
        case')':return 0;
        default:return 7;
    }
}

void infixpostfix(char infix[], char postfix[]){
    int top = -1, j = 0, i;
    char s[30], symbol;

    s[++top] = '#';

    for(i=0; i<strlen(infix); i++){
        symbol = infix[i];

        // ❌ OLD: operands treated like operators
        
        while(pre(s[top]) > inpre(symbol)){
            postfix[j] = s[top--];
            j++;
        }
        if(pre(s[top]) != inpre(symbol))
            s[++top] = symbol;
        else
            top--;
        

        // ✅ NEW: explicit operand handling
        if(isalnum(symbol)){
            postfix[j++] = symbol;
        }

        // ✅ NEW: handling ')'
        else if(symbol == ')'){
            while(s[top] != '(')
                postfix[j++] = s[top--];
            top--;   // remove '('
        }

        // ✅ operators and '('
        else{
            while(pre(s[top]) > inpre(symbol)){
                postfix[j++] = s[top--];
            }
            if(pre(s[top]) != inpre(symbol))
                s[++top] = symbol;
            else
                top--;
        }
    }

    while(s[top] != '#')
        postfix[j++] = s[top--];

    postfix[j] = '\0';
}

int main()
{
    char infix[20], postfix[20];
    printf("Enter a valid infix expression:\n");
    scanf("%s", infix);
    infixpostfix(infix,postfix);
    printf("\nThe postfix expression is:\n");
    printf("%s",postfix);
}
*/