#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <windows.h>

#define TOURS 50

#define MALADIE 66

#define TAILLE 10

#define CHANCE 2

#define SOL 0

#define KIT 44

#define PIEGE 33

#define RADAR 3



/// LES PROTOTYPES



int Degats(int Nb_Vies[30],int joueur); // initialise les degats



int main();



void ClearTerms(); // clear la console



void Wait(); // fait une pause



int coord_JoueursX(int tab[TAILLE][TAILLE],int joueurs); // dopnne le X de chaque joueur



int coord_JoueursY(int tab[TAILLE][TAILLE],int joueurs); // donne le Y de chaque joueur



int fin_jeu(int tab[TAILLE][TAILLE]); // declare la fin du jeu



int Nombre_Joueurs(); // donne le nombre de joueurs dans la partie



int Numero_Joueur(int tab[TAILLE][TAILLE],int test); // recupere le numero du joueur suivant ses coordonnees



void Propagation_Maladie(int tab[TAILLE][TAILLE],int joueur,int Nb_Vies[30]); // propage la maladie



int Shifumi (int J1, int J2); // lance le shifumi si egalite entre 2 joueurs



void Spawn_Bonus(int tab[TAILLE][TAILLE]); // fait spawn les bonus



void Spawn_Joueurs(int tab[TAILLE][TAILLE],int nb_joueurs); // fait spawn les joueurs avec 2 cases d'ecart avec la maladie



void Spawn_Maladie (int tab[TAILLE][TAILLE]); // fait spawn la maladie



void Spawn_Piege(int tab[TAILLE][TAILLE]); // fait spawn les pieges



void Tour_par_Tour(int tab[TAILLE][TAILLE],int nb_joueurs,int Nb_Vies[30],int joueur); // execute les actions des joueurs

int jeu();

void menu();



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



void ClearTerms(){

    system("cls");

}



void Wait(){

    system("pause");

}





IA(int joueur)

{

    switch(joueur)

    {

    case 1:

        ///code IA

        break;

    case 2:

        ///code IA

        break;

    case 3:

        ///code IA

        break;

    case 4:

        ///code IA

        break;

    case 5:

        ///code IA

        break;

     case 6:

        ///code IA

        break;

     case 7:

        ///code IA

        break;

     case 8:

        ///code IA

        break;

     case 9:

        ///code IA

        break;

     case 10:

        ///code IA

        break;

     case 11:

        ///code IA

        break;

     case 12:

        ///code IA

        break;

     case 13:

        ///code IA

        break;

     case 14:

        ///code IA

        break;

     case 15:

        ///code IA

        break;

     case 16:

        ///code IA

        break;

     case 17:

        ///code IA

        break;

     case 18:

        ///code IA

        break;

     case 19:

        ///code IA

        break;

     case 20:

        ///code IA

        break;

     case 21:

        ///code IA

        break;

     case 22:

        ///code IA

        break;

     case 23:

        ///code IA

        break;

     case 24:

        ///code IA

        break;

     case 25:

        ///code IA

        break;

     case 26:

        ///code IA

        break;

     case 27:

        ///code IA

        break;

     case 28:

        ///code IA

        break;

     case 29:

        ///code IA

        break;

     case 30:

        ///code IA

        break;



    }

}



int IA_test()

{

 return 0;

}



int IA_test_Shifumi()

{

    int x;

     x = rand()%3;

     return x;



}



int coord_JoueursX(int tab[TAILLE][TAILLE],int joueurs){



    int i,j,x;



    for (i=0;i<TAILLE;i++){



        for(j=0;j<TAILLE;j++){

            if (tab[i][j]==joueurs){

                x=i;

                return x;

            }

        }

}

}



int coord_JoueursY(int tab[TAILLE][TAILLE],int joueurs){



    int i,j,y;



    for (i=0;i<TAILLE;i++){



        for(j=0;j<TAILLE;j++){

            if (tab[i][j]==joueurs){

                y = j;

                return y;

}

}

}

}



