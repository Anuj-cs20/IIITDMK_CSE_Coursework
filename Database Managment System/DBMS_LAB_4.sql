-- drop database dblab4;
create database dblab4;
show databases; 
use dblab4;

 create table STUDENTACCOUNT(
 id int(1) not null unique,
 Person_Name varchar(20) not null,
 Department varchar(5) not null,
 Birth date not null);
 
 show tables;
 describe table STUDENTACCOUNT;
 
 insert into STUDENTACCOUNT value
 (1,'Ramesh','Cs','2001-01-12'),
 (2,'suresh','IT','2020-02-20'),
 (3,'Jomin','CS','1996-02-29'),
 (4,'Shree','IT','2012-12-18'),
 (5,'Hemanth','CS','2022-02-07');

-- StudentAccount Table 
select * 
from STUDENTACCOUNT;

-- The age in years and month of each of the person_Name working in department CS.
select 
id,
Person_Name,
Department,
concat
(
	floor((timestampdiff(month, Birth, CURDATE()) / 12)), ' Years ',
	mod(timestampdiff(month, Birth, CURDATE()), 12) , ' Months'
) as age
from STUDENTACCOUNT
where Department='Cs' ;

-- Retrieve name having alphabet 'S'.
select *
from STUDENTACCOUNT
where Person_Name like '%s%';  

-- Name of students containing exactly five characters.
select *
from STUDENTACCOUNT
where Person_Name like '_____';

-- Alternate rows from table.
select * 
from STUDENTACCOUNT
where mod(id,2) = 1;



create table Employees(
Employee_id int(1) not null unique,
First_name varchar(20) not null,
Last_name varchar(20) not null,
Salary int(10) not null,
Joining_date date not null,
Departement varchar(20) not null);

 show tables;
 describe table Employees;
 
insert into Employees value
(1, 'Boby', 'Rathod', 1000000, '2020-12-20', 'Finance'),
(2, 'Jasmin', 'Jose', 6000000, '2015-02-07','IT'),
(3, 'Pratap', 'Mathew', 8900000, '2014-03-09', 'Banking'),
(4, 'John', 'Michel', 2000000, '1999-03-17', 'Insurance'),
(5, 'Alex', 'Kinto', 2200000, '1987-02-25', 'Finance'),
(6, 'Jaswanth', 'Kumar', 1230000, '2021-07-23', 'IT');

-- Employees Table
select *
from Employees;

-- Employees with a salary between 2,000,000 and 5,000,000.
select *
from Employees
where Salary between 2000000 and 5000000;

-- The Last_name about employees with work experience more than three years whose first_name contain the alphabet ‘a’.
select Last_name
from Employees
where timestampdiff(year,Joining_date,curdate()) > 3 and First_name like '%a%';

-- Joining_date of employees working in IT department having salary more than average salary of company.
select Joining_date
from Employees
where Departement='IT' and Salary > (select avg(Salary) from Employees);

-- The details of employees working in Finance department having salary less than average salary of IT department.
select *
from Employees
where Departement='Finance' and Salary < (select avg(Salary) from Employees where Departement='IT');

