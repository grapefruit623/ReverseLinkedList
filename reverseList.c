/*
 * =====================================================================================
 *
 *       Filename:  reverList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年09月01日 19時09分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  grapefruit623 (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


struct node {
	int num;
	struct node *next;
};				/* ----------  end of struct node  ---------- */

typedef struct node Node;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  appendNewNode
 *  Description:  
 * =====================================================================================
 */
	Node*	
appendNewNode ( int n  )
{
	Node *a = (Node*)malloc( sizeof(Node) );
	a->num = n;
	a->next = NULL;
	return a;
}		/* -----  end of function appendNewNode  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  freeListMem
 *  Description:  
 * =====================================================================================
 */
	int
freeListMem ( Node* head  )
{

	Node *temp=NULL;
	while ( head!=NULL ) {
		temp = head->next;
		free( head );
		head = temp;
	}

	return 0;
}		/* -----  end of function freeListMem  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  reverseList
 *  Description:  
 * =====================================================================================
 */
	int
reverseList ( Node *head, Node *tail )
{
	Node *originHead = head;
	Node *temp=head->next, *after=NULL;
	while ( temp != NULL ) {
		after = temp->next;
		temp->next = head;
		head = temp;
		temp = after;
	}
	originHead->next = NULL;
	
	return 0;
}		/* -----  end of function reverseList  ----- */
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	printf ( "hello world\n" );

	Node *head=NULL, *tail=NULL;
	Node *itr = NULL;
	int i = 0;
	
	for ( i=0; i<10; i++ ) {
		if ( NULL == head ) {
			head = appendNewNode(i);
			tail = head;
		}
		else {
			tail->next = appendNewNode(i);
			tail = tail->next;
		}
	}
	
	printf ( "Not reverse\n" );
	for ( itr=head; itr!=NULL ; itr=itr->next ) {
		printf ( "%d ", itr->num );
	}
	printf ( "\nreverse\n" );
	reverseList( head, tail );
	for ( itr=tail; itr!=NULL ; itr=itr->next ) {
		printf ( "%d ", itr->num );
	}

	freeListMem( head );

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

