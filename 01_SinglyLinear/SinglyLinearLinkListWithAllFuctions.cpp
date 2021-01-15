#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
	
}NODE, *PNODE;

class SinglyLinkedList
{
	private : 
        PNODE Head;
	    int size; 
     
	public :
      SinglyLinkedList();
      void InsertFirst(int);
      void InsertLast(int);
	  void InsertAtPos(int,int);
      void DeleteFirst();
	  void DeleteLast();
	  void DeleteAtPos(int);
	  void Display();
      int Count();	  
      
};

SinglyLinkedList::SinglyLinkedList()
{
	Head = NULL;
	size =0;
}

void SinglyLinkedList::InsertFirst(int data)
{
	PNODE newn = new NODE; //c++ dynamic memory allocation via new intenally calls malloc
	newn->data = data;
	newn->next = NULL;
	
   if(Head == NULL)
   {
	   Head = newn;
   }	   
   else
	{
 		 newn ->next = Head;
          Head = newn;               
	}
	size++;
}

void SinglyLinkedList::Display()
{
  PNODE	temp = Head;
  
  while(temp != NULL)
  {
	  cout<<"|"<<temp -> data<<"|->";
      temp = temp -> next;
  }	  
	cout<<"NULL\n";
}

int SinglyLinkedList::Count()
{
	return size;	
}

void SinglyLinkedList::InsertLast(int data)
{
	PNODE newn = new NODE;
	PNODE temp = Head;

	newn->data = data;
	newn->next = NULL;
	
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
	}
	
	size++;
}

void SinglyLinkedList::InsertAtPos(int data, int pos)
{
      int count = Count();
     
	if(pos< 1 || pos> count+1)
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
	    PNODE temp = Head;

		PNODE newn = new NODE;
        newn->data = data;
		newn->next = NULL;
		
        for(int i =1; i < pos-1;i++)
		{
			temp = temp->next;
		}			
		  
		newn->next = temp->next;
        temp->next =newn; 
       
        size++;
  	  
    }
}


void SinglyLinkedList::DeleteFirst()
{
	if(Head == NULL)
		return;
	
	if(Head->next == NULL)
	{
		free(Head);
		 Head = NULL;
	}
	else
	{
      PNODE temp = Head;
	  Head = Head->next;
      free(temp);
	  
	}
	
	size--;
}

void SinglyLinkedList::DeleteLast()
{
	if(Head == NULL)
		return;
	
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
}

void SinglyLinkedList::DeleteAtPos(int pos)
{
	int count = Count(); 
	if(pos < 1 || pos > count)
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
 		PNODE temp1 = Head; 
		PNODE temp2 = NULL; 
         int i =0; 
		 for( i = 1; i <  pos-1; i++)
		 {
			 temp1 = temp1->next;
		 }
		 temp2 = temp1 -> next; 
		 temp1 -> next = temp2 -> next;
		 free(temp2);
		 
		 size--;
	}
}

int main()
{
     int choice =1, value =0, pos=0, cnt =0;
	
     SinglyLinkedList obj;
     
	  while(choice !=0)
	  {
		  cout<<"---------------------------------------------\n";
          cout<<"SINGLY LINKED LIST USING C++\n";		  
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
