#include <stdlib.h>
#include <stdio.h>
#define MAXLENGHT 256

void scan_bin_to_array(char*);
int btd(char*);
void enter_bin_array(char**, int);
void print_bin_array(char**, int);
void print_dec_array(char*, int);


int main() 
{
    int n;
    printf("Enter ammount of binary elements: ");
    scanf("%d", &n);
    getchar();

    char* array_dec = malloc(n*sizeof(int));
    char** array_bin = malloc(n*sizeof(char*));
	
    for (int i = 0; i < n; ++i) 
	{
        array_bin[i] = malloc(MAXLENGHT*sizeof(char));
    }
    
    enter_bin_array(array_bin, n);
    
    for (int i = 0; i < n; ++i) 
	{
        array_dec[i] = btd(array_bin[i]);
    }
    
    print_bin_array(array_bin, n);
    print_dec_array(array_dec, n);
    return 0;
}


void scan_bin_to_array(char* bin) 
{
    char bin_symb;
    int pointer = 0;
    while ((bin_symb = getchar())!='\n')
        if ((bin_symb == '1')||(bin_symb == '0'))
            bin[pointer++] = bin_symb;
    bin[pointer++] = '\0';
}

int btd(char* bin) 
{
    char bin_symb;
    int dec = 0;
    int pointer = 0;
    while ((bin_symb = bin[pointer++])!='\0')
        if ((bin_symb == '1')||(bin_symb == '0')) 
		{
            dec*=2;
            dec+= bin_symb-'0';
        }
    return dec;
}


void enter_bin_array(char** array_bin, int n) 
{
    printf("Enter binaries:\n");
    for (int i = 0; i < n; ++i) 
	{
        printf("%d: ", i+1);
        scan_bin_to_array(array_bin[i]);
    }
}


void print_bin_array(char** array_bin, int n) 
{
    printf("Array of binaries:\n");
    for (int i = 0; i < n; ++i) 
	{
        printf("%d: %s\n", i+1, array_bin[i]);
    }
}


void print_dec_array(char* array_dec, int n) 
{
    printf("Array of decimals:\n");
    for (int i = 0; i < n; ++i) 
	{
        printf("%d: %d\n", i+1, array_dec[i]);
    }
}



