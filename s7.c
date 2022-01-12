#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i=0;
	double b;
	double ans = 0.123;
	char s, p;
	
    while(s != 'E'){
		if(ans == 0.123){
			printf("数字を入力してください。\n");
			scanf("%lf",&ans);
		}
		printf("演算子を入力してください。\n");
		scanf(" %c",&s);
		if(s=='=')i++;
		if(!(s == '=' || s == 'c')){	
		    i=0;
		    p = s;
		    printf("数字を入力してください。\n");
		    scanf("%lf",&b);
		}
		switch(s){
			case'+': ans = ans + b; break;
			case'-': ans = ans - b; break;
			case'*': ans = ans * b; break;
			case'/': ans = ans / b; break;
/*  		case'%': ans = ans % b; break;*/
			case'=':
			    if(i>1){
				    switch(p){
			        	case'+': ans = ans + b; break;
				        case'-': ans = ans - b; break;
		        		case'*': ans = ans * b; break;
				        case'/': ans = ans / b; break;
/*  		        	case'%': ans = ans % b; break;*/
			        	case'=':printf("%.4f\n",ans); break;
				        case'c': ans = 0; printf("0\n"); break;
			        	default: printf("演算子エラーです\n"); break;
				    }
			    }
			    printf("%.4f\n",ans);
			    break;
			case'c': ans = 0; printf("0\n"); break;
			default: printf("演算子エラーです\n"); break;
		}
	}
	return 0;
}
