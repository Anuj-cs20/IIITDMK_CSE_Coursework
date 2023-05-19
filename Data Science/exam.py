class Color:
    def __init__(self, f, c):
        self.is_filled = f
        if self.is_filled:
            self.color = c
        else:
            self.color = ""

    def set(self, f, c):
        self.is_filled = f
        if self.is_filled:
            self.color = c
        else:
            self.color = ""

    def get(self):
        if self.is_filled:
            print(f"Color filled is: {self.color}")
        else:
            print("No Color is filled")


class Triangle(Color):
    def __init__(self, s, f, c):
        self.side = s
        self.col = Color(f, c)

    def set(self, s, f, c):
        self.side = s
        self.col.set(f, c)

    def get(self):
        print(f"Side Length: {self.side}")
        self.col.get()

    def area(self):
        print(f"Area of a Triangle: {(1/2) * (self.side ** 2)}")

    def perimeter(self):
        print(f"Perimeter of a Triangle: {3 * self.side}")


class Rectangle(Color):
    def __init__(self, a, b, f, c):
        self.side1 = a
        self.side2 = b
        self.col = Color(f, c)

    def set(self, a, b, f, c):
        self.side1 = a
        self.side2 = b
        self.col.set(f, c)

    def get(self):
        print(f"Side1 Length: {self.side1}")
        print(f"Side2 Length: {self.side2}")
        self.col.get()

    def area(self):
        print(f"Area of a Rectangle: {self.side1 * self.side2}")

    def perimeter(self):
        print(f"Perimeter of a Rectangle: {2 * (self.side1 + self.side2)}")


class Circle(Color):
    def __init__(self, r, f, c):
        self.radius = r
        self.col = Color(f, c)

    def set(self, r, f, c):
        self.radius = r
        self.col.set(f, c)

    def get(self):
        print(f"Radius: {self.radius}")
        self.col.get()

    def area(self):
        print(f"Area of a Circle: {3.14 * (self.radius ** 2)}")

    def perimeter(self):
        print(f"Perimeter of a Circle: {2 * 3.14 * self.radius}")


class Ellipse(Color):
    def __init__(self, a, b, f, c):
        self.minor = a
        self.major = b
        self.col = Color(f, c)

    def set(self, a, b, f, c):
        self.minor = a
        self.major = b
        self.col.set(f, c)

    def get(self):
        print(f"Minor axis Length: {self.minor}")
        print(f"Major axis Length: {self.major}")
        self.col.get()

    def area(self):
        print(f"Area of a Ellipse: {3.14 * self.minor * self.major}")

    def perimeter(self):
        print(f"Perimeter of a Ellipse: {3.14 * (self.minor + self.major)}")


print("\nTriangle")
tri = Triangle(2, 0, "")
tri.get()
tri.set(3, 1, "Yellow")
tri.get()
tri.perimeter()
tri.area()

print("\nRectangle")
rec = Rectangle(2, 2, 1, "Red")
rec.get()
rec.set(3, 4, 0, "")
rec.get()
rec.perimeter()
rec.area()

print("\nCircle")
cir = Circle(2, 1, "Blue")
cir.get()
cir.set(3, 0, "")
cir.get()
cir.perimeter()
cir.area()

print("\nEllipse")
cir = Ellipse(2, 1, 0, "")
cir.get()
cir.set(3, 4, 1, "Green")
cir.get()
cir.perimeter()
cir.area()
