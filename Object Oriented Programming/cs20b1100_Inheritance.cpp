/*

    Roll No. : cs20b1100
    Name     : K.Anuj
    Ex No.   : 8
    Topic    : Inheritance - Private, Public, and Protected + Multilevel and Hierarchical
    Date     : 16-09-2021

*/

#include <iostream>
#include <string>
using namespace std;

//Base class
class Employee
{
protected:
    // employee_ID and employee_name are protected data members.
    string employee_name;
    int employee_ID;
};

// Contract class is derived from Employee in protected mode
class Contract : protected Employee
{
protected:
    //pay_per_hour is protected data member.
    float pay_per_hour;

public:
    // setPay and getPay are public member functions.
    void setPay(float pph)
    {
        if (pph > 0.0)
        {
            this->pay_per_hour = pph;
        }
        else
        {
            this->pay_per_hour = 2;
            cout << "\nAs Pay per hour entered value is invalied(< $0)";
            cout << "\nWe set Pay per hour to Default Amount($2)" << endl;
        }
    }

    inline float getPay()
    {
        return this->pay_per_hour;
    }
};

// Salaried class is are derived from Employee in protected mode
class Salaried : protected Employee
{
protected:
    // monthlyPay is protected data member.
    float monthlyPay;

public:
    // setPay and getPay are public member functions.
    void setPay(float mP)
    {
        if (mP > 0.0)
        {
            this->monthlyPay = mP;
        }
        else
        {
            this->monthlyPay = 200;
            cout << "\nAs Monthly Pay entered value is invalied(< $0)";
            cout << "\nWe set Monthly Pay to Default Amount($200)" << endl;
        }
    }

    inline float getPay()
    {
        return this->monthlyPay;
    }
};

// Manager is derived from Salaried in private mode.
class Manager : private Salaried
{
private:
    Manager *next;

public:
    // setDetails, getDetails, calculateSalary, and setSalary are public member functions.
    // setDetails updates employee_ID, employee_name, monthlyPay
    void setDetails(int eID, string eN, float mP)
    {
        this->employee_ID = eID;
        this->employee_name = eN;
        setPay(mP);
    }

    // getDetails prints the values stored in these member functions.
    void getDetails()
    {
        cout << "\nEmployee ID: " << this->employee_ID << endl;
        cout << "Employee Name: " << this->employee_name << endl;
        cout << "Salary: $" << getPay() << " (per month)" << endl;
    }

    // calculateSalary gets the number of working months and prints the total salary for the number of months the manager has worked.
    void calculateSalary(float months)
    {
        cout << "Salary: $" << getPay() * months << endl;
    }

    // setSalary updates the salary of the manager.
    void setSalary(float mP)
    {
        setPay(mP);
    }

    // Creating Linked list to store Employees data
    Manager *insertToList(Manager *tmpHead, int eID, string eN, float mP);

    // Checking whether Employee already exists or not
    Manager *checking_man(Manager *tmpHead, int eID);

    // Deleting the List
    void freeLists(Manager *tmpHead);
};

// Intern is derived from Contract in private mode.
class Intern : private Contract
{
private:
    Intern *next;

public:
    // setDetails, getDetails, calculateSalary, and setSalary are public member functions.
    // setDetails updates employee_ID, employee_name, hourlyPay.
    void setDetails(int eID, string eN, float pph)
    {
        this->employee_ID = eID;
        this->employee_name = eN;
        setPay(pph);
    }

    // getDetails prints the values stored in these member functions.
    void getDetails()
    {
        cout << "\nEmployee ID: " << this->employee_ID << endl;
        cout << "Employee Name: " << this->employee_name << endl;
        cout << "Salary: $" << getPay() << " (per hour)" << endl;
    }

    // setSalary updates the salary of the intern.
    void setSalary(float pph)
    {
        setPay(pph);
    }

    // calculateSalary gets the number of working hours and prints the total salary for the number of hours the intern has worked.
    void calculateSalary(float hours)
    {
        cout << "Salary: $" << getPay() * hours << endl;
    }

    // Creating Linked list to store Employees data
    Intern *insertToList(Intern *tmpHead, int eID, string eN, float pph);

    // Checking whether Employee already exists or not
    Intern *checking_intr(Intern *tmpHead, int eID);

    // Deleting the List
    void freeLists(Intern *tmpHead);
};

