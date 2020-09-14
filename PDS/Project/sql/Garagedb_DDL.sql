drop database Garagedb;
create database Garagedb;
use Garagedb;   

create table item(
        item_id integer,
        item_name varchar(30),
        category varchar(20),
        MRP float,
        vehicle_type varchar(20),
        Part_no varchar(10),
        bill_no integer,
        constraint pk_item PRIMARY KEY (item_id)
);

create table garage(
    garage_id integer,
    garage_location varchar(50),
    garage_name varchar(30),
    owner_id integer,
    constraint pk_garage PRIMARY KEY (garage_id)
);

create table bill(
    bill_no integer,
    bill_amount float,
    cust_id integer,
    constraint pk_bill PRIMARY KEY (bill_no)
);

create table customer(
    cust_id integer,
    cust_name varchar(30),
    cust_mobile varchar(15),
    cust_email varchar(40),
    cust_password varchar(40),
    constraint pk_customer PRIMARY KEY (cust_id)
);

create table owner(
    owner_id integer,
    owner_name varchar(30),
    owner_mobile varchar(15),
    owner_email varchar(40),
    owner_password varchar(40),
    constraint pk_owner PRIMARY KEY (owner_id)
);


alter table garage
    add constraint fk_garage_owner FOREIGN KEY(owner_id) REFERENCES owner(owner_id);

alter table bill
    add constraint fk_bill_customer FOREIGN KEY(cust_id) REFERENCES customer(cust_id);

alter  table item
    add constraint fk_item_bill FOREIGN KEY(bill_no) REFERENCES bill(bill_no)

