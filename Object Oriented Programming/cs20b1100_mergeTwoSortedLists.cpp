#include<iostream>
using namespace std;

class LinkedLists
{
private:
	int data;
    LinkedLists *next;
public:
    LinkedLists *insertSortList(LinkedLists *head,int value);
    LinkedLists *removeNumberFromPosition(LinkedLists *head,int position);
    void displayList(LinkedLists *tmp);
    LinkedLists *merge2Lists(LinkedLists *head,LinkedLists *list1,LinkedLists *list2);
    void freeLists(LinkedLists *head);
  
};

int main()
{
	LinkedLists *head1,*head2,*head3; 
	int choice,num;

	while(1)
	{
		cout<<"\n";
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Merge"<<endl;
		cout<<"5. Exit"<<endl;
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
				cout<<"\n";
				cout<<"1. Delete from List 1"<<endl;
				cout<<"2. Delete from List 2"<<endl;
				cout<<"Enter your choice: ";
                cin>>choice;

                cout<<"\nEnter position which you want to delete: ";
				cin>>num;

                if (choice == 1)
                {
                	head1 = head1->removeNumberFromPosition(head1,num);
                }
                else
                {
                	head2 = head2->removeNumberFromPosition(head2,num);
                }
                break;
			}

			case 3:
			{
				cout<<"\nList1 ";
				head1->displayList(head1);
				cout<<"\nList2 ";
				head2->displayList(head2);
				cout<<"\nMerged Sorted List ";
				head3->displayList(head3);
				cout<<"\n";
				break;
			}

			case 4:
			{
				head3 = head3->merge2Lists(head3,head1,head2);
				cout<<"\nMerged Sorted List ";
				head3->displayList(head3);
				cout<<"\n";
				break;
			}

			case 5:
			{
				head1->freeLists(head1);
				head2->freeLists(head2);
				head3->freeLists(head3);
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

//deletion of an element
LinkedLists *LinkedLists::removeNumberFromPosition(LinkedLists *head,int position)
{
	LinkedLists *prevNode = NULL,*tmpNode = head;
	if (head == NULL)
	{
		cout<< " !!!! Empty list !!!!"<<endl;
	}
	else if (position == 1)
	{
		head = head->next;
        delete tmpNode;
	}
	else
	{
		for (int i = 1; i < position; ++i)
		{
			prevNode = tmpNode;
			tmpNode = tmpNode->next;

			if (tmpNode == NULL)
			{
				cout<< " !!! Position doesn't exists in the list !!!"<<endl;
				break;
			}
		}

		if (tmpNode != NULL && tmpNode->next != NULL)
		{
			prevNode->next = tmpNode->next;
			tmpNode->next = NULL;
			delete tmpNode;
		}
		else
		{
			prevNode->next = NULL;
			delete tmpNode;
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

//merge list 1 and list 2 into new sorted list 3
LinkedLists *LinkedLists::merge2Lists(LinkedLists *head, LinkedLists *list1,LinkedLists *list2)
{
	while(list1)
	{
		head = head->insertSortList(head,list1->data);
        list1 = list1->next;
	}

	while(list2)
	{
		head = head->insertSortList(head,list2->data);
        list2 = list2->next;
	}

	return head;
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