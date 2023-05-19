/*

    Roll No. : cs20b1100
    Name     : K.Anuj
    Ex No.   : 9.1
*/

#include <iostream>
#include <string>
using namespace std;

#define FT_B_RED "\x1B[1;31m"
#define FT_NRM "\x1B[0m"

template <typename T>

//base class
class person
{
protected:
    string name;
    T roll_number;

public:
    person() {}
    person(string n, T rollno)
    {
        name = n;
        roll_number = rollno;
    }
    void display()
    {
        cout << "Student Name: " << name << endl;
        cout << "Student Roll Number: " << roll_number << endl;
    }
};

//derived class from person
class student : protected virtual person<string>
{
protected:
    string course1, course2, course3;

public:
    student() {}
    student(string c1, string c2, string c3, string n, string r) : person<string>(n, r)
    {
        course1 = c1;
        course2 = c2;
        course3 = c3;
    }
    void display()
    {
        person<string>::display();
        cout << "Courses credited by the student are: " << course1 << "," << course2 << "," << course3 << "." << endl;
    }
};

//derived class from person
class research_student : protected virtual person<int>
{
protected:
    string course1, research_area;

public:
    research_student() {}
    research_student(string c1, string ra, string n, int r) : person<int>(n, r)
    {
        course1 = c1;
        research_area = ra;
    }
    void display()
    {
        person<int>::display();
        cout << "Courses credited by the student is: " << course1 << endl;
        cout << "Research area: " << research_area << endl;
    }
};

//derived class from student and research_student
class TA : protected student, protected research_student
{
protected:
    string course_assigned, role;

public:
    TA *next;
    TA(string cr, string ro, string c1, string ra, string n, int r) : research_student(c1, ra, n, r), student(), person<int>(n, r)
    {
        course_assigned = cr;
        role = ro;
    }

    TA(string cr, string ro, string c1, string c2, string c3, string n, string r) : student(c1, c2, c3, n, r), research_student(), person<string>(n, r)
    {
        course_assigned = cr;
        role = ro;
    }

    void display()
    {
        cout << "Course assigned to the TA: " << course_assigned << endl;
        cout << "Role of the TA: " << role << endl;
    }

