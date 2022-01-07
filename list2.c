#include <stdio.h>
#include <string.h>
typedef struct Car{
    char syasu[100];
    char ona[100];
    int nanba;
    int nensiki;
    float nenpi;
}Car;
int main(){
    printf("Hello World\n");
    Car car[6]={
        {"Fit","nakai",3580,2003,15.5},
        {"Prius","kusanagi",5500,2012,20.1},
        {"Lexus","kimura",3333,2015,25.5},
        {"Colora","inagaki",7777,2005,15.5},
        {"Harrier","mori",1234,2012,10.2},
        {"Lexus","katori",8080,2018,11.8}
    };
    int i;
    for(i=0;i<6;i++){
        printf("%s,%s,%d,%d,%.1f\n",car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
    }
    scanf("%d",&i);
    switch(i){
        case 1:{
            char s[100];
            scanf("%s",s);
            int j=0;
            for(i=0;i<6;i++){
                if(strcmp(car[i].syasu,s)==0){
                    printf("%s,%s,%d,%d,%.1f\n",car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("%s,%d exist\n",s,j);
            }else{
                printf("%s,not exist\n",s);
            }
            break;
        }
        case 2:{
            char s[100];
            scanf("%s",s);
            int j=0;
            for(i=0;i<6;i++){
                if(strcmp(car[i].ona,s)==0){
                    printf("%s,%s,%d,%d,%.1f\n",car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("%s,%d exist\n",s,j);
            }else{
                printf("%s,not exist\n",s);
            }
            break;
        }
        case 3:{
            int n;
            scanf("%d",&n);
            int j=0;
            for(i=0;i<6;i++){
                if(car[i].nanba==n){
                    printf("%s,%s,%d,%d,%.1f\n",car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("%d,%d exist\n",n,j);
            }else{
                printf("%d,not exist\n",n);
            }
            break;
        }
        case 4:{
            int n;
            scanf("%d",&n);
            int j=0;
            for(i=0;i<6;i++){
                if(car[i].nensiki==n){
                    printf("%s,%s,%d,%d,%.1f\n",car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("%d,%d exist\n",n,j);
            }else{
                printf("%d,not exist\n",n);
            }
            break;
        }
        case 5:{
            float n;
            scanf("%f",&n);
            int j=0;
            for(i=0;i<6;i++){
                if(car[i].nenpi>=n){
                    printf("%s,%s,%d,%d,%.1f\n",car[i].syasu,car[i].ona,car[i].nanba,car[i].nensiki,car[i].nenpi);
                    j++;
                }
            }
            if(j>0){
                printf("%.1f,%d exist\n",n,j);
            }else{
                printf("%.1f,not exist\n",n);
            }
            break;
        }
        default:
            break;
    }
    return 0;
}
