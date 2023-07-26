#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int time;
    int prev;
}Node;

typedef struct Graph
{
    int size;
    Node* node;
    int** matrix;
}Graph;

Graph* CreateGraph(int size)
{
    Graph* g=malloc(sizeof(Graph));
    g->size=size;
    g->node=malloc(sizeof(Node)*(size+1));
    g->matrix=malloc(sizeof(int*)*(size+2));
    for(int i=1;i<=size+1;i++)
    {
        g->matrix[i]=calloc(sizeof(int),(size+1));
    }
    return g;
}

int main()
{
    int n,tmp;
    int* arr=NULL;
    scanf("%d",&n);
    arr=malloc(sizeof(int)*(n+1));

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        while(1)
        {
            scanf("%d",&tmp);
            if(tmp==-1) break;
            arr[i]+=arr[tmp];
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}