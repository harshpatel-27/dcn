#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[1000]; 
    int char_count = 0;
    int alphabets = 0;
    int digits = 0;
    int spaces = 0;
    int special_chars = 0;

    printf("Enter text to analyze: ");
    fgets(text, sizeof(text), stdin);

    
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '\n')
        {
            continue; 
        }

        char_count++; 

        if (isalpha(text[i]))
        {
            alphabets++;
        }
        else if (isdigit(text[i]))
        {
            digits++;
        }
        else if (isspace(text[i]))
        {
            spaces++;
        }

        else
        {
            special_chars++;
        }
    }

   
    printf("\nCharacter Analysis Results:\n");
    printf("-------------------------\n");
    printf("Total Characters: %d\n", char_count);
    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Special Characters: %d\n", special_chars);

    return 0;
}