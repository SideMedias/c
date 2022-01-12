#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Card{
    char suji[3];
    int ten;
}Card;
void game(){
    int credit=1000;
    printf("Credit:%d\n",credit);
    while(1){
        printf("Bet(0~%d):",credit);
        int bet;
        scanf("%d",&bet);
        credit-=bet;
        srand(time(NULL));
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
/*        for(i=0;i<52;i++){
            printf("%s:%d ",card[i].suji,card[i].ten);
        }
        printf("\n");
*/        Card player[10],dealer[10];
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
        }
        if(playerTen==dealerTen&&playerTen>0){
            printf("引き分けです\n");
            credit+=bet;
        }else printf("あなたの負けです\n");
        if(credit<1)credit=1000;
        printf("Credit:%d\n",credit);
        while(1){
            printf("0:もう一戦する 1:メニューへ戻る\n");
            int select;
            scanf("%d",&select);
            if(select){
                printf("所持金がリセットされます。本当によろしいですか？\n");
                printf("0:はい 1:いいえ\n");
                scanf("%d",&select);
                if(!select)return;
            }
            if(!select)break;
        }
    }
}
void rule(){
    printf("カードの点数\n");
    printf("2~10 :数字の表示通り\n");
    printf("K,Q,J:10\n");
    printf("A    :1または11（もう一枚のカード数字から判断して、どちらか都合のいい方にすることができます。\n");
    printf("                 ただし一度、数値の宣言をした後に再び数値の変更はできません。）\n");
    printf("Hit（ヒット）\n");
    printf("配られたカードにもう一枚カードを追加すること。\n");
    printf("カードの合計数が21以内であれば何度でもヒットを行い、カードを追加することができます。\n");
    printf("Stand（スタンド）\n");
    printf("配られたカードにそれ以上のカードの追加は行わないという宣言です。\n");
    printf("プレイヤーのスタンド宣言の後にディーラーがカードを引く順番へと切り替わり、\n");
    printf("プレイヤーは手元のカードの数字でディーラーとの勝負に挑みます。\n");
}
void main(){
    printf("ブラックジャックです。\n");
    printf("プレイヤーはカードの合計点数が21点を超えないように、ディーラーより高い点数を目指してください。\n");
    while(1){
        printf("0:ゲーム開始 1:ルール説明 2:終了\n");
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
