<?php
//Start session
session_start();
include 'head.php';
?>

<body class="sb-nav-fixed">
<?php
include 'nav.php';

if(!isset($_SESSION)) session_start();
//Include database connection details
require_once('config.php'); 

$conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


$sql = "SELECT * FROM status_ruang WHERE gedung = 'D3'";
$result = $conn->query($sql);

$d3;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$d3[] = $row;
}}

$sql2 = "SELECT * FROM status_ruang WHERE gedung = 'D4'";
$result = $conn->query($sql2);

$d4;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$d4[] = $row;
}}

$sql3 = "SELECT * FROM status_ruang WHERE gedung = 'PASCA'";
$result = $conn->query($sql3);

$pasca;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$pasca[] = $row;
}}
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
                                Data Kondisi Ruang
                            </div>
                            
                            <div class="card-body">
                                 
 
                                <div class="table-responsive">
                                <table border="0" cellspacing="5" cellpadding="5">
                                <tbody>
                                <tr>
                                    <td>Tanggal:</td>
                                    <td><input type="text" id="max" name="max"></td>
                                </tr>
                                </tbody></table>
                                <br>
                                    <h2>D3</h2>
                                    <table class="table table-bordered" id="tabel-dataa" width="100%" height="40" cellspacing="0">
                                        <thead>
                                            <tr>
                                            <th>Lantai</th>
                                                <th>Ruangan</th>
                                                <th>Status</th>
                                                <th>Keterangan</th>
                                                <th>Tanggal Dicek</th>
                                                <th>Pengecek</th>
                                            </tr>
                                        </thead>
                                        <tbody>

                                        <?php
                                        foreach ($d3 as $d3s) {
                                        ?>
                                        <?php echo "<tr>
                                        <td>" . $d3s->lantai . "</td>"?>
                                        <?php  echo "<td>". $d3s->ruangan . "</td>" ?>
                                        <?php  echo "<td>" . $d3s->status . "</td>" ?>
                                        <?php echo "<td>" . $d3s->keterangan . "</td>" ?>
                                        <?php echo "<td>" . $d3s->tanggal . "</td>" ?>
                                        <?php echo "<td>" . $d3s->pengecek . "</td>" ?>
                                        <?php echo '</tr>'?>
                                        
                                        <?php
                                            }
                                        ?>
                                        </tbody>
                                    </table>
                                    <br>
                                    <br>
                                    <h2>D4</h2>
                                    <table class="table table-bordered" id="tabel-dataaa" width="100%" height="40" cellspacing="0">
                                        <thead>
                                            <tr>
                                            <th>Lantai</th>
                                                <th>Ruangan</th>
                                                <th>Status</th>
                                                <th>Keterangan</th>
                                                <th>Tanggal Dicek</th>
                                                <th>Pengecek</th>
                                                
                                            </tr>
                                        </thead>
                                        <tbody>
                                                                                    <?php
                                        foreach ($d4 as $d4s) {
                                            ?>
                                            <?php echo "<tr>
                                            <td>" . $d4s->lantai . "</td>"?>
                                            <?php  echo "<td>". $d4s->ruangan . "</td>" ?>
                                            <?php  echo "<td>" . $d4s->status . "</td>" ?>
                                            <?php echo "<td>" . $d4s->keterangan . "</td>" ?>
                                            <?php echo "<td>" . $d4s->tanggal . "</td>" ?>
                                            <?php echo "<td>" . $d4s->pengecek . "</td>" ?>
                                            <?php echo '</tr>'?>
                                            
                                            <?php
                                                }
                                            ?>
                                        </tbody>
                                    </table>
                                    <br>
                                    <br>
                                    <h2>PASCA</h2>
                                    <table class="table table-bordered" id="tabel-dataaaa" width="100%" height="40" cellspacing="0">
                                        <thead>
                                            <tr>
                                            <th>Lantai</th>
                                                <th>Ruangan</th>
                                                <th>Status</th>
                                                <th>Keterangan</th>
                                                <th>Tanggal Dicek</th>
                                                <th>Pengecek</th>
                                            </tr>
                                        </thead>
                                        <tbody>

                                        <?php
                                        foreach ($pasca as $pascas) {
                                            ?>
                                            <?php echo "<tr>
                                            <td>" . $pascas->lantai . "</td>"?>
                                            <?php  echo "<td>". $pascas->ruangan . "</td>" ?>
                                            <?php  echo "<td>" . $pascas->status . "</td>" ?>
                                            <?php echo "<td>" . $pascas->keterangan . "</td>" ?>
                                            <?php echo "<td>" . $pascas->tanggal . "</td>" ?>
                                            <?php echo "<td>" . $pascas->pengecek . "</td>" ?>
                                            <?php echo '</tr>'?>
                                            
                                            <?php
                                                }
                                            ?>
                                        </tbody>
                                    </table>
                                </div>
                            </div>
                        </div>
                    </div>
                </main>

<?php
include 'footer.php';
?>
</body>