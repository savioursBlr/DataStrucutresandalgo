
#include<stdio.h>
#include<stdlib.h>
typedef struct Node DLL;
struct Node
{
    int data;
    DLL *next;
    DLL *prev;
}*head = NULL;


int Read_No_Nodes();
void Traverse_DLL(DLL *);
void Insert_End(DLL *, int); 
void Insert_Begin(DLL *, int);
int Read_Element_to_Insert();
int Read_X();
int Search_X(DLL *, int);
void Insert_After_X(DLL *, int, int);
void Delete_Begin(DLL *);
void Delete_Last(DLL *);
void Delete_X(DLL *, int);

int main()
{
    int n, i, j, s, x, p;
    printf("enter no of nodes to be created\n");
    n = Read_No_Nodes(); // Read the number of nodes to be created;
    //Use insert_Last and create a list with n nodes
    printf("enter no");
    for(i=0;i<n;i++)
    {
       s = Read_Element_to_Insert();
       Insert_End(head, s);    
    }
    Traverse_DLL(head);
    
    //Insert an element at begining
    printf("enter no to be inserted at begining\n");
    s = Read_Element_to_Insert();
    Insert_Begin(head, s);
    Traverse_DLL(head);
    
    // Insert an element at end 
     printf("enter no to be inserted at end\n");
    s = Read_Element_to_Insert();
    Insert_End(head, s);
    Traverse_DLL(head);
    
    // Insert an element after x
    printf("enter no after which you want to insert new no\n");
    x = Read_X();
    p = Search_X(head, x);
    if(p == x)
    {
      
      s = Read_Element_to_Insert();
      
      Insert_After_X(head, s, x);
      Traverse_DLL(head);
    }
    else
    printf("\nNo element %d",x);
    // Delete the first node
    Delete_Begin(head);
    printf("after deleting first node\n");
    Traverse_DLL(head);
    
    // Delete the last node
    Delete_Last(head);
    printf("after deleting last node\n");
    Traverse_DLL(head);
    
    // Delete node X
    printf("enter no which you want to delete\n");
    x = Read_X();
    p = Search_X(head, x);
    if(p == x)
    {
       Delete_X(head, x);
       Traverse_DLL(head);
    }
   
    else
      printf("\nNo element %d",x);
return 0;
}

// Read the number of nodes to be created and return
 int Read_No_Nodes()
 {
     
    int x;
    scanf("%d",&x);
    return x;
     
 }
 
 
 // Dsiplay the elements in the list
void Traverse_DLL(DLL *h)
{
   int i;
   DLL *t; 
   if(head==NULL)
     printf("\nList is empty");
   else
   {t=head;
     printf("\nThe elements in list are...\n");
       
       while(t!=NULL)
       {
           printf("%d\n",t->data);
           t = t->next;
       }
      // printf ("%d",t->data);
   }
    
}
// Read an integer element and return
int Read_Element_to_Insert()
{
        int x;
    scanf("%d",&x);
    return x;
}

// Create a new node and insert it at the end of the list
void Insert_End(DLL *h, int s)
{
    DLL *temp;
    
    DLL* new_node=(DLL*)malloc(sizeof(DLL));
    new_node->prev=NULL;

    new_node->data=s;
    new_node->next=NULL;
    if(head==NULL){
      head=new_node;
      return;
    }
   else{
     temp=head;
     while(temp->next!=NULL ){
     temp=temp->next;
   }
   temp->next=new_node;
  new_node->prev=temp;
}}

// Create a new node and insert at the begining of the list
void Insert_Begin(DLL *h, int s)
{
    DLL *temp;
    DLL* new_node=(DLL*)malloc(sizeof(DLL));
    new_node->data=s;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head == NULL){
      head=new_node;
    }
    else{
      head->prev=new_node;
      new_node->next=head;
      head=new_node;
      
    }
   
}

// Read an integer element and return
int Read_X()
{
   int x;
    scanf("%d",&x);
    return x;
    
}

// Create a new node and load s in new node and insertit after a node which contains x
void Insert_After_X(DLL *h, int s, int x)
{
    DLL* new_node=(DLL*)malloc(sizeof(DLL));
  DLL* t;
  t=head;
  new_node->data=s;
  new_node->next=NULL;
  new_node->prev=NULL;
  while(t!=NULL){
    t=t->next;
  if(t->data == x){
 new_node->next=t->next;
  new_node->prev=t;
     t->next->prev=new_node;
    
     t->next=new_node;
     break;
  }}
}

// Delete the first node
void Delete_Begin(DLL *h)
{ DLL *t;
    if(head==NULL)
    return;
   else{
   
     head->next->prev=NULL;
     head=head->next;
   }
    }


// Delete the Last node
void Delete_Last(DLL *h)
{ DLL *t;
    if(h==NULL)
    return;
    
  else{
    t=head;
   while(t->next!=NULL)
     t=t->next;
 t->prev->next=NULL;  
 }
}


// Delete the node whcih contains data element x
void Delete_X(DLL *h, int x)
{
  DLL *t;
  if(h==NULL)
    return;
  t=head;
while(t->next!=NULL&& t->data !=x)
	t=t->next;
	if(t==head)
	{
		head=head->next;
		head->prev=NULL;
		free(t);
	}
	else
	if(t->next==NULL)
	{
		t->prev->next=NULL;
		free(t);
	}
	else
	{
		t->prev->next=t->next;
		t->next->prev=t->prev;
		free(t);
	}
   
  }
  

// Checking x is there in the list or not
// if x is in the list return x otherwise return 0
int Search_X(DLL *h, int x)
{
 
  DLL * cur;
  cur=head;
    while(cur != NULL)
    {
        if(cur ->data==x)
        {
        return x; break;
        }
      else
      cur=cur->next;
        }
        return 0;
   

        }



