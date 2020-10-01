<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Requester");
include("include/adminheader.php");
include("../connection.php");
?>
<?php

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    if (!empty($_POST['rname']) && !empty($_POST['remail'])) {
        $rname = $_POST['rname'];
        $rcity = $_POST['rcity'];
        $rmobile = $_POST['rmobile'];
        $remail = $_POST['remail'];

        $sql = "INSERT INTO technician_assigned (emp_name, emp_email, emp_city, emp_mobile )VALUE ('$rname','$remail','$rcity','$rmobile')";
        $result = mysqli_query($conn, $sql);
        if ($result) {
            $remsg = "<div class='alert alert-success'>Added Succesfully</div>";
        } else {
            $remsg = "<div class='alert alert-success'>Added Succesfully</div>";
        }
    } else {
        $remsg = "<div class='alert alert-warning mt-3'>Fill all details </div>";
    }
}

?>
<div class="col-sm-6 mt-5 jumbotron">
    <h2 class="text-center">Add New Technician</h2>
    <div class="row mt-4 mb-4">
        <div class="col-md-6 offset-md-3">
            <form action="" method="post" class="shadow-lg p-4 rounded">
                <div class="form-group">
                    <i class="fas fa-user"></i><label for="name" class="font-weight-bold pl-2">Name</label><input type="text" class="form-control" placeholder="Name" name="rname">
                </div>
                <div class="form-group">
                    <i class="fas fa-home"></i><label for="name" class="font-weight-bold pl-2">City</label><input type="text" class="form-control" placeholder="City" name="rcity">
                </div>
                <div class="form-group">
                    <i class="fas fa-mobile"></i><label for="name" class="font-weight-bold pl-2">Mobile</label><input type="number" class="form-control" placeholder="Mobile" name="rmobile">
                </div>
                <div class="form-group">
                    <i class="fas fa-envelope-square"></i><label for="email" class="font-weight-bold pl-2">Email</label><input type="email" class="form-control" placeholder="Email" name="remail">
                </div>
                <button type="submit" class="btn btn-info mt-5 btn-block shadow-lg font-weight-bold" name="rsignup">Sign Up</button>
                <?php if (isset($remsg)) {
                    echo $remsg;
                } ?>
            </form>
        </div>
    </div>
</div>


<?php
include("include/adminfooter.php");
?>