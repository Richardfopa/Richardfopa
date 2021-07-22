#include<stdio.h>
#include<math.h>
#include<stdlib.h>


void triangularisation(float **mat, int Nbrelement){
     printf("Triangularisation1\n");
     float ** matrig = NULL;
     matrig = (float **)malloc(Nbrelement * sizeof(float *));
     float *perm = NULL;
     perm = (float *)malloc(Nbrelement * sizeof(float)); 
     int i =0,j = 0,k = 0,l=0;
     for (i = 0; i < Nbrelement + 1; i++){matrig[i] = (float *)malloc(Nbrelement * sizeof(float));}
    if(mat[0][0] == 0){
        for ( int i = 1; i < Nbrelement; i++)
        {
            if(mat[i][0] == 0.0){continue;}
            else{
                for (int j = 0; j < Nbrelement + 1; j++)
                {
                    perm[j] = mat[i][j];
                    mat[i][j] = mat[0][j];
                    mat[0][j] = perm[j];
                }
                break;
            }
        }
     }
     printf("Triangularisation1\n");
     printf("\n\tMatrice initiale \n");
        for ( i = 0; i < Nbrelement; i++){
             for (j = 0; j < Nbrelement + 1; j++)
            {
                printf("%3.2f\t",mat[i][j]);
                matrig[i][j] = mat[i][j];        
            }
            printf("\n");
        }  
    
    printf("\nTrigonalisation\n\n");
     while(l < Nbrelement){
         for ( i = l; i < Nbrelement; i++){
             if(mat[i][l] != 0){
                 for(j = 0; j < Nbrelement + 1; j++){matrig[i][j] = mat[i][j] / mat[i][l];}    
              }else{continue;} 
         }
        for ( i = 0; i < Nbrelement; i++){
             for (j = 0; j < Nbrelement+1; j++){printf("%3.2f\t",matrig[i][j]);}
            printf("\n");
        }  
        printf("\n\n");
        for ( i = l+1; i < Nbrelement; i++){
            if(matrig[i][l] != 0){
                for(j = 0; j < (Nbrelement+1);j++){matrig[i][j] = matrig[l][j] - matrig[i][j];}
            }else{continue;}      
        } 
     for ( i = 0; i < Nbrelement; i++){
         for (j = 0; j < Nbrelement+1; j++)
         { 
            printf("%3.2f\t",matrig[i][j]); 
            // On change les donnees de matri en celle de matrig et on continue
            mat[i][j] = matrig[i][j];  
         } 
        printf("\n");    
     }  
     
     printf(" l = %d\n",l);
     l++;
     }
 }
// Qui prend en parametre la matrice trigonale et retourne le resulat
 void resulsub(float **matri, int Nbrelement){
     float **mat = NULL,*solut = NULL;
     int i = 0, j= 0,k=0;
     mat = (float **) malloc((Nbrelement + 1) * sizeof(float **));
     for (int i = 0; i < Nbrelement + 1; i++)
    {
        mat[i] = (float *)malloc((Nbrelement + 1) * sizeof(float));
    }
     solut = (float *)malloc((Nbrelement ) * sizeof( float ));
    //  Je recupere la derniere colonne de la matrice trigonaliser
     for ( i = 0; i < Nbrelement; i++)
     {
         solut[i] = matri[i][Nbrelement];
     }
    //  Je recupere aussi la matrice trigonale
     for ( i = 0; i < Nbrelement; i++)
     {
         for (j = 0; j < Nbrelement; j++)
         {  
             mat[i][j] = matri[i][j];
             if(j > i)
                mat[i][j] = - mat[i][j];
         }
     }
    //  Je calcule maintenant les solution finales
    for(i = 0 ; i < Nbrelement ; i++){
            printf("%3.2f\t",solut[i]);
        printf("####----------- %d\n",i);
    }
    int napasdesolution = 0; // Booleen qui s'arrete quand il y'a solution
    int infini = 0;

    if((mat[Nbrelement-1][Nbrelement-1] == 0.00) && (mat[Nbrelement-1][Nbrelement] != 0.00) ){
        printf("\n\tLe systeme matriciel n'admet pas de solution\n");
        napasdesolution = napasdesolution + 1;
        }
    else 
    if((mat[Nbrelement-1][Nbrelement-1] == 0.00) && (mat[Nbrelement-1][Nbrelement] == 0.00)){
        printf("\n\tLe systeme matriciel admet une infinite de solution\n");
        infini = infini + 1;
    }else
    for (int i = 0; i < Nbrelement; i++)
        {   
            for (int j = 0; j < Nbrelement; j++)
            {              
                if(j != Nbrelement-i-1)
                    solut[Nbrelement-i-1] +=  mat[Nbrelement-i-1][j] * solut[j]; 
            }   
        }
    for(i = 0 ; i < Nbrelement ; i++){
        printf("\n");
        for (j = 0 ; j < Nbrelement ; j++)
        {
            printf("%3.2f\t",matri[i][j]);
        }
        printf("####----------- %d\n",i);
    }
    //  J'affiche le resultat final
    printf("\n resultat avec la methode du pivot de Gauss\n"); 
    if(napasdesolution == 0 && infini == 0)
        for ( i = 0; i < Nbrelement; i++)
        {
            printf("\tt[%d] = %3.2f\n",i,solut[i]);
        }
    else 
    if(napasdesolution == 1 && infini == 0){
        printf("\n\tLe systeme n'admet pas de solution\n");
    }
    else
    if(napasdesolution == 0 && infini == 1){
        printf("\n\tLe systeme admet une infinite de solution\n");
    }
    
 }
