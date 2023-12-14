#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void FeldZurücksetzen(char Spielfeld[3][3]);
void SpielFeldAusgeben(char Spielfeld[3][3]);
int FreieFelderÜberprüfen(char Spielfeld[3][3]);                //MUSS 
void SpielerZug(char Spielfeld[3][3], char SPIELER);
void ComputerZug(char Spielfeld[3][3], char COMPUTER);
char GewinnerÜberprüfung(char Spielfeld[3][3]);                 //DAS HIER MUSS AUCH WEG
void AusgabeGewinner(char winner, char SPIELER, char COMPUTER);
        
int main()
{
    char Gewinner = ' ';
    char Rückgabe = ' ';
    char SPIELER = 'X';
    char COMPUTER = 'O';        
    char Spielfeld [3][3];

    printf("\n\n");
    printf("Dies ist ein TicTacToe Spiel.\n");
    printf("Gespielt wird nach den klassichen Regeln. Sie haben den ersten  Zug und spielen mit dem Symbol X.\n");
    printf("Sie wählen nacheinander die Reihe und dann die Spalte wo sie ihr X plazieren wollen.\n\n\n"); 

    do
    {
        Gewinner = ' ';
        Rückgabe = ' ';
        FeldZurücksetzen(Spielfeld);

        while (Gewinner == ' ' && FreieFelderÜberprüfen(Spielfeld) != 0)
        {
            SpielFeldAusgeben(Spielfeld);

            SpielerZug(Spielfeld,SPIELER);
            Gewinner = GewinnerÜberprüfung(Spielfeld);
            if (Gewinner != ' ' || FreieFelderÜberprüfen(Spielfeld) == 0)
            {
                break;
            }

            ComputerZug(Spielfeld,COMPUTER);
            Gewinner = GewinnerÜberprüfung(Spielfeld);
            if (Gewinner != ' ' || FreieFelderÜberprüfen(Spielfeld) == 0)
            {
                break;
            }
        }

        SpielFeldAusgeben(Spielfeld);
        /*AusgabeGewinner(Gewinner);*/      //WAS IST DEIN SCHEIß PROBLEM ???

        printf("\n\nWuerden sie gerne noch einmal Spielen ?(Y/N): ");
        getchar();
        scanf("%c", &Rückgabe);
        
    } while (Rückgabe == 'Y'||Rückgabe =='y');

    printf("Vielen Dank fürs Spielen, wir hoffen sie hatten spass!\n");

    return 0;
}

void FeldZurücksetzen(char Spielfeld[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Spielfeld[i][j] = ' ';
        }
    }
}


void SpielFeldAusgeben(char Spielfeld[3][3])
{
    printf(" %c | %c | %c ", Spielfeld[0][0], Spielfeld[0][1], Spielfeld[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", Spielfeld[1][0], Spielfeld[1][1], Spielfeld[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", Spielfeld[2][0], Spielfeld[2][1], Spielfeld[2][2]);
    printf("\n");
}

int FreieFelderÜberprüfen(char Spielfeld[3][3])
{
    int freeSpaces = 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Spielfeld[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}


void SpielerZug(char Spielfeld[3][3], char SPIELER)
{
    int x;
    int y;

    do
    {
        printf("Waehle eine Reihe von 1-3: ");
        scanf("%d", &x);
        x--;
        printf("Waehle eine Spalte von 1-3: ");
        scanf("%d", &y);
        y--;

        if (Spielfeld[x][y] != ' ')
        {
            printf("Dies ist leider nicht möglich!\n");
        }
        else
        {
            Spielfeld[x][y] = SPIELER;
            break;
        }
    } while (Spielfeld[x][y] != ' ');

}


void ComputerZug(char Spielfeld[3][3], char COMPUTER)
{
    //creates a seed based on current time
    srand(time(0));
    int x;
    int y;

    if (FreieFelderÜberprüfen(Spielfeld) > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (Spielfeld[x][y] != ' ');

        Spielfeld[x][y] = COMPUTER;
    }
    else
    {
        /*AusgabeGewinner(' ');*/
        printf("och ne");
    }
}


char GewinnerÜberprüfung(char Spielfeld[3][3])
{
    //check rows
    for (int i = 0; i < 3; i++)
    {
        if (Spielfeld[i][0] == Spielfeld[i][1] && Spielfeld[i][0] == Spielfeld[i][2])
        {
            return Spielfeld[i][0];
        }
    }
    //check columns
    for (int i = 0; i < 3; i++)
    {
        if (Spielfeld[0][i] == Spielfeld[1][i] && Spielfeld[0][i] == Spielfeld[2][i])
        {
            return Spielfeld[0][i];
        }
    }
    //check diagonals
    if (Spielfeld[0][0] == Spielfeld[1][1] && Spielfeld[0][0] == Spielfeld[2][2])
    {
        return Spielfeld[0][0];
    }
    if (Spielfeld[0][2] == Spielfeld[1][1] && Spielfeld[0][2] == Spielfeld[2][0])
    {
        return Spielfeld[0][2];
    }

    return ' ';
}


void AusgabeGewinner(char winner, char SPIELER, char COMPUTER)
{
    printf("Gewinner: %c, SPIELER: %c, COMPUTER: %c\n", winner, SPIELER, COMPUTER);

    if (winner == SPIELER)
    {
        printf("Sie haben gewonnen, fühlen sie sich jetzt toll?!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("Leider Verloren du looser!\n");
    }
    else {
        printf("Gleichstand, nächstes mal wirds besser!\n");
    }

}