    void display(TA *ta)
    {
        char choice1;
        TA *tmp1;
        string rl1;
        int rl, choice;
        while (1)
        {
            cout << "\n\tSUB - MENU" << endl;
            cout << "a. Person" << endl;
            cout << "b. Student" << endl;
            cout << "c. Research Student" << endl;
            cout << "d. Teaching Assistant" << endl;
            cout << "e. Exit(SUB-MENU)" << endl;
            cout << "Enter your choice: ";
            cin >> choice1;

            if (choice1 == 'e')
            {
                break;
            }

            switch (choice1)
            {
            case 'a':
                cout << "\nSelecte ROLE of person: " << endl;
                cout << "1. Student" << endl;
                cout << "2. Research Student" << endl;
                cout << "3. Exit(SUB-MENU)" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 3)
                {
                    break;
                }

                switch (choice)
                {
                case 1:
                    cout << "\nEnter Roll Number: ";
                    cin.ignore();
                    getline(cin, rl1);
                    if (ta->checking_ta(ta, rl1))
                    {
                        tmp1 = ta->checking_ta(ta, rl1);
                        cout << "\n------ Person Details -------\n\n";
                        tmp1->person<string>::display();
                        cout << "\n--------------------------------------\n";
                    }
                    else
                    {
                        cout << FT_B_RED << "!!!!! Person (student) dosen't exists !!!!!" << FT_NRM << endl;
                    }
                    break;

                case 2:
                    cout << "\nEnter again Roll Number: ";
                    cin >> rl;
                    if (ta->checking_ta(ta, rl))
                    {
                        tmp1 = ta->checking_ta(ta, rl);
                        cout << "\n------ Person Details -------\n\n";
                        tmp1->person<int>::display();
                        cout << "\n--------------------------------------\n";
                    }
                    else
                    {
                        cout << FT_B_RED << "!!!!! Person (research) dosen't exists !!!!!" << FT_NRM << endl;
                    }
                    break;

                default:
                    cout << FT_B_RED << "!! Wrong in-put try again !!" << FT_NRM << endl;
                    break;
                }

                break;

            case 'b':
                cout << "\nEnter Roll Number: ";
                cin.ignore();
                getline(cin, rl1);
                if (ta->checking_ta(ta, rl1))
                {
                    tmp1 = ta->checking_ta(ta, rl1);
                    cout << "\n------ Person Details -------\n\n";
                    tmp1->student::display();
                    cout << "\n--------------------------------------\n";
                }
                else
                {
                    cout << FT_B_RED << "!!!!! Student dosen't exists !!!!!" << FT_NRM << endl;
                }
                break;

            case 'c':
                cout << "\nEnter Roll Number: ";
                cin >> rl;
                if (ta->checking_ta(ta, rl))
                {
                    tmp1 = ta->checking_ta(ta, rl);
                    cout << "\n------ Person Details -------\n\n";
                    tmp1->research_student::display();
                    cout << "\n--------------------------------------\n";
                }
                else
                {
                    cout << FT_B_RED << "!!!!! Research Student dosen't exists !!!!!" << FT_NRM << endl;
                }
                break;

            case 'd':
                cout << "\nSelecte ROLE of TA: " << endl;
                cout << "1. Student" << endl;
                cout << "2. Research Student" << endl;
                cout << "3. Exit(SUB-MENU)" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 3)
                {
                    break;
                }

                switch (choice)
                {
                case 1:
                    cout << "\nEnter Roll Number: ";
                    cin.ignore();
                    getline(cin, rl1);
                    if (ta->checking_ta(ta, rl1))
                    {
                        tmp1 = ta->checking_ta(ta, rl1);
                        cout << "\n------ TA Details -------\n\n";
                        tmp1->person<string>::display();
                        tmp1->display();
                        cout << "\n--------------------------------------\n";
                    }
                    else
                    {
                        cout << FT_B_RED << "!!!!! TA (student) dosen't exists !!!!!" << FT_NRM << endl;
                    }
                    break;

                case 2:
                    cout << "\nEnter again Roll Number: ";
                    cin >> rl;
                    if (ta->checking_ta(ta, rl))
                    {
                        tmp1 = ta->checking_ta(ta, rl);
                        cout << "\n------ TA Details -------\n\n";
                        tmp1->person<int>::display();
                        tmp1->display();
                        cout << "\n--------------------------------------\n";
                    }
                    else
                    {
                        cout << FT_B_RED << "!!!!! TA (research) dosen't exists !!!!!" << FT_NRM << endl;
                    }
                    break;

                default:
                    cout << FT_B_RED << "!! Wrong in-put try again !!" << FT_NRM << endl;
                    break;
                }
                break;

            default:
                cout << FT_B_RED << "Enter proper input" << FT_NRM << endl;
                break;
            }
        }
    }

    TA *insertToList(TA *tmpHead, string cr, string ro, string c1, string ra, string n, int r);
    TA *insertToList(TA *tmpHead, string cr, string ro, string c1, string c2, string c3, string n, string r);

    TA *checking_ta(TA *tmpHead, string rl);
    TA *checking_ta(TA *tmpHead, int rl);

    void freeLists(TA *tmpHead);
};

