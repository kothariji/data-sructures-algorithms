#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int heap[MAX];

    void heapify(int len, int start_index)
    {
        int i = start_index;
        int lc = 2*start_index;
        int rc = 2*start_index+1;
        int temp;


        /******checking for left child******/


        if (lc < len and heap[i] < heap[lc])
        {
            i = lc;
            swap(heap[i],heap[start_index]);
        }

        /******checking for right child******/

        if (rc < len and heap[i] < heap[rc])
        {
            i = rc;
            swap(heap[i],heap[start_index]);
        }


        /******recursively calling heapify for the parent subtree******/

        if(i != start_index)
            heapify(len,i);
    }

    /******Display of MAX heap******/

    void display(int len)
    {
        cout<<"\n========================================\n";
        cout<<"HEAP: ";
        for(int i=1; i <= len; i++)
            cout<<heap[i]<<" ";
        cout<<"\n========================================";
    }


int main()
{
    int len,data,ind=0;
    cout<<"Enter the number of elements to be entered in Heap: ";
    cin>>len;
    heap[ind] = 0;

    /******Inserting values******/

    for(int ind=1;ind<=len;ind++)
    {
        cout<<"Enter "<<ind<<" element: ";
        cin>>heap[ind];
    }

    /******getting of index of first non leaf root******/
    int start_index = (len/2);

    /******heapify all elements******/
    for(int i= start_index; i>=1; i--)
    {
        heapify(len,i);
    }
    /******display heap******/
    display(len);
}
