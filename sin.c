#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define num 10
void main(){
    srand((unsigned int)time(NULL));
    int i,card[num];
    for(i=0;i<num;i+=2){
        card[i]=i/2+1; 
        card[i+1]=i/2+1;
    }
    for(i=0;i<1000;i++){
        int j=rand()%num,k=rand()%num,tmp;
        tmp=card[j];
        card[j]=card[k];
        card[k]=tmp;
    }
    for(i=0;i<num;i++){
        printf("%d ",card[i]);
    }
    printf("\n");
    printf("神経衰弱ゲームです。\n");
    printf("1~%dのカードが2枚ずつ%d組あります。\n",num/2,num/2);
    printf("全ての組を揃えたらクリアです。\n");
    int c1,c2,sc=100;
    char st[]="*****";
    while(1){
        printf("status:%s\n",st);
        printf("1枚目を選択してください。(0~9)\n");
        scanf("%d",&c1);
        printf("%d番のカードは%dです。\n",c1,card[c1]);
        printf("2枚目を選択してください。(0~9)\n");
        scanf("%d",&c2);
        printf("%d番のカードは%dです。\n",c2,card[c2]);
        if(card[c1]==card[c2]&&c1!=c2){
            printf("%dのカードが揃いました。\n",card[c1]);
            switch(card[c1]){
                case 1:st[0]='1';break;
                case 2:st[1]='2';break;
                case 3:st[2]='3';break;
                case 4:st[3]='4';break;
                case 5:st[4]='5';break;
                default:break;
            };          
        }else{
            printf("はずれです。\n");
            sc--;
        }
        if(!strcmp(st,"12345")){
            printf("クリアです。\n");
            printf("score:%d\n",sc);
            break;
        }
    }
}
