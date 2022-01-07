#include <stdio.h>

typedef struct Car{
    int num;
    double gas;
    struct Car *next;
}Car;

void main()
{
    printf("Hello World\n");
    
    Car car0,car1,car2,car3,car4,car5;
    car0.num=1111;car0.gas=11.1;car0.next=&car1;
    car1.num=2222;car1.gas=22.2;car1.next=&car2;
    car2.num=3333;car2.gas=33.3;car2.next=&car3;
    car3.num=4444;car3.gas=44.4;car3.next=&car4;
    car4.num=5555;car4.gas=55.5;car4.next=&car5;
    car5.num=6666;car5.gas=66.6;car5.next=NULL;
    Car *pC;
    Car *head;
    head=&car0;
    Car *prev;
    prev=NULL;

    for(pC=head;pC!=NULL;pC=pC->next){
        printf("num:%d gas:%.1f\n",pC->num,pC->gas);
    }

    int x,y=0;
    printf("select the number to delete\n");
    scanf("%d",&x);

    for(pC=head;pC!=NULL;pC=pC->next){
        if(x==pC->num){
            printf("%d:exist\ngas:%.1f\n",pC->num,pC->gas);
            y++;
            if(prev==NULL){
                head=pC->next;
            }else{
                prev->next=pC->next;
            }
        }else{
            prev=pC;
        }
    }    
    if(y<1)
    printf("%d:not exist",x);
    else{
        printf("%d:remove from list\nlist after deletion\n",x);
        if(head==NULL){
            printf("no data\n");
        }else{
            for(pC=head;pC!=NULL;pC=pC->next){
                printf("num:%d gas:%.1f\n",pC->num,pC->gas);
            }
        }
    }
}
