#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

void getInt(int* pResult , char msg[100],  char errorMsg[100], int mini, int maxi)
{
    int auxInt;
    int success = 0;
    do
    {
        printf("%s", msg);
        fflush(stdin);
        scanf("%d", &auxInt);
        if(auxInt<mini)
        {
            printf("%s\n", errorMsg);
        }
        else if(auxInt>maxi)
        {
            printf("%s\n", errorMsg);
        }
        else
        {
            success = 1;
        }
    }while(success==0);
    *pResult = auxInt;
}

void getIntMin(int* pResult , char msg[100], char errorMsg[100], int mini)
{
    int auxInt;
    int success = 0;
    do
    {
        printf("%s", msg);
        fflush(stdin);
        scanf("%d", &auxInt);
        if(auxInt<mini)
        {
            printf("%s\n", errorMsg);
        }
        else
        {
            success = 1;
        }
    }while(success==0);
    *pResult = auxInt;
}

void getString(char name[], char msg[], int maxLen)
{
    char auxChar[1000];
    int success = 0;
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(auxChar);
        if(strlen(auxChar)>=maxLen)
        {
            printf("Error, el valor ingresado supera los %d caracteres.\n", maxLen-1);
        }
        else
        {
            strcpy(name, auxChar);
            success=1;
        }
    }while(success==0);
}

int getYesOrNo(char msg[100], char errorMsg[100])
{
    char auxChar;
    int success = -1;
    do
    {
        printf("%s", msg);
        fflush(stdin);
        scanf("%c", &auxChar);
        if(auxChar=='s' || auxChar=='S')
        {
            success = 1;
        }
        else if(auxChar== 'n' || auxChar=='N')
        {
            success = 0;
        }
        else
        {
            printf("%s", errorMsg);
        }
    }while(success==-1);
    return success;
}
