<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $aemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Requests");
include("include/adminheader.php");
include("../connection.php");
?>

<!-- Start 2nd Column -->
<div class="col-sm-4 mb-5">
    <?php
    $sql = "SELECT req_id, req_info, req_desc, req_date FROM submit_request";
    $result = mysqli_query($conn, $sql);
    $num = mysqli_num_rows($result);
    if ($num > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            echo   '<div class="card mt-5 mx-5">
                    <div class="card-header font-weight-bold">
                        Request Id: '. $row['req_id'].'
                    </div>
                    <div class="card-body">
                      <h5 class="card-title">Request Info: ' . $row['req_info'] . '</h5>
                      <p class="card-text"><span class="font-weight-bold">Request Desc: </span>' . $row['req_desc'] . '</p>
                       <p class="card-text"><span class="font-weight-bold">Request Date: </span>' . $row['req_date'] . '</p>
                       <div class="float-right">
                         <form action="" method="post">
                          <input type="hidden" value="'.$row["req_id"]. '" name="id">
                          <input type="submit" class="btn btn-info mr-3" name="view" value="View">
                          <input type="submit" class="btn btn-info" name="close" value="Close"> 
                        </form>
                       </div>
                    </div>
                </div>';
        }
    };
    ?>
</div>
<!--End of 2nd Cloumn-->

