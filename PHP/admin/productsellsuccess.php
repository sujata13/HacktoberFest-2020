<?php
session_start();
if (isset($_SESSION['adminloggedin'])) {
    $custid = $_SESSION['myid'];
} else {
    echo "<script> location.href='adminlogin.php' </script>";
}
define("TITLE", "Product Sell Success");
include("include/adminheader.php");
include("../connection.php");
?>

<?php
$sql = "SELECT * FROM customer_table_bill WHERE c_id = '$custid'";
$result = mysqli_query($conn, $sql);
$num = mysqli_num_rows($result);
if ($num == 1) {
    $row = mysqli_fetch_assoc($result);
    echo "
 <div class='ml-5 mt-5'>
  <h3>Customer Bill</h3>
    <table class='table mt-4'>
    <tbody>
        <tr>
            <th>Customer Id</th>
            <td>".$row['c_id']."</td>
        </tr>
        <tr>
            <th>Customer Name</th>
            <td>".$row['c_name']."</td>
        </tr>
        <tr>
            <th>Customer Address</th>
            <td>".$row['c_add']."</td>
        </tr>
        <tr>
            <th>Product Name</th>
            <td>".$row['c_pname']."</td>
        </tr>
        <tr>
            <th>Product Quantity</th>
            <td>".$row['c_quan']."</td>
        </tr>
        <tr>
            <th>Product Price</th>
            <td>".$row['c_each']."</td>
        </tr>
        <tr>
            <th>Total Price</th>
            <td>".$row['c_total']."</td>
        </tr>
        <tr>
            <th>Purchased Date</th>
            <td>".$row['c_pdate']. "</td>
        </tr>
        <tr>
           <td>
            <form class='d-print-none d-inline'>
                <input type='submit' class='btn btn-info d-print-none' value = 'Print' onclick='window.print()'>
            </form>
            <a href='assets.php' class='btn btn-info d-print-none d-inline'> Close </a>
          </td>
        </tr>
    </tbody>
   </table>
  </div>";
}


?>
 
<?php
include("include/adminfooter.php");
?>