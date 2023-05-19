#include<iostream>
using namespace std;

class LinkedLists
{
private:
	int data;
    LinkedLists *next;
public:
    LinkedLists *insertSortList(LinkedLists *head,int value);
    void displayList(LinkedLists *tmp);
    friend LinkedLists * operator +(LinkedLists &,LinkedLists&);
    void freeLists(LinkedLists *head);
  
};

//Operator overloading to merge two linked lists
LinkedLists * operator + (LinkedLists &list1,LinkedLists &list2)
{
    LinkedLists *head1 = &list1;
    LinkedLists *head2 = &list2;
    
    LinkedLists *ptr = head2;

    while(ptr)
    {
	    head1 = head1->insertSortList(head1,ptr->data);
        ptr = ptr->next;
    }

    return head1;
}

int main()
{
	LinkedLists *head1,*head2; 
	int choice,num;

	while(1)
	{
		cout<<"\n";
		cout<<"1. Insert"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Merge"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice: ";

		cin>>choice;

		switch(choice)
		{
			case 1:
			{
				cout<<"Enter Number which you want to insert: ";
				cin>>num;

				cout<<"\n";
				cout<<"1. Insert into List 1"<<endl;
				cout<<"2. Insert into List 2"<<endl;
				cout<<"Enter your choice: ";
                cin>>choice;

                if (choice == 1)
                {
                	head1 = head1->insertSortList(head1,num);
                }
                else
                {
                	head2 = head2->insertSortList(head2,num);
                }
                break;
			}

			case 2:
			{
				cout<<"\nList1 ";
				head1->displayList(head1);
				cout<<"\nList2 ";
				head2->displayList(head2);
				cout<<"\n";
				break;
			}

			case 3:
			{
				head1 = *head1 + *head2;
				head2 = NULL;
				cout<<"\nMerged Sorted List ";
				head1->displayList(head1);
				cout<<"\n";
				break;
			}

			case 4:
			{
				head1->freeLists(head1);
				head2->freeLists(head2);
				exit(0);
			}

			default:
			{
				cout<<"\nWrong choice, try again!\n"; 
			}  
		}
	}

	return 0;
}

//insertion in sorted manner
LinkedLists *LinkedLists::insertSortList(LinkedLists *head,int value)
{
	if (head == NULL)
	{
		head = new LinkedLists();
		head->data = value;
		head->next = NULL;
	}
	else
	{
		LinkedLists *newNode = new LinkedLists();
	    newNode->data = value;
	    newNode->next = NULL;

		LinkedLists *prevNode = NULL, *tmpNode = head;
		while(1)
		{
			if (tmpNode->data == newNode->data)
			{
				cout<< " !!! Number already exists in the list !!!"<<endl;
				break;
			}
			else if (newNode->data < tmpNode->data)
			{
				if (prevNode == NULL)
				{
					newNode->next = head;
					head = newNode;
					prevNode = head;
				}
				else
				{
					prevNode->next = newNode;
					newNode->next = tmpNode;
					prevNode = prevNode->next;
				}
				break;
			}
			else if (newNode->data > tmpNode->data && tmpNode->next == NULL)
			{
				tmpNode->next = newNode;
				tmpNode = tmpNode->next;
				break;
			}
			else
			{
				prevNode = tmpNode;
				tmpNode = tmpNode->next;
			}
		}
	}

	return head;
}

void LinkedLists::displayList(LinkedLists *tmp)
{
	while(tmp)
	{
		cout<<"->"<< tmp->data;
        tmp = tmp->next;
	}
}

void LinkedLists::freeLists(LinkedLists *head)
{
	LinkedLists* cur = head;
    while (cur != nullptr) {
        LinkedLists* next = cur->next;
        delete cur;
        cur = next;
    }
}