#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define g 0
#define r 1
#define b 2
void blackjack();
void game();
void rule();
void roulette();
typedef struct Pocket{
	int number;
	int color;
}Pocket;
typedef struct Card{
    char suji[3];
    int ten;
}Card;
void main(){
    printf("カジノへようこそ!!\n");
    while(1){
        printf("0:ブラックジャック,1:ルーレット,2:終了 ");
        int modeSelect;
        scanf("%d",&modeSelect);
        switch(modeSelect){
            case 0:blackjack();break;
            case 1:roulette();break;
            case 2:printf("おつかれさまでした。\n");return;
            default:break;
        }
    }
}
void blackjack(){
    printf("ブラックジャックへようこそ!!\n");
    printf("プレイヤーはカードの合計点数が21点を超えないように、ディーラーより高い点数を目指してください。\n");
    while(1){
        printf("0:ゲーム開始,1:ルール説明,2:終了 ");
        int modeSelect;
        scanf("%d",&modeSelect);
        switch(modeSelect){
            case 0:game();break;
            case 1:rule();break;
            case 2:return;
            default:break;
        }
    }
}
void game(){
    int credit=1000;
    printf("Credit:%d\n",credit);
    srand((unsigned int)time(NULL));
    while(1){
        printf("Bet(0~%d):",credit);
        int bet;
        scanf("%d",&bet);
        credit-=bet;
        Card card[]={
            "A",11,"A",11,"A",11,"A",11,
            "K",10,"K",10,"K",10,"K",10,
            "Q",10,"Q",10,"Q",10,"Q",10,
            "J",10,"J",10,"J",10,"J",10,
            "10",10,"10",10,"10",10,"10",10,
            "9",9,"9",9,"9",9,"9",9,
            "8",8,"8",8,"8",8,"8",8,
            "7",7,"7",7,"7",7,"7",7,
            "6",6,"6",6,"6",6,"6",6,
            "5",5,"5",5,"5",5,"5",5,
            "4",4,"4",4,"4",4,"4",4,
            "3",3,"3",3,"3",3,"3",3,
            "2",2,"2",2,"2",2,"2",2,
        };
        int i,bj=0;
        for(i=0;i<1000;i++){
            int j=rand()%52,k=rand()%52;
            Card tmp;
            tmp=card[j];
            card[j]=card[k];
            card[k]=tmp;
        }
        Card player[10],dealer[10];
        int cardNum=0,playerNum=0,playerTen=0,dealerNum=0,dealerTen=0;
        dealerTen+=card[cardNum].ten;
        dealer[dealerNum++]=card[cardNum++];
        dealer[dealerNum++]=card[cardNum++];
        player[playerNum++]=card[cardNum++];
        player[playerNum++]=card[cardNum++];
        printf("Dealer:%s,*:%d\n",dealer[0].suji,dealerTen);
        while(1){
            printf("Player:");
            for(i=0;i<playerNum;i++){
                printf("%s",player[i].suji);
                if(i<playerNum-1)printf(",");
            }
            playerTen=0;
            for(i=0;i<playerNum;i++){
                playerTen+=player[i].ten;
            }
            for(i=0;playerTen>21&&i<playerNum;i++){
                if(player[i].ten==11){
                    player[i].ten=1;
                    playerTen=0;
                    int j;
                    for(j=0;j<playerNum;j++){
                        playerTen+=player[j].ten;
                    }
                }
            }
            printf(":%d\n",playerTen);
            if(playerTen>21){
                printf("Bust!\n");
                playerTen=0;
                break;
            }
            if(playerTen==21&&playerNum<3){
                printf("Blackjack!\n");
                bj=1;
                break;
            }
            if(playerTen==21){
                printf("Stand!\n");
                break;
            }
            printf("Hit(0) or Stand(1)?\n");
            int select;
            scanf("%d",&select);
            if(!select){
                printf("Hit!\n");
                player[playerNum++]=card[cardNum++];
            }else if(select){
                printf("Stand!\n");
                break;
            }
        }
        while(1){
            printf("Dealer:");
            for(i=0;i<dealerNum;i++){
                printf("%s",dealer[i].suji);
                if(i<dealerNum-1)printf(",");
            }
            dealerTen=0;
            for(i=0;i<dealerNum;i++){
                dealerTen+=dealer[i].ten;
            }
            for(i=0;dealerTen>21&&i<dealerNum;i++){
                if(dealer[i].ten==11){
                    dealer[i].ten=1;
                    dealerTen=0;
                    int j;
                    for(j=0;j<dealerNum;j++){
                        dealerTen+=dealer[j].ten;
                    }
                }
            }
            printf(":%d\n",dealerTen);
            if(dealerTen>21){
                printf("Bust\n");
                dealerTen=0;
                break;
            }
            if(dealerTen==21&&dealerNum<3){
                printf("Blackjack\n");
                break;
            }
            if(dealerTen==21){
                printf("Stand\n");
                break;
            }
            if(dealerTen<17){
                printf("Hit\n");
                dealer[dealerNum++]=card[cardNum++];
            }else{
                printf("Stand\n");
                break;
            }
        }
        printf("Dealer:");
            for(i=0;i<dealerNum;i++){
                printf("%s",dealer[i].suji);
                if(i<dealerNum-1)printf(",");
            }
        printf(":%d\n",dealerTen);
        printf("Player:");
            for(i=0;i<playerNum;i++){
                printf("%s",player[i].suji);
                if(i<playerNum-1)printf(",");
            }
        printf(":%d\n",playerTen);
        if(playerTen>dealerTen){
            printf("あなたの勝ちです!\n");
            if(bj)credit+=bet*2.5;
            else credit+=bet*2;
        }else if(playerTen==dealerTen&&playerTen>0){
            printf("引き分けです\n");
            credit+=bet;
        }else printf("あなたの負けです\n");
        if(credit<1)credit=1000;
        printf("Credit:%d\n",credit);
        while(1){
            printf("0:もう一戦する 1:メニューへ戻る ");
            int select;
            scanf("%d",&select);
            if(select){
                printf("所持金がリセットされます。本当によろしいですか？\n");
                printf("0:はい 1:いいえ ");
                scanf("%d",&select);
                if(!select)return;
            }
            if(!select)break;
        }
    }
}
void rule(){
    printf("\n");
    printf("カードの点数\n");
    printf("2~10 :数字の表示通り\n");
    printf("K,Q,J:10\n");
    printf("A    :1または11（手札のカードの数字から判断して、どちらか都合のいい方にすることができます。\n");
    printf("\n");
    printf("Hit（ヒット）\n");
    printf("配られたカードにもう一枚カードを追加すること。\n");
    printf("カードの合計数が21以内であれば何度でもヒットを行い、カードを追加することができます。\n");
    printf("\n");
    printf("Stand（スタンド）\n");
    printf("配られたカードにそれ以上のカードの追加は行わないという宣言です。\n");
    printf("プレイヤーのスタンド宣言の後にディーラーがカードを引く順番へと切り替わり、\n");
    printf("プレイヤーは手元のカードの数字でディーラーとの勝負に挑みます。\n");
}
void roulette(){
	Pocket pocket[]={
		0,g,1,r,2,b,3,r,4,b,5,r,6,b,7,r,8,b,9,r,10,b,11,b,12,r,
		13,b,14,r,15,b,16,r,17,b,18,r,19,r,20,b,21,r,22,b,23,r,24,b,
		25,r,26,b,27,r,28,b,29,b,30,r,31,b,32,r,33,b,34,r,35,b,36,r		
	};
	printf("ルーレットへようこそ!!\n");
	printf("ルーレットは回転する円盤に球を投げ入れ、落ちる場所を当てるカジノゲーム。\n");
	printf("ルーレットはカジノの女王とも呼ばれ、多くのカジノで提供されている。\n");
	printf("19世紀初めにフランスで現在の形が完成し、「小さな輪」を意味するフランス語がゲームの名前となった。\n");
	int credit=1000;
	printf("Credit:%d\n",credit);
	srand((unsigned int)time(NULL));
	while(1){		
		printf("0:Start,1:End ");
		int i;
		scanf("%d",&i);
		if(i)return;
		printf("Bet(0~%d):",credit);
		int bet;
		scanf("%d",&bet);
		credit-=bet;
		printf("アウトサイドベット\n");
		printf("0:赤黒-赤か黒のどちらかに賭ける。配当は2倍。\n");
		printf("1:大中小-1~12、13~24、25~36のどれかに賭ける。配当は3倍\n");
		printf("インサイドベット\n");
		printf("2:6目賭け-横二列の数字6つに賭ける。配当は6倍。\n");
		printf("3:3目賭け-横一列の数字3つに賭ける。配当は12倍。\n");
		printf("4:1目賭け-特定の数字1つに賭ける。配当は36倍。 ");
		scanf("%d",&i);
		int num=rand()%37;
		switch(i){
			case 0:{
				printf("0:赤,1:黒 ");
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
							printf("当たりです!\n");
							credit+=bet*2;
						}else{
							printf("外れです。\n");
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
							printf("当たりです!\n");
							credit+=bet*2;
						}else{
							printf("外れです。\n");
						}
						break;
					}
				}
				break;
			}
			case 1:{
				printf("0:小(1~12),1:中(13~24),2:大(25~36) ");
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
							printf("当たりです!\n");
							credit+=bet*3;
						}else{
							printf("外れです。\n");
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
							printf("当たりです!\n");
							credit+=bet*3;
						}else{
							printf("外れです。\n");
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
							printf("当たりです!\n");
							credit+=bet*3;
						}else{
							printf("外れです。\n");
						}
						break;
					}
				}
				break;
			}
			case 2:{
				printf("0:1~6,1:7~12,2:13~18,3:19~24,4:25~30,5:31~36 ");
				scanf("%d",&i);
				switch(i){
					case 0:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>0&&pocket[num].number<7){
							printf("当たりです!\n");
							credit+=bet*6;
						}else{
							printf("外れです。\n");
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
						if(pocket[num].number>6&&pocket[num].number<13){
							printf("当たりです!\n");
							credit+=bet*6;
						}else{
							printf("外れです。\n");
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
						if(pocket[num].number>12&&pocket[num].number<19){
							printf("当たりです!\n");
							credit+=bet*6;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 3:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>18&&pocket[num].number<25){
							printf("当たりです!\n");
							credit+=bet*6;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 4:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>24&&pocket[num].number<31){
							printf("当たりです!\n");
							credit+=bet*6;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 5:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>30&&pocket[num].number<37){
							printf("当たりです!\n");
							credit+=bet*6;
						}else{
							printf("外れです。\n");
						}
						break;
					}
				}
				break;
			}
			case 3:{
				printf("0:1~3,1:4~6,2:7~9,3:10~12,4:13~15,5:16~18,\n");
				printf("6:19~21,7:22~24,8:25~27,9:28~30,10:31~33,11:34~36 ");
				scanf("%d",&i);
				switch(i){
					case 0:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>0&&pocket[num].number<4){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
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
						if(pocket[num].number>3&&pocket[num].number<7){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
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
						if(pocket[num].number>6&&pocket[num].number<10){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 3:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>9&&pocket[num].number<13){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 4:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>12&&pocket[num].number<16){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 5:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>15&&pocket[num].number<19){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 6:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>18&&pocket[num].number<22){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 7:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>21&&pocket[num].number<25){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 8:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>24&&pocket[num].number<28){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 9:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>27&&pocket[num].number<31){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 10:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>30&&pocket[num].number<34){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
					case 11:{
						switch(pocket[num].color){
							case g:printf("Green:%d\n",pocket[num].number);break;
							case r:printf("Red:%d\n",pocket[num].number);break;
							case b:printf("Black:%d\n",pocket[num].number);break;
							default:break;
						}
						if(pocket[num].number>33&&pocket[num].number<37){
							printf("当たりです!\n");
							credit+=bet*12;
						}else{
							printf("外れです。\n");
						}
						break;
					}
				}
				break;
			}
			case 4:{
				printf("0~36 ");
				scanf("%d",&i);
				switch(pocket[num].color){
					case g:printf("Green:%d\n",pocket[num].number);break;
					case r:printf("Red:%d\n",pocket[num].number);break;
					case b:printf("Black:%d\n",pocket[num].number);break;
					default:break;
				}
				if(i==pocket[num].number){
					printf("当たりです!\n");
					credit+=bet*36;
				}else{
					printf("外れです。\n");
				}
				break;
			}
			default:break;
		}
		if(credit<1)credit=1000;
		printf("Credit:%d\n",credit);
	}
}
