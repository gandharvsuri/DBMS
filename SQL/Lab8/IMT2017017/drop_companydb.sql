-- drop_companydb.sql

-- Drop all foreign keys and later tables

alter table EMPLOYEE
    drop FOREIGN KEY fk_super_ssn,
    drop FOREIGN KEY fk_dno;

alter table DEPARTMENT
    drop FOREIGN KEY fk_mgr_ssn;

alter table DEPT_LOCATION
    drop FOREIGN KEY fk_dnumber;

alter table WORKS_ON
    drop FOREIGN KEY fk_workson_essn,
    drop FOREIGN KEY fk_workson_dno;

alter table PROJECT
    drop FOREIGN KEY fk_dnum;

alter table DEPENDENT
    drop FOREIGN KEY fk_dependent_essn;

drop table EMPLOYEE;
drop table DEPARTMENT;
drop table DEPT_LOCATION;
drop table PROJECT;
drop table WORKS_ON;
drop table DEPENDENT;

