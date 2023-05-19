/*
    Roll No. : cs20b1100
    Name     : K.Anuj
    Ex No.   : 7
    Topic    : Inheritance - Hierarchical
    Date     : 09-09-2021
*/

#include <iostream>
using namespace std;

//base class
class Account
{
public:
	double balance;
	int accNumber;
	// constructor
	Account(int accNo, double bal = 0.0)
	{
		if (bal >= 0.0)
		{
			this->balance = bal;
		}
		else
		{
			this->balance = 0.0;
			cout << "invalid initial balance" << endl;
		}
		this->accNumber = accNo;
	}

	void credit(double amount)
	{
		this->balance += amount;
	}

	bool debit(double amount)
	{
		if (amount > this->balance)
		{
			cout << "Debit amount exceeded account balance." << endl;
			return false;
		}
		else
		{
			this->balance -= amount;
			cout << "Debited ammount successfully" << endl;
			return true;
		}
	}

	double getBalance()
	{
		return this->balance;
	}
};

//subclass or derived class
class savingsAccount : public Account
{
public:
	double interestRate, IntrestAmount;
	savingsAccount *next;

	//constructor for a derived class
	savingsAccount(double IR, int accNo, double bal) : Account(accNo, bal)
	{
		if (IR >= 0.0)
		{
			this->interestRate = IR;
		}
		else
		{
			this->interestRate = 1;
			cout << "Interest rate must be >= 0.0" << endl;
		}
	}

	void ChangingIR(double IR)
	{
		this->interestRate = IR;
	}

	double calculateInterest()
	{
		this->IntrestAmount = (this->interestRate * getBalance()) / 100;
		return IntrestAmount;
	}

	savingsAccount *checking_sav(savingsAccount *tmpHead, int acc);

	savingsAccount *insertToList(savingsAccount *tmpHead, int value, int acc, double bal);

	void freeLists(savingsAccount *tmpHead);
};

//subclass or derived class
class checkingAccount : public Account
{
public:
	double transactionfee, totalfee;
	checkingAccount *next;

	//constructor for a derived class
	checkingAccount(double fee, int accNo, double bal) : Account(accNo, bal)
	{
		if (fee >= 0.0)
		{
			this->transactionfee = fee;
		}
		else
		{
			this->transactionfee = 0.0;
			cout << "Transaction fee must be >= 0.0" << endl;
		}

		totalfee = 0;
	}

	void ChangingTF(double fee)
	{
		this->transactionfee = fee;
	}

	void Credit(double amount)
	{
		credit(amount);
		totalfee += this->transactionfee;
	}

	bool Debit(double amount)
	{
		bool success = debit(amount);

		if (success)
		{
			totalfee += this->transactionfee;
			return true;
		}
		else
			return false;
	}

	double chargedFee()
	{
		double dummy = transactionfee;
		transactionfee = 0;
		return dummy;
	}

	checkingAccount *checking_che(checkingAccount *tmpHead, int acc);

	checkingAccount *insertToList(checkingAccount *tmpHead, int value, int acc, double bal);

	void freeLists(checkingAccount *tmpHead);
};

savingsAccount *savingsAccount::insertToList(savingsAccount *tmpHead, int value, int acc, double bal)
{
	if (tmpHead == NULL)
	{
		tmpHead = new savingsAccount(value, acc, bal);
		tmpHead->next = NULL;
	}
	else
	{
		savingsAccount *newNode = new savingsAccount(value, acc, bal);
		newNode->next = NULL;

		savingsAccount *tmpNode = tmpHead;
		while (tmpNode->next)
		{
			tmpNode = tmpNode->next;
		}

		tmpNode->next = newNode;
	}

	return tmpHead;
}

checkingAccount *checkingAccount::insertToList(checkingAccount *tmpHead, int value, int acc, double bal)
{
	if (tmpHead == NULL)
	{
		tmpHead = new checkingAccount(value, acc, bal);
		tmpHead->next = NULL;
	}
	else
	{
		checkingAccount *newNode = new checkingAccount(value, acc, bal);
		newNode->next = NULL;

		checkingAccount *tmpNode = tmpHead;
		while (tmpNode->next)
		{
			tmpNode = tmpNode->next;
		}

		tmpNode->next = newNode;
	}

	return tmpHead;
}

