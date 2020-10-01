<?php
include("connection.php");

if(isset($_POST['rsignup'])){
    //Checking for empty feilds
    if($_POST['rname']== ''|| $_POST['remail']== '' || $_POST['rpass']== ''){
             $remsg = "<div class='alert alert-warning mt-2 font-weight-bold' role='alert'>All Fields are Required</div>";
    }else{
        $remail = $_POST['remail'];
        $sql = "SELECT user_email FROM user_registration WHERE user_email='$remail'";
        $result = mysqli_query($conn, $sql) ;
        $num = mysqli_num_rows($result);
        // Checking if email already exist
        if($num == 1){
            $remsg = "<div class='alert alert-danger mt-2 font-weight-bold' role='alert'>Email already Existed</div>";
        }else{
            $rname = $_POST['rname'];
            $remail = $_POST['remail'];
            $rpass = $_POST['rpass'];
            $sql = "INSERT INTO user_registration(user_name, user_email, user_pass) VALUE ('$rname','$remail','$rpass')";
            $result = mysqli_query($conn, $sql);
            // Checking if account is created or not
            if ($result) {
                $remsg = "<div class='alert alert-success mt-2 font-weight-bold' role='alert'>Account is sucessfully Created</div>";
            } else {
                $remsg = "<div class='alert alert-danger mt-2' role='alert'>Unable to Create Account</div>";
            }
        }
    }
}
?>


<!-- Registration Form Start -->
<div class="container pt-5" id="registration">
    <h2 class="text-center">Create an Account</h2>
    <div class="row mt-4 mb-4">
        <div class="col-md-6 offset-md-3">
            <form action="" method="post" class="shadow-lg p-4 rounded">
                <div class="form-group">
                    <i class="fas fa-user"></i><label for="name" class="font-weight-bold pl-2">Name</label><input type="text" class="form-control" placeholder="Name" name="rname">
                </div>
                <div class="form-group">
                    <i class="fas fa-user"></i><label for="email" class="font-weight-bold pl-2">Email</label><input type="email" class="form-control" placeholder="Email" name="remail">
                    <small class="form-text">We will never share email with anyone</small>
                </div>
                <div class="form-group">
                    <i class="fas fa-key"></i><label for="password" class="font-weight-bold pl-2">Password</label><input type="password" class="form-control" placeholder="Password" name="rpass">
                </div>
                <button type="submit" class="btn btn-info mt-5 btn-block shadow-lg font-weight-bold" name="rsignup">Sign Up</button>
                <em style="font-size:15px">Note- By clicking Signup you agree our T and C</em>
                <?php if(isset($remsg)){
                    echo $remsg;
                } ?>
            </form>
        </div>
    </div>
</div>
<!-- Registration Form End -->