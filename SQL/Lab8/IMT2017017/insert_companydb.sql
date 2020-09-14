-- insert_companydb.sql

insert into EMPLOYEE
values
    ('John', "B", "Smith", 123456789, "1965-01-09", "731 Fondren, Houston, TX", "M", 30000, NULL, NULL),
    ("Franklin", "T", "Wong", 333445555, "1955-12-08", "638 Voss, Houston, TX", "M", 40000, NULL, NULL),
    ("Alicia", "J", "Zelaya", 999887777, "1968-01-19", "3321 Castle, Spring, TX", "F", 25000, NULL, NULL);  

insert into DEPARTMENT
values
    ("Research", 5, NULL, "1988-05-22"),
    ("Administration", 4, NULL, "1995-01-01"),
    ("Headquarters", 1, NULL, "1981-06-19");

insert into DEPT_LOCATION
values
    (1, "Houston"),
    (4, "Stafford"),
    (5, "Bellaire");
    
insert into PROJECT
values
    ("ProductX", 1, "Bellaire", NULL),
    ("ProductY", 2, "Sugarland", NULL),
    ("ProductZ", 3, "Houston", NULL);

insert into WORKS_ON
values
    (123456789, 1, 32.5),
    (123456789, 2, 07.5),
    (333445555, 3, 40.0);


insert into DEPENDENT
values
    (333445555, "Alice", "F", "1986-04-05", "Daughter"),
    (333445555, "Theodore", "M", "1983-10-25", "Son"),
    (333445555, "Joy", "F", "1958-05-03", "Spouse");
