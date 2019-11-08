select * from Customer where City like 'p%';
select * from Customer where City like '%la%';
select * from Table0 where City = 'Berlin' or City = 'London';

-- Q2
select Customer.CustomerName, Table2.ContactName, Table2.OrderId from Table1 left join Table2 on Table1.CustomerID = Table2.CustomerID;
select Table1.CustomerName, Table2.ContactName, Table2.OrderId from Table1 right join Table2 on Table1.CustomerID = Table2.CustomerID;
select Table1.CustomerName, Table2.ContactName, Table2.OrderId from Table1 inner join Table2 on Table1.CustomerID = Table2.CustomerID;
select * from SalesmanTable full join SalesOrder on SalesmanTable.SlMan_id = SalesOrder.Salesman_id;
