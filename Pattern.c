#include<stdio.h>
int main()
{
	int n=4;
	int i,j,space;
	for(i=1;i<=n;i++){
		for(space=1;space<=n-i;space++){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("%d ",j);
		}
		printf("\n");
	}
}
