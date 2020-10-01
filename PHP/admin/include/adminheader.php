<?php

include("../connection.php");
?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo constant("TITLE");?></title>
    <!-- Bootstrap CSS -->

    <link rel="stylesheet" href="../css/bootstrap.min.css">
    <!-- Font Awesome CSS -->

    <link rel="stylesheet" href="../css/all.min.css">
    <!-- Google Font -->
    <link href="https://fonts.googleapis.com/css2?family=Ubuntu:wght@300&display=swap" rel="stylesheet">
</head>

<body>
    <!-- Top Navbar -->
    <nav class="navbar navbar-expand-sm navbar-dark fixed-top bg-danger p-2 shadow-lg">
        <a href="../index.php" class="navbar-brand col-sm-3 col-md-2 mr-0">BugFix</a>
    </nav>
    <!-- Side Bar -->
    <div class="container-fluid" style="margin-top: 40px;">
        <div class="row">
            <nav class="col-sm-2 bg-light sidebar py-5  d-print-none">
                <div class="sidebar-sticky">
                    <ul class="nav flex-column">
                        <li class="nav-item "><a href="dashboard.php" class="nav-link active"><i class="fas fa-tachometer-alt mr-2"></i>Dashboard</a></li>
                        <li class="nav-item"><a href="work.php" class="nav-link"><i class="fab fa-accessible-icon mr-2"></i>Work Order</a></li>
                        <li class="nav-item"><a href="requests.php" class="nav-link"><i class="fas fa-align-center mr-2"></i></i>Requests</a></li>
                        <li class="nav-item"><a href="assets.php" class="nav-link"><i class="fas fa-align-center mr-2"></i></i>Assets</a></li>
                        <li class="nav-item"><a href="technician.php" class="nav-link"><i class="fas fa-align-center mr-2"></i></i>Technician</a></li>
                        <li class="nav-item"><a href="requester.php" class="nav-link"><i class="fas fa-users mr-2"></i></i>Requester</a></li>
                        <li class="nav-item"><a href="sellreport.php" class="nav-link"><i class="fas fa-table mr-2"></i></i>Sell Report</a></li>
                        <li class="nav-item"><a href="workreport.php" class="nav-link"><i class="fas fa-table mr-2"></i></i>Work Report</a></li>
                        <li class="nav-item"><a href="adminchangepassword.php" class="nav-link"><i class="fas fa-key mr-2"></i>Change Password</a></li>
                        <li class="nav-item"><a href="adminlogout.php" class="nav-link"><i class="fas fa-sign-out-alt mr-2"></i>Logout</a></li>
                    </ul>
                </div>
            </nav> <!-- End 1st Column-->