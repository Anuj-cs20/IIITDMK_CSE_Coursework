/*

    Roll No. : cs20b1100
    Name     : K.Anuj
    Ex No.   : 10.1
    Topic    : Functions Templates and Exception Handling

*/

#include <iostream>
#include <string>
#include <exception>
using namespace std;

#define FT_YEL "\x1B[0;33m"
#define FT_B_RED "\x1B[1;31m"
#define FT_GRN "\x1B[0;32m"
#define FT_B_YEL "\x1B[1;33m"
#define FT_B_WHT "\x1B[1;36m"
#define FT_WHT "\x1B[1;37m"
#define FT_NRM "\x1B[0m"

//Functions Templates
template <typename T>
void swap(T *xp, T *yp)
{
    T temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Functions Templates
template <typename U>
void selectionSort(U arr[], int n)
{
    int min_idx;

    for (size_t i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (size_t j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap<U>(&arr[min_idx], &arr[i]);
    }
}

//Functions Templates
template <typename V>
void printArray(V arr[], int size)
{
    for (size_t i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}

// Exception Handling
double check()
{
    double opc;
    bool aux = true;
    cin.exceptions(std::istream::failbit);
    do
    {
        try
        {
            cout << FT_GRN << "(INPUT): ";
            cin >> opc;
            aux = true;
        }
        catch (std::ios_base::failure &fail)
        {
            aux = false;
            cout << FT_B_RED << "PLEASE ENTER A VALID INPUT.\n\n";

            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
    } while (aux == false);

    return opc;
}

int main()
{
    int choice, size;

    while (1)
    {
        cout << FT_B_RED << "\n******* SELECTION SORT *********" << endl;
        cout << FT_B_YEL << "\t Main - MENU" << endl;
        cout << FT_YEL << "1. Integers input array" << endl;
        cout << FT_YEL << "2. Rational numbers input array" << endl;
        cout << FT_YEL << "3. Character/String input array " << endl;
        cout << FT_YEL << "4. Exit" << endl;
        cout << FT_GRN << "Enter your choice ";
        choice = check();

        if (choice == 4)
        {
            cout << FT_B_RED << "\nEXITING THE CODE.........\n\n"
                 << FT_NRM;
            exit(0);
        }

        while (1)
        {
            cout << FT_WHT << "\n\nEnter input SIZE of array ";
            size = check();

            if (size <= 0)
            {
                cout << FT_B_RED << "PLEASE ENTER A VALID INPUT.\n";
            }
            else
            {
                break;
            }
        }

        long long int arr1[size];
        double arr2[size];
        string arr3[size];
        for (size_t i = 0; i < size; i++)
        {
            arr1[i] = 0;
            arr2[i] = 0.0;
        }

        switch (choice)
        {
        case 1:

            while (1)
            {
                cout << FT_B_YEL << "\n\n\tSUB - MENU" << endl;
                cout << FT_YEL << "1. Get Values" << endl;
                cout << FT_YEL << "2. Sort" << endl;
                cout << FT_YEL << "3. Display" << endl;
                cout << FT_YEL << "4. Exit" << endl;
                cout << FT_GRN << "Enter your choice ";
                choice = check();

                if (choice == 4)
                {
                    break;
                }

                switch (choice)
                {
                case 1:
                    cout << endl;
                    for (size_t i = 0; i < size; i++)
                    {
                        cout << FT_GRN << "Enter element-" << i + 1;
                        arr1[i] = check();
                    }
                    break;

                case 2:
                    selectionSort<long long int>(arr1, size);
                    cout << FT_B_RED << "Successfully Sorted" << endl;
                    break;

                case 3:
                    cout << FT_B_WHT << "\nArray: ";
                    printArray<long long int>(arr1, size);
                    break;

                default:
                    cout << FT_B_RED << "Enter proper input" << endl;
                    break;
                }
            }
            break;

        case 2:

            while (1)
            {
                cout << FT_B_YEL << "\n\n\tSUB - MENU" << endl;
                cout << FT_YEL << "1. Get Values" << endl;
                cout << FT_YEL << "2. Sort" << endl;
                cout << FT_YEL << "3. Display" << endl;
                cout << FT_YEL << "4. Exit" << endl;
                cout << FT_GRN << "Enter your choice ";
                choice = check();

                if (choice == 4)
                {
                    break;
                }

                switch (choice)
                {
                case 1:
                    cout << endl;
                    for (size_t i = 0; i < size; i++)
                    {
                        cout << FT_GRN << "Enter element-" << i + 1;
                        arr2[i] = check();
                    }
                    break;

                case 2:
                    selectionSort<double>(arr2, size);
                    cout << FT_B_RED << "Successfully Sorted" << endl;
                    break;

                case 3:
                    cout << FT_B_WHT << "\nArray: ";
                    printArray<double>(arr2, size);
                    break;

                default:
                    cout << FT_B_RED << "Enter proper input" << endl;
                    break;
                }
            }
            break;

        case 3:

            while (1)
            {
                cout << FT_B_YEL << "\n\n\tSUB - MENU" << endl;
                cout << FT_YEL << "1. Get Values" << endl;
                cout << FT_YEL << "2. Sort" << endl;
                cout << FT_YEL << "3. Display" << endl;
                cout << FT_YEL << "4. Exit" << endl;
                cout << FT_GRN << "Enter your choice ";
                choice = check();

                if (choice == 4)
                {
                    break;
                }

                switch (choice)
                {
                case 1:
                    cout << endl;
                    for (size_t i = 0; i < size; i++)
                    {
                        cout << FT_GRN << "Enter array element-" << i + 1 << ": ";
                        cin >> arr3[i];
                    }
                    break;

                case 2:
                    selectionSort<string>(arr3, size);
                    cout << FT_B_RED << "Successfully Sorted" << endl;
                    break;

                case 3:
                    cout << FT_B_WHT << "\nArray: ";
                    printArray<string>(arr3, size);
                    break;

                default:
                    cout << FT_B_RED << "Enter proper input" << endl;
                    break;
                }
            }
            break;

        default:
            cout << FT_B_RED << "Wrong input Try again" << endl;
            break;
        }
    }

    return 0;
}