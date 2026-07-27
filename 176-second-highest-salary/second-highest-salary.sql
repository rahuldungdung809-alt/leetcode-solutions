# Write your MySQL query statement below
/*OPTIMAL SOLUTION*/
SELECT MAX(salary) AS SecondHighestSalary 
FROM(
    SELECT salary,
      DENSE_RANK() OVER
       (ORDER BY salary DESC) as Rnk
    FROM Employee)t 
WHERE Rnk=2;

/* BETTER SOLUTION*/
/*SELECT( SELECT DISTINCT salary 
FROM Employee
ORDER BY salary DESC 
LIMIT 1 OFFSET 1)AS SecondHighestSalary;*/


/*SELECT MAX(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT MAX(salary)
               FROM Employee);*/
