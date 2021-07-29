<?php
   //Start session
   session_start();
   include 'head.php';
   ?>
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

   $sql = "SELECT ruang.* FROM ruang WHERE NOT EXISTS(SELECT 1 FROM data_tugas_new WHERE data_tugas_new.ruang=ruang.ruang)";
$result = $conn->query($sql);

$ruangx;

if ($result->num_rows > 0) {
  // output data of each row
  while($row = mysqli_fetch_object($result)) {
	$ruangx[] = $row;
}}
   
   $sql = "SELECT * FROM data_tugas_new";
   $result = $conn->query($sql);
   
   $patroli;
   
   if ($result->num_rows > 0) {
     // output data of each row
     while($row = mysqli_fetch_object($result)) {
      $patroli[] = $row;
   }}

   $sql = "SELECT * FROM data_satpam_new";
   $result = $conn->query($sql);
   
   $satpam;
   
   if ($result->num_rows > 0) {
     // output data of each row
     while($row = mysqli_fetch_object($result)) {
      $satpam[] = $row;
   }}

   $sql = "SELECT ruang FROM ruang";
   $result = $conn->query($sql);

   $ruang;

   if ($result->num_rows > 0) {
   // output data of each row
   while($row = mysqli_fetch_object($result)) {
	   $ruang[] = $row;
   }}

   
   ?>
<script type="text/javascript"> 
   function display_c(){
   var refresh=1000; // Refresh rate in milli seconds
   mytime=setTimeout('display_ct()',refresh)
   }
   
   function display_ct() {
   var x = new Date()
   document.getElementById('ct').innerHTML = x;
   display_c();
    }
</script>
<body class="sb-nav-fixed " onload=display_ct();>
   <div id="layoutSidenav_content">
   <main>
      <div class="container-fluid">
      <h1 class="mt-4"></h1>
      <div class="row">
         <div class="col-xl-4 col-md-6">
            <div class="card text-white mb-4" style="background: linear-gradient(123.27deg, #6B6391 6.82%, #36315B 95.63%);box-shadow: 6px 6px 19px rgba(0, 0, 0, 0.35);border-radius: 12px;">
               <div class="card-body"><span id='ct' ></span> </div>
            </div>
            <div class="card mb-4">
               <div class="card-header">
                  <H3>Status Patroli Ruangan</H3>
               </div>
               <div class="card-body">
                  <div >
                     <table class="table table-striped table-dark"  width="100%" cellspacing="0">
                        <thead class="text-light">
                           <tr>
                              <th>Ruang</th>
                              <th>Waktu</th>
                              <th>Kondisi</th>
                           </tr>
                        </thead>
                        <tbody>
                        <?php
                                        foreach ($patroli as $patrolis) {
                                        ?>
                                        <?php echo "<tr>
                                        <td>". getdatass(1,$patrolis->ruang) . $patrolis->ruang . "</td>"?>
                                        <?php  echo "<td>". $patrolis->waktu_cek . "</td>" ?>
                                        <?php  echo "<td>" . getdatass(0,$patrolis->ruang) . "</td></tr>" ?>
                                        <?php
                                            }
                                        ?>
                        </tbody>
                     </table>
                  </div>
               </div>
            </div>
         </div>
         <div class="col-12 col-sm-6 col-md-8">
            <div class="card mb-4">
               <div class="card-header">
                  <h3>Patroli Hari Ini</h3>
               </div>
               <div class="card-body">
                  <div>
                  <table class="table table-striped table-dark" style="background: #36315B;" width="100%" cellspacing="0">
                        <thead class="text-light">
                           <tr>
                              <th>Posisi</th>
                              <th>Satpam</th>
                              <th>Waktu Cek</th>
                              <th>Histori</th>
                           </tr>
                        </thead>
                        <tbody>
                        <?php
                                        foreach ($satpam as $satpams) {
                                        ?>
                                        <?php echo "<tr>
                                        <td>" . getdatass(2,$satpams->nama) . "</td>"?>
                                        <?php  echo "<td>". $satpams->nama . "</td>" ?>
                                        <?php  echo "<td>". getdatass(3,$satpams->nama) . "</td>" ?>
                                        <?php  echo '<td><button class="btn"  data-toggle="modal" data-target="#report'.$satpams->u_id.'"><i class="far fa-clock"></i></button></td></tr>' ?>
                                        <?php
                                            }
                                        ?>
                        </tbody>
                     </table>
                     <?php
                        echo button();
                     ?>
                     
                  </div>
               </div>
            </div>
         </div>
      </div>
      <?php
                           foreach ($satpam as $satpams) {
                            echo '<!-- Modal -->
                                <div class="modal fade " id="report'.$satpams->u_id.'" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
                                <div class="modal-dialog modal-lg" role="document">
                                <div class="modal-content">
                                    <div class="modal-body">

                                    <table class="table table-striped table-dark" style="background: #36315B;" width="100%" cellspacing="0">
                        <thead class="text-light">
                           <tr>
                              <th>Ruang</th>
                              <th>Konsidi</th>
                              <th>Waktu Cek</th>
                           </tr>
                        </thead>
                        <tbody>';

                        $sql = "SELECT * FROM data_masuk WHERE nama_pengecek = '$satpams->nama' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC";
                        $result = $conn->query($sql);
                        
                        if ($result->num_rows > 0) {
                           while($row = mysqli_fetch_array($result)) {
                              
                              echo "<tr><td>" . $row['nama_ruang'] . "</td>";
                                          echo "<td>". $row['status'] . "</td>" ;
                                          echo "<td>". $row['date'] . "</td>" ;
                           
                        }}
                        else{
                           echo "<tr><td>" . "Belum Cek" . "</td>";
                                          echo "<td>". "Belum Cek" . "</td>" ;
                                          echo "<td>". "Belum Cek" . "</td>" ;
                        }
                        
                                        
                        echo '</tbody>
                     </table>
                                        
                                            <div align="right">
                                            <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
                                            </div>
                                        </form>
                                    </div>
                                </div>
                                </div>
                            </div>';
                           }
                           ?>
                            <!-- Modal -->
