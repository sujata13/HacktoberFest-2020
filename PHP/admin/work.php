<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Work");
include("include/adminheader.php");
include("../connection.php");
?>
<!--Start 2nd Column-->
<div class="col-sm-9 col-md-10 mt-5">
    <?php
    $sql = "SELECT * FROM assign_work";
    $result = mysqli_query($conn, $sql);
    $num = mysqli_num_rows($result);
    if ($num > 0) {
        echo "<table class='table'>
    <thead>
        <tr>
            <th>Req Id</th>
            <th>Req Info</th>
            <th>Name</th>
            <th>Address</th>
            <th>City</th>
            <th>Mobile</th>
            <th>Technician</th>
            <th>Assigned Date</th>
            <th>Action</th>
        </tr>
    </thead>
    <tbody>";
        while($row = mysqli_fetch_assoc($result)){
            $id = $row['r_id'];
        echo"<tr>
            <td>".$row['r_id']."</td>
            <td>".$row['r_info']."</td>
            <td>".$row['r_name']."</td>
            <td>".$row['r_add1']."</td>
            <td>".$row['r_city']."</td>
            <td>".$row['r_mobile']."</td>
            <td>".$row['assign_tech']."</td>
            <td>".$row['assign_date']. "</td>
            <td><form action='viewassignedwork.php' method='POST' class='d-inline'>
              <input type='hidden' name='id' value=".$id. ">
              <button class='btn btn-warning' name='view' type='submit'><i class='far fa-eye'></i></button>
            </form>
            <form class='d-inline' action='' method='POST'>
               <input type='hidden' name='id' value=" .$id. ">
              <button class='btn btn-info' name='delete' type='submit'><i class='far fa-trash-alt'></i></button>
            </form></td>
        </tr>";
        }
    echo"</tbody>
</table>";
    }else{
        echo "<div class='alert alert-warning'> No results</div>";
    }
    
    if(isset($_POST['delete'])){
       $id = $_POST['id'];
       $sql = "DELETE FROM assign_work WHERE r_id = '$id'";
       $result = mysqli_query($conn, $sql);
       if($result){
            echo "<meta http-equiv='refresh' content= '0'; URL=?closed' / >";
       }else{
           echo"Unable to delete";
       }
    }

    ?>

</div>

<?php

include("include/adminfooter.php");
?>