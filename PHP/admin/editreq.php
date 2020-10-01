<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "EditReq");
include("include/adminheader.php");
include("../connection.php");
?>


<div class="col-sm-6 mx-3 jumbotron mt-5">
   <h3 class="text-center">Update Requester Details</h3>
   <?php
    if(isset($_POST['edit'])){
        $id = $_POST['id'];
        $sql = "SELECT * FROM user_registration WHERE user_sno_id = '$id'";
        $result = mysqli_query($conn,$sql);
        $row = mysqli_fetch_assoc($result);
    }
    if(isset($_POST['update'])){
        if(!empty($_POST['user_name']) && !empty($_POST['user_email'])){
            $rid = $_POST['user_sno_id'];
            $rname = $_POST['user_name'];
            $remail = $_POST['user_email'];

            $sql = "UPDATE user_registration SET user_name = '$rname', user_email= '$remail' WHERE user_sno_id ='$rid'";
            $result = mysqli_query($conn, $sql);
            if ($result) {
                echo "<div class='alert alert-success'>Record Updated</div>";
            } else {
                echo "<div class='alert alert-warning'>Updation Failed</div>";
            }
        } else {
            echo "<div class='alert alert-warning'>Fill all details</div>";
    }
}
   ?>

    <form action="" method="POST" class="d-inline">
        <div class="form-group">
            <label for="id">Requester Id</label>
            <input type="text" name="user_sno_id" class="form-control" value="<?php  if(isset($row['user_sno_id'])){echo $row['user_sno_id'];}?>" readonly>
        </div>
        <div class="form-group">
            <label for="name">Requester Name</label>
            <input type="text" name="user_name" class="form-control" value="<?php  if(isset($row['user_name'])){echo $row['user_name'];}?>" required >
        </div>
        <div class="form-group">
            <label for="id">Requester Email</label>
            <input type="email" name="user_email" class="form-control" value="<?php  if(isset($row['user_email'])){echo $row['user_email'];}?>" required >
        </div>
        <button type="submit" class="btn btn-info text-center" name="update">Update</button>
    </form>
    <a href="requester.php"><button type="submit" class="btn btn-info text-center d-inline">Close</button></a>
</div>


<?php
include("include/adminfooter.php");
?>