<?php 
if(isset($_POST['view'])){
    $sql = "SELECT * FROM submit_request WHERE req_id = {$_POST['id']}";
    $result = mysqli_query($conn, $sql);
    $row = mysqli_fetch_assoc($result);
}
if(isset($_POST['close'])){
    $sql = "DELETE FROM submit_request WHERE req_id = {$_POST['id']}";
    $result = mysqli_query($conn,$sql);
    if($result){
       echo "<meta http-equiv='refresh' content= '0'; URL=?closed' / >";
    }else{
        echo "<div class='alert alert-warning'>Unable To delete</div>";
    }
}
?>
<?php
if(isset($_POST['assign'])){
 if(!empty($_POST['assigntech']) && !empty($_POST['assigndate']) && !empty($_POST['req_id'])){
        $rid = $_POST['req_id'];
        $rinfo = $_POST['req_info'];
        $rdesc = $_POST['req_desc'];
        $rname = $_POST['req_name'];
        $radd1 = $_POST['req_add1'];
        $radd2 = $_POST['req_add2'];
        $rcity = $_POST['req_city'];
        $rstate = $_POST['req_state'];
        $rzip = $_POST['req_zip'];
        $remail = $_POST['req_email'];
        $rnumber = $_POST['req_number'];
        $rassign = $_POST['assigntech'];
        $rdate = $_POST['assigndate'];

        $sql = "INSERT INTO `assign_work` ( `r_id`, `r_info`, `r_desc`, `r_name`, `r_add1`, `r_add2`, `r_city`, `r_state`, `r_zip`, `r_email`, `r_mobile`, `assign_tech`, `assign_date`) VALUES ( '$rid', '$rinfo', '$rdesc', '$rname', '$radd1', '$radd2', '$rcity', '$rstate', '$rzip', '$remail', '$rnumber', '$rassign', '$rdate')";
        $result = mysqli_query($conn,$sql);
        if($result){
            $remsg = "<div class='alert alert-success col-sm-6'>Work assign Successfully</div>";
        }else{
            $remsg = "<div class='alert alert-warning col-sm-6'>Work assign Unsuccessfully</div>";
        }
 }else{
     $remsg = "<div class='alert alert-danger col-sm-6'>Fill all details</div>";
 }
}?>
<div class="col-sm-6 jumbotron mt-5">
    <!-- Start Assign Workk-->
    <form class="mx-4 my-4" action="" method="POST">
        <h5 class="my-3">Assign Work Order Request</h5>
        <div class="form-group">
            <label for="reqid" class="font-weight-bold">Request Id</label>
            <input type="text" class="form-control" id="reqid" placeholder="Request Id" name="req_id" readonly value="<?php if(isset($row['req_id'])){echo $row['req_id'];} ?>">
        </div>
        <div class="form-group">
            <label for="reqinfo" class="font-weight-bold">Request Info</label>
            <input type="text" class="form-control" id="reqinfo" placeholder="Request Info" name="req_info" value="<?php if(isset($row['req_info'])){echo $row['req_info'];} ?>">
        </div>
        <div class="form-group">
            <label for="reqdesc" class="font-weight-bold">Request Desc</label>
            <input type="text" class="form-control" id="reqdesc" placeholder="Request Desc" name="req_desc"
            value="<?php if(isset($row['req_desc'])){echo $row['req_desc'];} ?>">
        </div>
        <div class="form-group">
            <label for="reqname" class="font-weight-bold">Requester Name</label>
            <input type="text" class="form-control" id="reqname" placeholder="Requester Name" name="req_name" 
            value="<?php if(isset($row['req_name'])){echo $row['req_name'];} ?>">
        </div>
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="reqaddress1" class="font-weight-bold">Address Line 1</label>
                <input type="text" class="form-control" id="reqaddress1" placeholder="Add Line 1" name="req_add1" value="<?php if(isset($row['req_add1'])){echo $row['req_add1'];} ?>">
            </div>
            <div class="form-group col-md-6">
                <label for="reqaddress2" class="font-weight-bold">Address Line 2</label>
                <input type="text" class="form-control" id="reqaddress2" placeholder="Add Line 2" name="req_add2" value="<?php if(isset($row['req_add2'])){echo $row['req_add2'];} ?>">
            </div>
        </div>
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="inputcity" class="font-weight-bold">City</label>
                <input type="text" class="form-control" id="inputcity" placeholder="Bilaspur" name="req_city"
                value="<?php if(isset($row['req_city'])){echo $row['req_city'];} ?>">
            </div>
            <div class="form-group col-md-4">
                <label for="inputstate" class="font-weight-bold">State</label>
                <input type="text" class="form-control" id="inputstate" placeholder="Chhattisgarh" name="req_state" value="<?php if(isset($row['req_id'])){echo $row['req_id'];} ?>">
            </div>
            <div class="form-group col-md-2">
                <label for="inputzip" class="font-weight-bold">Zipcode</label>
                <input type="number" class="form-control" id="inputzip" placeholder="495001" name="req_zip" value="<?php if(isset($row['req_zip'])){echo $row['req_zip'];} ?>">
            </div>
        </div>
        <div class="form-row">
            <div class="form-group col-sm-6">
                <label for="inputemail" class="font-weight-bold">Email</label>
                <input type="email" class="form-control" id="inputemail" placeholder="Email" name="req_email" 
                value="<?php if(isset($row['req_email'])){echo $row['req_email'];} ?>">
            </div>
            <div class="form-group col-md-6">
                <label for="inputnumber" class="font-weight-bold">Mobile</label>
                <input type="text" class="form-control" id="inputnumber" placeholder="Number" name="req_number" onkeypress="isInputNumber(event)" value="<?php if(isset($row['req_mobile'])){echo $row['req_mobile'];} ?>">
            </div>
        </div> 
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="assigntech" class="font-weight-bold">Assign Tech</label>
                <input type="text" class="form-control" id="assigntech" name="assigntech" placeholder="Assign Tech">
            </div>
            <div class="form-group col-md-6">
                <label for="assigndate" class="font-weight-bold">Date</label>
                <input type="date" class="form-control" id="assigndate" name="assigndate" value="<?php if(isset($row['req_id'])){echo $row['req_id'];} ?>">
            </div>
        </div>
        
        <div class="float-right">
            <button type="submit" class="btn btn-info" name="assign">Assign</button>
            <button type="reset" class="btn btn-info" name="resetrequest">Reset</button>
        </div>
        <?php if(isset($remsg)){echo $remsg;} ?>
    </form>
</div> <!-- End Assign form-->
<script>
    function isInputNumber(evt) {
        var ch = string.formCharCode(evt.which);
        if (!(/[0-9]/.test(ch))) {
            evt.preventDefault();
        }
    }
</script>
<?php

include("include/adminfooter.php");
?>