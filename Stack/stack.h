#ifndef STACK_H
#define STACK_H

#define MAX 10

extern int stack[MAX];
extern int top;
extern int size;

/*Stack operations*/
void push(void);
void pop(void);
void display(void);

int pali(void);

#endif