# Write your MySQL query statement below
select name,bonus from Employee E left join Bonus B on B.empID=E.empID
where B.bonus is null or B.bonus<1000
