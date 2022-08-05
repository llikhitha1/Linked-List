#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
int main()
{
    int n,first,val,first1,val1;
    cin>>n;
    cin>>first;
    struct node *head,*tail;
    head=new node(first);
    tail=head;
    for(int i=0;i<n-1;i++){
        cin>>val;
        tail->next=new node(val);
        tail=tail->next;
    }
    cin>>n;
    cin>>first1;
    struct node *head1,*tail1;
    head1=new node(first1);
    tail1=head1;
    for(int i=0;i<n-1;i++){
        cin>>val1;
        tail1->next=new node(val1);
        tail1=tail1->next;
    }
    struct node *dummy=new node(0);
    struct node *temp=dummy;
    int carry=0;
    while(head!=NULL || head1!=NULL || carry){
        int sum=0;
        if(head!=NULL){
            sum+=head->data;
            head=head->next;
        }
        if(head1!=NULL){
            sum+=head1->data;
            head1=head1->next;
        }
        sum+=carry;
        carry=sum/10;
        struct node *nodee=new node(sum%10);
        temp->next=nodee;
        temp=temp->next;
    }
    struct node *start=dummy->next;
    while(start!=NULL){
        cout<<start->data<<" ";
        start=start->next;
    }
}
