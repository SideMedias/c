#include<stdio.h>
#include<string.h>
#include<ctype.h>
int pwck(char *pw){
	int i,j=0;
	for(i=0;pw[i]!='\0';i++){
		if(isdigit(pw[i]))
			j++;
	}
	if(j<1)
		return 3;
	for(i=0;pw[i]!='\0';i++){
		if(isalnum(pw[i])==0)
			return 2;
	}
	if(strlen(pw)<8)
			return 1;
	return 0;
}
void main(){
	char pw[21];
	int i;
	printf("PASSWORDを設定しましょう\n要件 長さ：8文字以上20文字以内\n文字の種類：英数字\n");
	scanf("%s",pw);
	i=pwck(pw);
	switch(i){
		case 0:
			printf("成功\n");
			break;
		case 1:
			printf("文字数が足りない\n");
			break;
		case 2:
			printf("アルファベットか数値でない\n");
			break;
		case 3:
			printf("数字が含まれていない\n");
			break;
		default:
			break;
	}
}
