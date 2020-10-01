<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Change Password");
include("include/adminheader.php");
include("../connection.php");
?>


<?php

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    if (!empty($_POST['apass'])) {
        $apas = $_POST['apass'];
        $sql = "UPDATE admin_login SET admin_pass='$apas' WHERE admin_email='$aemail'";
        $result = mysqli_query($conn, $sql);
        if ($result) {
            $remsg = "<div class='alert alert-success font-weight-bold'>Updated Successfully</div>";
        } else {
            $remsg = "<div class='alert alert-danger font-weight-bold'>Error in Updating</div>";
        }
    } else {
        $remsg = "<div class='alert alert-warning font-weight-bold'>Fill all details</div>";
    }
}

?>

<div class="col-sm-6 col-md-6 mt-5">
    <!-- Start service request form of 2nd column-->
    <form class="mx-4 my-4" action="" method="POST">
        <h2 class="my-3">Change Password</h2>
        <div class="form-group">
            <label for="inputemail" class="font-weight-bold">Email</label>
            <input type="email" id="inputemail" class="form-control " readonly value="<?php echo $aemail; ?>">
        </div>
        <div class="form-group">
            <label for="inputpassword" class="font-weight-bold">New Password</label>
            <input type="password" class="form-control" id="inputpassword" name="apass" placeholder="New Password">
        </div>
        <button class="btn btn-info" type="submit" name="passupdate">Update</button>
        <button class="btn btn-info" type="reset">Reset</button>
    </form>
    <?php if (isset($remsg)) {
        echo $remsg;
    } ?>
</div> <!-- End changepassword form-->



<?php

include("include/adminfooter.php");
?>