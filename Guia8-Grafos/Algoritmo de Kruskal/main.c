#include <stdio.h>
#include <stdlib.h>
#define N 6

void kruskal(int mat[][N],int mat2[][N]);

int main(){

  int MAdy[N][N]=
  {{0,5,4,0,0,0},
   {5,0,6,2,0,0},  //Creo matriz de adyacencia
   {4,6,0,2,0,0},
   {0,2,2,0,4,3},
   {0,0,0,4,0,1},
   {0,0,0,3,1,0}};

  int MAdy2[N][N];

  kruskal(MAdy,MAdy2);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      printf("%d ",MAdy2[i][j]);
    printf("\n");
  }

  return 0;
}

void kruskal(int mat[N][N],int mat2[N][N])
{
    int i,j,a,b,min=999,cc[N],matLocal[N][N];

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
          matLocal[i][j]=mat[i][j];

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            mat2[i][j]=0;

    for(i=0;i<N;i++)
        cc[i]=i;

    while(!completo(cc)){
        for(i=0;i<N;i++)
            for(j=i+1;j<N;j++)
                if(matLocal[i][j]>0 && cc[i]!=cc[j] && mat[i][j]<min){
                    min=mat[i][j];
                    a=i;
                    b=j;
                }
        mat2[a][b]=min;
        mat2[b][a]=min;
        matLocal[a][b]=0;

        for(i=0;i<N;i++)
            if(cc[i]==cc[a])
                cc[a]=b;
    }
}

int completo(int cc[N])
{
    int i=1,aux=cc[0];
    while(i<N && aux==cc[i])
        i++;
    if(i<N)
        return 0;
    return 1;
}
