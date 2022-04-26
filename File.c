#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define stdLength 100

int characterGenerator();
int upperLowerNumberMix();

int main()
{
    srand(time(0));
    char password[stdLength] = {0};
    int passwordLength, passwordType;

    printf("\nWhat length should the password be: ");
    scanf("%d", &passwordLength);

    printf("\nWould you like special characters or not (1 for yes, 2 for no): ");
    scanf("%d", &passwordType);

    for (int i = 0; i < passwordLength; i++)
    {
        if (passwordType == 1)
        {
            password[i] = characterGenerator();
        }
        else if (passwordType == 2)
        {
            password[i] = upperLowerNumberMix();
        }

        if (i == passwordLength - 1)
        {
            password[i + 1] = '\0';
        }
    }
    printf("%s", password);

    password[0] = '\0';

    return 0;
}

int characterGenerator()
{
    int digit = rand() % (126 + 1 - 33) + 33;

    return digit;
}

int upperLowerNumberMix()
{
    int digit = rand() % (122 + 1 - 48) + 48;

    while (digit >= 58 && digit <= 64 || digit >= 91 && digit <= 96)
    {
        digit = rand() % (122 + 1 - 48) + 48;
    }

    return digit;
}