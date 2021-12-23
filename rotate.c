#include<stdio.h>
int main(void){
    int a,b,c,d;
    char f[][9]={
        {" ****** "},
        {" *      "},
        {" *      "},
        {" ****   "},
        {" *      "},
        {" *      "},
        {" *      "},
        {" *      "}
    };
    char g[][9]={
        {" ****** "},
        {" *      "},
        {" *      "},
        {" ****   "},
        {" *      "},
        {" *      "},
        {" *      "},
        {" *      "}
    };
    for(a=0;a<8;a++){
        for(b=0;f[a][b]!='\0';b++){
            printf("%c ",f[a][b]);
        }
        printf("\n");
    }
    d=0;
    do{
        printf("1:R,2:L,3:X,4:Y\n");
        scanf("%d",&c);
        if(d==0){
            switch(c){
                case 1:
                    for(a=0;a<8;a++){
                        for(b=0;f[a][b]!='\0';b++){
                            g[b][7-a]=f[a][b];
                        }
                    }
                    break;
                case 2:
                    for(a=0;a<8;a++){
                        for(b=0;f[a][b]!='\0';b++){
                            g[7-b][a]=f[a][b];
                        }
                    }
                    break;
                case 3:
                    for(a=0;a<8;a++){
                        for(b=0;f[a][b]!='\0';b++){
                            g[7-a][b]=f[a][b];
                        }
                    }
                    break;
                case 4:
                    for(a=0;a<8;a++){
                        for(b=0;f[a][b]!='\0';b++){
                            g[a][7-b]=f[a][b];
                        }
                    }
                    break;
                default :
                    break;
            }
            for(a=0;a<8;a++){
                for(b=0;g[a][b]!='\0';b++){
                    printf("%c ",g[a][b]);
                }
                printf("\n");
            }
            d=1;
        }else{
            switch(c){
                case 1:
                    for(a=0;a<8;a++){
                        for(b=0;g[a][b]!='\0';b++){
                            f[b][7-a]=g[a][b];
                        }
                    }
                    break;
                case 2:
                    for(a=0;a<8;a++){
                        for(b=0;g[a][b]!='\0';b++){
                            f[7-b][a]=g[a][b];
                        }
                    }
                    break;
                case 3:
                    for(a=0;a<8;a++){
                        for(b=0;g[a][b]!='\0';b++){
                            f[7-a][b]=g[a][b];
                        }
                    }
                    break;
                case 4:
                    for(a=0;a<8;a++){
                        for(b=0;g[a][b]!='\0';b++){
                            f[a][7-b]=g[a][b];
                        }
                    }
                    break;
                default :
                    break;
            }
            for(a=0;a<8;a++){
                for(b=0;f[a][b]!='\0';b++){
                    printf("%c ",f[a][b]);
                }
                printf("\n");
            }
            d=0;
        }
    }while(c!=0);
    return 0;
}
