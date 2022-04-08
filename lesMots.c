#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TBLOC 8
char *LireChaine()
{
	int taille = TBLOC;
	char *buffer = (char *) malloc(taille*sizeof(char));
	char *p=buffer;
	printf("taper une phrase ou un mot: ");
	for (;;) {
		/* boucle de lecture */
		if ((*p=getchar()) == '\n'){ /* lecture d'un \n */
		if ((p==buffer) || (*(p-1) != '\\'))
		break;
		p--; /* annulation du \n (precede de \)*/
		continue;
		}
		if (++p == buffer + taille) {
			/* Agrandissement de la mÃ©moire de lecture*/
			buffer=realloc(buffer,taille+TBLOC);
			p=buffer+taille;
			taille+=TBLOC;
		}
	}
	*p='\0';
	/*Allocation d'un zone de la taille de la chaÃ®ne*/
	p=malloc(p-buffer+1);
	strcpy(p,buffer);
	/*libÃ©ration de la mÃ©moire intermÃ©diaire*/
	free(buffer);
	return p;
}
int len(char *p){
	int i=0; char *s=p;
	if (s==NULL) {printf("pointeur de chaine nul\n");return 0;}
	while ((s!=NULL) && (*s!='\0')) {i++;s++;}
	if (*s=='\0')return i;
	else {printf("ceci n'est pas une chaine\n");return 0;}
}
int imprimer_motifs(int j, int l,int i,char *f){
	int k,ki;
	if (j==l) {
		printf("%3d%3d\n",i-l+1-l,i-l);
		for (k=i-l+1;k<=i;k++) printf("%3c",f[k-l]);
		printf("\n");}
	if (j>l){
		for (ki=1, k=i-l+1; k<=i;k++,ki++)
		if (f[k]!=f[ki]) return 0;
		printf("%3d%3d\n",i-l+1-l,i-l);
		for (k=i-l+1;k<=i;k++) printf("%3c",f[k-l]);
		printf("\n");
	}
}
void knuth_motifs(char *f,int phi[],int l){
	int i,j;
	phi[1]=0;
	for (i=2; f[i]!='\0';i++){
		j=phi[i-1];
		while ((f[j+1]!=f[i]) && (j>0))
		{
			j=phi[j];
			imprimer_motifs(phi[i],l,i,f);
		}
	}
	if (f[j+1]!=f[i]) phi[i]=0;
	else {
		phi[i]=j+1;
		imprimer_motifs(phi[i],l,i,f);
	}
}

