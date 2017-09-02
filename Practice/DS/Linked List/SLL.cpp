#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

struct frn{
    int popu;
    struct frn *next;
};

void deletefrn(frn** head,int n)
{
    frn *r=(*head), *p = r->next, *q = p->next, *prev, *rm;
    while(n && r)
    {
        if(!q)
        {
            if(r->popu < p->popu)
            {
                p = p->next;
                if(r == (*head))
                {
                    rm = (*head);
                    (*head) = (*head)->next;
                    free(rm);
                }
                else
                {
                    rm = r;
                    prev->next = r->next;
                    free(rm);
                }
                r = r->next;
                n--;
            }
            break;
        }
        if(r->popu < p->popu)
        {
            p = p->next;
            q = q->next;
            if(r == (*head))
            {
                rm = (*head);
                (*head) = (*head)->next;
                free(rm);
            }
            prev = r;
            r = r->next;
            n--;
        }
        else if(p->popu < q->popu)
        {
            r->next = q;
            free(p);
            p = q;
            q = q->next;
            n--;
        }
        else
        {
            prev = r;
            r = r->next;
            p = p->next;
            q = q->next;
        }
    }

    while(n>0)
    {
        p=(*head);
        frn *prev;
        while(p->next!=NULL)
        {
            prev = p;
            p=p->next;
        }
        prev->next = NULL;
        n--;
    }
}


int main()
{
    int n,m,k,p;
    cin>>n;
    vector<frn* > arr;
    vector<int > arr1;
    for(int i=0;i<n;i++)
    {
        cin>>k>>m;
        frn *head, *en;
        head = NULL;
        while(k)
        {
            cin>>p;
            frn *temp;
            temp = new frn;
            temp->next = NULL;
            temp->popu = p;
            if(head==NULL)
            {
               head = temp;
               en = head;
            }
            else
            {
                en->next = temp;
                en = en->next;
            }
            k--;
        }
        arr.push_back(head);
        arr1.push_back(m);
    }
    cout<<"done1";
    for(int i=0;i<n;i++)
    {
        deletefrn(&arr[i],arr1[i]);
    }
    cout<<"done2";
    for(int i=0;i<n;i++)
    {
        frn* hd = arr[i];
        while(hd!=NULL)
        {
            cout<<hd->popu<<" ";
            hd = hd->next;
        }
        cout<<endl;
    }
    return 0;
}

