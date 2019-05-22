
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumberInt (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isNumber (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isNumberFloat (char* pStr)
{
    int i=0;
    int contadorPuntos=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!='.') && (pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        if(pStr[i] == '.')
        {
            contadorPuntos++;
            if(contadorPuntos > 1)
            {
                return 0;
            }
        }

        i++;
    }
    return 1;
}
int isLetter (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]<'a'||pStr[i]>'z')&&(pStr[i]<'A'||pStr[i]>'Z'))
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int isAlphanumeric (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]<'a'||pStr[i]>'z')&&(pStr[i]<'A'||pStr[i]>'Z')
           &&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isTelephone (char* pStr)
{
    int i=0;
    int contadorGuion=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]!='-')&&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        if(pStr[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

int isMail(char* pStr)
{
    int i;
    int contadorArroba = 0;
    int ret = 0;

    while(pStr[i] != '\0')
    {
        if((pStr[i] != '.') && (pStr[i] != '-') && (pStr[i] != '_') &&
        (pStr[i] < '0' || pStr[i] > '9') && (pStr[i] < 'a' || pStr[i] > 'z') && (pStr[i] < 'A' || pStr[i] > 'Z'))
        {
            return ret;
        }
        if(pStr[0] == '.' || pStr[i-1] == '.')
        {
            return ret;
        }
        if(pStr[i] == '@')
        {
            contadorArroba++;
        }
        i++;
    }
    if(contadorArroba == 1)
    {
        ret = 1;
    }
    return ret;
}


int isDni (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(!isNumber(pStr))
        {
            return 0;
        }
        if(strlen(pStr)<7 || strlen(pStr)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isCuit (char* pStr)
{
    int ret=0;
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!='-')&&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        else if((pStr[2]=='-')&&(pStr[10]=='-' || pStr[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}

int isSexo (char* pStr)
{
    int ret = 0;

    if(strlen(pStr) == 1)
        {
            if((strcmp(pStr,"f") == 0) || (strcmp(pStr,"m") == 0) ||
               (strcmp(pStr,"F") == 0) || (strcmp(pStr,"M") == 0))
                {
                    ret = 1;
                }
        }
    return ret;
}

int isFecha(int dia,int mes,int anio)
{
  int ret = 0;

        if((anio < 1900 || anio > 2030) &&
            (mes < 1 || mes > 12) &&
            (dia < 1 || dia > 31))
        {
            ret = 0;
        }
        switch(mes)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    {
                        if(dia < 1 || dia > 31)
                        {
                            ret = 1;
                        }
                        break;
                    }
                case 4:
                case 6:
                case 9:
                case 11:
                    {
                        if(dia < 1 || dia > 30)
                        {
                            ret = 1;
                        }
                        break;
                    }
                case 2:
                    {
                        if(dia < 1 || dia > 29)
                        {
                            ret = 1;
                        }
                        break;
                    }
            }
    return ret;
}
