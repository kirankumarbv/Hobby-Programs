/*	 PROGRAM TO DETECT THE DEAD LOCK CONDITION IN THE DATABASE SYSTEM
	-------------------------------------------------------------------

	 USING TOPOLOGICAL SORT ALGORITHM
	----------------------------------


ALGORITHM : 	step 1: read the adjacency matrix
		
		step 2: convert the matrix into adjacency list form
		
		step 3: check for the deadlock

		step 4: repeat the following till there is no deadlock in the system
				if the dead lock exists then delete the latest node
				check for the deadlock
		
		step 5: the final remaining transaction contains no dead lock



*/


#include<stdio.h>
#include<stdlib.h>

struct list		// To maintain the nodes to which there is a directed edge in the wait for graph 
{	int n;
	struct list *next;
};

typedef struct list *LIST;

int **mat;			// To store the matrix
int n;				// Number of transactions
LIST *nodes;			// GRAPH IN THE FORM OF LINKED LIST
int *delete;			//To keep track of the deleted transactions


void read_matrix()
{	int i , j;
	
	scanf("%d",&n);						//Number of transactions
	
	mat = (int **) calloc(n,sizeof(int *));
	
	delete = ( int *) calloc(n,sizeof(int));

	for( i = 0 ;i < n ; i++)
		mat[i] = (int *) calloc(n,sizeof(int));		// allocate memory for matrix  of the wait for graph
	
	for( i = 0 ; i < n ;i++ )
	{	for(j = 0 ; j < n ; j++ )			// read the values of the matrix of the wait for graph
		{	scanf("%d",&mat[i][j]) ;
			if(mat[i][j] > 1)
			{	printf("Invalid input\n") ;
				exit(0);
			}
		}
		delete[i] = 0;
		
	}
}

void convert_into_list()
{	// converts the matrix in to linked list form so that algorithm can be effectively implemented
	
	int i , j ;
	
	FILE *out ;

	LIST temp,cur;
	
	out = fopen("dead.dot","a");
	
	fprintf(out,"digraph lock {\n");
	
	nodes = (LIST *) calloc ( n,sizeof(LIST));

	for( i = 0 ; i  < n; i++ )
	{	
		if(delete[i] == 1)	// If the node is deleted then it does not have any significance
		continue;
		
		nodes[i] = (LIST) calloc ( 1, sizeof( struct list));
		nodes[i]->next = NULL ;
		nodes[i]->n = i;
	
		fprintf(out,"%d[label = T%d];\n",i,i+1)	;
		for( j = 0 ; j  < n ; j++ )	
		{	
			if(delete[j] == 1)
			continue;

			if(i != j && mat[j][i] == 1 )
			{	fprintf(out,"%d->%d;\n",j,i);	
				temp = (LIST) calloc ( 1,sizeof(struct list));
				temp->n = j;
				temp->next = NULL;
				cur = nodes[i];
				while(cur->next != NULL)
					cur = cur->next;
				cur->next = temp;
			}
		}
	}
	fprintf(out,"}\n");
	fclose(out);


}		


int deadlock()
{	
	//checks whether there exists a dead lock in the system
	int i, j,x ;
	int *a, *indegree;			// keep track of the indegrees of each node
	LIST l1 = NULL,temp,cur;

	a = ( int *) calloc( n , sizeof(int));
	indegree = ( int *) calloc ( n , sizeof(int));
	
	
	for( i = 0 ; i < n ; i++)
	{	
		if( delete[i] == 1)
		continue;
	
		a[i] = 0;
		temp = nodes[i]->next;
		indegree[i] = 0;		//Initialize the indegree to 0
		
		while( temp != NULL)
		{	indegree[i] ++ ;
			temp = temp->next;		//calculate the indegree of each node
		}
	
		if(indegree[i] == 0 )
		{	temp = ( LIST) calloc( 1, sizeof(struct list));		// if there is no indegree for a node put it into a separate list
			temp->n = i;
			temp->next = l1;
			l1 = temp;			
		}
	}	
	
	if( l1 == NULL)
	{	for( i = n-1; i>= 0 ;i--)
		{	if(delete[i] == 1)
			continue;
			
			for(j = 0 ; j < i; j++)
			{	if(mat[i][j] == 1)
				return i;
			}
		}
	}
		
	while( l1 != NULL)
	{	temp = l1->next;
		x = l1->n;
		a[x] = 1;							// set the node as explored
		for( j = 0 ; j < n; j++)
		{	if( indegree[j] > 0)					//If the indegree is more tham 0 it might contain a deleted node from wich indegree comes
			{	temp = nodes[j] ;
				while( temp != NULL)
				{	if( temp-> n == x)
					{	indegree[j] --;	
						break;
					}
					temp = temp->next;				
				}
				if( indegree[j] <= 0)				//after deleting tha node if indegree becomes 0 put it into the list
				{	temp = (LIST) calloc(1, sizeof(struct list));
					temp->n = j;
					cur = l1;
					while( cur->next != NULL)
						cur = cur->next;
					cur->next = temp;
					temp->next = NULL;
				}
			}
		}
		l1 = l1->next;
		
	}
	
	for( i = n-1 ; i >=0 ; i--)
	{	if(delete[i] == 1)
		continue;
		
		if(a[i] == 0)					// if the node is not explored then cycle exists
		return i;
	}
	return -1;						//No cycle exists
	
}
int main()
{	int i,j,k;
	
	FILE *pipe;
	
	read_matrix();
	
	convert_into_list();
	
	k = deadlock();

	if( k == -1)
	{    printf("There is no deadlock in the system\n");
		
	}
	
	while ( k != -1)			// repeat the process until no cycles exists
	{	printf("Dead lock exists and the latest transaction T%d involved in dead lock is aborted\n",k+1);
		delete[k] = 1;
		convert_into_list();
		k = deadlock();
		if( k == -1)
		{   	printf("All deadlocks have been removed from the system\n");
			
		}			
	 }
	


	 pipe = popen("dot -Tps dead.dot -o dead.ps","w") ;		// display the dotty file
	 pclose(pipe) ;	
	 pipe=popen("evince dead.ps","r") ; 
 	 pclose(pipe) ;

         pipe = popen("rm dead.dot","w");
	pclose(pipe);
	return 0;		
}
	
