-- alter_comapnydb.sql

alter table EMPLOYEE
    add constraint fk_super_ssn FOREIGN KEY(Super_ssn) REFERENCES EMPLOYEE(Ssn),
    add constraint fk_dno FOREIGN KEY(Dno) REFERENCES DEPARTMENT(Dnumber);

alter table DEPARTMENT
    add constraint fk_mgr_ssn FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE(Ssn);

alter table DEPT_LOCATION
    add constraint fk_dnumber FOREIGN KEY (Dnumber) REFERENCES DEPARTMENT(Dnumber);

alter table WORKS_ON
    add constraint fk_workson_dno FOREIGN KEY (Pno) REFERENCES PROJECT(Pnumber),
    add constraint fk_workson_essn FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn);

alter table PROJECT
    add constraint fk_dnum FOREIGN KEY (Dnum) REFERENCES DEPARTMENT(Dnumber);

alter table DEPENDENT
    add constraint fk_dependent_essn FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn);
