-- create_companydb.sql

drop database companydb;
create database companydb;
use companydb;

-- Script for CREATE TABLE

create table EMPLOYEE(
    Minit varchar(30),
    Fname varchar(30),
    Lname varchar(30),
    Ssn integer,
    Bdate date,
    Address varchar(75),
    Sex varchar(1),
    Salary integer,
    Super_ssn integer,
    Dno integer,
    constraint pk_employee PRIMARY KEY (Ssn)
);

create table DEPARTMENT(
    Dname varchar(30),
    Dnumber integer,
    Mgr_ssn integer,
    Mgr_start_date date,
    constraint pk_department PRIMARY KEY (Dnumber)
);

create table DEPT_LOCATION(
    Dnumber integer,
    Dlocation varchar(30),
    constraint pk_dept_locations PRIMARY KEY (Dnumber,Dlocation)
);

create table WORKS_ON(
    Essn integer,
    Pno integer,
    Hours float,
    constraint pk_works_on PRIMARY KEY (Essn,Pno)
);

create table PROJECT(
    Pname varchar(30),
    Pnumber integer,
    Plocation varchar(75),
    Dnum integer,
    constraint pk_project PRIMARY KEY (Pnumber)
);

create table DEPENDENT(
    Essn integer,
    Dependent_name varchar(30),
    Sex varchar(1),
    Bdate date,
    Relationship varchar(30),
    constraint pk_dependent PRIMARY KEY (Essn,Dependent_name)
);