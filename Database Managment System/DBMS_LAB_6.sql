drop database dblab6;
create database dblab6;
-- show databases; 
use dblab6;

create table IIITDM(
Faculty_name varchar(20),
Student_Id varchar(20), 
Building_name varchar(20));

create table Faculty(
Faculty_id varchar(20),
Faculty_name varchar(20),
department varchar(20),
Subject varchar(20),
primary key (Faculty_id));

create table Student(
Student_Id varchar(20),
Student_name varchar(20), 
department varchar(20), 
course varchar(20), 
Building_name varchar(20),
primary key (Student_id));

create table Building(
Building_name varchar(20),
Room_no int,
Floor int);

create table Course(
department varchar(20), 
subject varchar(20), 
course_id varchar(20));

-- show tables;
-- describe table IIITDM;
-- describe table Faculty;
-- describe table Student;
-- describe table Building;
-- describe table Course;

insert into Faculty value
('CS001','ramesh','CSE','ToC'),
('CS002','suresh','CSE','Algorithms'),
('CS003','mukesh','CSE','DataStructure'),
('CS004','naresh','CSE','CProgramming'),
('CS005','rajesh','CSE','OOPs');

insert into Student value
('cs100','Anuj','CSE','Algorithms','block-A'),
('cs088','Sachin','CSE','Toc','block-B'),
('cs009','Ram','CSE','DataStructure','block-C'),
('cs057','Dhanush','CSE','CProgramming','block-D'),
('cs123','Harshith','CSE','Algorithms','block-E');

insert into Building value
('block-A',140,4),
('block-B',110,3),
('block-C',30,1),
('block-D',140,2),
('block-E',140,3);


insert into Course value
('CSE','Algorithms','cs201'),
('CSE','Toc','cs202'),
('CSE','DataStructure','cs203'),
('CSE','CProgramming','cs204'),
('CSE','OOPs','cs205');


-- The student_id who is learning course from a particular faculty and living in room no 30.
select Student.Student_Id, Course.subject, Faculty.Faculty_name, Building.Room_no
from Student
inner join Course on Course.subject = Student.course
inner join Faculty on Faculty.Subject = Course.subject
inner join Building on Building.Building_name = Student.Building_name
where Building.Room_no = 30;

-- The course of a student living in room no 140 in a given building.
select Course.*, Student.Student_name, Building.Building_name, Building.Room_no
from Course
inner join Student on Student.course = Course.subject
inner join Building on Building.Building_name = Student.Building_name
where Building.Room_no = 140;

-- The faculty who is not teaching subject to a particular student.
select Faculty.*,Student.Student_name as not_teaching_to
from Faculty
inner join Student on not Student.course = Faculty.Subject;

-- The course taught by the faculty to the student
-- lives in third floor of a particular building. 
select Course.subject, Faculty.Faculty_name, Student.Student_name, Building.Floor
from Course
inner join Faculty on Faculty.Subject = Course.subject
inner join Student on Student.course = Course.subject
inner join Building on Building.Building_name = Student.Building_name
where Building.Floor = 3;



