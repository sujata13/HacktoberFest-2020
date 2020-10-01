<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Work Report");
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

        $sql = "SELECT * FROM assign_work WHERE assign_date BETWEEN '$startdate' AND '$enddate'";
        $result = mysqli_query($conn, $sql);
        $num = mysqli_num_rows($result);
        if ($num == 1) {
            echo "<div><p class='bg-dark text-white p-2 mt-4'>Details</p>
<table class='table'>
    <thead>
        <tr>
            <th>Requester Id</th>
            <th>Requester Info</th>
            <th>Requester Desc</th>
            <th>Name</th>
            <th>Address</th>
            <th>City</th>
            <th>Mobile</th>
            <th>Technician</th>
            <th>Assigned Date</th>
        </tr>
    </thead>";
            while ($row = mysqli_fetch_assoc($result)) {
                echo "
        <tr>
            <td>" . $row['r_id'] . "</td>
        
       
            <td>" . $row['r_info'] . "</td>
            
            <td>" . $row['r_desc'] . "</td>
   
            <td>" . $row['r_name'] . "</td>
      
     
            <td>" . $row['r_add1'] . "</td>
      
   
            <td>" . $row['r_city'] . "</td>
        
      
            <td>" . $row['r_mobile'] . "</td>
        
        
            <td>" . $row['assign_tech'] . "</td>
        
        
            <td>" . $row['assign_date'] . "</td>
        </tr>";
            }
            echo "</table><div class=''><input type='submit' class='btn btn-info d-print-none' value='Print' onclick='window.print()'></div> </div>";
        } else {
            echo "<div class='alert alert-warning'>0 Result</div>";
        }
    }
    ?>
</div>

<?php

include("include/adminfooter.php");
?>