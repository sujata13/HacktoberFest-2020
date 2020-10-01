<?php
session_start();
if (isset($_SESSION['loggedin'])) {
    $lemail = $_SESSION['lemail'];
} else {
    echo "<script> location.href='requesterlogin.php' </script>";
}
define('TITLE', 'Submit Request');
include("include/header.php");
include("../connection.php");



if (isset($_POST['submitrequest'])) {

    //checking for empty field

    if (!empty($_POST['rinfo'])|| !empty($_POST['rdesc'])|| !empty($_POST['rname'])|| !empty($_POST['radd1'])|| !empty($_POST['radd2'])|| !empty($_POST['rcity'])|| !empty($_POST['rzip'])|| !empty($_POST['rstate'])|| !empty($_POST['remail']) || !empty($_POST['rdate'])|| !empty($_POST['rnumber'])) {
        
       $rinfo = $_POST['rinfo'];
       $rdesc = $_POST['rdesc'];
       $rname = $_POST['rname'];
       $radd1 = $_POST['radd1'];
       $radd2 = $_POST['radd2'];
       $rcity = $_POST['rcity'];
       $rstate = $_POST['rstate'];
       $rzip = $_POST['rzip'];
       $remail = $_POST['remail'];
       $rmobile = $_POST['rnumber'];
       $rdate = $_POST['rdate'];
       
       $sql = "INSERT INTO submit_request ( req_info, req_desc, req_name, req_add1, req_add2, req_city, req_state, req_zip, req_email, req_mobile, req_date) VALUES ('$rinfo', '$rdesc', '$rname', '$radd1', '$radd2', '$rcity', '$rstate', '$rzip', '$remail', '$rmobile','$rdate')";

       $result = mysqli_query($conn, $sql);
       echo($result);
       
       if($result){
            $genid  = mysqli_insert_id($conn);
            $remsg = "<div class='alert alert-success mt-2 font-weight-bold'>Request submitted successfully</div>"; 
            $_SESSION['myid'] = $genid;
            echo "<script> location.href='submitrequestsuccess.php'</script>";

       }else{
            $remsg = "<div class='alert alert-warning mt-2 font-weight-bold'>Unable to perform request</div>";
       }

    } else {
        $remsg= "<div class='alert alert-warning mt-2 font-weight-bold'>All field are required</div>";
    }
}
?>

<div class="col-sm-9 coml-md-10 mt-5">
    <!-- Start service request form of 2nd column-->
    <form class="mx-4 my-4" action="" method="POST">
        <h2 class="my-3">Request Area</h2>
        <div class="form-group">
            <label for="inputrequestinfo" class="font-weight-bold">Request Information</label>
            <input type="text" class="form-control" id="inputrequestinfo" placeholder="Request Info"    name="rinfo">
        </div>
        <div class="form-group">
            <label for="inputrequestdesc" class="font-weight-bold">Description</label>
            <input type="text" class="form-control" id="inputrequestdesc" placeholder="Description" name="rdesc">
        </div>
        <div class="form-group">
            <label for="inputrequestname" class="font-weight-bold">Name</label>
            <input type="text" class="form-control" id="inputrequestname" placeholder="Name" name="rname">
        </div>
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="inputaddress1" class="font-weight-bold">Address Line 1</label>
                <input type="text" class="form-control" id="inputaddress1" placeholder="House no.123" name="radd1">
            </div>
            <div class="form-group col-md-6">
                <label for="inputaddress2" class="font-weight-bold">Address Line 2</label>
                <input type="text" class="form-control" id="inputaddress2" placeholder="Tikrapara" name="radd2">
            </div>
        </div>
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="inputcity" class="font-weight-bold">City</label>
                <input type="text" class="form-control" id="inputcity" placeholder="Bilaspur" name="rcity">
            </div>
            <div class="form-group col-md-4">
                <label for="inputstate" class="font-weight-bold">State</label>
                <input type="text" class="form-control" id="inputstate" placeholder="Chhattisgarh" name="rstate">
            </div>
            <div class="form-group col-md-2">
                <label for="inputzip" class="font-weight-bold">Zipcode</label>
                <input type="number" class="form-control" id="inputzip" placeholder="495001" name="rzip">
            </div>
        </div>
        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="inputemail" class="font-weight-bold">Email</label>
                <input type="email" class="form-control" id="inputemail" placeholder="Email" name="remail">
            </div>
            <div class="form-group col-md-2">
                <label for="inputnumber" class="font-weight-bold">Mobile</label>
                <input type="text" class="form-control" id="inputnumber" placeholder="Number" name="rnumber" onkeypress="isInputNumber(event)">
            </div>
            <div class="form-group col-md-2">
                <label for="inputdate" class="font-weight-bold">Date</label>
                <input type="date" class="form-control" id="inputdate" name="rdate">
            </div>
        </div>
        <button type="submit" class="btn btn-info" name="submitrequest">Submit</button>
        <button type="reset" class="btn btn-info" name="resetrequest">Reset</button>
    </form>
    <?php if(isset($remsg)){echo $remsg;} ?>
</div> <!-- End Service form-->
 

<!-- Only number for input field Js -->

<script>
    function isInputNumber(evt) {
        var ch = string.formCharCode(evt.which);
        if (!(/[0-9]/.test(ch))) {
            evt.preventDefault();
        }
    }
</script>

<?php
include("include/footer.php");
?>