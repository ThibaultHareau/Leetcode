# Write your MySQL query statement below
WITH RankedSalaries AS (  
    SELECT DISTINCT salary,  
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rankk  
    FROM Employee  
)  
SELECT (SELECT salary  AS  SecondHighestSalary 
FROM RankedSalaries  
WHERE rankk = 2) AS SecondHighestSalary;  