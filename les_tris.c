#include <stdio.h>
#include <stdlib.h>

//--------------------TRI insertion-------------------------------------------
void tri_Insertion(int a[],int n)
{
	int i,j,cle;
	for(j=1; j<n ; j++)
	{
		cle=a[j];
		i=j-1;
			while ((i>=0) && (a[i]>cle))
			{
				a[i+1]=a[i];
				i=i-1;
				//printf(" %d %d %d\n",i,j,cle);
			}
		a[i+1]=cle;
	}
}
//--------------------TRI FUSION-------------------------------------------

void fusion(int a[],int p,int q,int r)
	{
	int i,j,k;
	printf("fusion p=%d q=%d r=%d\n",p,q,r);
	int n1=q-p+1;
	int n2=r-q;
	int *L=(int *) malloc(n1+1 * sizeof(int));
	int *R=(int *) malloc(n2+1 * sizeof(int));
	for(i=0; i<n1 ; i++) L[i] = a[p+i];
		for(j=0; j<n2 ; j++) R[j] = a[q+j+1];
	/*
	L[n1]=42767;
	R[n2]=42767;
	i=j=0;
	for (k=p; k<=r; k++)
	if (L[i]<=R[j])
	a[k]=L[i++];
	else a[k]=R[j++];*/
	i=j=0;
			for (i=0, j=0, k=p; (i<n1 && j< n2 && k<=r); k++)
	if (L[i]<=R[j])
	a[k]=L[i++];
	else a[k]=R[j++];
	if ((i == n1)&&(k<=r))
		while ((j<n2)&&(k<=r)) a[k++]=R[j++];
	if ((j==n2)&&(k<=r))
			while ((i<n1)&&(k<=r)) a[k++]=L[i++];
	}
void triFusion(int a[],int p,int r)
	{
	int q;
	printf(" t(%d,%d)\n",p,r);
	if (p<r) {
	q=(p+r)/2;
	triFusion(a,p,q);
	triFusion(a,q+1,r);
	fusion(a,p,q,r);
	}
}
//------------------------TRI RAPIDE-------------------------------------
int partition(int a[], int p,int r){
int x=a[r],y;
int j,i=p-1;
for (j=p; j <= r-1; j++)
	if (a[j] <= x) {
		i++;
		y=a[i]; a[i]=a[j]; a[j]=y;
	}
	y=a[i+1];a[i+1]=a[r]; a[r]=y;
return i+1;
}
void triRapide(int a[], int p,int r)
	{
	int q;
	if (p<r){
		q=partition(a,p,r);
		triRapide(a,p,q-1);
		triRapide(a,q+1,r);
		}
	}
//-----------------------------TRI PAR TAS---------------------------------
int gauche(int i){ return 2*i;}
int droit(int i){ return 2*i+1;}
int pere(int i){ return i/2;}
void entasserMax(int a[], int i,int n)
	{
	int x,max;
	int l=gauche(i);
	int r=droit(i);
	if ((l <= n) && (a[l]>a[i]))
	max=l;
	else max=i;
	if ((r <= n) && (a[r]>a[max]))
	max=r;
	if (max != i) 
		{
		x=a[i]; a[i]=a[max]; a[max]=x;
		entasserMax(a,max,n);
		}
}
void contruireTasMax(int a[], int n)
{
		int i;
		for (i=n/2; i>=1;i--)
			entasserMax(a,i,n);
			printf("affichage du tas\n");
		for(i=1;i<=9;i++) printf(" %d",a[i]); printf("\n");
}
void triTasMax(int a[], int n)
{
	int i,x;
	contruireTasMax( a, n);
	for (i=n; i>=2;i--)
	{
		x=a[1]; a[1]=a[i]; a[i]=x;
		n--;
		entasserMax(a,1,n);
	}
}
//-----------------------TRI PAR DENOMBREMENT------------------------------

void tri_denombrement(int a[],int b[],int n,int c[],int k)
{
	int i,j;
	for(i=0; i<=k ; i++) c[i]=0;
	for(j=1; j<=n ; j++) c[a[j]]=c[a[j]]+1;
	for(i=0; i<=k ; i++) printf("c[%d]=%d\n",i,c[i]);
	for(i=1; i<=k ; i++) c[i]=c[i]+c[i-1];
	for(i=0; i<=k ; i++) printf("c[%d]=%d\n",i,c[i]);
	for (j=n; j>0;j--)
	{
		printf("b[%d]=%d\n",c[a[j]],a[j]);
		b[c[a[j]]]=a[j];
		c[a[j]]=c[a[j]]-1; 
	}
}


