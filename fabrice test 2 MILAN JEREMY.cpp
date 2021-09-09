#include <stdio.h>
#include <sys/time.h>

//Déclaration des varibales
int valCapteur[8] = {2,56,180,60,10,1020,65,55};
int i, j, tampon,somme = 0;
float moyenne = 0.00;
unsigned long duree;
struct timeval debutCalcul, finCalcul;
int normaliseCapteur( int valCapteur[8] );

//Calcule le temps et affiche la duree et la moyenne
void print_all_info ()
{
    gettimeofday(&finCalcul,NULL);
    printf("MOYENNE = %.2f",moyenne);
    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Duree %ld ms\n", duree );  
}

//tri le tableau dans l'ordre croisant
void sorting_valCapteur ()
{
for (i=1 ; i <= 8-1; i++) 
	{
    j = i;
    while (j > 0 && valCapteur[j-1] > valCapteur[j]) 
		{
      tampon = valCapteur[j];
      valCapteur[j] = valCapteur[j-1];
      valCapteur[j-1] = tampon;
      j--;
    	}
  	}
i=0;
}

//Calcule la moyenne
void do_average ()
{
while (i!= 6)
	{
	somme = somme + valCapteur[i];
	i++;
	}
moyenne = somme / 4;
}

//main du programme
int main(void)
{
gettimeofday(&debutCalcul,NULL);// démare le timer pour le calcule

sorting_valCapteur();//tri le tableau dans l'ordre croisant

do_average();// calcule la moyenne

print_all_info();// calcule le temps et affiche la duree et la moyenne
}

