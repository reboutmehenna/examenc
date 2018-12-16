#include <stdio.h>
#include <stdlib.h>

/* Nom de la structure à utiliser et à ne pas modifier */
struct Equation_Recurrente
{	int m;
	int n;
	float *a;
	float *b;
};


/* En-têtes des fonctions
Il ne faut pas les modifier */

struct Equation_Recurrente Saisie_Affichage();

float Gain_Statique1(struct Equation_Recurrente);

float Gain_Statique2(struct Equation_Recurrente, float K);


struct Equation_Recurrente x;
struct Equation_Recurrente Saisie_Affichage()
{
	printf("saisir m :\n");
	scanf("%d",&x.m);
	printf("saisir n :\n");
	scanf("%d",&x.n);

	// allocations
	//x.a=malloc(sizeof(int)*(x.m+1))
	//x.b=malloc(sizeof(int)*(x.n+1))
	x.a=calloc ( x.m+1 , sizeof(int) );
	x.b=calloc ( x.n+1 , sizeof(int) );
	// Remplissage de a
	for(int i=0;i<=x.m;i++)
	{
		printf("saisir le ceof a[%d] :\n",i);
		scanf("%f",&x.a[i]);
	}
	//Remplissage b
	for(int i=0;i<=x.n;i++)
	{
		printf("saisir le ceof b[%d] :\n",i);
		scanf("%f",&x.b[i]);
	}
	//affichage a
	for( int i=0;i<=x.m;i++)
	{
		printf("a[%d]=%f \n",i,x.a[i]);
	}
	//affichage b
	for( int i=0;i<=x.n;i++)
	{
		printf("b[%d]=%f \n",i,x.b[i]);
	}
	return x;
}

float Gain_Statique1(struct Equation_Recurrente y)
{
	float somme_a=0, somme_b=0;
	if(y.m==0 && y.n==1)
	{// la somme des ai
		for(int i=0;i<=y.m;i++)
		{
			somme_a+=y.a[i];
			
		}
		printf("somme_a %f \n",somme_a);
	
		// la somme des bi
		for(int i=0;i<=y.n;i++)
		{
			somme_b+=y.b[i];
			
		}
		printf("somme_b %f \n",somme_b);

		if(somme_b != 0)
		{
			return somme_a/somme_b;
		}
		else
		{	
		printf("la division par zéro\n");
		return 0;
		}
		}
	else
	{
		printf(" il faut que n=1 et m=0\n");
		return 0;
	}
}

float Gain_Statique2(struct Equation_Recurrente c, float K)
{
		
}

int main(void)
{
/* Le main est à faire évoluer au cours de l’examen */

	//Saisie_Affichage();
	float gain = Gain_Statique1(Saisie_Affichage());
	printf("gain=%f \n",gain);
	return 0;
}
