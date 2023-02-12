#include <stdio.h>
#include <limits.h>
/*Écrire deux fonctions min et max qui prennent en argument un tableau d'entiers T et qui
retourne respectivement le minimum et le maximum du tableau.*/
int min(int t[], int n){
	int i,min;
	for (i=2,min=t[1];i<n;i++)
	if (min > t[i]) min=t[i];
	return min;
	}
int max(int t[], int n){
	int i,max;
	for (i=2,max=t[1];i<n;i++)
	if (max < t[i]) max=t[i];
	return max;
	}
/*Écrire une fonction contientUnique qui prend en argument un tableau d'entiers T et un
entier x, et qui retourne 1 si T contient x une unique fois, et qui retourne 0 sinon.*/
int contientUnique(int t[],int n,int x){
	int i=1,c=0;
	while (i< n) {
		if (t[i] == x)
		if (c==0) c=1;
		else return 0;
		i++;
	}
	if (c==1) return 1;
	return 0;
	} // tester 0, 1 et 2 fois
/*Écrire une fonction verifieIntervalle qui prend en argument un tableau d'entiers T et deux
entiers a et b (avec a <= b). Elle doit retourner 1 si T contient chaque entier entre a et b (a et
b compris) une seule fois, et 0 sinon.
Cette fonction utilisera contientUnique.*/
int verifieIntervalle(int t[], int n, int a, int b){
	int i;
	if (b < a) {
		printf(" [%d %d] n'est pas un intervalle\n",a,b);
		return 0;
	}
	for (i=1;i<n;i++)
	if ((t[i] < a) || (t[i] > b) || (!contientUnique(t,n,t[i])))
	return 0;
	return 1;
}
/*Écrire une fonction verifieIntervalle2 qui prend en argument un tableau d'entiers T et
retourne 1 si T correspond à un intervalle et 0 sinon. Cette fonction utilisera verifieIntervalle, min
et max.*/
int verifieIntervalle2(int t[], int n){
	int i;
	return verifieIntervalle(t,n,min(t,n),max(t,n));
}
/*Écrire une fonction inf qui prend en argument deux mots et qui retourne -1 si le premier
mot est avant le second dans l'ordre alphabétique , 0 si les deux mots sont les mêmes, et +1 sinon.*/
int inf(char m1[],char m2[]){
	int i=0;
	while ((m1[i] != '\0') && (m2[i] != '\0')){
		if (m1[i] < m2[i]) return -1;
		if (m1[i] > m2[i]) return 1;
		i++;
	}
	if (m1[i] != '\0') return 1;
	if (m2[i] != '\0') return -1;
	return 0;
}
/*Écrire une fonction minMot (utilisant inf) qui prend en argument un tableau de mots et qui
retourne le plus petit mot pour l'ordre alphabétique.*/
char *minm(char *tabMots[4],int n){
	int cm=0;
	for (int i=1; i<n;i++)
	if (inf(tabMots[cm],tabMots[i])== 1) cm=i;
	return tabMots[cm];
}
/*Écrire une fonction compteInf qui prend en argument un tableau d'entiers T et un entier
x, et qui retourne le nombre d'éléments de T qui sont < x.*/
int compteInf(int t[], int n,int x){
	int i,c=0;
	for (i=0;i<n;i++)
	if (x > t[i]) c++;
	return c;
}
/*Écrire un algorithme (utilisant cette fonction) qui trouve la médiane d'un tableau T à n
éléments distincts avec n impair.*/
int mediane(int t[], int n){
	int i,x=(n)/2;
	for (i=0;i<n;i++)
	if (compteInf(t,n,t[i])== x) return i;
}
/*pour chaque valeur de l’indice i de la boucle for dans la fonction
mediane(), on parcoure l’ensemble du tableau t dans la fonction
compteInf().
Donc la complexité a une croissance quadratique*/
//recherche le second minimun dans un tableau par la méthode itérative.
int min2(int l[],int p,int r){
	int i,smin=l[p],x,min =l[p+1];
	if (l[p] < l[p+1]) {smin=l[p+1];min=l[p];}
	for (i=p+2;i<=r;i++)
	if (min > l[i]) {smin = min;min =l[i];}
	else if (smin >l[i]) smin=l[i];
	return smin;
}
/*recherche le second minimun dans un tableau par la méthode récursive*/
int s=INT_MAX;
int compare(int l[],int p,int r){
	int q,minl,minr;
	printf("---%d--%d---\n",p,r);
	if (p==(r-1)){
		if (l[p] <= l[r]){
		if (s>=l[r]) s=l[r];return l[p];}
		else {if (s>=l[p]) s=l[p];return l[r];}}
	else
	if (p<r-1) {
		q=(p+r)/2;
		minl=compare(l,p,q);
		minr=compare(l,q+1,r);
		if ( minl <= minr){
			if (s>=minr) s=minr;
			return minl;}
		if (s>=minl)s=minl; return minr;}
	return l[p];
	printf("---%d--%d---\n",p,r);
}
/*Ecrire un algorithme efficace de recherche simultanée du minimum et du maximum d’un tableau
d’entiers T de taille N.
la complexité de votre algorithme ne doit pas dépasser 3(N/2) comparaisons.*/
void min_max(int L[],int p,int r,int *min, int *max){
	int i,d,minp,maxp;
	int n=p-r+1;
	if (n%2) {*min=*max=L[p]; d=p+1;}
	else {*min =L[p]; *max=L[p+1];d=p+2;}
	for (i=d;i<=r;i+=2){
		if (L[i+1] > L[i]){ minp = L[i]; maxp=L[i+1];}
		else
			{ maxp = L[i]; minp=L[i+1];}
		if (minp < *min) *min=minp;
		if (maxp > *max) *max=maxp;
	}
}
//Exemple de programme principal :
int main(){
int t[]={12,31,-15,11,11,6,19,12,15,99,1};
int i,min,max;
char* tabMots[]={"aaaa","ebbb","aaaaa","dddd"};
for (i=0;i<=10;i++) printf(" %d",t[i]);printf("\n\n");
printf("contientUnique %d \n",contientUnique(t,11,14));
printf("minmot=%s\n",minm(tabMots, 4));
printf("result %d \n",compare(t,0,10));
printf("s= %d\n",s);
printf("min2 %d \n",min2(t,0,10));
for (i=0;i<=10;i++) printf(" %d",t[i]);printf("\n\n");
min_max(t,0,10,&min,&max);
printf("min= %d\n",min);
printf("max= %d\n",max);
}
