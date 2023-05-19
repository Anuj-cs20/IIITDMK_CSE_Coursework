#include<iostream>
using namespace std;

class Area
{
private:
	float length,breadth,radius;

public:
	friend float rectangleArea(Area& ,float Length,float Breadth);
	friend float circleArea(Area& ,float Radius);
};

inline float rectangleArea(Area& area,float Length = 1,float Breadth = 1)
{
	area.length = Length;
	area.breadth = Breadth;
	return (area.length)*(area.breadth);
}

inline float circleArea(Area& area,float Radius = 1)
{
	area.radius = Radius;
	return (area.radius)*(area.radius)*3.14;
}

class Volume
{
private:
	float radius,height,area;

public:
    float cuboidVolume(float Area,float Height);
	float sphereVolume(float Area,float Radius); 
	bool compareCuboidVolume(Volume& V2,Area& R1,Area& R2,float L1,float B1,float H1,float L2,float B2,float H2);
	bool compareSphereVolume(Volume& V2,Area& C1,Area& C2,float R1,float R2);
};

inline float Volume::cuboidVolume(float Area,float Height = 1)
{
    this->height = Height;
	this->area = Area;
    return (this->area)*(this->height);
}

inline float Volume::sphereVolume(float Area,float Radius = 1)
{
	this->radius = Radius;
	this->area = Area;
    return ((this->radius)*(this->area)*4)/3;
}

bool Volume::compareCuboidVolume(Volume& V2,Area& R1,Area& R2,float L1,float B1,float H1,float L2,float B2,float H2)
{
	return this->cuboidVolume(rectangleArea(R1,L1,B1),H1) > V2.cuboidVolume(rectangleArea(R1,L2,B2),H2);
}

bool Volume::compareSphereVolume(Volume& V2,Area& C1,Area& C2,float R1,float R2)
{
	return this->sphereVolume(circleArea(C1,R1),R1) > V2.sphereVolume(circleArea(C2,R2),R2);
}

int main()
{
	Area Rectangle,Circle;
	Area Rectangle1,Circle1;
	
	Volume Cuboid,Sphere;
	Volume Cuboid1,Sphere1;

	float Length,Height,Breadth,Radius;
	float Length1,Height1,Breadth1,Radius1;

	int choice;
	while(1)
	{
		cout<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"1.Area of rectangle"<<endl;
		cout<<"2.Area of circle"<<endl;
		cout<<"3.Unit area of rectangle"<<endl;
        cout<<"4.Unit area of circle"<<endl;
        cout<<"5.Volume of cuboid"<<endl;
        cout<<"6.Volume of sphere"<<endl;
        cout<<"7.Unit volume of cuboid"<<endl;
        cout<<"8.Unit volume of sphere"<<endl;
        cout<<"9.Compare volume of two cuboids"<<endl;
        cout<<"10.Compare volume of two spheres."<<endl;

        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
			case 0:
        	
        		exit(0);
        	
        	case 1:
        	    cout<<"\nEnter Length of the Rectangle: ";
				cin>>Length;
				cout<<"Enter Breadth of the Rectangle: ";
				cin>>Breadth;

                cout<<"\nArea of a Rectangle is "<<rectangleArea(Rectangle,Length,Breadth)<<endl;
        		break;
        	
        	case 2:
			    cout<<"\nEnter Radius of the Circle: ";
				cin>>Radius;

                cout<<"\nArea of a Circle is "<<circleArea(Circle,Radius)<<endl;
        	    break;

        	case 3:
                cout<<"\nArea of a Unit Rectangle is "<<rectangleArea(Rectangle)<<endl;
        	    break;
           
        	case 4:
                cout<<"\nArea of a Unit Circle is "<<circleArea(Circle)<<endl;
        	    break;
            case 5:
                cout<<"\nEnter Length of the Cuboid: ";
				cin>>Length;
				cout<<"Enter Breadth of the Cuboid: ";
				cin>>Breadth;
				cout<<"Enter Height of the Cuboid: ";
                cin>>Height;
                
				cout<<"\nVolume of a Cuboid is ";
                cout<<Cuboid.cuboidVolume(rectangleArea(Rectangle,Length,Breadth),Height)<<endl;
        	    break;

        	case 6:
                cout<<"\nEnter Radius of the Sphere: ";
				cin>>Radius;
                
				cout<<"\nVolume of a Sphere is ";
                cout<<Sphere.sphereVolume(circleArea(Circle,Radius),Radius)<<endl;
        	    break;

        	case 7:
                cout<<"\nVolume of a Cuboid is ";
                cout<<Cuboid.cuboidVolume(rectangleArea(Rectangle))<<endl;
        	    break;

        	case 8:
                cout<<"\nVolume of a Sphere is ";
                cout<<Sphere.sphereVolume(circleArea(Circle))<<endl;
        	    break;

        	case 9:
                cout<<"\nEnter Length of the Cuboid-1: ";
				cin>>Length;
				cout<<"Enter Breadth of the Cuboid-1: ";
				cin>>Breadth;
				cout<<"Enter Height of the Cuboid-1: ";
                cin>>Height;

				cout<<"\nEnter Length of the Cuboid-2: ";
				cin>>Length1;
				cout<<"Enter Breadth of the Cuboid-2: ";
				cin>>Breadth1;
				cout<<"Enter Height of the Cuboid-2: ";
                cin>>Height1;

                if(Cuboid.compareCuboidVolume(Cuboid1,Rectangle,Rectangle1,Length,Breadth,Height,Length1,Breadth1,Height1))
				{
                    cout << "\nCuboid-2 is smaller than Cuboid-1" <<endl;
                }
				else
				{
                    cout << "\nCuboid-2 is equal to or larger than Cuboid-1" <<endl;
                }
        	    break;

        	case 10:
                cout<<"\nEnter Radius of the Sphere-1: ";
				cin>>Radius;

				cout<<"\nEnter Radius of the Sphere-2: ";
				cin>>Radius1;

                if(Sphere.compareSphereVolume(Sphere1,Circle,Circle1,Radius,Radius1))
				{
                    cout << "\nSphere-2 is smaller than Sphere1" <<endl;
                }
				else
				{
                    cout << "\nSphere-2 is equal to or larger than Sphere-1" <<endl;
                }
        	    break;

            default:
            cout<<"wrong choice,try again!"<<endl;
        }
	}
	return 0;
}