<div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
  <div class="modal-dialog modal-dialog-centered" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <h5 class="modal-title" id="exampleModalLabel" style="font-weight: bold;font-size: 24px;line-height: 28px;display: flex;align-items: center;">Tambah Penugasan</h5>
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
      </div>
      <div class="modal-body">


    <form action="api_tambah_tugas.php" method="post">        
    <div class="form-group">
    <label for="exampleFormControlSelect1">Nama Satpam</label>
    <select class="form-control" name="namanya" id="exampleFormControlSelect1">

    <?php
                    foreach ($satpam as $satpams) {
                      echo '<option>'.$satpams->nama.'</option>';
                    }
                ?>
    </select>
    <br>
    <label for="exampleFormControlSelect1">Tugas</label>
      <select class="chosen-select" name="taglist[]" id="taglist" tabindex="8" multiple="" style="width:100%;height:50px" data-placeholder="Pilih Tugas">
                <option value=""></option>
                <?php
                    foreach ($ruangx as $ruangxs) {
                      echo '<option>'.$ruangxs->ruang.'</option>';
                    }
                ?>
                
            </select>
      </div>
      <button type="button" class="btn btn-secondary" data-dismiss="modal">Close</button>
      <button type="submit" class="btn btn-primary">Save changes</button>
    </form>
    </div>
    <div class="modal-footer">





      </div>
    </div>
  </div>
</div>
   </main>


                  <?php
                     function getdatass($mode, $ruanganq){
                     
                        require_once('config.php');
                     
                        $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
                        // Check connection
                        if ($conn->connect_error) {
                           die("Connection failed: " . $conn->connect_error);
                        }
                        
                        //centang
                        if ($mode == 1){
                           $sql = "SELECT status FROM data_masuk WHERE `nama_ruang` = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                              return "<i class='fas fa-check'></i>";
                              
                           }
                           else{
                              return "<i class='fas fa-times-circle'></i>";
                           }
                        }
                        
                        //centang
                        if ($mode == 0){
                           $sql = "SELECT status FROM data_masuk WHERE `nama_ruang` = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                              while($row = mysqli_fetch_array($result)) {
                                 return $row['status'];
                              
                           }}
                           else{
                              return "Belum Dicek";
                           }
                        }          

                        //posisi
                        if ($mode == 2){
                           $sql = "SELECT `nama_ruang` FROM data_masuk WHERE nama_pengecek = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                           // output data of each row
                           while($row = mysqli_fetch_array($result)) {
                              return $row['nama_ruang'];
                              
                           }}
                           else{
                              return "Belum Patroli";
                           }
                        }
                     
                        //waktu cek
                        if ($mode == 3){
                           $sql = "SELECT date FROM data_masuk WHERE nama_pengecek = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                           // output data of each row
                           while($row = mysqli_fetch_array($result)) {
                              return $row['date'];
                              
                           }}
                           else{
                              return "Belum Patroli";
                           }
                        }   
                        //Jumlah Yang dicek
                        if ($mode == 4){
                           $sql = "SELECT gedung FROM data_ruang WHERE ruang = '$ruanganq' AND date > NOW() - INTERVAL 4 DAY_HOUR ORDER BY `date` DESC LIMIT 1";
                           $result = $conn->query($sql);
                           
                           if ($result->num_rows > 0) {
                           // output data of each row
                           while($row = mysqli_fetch_array($result)) {
                              return $row['gedung'];
                              
                           }}
                        }            
                     
                     }

      function button(){
      
         require_once('config.php');
     
         $conn = new mysqli(DB_HOST, DB_USER, DB_PASSWORD, DB_DATABASE);
         // Check connection
         if ($conn->connect_error) {
           die("Connection failed: " . $conn->connect_error);
         }

            $sql = "SELECT id FROM data_tugas_new WHERE status = 0";
            $result = $conn->query($sql);
            
            if ($result->num_rows > 0) {
              return '                     
              <a href="mulai.php?mulai=1&tempat=0" type="button" class="btn btn-primary" style="background: #FB6060; border-color: #60FBD5; color: #000; border-radius: 32px;">Hentikan Patroli</a>
              <button type="button" class="btn text-light" style="background: #655E8B; border-radius: 32px;" data-toggle="modal" data-target="#exampleModal" disabled>Tambah Patroli</button>';
                
            }else{
               return '                     
               <a href="mulai.php?mulai=0&tempat=0" type="button" class="btn btn-primary" style="background: #60FBD5; border-color: #60FBD5; color: #000; border-radius: 32px;">Mulai Patroli</a>
               <button type="button" class="btn text-light" style="background: #655E8B; border-radius: 32px;">Hasil Patroli</button>
               <button type="button" class="btn text-light" style="background: #655E8B; border-radius: 32px;" data-toggle="modal" data-target="#exampleModal">Tambah Patroli</button>';
            }

      }


      
      ?>


</body>

<?php
include 'footerv2.php';
?>