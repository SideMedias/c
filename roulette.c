#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define g 0
#define r 1
#define b 2
typedef struct Pocket{
	int number;
	int color;
}Pocket;
void main(){
	Pocket pocket[37]={
		0,g,1,r,2,b,3,r,4,b,5,r,6,b,7,r,8,b,9,r,10,b,11,b,12,r,
		13,b,14,r,15,b,16,r,17,b,18,r,19,r,20,b,21,r,22,b,23,r,24,b,
		25,r,26,b,27,r,28,b,29,b,30,r,31,b,32,r,33,b,34,r,35,b,36,r		
	};
	printf("ルーレットは回転する円盤に球を投げ入れ、落ちる場所を当てるカジノゲーム。\n");
	printf("ルーレットはカジノの女王とも呼ばれ、多くのカジノで提供されている。\n");
	printf("19世紀初めにフランスで現在の形が完成し、「小さな輪」を意味するフランス語がゲームの名前となった。\n");
	int credit=1000;
	printf("Credit:%d",credit);
	while(1){
		srand(time(NULL));		
		printf("0:Start,1:End");
		int i;
		scanf("%d"&i);
		if(!i)return;
		printf("Bet(0~%d):",credit);
		int bet;
		scanf("%d",&bet);
		credit-=bet;
		printf("アウトサイドベット\n")
		printf("0:赤黒-赤か黒のどちらかに賭ける。配当は2倍。\n");
		printf("1:大中小-1~12、13~24、25~36のどれかに賭ける。配当は3倍\n");
		printf("インサイドベット\n")
		printf("2:6目賭け-縦一列の数字12個に賭ける。配当は6倍。\n");
		printf("3:3目賭け-横一列の数字3つに賭ける。配当は12倍。\n");
		printf("4:1目賭け-特定の数字1つに賭ける。配当は36倍。\n");		
		scanf("%d",&i);
		int num=rand()%37;
		switch(i){
			case 0:{
				printf("0:赤,1:黒");
				scanf("%d",&i);
				switch(i){
					case 0:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].color==r){
							printf("当たりです!\n")
							credit+=bet*2;
						}else{
							printf("外れです。\n")
						}
						break;
					}
					case 1:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].color==b){
							printf("当たりです!\n")
							credit+=bet*2;
						}else{
							printf("外れです。\n")
						}
						break;
					}
				}
				break;
			}
			case 1:{
				printf("0:小(1~12),1:中(13~24),大(25~36)");
				scanf("%d",&i);
				switch(i){
					case 0:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>0&&pocket[num].number<13){
							printf("当たりです!\n")
							credit+=bet*3;
						}else{
							printf("外れです。\n")
						}
						break;
					}
					case 1:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>12&&pocket[num].number<25){
							printf("当たりです!\n")
							credit+=bet*3;
						}else{
							printf("外れです。\n")
						}
						break;
					}
					case 2:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>24&&pocket[num].number<37){
							printf("当たりです!\n")
							credit+=bet*3;
						}else{
							printf("外れです。\n")
						}
						break;
					}
				}
				break;
			}
			case 2:{
				printf("0:小(1~12),1:中(13~24),大(25~36)");
				scanf("%d",&i);
				switch(i){
					case 0:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>0&&pocket[num].number<13){
							printf("当たりです!\n")
							credit+=bet*3;
						}else{
							printf("外れです。\n")
						}
						break;
					}
					case 1:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>12&&pocket[num].number<25){
							printf("当たりです!\n")
							credit+=bet*3;
						}else{
							printf("外れです。\n")
						}
						break;
					}
					case 2:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>24&&pocket[num].number<37){
							printf("当たりです!\n")
							credit+=bet*3;
						}else{
							printf("外れです。\n")
						}
						break;
					}
				}
				break;
			}
		}
	}
}