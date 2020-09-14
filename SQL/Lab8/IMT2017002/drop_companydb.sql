-- drop companydb.sql

alter table employee
    drop FOREIGN KEY fk_super_ssn,
    drop FOREIGN KEY fk_Dno;

alter table department
    drop FOREIGN KEY fk_mgr_ssn;

alter table dept_locations
    drop FOREIGN KEY fk_dnumber;

alter table project
    drop FOREIGN KEY fk_dnum;

alter table works_on
    drop FOREIGN KEY fk_works_on_essn,
    drop FOREIGN KEY fk_pno;

alter table dependent
    drop FOREIGN KEY fk_dependent_essn;

drop table employee;
drop table department;
drop table dept_locations;
drop table project;
drop table works_on;
drop table dependent;
