#include<stdio.h>
#include<stdlib.h>
typedef struct Node CSLL;
struct Node
{
    int data;
    CSLL *next;
}*head = NULL;


int Read_No_Nodes();
void Traverse_CSLL(CSLL *);
void Insert_End(CSLL *, int); 
void Insert_Begin(CSLL *, int);
int Read_Element_to_Insert();
int Read_X();
int Search_X(CSLL *, int);
void Insert_After_X(CSLL *, int, int);
void Delete_Begin(CSLL *);
void Delete_Last(CSLL *);
void Delete_X(CSLL *, int);

int main()
{
    int n, i, j, s, x, p;
    // Read the number of nodes to be created; 
    printf("enter no of nodes to be created\n");
    n = Read_No_Nodes();
    //Use insert_END and create a list with n nodes
    printf("enter no"); 
    for(i=0;i<n;i++)
    {
       s = Read_Element_to_Insert();
       Insert_End(head, s);    
    }
    //traversing the list
    Traverse_CSLL(head);
    
    //Insert an element at begining
    printf("enter no to be inserted at begining\n");
    s = Read_Element_to_Insert();
    Insert_Begin(head, s);
    Traverse_CSLL(head);
    
    // Insert an element at end 
    printf("enter no to be inserted at end\n");
    s = Read_Element_to_Insert();
    Insert_End(head, s);
    Traverse_CSLL(head);
    
    // Insert an element after
    printf("enter no after wich you want to insert new no\n");
   x = Read_X();
    p = Search_X(head, x);
    if(p == x)
    {
     printf("enter");
      s = Read_Element_to_Insert();
      Insert_After_X(head, s, x);
      Traverse_CSLL(head);
    }
    else
    printf("\nNo element found %d",x);
  // Delete the first node
  
    Delete_Begin(head);
    printf("after deleting first node\n");
    Traverse_CSLL(head);
    
    // Delete the last node
    
   Delete_Last(head);
   printf("after deleting last node\n");
    Traverse_CSLL(head);
    
    // Delete node X
    printf("enter no which you want to delete\n");
    x = Read_X();
    p = Search_X(head, x);
    if(p == x)
    {
       Delete_X(head, x);
       Traverse_CSLL(head);
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
void Traverse_CSLL(CSLL *h)
{
   
   CSLL *t=h; 
   
   if(h==NULL)
     printf("\nList is empty");
   else
   {
       printf("\nThe elements in list are->\n");
       while(t->next!=head)
       {
           printf("%d\n",t->data);
           t = t->next;
       
      } printf("%d\n",t->data);
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
void Insert_End(CSLL *h, int s)
{
    CSLL *temp;
    CSLL* new_node=(CSLL*)malloc(sizeof(CSLL));
    new_node->next=NULL;
    new_node->data=s;
    if(head==NULL){
      head=new_node;
      new_node->next=new_node;
  }
  else{
   h=head;
    while(h->next!=head){
      h=h->next;
    }
    h->next=new_node;
   new_node->next=head;
  }
    
}

// Create a new node and insert at the begining of the list
void Insert_Begin(CSLL *h, int s)
{
    CSLL *temp,*temp1;
    CSLL* new_node=(CSLL*)malloc(sizeof(CSLL));
    new_node->data=s;
    new_node->next=NULL;
    if(head==NULL){
      new_node->next=new_node;
    }
    
    else{
      temp=head;temp1=head;
      new_node->next=head;
      head=new_node;
      while(temp->next!=temp1)
      temp=temp->next;
      
    temp->next=head;}
}

// Read an integer element and return
int Read_X()
{
   int x;
    scanf("%d",&x);
    return x;
    
}

// Create a new node and load s in new node and insertit after a node which contains x
void Insert_After_X(CSLL *h, int s, int x)
{
    CSLL* new_node=(CSLL*)malloc(sizeof(CSLL));
  CSLL *current;
  new_node->data=s;
  new_node->next=NULL;
  current=head;
   do 
    {
    if (current->data == x)
      {new_node->next=current->next;
      current->next=new_node; break;}

        current = current->next;
    
    } while (current != head);

    // Element not found in list
      return ;
  
}
// Delete the first node
void Delete_Begin(CSLL *h)
{ CSLL *t,*t1=head;
    if(head==NULL)
    return;
    else if(head->next==head)
    {
      head=NULL;
      return;
    }
    else
    {
      t=head;
      while(t->next!=head)
      t=t->next;
     
      
     t->next=t1->next;
     head=t->next;
     }
}


// Delete the Last node
void Delete_Last(CSLL *h)
{ CSLL *t=head,*t1=head;
    if(h==NULL)
    return;
   else if(h->next==NULL){
      head=NULL;
      return;
  }
   while(t->next!=head){
     t1=t;
     t=t->next;
   }
   t1->next=t->next;
   head=t1->next;
    
    
}


// Delete the node whcih contains data elelment x
void Delete_X(CSLL *h, int x)
{ 
  CSLL *t,*t1;
  if(h==NULL)
    return;
    t=head;
    t1=head;
  
  while(t->next!=head&& t->data !=x){
    t1=t;
   t=t->next;
   
  }
  	if(t->next==head)
	{
		  t1->next=t->next;
     head=t1->next;
		
	
	}
	else if(t==head)
	{  
      while(t->next!=head)
      t=t->next;
		 t->next=t1->next;
     head=t->next;
     
	}
	else {
		 t1->next=t->next;
	
	}
  
}

// Checking if x is there in the list or not

// if x is in the list return x otherwise return 0

int Search_X(CSLL *h, int x)
{
    CSLL *cur=head;
   do 
    {
    if (cur->data == x)
      {return x; break;}

        cur = cur->next;
    
    } while (cur != head);

    // Element not found in list
    return -1;
}



