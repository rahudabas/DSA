# Write your MySQL query statement below
with cte as(select customer_id from Visits V left join Transactions T on V.visit_id=T.visit_id where transaction_id is NULL)
select customer_id,count(customer_id) as count_no_trans from cte group by customer_id 
