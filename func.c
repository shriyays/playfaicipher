#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"


//Converting all characters to upper case
void toUpperCase(char letter[], int y)
{
    int i;
    for (i = 0; i < y; i++) {
        if (letter[i] >= 97 && letter[i] <= 122)
            letter[i] -= 32;
    }
}

// Remove all spaces in a string
int removeSpace(char letter[], int y)//y=length
{	
	int i, count;
	count=0;
    for (i = 0; letter[i]!='\0'; i++)
	{
        if (letter[i] != ' ')
            letter[count++] = letter[i];
       
	}
	letter[count] = '\0';
	return count-1;
}

//to make it even
int even(char str[], int ptrs)
{
    if (ptrs % 2 != 0)
    {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
    }
    return ptrs;
}

