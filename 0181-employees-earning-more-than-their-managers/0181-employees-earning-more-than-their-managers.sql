# Write your MySQL query statement below
SELECT name AS Employee
FROM Employee
INNER JOIN (SELECT salary AS managerSalary, id FROM Employee) AS Manager
ON Employee.managerId = Manager.id
WHERE Employee.salary > Manager.managerSalary;
