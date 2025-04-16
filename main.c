/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int i(int a,int b,int c);
int si(int a,int b,int c);

int main()
{
    int a,b,c;
    printf("정수 입력 3개\n");
    scanf("%d %d %d",&a,&b,&c);
    printf("셋중 큰 수는 %d\n",i(a,b,c));
    printf("셋 중 가장 작은 수는 %d",si(a,b,c));

    return 0;
}
// 정수 3개 최댓값 함수 
    int i(int a,int b,int c){
        if(a>b && a>c)
            return a;
        else if (b>c)
            return b;
        else
            return c;
    }
// 정수 3개 최솟값 함수 
    int si(int a,int b, int c){
        if(a<b && a<c)
            return a;
        else if (b<c)
            return b;
        else
            return c;
    }