savingsAccount *savingsAccount::checking_sav(savingsAccount *tmpHead, int acc)
{
	if (tmpHead == NULL)
	{
		return NULL;
	}
	else
	{
		while (tmpHead)
		{
			if (tmpHead->accNumber == acc)
			{
				return tmpHead;
			}
			tmpHead = tmpHead->next;
		}
	}
	return NULL;
}

checkingAccount *checkingAccount::checking_che(checkingAccount *tmpHead, int acc)
{
	if (tmpHead == NULL)
	{
		return NULL;
	}
	else
	{
		while (tmpHead)
		{
			if (tmpHead->accNumber == acc)
			{
				return tmpHead;
			}
			tmpHead = tmpHead->next;
		}
	}
	return NULL;
}

void savingsAccount::freeLists(savingsAccount *tmpHead)
{
	savingsAccount *currentNode = tmpHead;
	while (currentNode != nullptr)
	{
		savingsAccount *next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}
}

void checkingAccount::freeLists(checkingAccount *tmpHead)
{
	checkingAccount *currentNode = tmpHead;
	while (currentNode != nullptr)
	{
		checkingAccount *next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}
}

int main()
{
	savingsAccount *sav = NULL, *tmp1;
	checkingAccount *che = NULL, *tmp2;

	int choice, acc;
	double amo, b, data2, data1, y;

	while (1)
	{
		cout << "\n\n";
		cout << "1. Open Account(Savings or Checking Account)" << endl;
		cout << "2. Credit(Savings or Checking Account)" << endl;
		cout << "3. Debit(Savings or Checking Account)" << endl;
		cout << "4. Change / Update Interest rate(Savings Account)" << endl;
		cout << "5. Calculate Interest(Savings Account - Print) " << endl;
		cout << "6. Calculate and Update Interest(Savings Account - Credit)" << endl;
		cout << "7. Change / Update Fee Amount(Checking Account)" << endl;
		cout << "8. Print Checking Fee(Checking Account)" << endl;
		cout << "9. Transact and Update(Checking Account - Debit)" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nEnter NEW Account Number: ";
			cin >> acc;

			cout << "Enter inital Balance: ";
			cin >> b;
			while (1)
			{
				cout << "1.Creating Savings Account" << endl;
				cout << "2.Creating checking Account" << endl;
				cout << "3.Exit" << endl;
				cout << "Enter your choice: ";
				cin >> choice;
				if (choice == 3)
				{
					break;
				}

				switch (choice)
				{
				case 1:
					if (sav->checking_sav(sav, acc))
					{
						cout << "!!!!! Account already exists !!!!!" << endl;
						break;
					}
					cout << "\n------- Creating Savings Account --------" << endl;
					cout << "Enter Intrest Rate (in %): ";
					cin >> data1;
					cout << "-----------------------------------------" << endl;

					sav = sav->insertToList(sav, data1, acc, b);
					break;

				case 2:
					if (che->checking_che(che, acc))
					{
						cout << "!!!!! Account already exists !!!!!" << endl;
						break;
					}

					cout << "\n------- Creating Checking Account --------" << endl;
					cout << "Enter Transation Fee (per transaction): ";
					cin >> data2;
					cout << "--------------------------------------------" << endl;

					che = che->insertToList(che, data2, acc, b);
					break;
				case 3:

					break;

				default:
					cout << "!! Wrong in-put try again !!" << endl;
					break;
				}
			}

			break;

		case 2:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			cout << "Enter Amount you want to CREDIT: ";
			cin >> amo;

			while (1)
			{
				cout << "1.Savings Account" << endl;
				cout << "2.checking Account" << endl;
				cout << "3.Exit" << endl;
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					if (sav->checking_sav(sav, acc))
					{
						tmp1 = sav->checking_sav(sav, acc);
						tmp1->credit(amo);
						cout << "Successfully creditted" << endl;
					}
					else
					{
						cout << "!!!!! Account dosen't exists !!!!!" << endl;
					}
					break;

				case 2:
					if (che->checking_che(che, acc))
					{
						tmp2 = che->checking_che(che, acc);
						tmp2->Credit(amo);
						cout << "Successfully creditted" << endl;
					}
					else
					{
						cout << "!!!!! Account dosen't exists !!!!!" << endl;
					}
					break;
				case 3:

					break;

				default:
					cout << "!! Wrong in-put try again !!" << endl;
					break;
				}
				break;
			}

			break;

		case 3:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			cout << "Enter Amount: ";
			cin >> amo;

			while (1)
			{
				cout << "1.Savings Account" << endl;
				cout << "2.checking Account" << endl;
				cout << "3.Exit" << endl;
				cout << "Enter your choice: ";
				cin >> choice;

				switch (choice)
				{
				case 1:
					if (sav->checking_sav(sav, acc))
					{
						tmp1 = sav->checking_sav(sav, acc);
						tmp1->debit(amo);
					}
					else
					{
						cout << "!!!!! Account dosen't exists !!!!!" << endl;
					}
					break;

				case 2:
					if (che->checking_che(che, acc))
					{
						tmp2 = che->checking_che(che, acc);
						tmp2->Debit(amo);
					}
					else
					{
						cout << "!!!!! Account dosen't exists !!!!!" << endl;
					}
					break;
				case 3:
					break;

				default:
					cout << "!! Wrong in-put try again !!" << endl;
					break;
				}
				break;
			}

			break;

		case 4:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			cout << "Enter Intrest Rate to Change: ";
			cin >> data1;

			if (sav->checking_sav(sav, acc))
			{
				tmp1 = sav->checking_sav(sav, acc);
				tmp1->ChangingIR(data1);
				cout << "Successfully changed Intrest rate" << endl;
			}
			else
			{
				cout << "!!!!! Account dosen't exists !!!!!" << endl;
			}
			break;

		case 5:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			if (sav->checking_sav(sav, acc))
			{
				tmp1 = sav->checking_sav(sav, acc);
				cout << "\n---------------------------------------------------------------------" << endl;
				cout << "Your Account Number: " << acc << endl;
				cout << "Calculated intrest Amount: $" << tmp1->calculateInterest() << endl;
				cout << "---------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "!!!!! Account dosen't exists !!!!!" << endl;
			}

			break;

		case 6:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			if (sav->checking_sav(sav, acc))
			{
				tmp1 = sav->checking_sav(sav, acc);
				cout << "\n---------------------------------------------------------------------" << endl;
				cout << "Your Account Number: " << acc << endl;
				cout << "Current Balance: $" << tmp1->getBalance() << endl;
				cout << "Calculated intrest Amount: $" << tmp1->calculateInterest() << endl;
				tmp1->credit(tmp1->calculateInterest());
				cout << "After Crediting Intrest Amount" << endl;
				cout << "Total Balance: $" << tmp1->getBalance() << endl;
				cout << "---------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "!!!!! Account dosen't exists !!!!!" << endl;
			}

			break;

		case 7:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			cout << "Enter Transation Fee to Update: ";
			cin >> data2;

			if (che->checking_che(che, acc))
			{
				tmp2 = che->checking_che(che, acc);
				tmp2->ChangingTF(data2);
				cout << "Successfully changed Transaction fee" << endl;
			}
			else
			{
				cout << "!!!!! Account dosen't exists !!!!!" << endl;
			}

			break;

		case 8:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			if (che->checking_che(che, acc))
			{
				tmp2 = che->checking_che(che, acc);
				cout << "\n---------------------------------------------------------------------" << endl;
				cout << "Your Account Number: " << acc << endl;
				cout << "Transaction fee is: $" << tmp2->chargedFee() << endl;
				cout << "---------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "!!!!! Account dosen't exists !!!!!" << endl;
			}

			break;

		case 9:
			cout << "\nEnter Account Number: ";
			cin >> acc;

			if (che->checking_che(che, acc))
			{
				tmp2 = che->checking_che(che, acc);
				cout << "\n---------------------------------------------------------------------" << endl;
				cout << "Your Account Number: " << acc << endl;
				cout << "Current Balance: $" << tmp2->getBalance() << endl;
				cout << "Calculated Transaction Amount: $" << tmp2->totalfee << endl;
				tmp2->debit(tmp2->chargedFee());
				cout << "After Debiting transaction Amount" << endl;
				cout << "Total Balance: $" << tmp2->getBalance() << endl;
				cout << "---------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << "!!!!! Account dosen't exists !!!!!" << endl;
			}

			break;

		case 10:
			sav->freeLists(sav);
			cout << "\nSuccessfully cleared Linked list of savings account........." << endl;
			che->freeLists(che);
			cout << "\nSuccessfully cleared Linked list of checking account........." << endl;
			cout << "\nEXITING THE CODE........." << endl;
			exit(0);

		default:
			cout << "!! Wrong in-put try again !!" << endl;
			break;
		}
	}

	return 0;
}