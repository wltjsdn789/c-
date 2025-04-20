/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int num1=10,num2=20;
    int *ptr1=&num1,*ptr2=&num2;
    
    *ptr1+=10;
    *ptr2-=10;
    
    ptr1=&num2;
    ptr2=&num1;
    
    printf("ptr1:%d\n ptr2:%d",*ptr1,*ptr2);

    return 0;
}