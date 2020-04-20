#include<bits/stdc++.h>
using namespace std;
#define I INT_MAX
#define MAX 100

int near[MAX] = {I};
int t[2][MAX];
int Cost[MAX][MAX];

int main()
{


    int vertex_count,data,total_weight = 0;
    cout<<"Enter the number of vertex:- ";
    cin>>vertex_count;


    memset(near, I , sizeof(near));
    /**********INPUT VALUES***********/


    for(int i=1; i <= vertex_count;i++)
        for(int j=1; j <= vertex_count;j++)
        {
            cout<<"If there is edge between "<<i<<" and "<<j<<" Enter it's weight else press 0: ";
            cin>>data;
            if(data!=0)
                Cost[i][j] = data;
            else
                Cost[i][j] = I;

        }

     /**********INITIAL STEP***********/


     int minimum = I,u,v;
        for(int i=1;i<vertex_count+1;i++)
        for(int j=i;j<vertex_count+1;j++)       //here j = i because its values are same as they are repeating so we can consider only upper triangular matrix
        {
            if(Cost[i][j] < minimum)
            {
                minimum = Cost[i][j];
                u = i;
                v = j;
            }
        }

     t[0][0] = u;
     t[1][0] = v;

     total_weight += Cost[u][v];

     near[u] = 0;
     near[v] = 0;

     //Now lets update near array

     for(int i=1; i <= vertex_count ; i++)
     {
        if(near[i] != 0)
        {
            if(Cost[i][u] < Cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
     }

    /**********REPEATING STEP***********/
    int k,j;
    for(int i=1 ; i < vertex_count-1 ;i++)
    {
        minimum = I;
        for(j = 1 ; j <= vertex_count ; j++)
        {
            if((near[j] != 0) and (Cost[j][near[j]] < minimum))
            {
                minimum = Cost[j][near[j]];
                k = j;
            }
        }

        total_weight += Cost[k][near[k]];
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        //update near array

        for(int j = 1 ; j <= vertex_count ; j++)
        {
            if((near[j] != 0) && (Cost[j][k] < Cost[j][near[j]]))
            near[j] = k;
        }
    }

    for(int i = 0; i < vertex_count-1; i++)
        cout<<t[0][i]<<"  "<<t[1][i]<<endl;

    cout<<"\nTotal weight: "<<total_weight<<endl;

return 0;
}
