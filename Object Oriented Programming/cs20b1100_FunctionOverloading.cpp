#include <iostream>
using namespace std;

class FnOverload
{
private:
	int data;
    FnOverload *next;
public:
	FnOverload(){};
	//In Function Overloading “Function” name should be the same and the arguments should be different.
	//Function overloading where two or more functions can have the same name but different parameters.
	FnOverload *insertToList(FnOverload *tmpHead,int value);
	FnOverload *insertToList(FnOverload *tmpHead,int value,int pos);
	FnOverload *deleteFromList(FnOverload *tmpHead);
	FnOverload *deleteFromList(FnOverload *tmpHead,int pos);
	void displayList(FnOverload *tmpHead);
    void freeLists(FnOverload *tmpHead);
	~FnOverload(){};
	
};

FnOverload *FnOverload::insertToList(FnOverload *tmpHead,int value)
{
	if (tmpHead == NULL)
	{
		tmpHead = new FnOverload();
		tmpHead->data = value;
		tmpHead->next = NULL;
	}
	else
	{
		FnOverload *newNode = new FnOverload();
	    newNode->data = value;
	    newNode->next = NULL;

		FnOverload *tmpNode = tmpHead;
		while(tmpNode->next)
		{
			tmpNode = tmpNode->next;
		}

		tmpNode->next = newNode;
	}

	return tmpHead;
}

FnOverload *FnOverload::insertToList(FnOverload *tmpHead,int value,int pos)
{
	if (pos == 1 && tmpHead == NULL)
	{
		tmpHead = new FnOverload();
		tmpHead->data = value;
		tmpHead->next = NULL;
	}
	else if (pos != 1 && tmpHead == NULL)
	{
		cout<<"!!!! Position doesn't exists !!!!"<<endl;
	}
	else
	{
		FnOverload *newNode = new FnOverload();
	    newNode->data = value;
	    newNode->next = NULL;

		FnOverload *prevNode,*tmpNode = tmpHead;
        int n = 0;
		while(tmpNode)
		{
			prevNode = tmpNode;
			tmpNode = tmpNode->next;
			++n;
			if (n == pos - 1)
			{
				break;
			}
			if (!tmpNode )
			{
				break;
			}
		}

		if (tmpNode == NULL && n == pos-1)
		{
			prevNode->next = newNode;
		}
		else if (tmpNode)
		{
			prevNode->next = newNode;
		    newNode->next = tmpNode;
		}
		else
	    {
	    	cout<<"\n!!!! Position doesn't exists !!!!"<<endl;
	    }
	}

	return tmpHead;
}

FnOverload *FnOverload::deleteFromList(FnOverload *tmpHead)
{
	FnOverload *tmp = NULL,*tmpNode = tmpHead;
	if (tmpHead == NULL)
	{
		cout<<"!!!! List is empty !!!!\n";
	}
	else if (tmpHead->next == NULL)
	{
		tmpHead = tmp;
		delete tmpNode;
	}
	else
	{
		while(tmpNode->next)
		{
			tmp = tmpNode;
			tmpNode = tmpNode->next ;
		}
        
        tmp->next = NULL;
        delete tmpNode;
	}

	return tmpHead;
}

FnOverload *FnOverload::deleteFromList(FnOverload *tmpHead,int pos)
{
	FnOverload *tmp = NULL,*tmpNode = tmpHead;
	if (tmpHead == NULL)
	{
		cout<<"!!!! List is empty !!!!\n";
	}
	else if (pos == 1 && tmpHead->next == NULL)
	{
		tmpHead= tmp;
		delete tmpNode;
	}
	else if (pos == 1)
	{
		tmpHead = tmpHead->next;
		delete tmpNode;
	}
	else
	{
        int n = 0;
		while(tmpNode)
		{
			tmp = tmpNode;
			tmpNode = tmpNode->next;
			++n;
			if (n == pos - 1)
			{
				break;
			}
			if (!tmpNode )
			{
				break;
			}
		}

		if (tmpNode)
		{
			tmp->next = tmpNode->next;
		}
		else
	    {
	    	cout<<"\n!!!! Position doesn't exists !!!!"<<endl;
	    }

		/*for (int i = 0; i < pos; ++i)
		{
			tmp = tmpNode;
			tmpNode = tmpNode->next;
			if (!tmpNode)
			{
				cout<<"!!!! Position doesn't exists !!!!\n"<<endl;
				break;
			}
		}

		if (tmpNode)
		{
			tmp->next = tmpNode->next;
		}*/
        
        delete tmpNode;
	}

	return tmpHead;
}

void FnOverload::displayList(FnOverload *tmpHead)
{
	if (tmpHead == NULL)
	{
		cout<<"!!!! List is empty !!!!";
	}
	else
	{
		while(tmpHead)
	    {
	    	cout<<"->"<< tmpHead->data;
            tmpHead = tmpHead->next;
	    }
	}
}

void FnOverload::freeLists(FnOverload *tmpHead)
{
	FnOverload* currentNode = tmpHead;
    while (currentNode != nullptr) {
        FnOverload* next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }
}

int main()
{
	FnOverload *head;
	int choice,number,position;
	while(1)
	{
		cout<<"\n0.Exit"<<endl;
		cout<<"1.Insert an element"<<endl;
		cout<<"2.Insert an element at particular postion"<<endl;
		cout<<"3.Delete an element"<<endl;
		cout<<"4.Delete an element at particular postion"<<endl;
		cout<<"5.Display elements in linked list"<<endl;
		cout<<"Enter your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 0:
			{
				head->freeLists(head);
				exit(0);
			}

			case 1:
			{
				cout<<"\nEnter Number which you want to insert: ";
				cin>>number;

                head = head->insertToList(head,number);
                break;
			}

			case 2:
			{
				cout<<"\nEnter Number which you want to insert: ";
				cin>>number;
				cout<<"Enter position where you want to insert: ";
				cin>>position;

                head = head->insertToList(head,number,position);
                break;
			}
            
            case 3:
			{
				cout<<endl;
                head = head->deleteFromList(head);
                break;
			}

			case 4:
			{
				cout<<"\nEnter position where you want to delete: ";
				cin>>position;

                head = head->deleteFromList(head,position);
                break;
			}

			case 5:
			{
				cout<<"\nSingle Linked List: ";
				head->displayList(head);
				cout<<endl;
				break;
			}

			default:
			{
				cout<<"\nWrong choice, try again!\n"; 
			}  
		}
	}
	
	return 0;
}