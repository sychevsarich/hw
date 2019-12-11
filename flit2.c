#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

FILE *fp;

char *name = "sample";
int quantityrOfNumberInFile(FILE *fp);
int *arrayOfNumber(FILE *fp);
int findOfMaxElement(int *Array);
int main()
{
	int *a = arrayOfNumber(fp);
	int max = findOfMaxElement(a)+1;
	int n = quantityrOfNumberInFile(fp);
	int *count = (int*)malloc(max * sizeof(int));
	for(int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }
	for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < max; ++j)
        {
            if (a[i] == j)
            {
                count[j]++;
            }
        }
    }
    int b = count[0]; 
	for (int i = 0; i < max; ++i)
	{
		if (count[i] >= b)
		{
			b = count[i];
		}
	}
	int acc = 0;
	for (int i = 0; i < max; ++i)
	{
		if (count[i] == b)
		{
			acc++;
		}
	}
	int *massiv = (int*)malloc(acc * sizeof(int));
	int y = 0;
	for(int i = 0; i < acc; i++)
	{
		for (int j = 0+y; j < max; ++j)
		{
			if (count[j] == b)
			{
				massiv[i] = j;
				y = j+1;
				break;
			}
		}
	}
    printf("Вершины с максимальной степенью: ");

    for (int i = 0; i < acc; ++i)
    {
    	printf("%d", massiv[i]);
    	printf("-ая ");
    }
	return 0;
}
int quantityrOfNumberInFile(FILE *fp)
{
	int c, acc;
	fp = fopen(name, "r");
	c = getc(fp);
	acc = 0;
	while(c != EOF)
	{
		if (isdigit(c))
		{
			acc++;
		}
		c = getc(fp);
	}
	fclose(fp);
	return acc;
}
int *arrayOfNumber(FILE *fp)
{
	int c, n;
	n = quantityrOfNumberInFile(fp);
	int *Array = (int*)malloc(n * sizeof(int));
	fp = fopen(name, "r");
	c = getc(fp);
	int i = 0;
	while(c != EOF)
	{
		if (isdigit(c))
		{
			Array[i] = (c - '0');
			i++;
		}
		c = getc(fp);
	}
	fclose(fp);
	return &Array[0];
}
int findOfMaxElement(int *Array)
{
	int max = Array[0]; 
	for (int i = 0; Array[i] != '\0'; ++i)
	{
		if (Array[i] >= max)
		{
			max = Array[i];
		}
	}
	return max;
}