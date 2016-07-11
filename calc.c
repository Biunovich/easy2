#include "1.h"
int main(void)
{
	Comlex first,second,result;
	char op;
	void *dis;
	dis = dlopen("./libcalc.so",RTLD_NOW);
	Comlex (*funk)(Comlex,Comlex);
	while(1)
	{
		printf("Enter first complex number: ");
		scanf("%lf%lf",&first.Re,&first.Im);
		printf("Enter second complex number: ");
		scanf("%lf%lf",&second.Re,&second.Im);
		printf("Enter operation\n+\t-\t*\t/\nor q to quit: ");
		scanf(" %c",&op); 
		switch (op)
		{
			case '+':
			funk = dlsym(dis,"plus");
			result = funk(first,second);
			break;
			case '-':
			funk = dlsym(dis,"minus");
			result = funk(first,second);
			break;
			case '/':
			funk = dlsym(dis,"devide");
			result = funk(first,second);
			break;
			case '*':
			funk = dlsym(dis,"mult");
			result = funk(first,second);
			break;
			case 'q':
			exit(1);
			default :
			printf("Invalid operation\n");
			break;
		}
		printf("Result %lf %lf\n",result.Re,result.Im);
	}
}