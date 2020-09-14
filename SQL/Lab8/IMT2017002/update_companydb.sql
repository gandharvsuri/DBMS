-- Update companydb.sql

-- Update employee
update employee set super_ssn = 333445555 where ssn = 123456789;
update employee set super_ssn = 999887777 where ssn = 333445555;
update employee set super_ssn = 123456789 where ssn = 999887777;

-- Update department
update department set mgr_ssn = 333445555 where dnumber = 5; 
update department set mgr_ssn = 123456789 where dnumber = 4; 
update department set mgr_ssn = 999887777 where dnumber = 1; 

-- Update dept_locations 
    -- primary key is same as the foreign key
-- Update project
update project set dnum = 5 where pnumber in(1, 2, 3);

-- Update works_on
    -- primary key is same as the foreign key

-- Update dependent
    -- primary key is same as the foreign key
