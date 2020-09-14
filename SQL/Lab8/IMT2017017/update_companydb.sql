-- update_companydb.sql

-- Update EMPLOYEE
    -- if ssn =123456789 then super_ssn = 333445555
update EMPLOYEE set Super_ssn = 333445555 where Ssn = 123456789; 
update EMPLOYEE set Super_ssn = 999887777 where Ssn = 333445555;
update EMPLOYEE set Super_ssn = 123456789 where Ssn = 999887777;

-- Update DEPARTMENT
update DEPARTMENT set Mgr_ssn = 333445555 where Dnumber = 5; 
update DEPARTMENT set Mgr_ssn = 123456789 where Dnumber = 4; 
update DEPARTMENT set Mgr_ssn = 999887777 where Dnumber = 1; 

-- Update DEPT_LOCATION
    -- PK same as FK

-- Update PROJECT
update PROJECT set dnum = 5 where pnumber in(1, 2, 3); -- #SHORTCUT

-- Update WORKS_ON
    -- PK same as FK

-- Update DEPENDENT
    -- PK same as FK