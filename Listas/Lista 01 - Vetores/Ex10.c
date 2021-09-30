#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int nota, i, freq[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0; i < 80; i++)
    {
        printf("Insira uma nota: ");
        scanf("%d", &nota);
        switch (nota)
        {
        case 0:
            freq[0]++;
            break;
        case 1:
            freq[1]++;
            break;
        case 2:
            freq[2]++;
            break;
        case 3:
            freq[3]++;
            break;
        case 4:
            freq[4]++;
            break;
        case 5:
            freq[5]++;
            break;
        case 6:
            freq[6]++;
            break;
        case 7:
            freq[7]++;
            break;
        case 8:
            freq[8]++;
            break;
        case 9:
            freq[9]++;
            break;
        case 10:
            freq[10]++;
            break;
        default:
            break;
        }
    }
    for (i = 0; i < 80; i++)
        ((i < 10) ? (printf("|Nota: %d | Frequência: %d|\n", i, freq[i])) : (printf("|Nota: %d| Frequência: %d|\n", i, freq[i])));
    return 0;
}