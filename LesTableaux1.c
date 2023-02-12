/*Deux versions pour programmer le tri par sélection :
La première version utilise une fonction imin qui recherche l’indice du plus petit
élément entre les indices i et j. cette version utilise deux boucles for.
On considère le tri suivant de n nombres rangés dans un tableau t : on commence par trouver le plus
petit élément de t et on le permute avec t[1]. On trouve ensuite le deuxième plus petit élément de t
et on le permute avec t[2]. On continue de cette manière pour les n-1 premiers éléments de A. Écrire
du pseudo code pour cet algorithme, connu sous le nom de tri par sélection.*/
#include <stdio.h>
int imin(int t[], int i,int j){
	int k,m=i;
	for (k=i+1;k<=j;k++)
	if (t[k]<t[m]) m=k;
	return m;
}
void tri_sel(int t[],int n){
	int i,x,y;
	for (i=0;i<n-2;i++){
		x=imin(t,i,n-1);
		if (t[i]>t[x]) {y=t[x]; t[x]=t[i];t[i]=y;}
	}
}
//La deuxième version est écrite en une seule fonction qui utilise deux boucles while.
void tri_sel_1(int t[],int n){
	int i=0,k,m,y;
	while (i<=n-2) {
		k=i+1;
		m=i;
		while (k <=n-1){
			if (t[k]<t[m]) m=k;
			k=k+1;
		}
		if (t[i]>t[m]) {y=t[m]; t[m]=t[i];t[i]=y;}
		i=i+1;
	}
}
//Exemple de programme principal
main(){
int i,t[]={3,2,5,7,9,1,6,8,4};
tri_sel_1(t,9);
for (i=0;i<9;i++) printf(" %d",t[i]); //affichage d’un tableau
printf("\n") ;
}
/*supprimer(i,T,n) supprimant l'élément d'indice i d'un tableau T de n entiers
(en décalant les éléments de T d'indice supérieur à i).*/
void supprimer(int i, int t[], int n) {
	int j;
	for (j=i; j<n­1;j++)
	t[j]=t[j+1];
}
/*placer( x,T, n) insérant l'entier x à sa place dans un tableau T de n entiers
triés dans l'ordre croissant.*/
void placer(int x, int t[],int n) {
	int i,j;
	for (i=0 ; (i < n) && (t[i] < x); i++);
	// Remarquer le ; à la fin de cette boucle !!
	for (j=n ; j>i ; j­­) t[j]=t[j­1];
	t[i]=x;
}
/*detruire( x,T, n) supprimant toutes les occurrences de l'entier x dans un
tableau T de n entiers*/
void detruire(int x, int t[], int n) {
	int i,j;
	for (i=0 ; (i < n) ;i++)
	if (t[i]==x) {
		for (j=i;j<n;j++) t[j]=t[j+1];
		n­­; //on enlève un x et le nbre d’éléments du tableau diminue
		i­­; //on recule i pour le cas où deux x se suivent dans le tableau
	}
}

main(){
	int T1[]={1,2,5,3,9}, T2[]={2,4,6,9,10};
	int i1=0,i2=0,n=5,x,i;
	while ((i1< n) && (i2<n)){
		if (T1[i1]%2==0)
		if (T2[i2]%2==1) {
			x=T1[i1];T1[i1]=T2[i2];T2[i2]=x;
		}
		else i2++;
		else
		i1++;
	}
}
main(){
	int T[]={1,2,5,3,9,2,4,6,9,10};
	int i1=0,n=10,i2=n-1,x,i;
	while ((i1< n) && (i2>i1)){
		if (T[i1]%2==0)
		if (T[i2]%2==1) {
		x=T[i1];T[i1]=T[i2];T[i2]=x;
		}
		else i2--;
		else
		i1++;
	}
}
//Ecrire un algorithme qui retourne le nombre d'éléments différents dans un tableau donné.
int nb_elt_diff(int t[], int n) {
	int i,j,j1; int b[n];
	b[0]=t[0]; j1=0;
	for (i=1;i<n;i++) {
		for (j=0; (j<=j1) && (t[i]!=b[j]) ;j++);
		if (j>j1) { j1++ ; b[j1]= t[i]; }
	}
	return j1+1;
}

/*izero( T) retournant l'indice du début de la plus longue suite de zéros contenue
dans le tableau T de taille n*/
int izero(int t[],int n) {
	int i=0, j=0, max_j=0,max_i;
	while (i<n) 	{
		if (t[i]==0) j++;
		else {
		if (j > max_j) {max_j=j ; max_i=i­j;}
		j=0;
		}
		i++;
			}
	if (j > max_j) {max_j = j ; max_i = i­j;}
	return max_i;
}
/*Un tableau est dit creux s’il contient beaucoup de valeurs nulles et très peu de valeurs non nulles.
exemple : T = {0,0,0 ,0,2,0,0,0,0,0,4,0,0,0,0,0,0,0,0,5,0,0}
Afin d’économiser de l’espace mémoire, on propose de représenter ce genre de tableau par deux
tableaux de petite taille:
IT tableau contenant les indices dans T des valeurs non nulles
VT tableau contenant les valeurs de T correspondantes aux indices contenus dans IT
exemple :
IT={5,11,20} VT={2,4,5}
on pose arbitrairement : n← longueur[T]
a) Ecrire un algorithme qui remplit les tableaux IT et VT à partir d’un tableau creux T en calculant
le nombre d’éléments de IT et VT qu’on appellera m
b) Ecrire un algorithme qui calcule efficacement le produit scalaire de deux tableaux creux A et B.
indications :
A et B sont creux et sont de même taille
A et B n’ont pas le même nombre de valeurs non nulles
A doit être représenté par deux tableaux IA et VA de taille mA
B doit être représenté par deux tableaux IB et VB de taille mB.*/
int creux(int T[],int n,int I[],int V[],int tv){
	int v,i,j;
	v=0;
	for (i=1;((i<=n)&&(v<=tv));i++)
	if (T[i]!=0) {v++;I[v]=i; V[v]=T[i];}
	if (v<=tv)return v;
	else { printf(" taille insuffisante \n"); return 0;}
}
int ps_creux(int IA[],int VA[],int mA,int IB[],int VB[],int mB){
	int i=1,j=1,ps=0;
	while ((i<=mA)&&(j<=mB)){
		if (IA[i]==IB[j])
		{ps = ps + VA[i]*VB[j];i++;j++;}
		else
		if (IA[i] < IB[j]) i++;
		else j++;
	}
	return ps;
}

