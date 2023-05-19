/*
    Roll No. : cs20b1100
    Name     : K.Anuj
*/

#include <iostream>
using namespace std;

//base class
class twoDShape
{
protected:
    float xdim, ydim;

public:
    void setDimensions(float x, float y)
    {
        if (x > 0)
        {
            this->xdim = x;
        }
        else
        {
            cout << "Entered value is '< 0'. So, value is 1(default)" << endl;
            this->xdim = 1.0;
        }

        if (y > 0)
        {
            this->ydim = y;
        }
        else
        {
            cout << "Entered value is '< 0'. So, value is 1(default)" << endl;
            this->ydim = 1.0;
        }
    }

    void getDimensions()
    {
        cout << xdim << "," << ydim << endl;
    }
};

//subclass derived from twoDShape with protected mode
class Triangle : protected twoDShape
{
public:
    void calculateArea()
    {
        cout << xdim * ydim * 0.5 << endl;
    }
};

//subclass derived from twoDShape with protected mode
class Rectangle : protected twoDShape
{
public:
    void calculateArea()
    {
        cout << xdim * ydim << endl;
    }
};

//subclass derived from twoDShape with protected mode
class Square : protected twoDShape
{
public:
    void calculateArea()
    {
        cout << xdim * ydim << endl;
    }
};

int main()
{
    float x, y;
    twoDShape t;
    Triangle T;
    twoDShape *ptr1 = &T;
    Rectangle R;
    twoDShape *ptr2 = &R;
    Square S;
    twoDShape *ptr3 = &S;

    int choice;
    while (1)
    {
        cout << "\n\n";
        cout << "The MENU is as follows: " << endl;
        cout << "1. Set Dimensions" << endl;
        cout << "2. Get Dimensions" << endl;
        cout << "3. Calcualte Area of the Triangle" << endl;
        cout << "4. Calculate Area of the Rectangle" << endl;
        cout << "5. Calculate Area of the Square " << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << " \nEnter Base length of a Triangle: ";
            cin >> x;
            cout << "Enter Height length of a Triangle: ";
            cin >> y;
            ptr1->setDimensions(x, y);

            break;

        case 2:
            cout << " \nBase and Height of the Triangle are: ";
            ptr1->getDimensions();

            break;

        case 3:
            cout << "Area of Triangle is: ";

            ptr1->calculateArea();
            break;

        case 4:
            cout << "Area of Rectangle is: ";
            ptr1->calculateArea();
            break;

        case 5:
            cout << "Area of Square is: ";
            ptr1->calculateArea();
            break;

        case 6:
            exit(0);

        default:
            cout << "!! Wrong in-put try again !!" << endl;
            break;
        }
    }

    return 0;
}