<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Bugfix </title>

    <!-- Bootstrap CSS -->

    <link rel="stylesheet" href="css/bootstrap.min.css">
    <!-- Font Awesome CSS -->

    <link rel="stylesheet" href="css/all.min.css">
    <!-- Google Font -->
    <link href="https://fonts.googleapis.com/css2?family=Ubuntu:wght@300&display=swap" rel="stylesheet">

    <!-- Custom CSS -->
    <link rel="stylesheet" href="css/custom.css">
</head>

<body>
    <!-- Start Navigation -->
    <nav class="navbar navbar-expand-sm navbar-dark bg-danger pl-4 fixed-top">
        <a href="index.php" class="navbar-brand">BugFix</a>
        <span class="navbar-text">Customer's Happiness is our Aim</span>
        <button type="button" class="navbar-toggler" data-toggle="collapse" data-target="#myMenu"><span class="navbar-toggler-icon"></span></button>
        <div class="collapse navbar-collapse" id="myMenu">
            <ul class="navbar-nav pl-5 custom-nav">
                <li class="nav-item"><a href="index.php" class="nav-link">Home</a></li>
                <li class="nav-item"><a href="#services" class="nav-link">Services</a></li>
                <li class="nav-item"><a href="#registration" class="nav-link">Registration</a></li>
                <li class="nav-item"><a href="requester/requesterlogin.php" class="nav-link">Login</a></li>
                <li class="nav-item"><a href="#contact" class="nav-link">Contact</a></li>
            </ul>
        </div>
    </nav> <!-- End Navigation -->

    <!-- Start Header -->

    <header class="jumbotron back-image" style="background-image:url(images/2.png);">
        <div class="main-heading">
            <h1 class=" text-white">Welcome To BugFix</h1>
            <p class="text-white font-italic pclass">Customer's Happiness is our Aim</p>
            <a href="requester/requesterlogin.php" class="btn btn-info text-white">Login</a>
            <a href="#" class="btn btn-info text-white">SignUp</a>
        </div>
    </header>

    <!-- End Header -->

    <!-- Start Intro Section -->
    <div class="container">
        <div class="jumbotron">
            <h3 class="text-center">BugFix Services</h3>
            <p>Lorem ipsum dolor sit amet consectetur adipisicing elit. Laudantium inventore maxime, tempora, ipsam dolorum dolorem culpa exercitationem ea fuga, debitis placeat. Ipsa id, ipsam omnis in eveniet culpa. Mollitia, temporibus?</p>
        </div>
    </div>
    <!-- End Intro Section -->

    
    <!-- Start Service Section -->
    <div class="container text-center border-bottom" id="services">
        <h3>Our Services</h3>
        <div class="row mt-4">
            <div class="col-sm-4 mb-4">
                <a href="#"><i class="fas fa-tv fa-8x text-success"></i></a>
                <h4 class="mt-4">Electronics Application</h4>
            </div>
            <div class="col-sm-4 mb-4">
                <a href="#"><i class="fas fa-sliders-h fa-8x text-primary"></i></a>
                <h4 class="mt-4">Preventive Maintenance</h4>
            </div>
            <div class="col-sm-4 mb-4">
                <a href="#"><i class="fas fa-cogs fa-8x text-info"></i></a>
                <h4 class="mt-4">Fault Repair</h4>
            </div>
        </div>
    </div>
    <!-- End Service Section -->


    <!-- Registration Form Start -->
    <?php
    include("userregistration.php");
    ?>
    <!-- Registration Form End -->

    <!-- Start Testimonial  -->
    <div class="jumbotron bg-danger mt-5 rounded-0">
        <div class="container">
            <h2 class="text-center text-white">Happy Customer</h2>
            <div class="row mt-5 ">
                <div class="col-lg-3 col-sm-6">
                    <div class="card shadow-lg mb-2">
                        <div class="card-body text-center">
                            <img src="images/user.png" alt="avt-1" height="180px" class="img-fluid">
                            <h4 class="card-title mt-2">Rahul Kumar</h4>
                            <p class="card-text">Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatum alias dolore aspernatur ullam quo voluptatem consectetur dolorum deserunt.</p>
                        </div>
                    </div>
                </div>
                <!--1st Column End -->
                <div class="col-lg-3 col-sm-6">
                    <div class="card shadow-lg mb-2">
                        <div class="card-body text-center">
                            <img src="images/user.png" alt="avt-1" height="180px" class="img-fluid">
                            <h4 class="card-title mt-2">Sonam Kumar</h4>
                            <p class="card-text">Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatum alias dolore aspernatur ullam quo voluptatem consectetur dolorum deserunt.</p>
                        </div>
                    </div>
                </div>
                <!--2nd Column End -->
                <div class="col-lg-3 col-sm-6">
                    <div class="card shadow-lg mb-2">
                        <div class="card-body text-center">
                            <img src="images/user.png" alt="avt-1" height="180px" class="img-fluid">
                            <h4 class="card-title mt-2">Sneha Joshi</h4>
                            <p class="card-text">Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatum alias dolore aspernatur ullam quo voluptatem consectetur dolorum deserunt.</p>
                        </div>
                    </div>
                </div>
                <!--3rd Column End -->
                <div class="col-lg-3 col-sm-6">
                    <div class="card shadow-lg mb-2">
                        <div class="card-body text-center">
                            <img src="images/user.png" alt="avt-1" height="180px" class="img-fluid">
                            <h4 class="card-title mt-2">Harsh Joshi</h4>
                            <p class="card-text">Lorem ipsum dolor sit amet consectetur adipisicing elit. Voluptatum alias dolore aspernatur ullam quo voluptatem consectetur dolorum deserunt.</p>
                        </div>
                    </div>
                </div>
                <!--4th Column End -->
            </div>
        </div>
    </div>
    <!-- End Testimonial -->

    <!-- Start Contact Us -->
    <div class="container" id="contact">
        <h2 class="text-center mb-4">Contact Us</h2>
        <div class="row">
            <?php include("contactform.php"); ?>
            <!-- ContactForm -->
            <div class="col-md-4 text-center">
                <strong>Headquarter: </strong><br>
                BugFix Pvt Ltd <br>
                Bilaspur, C.G <br>
                Phone: +91 9xxxxxxxxx <br>
                <a href="" target="_blank">www.bugfix.com</a> <br><br>
                <strong>Raipur Branch: </strong><br>
                BugFix Pvt Ltd <br>
                Raipur, C.G <br>
                Phone: +91 9xxxxxxxxx <br>
                <a href="" target="_blank">www.bugfix.com</a>
            </div>
        </div>
    </div>
    <!-- End Contatc US -->

    <!-- Start Footer -->
    <footer class="container-fluid bg-dark mt-5">
        <div class="container text-white">
            <div class="row py-3">
                <div class="col-md-6">
                    <span class="pr-2">Follow Us: </span>
                    <a href="" class="pr-2"><i class="fab fa-facebook-f text-danger"></i></a>
                    <a href="" class="pr-2"><i class="fab fa-twitter text-danger"></i></a>
                    <a href="" class="pr-2"><i class="fab fa-instagram text-danger"></i></a>
                    <a href="" class="pr-2"><i class="fas fa-rss text-danger"></i></a>
                </div>
                <div class="col-md-6 text-right">
                    <span>Designed By- Sneh Joshi &copy; 2020</span>
                    <small><a href="admin/adminlogin.php" class="ml-2 font h6">Admin Login </a></small>
                </div>
            </div>
        </div>
    </footer>
    <!-- End Footer -->

    <!-- Javascript -->
    <script src="js/jquery.min.js"></script>
    <script src="js/popper.min.js"></script>
    <script src="js/bootstrap.min.js"></script>
    <script src="js/all.min.js"></script>
</body>

</html>