Intern *Intern::insertToList(Intern *tmpHead, int eID, string eN, float pph)
{
    if (tmpHead == NULL)
    {
        tmpHead = new Intern();
        tmpHead->employee_ID = eID;
        tmpHead->employee_name = eN;
        tmpHead->setPay(pph);
        tmpHead->next = NULL;
    }
    else
    {
        Intern *newNode = new Intern();
        newNode->employee_ID = eID;
        newNode->employee_name = eN;
        newNode->setPay(pph);
        newNode->next = NULL;

        Intern *tmpNode = tmpHead;
        while (tmpNode->next)
        {
            tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;
    }

    return tmpHead;
}

Intern *Intern::checking_intr(Intern *tmpHead, int eID)
{
    if (tmpHead == NULL)
    {
        return NULL;
    }
    else
    {
        while (tmpHead)
        {
            if (tmpHead->employee_ID == eID)
            {
                return tmpHead;
            }
            tmpHead = tmpHead->next;
        }
    }
    return NULL;
}

void Intern::freeLists(Intern *tmpHead)
{
    Intern *currentNode = tmpHead;
    while (currentNode != nullptr)
    {
        Intern *next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }
    cout << "\n";
}

Manager *Manager::insertToList(Manager *tmpHead, int eID, string eN, float mP)
{
    if (tmpHead == NULL)
    {
        tmpHead = new Manager();
        tmpHead->employee_ID = eID;
        tmpHead->employee_name = eN;
        tmpHead->setPay(mP);
        tmpHead->next = NULL;
    }
    else
    {
        Manager *newNode = new Manager();
        newNode->employee_ID = eID;
        newNode->employee_name = eN;
        newNode->setPay(mP);
        newNode->next = NULL;

        Manager *tmpNode = tmpHead;
        while (tmpNode->next)
        {
            tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;
    }

    return tmpHead;
}

Manager *Manager::checking_man(Manager *tmpHead, int eID)
{
    if (tmpHead == NULL)
    {
        return NULL;
    }
    else
    {
        while (tmpHead)
        {
            if (tmpHead->employee_ID == eID)
            {
                return tmpHead;
            }
            tmpHead = tmpHead->next;
        }
    }
    return NULL;
}

void Manager::freeLists(Manager *tmpHead)
{
    Manager *currentNode = tmpHead;
    while (currentNode != nullptr)
    {
        Manager *next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }
    cout << "\n";
}

int main()
{
    Manager *man = NULL, *tmp1;
    Intern *intr = NULL, *tmp2;

    string name;
    float mPA, ppH, m, h;
    int choice, id;
    while (1)
    {
        cout << "\n\n";
        cout << "1. Create Employee (Manager or Intern)" << endl;
        cout << "2. Update Employee Details (Manager or Intern)" << endl;
        cout << "3. Print Employee Details (Manager or Intern)" << endl;
        cout << "4. Update Pay (Manager or Intern)" << endl;
        cout << "5. Calculate Salary (Manager or Intern)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n";
            cout << "1. Create NEW Manager Employee Account" << endl;
            cout << "2. Create NEW Intern Employee Account" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\n--------- Creating Manager Account --------\n\n";
                cout << "\nEnter NEW Employee ID: ";
                cin >> id;

                if (man->checking_man(man, id))
                {
                    cout << "!!!!! Employee already exists !!!!!" << endl;
                    break;
                }

                cout << "Enter NEW Employee Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Monthly Pay Amount: $";
                cin >> mPA;
                man = man->insertToList(man, id, name, mPA);
                cout << "\n----------- Successfully Created ----------" << endl;
                break;

            case 2:
                cout << "\n--------- Creating Intern Account --------\n\n";
                cout << "\nEnter NEW Employee ID: ";
                cin >> id;
                if (intr->checking_intr(intr, id))
                {
                    cout << "!!!!! Employee already exists !!!!!" << endl;
                    break;
                }

                cout << "Enter NEW Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Pay per Hour Amount: $";
                cin >> ppH;
                intr = intr->insertToList(intr, id, name, ppH);
                cout << "\n----------- Successfully Created ----------" << endl;
                break;

            default:
                cout << "!! Wrong in-put try again !!" << endl;
                break;
            }
            break;

        case 2:
            cout << "\n";
            cout << "1. Update Manager Employee Details" << endl;
            cout << "2. Update Intern Employee Details" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "\nEnter Employee ID: ";
            cin >> id;

            switch (choice)
            {
            case 1:
                if (man->checking_man(man, id))
                {
                    tmp1 = man->checking_man(man, id);
                    cout << "\n------- Updating Manager Account --------\n\n";
                    cout << "Enter NEW Employee ID: ";
                    cin >> id;

                    if (man->checking_man(man, id))
                    {
                        cout << "!!!!! Employee already exists !!!!!" << endl;
                        break;
                    }

                    cout << "Enter NEW Employee Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter NEW Monthly Pay Amount: $";
                    cin >> mPA;

                    tmp1->setDetails(id, name, mPA);
                    cout << "\n--------- Successfully Updated -----------" << endl;
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            case 2:
                if (intr->checking_intr(intr, id))
                {
                    tmp2 = intr->checking_intr(intr, id);
                    cout << "\n--------- Updating Intern Account --------\n\n";
                    cout << "Enter NEW Employee ID: ";
                    cin >> id;
                    //
                    if (intr->checking_intr(intr, id))
                    {
                        cout << "!!!!! Employee already exists !!!!!" << endl;
                        break;
                    }

                    cout << "Enter NEW Employee Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter NEW Pay per Hour Amount: $";
                    cin >> ppH;

                    tmp2->setDetails(id, name, ppH);
                    cout << "\n---------- Successfully Updated ----------" << endl;
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            default:
                cout << "!! Wrong in-put try again !!" << endl;
                break;
            }
            break;

        case 3:
            cout << "\n";
            cout << "1. Print Manager Employee Details" << endl;
            cout << "2. Print Intern Employee Details" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "\nEnter Employee ID: ";
            cin >> id;

            switch (choice)
            {
            case 1:
                if (man->checking_man(man, id))
                {
                    tmp1 = man->checking_man(man, id);
                    cout << "\n------ Manager Employee Details -------\n\n";
                    tmp1->getDetails();
                    cout << "\n--------------------------------------\n";
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            case 2:
                if (intr->checking_intr(intr, id))
                {
                    tmp2 = intr->checking_intr(intr, id);
                    cout << "\n------ Intern Employee Details -------\n\n";
                    tmp2->getDetails();
                    cout << "\n--------------------------------------\n";
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            default:
                cout << "!! Wrong in-put try again !!" << endl;
                break;
            }
            break;

        case 4:
            cout << "\n";
            cout << "1. Update Pay for Manager Employee" << endl;
            cout << "2. Update Pay for Intern Employee" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "\nEnter Employee ID: ";
            cin >> id;

            switch (choice)
            {
            case 1:
                if (man->checking_man(man, id))
                {
                    tmp1 = man->checking_man(man, id);
                    cout << "\n------- Updating Manager Employee Pay --------\n\n";
                    cout << "Enter NEW Monthly Pay Amount: $";
                    cin >> mPA;
                    tmp1->setSalary(mPA);
                    cout << "\n------------Successfully Updated-------------" << endl;
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            case 2:
                if (intr->checking_intr(intr, id))
                {
                    tmp2 = intr->checking_intr(intr, id);
                    cout << "\n------- Updating Intern Employee Pay --------\n\n";
                    cout << "Enter NEW Pay per Hour Amount: $";
                    cin >> ppH;
                    tmp2->setSalary(ppH);
                    cout << "\n------------Successfully Updated-------------" << endl;
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            default:
                cout << "!! Wrong in-put try again !!" << endl;
                break;
            }
            break;

        case 5:
            cout << "\n";
            cout << "1. Calculate Salary of Manager Employee" << endl;
            cout << "2. Calculate Salary of Intern Employee" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "\nEnter Employee ID: ";
            cin >> id;

            switch (choice)
            {
            case 1:
                if (man->checking_man(man, id))
                {
                    tmp1 = man->checking_man(man, id);
                    cout << "\n----------- Manager Employee Salary -------------\n\n";
                    cout << "Enter Number of Months to calculate Salary: ";
                    cin >> m;
                    tmp1->calculateSalary(m);
                    cout << "\n-------------------------------------------------" << endl;
                }
                else
                {
                    cout << "!!!!! Account dosen't exists !!!!!" << endl;
                }
                break;

            case 2:
                if (intr->checking_intr(intr, id))
                {
                    tmp2 = intr->checking_intr(intr, id);
                    cout << "\n------------ Intern Employee Salary ------------\n\n";
                    cout << "Enter Number of Hours to calculate Salary: ";
                    cin >> h;
                    tmp2->calculateSalary(h);
                    cout << "\n------------------------------------------------" << endl;
                }
                else
                {
                    cout << "!!!!! Employee dosen't exists !!!!!" << endl;
                }
                break;

            default:
                cout << "!! Wrong in-put try again !!" << endl;
                break;
            }
            break;

        case 6:
            man->freeLists(man);
            cout << "\nSuccessfully cleared Manager list........." << endl;
            intr->freeLists(intr);
            cout << "\nSuccessfully cleared Intern list........." << endl;
            cout << "\nEXITING THE CODE.........\n\n";
            exit(0);

        default:
            cout << "!! Wrong in-put try again !!" << endl;
            break;
        }
    }
    return 0;
}