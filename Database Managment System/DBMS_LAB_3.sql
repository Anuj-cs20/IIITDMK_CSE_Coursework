drop database dblab1;
-- Creating a database named dblab1 and using it
CREATE DATABASE dblab1;
SHOW databases;
USE dblab1; 

-- creating tables named as "Students","Course" and "Enrolled" 
CREATE TABLE Student( 
RollNo char (8) NOT NULL UNIQUE,
SName varchar (20) NOT NULL,
Gender char (1) NOT NULL, 
City varchar(20) NOT NULL,
PRIMARY KEY (RollNo));

CREATE TABLE Course(
CCode char(5) NOT NULL UNIQUE, 
CName varchar(20) NOT NULL, 
Credit smallint NOT NULL,
PRIMARY KEY (CCode));

CREATE TABLE Enrolled(
RollNo char(8) NOT NULL , 
CCode char(5) NOT NULL , 
YoE int NOT NULL,
FOREIGN KEY (RollNo) REFERENCES Student(RollNo),
FOREIGN KEY (CCode) REFERENCES Course(CCode));

SHOW tables;

INSERT INTO Student VALUE('2018CS01','Olivia','F','Delhi');
INSERT INTO Student VALUE('2018CS02','Liam','M','Mumbai');
INSERT INTO Student VALUE('2018ME01','Noa','F','Mumbai');
INSERT INTO Student VALUE('2019CS11','Emma','F','Delhi');
INSERT INTO Student VALUE('2019ME11','Oliver','M','Delhi');
INSERT INTO Student VALUE('2019EC11','Aalyiah','F','Hyderabad');
INSERT INTO Student VALUE('2020CS21','Aashik','M','Hyderabad');
INSERT INTO Student VALUE('2020EC22','Anuj','M','Chennai');
INSERT INTO Student VALUE('2020ME21','Samantha','F','Chennai');
INSERT INTO Student VALUE('2021CS31','Sony','F','Kolkata');

INSERT INTO Course VALUE('CS101','Data Structures',4);
INSERT INTO Course VALUE('CS302','Algorithms',5);
INSERT INTO Course VALUE('CS503','Computation',3);
INSERT INTO Course VALUE('EC403','Digital Circuits',4);
INSERT INTO Course VALUE('EC507','Computer Arch.',3);
INSERT INTO Course VALUE('ME603','Mechatronics',5);
INSERT INTO Course VALUE('ME702','Mechanics',3);

INSERT INTO Enrolled VALUE('2018CS01','CS101',2018);
INSERT INTO Enrolled VALUE('2018CS01','ME702',2018);
INSERT INTO Enrolled VALUE('2018CS01','CS302',2019);
INSERT INTO Enrolled VALUE('2018CS01','CS503',2020);
INSERT INTO Enrolled VALUE('2018CS01','ME702',2020);
INSERT INTO Enrolled VALUE('2018CS02','CS101',2018);
INSERT INTO Enrolled VALUE('2018CS02','ME702',2018);
INSERT INTO Enrolled VALUE('2018CS02','CS302',2019);
INSERT INTO Enrolled VALUE('2018CS02','CS503',2020);
INSERT INTO Enrolled VALUE('2018CS02','ME702',2020);
INSERT INTO Enrolled VALUE('2018ME01','CS101',2018);
INSERT INTO Enrolled VALUE('2018ME01','ME603',2019);
INSERT INTO Enrolled VALUE('2018ME01','ME702',2020);
INSERT INTO Enrolled VALUE('2019CS11','CS302',2019);
INSERT INTO Enrolled VALUE('2019CS11','CS503',2020);
INSERT INTO Enrolled VALUE('2019CS11','EC507',2020);
INSERT INTO Enrolled VALUE('2019ME11','CS302',2019);
INSERT INTO Enrolled VALUE('2019ME11','ME702',2020);
INSERT INTO Enrolled VALUE('2019ME11','EC507',2020);
INSERT INTO Enrolled VALUE('2019EC11','EC403',2019);
INSERT INTO Enrolled VALUE('2019EC11','EC507',2020);
INSERT INTO Enrolled VALUE('2019EC11','CS101',2020);
INSERT INTO Enrolled VALUE('2020CS21','CS302',2020);
INSERT INTO Enrolled VALUE('2020CS21','ME702',2020);
INSERT INTO Enrolled VALUE('2020EC22','EC403',2020);
INSERT INTO Enrolled VALUE('2020EC22','CS503',2020);
INSERT INTO Enrolled VALUE('2020ME21','ME603',2020);
INSERT INTO Enrolled VALUE('2020ME21','ME702',2020);
INSERT INTO Enrolled VALUE('2021CS31','CS302',2020);
INSERT INTO Enrolled VALUE('2021CS31','EC403',2020);
INSERT INTO Enrolled VALUE('2021CS31','CS503',2020);
INSERT INTO Enrolled VALUE('2021CS31','ME603',2020);
INSERT INTO Enrolled VALUE('2021CS31','ME702',2020);

