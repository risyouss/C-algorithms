#define N 10
typedef int permutation[N];
int saisir(permutation a)
	{
	int i;
	for (i=1;i<N;i++) 
	{
		printf("donner a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	}
int afficher(permutation a)
	{
	int i;
	for (i=1;i<N;i++)
		printf(" %d",i);
		printf("\n");
	for (i=1;i<N;i++)
		printf(" %d",a[i]);
		printf("\n");
	}
int produit(permutation alpha,permutation beta,permutation gamma)
	{
	int i,j;
	for (i=1;i<N;i++) 
		{
			j=beta[i];
			gamma[i]=alpha[j];
		}
	}
int inverse(permutation a,permutation amoins1)
	{
	int i;
	for (i=1;i<N;i++)
	amoins1[a[i]]=i;
	}
int verifier(permutation a)
	{
	int i,x ;
	short marque[N];
	for(i=1;i<N;i++) marque[i]=0;
	for(i=1;i<N;i++) 
		{
			x=a[i];
			if ((x<1)||(x>N)) return 0;
			if (marque[x]==1) return 0;
			marque [x]=1;
		}
	return 1;
	}
int longueur(permutation alpha, int x)
	{
	int y=alpha[x],l=1;
	while (y!=x) { y=alpha[y]; l++;}
	return l;
	}
void marquage(permutation alpha,int x,int m[])
	{
	int i,y;
	for(i=1;i<N;i++) m[i]=0;
	m[x]=1; y=alpha[x];
	while (y!=x) { m[y]=1;y=alpha[y];}
	}
void structure(permutation alpha,int struc[])
	{
	int y,i,marq[N],l;
	for (i=1;i<N;i++) { marq[i]=0; struc[i]=0;}
	for (i=1;i<N;i++) {
		if (marq[i]==0) { marq[i]=1; y=alpha[i]; l=1;
		while (y!=i) { marq[y]=1; y=alpha[y];l++;}
		struc[l]=struc[l]+1;
		}//fin if
		}
	}
void saisie_cycles(permutation alpha){
	int debut_cycle,x,y;
	printf("donner un element:"); scanf("%d",&debut_cycle);
	while (debut_cycle!=0) 
		{
		x=debut_cycle;
		printf("donner un element:"); scanf("%d",&y);
		while (y!=0) {
		alpha[x]=y;
		x=y;
		printf("donner un element:"); scanf("%d",&y);
		}
		alpha[x]=debut_cycle;
		printf("donner un element:");
		scanf("%d",&debut_cycle);
		}
				}
void afficher_cycles(permutation a){
	int x,y,i,m[N];
	for(i=1;i<N;i++) m[i]=0;
	for(i=1;i<N;i++) {
		if (m[i]==0) {printf("(%d ",i);m[i]=1;
		x=i;y=a[i];
		while(y!=x) 
			{
			m[y]=1;
			printf("%d ",y);
			y=a[y];
			}
		printf(") ");
		}
			}
	printf("\n");
}
int appartient(permutation alpha,int a,int b) 
	{
	int x,y;
	x=a;
	y=alpha[x];
	while ((x!=y) && (x!=b)) {x=y;y=alpha[y];}
	if (x==y) return 0;
	return 1;
	}
