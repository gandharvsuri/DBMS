-- alter companydb.sql

alter table employee
    add constraint fk_super_ssn FOREIGN KEY(super_ssn) REFERENCES employee(ssn),
    add constraint fk_Dno FOREIGN KEY(Dno) REFERENCES department(Dnumber);

alter table department
    add constraint fk_mgr_ssn FOREIGN KEY(mgr_ssn) REFERENCES employee(ssn);

alter table dept_locations
    add constraint fk_Dnumber FOREIGN KEY(Dnumber) REFERENCES department(Dnumber);

alter table project
    add constraint fk_Dnum FOREIGN KEY(Dnum) REFERENCES department(Dnumber);
    
alter table works_on
    add constraint fk_Pno FOREIGN KEY(Pno) REFERENCES project(pnumber),
    add constraint fk_works_on_essn FOREIGN KEY(essn) REFERENCES employee(ssn);

alter table dependent
    add constraint fk_dependent_essn FOREIGN KEY(essn) REFERENCES employee(ssn);
