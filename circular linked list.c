#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
    struct node *head,*tail,*temp,*newnode;
int lenght(void);
void insert();
void insert_beg();
void insert_end();
int insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void reverse();
void display();

int main()
{
	int ch,flag=1;
	
	while(flag==1)
	{
		printf("\n LINKED LIST MENU:");
		printf("\n PRESS 1 FOR INSERT:");
		printf("\n PRESS 2 FOR INSERT BEGINNING:");
		printf("\n PRESS 3 FOR INSERT END:");
		printf("\n PRESS 4 FOR INSERT AT POSITION:");
		printf("\n PRESS 5 FOR DISPLAY:");
		printf("\n PRESS 6 FOR DELETE BEGINNING:");
		printf("\n PRESS 7 FOR DELETE  END:");
		printf("\n PRESS 8 FOR DELETE FROM POSITION:");
		printf("\n PRESS 9 FOR REVERSE FOR ELEMENT:");
		
		
		 
		printf("\n ENTER THE YOUR OPTION:");
               scanf("%d",&ch);
               
              switch(ch)
              {
       	 case 1:insert();
       	        break;
       	 case 2:insert_beg();
       	        break;
               case 3:insert_end();
                      break;
               case 4:insert_pos();
                      break;           
       	 case 5:display();
		        break;    
	        case 6:delete_beg();
		        break;           
	        case 7:delete_end();
	               break;
	        case 8:delete_pos();
	               break;
	        case 9:reverse();
	               break;
		        
		 default:printf("ENTER THE CORRECT OPTION:");
                     break;
        	}
	printf("\n PRESS 1 FOR LINKED LIST MENU:");
       scanf("%d",&flag);      
       }
       return 0;
		
}
void insert()
{
	int ch=1;
	
	struct node *newnode;
	head=NULL;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER THE DATA:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if(head==NULL)
		{
		  head=tail=newnode;
		}
		else 
		{
			tail->next=newnode;
			tail=newnode;
		}
		
		printf("\n DO YOU WANT TO CONTINUE(PRESS 1):");
		scanf("%d",&ch);
		
		tail->next=head;
		printf("%d",tail->next->data);
      }
}
void insert_beg()
{
	
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER THE DATA:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=tail=newnode;
		tail->next=newnode;
	}
	else 
	{
	 newnode->next=head;
	 head=newnode;
	 tail->next=head;
	}
	printf("NEW DATA:%d",tail->next->data);	
}
void insert_end()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER THE DATA:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
	    head=tail=newnode;
	    tail->next=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=newnode;
		tail->next=head;
	}
	printf("NEW DATA:%d",tail->data);
	 
}

int insert_pos()
{
	int i=1,l,pos;
	
       printf("\n ENTER THE POSITION:");
	scanf("%d",&pos);
	l=lenght();
        printf("\n lenght of list %d",l);
	
	if(pos>l || pos<0)
	{
		printf("\n INVALID POSITION !");
	}
       else if(pos==1)
	{
	  insert_beg();
	}
	else 
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER THE DATA:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp=head;
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
              newnode->next=temp->next;
              temp->next=newnode;
	}
      return 0;
}

void delete_beg()
{
	
	temp=head;
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else if(temp->next==temp)
	{
		head=tail=NULL;
		printf("\nDELETE ELEMENT:%d",temp->data);  
		free(temp);
	}
	else
	{
		head=head->next;
		printf("\nDELETE ELEMENT:%d",temp->data);
		free(temp);
		tail->next=head;
	}
}
void delete_end()
{
	struct node *current,*previous;
	current=head;
	
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else if(current->next==current)
	{
		head=tail=NULL;
		printf("\n DELETE ELEMENT:%d",current->data);
		free(current);
	}
	else
	{
		while(current->next!=head)
		{
			previous=current;
			current=current->next;
		}
		previous->next=head;
		tail=previous;
		printf("\n DELETE ELEMENT:%d",current->data); 
		free(current);
		
	}
}

void delete_pos()
{
      
       struct node *nextnode,*current;
	 int pos,i=1,l;
	current=head;
	printf("\n ENTER THE POSITION:");
	scanf("%d",&pos);
	l=lenght();
        printf("\n lenght of list %d",l);
      
      	if(pos>l || pos<0)
	{
		printf("\n INVALID POSITION !");
	}
       else if(pos==1)
	{
		delete_beg();
	}
	else 
	{
		while(i<pos-1)
	{
		current=current->next;
		i++;
	}
       nextnode=current->next;
       current->next=nextnode->next;
       if(nextnode->next==head)
	{
	       tail=current;
	   	printf("\nDELETE ELEMENT:%d",nextnode->data);
	       free(nextnode);	
	}
	else
	{
		
	 	printf("\nDELETE ELEMENT:%d",nextnode->data);
        	free(nextnode);
      }
   }
  
}
int lenght()    
{
 	int cout;
 	temp=head;
       do 
 	{
 	       cout++;
 		temp=temp->next;
 		if(temp->next==tail->next)
 		{
 			cout++;
		 }
	}
        while(temp->next!=head);
        

	return(cout);
 }
 
void reverse()
{
	struct node *current,*prev,*nextnode;
	current=head;
	nextnode=current->next;
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{ 
	  printf("\n REVERSE THE ELEMENT:");
	
		while(current!=tail)
		{
			prev=current;
			current=nextnode;
			nextnode=current->next;
			current->next=prev;
		}
		nextnode->next=tail;
		head=tail;
		tail=nextnode;
		
	}
}
void display()  
{
	struct node *temp;
	
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		temp=head;
	       do
		{ 
		  	printf("%d\n",temp->data);
		   	temp=temp->next;
		       if(temp->next==tail->next)
			{
		       	printf("%d\n",temp->data);
			}
		} while(temp->next!=tail->next);
		
	}

}
 
