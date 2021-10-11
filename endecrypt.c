#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

//Encryption

void encrypt(char cipherkey[5][5], int row1,int row2,int col1,int col2, char numcipher[2])
{
    
	if(col1==col2)
	{
		row1=(row1+1)%5;
		row2=(row2+1)%5;
		if(row1>5)
		{
			row1=row1-5;

		}
		if(row2>5)
		{
			row2=row2-5;
		}
		numcipher[0]=cipherkey[row1][col1];
		numcipher[1]=cipherkey[row2][col2];
	}
	else if(row1==row2)
	{
		col1=(col1+1)%5;
		col2=(col2+1)%5;

		if (col1>5)
		{
			col1=col1-5;
		}
		if(col2>5)
		{
			col2=col2-5;
		}
		numcipher[0]=cipherkey[row1][col1];
		numcipher[1]=cipherkey[row2][col2];
	}
	else if(row1!=row2&&col1!=col2)
	{
		numcipher[0]=cipherkey[row1][col2];
		numcipher[1]=cipherkey[row2][col1];
	}
	numcipher[2]='\0';
}

// Function to search for the characters
void search(char cipherkey[5][5], char a , char b, int 	arr[])
{
	int i,j;
	if (a=='j')
		a= 'i';
	else if(b=='j')
		b= 'i';

	for (i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			if(cipherkey[i][j] ==a)
			{
				arr[0]=i;
				arr[1]=j;
			}
			if(cipherkey[i][j] ==b)
			{
				arr[2]=i;
				arr[3]=j;
			}
		}
	}
}

// Decryption
void decrypt(char cipherkey[5][5],int row1,int row2,int col1,int col2, char numcipher[2])
{
	
	if(row1==row2)
    {
		col1=(col1-1)%5;
		col2=(col2-1)%5;
		if(col1<0)
		{
			col1=5+col1;
		}
		if(col2<0)
		{
			col2=5+col2;
		}
		numcipher[0]=cipherkey[row1][col1];
		numcipher[1]=cipherkey[row2][col2];
    }
    else if(col1==col2)
    {
		row1=(row1-1)%5;
		row2=(row2-1)%5;
		if(row1<0)
		{
		  row1=5+row1;
		}
		if(row2<0)
		{
			row2=5+row2;
		}
		numcipher[0]=cipherkey[row1][col1];
		numcipher[1]=cipherkey[row2][col2];
    }
    else if(row1!=row2&&col1!=col2)
    {
		numcipher[0]=cipherkey[row1][col2];
		numcipher[1]=cipherkey[row2][col1];
    }
   
   numcipher[2]='\0';
}