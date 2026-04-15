# Write your MySQL query statement below
select e.name , un.unique_id from Employees e
left join EmployeeUNI un 
 on e.id = un.id