<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Technician");
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-9 col-md-10 mt-5 text-center">
    <p class="bg-dark text-white p-2">List of Technician</p>
    <?php
    $sql = "SELECT * FROM technician_assigned";
    $result = mysqli_query($conn, $sql);
    if ($num = mysqli_num_rows($result) > 0) {
        echo "<table class='table'>
                <thead>
                  <tr>
                    <th>Requester Id</th>
                    <th>Name</th>
                    <th>City</th>
                    <th>Mobile</th>
                    <th>Email</th>
                    <th>Action</th>
                  </tr>
                </thead>    
                <tbody>";
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>
                          <td>" . $row['emp_id'] . "</td>   
                          <td>" . $row['emp_name'] . "</td> 
                          <td>" . $row['emp_city'] . "</td> 
                          <td>" . $row['emp_mobile'] . "</td> 
                          <td>" . $row['emp_email'] . "</td> 
                          <td><form action = 'edittech.php' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['emp_id'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-info mr-3' name='edit' value='Edit'><i class='fas fa-pen'></i></button>                       
                               </form>
                               <form action = '' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['emp_id'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-dark mr-3' name='delete' value='Delete'><i class='fas fa-trash-alt'></i></button>                       
                               </form>
                           </td>                
                       </tr>";
        }

        echo " </tbody>
              </table>";
    } else {
        echo "<div class='alert alert-warning'> </div>";
    }

    if (isset($_POST['delete'])) {
        $id = $_POST['id'];
        $sql = "DELETE FROM technician_assigned WHERE emp_id= '$id'";
        $result = mysqli_query($conn, $sql);
        if ($result) {
            echo "<meta http-equiv='refresh' content= '0'; URL=?closed' / >";
        } else {
            echo "Unable to Delete";
        }
    }
    ?>
</div>

</div> <!-- End Row -->
<div class="float-right"><a href="inserttech.php" class="btn btn-danger"><i class="fas fa-plus fa-2x"></i></a></div>
</div>

<!---End Container-->
<!-- Javascript -->
<script src="../js/jquery.min.js"></script>
<script src="../js/popper.min.js"></script>
<script src="../js/bootstrap.min.js"></script>
<script src="../js/all.min.js"></script>
</body>

</html>


<?php

include("include/adminfooter.php");
?>