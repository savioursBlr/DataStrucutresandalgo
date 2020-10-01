/*P4.1 Program of stack using array*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

main()
{
	int choice,item;
	while(1)
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display the top element\n");
		printf("4.Display all stack elements\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1 :
			printf("Enter the item to be pushed : ");
			scanf("%d",&item);
			push(item);
			break;
		 case 2:
			item = pop();
			printf("Popped item is : %d\n",item );
			break;
		 case 3:
			printf("Item at the top is : %d\n", peek() );
			break;
		 case 4:
			display();
			break;
		 case 5:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while*/
}/*End of main()*/

void push(int item)
{
	if( isFull() )
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top+1;
	stack_arr[top] = item;
}/*End of push()*/

int pop()
{
	int item;
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item = stack_arr[top];
	top = top-1;
	return item;
}/*End of pop()*/

int peek()
{
	if( isEmpty() )
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack_arr[top];
}/*End of peek()*/

int isEmpty()
{
	if( top == -1 )
		return 1;
	else
		return 0;
}/*End of isEmpty*/

int isFull()
{
	if( top == MAX-1 )
		return 1;
	else
		return 0;
}/*End of isFull*/

void display()
{
	int i;
	if( isEmpty() )
	{
		printf("Stack is empty\n");
		return;
	}
    printf("Stack elements :\n\n");
	for(i=top;i>=0;i--)
		printf(" %d\n", stack_arr[i] );
	printf("\n");
}/*End of display()*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///linked list implementation of stack


// C++ program to Implement a stack  
//using singly linked list  
#include <bits/stdc++.h>  
using namespace std;  
  
// Declare linked list node  
  
struct Node  
{  
    int data;  
    struct Node* link;  
};  
  
struct Node* top;  
  
// Utility function to add an element  
// data in the stack insert at the beginning  
void push(int data)  
{  
      
    // Create new node temp and allocate memory  
    struct Node* temp;  
    temp = new Node();  
  
    // Check if stack (heap) is full.  
    // Then inserting an element would  
    // lead to stack overflow  
    if (!temp) 
    {  
        cout << "\nHeap Overflow";  
        exit(1);  
    }  
  
    // Initialize data into temp data field  
    temp->data = data;  
  
    // Put top pointer reference into temp link  
    temp->link = top;  
  
    // Make temp as top of Stack  
    top = temp;  
}  
  
// Utility function to check if  
// the stack is empty or not  
int isEmpty()  
{  
    return top == NULL;  
}  
  
// Utility function to return top element in a stack  
int peek()  
{  
      
    // Check for empty stack  
    if (!isEmpty())  
        return top->data;  
    else
        exit(1);  
}  
  
// Utility function to pop top  
// element from the stack  
void pop()  
{  
    struct Node* temp;  
  
    // Check for stack underflow  
    if (top == NULL)  
    {  
        cout << "\nStack Underflow" << endl;  
        exit(1);  
    }  
    else
    {  
          
        // Top assign into temp  
        temp = top;  
  
        // Assign second node to top  
        top = top->link;  
  
        // Destroy connection between 
        // first and second  
        temp->link = NULL;  
  
        // Release memory of top node  
        free(temp);  
    }  
}  
  
// Function to print all the  
// elements of the stack  
void display()  
{  
    struct Node* temp;  
  
    // Check for stack underflow  
    if (top == NULL) 
    {  
        cout << "\nStack Underflow";  
        exit(1);  
    }  
    else 
    {  
        temp = top;  
        while (temp != NULL) 
        {  
  
            // Print node data  
            cout << temp->data << "-> ";  
  
            // Assign temp link to temp  
            temp = temp->link;  
        }  
    }  
}  
  
// Driver Code  
int main()  
{  
      
    // Push the elements of stack  
    push(11);  
    push(22);  
    push(33);  
    push(44);  
  
    // Display stack elements  
    display();  
  
    // Print top element of stack  
    cout << "\nTop element is "
         << peek() << endl;  
  
    // Delete top elements of stack  
    pop();  
    pop();  
  
    // Display stack elements  
    display();  
  
    // Print top element of stack  
    cout << "\nTop element is " 
         << peek() << endl;  
           
    return 0;  
}  
  