SELECT* FROM Student;
SELECT* FROM Course;
SELECT* FROM Enrolled;

ALTER TABLE Course
ADD CType VARCHAR(20) NOT NULL;

ALTER TABLE Student
ADD Email VARCHAR(30) UNIQUE;

UPDATE Student SET Email='Olivia@iiitdm.ac.in' WHERE RollNo='2018CS01';
UPDATE Student SET Email='Liam@iiitdm.ac.in' WHERE RollNo='2018CS02';
UPDATE Student SET Email='Noa@yahoo.com' WHERE RollNo='2018ME01';
UPDATE Student SET Email='Emma@yahoo.com' WHERE RollNo='2019CS11';
UPDATE Student SET Email='Oliver@yahoo.com' WHERE RollNo='2019ME11';
UPDATE Student SET Email='Aalyiah@yahoo.com' WHERE RollNo='2019EC11';
UPDATE Student SET Email='Aashik@yahoo.com' WHERE RollNo='2020CS21';
UPDATE Student SET Email='Anuj@gmail.com' WHERE RollNo='2020EC22';
UPDATE Student SET Email='Samantha@gmail.com' WHERE RollNo='2020ME21';
UPDATE Student SET Email='Sony@gmail.com' WHERE RollNo='2021CS31';

UPDATE Course SET CType='Open Elective' WHERE CCode='CS101';
UPDATE Course SET CType='Core' WHERE CCode='CS302';
UPDATE Course SET CType='Elective' WHERE CCode='CS503';
UPDATE Course SET CType='Core' WHERE CCode='EC403';
UPDATE Course SET CType='Elective' WHERE CCode='EC507';
UPDATE Course SET CType='Core' WHERE CCode='ME603';
UPDATE Course SET CType='Open Elective' WHERE CCode='ME702';

SELECT* FROM Student;
SELECT* FROM Course;

-- Name of all the courses which start with “CS” code.
SELECT CName FROM Course WHERE CCode LIKE 'CS___';

-- Name of the male students who have at least two “a”s in their names.
SELECT SName FROM Student WHERE Gender='M' and SName LIKE '%a%a%';

-- Students who have not enrolled in between 2018 and 2019.
SELECT distinct Student.SName FROM Student,Enrolled WHERE not YoE=2018 and not YoE=2019;

-- Course with least credit.
SELECT CName FROM Course WHERE Credit=3;



-- Name of the Course which is not enrolled by any students in the year 2020.
SELECT distinct Course.CName FROM Course JOIN Enrolled WHERE Enrolled.YoE != 2020;

-- Total number of students city wise.
SELECT City,count(*) as CNT FROM student group by city;

-- Rollno of the students who have enrolled to 5 number of courses.
SELECT RollNo FROM enrolled group by RollNo having count(RollNo)=5;

-- Total number of courses enrolled by student with roll no “2018CS02”.
SELECT count(*) as 'number of courses enrolled are ' FROM enrolled WHERE RollNo = '2018CS02';

-- The 5 level courses (the digits parts of the course code should start with 5).
SELECT * FROM course WHERE CCode like '__5__';

-- Count of number of students containing “CS” as part of the RollNo.
SELECT count(*) as 'number of CS students' FROM student WHERE RollNo like '%CS%';

-- Roll no of students who have enrolled in more than 4 courses in the year 2020.
SELECT RollNo FROM enrolled WHERE YoE = 2020 GROUP BY RollNo HAVING count(RollNo)>=4;

-- Course code which is taken by most number of female students who are from Delhi city
SELECT CCode FROM enrolled WHERE RollNo in (select RollNo from student where gender = 'F' and city = 'Delhi') group by CCode order by count(*) desc limit 1;

-- Name of all the students whose email ids have “gmail.com” or “yahoo.com” as the domain name.
SELECT SName FROM Student WHERE Email like '%yahoo.com' or Email like '%gmail.com';