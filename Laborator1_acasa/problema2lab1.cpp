#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/*
Read a sentence from the input using scanf API. Then sort split it into words and write to the screen (using the printf API) the words sorted (from the longest one to the shortest one).If two words have the same length - they will be sorted out alphabetically. We consider that each word is separated from another one using space (one or multiple).

Example: let's consider the following sentence: "I went to the library yesterday". The program will print the following to the screen:

             yesterday

             library

             went

             the

             to

             I
*/
using namespace std;
void sortare(char x[50][50], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (strlen(x[i]) < strlen(x[j]))
            {
                char aux[100];
                strcpy(aux, x[i]);
                strcpy(x[i], x[j]);
                strcpy(x[j], aux);
            }
}
int main()
{
    char x[50][50], s[250];
    int n = 0;
    scanf("%[^\n]", s);
    char* p;
    p = strtok(s, " ");
    while (p != NULL)
    {
        n++;
        strcpy(x[n], p);
        p = strtok(NULL, " ");
    }
    sortare(x, n);
    for (int i = 1; i <= n; i++)
        cout << x[i] << endl;
    return 0;
}