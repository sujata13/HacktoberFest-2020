<?php
include('../../config.php');

if(isset($_POST['albumId'])){
    $albumId=$_POST['albumId'];
    $query=mysqli_query($con,"SELECT * from albums where id='$albumId'");
    $resultArray=mysqli_fetch_array($query);
    echo json_encode($resultArray);
}

?>