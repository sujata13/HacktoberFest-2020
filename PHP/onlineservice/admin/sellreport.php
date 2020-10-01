<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Sell Report");
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-9 col-md-10 mt-5 text-center">
    <form action="" class="d-print-none" method="POST">
        <div class="form-row">
            <div class="form-group col-md-2 mr-2">
                <input type="date" class="form-control" id="startdate" name="startdate">
            </div>
            <span> to </span>
            <div class="form-group col-md-2 ml-2">
                <input type="date" class="form-control" id="enddate" name="enddate">
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-info" name="searchsubmit" value="Search">
            </div>
        </div>
    </form>
    <?php

    if (isset($_POST['searchsubmit'])) {
        $startdate = $_POST['startdate'];
        $enddate = $_POST['enddate'];

        $sql = "SELECT * FROM customer_table_bill WHERE c_pdate BETWEEN '$startdate' AND '$enddate'";
        $result = mysqli_query($conn, $sql);
        $num = mysqli_num_rows($result);
        if ($num == 1) {
            echo "<div><p class='bg-dark text-white p-2 mt-4'>Details</p>
<table class='table'>
    <thead>
        <tr>
            <th>Customer Id</th>
            <th>Customer Name</th>
            <th>Address</th>
            <th>Product</th>
            <th>Quantity</th>
            <th>Price</th>
            <th>Total</th>
            <th>Date</th>
        </tr>
    </thead>";
            while ($row = mysqli_fetch_assoc($result)) {
                echo "
        <tr>
            <td>" . $row['c_id'] . "</td>
        
       
            <td>" . $row['c_name'] . "</td>
        
   
            <td>" . $row['c_add'] . "</td>
      
     
            <td>" . $row['c_pname'] . "</td>
      
   
            <td>" . $row['c_quan'] . "</td>
        
      
            <td>" . $row['c_each'] . "</td>
        
        
            <td>" . $row['c_total'] . "</td>
        
        
            <td>" . $row['c_pdate'] . "</td>
        </tr>";
            }
            echo "</table><div class=''><input type='submit' class='btn btn-info d-print-none' value='Print' onclick='window.print()'></div> </div>";
        }else{
            echo "<div class='alert alert-warning'>0 Result</div>";
        }
    }
    ?>
</div>

<?php

include("include/adminfooter.php");
?>