void Propagation_Maladie(int tab[TAILLE][TAILLE],int joueur,int Nb_Vies[30]){



    int i,j;

    int test;

    int degats;

    int tab1[TAILLE][TAILLE];





    srand(time(NULL));



    for(i=0;i<TAILLE;i++){



        for(j=0;j<TAILLE;j++){



            tab1[i][j] = tab[i][j];

}

}





    for (i=0;i<TAILLE-1;i++){





        for(j=0;j<TAILLE-1;j++){





            if (tab[i][j] == MALADIE){



                test = rand()%CHANCE;   // 1 CHANCE sur 5 que la MALADIE se propage



                if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){ // Propagation de la MALADIE

                    if (tab[i-1][j] >= 1 && tab[i-1][j]<=30){



                    degats = Degats(Nb_Vies,joueur);





                }

                if (degats == 0){
                    tab1[i-1][j] = MALADIE;


            }

                else

                    {

                    tab1[i-1][j] = MALADIE;



                }



                }



                test = rand()%CHANCE;

                    if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){



                        if (tab[i+1][j] >= 1 && tab[i+1][j] <= 30){



                            degats = Degats(Nb_Vies,joueur);

}



                if (degats == 0){

                    tab1[i+1][j] = MALADIE;



}



                else{



                   tab1[i+1][j] = MALADIE;

                }

                }

                test = rand()%CHANCE;

                if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){



                    if (tab[i][j-1] >= 1 && tab[i][j-1] <= 30){



                        degats = Degats(Nb_Vies,joueur);





}



                if (degats == 0){

                    tab1[i][j-1] = MALADIE;

}



                else

                    {

                    tab1[i][j-1] = MALADIE;

                    }



                }

                test = rand()%CHANCE;

                if (test == 1 && i > 0 && j > 0 && i<TAILLE && j<TAILLE){



                    if (tab[i][j+1] >= 1 && tab[i][j+1] <= 30){



                        degats = Degats(Nb_Vies,joueur);



                    }



                 if (degats == 0){

                    tab1[i][j+1] = MALADIE;

}



                    else

                        {

                        tab1[i][j+1] = MALADIE;



                    }

                }

}

}
}



    for(i=0;i<TAILLE;i++){



        for(j=0;j<TAILLE;j++){



            tab[i][j] = tab1[i][j];





        }

    }


    }



void Bonus(int Nb_Vies[30],int joueur){



    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] + 1;





}



int Degats(int Nb_Vies[30],int joueur){







    Nb_Vies[joueur-1] = Nb_Vies[joueur-1] - 1;

    if (Nb_Vies[joueur-1] <= 0){



        return 0;

    }

    else

        {

        return 1;

}

}





void Tour_par_Tour(int tab[TAILLE][TAILLE],int nb_joueurs,int Nb_Vies[30],int joueur){ /// La fonction qui lance les différentes actions a faire (ou les execute)



int i,action,x,y;







        for (i=1;i<= nb_joueurs+1;i++)

        {



            x = coord_JoueursX(tab,joueur);

            y = coord_JoueursY(tab,joueur);

            //action = IA(i);

            action = IA_test();





       if (action == 1){ ///en bas

            tab[x][y]=0;

            tab[x+1][y]=i;



            if (tab[x+1][y]== KIT){

                Bonus(Nb_Vies,joueur);

            }

            else if (tab[x+1][y] == PIEGE){

                Degats(Nb_Vies,joueur);

            }
            else if (tab[x+1][y] == 99){
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
            }

       }





       else if (action == 2){///en haut

            tab[x][y]=0;

            tab[x-1][y]=i;



            if (tab[x-1][y] == KIT){

                Bonus(Nb_Vies,joueur);

            }

            else if (tab[x-1][y] == PIEGE){

                Degats(Nb_Vies,joueur);

            }
            else if (tab[x-1][y] == 99){
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
            }

       }



       else if (action == 3){/// a droite

          tab[x][y]=0;

          tab[x][y+1]=i;



            if (tab[x][y+1] == KIT){

                Bonus(Nb_Vies,joueur);

            }

            else if (tab[x][y+1] == PIEGE){

                Degats(Nb_Vies,joueur);

            }
            else if (tab[x][y+1] == 99){
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
            }

       }



       else if (action == 4){ /// a gauche

        tab[x][y]=0;

        tab[x][y-1]=i;



            if (tab[x][y-1] == KIT){

                Bonus(Nb_Vies,joueur);

            }

            else if (tab[x][y-1] == PIEGE){

                Degats(Nb_Vies,joueur);

            }
            else if (tab[x][y-1] == 99){
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
                Degats(Nb_Vies,joueur);
            }

       }



       else if (action == 5){ /// pas bouger

        tab[x][y] = joueur;

       }

       else if (action == 2){}

        }

}



