# Write your MySQL query statement below
select e.name , b.bonus from Employee e 
LEFT OUTER JOIN Bonus b
on e.empId = b.empId
where  bonus < 1000 OR bonus IS NULL