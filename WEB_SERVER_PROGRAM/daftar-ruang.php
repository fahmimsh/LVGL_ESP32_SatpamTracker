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
      
      $sql = "SELECT * FROM ruang";
      $result = $conn->query($sql);
      
      $ruang;
      
      if ($result->num_rows > 0) {
        // output data of each row
        while($row = mysqli_fetch_object($result)) {
         $ruang[] = $row;
      }}
      if(is_array($_POST) && count($_POST) > 0){
         $tgl = $_POST['tgl'];
         $shif = $_POST['shif'];   
      }else{
         $tgl = date("Y-m-d");
         $shif = 0; 
      }  
      ?>
   <div id="layoutSidenav_content">
      <main>
         <div class="container-fluid " style="padding:50px; background: #FFFFFF;box-shadow: 4px 4px 19px rgba(0, 0, 0, 0.25);border-radius: 12px;">
            <div class="row">
            </div>
            <div class="row">
            </div>
            <div class="card mb-4" style=" background: #FFFFFF;box-shadow: 4px 4px 19px rgba(0, 0, 0, 0.25);border-radius: 12px;">
               <div class="card-body">
                  <div class="table-responsive" >
                     <H4>Daftar Ruangan</H4>
                     <div class="row" style="padding-bottom: 25px;">
                        <div class="col-8">
                           <form action="" method="POST">
                              <table border="0" cellspacing="5" cellpadding="5" >
                                 <tbody>
                                    <tr>
                                       <td>Tanggal:</td>
                                       <td><input value="<?php echo $tgl; ?>" type="date" id="tgl" name="tgl"></td>
                                       <td>
                                          Shift:  
                                          <select class="form-select" id="shif" name="shif" aria-label="Disabled select example">
                                             <option value="0" selected>Semua Shift</option>
                                             <option value="1">06:00-08:00</option>
                                             <option value="2">13:00-14:00</option>
                                             <option value="3">16:00-17:00</option>
                                             <option value="4">23:00-24:00</option>
                                          </select>
                                       </td>
                                       <td><input class="btn" type="submit" value="Refresh"></td>
                                    </tr>
                                 </tbody>
                              </table>
                           </form>
                        </div>
                        <div class="col-4">
                           <button type="button" class="btn text-light" style="background: #655E8B;border-radius: 32px;  float: right;" data-toggle="modal" data-target="#exampleModal">Tambah Ruangan</button>
                        </div>
                     </div>
                     <table id="dataTablexz" width="100%" height="40" cellspacing="0" class="table table-dark" style="background: #36315B;  ">
                        <thead class="text-light">
                           <tr>
                              <th>Ruang</th>
                              <th>Keterangan</th>
                              <th>Kondisi</th>
                              <th>Terakhir Dicek</th>
                              <th>Pengecek</th>
                              <th>Hapus</th>
                           </tr>
                        </thead>
                        <tbody>
                           <?php
                              foreach ($ruang as $ruangs) {
                              ?>
                           <?php echo "<tr>
                              <td>" . $ruangs->ruang . "</td>"?>
                           <?php  echo "<td>". $ruangs->keterangan . "</td>" ?>
                           <?php  echo "<td>". getdatass(0, $tgl, $shif, $ruangs->ruang) . "</td>" ?>
                           <?php  echo "<td>". getdatass(1, $tgl, $shif, $ruangs->ruang) . "</td>" ?>
                           <?php  echo "<td>". getdatass(2, $tgl, $shif, $ruangs->ruang) . "</td>" ?>
                           <?php  echo '<td><a href="api_hapus_ruang.php?uid='.$ruangs->id_ruang.'" class="btn"><i class="fas fa-trash-alt"></i></a></tr>' ?>
                           <?php
                              }
                              ?>
                        </tbody>
                     </table>
                  </div>
               </div>
            </div>
         </div>
               <!-- Modal -->
      <div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
         <div class="modal-dialog modal-sm" role="document">
            <div class="modal-content">
               <div class="modal-header">
                  <h5 class="modal-title" id="exampleModalLabel">Tambah Ruangan</h5>
                  <button type="button" class="close" data-dismiss="modal" aria-label="Close">
                  <span aria-hidden="true">&times;</span>
                  </button>
               </div>
               <div class="modal-body">
                  <form role="form" action="api_tambah_ruang.php" method="post">
                     <div class="form-group">
                        <div class="container">
                                 <p>
                                    <label for="nama">Nama Ruangan:</label><br>
                                    <input type="text" name="nama" id="nama" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="ket">Keterangan:</label><br>
                                    <input type="text" name="ket" id="ket" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p>
                                 <p>
                                    <label for="rfid">RFID:</label><br>
                                    <input type="text" name="rfid" id="rfid" style="background: #F4ECFF;border: 1px solid #655E8B;box-sizing: border-box;border-radius: 32px;">
                                 </p><br>
                        </div>
                     </div>
                     <div align="right">
                        <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                        <button type="submit" class="btn btn-primary">Save changes</button>
                     </div>
                  </form>
               </div>
            </div>
         </div>
      </div>
      </main>
   </div>
   <?php
      function getdatass($mode, $tgl, $shif, $ruanganq){
      
         require_once('config.php');
      
         $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
         // Check connection
         if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
         }
         
         //centang
         if ($mode == 1){
               $sql = "SELECT waktu_cek FROM `data_tugas_new` WHERE `ruang` = '$ruanganq'";
            $result = $conn->query($sql);
            
            if ($result->num_rows > 0) {
               while($row = mysqli_fetch_array($result)) {
                  return $row['waktu_cek'];
               
            }}
            else{
               return "Belum Dicek";
            }
         }
         
         //kondisi
         if ($mode == 0){
            if($shif == 4){
               $sql = "SELECT status_ruangan FROM `data_tugas_new` WHERE `ruang` = '$ruanganq' AND (waktu_cek BETWEEN '$tgl 06:00' AND '$tgl 13:00')";}
            if($shif == 1){
               $sql = "SELECT status_ruangan FROM `data_tugas_new` WHERE `ruang` = '$ruanganq' AND (waktu_cek BETWEEN '$tgl 13:00' AND '$tgl 16:00')";}
            if($shif == 2){
               $sql = "SELECT status_ruangan FROM `data_tugas_new` WHERE `ruang` = '$ruanganq' AND (waktu_cek BETWEEN '$tgl 16:00' AND '$tgl 23:00')";}
            if($shif == 3){
               $sql = "SELECT status_ruangan FROM `data_tugas_new` WHERE `ruang` = '$ruanganq' AND (waktu_cek BETWEEN '$tgl 23:00' AND '$tgl 06:00')";}
            else{
               $sql = "SELECT status_ruangan FROM `data_tugas_new` WHERE `ruang` = '$ruanganq' AND (waktu_cek BETWEEN '$tgl 00:00' AND '$tgl 23:59')";}
            //echo $sql;
            $result = $conn->query($sql);
            
            if ($result->num_rows > 0) {
               while($row = mysqli_fetch_array($result)) {
                  return $row['status_ruangan'];
               
            }}
            else{
               return "Belum Dicek";
            }
         }          
      
         //posisi
         if ($mode == 2){
            $sql = "SELECT `satpam` FROM data_tugas_new WHERE ruang = '$ruanganq' ";
            $result = $conn->query($sql);
            
            if ($result->num_rows > 0) {
            // output data of each row
            while($row = mysqli_fetch_array($result)) {
               return $row['satpam'];
               
            }}
            else{
               return "Belum Diassign";
            }
         }
                
      
      }
      ?>
   <?php
      include 'footerv2.php';
      ?>
</body>