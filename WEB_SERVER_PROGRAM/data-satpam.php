<?php
//Start session
session_start();
include 'head.php';
?>

<body class="sb-nav-fixed">
<?php
include 'nav.php';
?>

<?php
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT * FROM data_satpam";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  // output data of each row

?>
<div id="layoutSidenav_content">
                <main>
                    <div class="container-fluid">
                        <div class="row">
                        </div>
                        <div class="row">
                        </div>
                        <div class="card mb-4">
                            <div class="card-header">
                                <i class="fas fa-table mr-1"></i>
                                Data Satpam
                            </div>
                            <div class="card-body"> <canvas id="myAreaChart" width="100%" height="40"></canvas>
                                <div class="table-responsive">
                                    <table class="table table-bordered" id="dataTable" width="100%" cellspacing="0">
                                        <thead>
                                            <tr>
                                                <th>id</th>
                                                <th>Nama</th>
                                                <th>NIP</th>
                                                <th>Email</th>
                                                <th>Password</th>
                                                <th>Posisi</th>
                                                <th>Alamat</th>
                                                <th>Umur</th>
                                                <th>Tanggal Masuk</th>
                                                <th>Nomor HP.</th>
                                            </tr>
                                        </thead>
                                        <tbody>
                                        <?php
                                          while($row = $result->fetch_assoc()) {
                                            echo 
                                        
                                            "<tr>
                                                <td>" . $row["u_id"] . "</td>
                                                <td>" . $row["nama"] . "</td>
                                                <td>" . $row["nip"] . "</td>
                                                <td>" . $row["email"] . "</td>
                                                <td>" ."***************" . "</td>
                                                <td>"  . $row["posisi"] . "</td>
                                                <td>" . $row["alamat"] . "</td>
                                                <td>" . $row["umur"] . "</td>
                                                <td>" . $row["tanggal_masuk"] . "</td>
                                                <td>" . $row["nomor_hp"] . "</td>
                                            </tr>";}
                                            ?>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                    </div>
                </main>

<?php
  }
 else {
  echo "0 results";
}
$conn->close();
include 'footerv2.php';
?>

</body>