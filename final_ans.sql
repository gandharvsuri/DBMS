select * from employee;
select * from employee order by ssn;
select e.fname as 'first name', e.lname as 'last name' from employee as e;
select e.fname as 'first name', e.lname as 'last name' from employee as e order by e.fname;
select essn from works_on order by essn;
select distinct essn from works_on order by essn;
select distinct essn, pno from works_on order by pno;
select ssn as 'SSN', (salary/12) as 'Monthly Salary' from employee order by ssn;
select ssn as SSN, fname as 'first name', bdate as 'Date of Birth' from employee order by ssn;
select essn from works_on where pno = 2 order by essn;
select * from dependent where essn = 333445555 and sex = 'M';
select fname as 'first name' from employee where dno = 5 or dno = 1 order by fname;
select ssn, salary from employee where salary between 30000 and 50000 order by ssn;
select ssn, (salary/12) from employee where (salary/12) between 3000 and 4000 order by ssn;
select ssn from employee where super_ssn in (333445555, 987654321) order by ssn;
select ssn from employee where super_ssn not in (333445555, 987654321) order by ssn;
select pname from project where pname like "Product%" order by pname;
select ssn from employee where super_ssn is NULL order by ssn;
select essn from works_on  where pno = 20 and hours is NULL order by essn;
select ssn from employee where super_ssn is not  NULL order by ssn;
select ssn, concat(Fname,' ',Minit,' ',Lname) as 'Full name' from employee order by salary asc;
select ssn, concat(Fname,' ',Minit,' ',Lname) as 'Full name' from employee order by salary desc;
select ssn, dno, (salary/12) from employee order by dno, (salary/12) desc;
select max(salary), min(salary), count(salary), avg(salary), sum(salary) from employee;
select count(distinct pno) from works_on;
select sum(hours) from works_on;
select sum(distinct hours) from works_on;
select min(hours) from works_on;
select min(distinct hours) from works_on;
select count(*), sum(salary), avg(salary) from employee;
select sum(hours) from works_on group by pno;
select essn, count(dependent_name) from dependent group by essn;
select dno, avg(salary) from employee group by dno having avg(salary) > 35000 order by dno;
select pno from works_on group by pno having count(essn) >= 3;
select essn from works_on,project  where pname = 'ProductX' and pno = Pnumber order by essn;
select fname from employee where ssn in (select essn from works_on where hours >= 10) order by fname;
select ssn as 'Full Name' from employee where ssn in (select essn from works_on group by essn having avg(hours) >= 10) order by ssn;
select essn from works_on as w, project as p where w.pno = p.pnumber and p.pname like 'Product%' order by essn;
select fname from employee e where salary > (select avg(salary) from employee e1 where e1.dno = e.dno) order by fname;
select d.dnumber, d.dname, dl.dlocation from department d cross join dept_locations dl;
select * from employee e, dependent d, dept_locations l where e.ssn = d.essn and e.dno = l.dnumber order by ssn;
select * from employee e, works_on w, project p where e.ssn = w.essn and w.pno = p.pnumber order by e.ssn;
select * from employee e1, employee e2 where e1.ssn = e2.ssn order by e1.ssn;
select ssn,fname,dependent_name from employee e, dependent d where e.ssn = d.essn order by fname;
select ssn,fname,dependent_name from employee e left outer join dependent d on e.ssn = d.essn order by fname;
select essn , count(essn) from employee e, dependent d where e.ssn = d.essn group by ssn;
select d.essn, count(d.dependent_name) from employee e left join dependent d on e.ssn = d.essn  group by essn;
(select dlocation from dept_locations) union (select plocation from project) order by dlocation;
select dlocation from dept_locations d left join project p on d.dnumber=p.dnum where p.dnum is NULL order by d.dlocation;
select distinct dlocation from dept_locations where dlocation in (select plocation from project) order by dlocation;