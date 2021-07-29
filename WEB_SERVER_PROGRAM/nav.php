<nav class="sb-topnav navbar navbar-expand" style="background: #FFFFFF;
box-shadow: 6px 6px 17px rgba(0, 0, 0, 0.25);">
            
            <button class="btn btn-link btn-lg" style="color: #38335C;" id="sidebarToggle" href="#!"><i class="fas fa-bars"></i></button>
            <!-- Navbar-->
            <div  >

                <?php if(isset($_SESSION['SESS_USER_ID'])) { ?>
                <a>Hi, <?php echo $_SESSION['SESS_USERNAME'] ?>!</a>
                <?php }else{ ?>
                <script type="text/javascript">location.href = 'login.php';</script>
                <!-- <a href="login.php">Login</a> -->
                <?php } ?>
            </div>

            <div style="display: flex; align-items: center; justify-content: center; margin: auto"><img href="index.php" style="width: 364px;height: 40px;" src="./assets/logo.svg"></img></div>
            <a href="#!"> <div style="left: 0%;right: 0%;top: 0%;bottom: 0%;background: #FB6060;border-radius: 40px;width: 90; height: 36; line-height: 12px;display: flex;align-items: center;text-align: center; justify-content: center; " style="cursor: pointer;" onclick="window.location='logout.php';" > <a>logout</a></div> </a>
        </nav>
        <div id="layoutSidenav" >
            <div id="layoutSidenav_nav" >
                <nav class="sb-sidenav accordion sb-sidenav-dark" id="sidenavAccordion" style="background: linear-gradient(123.27deg, #6B6391 6.82%, #36315B 95.63%);">
                    <div class="sb-sidenav-menu">
                        <div class="nav" >
                        <br>
                        <br>
                            <a class="nav-link" href="index.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-columns"></i></div>
                                Dashboard
                            </a>
                            
                            <div class="sb-sidenav-menu-heading" >Satpam</div>
                            <a class="nav-link" href="penugasan_new.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-list-ul"></i></div>
                                Penugasan
                            </a>
                            <a class="nav-link" href="presensi.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-id-card"></i></div>
                                Daftar Satpam
                            </a>
                            <a class="nav-link" href="admin.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-key"></i></div>
                                Administrator
                            </a>
                            
                            <div class="sb-sidenav-menu-heading">Ruangan</div>

                            <a class="nav-link" href="peminjaman.php">
                                <div class="sb-nav-link-icon"><i class="far fa-calendar-alt"></i></i></div>
                                Peminjaman
                            </a>
                            <a class="nav-link" href="daftar-ruang.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-door-closed"></i></i></div>
                                Data Ruangan
                            </a>

                        </div>
                    </div>
                </nav>
            </div>