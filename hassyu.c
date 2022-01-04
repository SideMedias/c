#include <stdio.h>

int main()
{
    int i,k;
    int A[10]={0,0,0,0,0,0,0,0,0,0};
    int B[10]={0,0,0,0,0,0,0,0,0,0};
    for(i=0;i<10;i++){
        scanf("%d",&k);
        if(k==0){
            break;
        }else{
            B[i]=k;
        }
    }
    for(i=0;i<10;i++){
        if(A[B[i]%10]==0){
            A[B[i]%10]=B[i];
        }else if(A[(B[i]+1)%10]==0){
            A[(B[i]+1)%10]=B[i];
        }else if(A[(B[i]+4)%10]==0){
            A[(B[i]+4)%10]=B[i];
        }else{
            printf("error: Not vacant: '%d'\n",B[i]);
        }
    }
    for(i=0;i<10;i++){
        printf("A[%d]:%d\n",i,A[i]);
    }

    return 0;
}
