#include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define I INT_MAX

int edge[3][MAX];
int s[MAX];
int included[MAX];
int t[2][MAX];

void union1(int u, int v)
{
    if(s[u] < s[v])
    {
        s[u] = s[u] + s[v];
        s[v] = u;
    }
    else
    {
        s[v] = s[u] + s[v];
        s[u] = v;
    }
}

int find(int u)
{
    int x = u;
    while(s[x] > 0)
    {
        x = s[x];
    }
    return x;
}


int main()
{
    memset(s,-1,sizeof(s));
    memset(included,0,sizeof(included));
    int vertex_count, edge_count, total_weight = 0;
    cout<<"Enter the number of vertex: ";
    cin>>vertex_count;
    cout<<"Enter the number of edges: ";
    cin>>edge_count;
    for(int i= 0;i < edge_count;i++)
    {
        cout<<"Enter vertex 1: ";
        cin>>edge[0][i];
        cout<<"Enter vertex 2: ";
        cin>>edge[1][i];
        cout<<"Enter edge weight: ";
        cin>>edge[2][i];
    }

    int i=0,j,k,min,u,v;

    while(i < vertex_count-1)
    {
        min = I;
        for(j = 0; j < edge_count ; j++)
        {
            if((included[j]==0) and (edge[2][j] < min))
            {
                min = edge[2][j];
                k = j;
                u = edge[0][j];
                v = edge[1][j];
            }
        }

        if(find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            total_weight += edge[2][k];
            union1(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }


    for(int i = 0; i < vertex_count-1; i++)
        cout<<t[0][i]<<"  "<<t[1][i]<<endl;

    cout<<"\nTotal weight: "<<total_weight<<endl;

    return 0;
}
