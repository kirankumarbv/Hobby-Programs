#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
struct vector
{	int snum;	
	unsigned int bvec;
	struct vector* link;
};
typedef struct vector* VECTOR;

VECTOR getvec()
{	
	VECTOR temp;
	temp=(VECTOR) calloc(1,sizeof(struct vector));
	if(temp==NULL)
	{	printf("Out of memory!") ;
			exit(0) ;
	}	
	return temp;
}


VECTOR input(int x,VECTOR head)
{	
	VECTOR prev,cur,temp;
	int y=x/32;
	y=y*32;
	
	if(head==NULL)
	{	head=getvec();
		head->snum=y;
		head->bvec=pow(2,(x%32));
		return head;
	}
	prev=NULL;
	cur=head;
	
	while( cur!=NULL && (y>cur->snum) )
	{	prev=cur;
		cur=cur->link;
	}
	
	if(cur==NULL)
	{	temp=getvec();
		temp->snum=y;
		temp->bvec=pow(2,(x%32));
		prev->link=temp;	
	}
	else if(cur->snum==y)
	{	cur->bvec=cur->bvec+pow(2,(x%32));
	}
	else 
	{	
		temp=getvec();
		temp->snum=y;;
		temp->bvec=pow(2,(x%32));
		if(prev==NULL)
		{	temp->link=head;
			head=temp;
		}
		else
		{	temp->link=prev->link;
			prev->link=temp;
		}
	}

	return head;
}

VECTOR set_union(VECTOR head1,VECTOR head2)
{
	VECTOR u_head,temp;
	u_head = getvec();

	if(head1 == NULL || head2 == NULL)
	{
		if(head1!=NULL)
			return head1;
		else 
			return head2;
	}

	int i=0;

	while(head1 !=NULL && head2!=NULL)
	{
		VECTOR temp1=getvec();		
		if(head1->snum==head2->snum)
		{
		temp1->snum=head1->snum;
			temp1->bvec = head1->bvec | head2->bvec;
			temp1->link=NULL;
			head1=head1->link;
			head2=head2->link;
		}
		else if(head1->snum < head2->snum)
		{
			temp1->snum=head1->snum;
			temp1->bvec = head1->bvec;
			temp1->link=NULL;
			head1=head1->link;
		}
		else
		{
			temp1->snum=head2->snum;
			temp1->bvec = head2->bvec;
			temp1->link=NULL;
			head2=head2->link;
		}
		if(i==0)
		{
			u_head=temp1;
			i=1;
			temp=u_head;
		}
		else
		{
			temp->link=temp1;
			temp=temp->link;
		}
	}
	if(head1!=NULL)
	{
		if(i==0)
			u_head=head1;
		else
		temp->link=head1;
	}
	else if(head2!=NULL)
	{	
		if(i==0)
			u_head=head2;
		else
		temp->link=head2;
	}

	return u_head;	
}

VECTOR set_intersection(VECTOR head1, VECTOR head2)
{
	VECTOR i_head=NULL,cur;
	int i=0;

	while(head1!=NULL && head2!=NULL)
	{
		if(head1->snum==head2->snum)
		{	VECTOR temp=getvec();
			temp->bvec=head1->bvec&head2->bvec;
			if(temp->bvec)
			{	temp->snum=head1->snum;
				if(i==0)
				{	i_head=temp;
					cur=temp;
					i=1;

				}
				else
				{	cur->link=temp;
					cur=cur->link;
				}
			}
			head1=head1->link;
			head2=head2->link;
		}
		else if(head1->snum < head2->snum)
			head1=head1->link;
		else if(head2->snum < head1->snum)
			head2=head2->link;
	}

return i_head;
}


VECTOR set_diff(VECTOR head1,VECTOR head2)
{	
	VECTOR d_head=NULL,cur;
	int i=0;

	while(head1!=NULL&&head2!=NULL)
	{	VECTOR temp=getvec();
		if(head1->snum==head2->snum)
		{	temp->bvec=head1->bvec&(~head2->bvec);
			if(temp->bvec)
			{	temp->snum=head1->snum;
				
			}
			head1=head1->link;
			head2=head2->link;
		}
		else if(head1->snum<head2->snum)		
		{	temp=head1;
			head1=head1->link;
		}
		else head2=head2->link;
		if(i==0)
		{	d_head=cur=temp;i=1;	
		}
		else
		{	cur->link=temp;
			cur=cur->link;
		}
	}

	if(head1!=NULL)
	{	
		if(i==0)
		d_head=head1;
		else
		cur->link=head1;
	}

	return d_head;
}

int set_membership(int x,VECTOR head)
{	
	int y=x/32;
	y=y*32;
	
	while(head!=NULL&&y>head->snum)
	{	head=head->link;
	}
	if(head==NULL)
		return 0;
	if(y==head->snum)
	{	int z=0;
		z=pow(2,x%32);
		z=z&head->bvec;
		if(z!=0)
			return 1;
	}

	return 0;
}


void display(VECTOR head)
{	
	unsigned int x;
	int count;

	while(head!=NULL)
	{
		count=0;
		x=head->bvec;
		do
		{	if(x%2==1)
				printf("%d\t",count+head->snum);
	 		count++;
			x=x>>1;
		}while(x!=0);
		head=head->link;
	}
}	

int main()
{	
	int i,x,n,y;
	srand(time(NULL)); 	
	VECTOR setA=NULL,setB=NULL,setC=NULL;

	printf("Enter no. of elements in set A\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	x=rand()%10000;
		setA=input(x,setA);
	}

	printf("Enter no. of elements in set B\n");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{	
				y=rand()%10000;
				setB=input(y,setB);
			}

	while(1)
	{	printf("\nEnter your choice\n");
		printf("1.Union of sets\n2.Intersection of sets\n3.Set difference\n4.Set membership\n5.exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				setC=set_union(setA,setB);
				printf("Set A :");
				display(setA);
				printf("\nSet B :");
				display(setB);
				printf("\nUnion :");
				display(setC);
				break;
			case 2:
				setC=set_intersection(setA,setB);
				printf("Set A :");
				display(setA);
				printf("\nSet B :");
				display(setB);
				printf("\nIntersection :");
				display(setC);
				break;
			case 3: 
				setC=set_diff(setA,setB);
				printf("Set A :");
				display(setA);
				printf("\nSet B :");
				display(setB);
				printf("\nDifference(A-B) :");
				display(setC);
				break;
			case 4:
				int key;
				printf("Enter the element\n");
				scanf("%d",&key);
				y=set_membership(key,setA);
				if(y==0)
					printf("The element is not a member\n");
				else
					printf("The element is a member of the set A\n");
				break;
			default:
				printf("Set A :");
				display(setA);
				printf("\nSet B :");
				display(setB);
				exit(0);
		}
		
	}
	return 0;
}
	

	
