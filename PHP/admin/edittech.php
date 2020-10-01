<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "EditTech");
include("include/adminheader.php");
include("../connection.php");
?>


<div class="col-sm-6 mx-3 jumbotron mt-5">
    <h3 class="text-center">Update Technician Details</h3>
    <?php
    if (isset($_POST['edit'])) {
        $id = $_POST['id'];
        $sql = "SELECT * FROM technician_assigned WHERE emp_id = '$id'";
        $result = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($result);
    }
    if (isset($_POST['update'])) {
        if (!empty($_POST['emp_name']) && !empty($_POST['emp_email'])) {
            $rid = $_POST['emp_id'];
            $rname = $_POST['emp_name'];
            $remail = $_POST['emp_email'];

            $sql = "UPDATE technician_assigned SET emp_name = '$rname', emp_email= '$remail' WHERE emp_id ='$rid'";
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
            <label for="id">Technician Id</label>
            <input type="text" name="emp_id" class="form-control" value="<?php if (isset($row['emp_id'])) { echo $row['emp_id'];
             } ?>" readonly>
        </div>
        <div class="form-group">
            <label for="name">Technicain Name</label>
            <input type="text" name="emp_name" class="form-control" value="<?php if (isset($row['emp_name'])) {
                 echo $row['emp_name'];
                } ?>" required>
        </div>
        <div class="form-group">
            <label for="id">Technician Email</label>
            <input type="email" name="emp_email" class="form-control" value="<?php if (isset($row['emp_email'])) { echo $row['emp_email'];
                  } ?>" required>
        </div>
        <button type="submit" class="btn btn-info text-center" name="update">Update</button>
    </form>
    <a href="requester.php"><button type="submit" class="btn btn-info text-center d-inline">Close</button></a>
</div>


<?php
include("include/adminfooter.php");
?>