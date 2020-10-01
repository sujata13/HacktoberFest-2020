   <?php

    if ($_SERVER['REQUEST_METHOD'] == "POST") {
        if (!empty($_POST['cname']) && !empty($_POST['csubject']) && !empty($_POST['cemail'])) {
            $cname = $_POST['cname'];
            $csubject = $_POST['csubject'];
            $cemail = $_POST['cemail'];
            $cmessage = $_POST['cmessage'];

            $mailto = ""; // enetr your mail;
            $headers = "From" . $mailto;
            $txt = "You have received mail from" . $cname . "\n\n" . $cmessage;

            mail($mailto, $csubject, $txt, $headers);
            $msg = "<div class='alert alert-success'>Sent Successfully</div>";
        }
    }

    ?>


   <div class="col-md-8">
       <form action="" method="post" class="mb-4">
           <input type="text" name="cname" placeholder="Name" class="form-control"> <br>
           <input type="text" name="csubject" placeholder="Subject" class="form-control"> <br>
           <input type="email" name="cemail" placeholder="Email" class="form-control"> <br>
           <textarea name="cmessage" id="" cols="30" rows="5" class="form-control" placeholder="How we can help you ?"></textarea> <br><br>
           <input type="submit" class="btn btn-primary" value="Send" name="submit">
       </form>
       <?php
         if(isset($msg)){
            echo $msg;
         }   
       ?>
   </div>