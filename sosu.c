#include<stdio.h>
int main(){
	int a,b,c,d;
	printf("上限を入力\n");
	scanf("%d",&a);
	for(b=2;b<=a;b++){
		d=0;
		for(c=2;c<b;c++);{
			if(b%c==0){
				d=1;
			}
		}
		if(d==0){
			printf("%d\n",b);
		}
	}	
}
