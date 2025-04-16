/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
double fahtocel(double cel){
    double fah=1.8*cel+32;
    return fah;
}
double celtofah(double fah2){
    double cel2=(fah2/1.8)-(32/1.8);
    return cel2;
}
int main()
{
    printf("화->섭 %lf, 섭->화 %lf",fahtocel(10),celtofah(10));
    return 0;
}