void remplirMat(float **mat, int Nbrelement){
    printf("Entrer les donnees de la matrice ligne par ligne \n");
    int i =0;
    // affiche(mat,Nbrelement);
    for (i = 0; i < Nbrelement; i++)
    {
        printf("\nLigne %d\t\n",i);
        int j = 0;
        for (  j = 0; j < Nbrelement; j++)
        {
            printf("A[%d][%d] = ",i,j);
            scanf("%f",&mat[i][j]);
        }
    }
}

void remplirvect(float *vect_b, int Nbrelement){    
    printf("Entrer les donnees du vecteur colonne B(t) \n");
    for (int j = 0; j < Nbrelement; j++)
    {
        printf("\tB[%d] = ",j);
        scanf("%f",&vect_b[j]);
    }
}

// Matrice pour la triangularisation

void rendrtrig(float **mat_A,float **matrice_A,float *vect_b, int Nbrelement){
    //  matrice_A = malloc(sizeof(float));
    printf("rendre trig 1");
    for (int i = 0; i < Nbrelement; i++)
    {
        for (int j = 0; j < Nbrelement +1; j++)
        {
            if (j == Nbrelement)
            {
                matrice_A[i][j] = vect_b[i];
            }
            else
                matrice_A[i][j] = mat_A[i][j];
        }
        printf("%d",i);
    }
    printf("fin");
}
void affiche(float ** mat_a,int Nbrelement){
    printf("La matrice est \n");
    for (int i = 0; i < Nbrelement; i++){
        for (int j = 0; j < Nbrelement ; j++)
         {
              printf("%3.2f\t",mat_a[i][j]);
         }
         printf("L[%d]\n",i); 
     }  
}

int presentation(){
    printf("******************************************************************************\n");
    printf("***** \t\t TPE DE CALCUL MATRICIEL \t\t\t\t ***** \n");
    printf("***** \t\t Fait par :\t\t\t\t\t\t ***** \n");
    printf("***** 1)\t LONMENE FOPA Richard \t\t 14S21364 \t\t ***** \n");
    printf("***** 2)\t KAMDEM DIPPUE Ivan Blondel \t 14S22232 \t\t ***** \n");
    printf("***** 3)\t SIMO FOMO Arthur-Xavier \t 15S46315 \t\t ***** \n\nResolution \n1)A x = b\n2)f x = 0\n3)Pour quitter");    
    printf("\n******************************************************************************\n");
    int choix ;
    scanf("%d",&choix);
    return choix;

}

