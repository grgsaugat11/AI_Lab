#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int i,x;
	char str[100];
	printf("Enter a message\n");
	gets(str);
	
	int key=3;
	begin:
		printf("Please choose following options:\n");
		printf("1 = Encrypt the string.\n");
		printf("2 = Decrypt the string.\n");
		printf("3 = Exit\n");
		scanf("%d", &x);
	
	switch(x){
		case 1:
			for(i=0;(i<100&&str[i]!='\0');i++)
			str[i]=str[i]+key;
			printf("\nEncrypted string:%s\n",str);
			goto begin;
		
		case 2:
			for(i=0;(i<100&&str[i]!='\0');i++)
			str[i]=str[i]-key;
			printf("\nDecrypted string: %s\n",str);
			goto begin;
		
		case 3:
			exit(0);
		
		default:
			printf("\nError\n");
	}
	return 0;
}
