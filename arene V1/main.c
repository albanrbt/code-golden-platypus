#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MALADIE 6
#define NB_TOURS 10
#define TAILLE 10
#define CHANCE 2
#define SOL 0
#define KIT 44
#define PIEGE 33

int Degats(int Nb_Vies[30],int joueur);

void SetColor(int ForgC){//Ne pas tenir compte de cette fonction.

  WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
  {
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }

}

void ClearTerms()
{
    system("cls");
}

void Wait()
{
    system("pause");
}


int IA_test(){

    return 0;
}

int coord_JoueursX(int tab[TAILLE][TAILLE],int joueurs)
{
    int i,j,x;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (tab[i][j] == joueurs)
            {
                x = i;
                return x;
            }
        }
    }
}

int coord_JoueursY(int tab[TAILLE][TAILLE],int joueurs)
{
    int i,j,y;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (tab[i][j] == joueurs)
            {
                y = j;
                return y;
            }
        }
    }
}

void Propagation_Maladie(int tab[TAILLE][TAILLE],int joueur,int Nb_Vies[30])
{
    int i,j;
    int test;
    int degats;
    int tab1[TAILLE][TAILLE];

    srand(time(NULL));
    for (i = 0; i < TAILLE - 1; i++)
    {
        for (j = 0; j < TAILLE - 1; j++)
        {
            tab1[i][j] = tab[i][j];
        }
    }
    for (i = 0; i < TAILLE - 1; i++)
    {
        for (j = 0; j < TAILLE - 1; j++)
        {
            if (tab[i][j] == MALADIE)
            {
                test = rand() % CHANCE;   // 1 CHANCE sur 5 que la MALADIE se propage
                if ((test == 1) && (i > 0) && (j > 0) && (i < TAILLE) && (j < TAILLE)) // Propagation de la MALADIE
                {
                    if ((tab[i-1][j] >= 1) && (tab[i-1][j] <= 30))
                    {
                    degats = Degats(Nb_Vies,joueur);
                    }
                }
                else if (test == 0)
                {
                    tab1[i-1][j] = MALADIE;
                }
                test = rand() % CHANCE;
                if ((test == 1) && (i > 0) && (j > 0) && (i < TAILLE) && (j < TAILLE))
                {
                    if ((tab[i+1][j] >= 1) && (tab[i+1][j] <= 30))
                    {
                        degats = Degats(Nb_Vies,joueur);
                    }
                }
                else if (degats == 0)
                {
                    tab1[i+1][j] = MALADIE;
                }
                test = rand() % CHANCE;
                if ((test == 1) && (i > 0) && (j > 0) && (i < TAILLE) && (j < TAILLE))
                {
                    if ((tab[i][j-1] >= 1) && (tab[i][j-1] <= 30))
                    {
                        degats = Degats(Nb_Vies,joueur);
                    }
                }
                else if (degats == 0)
                {
                    tab1[i][j-1] = MALADIE;
                }
                test = rand() % CHANCE;
                if ((test == 1) && (i > 0) && (j > 0) && (i < TAILLE) && (j < TAILLE))
                {
                    if ((tab[i][j+1] >= 1) && (tab[i][j+1] <= 30))
                    {
                        degats = Degats(Nb_Vies,joueur);
                    }
                }
                else if (degats == 0)
                {
                    tab1[i][j+1] = MALADIE;
                }
            }
        }
    }
    for (i = 0; i < TAILLE - 1; i++)
    {
        for (j = 0; j < TAILLE - 1; j++)
        {
            tab[i][j] = tab1[i][j];
        }
    }
}

void Bonus(int Nb_Vies[30],int joueur)
{
    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] + 1;
}

