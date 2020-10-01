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
<?php

if (isset($_POST['padd'])) {
    if (empty($_POST['pname'])) {
        $remsg = "<div class='alert alert-danger mt-2'>Name is required</div>";
    } elseif (empty($_POST['pdop'])) {
        $remsg1 = "<div class='alert alert-danger mt-2'>Date is required</div>";
    } elseif (empty($_POST['pava'])) {
        $remsg2 = "<div class='alert alert-danger mt-2'>Product availability is required</div>";
    } elseif (empty($_POST['ptotal'])) {
        $remsg3 = "<div class='alert alert-danger mt-2'>Product total is required</div>";
    } elseif (empty($_POST['porg'])) {
        $remsg4 = "<div class='alert alert-danger mt-2'>Original Price is required</div>";
    } elseif (empty($_POST['psell'])) {
        $remsg5 = "<div class='alert alert-danger mt-2'>Selling Price is required</div>";
    } else {
        $pname = $_POST['pname'];
        $pdop = $_POST['pdop'];
        $pava = $_POST['pava'];
        $ptotal = $_POST['ptotal'];
        $porg = $_POST['porg'];
        $psell =  $_POST['psell'];
        $sql = "INSERT INTO assets (pname, pdop, pava, ptotal, poriginalcost, psellingcost) VALUES ('$pname', '$pdop' ,'$pava' ,'$ptotal' ,'$porg' ,'$psell')";
        $result = mysqli_query($conn, $sql);
        if ($result) {
            $remsg6 = "<div class='alert alert-success mt-2'>Product added Successfully</div>";
        } else {
            $remsg7 = "<div class='alert alert-warning mt-2'>Fail to add product</div>";
        }
    }
}


?>
<div class="col-sm-6 mt-5 mx-5 jumbotron">
    <h2 class="text-center">Add New Product</h2>
    <div class="row mt-4 mb-4">
        <div class="col-md-6 offset-md-3">
            <form action="" method="post" class="shadow-lg p-4 rounded">
                <div class="form-group">
                    <label for="pname" class="font-weight-bold pl-2">Product Name</label><input type="text" class="form-control" placeholder="Product Name" name="pname">
                    <?php if (isset($remsg)) {
                        echo $remsg;
                    } ?>
                </div>
                <div class="form-group">
                    <label for="dop" class="font-weight-bold pl-2">Date of Purchase</label><input type="date" class="form-control" placeholder="Dop" name="pdop">
                    <?php if (isset($remsg1)) {
                        echo $remsg1;
                    } ?>
                </div>
                <div class="form-group">
                    <label for="available" class="font-weight-bold pl-2">Available</label><input type="number" class="form-control" placeholder="Avaiable" name="pava">
                    <?php if (isset($remsg2)) {
                        echo $remsg2;
                    } ?>
                </div>
                <div class="form-group">
                    <label for="total" class="font-weight-bold pl-2">Total</label><input type="number" class="form-control" placeholder="Total" name="ptotal">
                    <?php if (isset($remsg3)) {
                        echo $remsg3;
                    } ?>
                </div>
                <div class="form-group">
                    <label for="Original Cost" class="font-weight-bold pl-2">Original Cost Each</label><input type="number" class="form-control" placeholder="Original Cost" name="porg">
                    <?php if (isset($remsg4)) {
                        echo $remsg4;
                    } ?>
                </div>
                <div class="form-group">
                    <label for="Selling Cost" class="font-weight-bold pl-2">Selling Cost Each</label><input type="number" class="form-control" placeholder="Selling Cost" name="psell">
                    <?php if (isset($remsg5)) {
                        echo $remsg5;
                    } ?>
                </div>
                <button type="submit" class="btn btn-info mt-5 btn-block shadow-lg font-weight-bold" name="padd">Add Product</button>
                <a href="assets.php" class="btn btn-info mt-2 btn-block shadow-lg font-weight-bold">Close</a>
                <?php if (isset($remsg6)) {
                    echo $remsg6;
                }elseif(isset($remsg7)){
                    echo $remsg7;
                } ?>
            </form>
        </div>
    </div>
</div>





<?php
include("include/adminfooter.php");
?>