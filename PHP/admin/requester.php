<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Requester");
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-9 col-md-10 mt-5 text-center">
    <p class="bg-dark text-white p-2">List of Requester</p>
    <?php
    $sql = "SELECT * FROM user_registration";
    $result = mysqli_query($conn, $sql);
    if ($num = mysqli_num_rows($result) > 0) {
        echo "<table class='table'>
                <thead>
                  <tr>
                    <th>Requester Id</th>
                    <th>Name</th>
                    <th>Email</th>
                    <th>Action</th>
                  </tr>
                </thead>    
                <tbody>";
        while ($row = mysqli_fetch_assoc($result)) {
            echo "<tr>
                          <td>" . $row['user_sno_id'] . "</td>   
                          <td>" . $row['user_name'] . "</td> 
                          <td>" . $row['user_email'] . "</td> 
                          <td><form action = 'editreq.php' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['user_sno_id'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-info mr-3' name='edit' value='Edit'><i class='fas fa-pen'></i></button>                       
                               </form>
                               <form action = '' method='POST' class='d-inline'>
                                <input type='hidden' value=" . $row['user_sno_id'] . " name='id'>
                                <button type = 'submit' class = 'btn btn-dark mr-3' name='delete' value='Delete'><i class='fas fa-trash-alt'></i></button>                       
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
        $sql = "DELETE FROM user_registration WHERE user_sno_id= '$id'";
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
<div class="float-right"><a href="insertreq.php" class="btn btn-danger"><i class="fas fa-plus fa-2x"></i></a></div>
</div>

<!---End Container-->
<!-- Javascript -->
<script src="../js/jquery.min.js"></script>
<script src="../js/popper.min.js"></script>
<script src="../js/bootstrap.min.js"></script>
<script src="../js/all.min.js"></script>
</body>

</html>