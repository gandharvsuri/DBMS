use library;

INSERT INTO Library VALUES(
    1056789,
	"Just Books",
	"Sahakarnagar",
	"#456D, 60 Ft Road, Sahakarnagar, opposite McD",
	"8650234791"
);

INSERT INTO Library VALUES(
    1038056,
	"Just Books",
	"Malleswaram",
	"#321H, 18th cross, Malleswaram, opposite McD",
	"8690478901"
);

INSERT INTO `Member` VALUES(
    128965,
	null,
	"7338027548",
	"311B, 60 ft road, CQAL Layout, Blore 560092",
	"Ajita"
);

INSERT INTO `Member` VALUES(
    123456,
	null,
	"8904489104",
	"512K, Defense Colony, Blore 560092",
	"Dhruv"
);

INSERT INTO `Member` VALUES(
    176790,
	null,
	"8904486709",
	"534B, A Block Colony, Blore 560092",
	"Leenu"
);

INSERT INTO Subscription VALUES(
    1,
	DATE("2019-01-09"),
	DATE("2019-02-09"),
	500.00,
    1500,
	"Standard",
	null
);

INSERT INTO Subscription VALUES(
    2,
	DATE("2019-03-17"),
	DATE("1965-04-17"),
	500.00,
    1500,
	"Standard",
	null
);

INSERT INTO Subscription VALUES(
    3,
	DATE("2019-01-13"),
	DATE("2019-02-13"),
	1000.00,
    3000,
	"Premiuim",
	null
);

UPDATE Subscription
SET member_id = 128965
WHERE subscription_id = 1;

UPDATE Subscription
SET member_id = 123456
WHERE subscription_id = 2;

UPDATE Subscription
SET member_id = 176790
WHERE subscription_id = 3;