void pivotdegauss(){
    int Nbrelement = 0; 
    printf("Entrer la taille n de la matrice n = ");
    scanf("%d",&Nbrelement);
    system("Pause");
    float **mat_A = NULL,*vect_B = NULL,**matrig_A = NULL;
    // Allocation dynamique de la memoire
    mat_A = (float **)malloc(Nbrelement * sizeof(float *));
    for (int i = 0; i < Nbrelement; i++)
    {
        mat_A[i] = (float *)malloc(Nbrelement * sizeof(float));
    }    
    vect_B = (float *)malloc(Nbrelement * sizeof(float *));
    matrig_A =  (float **)malloc(Nbrelement * sizeof(float *));
    for (int i = 0; i < Nbrelement+1; i++)
    {
        matrig_A[i] = (float *)malloc((Nbrelement+1) * sizeof(float));
    }
    // On rempli la matrice et on renvoi dans matA
    remplirMat(mat_A,Nbrelement);
    system("Pause");
    affiche(mat_A,Nbrelement);
    system("Pause");
    // On rempli le vecteur et on renvoi dans vect
    remplirvect(vect_B,Nbrelement);
    system("Pause");
    // On cree une matrice de taille taille n x (n+1)
    printf("Rendre trigonale");
    rendrtrig(mat_A,matrig_A,vect_B,Nbrelement);
    system("Pause");
    affiche(matrig_A,Nbrelement);
    system("Pause");    
    // // On affiche la matrice n x n+1 a trigonaliser
    // affiche(mat_A,Nbrelement);
    
    triangularisation(matrig_A,Nbrelement);
    
    printf("Triangularisation is okay\n");
    system("Pause");
    resulsub(matrig_A,Nbrelement);
    system("Pause");

    // Liberation de la memoire

    for (int i = 0; i < Nbrelement; i++)
    {
        free(matrig_A[i]);
        free(mat_A);
    }    
    free(mat_A);
    free(vect_B);
    free(matrig_A);
}

float f(float *tab,int n,float x){
      float y = 0.00;
    
      if(n < 0){
          printf("\n\tVerifier votre tableau\n");
      }
      else
      for(int i = n; i > -1;i--){
          y = y + tab[i]*pow(x,i);
      }
      return y;
}

void dichotomie(){
      int i,n;
      float a,b,x;
      float E;
      float x1;
      float *tab = NULL;
    //   tab = test;
    //   test[0] = 1;test[1] = -2;test[2] = 1;
      printf("\ndonner l'interval [ a  b ] : ");
      scanf("%lf %lf",&a,&b);
      printf("\ndonner E : ");
      scanf("%lf",&E);
      printf("\nDonner le degree du polynome N = ");
      int Nbre ; 
      scanf("%d",&Nbre);
      Nbre = Nbre + 1;
      tab = (float *)malloc(Nbre * sizeof(float ));
    //   remplissage du vecteur
      printf("\nEntrer les element du vecteur polynome un a un");

    

    for (int j = 0; j <= Nbre; j++)
    {
        printf("\tB[%d] = ",j);
        scanf("%f",&tab[j]);
    }
      if(f(tab,Nbre,a)==0){
                  printf("\nla solution est : f(tab,%d,%lf) = %lf\n",f(tab,Nbre,a),a);}
      if(f(tab,Nbre,b)==0){printf("\nla solution est : %lf\n",b);}
      if(f(tab,Nbre,a)*f(tab,Nbre,b)>0){printf("\nf n'admet pas de solution dans cette intervalle \n\tRecommencer\n");goto fin;}
      if(f(tab,Nbre,a)*f(tab,Nbre,b)<0){
      n=(log10((b-a)/E)/(log10(2)))+1;
      printf("%d",n);
      for(i=1;i<=n;i++){
            x1=(a+b)/2;
            if(f(tab,Nbre,a)*f(tab,Nbre,x1)<0){
                                b=x1;}
            else if(f(tab,Nbre,b)*f(tab,Nbre,x1)<0){ a=x1;}
        }
    printf(" %lf ",x1);

 }
 fin :{system("exit : 0");}
 }


int main(int argc, char const *argv[]){
    int choix = presentation();
    
    if(choix == 1)
        while(1){
            pivotdegauss();
        }
    else if(choix == 2){
        while(1){
            dichotomie();
        }
    }else{
        printf("");
        exit(0);
    }
  system("PAUSE>null");
  return 0;
    
    system("exit");
}
