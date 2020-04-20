#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int A[MAX][MAX], visitedB[MAX] = {0},visitedD[MAX] = {0};

void BFS(int root,int limit)
{
    int u;
    cout<<root<<" ";
    visitedB[root] = 1;
    queue <int> q1;
    q1.push(root);
    while(!q1.empty())
    {
        u = q1.front();
        q1.pop();
        for(int i=1;i<limit;i++)
        {
            if((A[u][i] == 1) and (visitedB[i] == 0))
            {
                cout<<i<<" ";
                visitedB[i] = 1;
                q1.push(i);
            }
        }
    }
}

void DFS(int root,int limit)
{
    if(visitedD[root]==0)
    {
        cout<<root<<" ";
        visitedD[root] = 1;
        for(int i=0;i<limit;i++)
        {
            if((A[root][i]==1) and (visitedD[i]==0))
                DFS(i,limit);
        }
    }
}

int main()
{


    for(int i=0;i<MAX;i++)
    {
        A[0][i]= 0;
        A[i][0]= 0;
    }
    int vertex_count;
    cout<<"Enter the number of vertex:- ";
    cin>>vertex_count;

    for(int i=1;i<vertex_count+1;i++)
        for(int j=1;j<vertex_count+1;j++)
        {
            cout<<"If there is edge between "<<i<<" and "<<j<<" Press 1 else 0: ";
            cin>>A[i][j];
        }

    cout<<"\nBFS: ";
    BFS(1,vertex_count+1);

    cout<<"\nDFS: ";
    DFS(1,vertex_count+1);
}
