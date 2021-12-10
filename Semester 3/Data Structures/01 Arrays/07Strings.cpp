#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    /* Definition */
    char A[] = {'A', 'B', 'C', '\0'};
    char B[] = "ABC";
    /* Input including blanks */
    char C[25];
    scanf("%[^\n]s", C);
    printf("%s \n", C);
    char D[20];
    //gets_s(D);
    puts(D);
    /* Traversing through string */
    int i = 0;
    char E[10];
    scanf("%[^\n]s", E);
    //gets_s(E);
    while (E[i] != '\0')
        printf("%c", E[i++]);
    printf("\n");
    i = 0;
    while (i < strlen(E))
        printf("%c", E[i++]);
    printf("\n");
    /* Inbuilt functions */
    char F[] = "wxYZ", G[] = "78", H[20];
    printf("Length of %s = %d \n", F, strlen(F));
    if (strcmp(F, G) == 0)
        printf("F, G same strings \n");
    printf("H = %s \n", strcpy(H, F));
    printf("Uppercase of F = %s \n", strupr(F));
    printf("Concat F + H = %s \n", strcat(H, F));
    printf("Reverse F = %s \n", strrev(F));
    /* 2-D character array */
    char names[6][10] = {"akshay", "parag", "raman"};
    puts(names[0]);
    puts(names[2]);
    return 0;
}