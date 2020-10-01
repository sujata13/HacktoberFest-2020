<?php

include("../connection.php");
session_start();
if(!isset($_SESSION['loggedin'])){
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        if (!empty($_POST['uemail']) && !empty($_POST['upass'])) {
            $lemail = mysqli_real_escape_string($conn, trim($_POST['uemail']));
            $lpass = mysqli_real_escape_string($conn, trim($_POST['upass']));

            $sql = "SELECT user_email, user_pass FROM `user_registration` WHERE user_email= '$lemail' AND user_pass= '$lpass' LIMIT 1";
            $result = mysqli_query($conn, $sql);

            $num = mysqli_num_rows($result);
            if ($num == 1) {
                $_SESSION['loggedin'] = true;
                $_SESSION['lemail'] = $lemail;
                echo "<script> location.href='requesterprofile.php' </script>";
            } else {
                $remsg = "<div class='alert alert-danger mt-2 font-weight-bold' role='alert'>Enter valid email or password </div>";
            }
        } else {
            $remsg = "<div class='alert alert-danger mt-2 font-weight-bold' role='alert'>Fill all Credentials</div>";
        }
    }
}else{
    echo "<script> location.href='requesterprofile.php' </script>";
}

?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>

    <!-- Bootstrap CSS -->

    <link rel="stylesheet" href="../css/bootstrap.min.css">
    <!-- Font Awesome CSS -->

    <link rel="stylesheet" href="../css/all.min.css">
    <!-- Google Font -->
    <link href="https://fonts.googleapis.com/css2?family=Ubuntu:wght@300&display=swap" rel="stylesheet">
</head>

<body>
    <div class="mt-5 text-center" style="font-size: 30px;">
        <i class="fas fa-stethoscope"></i>
        <span>BugFix User Login</span>
    </div>
    <p class="text-center mt-4" style="font-size: 20px;"><i class=" fas fa-user-secret text-danger mr-3"></i>User Area</p>

    <div class="container-fluid">
        <div class="row justify-content-center">
            <div class="col-sm-6 col-md-4 ">
                <form action="" method="post" class="shadow-lg p-4 rounded">
                    <div class="form-group">
                        <i class="fas fa-user"></i><label for="email" class="font-weight-bold pl-2">Email</label>
                        <input type="email" name="uemail" id="email" placeholder="Email" class="form-control">
                        <small class="form-text">We will never share your email with anyone</small>
                    </div>
                    <div class="form-group">
                        <i class="fas fa-key"></i><label for="password" class="font-weight-bold pl-2">Password</label>
                        <input type="password" name="upass" id="password" placeholder="Password" class="form-control">
                    </div>
                    <button type="submit" class="btn btn-outline-info btn-block font-weight-bold shadow-sm">Login</button>
                </form>
                <div>
                    <?php if(isset($remsg)){echo $remsg;}; ?>
                </div>
                <div class="text-center">
                    <a href="../index.php" class="btn btn-info text-white shadow-sm mt-4">Back to Home</a>
                </div>
            </div>
        </div>
    </div>

    <!-- Javascript -->
    <script src="../js/jquery.min.js"></script>
    <script src="../js/popper.min.js"></script>
    <script src="../js/bootstrap.min.js"></script>
    <script src="../js/all.min.js"></script>
</body>

</html>