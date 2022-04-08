//Ecrire un algorithme efficace qui calcule la puissance d’un entier.
//algorithme classique :
double puissance(double x,int n) {
	int i ;
	double p=x ;
	for(i=2 ; i<=n ; i++)
	p=p*x ;
	return p ;
}
//ici on effectue n-1 multiplications.
//Algorithme efficace :
double puissance(double x,int n) {
	double p,t ;
	for(p=1,t=x ; n>0 ; n/=2) {
		if (n%2==1) p *= t ;
		t *= t ;
		printf("%f %f %d\n",p,t,n);
	}
	return p ;
}
/*Ecrire un algorithme qui prend en paramètre un entier et qui retourne le nombre de bits valant 1
dans l'écriture de cet entier.*/
//version itérative :
int nbre_bits_1(int n){
	int i=0;
	while (n >0) {i+=(n%2); n/=2;}
	return i;
}
//version récursive :
int nbre_bits_r(int n){
	if (n==0) return 0;
	return (n%2)+nbre_bits_r(n/2);
}
//Ecrire une algorithme récursif qui calcule la somme des chiffres (en base décimale) de l'entier n.
//version récursive :
int sommeChiffres_r(int n){
	if (n==0) return 0;
	return (n%10) + sommeChiffres_r(n/10);
			}
//version itérative :
int sommeChiffres(int n){
	int i=0;
	while (n >0) {i+=(n%10); n/=10;}
	return i;
}
//Ecrire un algorithme calculant la somme des diviseurs d'un entier.
int sommeDiviseurs(int n){
	int i;
	int somme=n+1;
	for (i=2; i<=(n/i); i++)
	if (n%i == 0)
	if (i!= (n/i)) somme +=i+(n/i);
	else somme+=i;
	return somme;
}
/*ici la boucle s’arrête à (n/i). En effet, si i divise n alors n/i divise n.
si i et n/i sont égaux, on joute seulement l’un des deux.*/
/*Ecrire un algorithme décomposition() qui prend un entier en paramètre et qui affiche la
décomposition*/
void decompose(int n) {
	int d;
	while (n%2 ==0) {printf("%d x ",2); n=n/2;}
	for (d=3;d*d<=n;)
	if (n%d==0) {printf("%d x ",d);n=n/d;}
	else d=d+2;
	if (n>=1) printf("%d \n",n);
}
/*la boucle while imprime des multiplications par 2 (premier facteur premier)
tant que n est pair.
La boucle for démarre avec d=3 et cherche les facteurs premiers impairs en
progressant avec d=d+2 . Elle s’arrête lorsqu’elle atteint la racine carrée
de n.*/
//triangle de Pascal
//version récursive du calcul de la factorielle
double factr(int n){
	if (n==2) return 2;
	return n*factr(n-1);
}
//version itérative du calcul de la factorielle
double facti(int n){
	double p=n;
	int i;
	for (i=n-1; i>1; i--)
	p=p*i;
	return p;
}
/*pour calculer les coefficients binomiaux on
peut utiliser :
c(n,p)=c(n-1,p)+c(n-1,p-1) avec 0<p<n
on peut programmer cela d’une manière récursive :*/
double binomial(int n, int p){
	if (p==0 || p==n) return 1.;
	return binomial(n-1,p) + binomial(n-1,p-1);
}
/*c’est une mauvaise façon de faire par on répète inutilement les mêmes
calculs plusieurs fois. (voir aussi la version récursive de la fonction
fibonacci en page 14 du cours)
on peut aussi utiliser la formule suivante pour calculer
binomiaux :
les coefficients
c(n,p)=n!/(p!*(n-p)!)*/
double binomial1(int n, int p){
	return factr(n)/(factr(p)*factr(n-p));
}
/*cette façon de faire n’est pas efficace non plus. Voir ci dessus les
problèmes posés par le calcul de la factorielle.
Ajouter à cela les calculs redondants de 1*2*3 …
on peur simplifier comme suit :
c(n,p)= 1*2*...n / ((1*2*...p)*(1*2*...n-p)) =
1*2*… p*p+1* ...n/ ((1*2*...p)*(1*2*...n-p)) = p+1*...n/(1*2*...n-p)
et programmer cette expression itérativement :*/
double binomial2(int n, int p){
	int i;
	double a=1,b=1;
	for(i=p+1; i<=n;i++)
	a=a*i;
	for(i=2; i<=n-p;i++)
	b=b*i;
	return a/b;
}
/*on calcule d’abord le numérateur et ensuite le dénominateur. Or, les
multiplications successives font grandir rapidement ces deux valeurs
conduisant au risque de dépassement de capacité !Il serait plus judicieux d’effectuer la division de chaque terme avant la
multiplication afin d’éviter le dépassement de capacité :
on réécrit l’expression de la façon suivante :
c(n,p)= (p+i)/i pour i allant de 1 à n-p.*/
double binomial3(int n, int p){
	int i;
	double a=1,b=1;
	for(i=1; i<=n-p;i++)
	a*=(p+i)/(double)i;
	return a;
}
/*Remarquer la conversion explicite au type double de la division.
Pour finir voici un exemple de programme principal, à vous d’écrire le
votre ! Bon courage.*/
main(){
printf("%lf ** %d = %lf\n",2.,40,puissance(2,40));
printf("%d\n",nbre_bits_1(1023));
printf("%d\n",nbre_bits_r(1023));
printf("r %d! =%g\n", 170,factr(170));
printf("i %d! =%g\n", 170,facti(170));
printf("b3 %d p %d %g\n",10,5,binomial3(36,18));
printf("b2 %d p %d %g\n",10,5,binomial2(36,18));
printf("b1 %d p %d %g\n",10,5,binomial1(36,18));
printf("b %d p %d %g\n",10,5,binomial(36,18));
decompose(110);
}
