<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Sell Product");
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-6 mx-3 jumbotron mt-5">
    <h3 class="text-center">Customer Bill</h3>
    <?php
    if (isset($_POST['sell'])) {
        $id = $_POST['id'];
        $sql = "SELECT * FROM assets WHERE pid = '$id'";
        $result = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($result);
    }
    if (isset($_POST['psubmit'])) {
        if (!empty($_POST['cname']) && !empty($_POST['selldate']) && !empty($_POST['pquant']) && !empty($_POST['cadd']) && !empty($_POST['totalcost'])){
            $pid = $_POST['pid'];
            $cname = $_POST['cname'];
            $cadd = $_POST['cadd'];
            $pname = $_POST['pname'];
            $pquant = $_POST['pquant'];
            $pava = $_POST['pava'] - $_POST['pquant']; // for changing availability dynamically
            $priceeach= $_POST['priceeach'];
            $totalcost =  $_POST['totalcost'];
            $selldate = $_POST['selldate'];
            $sql = "INSERT INTO customer_table_bill(c_name, c_add, c_pname, c_quan, c_each, c_total, c_pdate) VALUES ('$cname','$cadd','$pname','$pquant','$priceeach','$totalcost', '$selldate')";
            $result = mysqli_query($conn, $sql);
            if ($result) {
                $genid = mysqli_insert_id($conn);
                $_SESSION['myid'] = $genid;
                $sql2 = "UPDATE assets SET pava = '$pava' WHERE pid = '$pid'";
                $result2 = mysqli_query($conn, $sql2);
                echo "<script> location.href = 'productsellsuccess.php'</script>";
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
            <label for="name">Customer Name</label>
            <input type="text" name="cname" class="form-control" required>
        </div>
        <div class="form-group">
            <label for="name">Address</label>
            <input type="text" name="cadd" class="form-control" required>
        </div>
        <div class="form-group">
            <label for="name">Product Name</label>
            <input type="text" name="pname" class="form-control" value="<?php if (isset($row['pname'])) {
                                                                            echo $row['pname'];
                                                                        } ?>" required readonly>
        </div>
        <div class="form-group">
            <label for="name">Product Available</label>
            <input type="number" name="pava" class="form-control" value="<?php if (isset($row['pava'])) {
                                                                                echo $row['pava'];
                                                                            } ?>" required readonly>
        </div>
        <div class="form-group">
            <label for="name">Quantity</label>
            <input type="number" name="pquant" class="form-control" required id="quant">
        </div>
        <div class="form-group">
            <label for="name">Price Each</label>
            <input type="number" name="priceeach" class="form-control" value="<?php if (isset($row['psellingcost'])) {
                                                                                echo $row['psellingcost'];
                                                                            } ?>" required readonly>
        </div>
        <div class="form-group">
            <label for="name">Total Price</label>
            <input type="text" name="totalcost" class="form-control"  required >
        </div>
        <div class="form-group">
            <label for="name">Date of Selling</label>
            <input type="date" name="selldate" class="form-control" required>
        </div>
        <button type="submit" class="btn btn-info text-center" name="psubmit">Submit</button>
    </form>
    <a href="assets.php"><button type="submit" class="btn btn-info text-center d-inline">Close</button></a>
</div>
<?php
include("include/adminfooter.php");
?>