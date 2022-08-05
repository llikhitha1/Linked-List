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
int main(){
  int n,first,val;
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
  struct node *nodee=head->next->next;
  nodee->data=nodee->next->data;
  nodee->next=nodee->next->next;
  while(head!=NULL){
      cout<<head->data<<" ";
      head=head->next;
  }
}
