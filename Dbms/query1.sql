->create table customer ( customer_id int, customer_name varchar(8), customer_city varchar(8), customer_grade varchar(2), salesman_id int, primary key(customer_id));

->create table orders( order_no int, purchase_amount int, order_date date, customer_id int, salesman_id int, foreign key(customer_id) references customer(customer_id), foreign key(salesman_id) references salesman(salesman_id) );


->insert into salesman (salesman_id,salesman_name,salesman_city,salesman_commission) values (1,'john','london',10);
->insert into customer (customer_id,customer_name,customer_city,customer_grade,salesman_id) values (4,'smith','tokyo','b',2);
->insert into orders (order_no,purchase_amount,order_date,customer_id,salesman_id) values (4,130,'5-AUG-1900',1,2);

1.
select * from orders where
salesman_id = 1;
2.
select * from orders where
salesman_id IN (select salesman_id from salesman where salesman_city = 'paris');
4.
select * from orders where
purchase_amount > ( select avg(purchase_amount) from orders); 
5.
select * from orders where
salesman_id = ( select salesman_id from salesman where salesman_city = 'paris');
6.
select salesman_commission,salesman_name from salesman where
salesman_id IN (select salesman_id from customer where customer_city = 'paris');
7.
XXX
8.
9.
select customer_name,customer_id from customer where
customer_id = ( select customer_id from orders where order_date = '21-NOV-1996');
10.
select * from customer where 
customer_id IN (select customer_id from orders where order_date BETWEEN DATE '1990-01-01' AND DATE '2000-02-01');
11.
select salesman_name from salesman where 
salesman_in IN ( select salesman_id from customer where count(salesman_id) >1 );

ERROR: Group function is not allowed here.
13.
select salesman.salesman_id,salesman.salesman_city,customer.customer_city from salesman INNER JOIN
customer ON customer.customer_city = salesman.salesman_city;

or
select s.salesman_id,s.salesman_city,c.customer_city from salesman s INNER JOIN
customer c ON c.customer_city = s.salesman_city;
 
14.
select salesman_name from salesman where
salesman_id IN (select salesman_id from customers where count(salesman_id) >1 group by (customer_id));
ERROR.
15.
select * from orders where 
purchase_amount < ANY (select purchase_amount from orders where
customer_id  IN (select customer_id from customer where customer_city = 'paris')
);
 