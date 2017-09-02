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


void add(frn** head,int info)
{
    frn *temp, *p;
    temp = new frn;
    temp->next = NULL;
    temp->popu = info;
    if((*head)==NULL)
    {
       (*head) = temp;
    }
    else
    {
        p = (*head);
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }

}

void deletefrn(frn** head,int n,int flag)
{
    frn *p=(*head);
//    while(!flag && p && p->next!=NULL)
//    {
//        if(p->popu < p->next->popu)
//            flag=1;
//        p = p->next;
//    }

    while(n>0 && (*head)!=NULL && (*head)->next!=NULL && (*head)->popu < (*head)->next->popu)
    {
        (*head) = (*head)->next;
        n--;
        flag = 1;
    }
    frn *q = (*head);
    p = (*head)->next  ;
    while(n>0 && q && p && p->next!=NULL)
    {
        if(p->popu < p->next->popu)
        {
            p = p->next;
            q->next = p;
            n--;
            flag = 1;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    if(n>0 && !flag)
    {
        q->next = NULL;
        n--;
    }
    if(n>0)
    {
        deletefrn(head,n,0);
    }

    while(!flag && n>0)
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
    for(int i=0;i<n;i++)
    {
        cin>>k>>m;
        frn *head;
        head = NULL;
        while(k)
        {
            cin>>p;
            add(&head,p);
            k--;
        }
        //cout<<head->popu;
        deletefrn(&head,m,0);
        arr.push_back(head);
    }
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
