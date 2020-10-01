<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Assets");
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-9 col-md-10 mt-5 text-center">
    <p class="bg-dark text-white p-2">Prdouct Parts Details</p>
    <?php
    $sql = "SELECT * FROM assets";
    $result = mysqli_query($conn, $sql);
    if ($num = mysqli_num_rows($result) > 0) {
        echo "<table class='table'>
                <thead>
                  <tr>
                    <th>Product Id</th>
                    <th>Name</th>
                    <th>DOP</th>
                    <th>Available</th>
                    <th>Total</th>
                    <th>Original Cost Each</th>
                    <th>Selling Cost Each</th>
                    <th>Action</th>
                  </tr>
                </thead>    
                <tbody>";
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>
                          <td>" . $row['pid'] . "</td>   
                          <td>" . $row['pname'] . "</td> 
                          <td>" . $row['pdop'] . "</td> 
                          <td>" . $row['pava'] . "</td> 
                          <td>" . $row['ptotal'] . "</td> 
                          <td>" . $row['poriginalcost'] . "</td> 
                          <td>" . $row['psellingcost'] . "</td> 
                          <td><form action = 'editproduct.php' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['pid'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-info mr-3' name='edit' value='Edit'><i class='fas fa-pen'></i></button>                       
                               </form>
                               <form action = '' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['pid'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-dark mr-3' name='delete' value='Delete'><i class='fas fa-trash-alt'></i></button>                       
                               </form>
                                <form action = 'sellproduct.php' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['pid'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-warning mr-3' name='sell' value='Sell'><i class='fas fa-handshake'></i></button>                       
                               </form>
                           </td>                
                       </tr>";
        }

        echo " </tbody>
              </table>";
    } else {
        echo "<div class='alert alert-warning'> 0 Results </div>";
    }

    if (isset($_POST['delete'])) {
        $id = $_POST['id'];
        $sql = "DELETE FROM assets WHERE pid= '$id'";
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
<div class="float-right"><a href="addproduct.php" class="btn btn-danger"><i class="fas fa-plus fa-2x"></i></a></div>
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