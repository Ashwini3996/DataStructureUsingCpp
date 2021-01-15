#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
    struct Node *prev; 	
}NODE, *PNODE;

class DoublyLinkedList
{
	private :
	     PNODE Head;
		 int size;
		 
	public :
    DoublyLinkedList();
	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPos(int, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};

DoublyLinkedList::DoublyLinkedList()
{
	Head =NULL;
	size = 0;
}

void DoublyLinkedList::InsertFirst(int data)
{
	PNODE newn = new NODE;
    
	newn->data = data;
    newn->next = NULL;
	newn->prev = NULL;	
	
    if(Head == NULL)
    {
	   Head = newn;
    }	   
    else
	{
 		 newn ->next = Head;
		 Head ->prev = newn;
         Head = newn;               
	}	
	size++;
}

void DoublyLinkedList::InsertLast(int data)
{
	PNODE newn = new NODE;
	PNODE temp = Head;

	newn->data = data;
	newn->next = NULL;
	newn->prev = NULL;
	
    if(Head == NULL)
    {
	    Head = newn;
    }	   
    else
	{
		while(temp->next != NULL)
		{
			temp=temp->next;		  
		}
      
		temp -> next = newn;   
		newn->prev = temp;  		
	}	
	size++;
}


void DoublyLinkedList::InsertAtPos(int data, int pos)
{
    int count = Count();
     
	if(pos <= 0 || pos > count+1)
	{
		printf("Error: Invalid Input!\n");
		return;
	}	
	 
	  if(pos ==1)
	  {
		  InsertFirst(data);
	  }
	  else if(pos == count+1)
	  {
		  InsertLast(data);
	  }
	  else
      {
	    PNODE newn = new NODE;
        PNODE temp = Head;
		
		newn->data = data;
		newn->next = NULL;
		newn->prev = NULL;
		
        for(int i = 1; i < pos-1;i++)
		{
			temp =temp->next;
		}			
		  
		newn->next = temp->next;
        temp->next->prev =newn; 
		temp->next = newn;
		newn->prev = temp;
  	   size++;
	  }
}

void DoublyLinkedList::DeleteFirst()
{
	if(Head == NULL)
	{
	    printf("Linked list is Empty!\n");	
		return;
	}
	
	if(Head->next == NULL)
	{
		free(Head);
		Head = NULL;
	}
	else
	{
        Head =  Head->next;
	    free(Head->prev);
		Head->prev = NULL;	  
	}
    size--;	
	printf("Node Deleted Succesfully!\n");
}

void DoublyLinkedList::DeleteLast()
{
	if(Head == NULL)
	{
	    printf("Linked list is Empty!\n");	
		return;
	}
	
	if(Head->next == NULL)
	{
		free(Head);
		Head = NULL;
	}
	else
	{
        PNODE temp = Head;
        while(temp->next->next !=NULL)
		{
			temp = temp->next;
		}			
		free(temp->next);
		temp->next = NULL;
	}
    size--;	
	printf("Node Deleted Succesfully!\n");
}

void DoublyLinkedList::DeleteAtPos(int pos)
{
	int count = Count(); 
	if(pos <=0 || pos > count)
	{
		printf("Error : Invalid position!\n");
	    return;
	}
	else if(pos == 1)
	{
	  DeleteFirst();
	}
	else if(pos == count)
	{
		DeleteLast();
	}
	else
	{
 		PNODE temp = Head; 
		 int i =0; 
		 for( i = 1; i <  pos-1; i++)
		 {
			 temp = temp->next;
		 }
		 
		 temp->next = temp->next->next;
		 free(temp->next->prev);
		 temp->next->prev=temp;
		 
		 size--;
		 printf("Node Deleted Succesfully from pos:%d\n", pos);
	}
}

void DoublyLinkedList::Display()
{
	PNODE temp = Head;
	while(temp != NULL)
	{
		printf("|%d|<=>",temp->data);
		temp = temp -> next;
	}	  
	printf("NULL\n");
}

int DoublyLinkedList::Count()
{
	return size;	
}


int main()
{
     int choice =1, value =0, pos=0, cnt =0;
	
     DoublyLinkedList obj;
     
	  while(choice !=0)
	  {
		  cout<<"---------------------------------------------\n";
          cout<<"DOUBBLY LINKED LIST USING C++\n";		  
		  cout<<"---------------------------------------------\n";
		  cout<<"1:Insert First\n";
          cout<<"2:Insert Last\n";
          cout<<"3:Insert At Pos\n";
          cout<<"4:Delete First\n";
          cout<<"5:Delete Last\n";
          cout<<"6:Delete At Pos\n";
		  cout<<"7:Display\n";
		  cout<<"8:Count\n";
		  cout<<"0:Exit\n\n";
          cout<<"---------------------------------------------\n";
		  
		 cout<<"Enter your choice:\n";
         cin>>choice;		  

	     switch(choice)
		 {
			 case 1: 
			        cout<<"Enter value:\n";
                	cin>>value;
                    obj.InsertFirst(value);	
               break;

           case 2: 
			        cout<<"Enter value:\n";
  				    cin >>value;
                    obj.InsertLast(value);	
               break;	

            case 3: 
			        cout<<"Enter value:\n";
  				    cin >>value;
                    cout<<"Enter position:\n";
  				    cin >>pos;
                    obj.InsertAtPos(value, pos);	
               break;

            case 4: 
			        obj.DeleteFirst();	
               break;

            case 5: 
			        obj.DeleteLast();	
               break;			   

              case 6: 
			         cout<<"Enter position:\n";
 				     cin>>pos;
                     obj.DeleteAtPos(pos);	
               break;

            case 7: 
                   obj.Display();	
					break;	

            case 8: 
                   cnt = obj.Count();	
				   cout<<"Number of Nodes Present in linked list is:"<<cnt<<"\n\n";
					break;						
		 }
	  }
	printf("Thank You!");
	return 0;
}
