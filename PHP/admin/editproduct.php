<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Add Product");
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-6 mx-3 jumbotron mt-5">
    <h3 class="text-center">Update Product Details</h3>
    <?php
    if (isset($_POST['edit'])) {
        $id = $_POST['id'];
        $sql = "SELECT * FROM assets WHERE pid = '$id'";
        $result = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($result);
    }
    if (isset($_POST['update'])) {
        if (!empty($_POST['pname']) && !empty($_POST['pdop']) && !empty($_POST['ptotal']) && !empty($_POST['porg'])) {
            $pid = $_POST['pid'];
            $pname = $_POST['pname'];
            $pdop = $_POST['pdop'];
            $pava = $_POST['pava'];
            $ptotal = $_POST['ptotal'];
            $porg = $_POST['porg'];
            $psell =  $_POST['psell'];
            $sql = "UPDATE assets SET pname = '$pname', pdop = '$pdop', pava = '$pava', ptotal = '$ptotal' , psellingcost = '$psell', poriginalcost = '$porg' WHERE pid ='$pid'";
            $result = mysqli_query($conn, $sql);
            if ($result) {
                echo "<div class='alert alert-success'>Product Updated</div>";
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
            <label for="id">Product Id</label>
            <input type="text" name="pid" class="form-control" value="<?php if (isset($row['pid'])) {
                                                                            echo $row['pid'];
                                                                        } ?>" readonly>
        </div>
        <div class="form-group">
            <label for="name">Product Name</label>
            <input type="text" name="pname" class="form-control" value="<?php if (isset($row['pname'])) {
                                                                            echo $row['pname'];
                                                                        } ?>" required>
        </div>
        <div class="form-group">
            <label for="id">Product Dop</label>
            <input type="date" name="pdop" class="form-control" value="<?php if (isset($row['pdop'])) {
                                                                            echo $row['pdop'];
                                                                        } ?>" required>
        </div>
        <div class="form-group">
            <label for="name">Product Available</label>
            <input type="number" name="pava" class="form-control" value="<?php if (isset($row['pava'])) {
                                                                            echo $row['pava'];
                                                                        } ?>" required>
        </div>
        <div class="form-group">
            <label for="name">Product Total</label>
            <input type="number" name="ptotal" class="form-control" value="<?php if (isset($row['ptotal'])) {
                                                                            echo $row['ptotal'];
                                                                        } ?>" required>
        </div>
        <div class="form-group">
            <label for="name">Original Cost</label>
            <input type="number" name="porg" class="form-control" value="<?php if (isset($row['poriginalcost'])) {
                                                                            echo $row['poriginalcost'];
                                                                        } ?>" required>
        </div>
        <div class="form-group">
            <label for="name">Selling Cost</label>
            <input type="number" name="psell" class="form-control" value="<?php if (isset($row['psellingcost'])) {
                                                                            echo $row['psellingcost'];
                                                                        } ?>" required>
        </div>
        <button type="submit" class="btn btn-info text-center" name="update">Update</button>
    </form>
    <a href="assets.php"><button type="submit" class="btn btn-info text-center d-inline">Close</button></a>
</div>


<?php
include("include/adminfooter.php");
?>