void Spawn_Joueurs(int tab[TAILLE][TAILLE],int nb_joueurs){



    int x,y,i;

    int X_maladie,Y_maladie;



    X_maladie = coord_JoueursX(tab,MALADIE);

    Y_maladie = coord_JoueursY(tab,MALADIE);



    for (i=1;i<=nb_joueurs;i++){



        do {

            x = rand()%TAILLE;

            y = rand()%TAILLE;



        }

        while (tab[x][y] != SOL || x > (X_maladie-RADAR) && x < (X_maladie+RADAR) || y > (Y_maladie-RADAR) && y < (Y_maladie+RADAR));

        tab[x][y] = i;

    }

}



void Spawn_Maladie (int tab[TAILLE][TAILLE]){



    int x,y;



    do

    {

    x = rand()%TAILLE-1; //spawn de la MALADIE aléatoire

    y = rand()%TAILLE-1;

    }

    while (x<1 || x>TAILLE-1 || y<1 || y>TAILLE-1);



    tab[x][y] = MALADIE;





}

void Spawn_Piege(int tab[TAILLE][TAILLE]){



    int x,y;



    do

    {

        x = rand()%TAILLE;

        y = rand()%TAILLE;



    }

    while (tab[x][y] != SOL);



    tab[x][y] = PIEGE;

}

void Spawn_Bonus(int tab[TAILLE][TAILLE]){



    int x,y;



    do

    {

        x = rand()%TAILLE;

        y = rand()%TAILLE;



    }

    while (tab[x][y] != SOL);



    tab[x][y] = KIT;





}

