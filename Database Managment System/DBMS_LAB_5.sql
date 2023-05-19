-- drop database dblab5;
create database dblab5;
show databases; 
use dblab5;

create table Orders(
ORD_NUM varchar(10) not null ,
ORD_AMOUNT varchar(10) not null ,
ADVANCE_AMOUNT varchar(10) not null, 
ORD_DATE varchar(20) not null,
CUST_CODE varchar(10) not null,
AGENT_CODE varchar(10) not null,
ORD_DESCRIPTION varchar(30));

create table Agent(
AGENT_CODE varchar(10) not null , 
AGENT_NAME varchar(20) not null, 
WORKING_AREA varchar(20) not null,
COMMISSION varchar(5) not null, 
PHONE_NO varchar(20) not null, 
COUNTRY varchar(20)); 

show tables;
describe table Orders;
describe table Agent;

insert into Orders value
('004','200','3000','15-aug-2020','C004','Ac001','Masala kulcha'),
('007','600','5000','17-sept-2020','C006','Ac003','Biriyani');
insert into Orders(ORD_NUM, ORD_AMOUNT, ADVANCE_AMOUNT, ORD_DATE,CUST_CODE,AGENT_CODE )
value('008','700','100','19-feb-2019','C007','Ac005');
insert into Orders 
value ('009','10000','600','21-march-2010','C009','Ac008','Masala dosa');
insert into Orders(ORD_NUM, ORD_AMOUNT, ADVANCE_AMOUNT, ORD_DATE,CUST_CODE,AGENT_CODE )
value('010','20','600','21-april-2012','C006','Ac005');

insert into Agent value
('Ac001','Ramesh','Bangalore','.15','0331234567','India');
insert into Agent(AGENT_CODE, AGENT_NAME, WORKING_AREA ,COMMISSION , PHONE_NO)
value('Ac002','Dinesh','Bangalore','.25','0331234568');
insert into Agent 
value ('Ac003','Suresh','Mumbai','.35','0331234569','London');
insert into Agent(AGENT_CODE, AGENT_NAME, WORKING_AREA ,COMMISSION , PHONE_NO)
value('Ac004','Kamlesh','New jersey','.68','0331234564');
insert into Agent 
value ('Ac005','Kartik','Chenni','.73','0331234563','India');

select * from Orders;
select * from Agent;

-- Find ord_num, ord_amount, ord_date, cust_code and agent_code 
-- from the table Orders working_area of Agent table must be Bangalore.
select ORD_NUM,ORD_AMOUNT,ORD_DATE,CUST_CODE,AGENT_CODE
from Orders 
where AGENT_CODE in (
select AGENT_CODE 
from Agent 
where WORKING_AREA='Bangalore'); 

-- Retrive ord_num, ord_amount, cust_code and agent_code 
-- from the table orders 
-- where the agent_code of orders table must be the same agent_code of agents table 
-- and agent_name of agents table must be Ramesh.
select ORD_NUM,ORD_AMOUNT,CUST_CODE,AGENT_CODE
from Orders 
where AGENT_CODE in (
select AGENT_CODE 
from Agent 
where AGENT_NAME='Ramesh');



drop database dblab5;
create database dblab5;
show databases; 
use dblab5;

create table salesman(
salesman_id varchar(20) not null ,
name varchar(20) not null,
city varchar(20) not null,
commission varchar(5) not null);

create table Orders(
ord_no int not null, 
purch_amt int not null, 
ord_date varchar(20) not null, 
customer_id varchar(20) not null, 
salesman_id varchar(20));

show tables;
describe table salesman;
describe table Orders;

insert into salesman value
('si123@06','Lakshmi','Kolkata','.5'),
('si123@09','Ganesh','London','.6'),
('si123@90','Dinesh','London','.3'),
('si123@10','Joseph','Chennai','.6'),
('si123@19','Mahesh','Hyderabad','.65'),
('si123@26','Paul Adam','London','.1'),
('si123@67','Rahul','Delhi','.4');

insert into Orders value
(123,600,'20-aug-2010','003cd','si123@19'),
(576,750,'20-feb-2018','004cd','si123@19'),
(579,800,'20-may-2012','004cd','si123@26'),
(600,60000,'20-jan-2021','006cd','si123@10'),
(700,745,'26-jan-2021','007cd','si123@09'),
(800,860,'29-jan-2019','007cd','si123@26');

-- Display all the orders from the orders table 
-- issued by the salesman 'Paul Adam'.
select *
from Orders
where salesman_id in(
select salesman_id
from salesman
where name='Paul Adam');

-- Display all the orders for the salesman 
-- who belongs to the city London
select *
from Orders
where salesman_id in(
select salesman_id
from salesman
where city='London');
 
