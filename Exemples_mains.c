#include<les_tris.c>
#include <stdio.h>
#include <stdlib.h>


main(){
int a[]={5,2,4,6,1,3},i;
for(i=0;i<6;i++) printf(" %d",a[i]); printf("\n");
tri_Insertion(a,6);
for(i=0;i<6;i++) printf(" %d",a[i]); printf("\n");
}
main(){
int a[]={5,1,8,6,3,4,19,9},i;
for(i=0;i<=7;i++) printf(" %d",a[i]); printf("\n");
triFusion(a,0,7);
for(i=0;i<=7;i++) printf("A[%d]= %d\n",i,a[i]); printf("\n");
}
main(){//rapide
int a[]={-1,5,13,25,25,7,17,20,8,4};
int i;
for(i=1;i<=9;i++) printf(" %d",a[i]); printf("\n");
triRapide(a,1,9);
for(i=1;i<=9;i++) printf(" %d",a[i]); printf("\n");
}
main(){//tris tas
int a[]={-1,5,13,2,25,7,17,20,8,4};
int i;
for(i=1;i<=9;i++) printf(" %d",a[i]); printf("\n");
triTasMax(a,9);
for(i=1;i<=9;i++) printf(" %d",a[i]); printf("\n");
}
main(){//DENOMBREMENT
int a[]={-1,5,5,4,6,1,3},i;
int c[7],b[7];
for(i=0;i<7;i++) printf(" %d",a[i]); printf("\n");
tri_denombrement(a,b,6,c,6);
for(i=0;i<7;i++) printf(" %d",b[i]); printf("\n");
}
