<?php
define('TITLE', 'Success');
include("include/header.php");
include("../connection.php");
session_start();
if (isset($_SESSION['loggedin'])) {
    $myid = $_SESSION['myid'];
} else {
    echo "<script> location.href='requesterlogin.php' </script>";
}

$sql = "SELECT * FROM submit_request WHERE req_id='$myid'";
$result = mysqli_query($conn, $sql);
$num = mysqli_num_rows($result);
if ($num == 1) {
    $row = mysqli_fetch_assoc($result);
    echo "<div class='ml-5 mt-5'>
    <table class='table'>
        <tbody>
            <tr>
                <th>Request ID</th>
                <td>" . $row['req_id'] . "</td>
            </tr>
            <tr>
                <th>Name</th>
                <td>" . $row['req_name'] . "</td>
            </tr>
            <tr>
                <th>Email</th>
                <td>" . $row['req_email'] . "</td>
            </tr>
            <tr>
                <th>Information</th>
                <td>" . $row['req_info'] . "</td>
            </tr>
            <tr>
                <th>Description</th>
                <td>" . $row['req_desc'] . "</td>
            </tr>
            <tr>
                <td><form class='d-print-none'><input class='btn btn-info' type='submit' value='Print' onclick='window.print()'></form></td>
            </tr>
        </tbody>
    </table>
</div>";
}
?>
<?php
include("include/footer.php");
?>
