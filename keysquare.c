#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

//int main()
void GenerateCipherKey(char key[] , char key_square[][5])
{
	//char key[25]="CLOWN";   // key word
	//char key_square[5][5];   // 2 d array for storing the key square
	
	int *arr=(int*)calloc(26,sizeof(int));  // 26 contiguous pointers or array of 26 integers that point to -1(j), 0(non keyword letters), 1(keyword) 
	
	arr['J'-65]= -1;  // pos of j = -1
	
	int i,j,k;
	
	i=0; j=0; k=0;
	
	// filling positions of c l o w n with 1's and storing the them first in the 2d array 
	for (k = 0;key[k]!='\0'; k++)
	{
		if(key[k]=='J')
		{
			arr['I'-65]=1;
			key_square[i][j]= 'I';
			j++;
			
		}
		else
		{
			arr[key[k]-65]=1;
			key_square[i][j]=key[k];
			j++;
		}
		if (j == 5) 
		{
			i++;
			j=0;
		}
		
	}
	
	
	// rest of the positions are automatically 0, only storing the rest in the 2d array in order
	for(k=0;k<26;k++)
	{
		if(arr[k]==0)	
		{
			key_square[i][j]=(char)(k+65);
			j++;
			if(j==5)
			{
				i++;
				j=0;
			}
		}
	}
	
		
/*
	//to print arr
	for(i=0;i<26;i++)
		printf("%d\n",arr[i]);
	
	//to print key square
	for(int =0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%c",key_square[i][j]);
        }
        printf("\n");

    }
	
*/
	
	free(arr);
	//return 0;
}

