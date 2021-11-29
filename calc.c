#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = 0;
    if (argc != 4)
    {
        printf("Usage: ./calc <values>\n");
        return 1;
    }
    else
    {
         key = atoi(argv[1]);
    }
    if (strcmp(argv[2],"+") == 0)
    {
        printf("%f\n",atof(argv[1]) + atof(argv[3]));
    }
    else if (strcmp(argv[2],"-") == 0)
    {
        printf("%f\n",atof(argv[1]) - atof(argv[3]));
    }
    else if (strcmp(argv[2],"/")==0)
    {
        printf("%f\n",atof(argv[1]) / atof(argv[3]));
    }
    else if (strcmp(argv[2],"x")==0)
    {
        printf("%f\n",atof(argv[1]) * atof(argv[3]));
    }
    else if (strcmp(argv[2],"%")==0)
    {
        //printf("%f\n",(double)(atoi(argv[1]) % atoi(argv[3])));
        printf("%f\n",fmod(atof(argv[1]), atof(argv[3])));
    }
    else
    {
        return 1;
    }

}