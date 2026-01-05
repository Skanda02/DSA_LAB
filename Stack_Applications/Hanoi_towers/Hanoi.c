#include<stdio.h>

void towers(int, char, char, char);

int main()
{
    int n;
    printf("Enter thr number of disk : ");
    scanf("%d", &n);

    printf("The seuence of moves involved in the Tover of Hanoi are :\n");
    towers(n,'A','B','C');
    return 0;
}

void towers(int n, char A, char B, char C){
    if(n == 1){
        printf("\n Move disk 1 from peg %c to prg %c \n", A, C);
        return;
    }
    towers(n-1,A,C,B);
    printf("\n Move disk %d from peg %c to peg %c\n ", n,A,C);
    towers(n-1,B,A,C);
}