TA *TA::insertToList(TA *tmpHead, string cr, string ro, string c1, string ra, string n, int r)
{
    if (tmpHead == NULL)
    {
        tmpHead = new TA(cr, ro, c1, ra, n, r);
        tmpHead->next = NULL;
    }
    else
    {
        TA *newNode = new TA(cr, ro, c1, ra, n, r);
        newNode->next = NULL;

        TA *tmpNode = tmpHead;
        while (tmpNode->next)
        {
            tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;
    }

    return tmpHead;
}

TA *TA::insertToList(TA *tmpHead, string cr, string ro, string c1, string c2, string c3, string n, string r)
{
    if (tmpHead == NULL)
    {
        tmpHead = new TA(cr, ro, c1, c2, c3, n, r);
        tmpHead->next = NULL;
    }
    else
    {
        TA *newNode = new TA(cr, ro, c1, c2, c3, n, r);
        newNode->next = NULL;

        TA *tmpNode = tmpHead;
        while (tmpNode->next)
        {
            tmpNode = tmpNode->next;
        }

        tmpNode->next = newNode;
    }

    return tmpHead;
}

TA *TA::checking_ta(TA *tmpHead, string rl)
{
    if (tmpHead == NULL)
    {
        return NULL;
    }
    else
    {
        while (tmpHead)
        {
            if (tmpHead->person<string>::roll_number == rl)
            {
                return tmpHead;
            }
            tmpHead = tmpHead->next;
        }
    }
    return NULL;
}

TA *TA::checking_ta(TA *tmpHead, int rl)
{
    if (tmpHead == NULL)
    {
        return NULL;
    }
    else
    {
        while (tmpHead)
        {
            if (tmpHead->person<int>::roll_number == rl)
            {
                return tmpHead;
            }
            tmpHead = tmpHead->next;
        }
    }
    return NULL;
}

void TA::freeLists(TA *tmpHead)
{
    TA *currentNode = tmpHead;
    while (currentNode != nullptr)
    {
        TA *next = currentNode->next;
        delete currentNode;
        currentNode = next;
    }
    cout << "\n";
}

int main()
{
    TA *ta = NULL, *tmp1;
    int choice;
    string name, rl1, ca, c1, c2, c3, ra, ro;
    int rl;
    while (1)
    {
        cout << "\n\n\tMENU" << endl;
        cout << "1. Set TA Details" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nSelecte ROLE of student: " << endl;
            cout << "1. Student" << endl;
            cout << "2. Research Student" << endl;
            cout << "3. Exit(SUB-MENU)" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 3)
            {
                break;
            }

            switch (choice)
            {
            case 1:
                cout << "\n--------- Creating Student Profile --------\n\n";
                ro = "Student";
                cout << "\nEnter NEW Student Roll Number: ";
                cin.ignore();
                getline(cin, rl1);

                if (ta->checking_ta(ta, rl1))
                {
                    cout << FT_B_RED << "!!!!! Student Profile already exists !!!!!" << FT_NRM << endl;
                    break;
                }

                cout << "Enter NEW Student Name: ";

                cin >> name;

                cout << "Courses assigned to the TA: ";

                cin >> ca;

                while (1)
                {
                    cout << "Course 1: ";
                    cin >> c1;
                    if (c1 == ca)
                    {
                        cout << "course assigned should not be equal to course1" << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                while (1)
                {
                    cout << "Course 2: ";
                    cin >> c2;

                    if (c2 == ca)
                    {
                        cout << "course assigned should not be equal to course2" << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                while (1)
                {
                    cout << "Course 3: ";
                    cin >> c3;

                    if (c3 == ca)
                    {
                        cout << "course assigned should not be equal to course3" << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                ta = ta->insertToList(ta, ca, ro, c1, c2, c3, name, rl1);

                cout << "\n----------- Successfully Created ----------" << endl;
                break;

            case 2:
                cout << "\n--------- Creating Research Student Profile --------\n\n";
                ro = "Research_Student";
                cout << "\nEnter NEW Student Roll Number: ";
                cin >> rl;

                if (ta->checking_ta(ta, rl))
                {
                    cout << FT_B_RED << "!!!!! Research Student already exists !!!!!" << FT_NRM << endl;
                    break;
                }

                cout << "Enter NEW Student Name: ";
                cin >> name;

                cout << "Courses assigned to the TA: ";
                cin >> ca;

                while (1)
                {
                    cout << "Course 1: ";
                    cin >> c1;
                    if (c1 == ca)
                    {
                        cout << "course assigned should not be equal to course1" << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                cout << "Enter Research Area: ";
                cin >> ra;

                ta = ta->insertToList(ta, ca, ro, c1, ra, name, rl);

                cout << "\n----------- Successfully Created ----------" << endl;
                break;

            default:
                cout << FT_B_RED << "!! Wrong in-put try again !!" << FT_NRM << endl;
                break;
            }
            break;

        case 2:
            ta->display(ta);
            break;

        case 3:
            ta->freeLists(ta);
            exit(0);

        default:
            cout << FT_B_RED << "Enter proper input" << FT_NRM << endl;
            break;
        }
    }

    return 0;
}