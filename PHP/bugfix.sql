-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 17, 2020 at 03:46 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.4.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bugfix`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin_login`
--

CREATE TABLE `admin_login` (
  `admin_id` int(11) NOT NULL,
  `admin_name` varchar(60) NOT NULL,
  `admin_email` varchar(60) NOT NULL,
  `admin_pass` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `admin_login`
--

INSERT INTO `admin_login` (`admin_id`, `admin_name`, `admin_email`, `admin_pass`) VALUES
(1, 'admin', 'admin@admin.com', '1234');

-- --------------------------------------------------------

--
-- Table structure for table `assets`
--

CREATE TABLE `assets` (
  `pid` int(11) NOT NULL,
  `pname` varchar(60) NOT NULL,
  `pdop` date NOT NULL,
  `pava` int(11) NOT NULL,
  `ptotal` int(11) NOT NULL,
  `poriginalcost` int(11) NOT NULL,
  `psellingcost` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `assets`
--

INSERT INTO `assets` (`pid`, `pname`, `pdop`, `pava`, `ptotal`, `poriginalcost`, `psellingcost`) VALUES
(1, 'Keyboard', '2020-09-05', 9, 12, 300, 600),
(4, 'Mouse', '2020-09-16', 12, 12, 600, 650);

-- --------------------------------------------------------

--
-- Table structure for table `assign_work`
--

CREATE TABLE `assign_work` (
  `r_number` int(11) NOT NULL,
  `r_id` int(11) NOT NULL,
  `r_info` text NOT NULL,
  `r_desc` varchar(255) NOT NULL,
  `r_name` varchar(60) NOT NULL,
  `r_add1` text NOT NULL,
  `r_add2` text NOT NULL,
  `r_city` varchar(60) NOT NULL,
  `r_state` varchar(60) NOT NULL,
  `r_zip` int(11) NOT NULL,
  `r_email` varchar(60) NOT NULL,
  `r_mobile` int(11) NOT NULL,
  `assign_tech` varchar(60) NOT NULL,
  `assign_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `customer_table_bill`
--

CREATE TABLE `customer_table_bill` (
  `c_id` int(11) NOT NULL,
  `c_name` text NOT NULL,
  `c_add` varchar(60) NOT NULL,
  `c_pname` varchar(60) NOT NULL,
  `c_quan` int(11) NOT NULL,
  `c_each` int(11) NOT NULL,
  `c_total` int(11) NOT NULL,
  `c_pdate` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `submit_request`
--

CREATE TABLE `submit_request` (
  `req_id` int(11) NOT NULL,
  `req_info` text NOT NULL,
  `req_desc` text NOT NULL,
  `req_name` varchar(60) NOT NULL,
  `req_add1` text NOT NULL,
  `req_add2` text NOT NULL,
  `req_city` text NOT NULL,
  `req_state` varchar(60) NOT NULL,
  `req_zip` int(11) NOT NULL,
  `req_email` varchar(60) NOT NULL,
  `req_mobile` bigint(20) NOT NULL,
  `req_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `technician_assigned`
--

CREATE TABLE `technician_assigned` (
  `emp_id` int(11) NOT NULL,
  `emp_name` text NOT NULL,
  `emp_city` varchar(60) NOT NULL,
  `emp_mobile` bigint(20) NOT NULL,
  `emp_email` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `technician_assigned`
--

INSERT INTO `technician_assigned` (`emp_id`, `emp_name`, `emp_city`, `emp_mobile`, `emp_email`) VALUES
(1, 'technician 1', 'Bhopal', 123456789, 'technician1@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `user_registration`
--

CREATE TABLE `user_registration` (
  `user_sno_id` int(11) NOT NULL,
  `user_name` varchar(60) NOT NULL,
  `user_email` varchar(60) NOT NULL,
  `user_pass` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user_registration`
--

INSERT INTO `user_registration` (`user_sno_id`, `user_name`, `user_email`, `user_pass`) VALUES
(1, 'user', 'user@user.com', '1234');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin_login`
--
ALTER TABLE `admin_login`
  ADD PRIMARY KEY (`admin_id`);

--
-- Indexes for table `assets`
--
ALTER TABLE `assets`
  ADD PRIMARY KEY (`pid`);

--
-- Indexes for table `assign_work`
--
ALTER TABLE `assign_work`
  ADD PRIMARY KEY (`r_number`);

--
-- Indexes for table `customer_table_bill`
--
ALTER TABLE `customer_table_bill`
  ADD PRIMARY KEY (`c_id`);

--
-- Indexes for table `submit_request`
--
ALTER TABLE `submit_request`
  ADD PRIMARY KEY (`req_id`);

--
-- Indexes for table `technician_assigned`
--
ALTER TABLE `technician_assigned`
  ADD PRIMARY KEY (`emp_id`);

--
-- Indexes for table `user_registration`
--
ALTER TABLE `user_registration`
  ADD PRIMARY KEY (`user_sno_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin_login`
--
ALTER TABLE `admin_login`
  MODIFY `admin_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `assets`
--
ALTER TABLE `assets`
  MODIFY `pid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `assign_work`
--
ALTER TABLE `assign_work`
  MODIFY `r_number` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `customer_table_bill`
--
ALTER TABLE `customer_table_bill`
  MODIFY `c_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `submit_request`
--
ALTER TABLE `submit_request`
  MODIFY `req_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `technician_assigned`
--
ALTER TABLE `technician_assigned`
  MODIFY `emp_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `user_registration`
--
ALTER TABLE `user_registration`
  MODIFY `user_sno_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
