#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display(); 
typedef struct node STACK; 
struct node   
{  
int data;  
struct node *next;  
};  
STACK *top;  
  
void main ()  
{  
    int choice=0;     
    printf("\n\n***** MENU *****\n");   
    while(choice != 4)  
    {  
        printf("\n\nChose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exit");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
    };  
}  
}  
//pushing value in stack
void push ()  
{  
    int ele;  
    STACK *ptr = (STACK*)malloc(sizeof(STACK));   
    if(ptr == NULL)  
    {  
        printf("Stack Overflow");   
    }  
    else   
    {  
        printf("Enter the value");  
        scanf("%d",&ele);  
        if(top==NULL)  
        {         
            ptr->data = ele;  
            ptr -> next = NULL;  
            top=ptr;  
        }   
        else   
        {  
            ptr->data = ele;  
            ptr->next = top;  
            top=ptr;  
               
        }  
        printf("Insertion done");  
          
    }  
}  

//popping stack data  
void pop()  
{  
    int ele;  
    STACK *ptr;  
    if (top == NULL)  
    {  
        printf("Stack Underflow");  
    }  
    else  
    {  
        ele = top->data;  
        ptr = top;  
        top = top->next;  
        free(ptr);  
        printf("popped value is %d\n",ele);  
          
    }  
}
//displaying stack  
void display()  
{  
      
    STACK *ptr;  
    ptr=top;  
    if(ptr == NULL)  
    {  
        printf("Stack Undeflow");  
    }  
    else  
    {  
        printf("Stack elements are\n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->data);  
            ptr = ptr->next;  
        }  
    }  
}