int Degats(int Nb_Vies[30],int joueur)
{
    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] - 1;
    if (Nb_Vies[joueur-1] == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Tour_par_Tour(int tab[TAILLE][TAILLE],int nb_joueurs,int Nb_Vies[30],int joueur)/// La fonction qui lance les différentes actions a faire (ou les execute)
{
    int i,action,x,y;

    for (i = 1; i <= nb_joueurs + 1; i++)
    {
        x = coord_JoueursX(tab,joueur);
        y = coord_JoueursY(tab,joueur);
        //action = IA_i();
        action = IA_test();
        if (action == 1)///en bas
        {
            tab[x][y] = 0;
            tab[x+1][y] = i;
            if (tab[x+1][y] == KIT)
            {
                Bonus(Nb_Vies,joueur);
            }
            else if (tab[x+1][y] == PIEGE)
            {
                Degats(Nb_Vies,joueur);
            }
        }
        else if (action == 2)///en haut
        {
            tab[x][y] = 0;
            tab[x-1][y] = i;
            if (tab[x-1][y] == KIT)
            {
                Bonus(Nb_Vies,joueur);
            }
            else if (tab[x-1][y] == PIEGE)
            {
                Degats(Nb_Vies,joueur);
            }
       }
       else if (action == 3)/// a droite
       {
            tab[x][y] = 0;
            tab[x][y+1] = i;
            if (tab[x][y+1] == KIT)
            {
                Bonus(Nb_Vies,joueur);
            }
            else if (tab[x][y+1] == PIEGE)
            {
                Degats(Nb_Vies,joueur);
            }
       }
       else if (action == 4)/// a gauche
       {
            tab[x][y] = 0;
            tab[x][y-1] = i;
            if (tab[x][y-1] == KIT)
            {
                Bonus(Nb_Vies,joueur);
            }
            else if (tab[x][y-1] == PIEGE)
            {
                Degats(Nb_Vies,joueur);
            }
       }
       else if (action == 2)
       {
       }
       else if (action == 2)
       {
       }
    }
}

void Spawn_Joueurs(int tab[TAILLE][TAILLE],int nb_joueurs)
{
    int x,y,i;

    for (i = 1; i <= nb_joueurs; i++)
    {
        do
        {
            x = rand() % TAILLE - 1;
            y = rand() % TAILLE - 1;
        } while (tab[x][y] != SOL);
        tab[x][y] = i;
    }
}

void Spawn_Maladie (int tab[TAILLE][TAILLE])
{
    int x,y;

    x = rand() % TAILLE - 1; //spawn de la MALADIE aléatoire
    y = rand() % TAILLE - 1;
    tab[x][y] = MALADIE;
}

void Spawn_Piege(int tab[TAILLE][TAILLE])
{
    int x,y;

    do
    {
        x = rand() % TAILLE;
        y = rand() % TAILLE;
    } while (tab[x][y] != SOL);
    tab[x][y] = PIEGE;
}

void Spawn_Bonus(int tab[TAILLE][TAILLE])
{
    int x,y;

    do
    {
        x = rand() % TAILLE;
        y = rand() % TAILLE;
    } while (tab[x][y] != SOL);
    tab[x][y] = KIT;
}

void Afficher_carte(int tab[TAILLE][TAILLE])
{
    int i,j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

int Nombre_Joueurs()
{
    int nb_joueurs;

    printf("Combien de joueurs: ");
    scanf("%d", &nb_joueurs);
    printf("\n");
    return nb_joueurs;
}

int Numero_Joueur(int tab[TAILLE][TAILLE],int test)
{
    int i,j,x;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if ((tab[i][j] >= 1) && (tab[i][j] <= 30) && (tab[i][j] != test))
            {
                x = tab[i][j];
            }
        }
    }
    return x;
}

int Shifumi (int J1, int J2)
{
    printf("bataille entre %d et %d ", J1,J2);
}

int Afficher_Gagnant(int gagnant)
{
    ClearTerms();
    printf("gagnant \n \n");
    Wait();
    return 1;
}

int fin_jeu(int tab[TAILLE][TAILLE])
{
    int i,j,Joueur1,Joueur2,cas,gagnant;
    int test = 0;
    int y = 0;
    int joueur_Restant = 0;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if ((tab[i][j] >= 1) && (tab[i][j] <= 30))
            {
                joueur_Restant = joueur_Restant+1;

            }
        }
    }
    if (joueur_Restant == 2)
    {
        cas = 2;
        Joueur1 = Numero_Joueur(tab,test);
        test = Joueur1;
        Joueur2 = Numero_Joueur(tab,test);
    }
    if (joueur_Restant > 2)
    {
        cas = 3;
    }
    if (joueur_Restant == 0)
    {
        if (cas == 2)
        {
            gagnant = Shifumi(Joueur1,Joueur2);
            y = Afficher_Gagnant(gagnant);
        }
        else if (cas == 3)
        {
            printf("pas de gagnant, on relance la partie");
            Wait();
            ClearTerms();
            main();
        }
    }
    if (joueur_Restant == 1)
    {
        gagnant = Numero_Joueur(tab,test);
        y = Afficher_Gagnant(gagnant);
    }
    return y;
}

int main()/// Recuperer les valeurs des joueurs dans le tableau
{
    int i,j;
    int tab[TAILLE][TAILLE];
    int nb_joueurs;
    int Nb_Vies[30];
    int joueur = 1;  /// Le joueur qui joue actuellement
    int gagnant;

    srand(time(NULL));
    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            tab[i][j] = 0;
        }
    }
    do
    {
       nb_joueurs = Nombre_Joueurs();
    } while (nb_joueurs <= 0);
    for (i = 0; i < 30; i++)
    {
        Nb_Vies[i] = 1;
    }
    Spawn_Maladie(tab);
    Spawn_Joueurs(tab,nb_joueurs);
    Spawn_Bonus(tab);
    Spawn_Piege(tab);
    for (i = 0; i < NB_TOURS; i++)
    {
        Afficher_carte(tab);
        Tour_par_Tour(tab,nb_joueurs,Nb_Vies,joueur);
        Propagation_Maladie(tab,joueur,Nb_Vies);
        gagnant = fin_jeu(tab);
        if (gagnant == 1)
        {
            return 0;
        }
        else
        {
            Wait();
            ClearTerms();
        }
    }
    return 0;
}
