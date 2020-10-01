<?php
session_start();
if (isset($_SESSION['loggedin'])) {
    $lemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='requesterlogin.php' </script>";
}
define('TITLE', 'CheckStatus');
include("include/header.php");
include("../connection.php");
?>


<!-- Start 2nd Column -->
<div class="col-sm-4 mt-5">
    <form action="" method="POST" class="form-inline d-print-none">
        <div class="form-group mr-3">
            <label for="checkid" class="font-weight-bold">Enter Request Id:</label>
            <input type="number" name="req_id" id="checkid" class="form-control ml-3">
        </div>
        <button class="btn btn-info" value="Search" type="submit">Submit</button>
    </form>
    <?php
if($_SERVER['REQUEST_METHOD']=='POST'){


    if(!empty($_POST['req_id'])){
        if (isset($_POST['req_id'])) {
            $id = $_POST['req_id'];
            $sql = "SELECT * FROM assign_work WHERE r_id = '$id'";
            $result = mysqli_query($conn, $sql);
            $row = mysqli_fetch_assoc($result);

            $sql2 = "SELECT * FROM submit_request WHERE req_id = '$id'";
            $result2 = mysqli_query($conn,$sql2);
            $row2 = mysqli_fetch_assoc($result2);
            if($id == isset($row['r_id'])){
        ?>
            <h3 class="text-center mt-5">Assign Work Details</h3>
            <table class="table table-bordered mt-3">
                <tbody>
                    <tr>
                        <td>Request Id </td>
                        <td><?php if (isset($row['r_id'])) {
                                echo $row['r_id'];;
                            }; ?></td>
                    </tr>
                    <tr>
                        <td>Request Info </td>
                        <td><?php if (isset($row['r_info'])) {
                                echo $row['r_info'];;
                            }; ?></td>
                    </tr>
                    <tr>
                        <td>Request Desc </td>
                        <td><?php if (isset($row['r_desc'])) {
                                echo $row['r_desc'];;
                            }; ?></td>
                    </tr>
                    <tr>
                        <td>Request Name </td>
                        <td><?php if (isset($row['r_name'])) {
                                echo $row['r_name'];;
                            }; ?></td>
                    </tr>
                    <tr>
                        <td>Technician Name </td>
                        <td><?php if (isset($row['assign_tech'])) {
                                echo $row['assign_tech'];;
                            }; ?></td>
                    </tr>
                    <tr>
                        <td>Assign Date </td>
                        <td><?php if (isset($row['assign_date'])) {
                                echo $row['assign_date'];;
                            }; ?></td>
                    </tr>
                    <tr>
                        <td>Customer Sign </td>
                        <td></td>
                    </tr>
                    <tr>
                        <td>Technician Sign </td>
                        <td></td>
                    </tr>
                </tbody>
            </table>
            <div class="text-center">
               <form action="">
                  <input class="btn btn-info mx-2 d-print-none" type="submit" value="Print" onclick="window.print()">
                  <input class="btn btn-info d-print-none" type="submit" value="Close">
               </form>
             
            </div>
        <?php }else if($id == isset($row2['req_id'])){
            echo "<div class='alert alert-warning mt-3'>Your request is still pending</div>";
        }
        else{
             echo "<div class='alert alert-warning mt-3'>Please enter correct Id</div>";
        }
      }
    }else{
        echo "<div class='alert alert-danger mt-3'>Please Enter Your Id</div>";
    }
 } ?>
</div>


<?php
include("include/footer.php");
?>

