drop database library;

create database library;

use library;

create table Library(
    library_id integer primary key,
	name varchar(20),
	branch varchar(20),
	address varchar(50),
	phone varchar(10)
);

create table `Member`(
    member_id integer primary key,
	lib_id integer,
	phone varchar(10),
	address varchar(50),
	name varchar(20),
    constraint lib_mem_fk foreign key (lib_id) references Library (library_id)
);

create table Subscription(
    subscription_id integer primary key,
	start_date Date,
	end_date Date,
	monthly_fee float,
    reg_fee float,
	type varchar(20),
	member_id integer,
    constraint sub_mem_fk foreign key (member_id) references `Member` (member_id)
);

create table `Book`(
    book_id integer primary key,
    lib_id integer,
	branch varchar(50),
	genre varchar(50),
	author varchar(50),
	publication varchar(50),
	name varchar(50),
	copies_left integer,
    constraint lib_book_fk foreign key (lib_id) references Library (library_id)
);

create table `Book_Issue_Details`(
	book_details_id integer primary key,
	borrow_date Date,
	return_date Date,
	book_name varchar(50),
	member_id integer,
	book_id integer,
    constraint mem_id_fk foreign key (member_id) references `Member` (member_id),
    constraint book_id_fk foreign key (book_id) references Library (library_id)
);