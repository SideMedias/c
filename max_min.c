#include<stdio.h>
void max(int *a,int *b,int *c);
int main(void){
	int test[5];
	int i,a,b;
	printf("5人の点数を入力\n");
	for(i=0;i<5;i++){
		scanf("%d",&test[i]);
	}
	max(test,&a,&b);
	printf("max:%d\nmin:%d\n",a,b);
	return 0;
}
void max(int *a,int *b,int *c)
{
	int i;
	*b=*c=*a;
	for(i=1;i<5;i++){
		if(*b<*(a+i)){
			*b=*(a+i);
		}
		if(*c>*(a+i)){
			*c=*(a+i);
		}
	}
}
