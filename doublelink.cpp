#include<iostream>
#include<stdlib.h>
using namespace std;
struct DoubleNode{
 int data;
 struct DoubleNode *next;
 struct DoubleNode *previous;
}*head;
void insertNode(int n){
   struct DoubleNode *newnode;
   struct DoubleNode *temp;
   int data,i;
   if(n<0)
   {
       cout<<"N value must be greater than 0"<<endl;
   }
   else{
    head=(struct DoubleNode*)malloc(sizeof(DoubleNode));
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else{
        cout<<"Enter the data of 1st node"<<endl;
        cin>>data;
        head->data=data;
        head->previous=NULL;
        head->next=NULL;
        temp=head;
        for(int i=2;i<=n;i++)
        {
            newnode=(struct DoubleNode*)malloc(sizeof(DoubleNode));
            cout<<"Enter the data of" <<i <<"node:"<<" ";
            cin>>data;
            newnode->data=data;
            newnode->next=NULL;
            temp->next=newnode;
            newnode->previous=temp;
            temp=newnode;

        }
    }
   }
}
void insertAtBeginning(DoubleNode **head){
    struct DoubleNode *newnode;
    int data;

    newnode=(struct DoubleNode*)malloc(sizeof(struct DoubleNode));
    cout<<"Enter the data to the beginning node"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->previous=NULL;
    newnode->next=(*head);
    (*head)->previous=newnode;
    *head=newnode;

}
void insertAtMiddle(DoubleNode **head)
{  struct DoubleNode *newnode;
    struct DoubleNode *p=*head;
    struct DoubleNode *q;
    int data,pos;
    int k=1;
    cout<<"enter the position:"<<" ";
    cin>>pos;
    while(p!=NULL && k<pos){
        k++;
        q=p;
        p=p->next;
    }
    newnode=(struct DoubleNode*)malloc(sizeof(struct DoubleNode));
    cout<<"Enter the data to the middle node"<<endl;
    cin>>data;
    newnode->data=data;
    newnode->next=p;
    newnode->previous=q;
    q->next=newnode;
    p->previous=newnode;



}
void insertAtLast(DoubleNode **head)
{
    struct DoubleNode *newnode;
    struct DoubleNode *p=*head;
    int data;
      while(p->next!=NULL)
    {
        p=p->next;
    }
    newnode=(struct DoubleNode*)malloc(sizeof(struct DoubleNode));
     cout<<"Enter the data to be inserted at the end of the list"<<endl;
    cin>>data;
     newnode->data=data;
     newnode->next=NULL;
     newnode->previous=p;
     p->next=newnode;


}

void displayDDL()
{
    struct DoubleNode *temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<"->";
        temp1=temp1->next;
    }
    cout<<"NULL"<<endl;
}
void deleteAtFront(DoubleNode **head)
{
    DoubleNode *temp;
    temp=*head;
   temp->next->previous=NULL;
   *head=temp->next;
   free(temp);
}
void deleteAtMiddle(DoubleNode **head){
  DoubleNode *p,*q;
  p=*head;
  int k=1;
  int pos;
  cout<<"Enter position"<<endl;
  cin>>pos;

  while(p->next!=NULL && k<pos)
  {
      k++;
      q=p;
      p=p->next;
  }
  q->next=p->next;
  p->next->previous=q;
  free(p);
}
void deleteAtLast(DoubleNode **head)
{
    DoubleNode *temp;
    temp=*head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
int main()
{

    int n,ch;
    cout<<"Enter the value of n"<<endl;
    cin>>n;
    insertNode(n);
    cout<<"1.insert at beginning"<<endl;
    cout<<"2.insert at middle"<<endl;
    cout<<"3.insert at end"<<endl;
    cout<<"4.delete at beginning"<<endl;
    cout<<"5.delete at middle"<<endl;
    cout<<"6.delete at end"<<endl;
    cout<<"7.display"<<endl;
    while(1){
    cout<<"Enter choice"<<endl;
    cin>>ch;
    switch(ch){
        case 1 : insertAtBeginning(&head);
                break;
        case 2 : insertAtMiddle(&head);
                 break;
        case 3 : insertAtLast(&head);
                break;
        case 4:  deleteAtFront(&head);
                 break;
        case 5: deleteAtMiddle(&head);
                break;
        case 6: deleteAtLast(&head);
                break;
        case 7: displayDDL();
                 break;
        default:
            cout<<"Invalid choice"<<endl;
    }

}
}

