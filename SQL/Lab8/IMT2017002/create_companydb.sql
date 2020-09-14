-- create_companydb.sql
-- Create DDL for companydb
drop database companydb;
create database companydb;
use companydb;

-- CREATE TABLE script goes below

create table employee(
    Fname varchar(30),
    Minit varchar(30),
    Lname varchar(30),
    SSN integer,
    Bdate date,
    Address varchar(75),
    Sex varchar(1),
    Salary integer,
    Super_ssn integer,
    Dno integer,
    constraint pk_employee PRIMARY KEY (SSN)
);

create table department(
    dname varchar(30),
    dnumber integer,
    Mgr_ssn integer,
    Mgr_start_date date,
    constraint pk_department PRIMARY KEY (dnumber)
);

create table dept_locations(
    dnumber integer,
    dlocation varchar(30),
    constraint pk_dept_locations PRIMARY KEY (dnumber,dlocation)
);

create table project(
    pname varchar(30),
    pnumber integer,
    plocation varchar(75),
    dnum integer,
    constraint pk_project PRIMARY KEY (pnumber)
);

create table works_on(
    essn integer,
    pno integer,
    hours integer,
    constraint pk_works_on PRIMARY KEY (essn, pno)
);

create table dependent(
    essn integer,
    dependent_name varchar(30),
    sex varchar(1),
    bdate date,
    relationship varchar(30),
    constraint pk_dependent PRIMARY KEY (essn, dependent_name)
);






