#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define Maladie 6
#define taille 10
#define chance 2
#define Sol 0

int Degats(int Nb_Vies[30],int joueur,int tab[taille][taille]);

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
    int x,y;

    x = rand()%taille+1; //spawn de la maladie aléatoire
    y = rand()%taille+1;

    tab[x][y] = Maladie;
}
int IA_test()
{

    return 0;
}

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

void Propagation_Maladie(int tab[taille][taille],int joueur,int Nb_Vies[30]){

    int i,j;
    int test;
    int degats;

    for (i=0;i<taille-1;i++){


        for(j=0;j<taille-1;j++){


        if (tab[i][j] == Maladie){

                    test = rand()%chance;   // 1 chance sur 5 que la maladie se propage

                    if (test == 1 && i>0 && j>0 && i<taille && j<taille){ // Propagation de la maladie
                        if (tab[i-1][j] != Sol && tab[i-1][j]!= Maladie){

                            degats = Degats(Nb_Vies,joueur,tab);

                    }
                    }
                    else if (test == 0){
                        tab[i-1][j] = Maladie;
                }


                    test = rand()%chance;
                    if (test == 1 && i>0 && j>0 && i<taille && j<taille){

                        if (tab[i+1][j] != Sol && tab[i+1][j]!= Maladie){

                            degats = Degats(Nb_Vies,joueur,tab);

                    }
                    }
                    else if (degats == 0){
                        tab[i+1][j] = Maladie;

                    }

                    test = rand()%chance;
                    if (test == 1 && i>0 && j>0 && i<taille && j<taille){

                        if (tab[i][j-1] != Sol && tab[i][j-1]!= Maladie){

                            degats = Degats(Nb_Vies,joueur,tab);

                    }
                    }
                    else if (degats == 0){
                        tab[i][j-1] = Maladie;
                    }


                    test = rand()%chance;
                    if (test == 1 && i>0 && j>0 && i<taille && j<taille){

                        if (tab[i][j+1] != Sol && tab[i][j+1]!= Maladie){

                            degats = Degats(Nb_Vies,joueur,tab);

                    }
                    }
                    else if (degats == 0){
                        tab[i][j+1] = Maladie;
                    }
               }
       }
    }
    }


int Degats(int Nb_Vies[30],int joueur,int tab[taille][taille]){



    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] - 1;
    if (Nb_Vies[joueur-1] == 0){

        return 0;
    }
    else
        {
        return 1;
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
{

    int x,i,y;

    for (i=1;i<=nb_joueurs;i++){
    do {
    x = rand()%taille;
    y = rand()%taille;

    }
    while (tab[x][y] == Maladie);
    tab[x][y] = i;
    }
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

int Nombre_Joueurs(){

int nb_joueurs;

    printf("Combien de joueurs: ");
    scanf("%d", &nb_joueurs);
    printf("\n");

    return nb_joueurs;
}
int main(){ /// Recuperer les valeurs des joueurs dans le tableau

int i,j;
int tab[taille][taille];
int nb_joueurs;
int Nb_Vies[30];
int joueur = 1;  /// Le joueur qui joue actuellement


    srand(time(NULL));
    for (i=0;i<taille;i++){

        for(j=0;j<taille;j++){
            SetColor(0);
            tab[i][j] = 0;
        }
    }
    SetColor(255);
    nb_joueurs = Nombre_Joueurs();

    for(i=0;i<30;i++){

        Nb_Vies[i]= 2;
    }

    Spawn_Maladie(tab);
    Spawn_Joueurs(tab,nb_joueurs);

    for (i=0;i<10;i++){
            Tour_par_Tour(tab,nb_joueurs);
            Propagation_Maladie(tab,joueur,Nb_Vies);
            Afficher_carte(tab);
            Wait();
            ClearTerms();
    }


    return 0;
}
