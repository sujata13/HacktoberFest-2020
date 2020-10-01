<?php
session_start();
if (isset($_SESSION['loggedin'])) {
    $lemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='requesterlogin.php' </script>";
}
define('TITLE', 'RequesterProfile');
include("include/header.php");
include("../connection.php");



$sql = "SELECT user_name, user_email FROM user_registration WHERE user_email= '$lemail'";
$result = mysqli_query($conn, $sql);
$num = mysqli_num_rows($result);
if ($num == 1) {
    $row = mysqli_fetch_assoc($result);
    $pname = $row['user_name'];
}

//for updating name
if (isset($_POST['pupdate'])) {
    if (!empty($_POST['pname'])) {
        $pname = $_POST['pname'];
        $sql = "UPDATE user_registration SET user_name = '$pname' WHERE user_email = '$lemail'";
        $result = mysqli_query($conn, $sql);
        if ($result) {
            $remsg = '<div class="alert alert-success mt-2" role="alert">Update Successfull</div>';
        } else {
            $remsg = '<div class="alert alert-warning mt-2" role="alert">Unable to update</div>';
        }
    } else {
        $remsg = '<div class="alert alert-danger mt-2" role="alert">Name cannot be empty</div>';
    }
}
?>

<div class="col-sm-6 mt-5 font-weight-bold">
    <h2 style="font-family:  Ubuntu, sans-serif;">Update Profile</h2>
    <!--Profile Area-->
    <form action="" method="POST" class="mt-4">
        <div class="form-group">
            <!-- P= Profile-->
            <label for="inputemail">Email</label><input class="form-control" type="email" name="pemail" id="inputemail" value="<?php echo $_SESSION['lemail']; ?>" readonly>
        </div>
        <div class="form-group">
            <!-- P= Profile-->
            <label for="inputname">Name</label><input class="form-control" type="text" name="pname" id="inputname" value="<?php echo $pname; ?>">
        </div>
        <?php if (isset($remsg)) {
            echo $remsg;
        } ?>
        <div class="form-group">
            <!-- P= Profile-->
            <button class="btn btn-info" name="pupdate">Update</button>
        </div>
    </form>
</div>
<?php
include("include/footer.php");
?>