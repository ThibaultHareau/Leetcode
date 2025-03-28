CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
WITH RankedSalaries AS (  
    SELECT DISTINCT salary,  
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rankk  
    FROM Employee  
)  
SELECT (SELECT salary  AS  NthHighestSalary 
FROM RankedSalaries  
WHERE rankk = N) AS NthHighestSalary
  );
END