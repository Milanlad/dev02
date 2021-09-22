#include <stdio.h>
#include <sys/time.h>

//Déclaration des varibales globales
int valCapteur[8] = {2,56,180,60,10,1020,65,55};
unsigned long duree;
struct timeval debutCalcul, finCalcul;


//Calcule le temps et affiche la duree et la moyenne
void print_all_info (float average)
{
    gettimeofday(&finCalcul,NULL);
    printf("MOYENNE = %.2f",average);
    duree = ((finCalcul.tv_sec - debutCalcul.tv_sec) * 1000000) + (finCalcul.tv_usec - debutCalcul.tv_usec);
    printf( "Duree %ld ms\n", duree );  
}

//tri le tableau dans l'ordre croisant
void sorting_valCapteur ()
{
int tampon = 0;
for (int i =1 ; i <= 8-1; i++) 
	{
    int j = i;
    while (j > 0 && valCapteur[j-1] > valCapteur[j]) 
		{
      tampon = valCapteur[j];
      valCapteur[j] = valCapteur[j-1];
      valCapteur[j-1] = tampon;
      j--;
    	}
  	}
}

//Calcule la moyenne
float do_average ()
{
int somme = 0;
float moyenne =0.00;
for (int b = 2; b!=6 ;b++)
	{
	somme = somme + valCapteur[b];
	}
moyenne = somme / 4;
return moyenne ;
}

//main du programme
int main(void)
{
gettimeofday(&debutCalcul,NULL);// démare le timer pour le calcule

sorting_valCapteur();//tri le tableau dans l'ordre croisant

print_all_info(do_average());// calcule le temps et affiche la duree et la moyenne
}