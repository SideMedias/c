#include <stdio.h>
#include <string.h>

typedef struct Car{
    char syasu[100];
    char ona[100];
    int nanba;
    int nensiki;
    float nenpi;
}Car;

void main()
{
    printf("\n-------------- Hello World --------------\n\n");

    Car car[6]={
        {"Fit","nakai",3580,2003,15.5},
        {"Prius","kusanagi",5500,2012,20.1},
        {"Tanto","kimura",3333,2015,25.5},
        {"Colora","inagaki",7777,2005,15.5},
        {"Harrier","mori",1234,2012,10.2},
        {"Lexus","katori",8080,2018,11.8}
    };

    int i;
	printf("配列のデータを表示します。\n    車種 オーナー ナンバー 年式 燃費(L/km)\n");
	printf("-----------------------------------------\n");
    for(i=0;i<6;i++){
        printf("%8s %8s%8d%8d%8.1f\n"
				,car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
    }

	printf("-----------------------------------------\n");
	printf("探索する項目を選択してください。\n1:モデル 2:オーナー 3:ナンバー 4:年式 5:燃費\n");
    scanf("%d",&i);
    switch(i){
        case 1:{
            char s[100];
			printf("\n探索します。車種名を入力してください。\n");
            scanf("%s",s);
			printf("-----------------------------------------\n");
            int j=0;
            for(i=0;i<6;i++){
                if(strcmp(car[i].syasu,s)==0){
                    printf("%8s %8s%8d%8d%8.1f\n"
							,car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("-----------------------------------------\n");
				printf("%sは%d件ありました。\n",s,j);
            }else{
                printf("-----------------------------------------\n");
				printf("%sは配列に存在しません。\n",s);
            }
            break;
        }
        case 2:{
            char s[100];
			printf("\n探索します。オーナー名を入力してください。\n");
            scanf("%s",s);
			printf("-----------------------------------------\n");
            int j=0;
            for(i=0;i<6;i++){
                if(strcmp(car[i].ona,s)==0){
                    printf("%8s %8s%8d%8d%8.1f\n"
							,car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("-----------------------------------------\n");
				printf("%sは%d件ありました。\n",s,j);
            }else{
                printf("-----------------------------------------\n");
				printf("%sは配列に存在しません。\n",s);
            }
            break;
        }
        case 3:{
            int n;
			printf("\n探索します。ナンバーを入力してください。\n");
            scanf("%d",&n);
			printf("-----------------------------------------\n");
            int j=0;
            for(i=0;i<6;i++){
                if(car[i].nanba==n){
                    printf("%8s %8s%8d%8d%8.1f\n"
							,car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("-----------------------------------------\n");
				printf("%dは%d件ありました。\n",n,j);
            }else{
                printf("-----------------------------------------\n");
				printf("%dは配列に存在しません。\n",n);
            }
            break;
        }
        case 4:{
            int n;
			printf("\n探索します。年式を入力してください。\n");
            scanf("%d",&n);
			printf("-----------------------------------------\n");
            int j=0;
            for(i=0;i<6;i++){
                if(car[i].nensiki==n){
                    printf("%8s %8s%8d%8d%8.1f\n"
							,car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("-----------------------------------------\n");
				printf("%dは%d件ありました。\n",n,j);
            }else{
                printf("-----------------------------------------\n");
				printf("%dは配列に存在しません。\n",n);
            }
            break;
        }
        case 5:{
            float n;
			printf("\n探索します。基準燃費を入力してください。\n");
            scanf("%f",&n);
			printf("-----------------------------------------\n");
            int j=0;
            for(i=0;i<6;i++){
                if(car[i].nenpi>=n){
                    printf("%8s %8s%8d%8d%8.1f\n"
							,car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("-----------------------------------------\n");
				printf("%.1f以上は%d件ありました。\n",n,j);
            }else{
                printf("-----------------------------------------\n");
				printf("%.1f以上は配列に存在しません。\n",n);
            }
            break;
        }
        default:
            break;
    }
}
