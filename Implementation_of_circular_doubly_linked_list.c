
#include<stdio.h>
#include<stdlib.h>
typedef struct Node CDLL;
struct Node
{
    int data;
    CDLL *next;
    CDLL *prev;
}*head = NULL;


int Read_No_Nodes();
void Traverse_CDLL(CDLL *);
void Insert_End(CDLL *, int); 
void Insert_Begin(CDLL *, int);
int Read_Element_to_Insert();
int Read_X();
int Search_X(CDLL *, int);
void Insert_After_X(CDLL *, int, int);
void Delete_Begin(CDLL *);
void Delete_Last(CDLL *);
void Delete_X(CDLL *, int);

int main()
{
    int n, i, j, s, x, p;
    printf("enter no of nodes to be created\n");
    // Read the number of nodes to be created;
    n = Read_No_Nodes(); 
    //Use insert_Last and create a list with n nodes
      printf("enter no");
    for(i=0;i<n;i++)
    {
       s = Read_Element_to_Insert();
       Insert_End(head, s);    
    }
    Traverse_CDLL(head);
    
    //Insert an element at begining
    printf("enter no to be inserted at begining\n");
    s = Read_Element_to_Insert();
    Insert_Begin(head, s);
    Traverse_CDLL(head);
    
    // Insert an element at end
	 printf("enter no to be inserted at end\n"); 
    s = Read_Element_to_Insert();
    Insert_End(head, s);
    Traverse_CDLL(head);
    
    // Insert an element after x
    printf("enter no after which you want to insert new no\n");
   x = Read_X();
    p = Search_X(head, x);
    if(p == x)
    {
     
      s = Read_Element_to_Insert();
      Insert_After_X(head, s, x);
      Traverse_CDLL(head);
    }
    else
    printf("\nNo element %d",x);
  // Delete the first node
    Delete_Begin(head);
    printf("after deleting first node\n");
    Traverse_CDLL(head);
    
    // Delete the last node
   Delete_Last(head);
   printf("after deleting last node\n");
    Traverse_CDLL(head);
    
    // Delete node X
     printf("enter no which you want to delete\n");
    x = Read_X();
    p = Search_X(head, x);
    if(p == x)
    {
       Delete_X(head, x);
       Traverse_CDLL(head);
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
void Traverse_CDLL(CDLL *h)
{
   
   CDLL *t=head; 
   if(head==NULL)
     printf("\nList is empty");
   else
   {
       printf("\nThe elements in list are...\n");
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
void Insert_End(CDLL *h, int s)
{
    CDLL *temp;
    CDLL* new_node=(CDLL*)malloc(sizeof(CDLL));
    new_node->next=NULL;
    new_node->prev=NULL;
    new_node->data=s;
    if(head==NULL){
      head=new_node;
      new_node->next=new_node;
      new_node->prev=new_node;
  }
  else{
  
   new_node->next=head; 
   new_node->prev=head->prev;
   head->prev->next=new_node;
   head->prev=new_node;
  }
    
}

// Create a new node and insert at the begining of the list
void Insert_Begin(CDLL *h, int s)
{
    
    CDLL* new_node=(CDLL*)malloc(sizeof(CDLL));
    new_node->data=s;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL){
      head=new_node;
      new_node->next=new_node;
     new_node->prev=new_node;}
    
   else
   {
      new_node->next=head;
      new_node->prev=head->prev;
      head->prev->next=new_node;
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
void Insert_After_X(CDLL *h, int s, int x)
{
    CDLL* new_node=(CDLL*)malloc(sizeof(CDLL));
  CDLL *current;
  new_node->data=s;
  new_node->next=NULL;
 new_node->prev=NULL;
  current=head;
   do 
    {
    if (current->data == x)
      {
        new_node->prev=current;
      new_node->next=current->next;
      current->next=new_node; 
      new_node->next->prev=new_node;
      break;
      }
        current = current->next;
    
    } while (current != head);

    // Element not found in list
    return ;
  
}
// Delete the first node
void Delete_Begin(CDLL *h)
{ CDLL *t=head;
    if(head==NULL)
    return;
    else if(t->next==t&&t->prev==t)
    {
      head=NULL;
      
      return;
    }
    else
    { 
     head=t->next;
     t->prev->next=t->next;
     t->next->prev=t->prev;
     free(t);
     }
}


// Delete the Last node
void Delete_Last(CDLL *h)
{
    CDLL *t;
    t=head->prev;
    if(h==NULL)
    return;
   else
   {
     t->prev->next=head;
     head->prev=t->prev;
     free(t);
   }   
}


// Delete the node whcih contains data element x
void Delete_X(CDLL *h, int x)
{ 
  CDLL *t=head;
  if(h==NULL)
    return;
  while(t->next!=head&& t->data !=x)
  {
  	t=t->next;
  }
   
   	if(t->next==head)
	{
		  t->prev->next=head;
     head->prev=t->prev;
		
	
	}
	else if(t==head)
	{  
     head=t->next;
     t->prev->next=t->next;
     t->next->prev=t->prev;
  
	}

  else
  t->next->prev=t->prev;
  t->prev->next=t->next;
}

// Check x is there in the list or not
// if x is in the list return x otherwise return 0
int Search_X(CDLL *h, int x)
{
    CDLL *cur=head;
   do 
    {
    if (cur->data == x)
      {return x; break;}

        cur = cur->next;
    
    } while (cur != head);

    // Element not found in list
    return -1;
}

