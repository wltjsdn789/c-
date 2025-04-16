/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int fibo(int i){
    if(i==0)
        return 0;
    else if(i==1)
        return 1;
    else if(i>=2){
        int result=fibo(i-1)+fibo(i-2);
        return result;
        
    }
}

int main()
{
    int i;
    printf("피보나치 수열 입력:\n");
    scanf("%d",&i);
    printf("피보나치 수열출력: \n");
    printf("%d\n",fibo(i));
    return 0;
}
