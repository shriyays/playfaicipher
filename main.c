#include <stdio.h>
#include<string.h>
#include"header.h"
#define MAX 500
#include<stdlib.h>

void Encryption()
{
	
	char plaintext[MAX],result[MAX]="";
	int i;
	
	//---GETTING KEYWORD FROM THE USER AND CONVERTING IT TO UPPERCASE---	
	char keyword[25];
	printf("\n----Enter the keyword.[conditions: has to be unique]----\n");
	scanf("%s",keyword);
	toUpperCase(keyword, sizeof(keyword)/sizeof(char));
	fflush(stdin);
	
	//key square generation
	char cipherkey[5][5];
    GenerateCipherKey(keyword,cipherkey);
	printf("\n---KEYSQUARE---\n");
	
	//to print key square
	for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%c",cipherkey[i][j]);
        }
        printf("\n");

    }
	
	
	
	
	
	//---TAKING PLAIN TEXT AS INPUT AND REMOVING SPACES---	
	printf("\n----Enter the text----\n");
	fgets(plaintext,MAX,stdin);
	int len=removeSpace(plaintext,MAX);
	//fflush(stdin);
	
	

	//printf("plaintext:%s\n",plaintext);
	//printf("len:%d\n",len);	



	//---TO MAKE IT EVEN---	
	len=even(plaintext,len);
	//printf("\nplaintext:%s",plaintext);
	//printf("\nlen:%d",len);
	
	//---TO CONVERT IT TO UPPERCASE---
	toUpperCase(plaintext, len);
	//printf("\nplaintext:%s",plaintext);
	//printf("\nlen:%d",len);
	
	//---TO ENCRYPT---
	int pos[4]; //pos[0]=r1 pos[1]= c1 pos[2]=r2 pos[3]=c2
	char en[2]="";
	for(i=0;i<len;i+=2)
	{
		search(cipherkey,plaintext[i],plaintext[i+1],pos);
		encrypt(cipherkey,pos[0],pos[2],pos[1],pos[3],en);
		strcat(result,en);
		//printf("\nresult:%s",result);
	}
	
	printf("\nPLAIN TEXT:%s ",plaintext);
	printf("\nENCRYPTED TEXT:%s \n",result);	
	
	
	
}


void Decryption()
{
	
	char encryptedtext[MAX], result[MAX]="";
	int i;
	
	//---GETTING KEYWORD FROM THE USER AND CONVERTING IT TO UPPERCASE---	
	char keyword[25];
	printf("\nEnter the keyword.[conditions: has to be unique]--\n");
	scanf("%s",keyword);
	toUpperCase(keyword, sizeof(keyword)/sizeof(char));
	fflush(stdin);
	
	//key square generation
	char cipherkey[5][5];
    GenerateCipherKey(keyword,cipherkey);
	printf("\n---KEYSQUARE---\n");
	
	//to print key square
	for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%c",cipherkey[i][j]);
        }
        printf("\n");

    }
	
	
	
	//---TAKING ENCRYPTED TEXT AS INPUT AND REMOVING SPACES---	
	printf("\n--Enter the text--");
	fgets(encryptedtext,MAX,stdin);
	int len=removeSpace(encryptedtext,MAX);
	printf("encryptedtext:%s\n",encryptedtext);
	//printf("len:%d\n",len);	



	//---TO MAKE IT EVEN---	
	len=even(encryptedtext,len);
	printf("\nplaintext:%s",encryptedtext);
	//printf("\nlen:%d",len);
	
	//---TO CONVERT IT TO UPPERCASE---
	toUpperCase(encryptedtext, len);
	printf("\nplaintext:%s",encryptedtext);
	//printf("\nlen:%d",len);
	
	//---TO DECRYPT---
	int pos[4]; //pos[0]=r1 pos[1]= c1 pos[2]=r2 pos[3]=c2
	char de[2]="";
	for(i=0;i<len;i+=2)
	{
		search(cipherkey,encryptedtext[i],encryptedtext[i+1],pos);
		decrypt(cipherkey,pos[0],pos[2],pos[1],pos[3],de);
		strcat(result,de);
		//printf("\nresult:%s",result);
	}
	
	
	printf("\nENCRYPTED TEXT:%s ",encryptedtext);	
	printf("\nDECRYPTED TEXT:%s\n",result);
	
}




int main()
{
	int flag=0;
	
	while(!flag)
	{
		
		int choice;

		printf("\n-----OPTIONS-----\n");
		printf("1.Encryption\n2.Decryption\n3.Exit\n");
		printf("\nCHOICE (Pick 1 or 2) :");
		scanf("%d",&choice);
	
	
		switch(choice)
		{
			case 1:Encryption();
			break;
		
			case 2:Decryption();
			break;
			
			case 3:
			{
				printf("\nXXX EXITED XXX\n");
				flag=1;
			}
			break;
		
			default:
			printf("XXX INVALID CHOICE XXX");
		
		}
	}
	
	return 0;
	
}