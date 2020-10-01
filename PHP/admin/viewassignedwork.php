<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}

define('TITLE', 'ViewAssignedWork');
include("include/adminheader.php");
include("../connection.php");
?>

<div class="col-sm-6 mt-5 mx-3">
    <h3 class="text-center">Assigned Work Details</h3>
    <?php
    if (isset($_POST['view'])) {
        $id = $_POST['id'];
        $sql = "SELECT * FROM assign_work WHERE r_id = '$id'";
        $result = mysqli_query($conn, $sql);
        $row = mysqli_fetch_assoc($result); ?>
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
        <div class="text-center " >
            <form action="" class="d-inline">
                <input class="btn btn-info mx-2 d-print-none" type="submit" value="Print" onclick="window.print()"></form>
            <form action="work.php" class="d-inline">    
                <input class="btn btn-info d-print-none" type="submit" value="Close">
            </form>
        </div>
    <?php } ?>
</div>
<?php
include("include/adminfooter.php");
?>