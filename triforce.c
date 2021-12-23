#include<stdio.h>
int main(void){
	int i,j,num=10;
//	while(1){
	for(i=0;i<num;i++){
		for(j=num;j>i+1;j--){
			printf(" ");
		}
		for(j=0;j<i;j++){
			printf(" ");
		}
		for(j=num;j>i;j--){
			printf(" ");
		}
		for(j=0;j<i*2+1;j++){
			printf("3");		
		}
		printf("\n");
	}
	for(i=0;i<num;i++){
		for(j=num;j>i+1;j--){
			printf(" ");
		}
		for(j=0;j<i*2+1;j++){
			printf("3");		
		}
		for(j=num;j>i+1;j--){
			printf(" ");
		}
		for(j=num;j>i;j--){
			printf(" ");
		}
		for(j=0;j<i*2+1;j++){
			printf("3");		
		}
		printf("\n");
	}
//	}
	return 0;
}