void Afficher_carte(int tab[TAILLE][TAILLE]){



    int i,j;



    for (i=0;i<TAILLE;i++)

    {



        for(j=0;j<TAILLE;j++){



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



int Numero_Joueur(int tab[TAILLE][TAILLE],int test)

{

    int i,j,x;

    for (i=0;i<TAILLE;i++)

        {



        for(j=0;j<TAILLE;j++)

        {

            if ((tab[i][j]>= 1) && (tab[i][j]<= 30) && (tab[i][j]!= test))

            {

                x = tab[i][j];



            }

        }

        }

        return x;

}



int Shifumi (int J1, int J2)

{

    int i,jeu_1,jeu_2;

    int pierre = 1;

    int ciseaux = 2 ;

    int feuille = 3;

    int gagnant = 0;



    printf("bataille entre  joueur %d et joueur %d :", J1,J2);

    do

    {

        for (i=0; i<3; i++)

        {

            jeu_1 = IA_test_Shifumi();

            jeu_2 = IA_test_Shifumi();

        }

        if ((jeu_1==1) && (jeu_2==1))

        {

            printf("LES DEUX JOUEURS ONT FAIT PIERRE \n");

        }

        else if ((jeu_1==2) && (jeu_2==2))

        {

            printf("LES DEUX JOUEURS ONT FAIT CISEAUX\n");

        }

        else if ((jeu_1==3) && (jeu_2==3))

        {

            printf("LES DEUX JOUEURS ONT FAIT FEUILLE");

        }

        else if ((jeu_1==1) && (jeu_2==2))

        {

            printf(" Aie aie joueur %d a casse ses ciseaux contre la pierre de joueur %d\n",J2,J1);

            gagnant = J1;

        }

        else if ((jeu_1==2) && (jeu_2==1))

        {

             printf(" Aie aie joueur %d a casse ses ciseaux contre la pierre de joueur %d \n",J1,J2);

            gagnant = J2;

        }

        else if ((jeu_1==2) && (jeu_2==3))

        {

            printf(" Joueur %d a appris a Joueur %d comment reduire en confettis un mauvais bulletin \n",J1,J2);

            gagnant = J1;

        }

        else if ((jeu_1==3) && (jeu_2==2))

        {

            printf(" Joueur %d a appris a Joueur %d comment reduire en confettis un mauvais bulletin\n ",J2,J1);

            gagnant = J2;

        }

        else if ((jeu_1==1) && (jeu_2==3))

        {

            printf("joueur %d viens d'emballer a la perfection la pierre de Joueur %d dans sa feuille\n", J2,J1);

            gagnant = J2;

        }

        else if ((jeu_1==3) && (jeu_2==1))

        {

             printf("joueur %d viens d'emballer a la perfection la pierre de Joueur %d dans sa feuille \n", J1,J2);

             gagnant = J1;



        }

    } while (gagnant == 0);

    return gagnant;

}



int Afficher_Gagnant(int gagnant)

{

    ClearTerms();

    printf("\n");

    printf("===========================================\n \n \n \n");

    printf("      LE GAGNANT EST LE JOUEUR %d !!! \n \n \n \n", gagnant);

    printf("=========================================== \n \n");

    Wait();

    return 1;

}

void mur (int tab[TAILLE][TAILLE]){
    tab[0][0]=99;
    tab[0][TAILLE-1]=99;
    tab[TAILLE-1][0]=99;
    tab[TAILLE-1][TAILLE-1]=99;

}

int fin_jeu(int tab[TAILLE][TAILLE])

{

    int i,j,y,joueur_Restant,test,Joueur1,Joueur2,cas,gagnant;





    test=0;

    y=0;

    joueur_Restant = 0;

    for (i=0;i<TAILLE;i++){



        for(j=0;j<TAILLE;j++){

            if ((tab[i][j]>= 1) && (tab[i][j]<= 30)){

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

int jeu()
{
int i,j;

int tab[TAILLE][TAILLE];

int nb_joueurs;

int Nb_Vies[30];

int joueur = 1;  /// Le joueur qui joue actuellement

int gagnant;



    srand(time(NULL));

    for (i=0;i<TAILLE;i++){



        for(j=0;j<TAILLE;j++){

            SetColor(0);

            tab[i][j] = 0;

        }

    }

    SetColor(255);

    do

    {

       nb_joueurs = Nombre_Joueurs();

    }

    while (nb_joueurs <= 0);





    for(i=0;i<30;i++){



        Nb_Vies[i] = 1;

    }



    Spawn_Maladie(tab);

    Spawn_Joueurs(tab,nb_joueurs);

    Spawn_Bonus(tab);

    Spawn_Piege(tab);

    mur(tab);


    for (i=0;i<TOURS;i++){



            Afficher_carte(tab);

            Tour_par_Tour(tab,nb_joueurs,Nb_Vies,joueur);

            Propagation_Maladie(tab,joueur,Nb_Vies);

            gagnant = fin_jeu(tab);

            if (gagnant == 1)

            {

                return 0;

            }

            else {

            Wait();

            ClearTerms();

            }

    }
}
void menu()
{
    int choix;
    do{
    ClearTerms();
    SetColor(255);
    printf("====== Menu ======\n\n");
    printf("Choisir une action\n");
    printf("1. Jouer\n");
    printf("2. Quitter\n\n");
    printf("==================\n");
    scanf("%d", &choix);
    if(choix==1)
    {
        jeu();
    }

}while (choix!=2);

}
int main(){ /// Recuperer les valeurs des joueurs dans le tableau

menu();
return 0;

}
