main(){
//mots
char *s=LireChaine();//" cbcbcbcbcbcbcbcbcbcb";
char *g=LireChaine();//" cb";
int ls,lg,lf;
ls =(int)len(( char *)s); lg=(int)len(( char *)g);
char *f=(char *)malloc( (ls+lg+1) *sizeof(char));
lf=len(( char *)f);
int *phi=(int *)malloc( lf*sizeof(int));
int i,j,l=lg;
for (i=1; g[i]!='\0';i++) f[i]=g[i];
for (i=1,j=l;s[i]!='\0';i++,j++) f[j]=s[i];f[j]='\0';
//
knuth_motifs(f,phi,l-1);
for (i=1;s[i]!='\0';i++) printf("%3d",i); printf("\n");
for (i=1;s[i]!='\0';i++) printf("%3c",s[i]); printf("\n");
for (i=1;s[i]!='\0';i++) printf("%3d",phi[i]); printf("\n");
}
