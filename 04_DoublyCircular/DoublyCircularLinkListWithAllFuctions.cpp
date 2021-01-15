#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev; 
}NODE, *PNODE;

class DoublyCircularList
{
	private :
	    PNODE Head;
		PNODE Tail;
		int size;
		
	public:
		DoublyCircularList();
		void InsertFirst(int);
		void InsertLast(int);
		void InsertAtPos(int, int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int Count();
};

DoublyCircularList::DoublyCircularList()
{
	Head = NULL;
	Tail = NULL;
	size = 0;
}

void DoublyCircularList::InsertFirst(int data)
{
	PNODE newn = new NODE;
	newn->data = data;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((Head == NULL) && (Tail ==  NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn ->next = Head;
	    Head->prev = newn;
		Head = newn;
	}
	
	Tail->next = Head;
	Head->prev = Tail;
    size++; 
}

void DoublyCircularList::InsertLast(int data)
{
	PNODE newn = new NODE;
	newn->data = data;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((Head == NULL) && (Tail ==  NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->next = newn;
		newn->prev = Tail;
		Tail = newn;
	}
	
	Tail->next = Head;
	Head->prev = Tail;
	size++; 
}

void  DoublyCircularList::InsertAtPos(int data, int pos)
{
    int count = Count();
     
	if(pos <= 0 || pos > count+1)
	{
		cout<<"Error: Invalid Input!\n";
		return;
	}	
	 
	if(pos == 1)
	{
		InsertFirst(data);
	}
	else if(pos == count + 1)
	{
		InsertLast(data);
	}
	else
    {
	    PNODE temp = Head;

		PNODE newn = new NODE;
		newn->data = data;
		newn->next = NULL;
		newn->prev = NULL;
		
        for(int i =1; i < pos-1;i++)
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

void DoublyCircularList::DeleteFirst()
{
	if((Head == NULL) && (Tail == NULL))                      //Linked List Empty
	{
		cout<<"Linked List is Empty!\n";
		return;
	}
	
	if(Head == Tail)                                          //At least Single Node
	{
		free(Head);
		Head = NULL;
		Tail = NULL;
	}
	else                                                       //More than One Node
	{
		Head = Head -> next;
		free(Tail->next);
		
		Head->prev = Tail;
		Tail->next = Head;
	}
	
	size--; 
	cout<<"Node Deleted Sucessfully\n";
}

void DoublyCircularList::DeleteLast()
{
	if((Head == NULL) && (Tail == NULL))                    //Linked List Empty
	{
		cout<<"Linked List is Empty!\n";
		return;
	}
	
	if(Head == Tail)                                         //At least Single Node
	{
		free(Head);
		Head = NULL;
		Tail = NULL;
	}
	else                                                     //More than One Node
	{
		Tail = Tail->prev;
		free(Tail->next);
		
		Head->prev = Tail;
		Tail->next = Head;		
	}
	size--; 
	cout<<"Node Deleted Sucessfully\n";
}

void DoublyCircularList::DeleteAtPos(int pos)
{
	int count = Count(); 
	if(pos <= 0 || pos > count)
	{
		cout<<"Error : Invalid position!\n";
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
		cout<<"Node Deleted Succesfully from pos:\n"<<pos;
	}
}

void DoublyCircularList::Display()
{
	if((Head == NULL) && (Tail == NULL))
	{
		cout<<"Linked List is Empty!\n";
		return;
	}
     
	do
	{
		printf("|%d|<=>",Head->data);
		Head = Head -> next;
	} 
    while(Head != Tail->next);
	cout<<"\n";
}

int DoublyCircularList::Count()
{
	return size;	
}

int main()
{
     int choice =1, value =0, pos=0, cnt =0;
	
     DoublyCircularList obj;
     
	  while(choice !=0)
	  {
		  cout<<"---------------------------------------------\n";
          cout<<"DOUBBLY CIRCULAR LINKED LIST USING C++\n";		  
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
