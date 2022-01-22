#include <stdio.h>
#include <string.h>
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    char str[1000];
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1]='\0';    
    for(int i=0;i<strlen(str)+2;i++){
        printf("+");
    }
    printf("\n");
    printf("+%s+\n", str);
    for(int i=0;i<strlen(str)+2;i++){
        printf("+");
    }
        printf("\n");
    return 0;
}
