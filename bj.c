#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct Card{
    char suji[3];
    int ten;
}Card;
void game(){
    while(1){
        srand((unsigned int)time(NULL));
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
        int i;
        for(i=0;i<1000;i++){
            int j=rand()%52,k=rand()%52;
            Card tmp;
            tmp=card[j];
            card[j]=card[k];
            card[k]=tmp;
        }
        for(i=0;i<52;i++){
            printf("%s:%d ",card[i].suji,card[i].ten);
        }
        printf("\n");
        Card player[10],dealer[10];
        int cnum=0,pnum=0,pten=0,dnum=0,dten=0;
        dten+=card[cnum].ten;
        dealer[dnum++]=card[cnum++];
        dealer[dnum++]=card[cnum++];
        pten+=card[cnum].ten;
        player[pnum++]=card[cnum++];
        pten+=card[cnum].ten;
        player[pnum++]=card[cnum++];
        printf("ディーラー:%s,*:%d\n",dealer[0].suji,dten);
        printf("プレイヤー:%s,%s:%d\n",player[0].suji,player[1].suji,pten);
        break;
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
        printf("1:ゲーム開始 2:ルール説明 3:終了\n");
        int modeSelect;
        scanf("%d",&modeSelect);
        switch(modeSelect){
            case 1:game();break;
            case 2:rule();break;
            case 3:return;
            default:break;
        }
    }
}
