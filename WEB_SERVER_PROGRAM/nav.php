<nav class="sb-topnav navbar navbar-expand navbar-dark bg-dark">
            <a class="navbar-brand" href="index.php">Ini Nama</a>
            <button class="btn btn-link btn-sm order-1 order-lg-0" id="sidebarToggle" href="#!"><i class="fas fa-bars"></i></button>
            <!-- Navbar-->
            <div class="collapse navbar-collapse" role="navigation" id="navbar-main">
            <ul class="nav navbar-nav navbar-right">
              <li>
                <?php if(isset($_SESSION['SESS_USER_ID'])) { ?>

                  <li class="dropdown">
                    <a href="#" class="dropdown-toggle" data-toggle="dropdown">Hi, <?php echo $_SESSION['SESS_USERNAME'] ?>! <b class="caret"></b></a>
                    <ul class="dropdown-menu" style="">
                      <li>
                        <a href="logout.php">Logout</a>
                      </li>
                    </ul>
                  </li>

                <?php }else{ ?>
                <script type="text/javascript">location.href = 'login.php';</script>
                <!-- <a href="login.php">Login</a> -->
                <?php } ?>
              </li>
            </ul>
            </div>
        </nav>
        <div id="layoutSidenav">
            <div id="layoutSidenav_nav">
                <nav class="sb-sidenav accordion sb-sidenav-dark" id="sidenavAccordion">
                    <div class="sb-sidenav-menu">
                        <div class="nav">
                            <div class="sb-sidenav-menu-heading">Main</div>
                            <a class="nav-link" href="index.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-tachometer-alt"></i></div>
                                Dashboard
                            </a>
                            
                            <div class="sb-sidenav-menu-heading">Administrasi</div>
                            <a class="nav-link" href="penugasan.php">
                                Penugasan
                            </a>
                            <a class="nav-link" href="penugasan_new.php">
                                Penugasan (NEW)
                            </a>
                            <a class="nav-link" href="presensi.php">
                                Presensi
                            </a>
                            <a class="nav-link" href="data-satpam.php">
                                Data Satpam
                            </a>
                            <a class="nav-link" href="data-tugas.php">
                                Daftar Tugas
                            </a>
                            
                            <div class="sb-sidenav-menu-heading">Ruangan</div>

                            <a class="nav-link" href="form-pinjam.php">
                                Form Peminjaman
                            </a>
                            <a class="nav-link" href="daftar-ruang.php">
                                Daftar Ruang
                            </a>
                            <a class="nav-link" href="jadwal-ruang.php">
                                Jadwal Ruangan
                            </a>
                            <a class="nav-link" href="kondisi-ruang.php">
                                Kondisi Ruangan
                            </a>
                            <a class="nav-link" href="daftar-alat.php">
                                ID Alat
                            </a>

                        </div>
                    </div>
                    <div class="sb-sidenav-footer">
                        <div class="small">Logged in as:</div>
                        Admin
                    </div>
                </nav>
            </div>