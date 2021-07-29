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
$sql = "SELECT * FROM `tbl_user`";
$result = $conn->query($sql);

$nama;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
   $nama[] = $row;
}}
?>
<div id="layoutSidenav_content">
<main>
      <div class="container-fluid " style="margin:auto;display: flex;align-items: center;justify-content: center;padding:50px;">
         <div class="row">
         </div>
         <div class="row">
         </div>
         <div class="card mb-4 "  style="  width:50%;padding:50px; background: #FFFFFF;box-shadow: 4px 4px 19px rgba(0, 0, 0, 0.25);border-radius: 12px;">
         <H3>Profil Admin</H3>
            <div class="card-body">
            <form role="form" action="api_tambah_admin.php" method="post">
                     <div class="form-group">
            <div class="container">
            <div class="row">
    <div class="col">
      
    <p>
                                    <label for="nama">Nama:</label><br>
                                    <input type="text" name="nama" id="nama" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="email">Email:</label><br>
                                    <input type="text" name="email" id="email" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
    </div>
    <div class="col">
    <p>
                                    <label for="password">Password:</label><br>
                                    <input type="password" id="password" name="password" class="form-control" placeholder="Password" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p><br>
                                 <button type="button" class="btn btn-secondary" data-toggle="modal" data-target="#exampleModal">Edit Admin</button>
                        <button type="submit" class="btn btn-primary">Save changes</button>
                                 </p>
    </div>
  </div>
</div>
</div>
                  </form>


            </div>
         </div>
      </div>
                     <!-- Modal -->
                     <div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
         <div class="modal-dialog modal-lg" role="document">
            <div class="modal-content">
               <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">Tambah Ruangan</h5>
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                  </button>
               </div>
               <div class="modal-body">
               <table id="tabel-dataa" width="100%" height="40" cellspacing="0" class="table table-striped table-dark" style="background: #36315B; ">
                     <thead class="text-light">
                        <tr>
                           <th>Nama</th>
                           <th>Email</th>
                           <th>Password</th>
                           <th>Hapus</th>
                        </tr>
                     </thead>
                     <tbody>
                        <?php
                           foreach ($nama as $namas) {
                           ?>
                        <?php echo "<tr>
                           <td>" . $namas->user_name . "</td>"?>
                        <?php  echo "<td>". $namas->user_email . "</td>" ?>
                        <?php  echo "<td>". "********" . "</td>"?>
                        <?php  echo '<td><a href="api_hapus_admin.php?uid='.$namas->user_id.'" class="btn"><i class="fas fa-trash-alt"></i></a></td></tr>' ?>
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
include 'footerv2.php';
?>
</body>