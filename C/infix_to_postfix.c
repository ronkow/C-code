#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//Linked list structure and functions

typedef struct ListNode 
{
    int item;
    struct ListNode *next;
} ListNode;

typedef struct List 
{
    int size;
    struct ListNode *head;
} List;

List * make_list() 
{
    List *l = (List *)malloc(sizeof(List));
    l->size = 0;
    l->head = 0;
    return l;
}

int get_list(List *l, int index) 
{
    ListNode *curr = l->head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->item;
}

void insert_list(List *l, int index, int val) 
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->item = val;

    if (index == 0) 
    {
        node->next = l->head;
        l->head = node;
    } 
    else 
    {
        ListNode *curr = l->head;
        for (int i=0; i<index-1; ++i)
            curr = curr->next;
        node->next = curr->next;
        curr->next = node;
    }
    l->size++;
}

void remove_list(List *l, int index) 
{
    ListNode *del;
    if (index == 0) {
        del = l->head;
        l->head = del->next;
    } 
    else 
    {
        ListNode *curr = l->head;
        for (int i=0; i<index-1; ++i)
            curr = curr->next;
        del = curr->next;
        curr->next = del->next;
    }
    if (del)
        free(del);
    l->size--;
}

int get_length(List *l) 
{
    return l->size;
}

void print_list(List *l) 
{
    for (ListNode *n = l->head; n; n = n->next)
        printf("%d ", n->item);
}

//----------------
// Stack functions

typedef List Stack;

Stack * make_stack() 
{    return (Stack *)make_list();
}

void push(Stack *s, int val) 
{    insert_list(s, 0, val);
}

int peek(Stack *s) 
{    return get_list(s, 0);
}

int pop(Stack *s) 
{   int value = peek(s);
    remove_list(s, 0);
    return value;
}

bool empty_stack(Stack *s) 
{    return s->size == 0;
}

int size_stack(Stack *s) 
{    return s->size;
}

//-------------------------
// Functions to check signs

int precedenceToken(char c)
{
	if( c=='^' ) 
		return 3;
	else if ( c=='*' || c=='/' || c=='%' )
		return 2;
	else if ( c=='+' || c=='-' )
		return 1;
	else 
		return 0;
}

int precedenceStack(Stack *s)
{
	char c = peek(s);
	
	if( c=='^' ) 
		return 3;
	else if ( c=='*' || c=='/' || c=='%' )
		return 2;
	else if ( c=='+' || c=='-' )
		return 1;		
	else
		return 0;	
}

bool operatorToken(char c)
{
    return ( c=='^' || c=='*' || c=='/' || c=='%' || c=='+' || c=='-' );
}	

bool openBracketToken (char c)
{	
    return ( c=='(' || c=='[' || c=='{' );
}
	
bool closeBracketToken (char c)
{
    return ( c==')' || c==']' || c=='}' );
}
	
bool openBracketStack (Stack *s)
{
	char c = peek(s);
	return ( c=='(' || c=='[' || c=='{' );
}	

//---------------------------------------------------------
// Function checks that brackets {[( )]} match in an expression
// Returns true if the expression is valid

bool match_bracket(FILE *in) 
{
	int flag;
	int d;
	char c;
	
	Stack *sOpen = make_stack();	    //stack for open brackets
	
	while ( (flag = fscanf(in, "%d", &d)) != EOF ) 
	{
        if (flag == 0)                  //if not integer
		{
            c = getc(in); 
			
			if ( openBracketToken(c) )  //character is an open bracket
			{	push(sOpen, c);
			}
			
			if ( closeBracketToken(c) ) //character is a close bracket
			{					
				if ( size_stack(sOpen) > 0 )
				{   //pop one open bracket to check for match with close bracket
					int bOpen = pop(sOpen);     
					if( (bOpen=='(' && c!=')') ||
						(bOpen=='[' && c!=']') ||
						(bOpen=='{' && c!='}') ) 
					{	return false;		
					}		
				}
				//else if size_stack(sOpen) == 0. 
				//There are no open brackets before this close bracket
				else    
				{   return false;
				}
			}	
		}
	}	
	//if num of open brackets exceeds num of close brackets
	if( size_stack(sOpen) > 0)
	{	   return false;
	}	
	return true;
}

//-------------------------------------------------------------
//Function converts an infix expression to a postfix expression
//Function does not check validity of bracket matching in infix expression. 
//A valid input is assumed.

void in_to_post(FILE *in) 
{
	int flag;
	int d;
	char c;
	
	Stack *s = make_stack();	
	
	while ( (flag = fscanf(in, "%d", &d)) != EOF ) 
	{	
        if (flag == 1) 
		{   printf("%d ", d);	//print operand
        } 
		else  //flag == 0 
		{	c=getc(in);			
		
			if ( operatorToken(c) )  //if token is an operator
			{				
				if ( size_stack(s)==0 || 
					 (openBracketStack(s) == true) ||
					 precedenceStack(s) < precedenceToken(c) )
				{	push(s, c);
				}	
				else
				{	while ( size_stack(s) > 0 &&
							( (openBracketStack(s) == false) || 
							 precedenceStack(s) >= precedenceToken(c)) )
					{	printf("%c ", pop(s));
					}								
					push(s, c);		
				}
			}
			else if ( openBracketToken(c) )  //if token is an open bracket
			{   push(s, c);
			}		
			else if ( closeBracketToken(c) ) //if token is a close bracket
			{
				while ( size_stack(s) > 0 &&
						openBracketStack(s) == false ) 
				{	printf("%c ", pop(s));
				}
			
				if ( openBracketStack(s) )
				{	pop(s);
				}
			}	
        }		
	}
				
    while ( size_stack(s) > 0 )  //print remaining operators
	{	printf("%c ", pop(s));
	}
}

//------------------------------------------------------
//Function calculates the result of a postfix expression
//Function does not check validity of postfix expression. 
//A valid input is assumed. 

int calculate(FILE *in) 
{
    int flag = 0;
  	int d;
    char c;
	
	Stack *s = make_stack();
	
	int result;
		
    while ((flag = fscanf(in, "%d", &d)) != EOF) 
	{
        if (flag == 1) 
		{   push(s, d); 
        } 
		else 
		{	c = getc(in);
	
			if(c == ' ')    //if character is a space, get the next character
			{	c = getc(in);
			}
			
			int x = pop(s);
			int y = pop(s);
			
			if( c == '^' )
			{	result = 1;
				for(int i=1; i<=x; i++)
					result *= y;
			}
			else if( c == '*' )
				result = y * x;
			else if( c == '/' )
				result = y / x;
			else if( c == '%' )
				result = y % x;
			else if( c == '+' )
				result = y + x;
				
			else if( c == '-' )
				result = y - x;
			
			push(s, result);
		}
	}
	return pop(s);
}
