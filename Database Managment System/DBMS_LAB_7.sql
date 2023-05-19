drop database lab7;
create database lab7;
use lab7;

create table Bank(
Bank_name varchar(20),
State varchar(30));

create table Account_holder(
Account_name varchar(20),
Bank_name varchar(20),
State_name varchar(20));

describe Bank;
describe Account_holder;

insert into Bank value
('SBI','Andhra Pradesh'),
('SBI','Tamilnadu'),
('SBI','Karnataka'),
('ICICI','TamilNadu'),
('ICICI','Karnataka');

insert into Account_holder value
('Ramesh','ICICI','TamilNadu'),
('Dinesh','SBI','Andhra Pradesh'),
('Robert','SBI','Tamilnadu'),
('Robert','ICICI','Karnataka'),
('Robert','SBI','Andhra Pradesh'),
('Karthik','SBI','Andhra Pradesh');

select * from Bank;
select * from Account_holder;

-- The Account_name having account in all banks.
CREATE TABLE All_Account_names
AS SELECT DISTINCT
Account_name FROM
Account_holder;

select * from All_Account_names;

CREATE table Accountandrequired AS 
SELECT DISTINCT Account_holder.Account_name, Bank.Bank_name
FROM Account_holder, Bank;

select * from Accountandrequired;

CREATE table AccountsAndNotTaken AS
SELECT * FROM Accountandrequired WHERE NOT EXISTS
(Select * FROM Account_holder 
WHERE Accountandrequired.Bank_name = Account_holder.Bank_name
AND Accountandrequired.Account_name = Account_holder.Account_name);

select * from AccountsAndNotTaken;

CREATE table NotHavingAllAcc AS 
SELECT DISTINCT Account_name
FROM AccountsAndNotTaken;

select * from NotHavingAllAcc; 

CREATE Table HaveAllAcc AS 
SELECT * FROM All_Account_names
WHERE NOT EXISTS
(SELECT * FROM NotHavingAllAcc 
WHERE NotHavingAllAcc.Account_name = All_Account_names.Account_name);

select * from HaveAllAcc;

drop table All_Account_names;
drop table Accountandrequired;
drop table AccountsAndNotTaken;
drop table NotHavingAllAcc;

-- The bank available in all state.
CREATE TABLE All_Bank_names
AS SELECT DISTINCT Bank_name
FROM Bank;

select * from All_Bank_names;

CREATE TABLE All_States
AS SELECT DISTINCT State
FROM Bank;

select * from All_States;

CREATE table BanksAndStatesRequired AS
SELECT All_Bank_names.Bank_name, All_States.State
FROM All_Bank_names,  All_States;

select * from BanksAndStatesRequired;

CREATE table BanksNotinStates AS
SELECT * FROM BanksAndStatesRequired WHERE NOT EXISTS
(Select * FROM Bank WHERE BanksAndStatesRequired.Bank_name = Bank.Bank_name
AND BanksAndStatesRequired.State = Bank.State);

select * from BanksNotinStates;

CREATE table BanksNamesNotinStates 
AS SELECT DISTINCT Bank_name
FROM BanksNotinStates;

-- The bank not available in all the state.
select * from BanksNamesNotinStates;

CREATE Table BanksNamesinStates AS 
SELECT * FROM All_Bank_names
WHERE NOT EXISTS
(SELECT * FROM BanksNamesNotinStates 
WHERE BanksNamesNotinStates.Bank_name = All_Bank_names.Bank_name);

select * from BanksNamesinStates;

drop table All_Bank_names;
drop table All_States;
drop table BanksAndStatesRequired;
drop table BanksNotinStates;


-- The Account_name having account in all the state.
CREATE TABLE All_Account_names
AS SELECT DISTINCT Account_name 
FROM Account_holder;

-- select * from All_Account_names;

CREATE table AccountandrequiredStates AS 
SELECT DISTINCT Account_holder.Account_name, Bank.State
FROM Account_holder, Bank;

-- select * from AccountandrequiredStates;

CREATE table AccountsAndNotTaken AS
SELECT * FROM AccountandrequiredStates WHERE NOT EXISTS
(Select * FROM Account_holder 
WHERE AccountandrequiredStates.State = Account_holder.State_name
AND AccountandrequiredStates.Account_name = Account_holder.Account_name);

-- select * from AccountsAndNotTaken;

CREATE table NotHavingAllBanks AS 
SELECT DISTINCT Account_name
FROM AccountsAndNotTaken;

-- select * from NotHavingAllBanks;

CREATE Table HaveAccinAllStates AS 
SELECT * FROM All_Account_names
WHERE NOT EXISTS
(SELECT * FROM NotHavingAllBanks
WHERE NotHavingAllBanks.Account_name = All_Account_names.Account_name);

select * from HaveAccinAllStates; 

drop table All_Account_names;
drop table AccountandrequiredStates;
drop table AccountsAndNotTaken;
drop table NotHavingAllBanks;