#include<stdio.h>
#include<stdlib.h>
int Power(int n,int k){
	if(k==0){
		return 0;
	}
	else if(k==1){
		return n;
	}
    else{
    	return n*Power(n,k-1);
	}
}
int main(){
	int n=0;
	int k=0;
	scanf_s("%d %d",&n,&k);
	printf("%d\n",Power(n,k));
	system("pause");
	return 0;
}