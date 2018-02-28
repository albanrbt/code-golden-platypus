#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Maladie 6
#define taille 50
#include <windows.h>

void SetColor(int ForgC)//Ne pas tenir compte de cette fonction.
{
  WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
  {
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
  return;
}

void ClearTerms()
{
    system("cls");
}

void Wait()
{
    system("pause");
}

void Spawn_Maladie (int tab[taille][taille])
 {
    srand(time(NULL));
    int x,y;
    x = rand()%taille; /// aleatoire a corriger, le spawn est toujours au meme endroit
    y = rand()%taille;
    tab[x][y] = Maladie;

}

void Propagation_Maladie(int tab[taille][taille]){ /// aleatoire a revoir encore

    int i,j;
    int test;


    for (i=1;i<taille-1;i++){ /// corriger les sorties de tableau pour les voisins


        for(j=1;j<taille-1;j++){


               if (tab[i][j] == Maladie){

                test = rand()%4;   // 1 chance sur 5 que la maladie se propage
                if (test == 1){
                    tab[i-1][j] = Maladie; // Propagation de la maladie

                    }

                    test = rand()%4;
                if (test == 1){
                    tab[i+1][j] = Maladie;

                    }

                    test = rand()%4;
                if (test == 1){
                    tab[i][j-1] = Maladie;

                    }

                    test = rand()%4;
                if (test == 1){
                    tab[i][j+1] = Maladie;

                    }
               }
       }

    }

}

int IA_test()
{
    return 0;
}
/*
int coord_Joueurs(int tab[taille][taille],int joueurs)
{
    int coord[2];
    int i,j;
    for (i=0;i<taille;i++){

        for(j=0;j<taille;j++){
            if (tab[i][j]==joueurs){
                coord[0]=i;
                coord[1]=j;
                return &coord;
            }
        }
}
}
*/

int coord_JoueursX(int tab[taille][taille],int joueurs)
{
    int coord[2];
    int i,j,x;
    for (i=0;i<taille;i++){

        for(j=0;j<taille;j++){
            if (tab[i][j]==joueurs){
                x=i;
                return x;
            }
        }
}
}

int coord_JoueursY(int tab[taille][taille],int joueurs)
{
    int coord[2];
    int i,j,y;
    for (i=0;i<taille;i++){

        for(j=0;j<taille;j++){
            if (tab[i][j]==joueurs){
                y=j;
                return y;
            }
        }
}
}


void Tour_par_Tour(int tab[taille][taille],int nb_joueurs){ /// La fonction qui lance les différentes actions a faire (ou les execute)

int i,j,action,x,y;
int coord[2];
int* cood;
        for (i=1;i<= nb_joueurs+1;i++)
        {

            x= coord_JoueursX(tab,i);
            y= coord_JoueursY(tab,i);
            //action = IA_i();
            action= IA_test();


       if (action == 1){ ///en bas
            tab[x][y]=0;
            x=x+1;
            tab[x][y]=i;
       }

       else if (action == 2){

       }

       else if (action == 2){}

       else if (action == 2){}

       else if (action == 2){}

       else if (action == 2){}
        }
}

void Spawn_Joueurs(int tab[taille][taille],int nb_joueurs)
{//mettre pas de spawn dans la maladie

    int x,i,y;

    for (i=1;i<=nb_joueurs;i++){
    do {
    x = rand()%taille;
    y = rand()%taille;
    tab[x][y] = i;}
    while (tab[x][y] == Maladie);
    }
}


int Nombre_Joueurs(){

int nb_joueurs;

    printf("Combien de joueurs: ");
    scanf("%d", &nb_joueurs);
    printf("\n");

    return nb_joueurs;
}

void Afficher_carte(int tab[taille][taille])
{
    int i,j;
 for (i=0;i<taille;i++)
    {

        for(j=0;j<taille;j++){

            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }

}
int main(){ /// Recuperer les valeurs des joueurs dans le tableau

int i,j;
int tab[taille][taille];
int nb_joueurs;
 srand(time(NULL));

    for (i=0;i<taille;i++){

        for(j=0;j<taille;j++){
            SetColor(0);
            tab[i][j] =0;
        }
    }
    SetColor(255);
    nb_joueurs = Nombre_Joueurs();
    Spawn_Joueurs(tab,nb_joueurs);
    Spawn_Maladie(tab);



    for (i=0;i<10;i++){
            Tour_par_Tour(tab,nb_joueurs);
            Propagation_Maladie(tab);
            Afficher_carte(tab);
            Wait();
            ClearTerms();
    }

    return 0;
}
