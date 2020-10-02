-- This script assumes you have a Database with Table "Cities"
-- In SQL World, CRUD operations are performed by DML (Data Manipulative Language) queries

-- SELECT = Read Operation from a Table

-- Select all rows from CITIES
SELECT * FROM CITIES;
-- Select specific columns from CITIES
SELECT ID, NAME, STATE FROM CITIES;
-- Select rows which satisfy a specific condition
SELECT * FROM CITIES WHERE STATE='GA';
-- Select rows in a specific order
SELECT * FROM CITIES ORDER BY ID ASC;

-- INSERT = Create/Insert rows in a Table

-- Insert a single row
INSERT INTO CITIES
        (ID, NAME, STATE)
 VALUES (1234, "Atlanta", 'GA');
-- Insert multiple rows
INSERT INTO CITIES
        (ID, NAME, STATE)
 VALUES
        (1234, "Atlanta", 'GA'),
        (5678, "San Francisco", 'CA'),
        (1001, "New York", 'NY');
-- Insert only specific rows
INSERT INTO CITIES
        (ID, NAME)
 VALUES (1234, "Atlanta");

-- UPDATE = Update values in existing rows

-- Update a specific column for all rows
UPDATE CITIES
SET COUNTRY='US';
-- Update a specific column for rows which satisfy a condition
UPDATE CITIES
SET NAME='Atlanta'
WHERE CITY_CODE='07';
-- Update multiple columns for rows which satisfy a condition
UPDATE CITIES
SET NAME='Atlanta', STATE='GA'
WHERE CITY_CODE='07';

-- DELETE = Delete row/rows from a table

-- Delete all rows
DELETE FROM CITIES;
-- Delete rows which satisfy a condition
DELETE FROM CITIES WHERE NAME='New York';
