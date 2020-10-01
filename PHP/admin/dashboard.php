<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Dashboard");
include("include/adminheader.php");

?>

<?Php
// For diplaying Request Recieved
$sql = "SELECT max(req_id) FROM submit_request";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_row($result);
if ($row) {
    $show_row = $row[0];
}

// For displaying Assign Work
$sql = "SELECT max(r_number) FROM assign_work";
$result = mysqli_query($conn, $sql);
$row1 = mysqli_fetch_row($result);
if ($row1) {
    $show_work = $row1[0];
}


// For displaying Technician
$sql = "SELECT * FROM technician_assigned";
$result = mysqli_query($conn, $sql);
$row2 = mysqli_num_rows($result);
if ($row2) {
    $total_tech = $row2;
}

?>

<div class="col-md-10 col-sm-9">
    <!--Start 2nd column-->
    <div class="row text-center mt-5 ml-3">
        <div class="col-sm-4">
            <div class="card text-white bg-danger mb-3" style="max-width: 18rem;">
                <div class="card-header font-weight-bold">
                    Request Received
                </div>
                <div class="card-body">
                    <h4 class="card-title"><?php if (isset($show_row)) {
                                                echo $show_row;
                                            } else {
                                                echo 0;
                                            } ?></h4>
                </div>
                <a href="requests.php" class="btn text-white font-weight-bold">View</a>
            </div>
        </div>
        <div class="col-sm-4">
            <div class="card text-white bg-success mb-3" style="max-width: 18rem;">
                <div class="card-header font-weight-bold">
                    Assign Work
                </div>
                <div class="card-body">
                    <h4 class="card-title"><?php if (isset($show_work)) {
                                                echo $show_work;
                                            } else {
                                                echo 0;
                                            } ?></h4>
                </div>
                <a href="work.php" class="btn text-white font-weight-bold">View</a>
            </div>
        </div>
        <div class="col-sm-4">
            <div class="card text-white bg-info mb-3" style="max-width: 18rem;">
                <div class="card-header font-weight-bold">
                    No. of Technician
                </div>
                <div class="card-body">
                    <h4 class="card-title"><?php if (isset($total_tech)) {
                                                echo $total_tech;
                                            } else {
                                                echo 0;
                                            } ?></h4>
                </div>
                <a href="technician.php" class="btn text-white font-weight-bold">View</a>
            </div>
        </div> <!-- End 2 column - 1 column-->
    </div>
    <div class="mx-5 mt-5 text-center">
        <p class="bg-dark text-white p-2">List of Requesters</p>
        <?php
        $sql = "SELECT * FROM submit_request";
        $result = mysqli_query($conn, $sql);
        $num = mysqli_num_rows($result);
        if ($num > 0) {
            echo '
                            <table class="table">
                                <thead>
                                    <tr>
                                        <th>Requester Id</th>
                                        <th>Name</th>
                                        <th>Email</th>
                                    </tr>
                                </thead>
                                <tbody>';
            while ($row = mysqli_fetch_assoc($result)) {
                echo '<tr>
                                        <td>' . $row["req_id"] . '</td>
                                        <td>' . $row["req_name"] . '</td>
                                        <td>' . $row["req_email"] . '</td>
                                    </tr>';
            }
            echo '</tbody>
                            </table>';
        } else {
            echo "0 Result";
        }
        ?>
    </div>
</div>
<!--End 2nd Column-->


<?php



?>
<?php

include("include/adminfooter.php");
?>