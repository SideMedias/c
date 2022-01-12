#include <stdio.h>

int main()
{
    printf("Hello World\n");
    
    int i,num,nums[10];
    
    printf("2進数に変換する数値を入力(0~1024)\n");
    scanf("%d",&num);
    
    for(i=0;i<10;i++){
        nums[i]=num%2;
        num=num/2;
    }
    
    for(i=9;i>=0;i--){
        printf("%d",nums[i]);
    }
    printf("\n");

    return 0;
}
