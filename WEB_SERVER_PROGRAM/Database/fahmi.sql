-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: 202.157.176.228:21334
-- Generation Time: Aug 01, 2021 at 06:02 AM
-- Server version: 10.5.9-MariaDB-1:10.5.9+maria~focal
-- PHP Version: 7.4.15

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `fahmi`
--

-- --------------------------------------------------------

--
-- Table structure for table `data_masuk`
--

CREATE TABLE `data_masuk` (
  `id_data` int(10) NOT NULL,
  `ruang` varchar(255) NOT NULL,
  `status` varchar(255) NOT NULL,
  `date` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  `nama_ruang` varchar(255) NOT NULL,
  `nama_pengecek` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `data_masuk`
--

INSERT INTO `data_masuk` (`id_data`, `ruang`, `status`, `date`, `nama_ruang`, `nama_pengecek`) VALUES
(1, '2860360981', 'tidak_ada_masalah', '2021-07-26 20:00:06', 'GG-214F', ' Tanner Hatfield'),
(2, '2860360981', 'tidak_ada_masalah', '2021-07-26 20:09:22', 'GG-214F', ' Tanner Hatfield'),
(3, '2860360981', 'tidak_ada_masalah', '2021-07-26 20:34:54', 'GG-214F', 'Tanner Hatfield'),
(4, '2860360981', 'tidak_ada_masalah', '2021-07-28 10:42:30', 'CPRAS3', 'Tanner Hatfield painem'),
(5, '2208452640', 'Ada Masalah', '2021-07-28 12:11:51', 'CPRAS1', 'Tanner Hatfield painem'),
(6, '920925945', '1073421984', '2021-07-28 12:45:32', 'HH-102', 'Fahmi Mashuri'),
(7, '2208452640', 'Tidak Terdaftar', '2021-07-28 12:58:14', 'CPRAS1', 'Tanner Hatfield painem'),
(8, '2797023737', '1073421984', '2021-07-28 13:22:19', 'HH-103', 'Fahmi Mashuri'),
(9, '2521190137', '1073421984', '2021-07-28 13:24:20', 'HH-105', 'Fahmi Mashuri'),
(10, '1447176441', '1073421984', '2021-07-28 13:24:33', 'HH-106B', 'Fahmi Mashuri'),
(11, '3068081657', '1073421984', '2021-07-28 13:25:06', 'HH-201', 'Fahmi Mashuri'),
(12, '2532924409', '1073421984', '2021-07-28 13:25:49', 'HH-204T', 'Fahmi Mashuri'),
(13, '1187074297', '1073421984', '2021-07-28 13:26:19', 'JJ-101', 'Fahmi Mashuri'),
(14, '638264569', '1073421984', '2021-07-28 13:26:40', 'JJ-102', 'Fahmi Mashuri'),
(15, '3058055161', '1073421984', '2021-07-28 15:00:41', 'JJ-103', 'Fahmi Mashuri'),
(16, '920925945', 'Tidak Terdaftar', '2021-07-29 16:40:29', 'HH-102', 'Fahmi Mashuri'),
(17, '2797023737', 'Tidak ada Masalah', '2021-07-29 16:40:51', 'HH-103', 'Fahmi Mashuri'),
(18, '2521190137', 'Ada Masalah', '2021-07-29 16:41:07', 'HH-105', 'Fahmi Mashuri'),
(19, '1447176441', 'Ada Masalah', '2021-07-29 16:41:10', 'HH-106B', 'Fahmi Mashuri'),
(20, '3068081657', 'Ada Masalah', '2021-07-29 16:41:16', 'HH-201', 'Fahmi Mashuri'),
(21, '920925945', 'Tidak Terdaftar', '2021-07-29 16:51:03', 'HH-102', 'Fahmi Mashuri'),
(22, '2797023737', 'Tidak Terdaftar', '2021-07-29 16:51:07', 'HH-103', 'Fahmi Mashuri'),
(26, '2208452640', 'Tidak Terdaftar', '2021-07-30 02:02:54', 'CPRAS1', 'Tanner Hatfield painem'),
(27, '1795525922', 'Tidak ada Masalah', '2021-07-30 02:04:23', 'CPRAS4', 'Tanner Hatfield painem'),
(28, '2860360981', 'Tidak ada Masalah', '2021-07-30 02:04:34', 'CPRAS3', 'Tanner Hatfield painem'),
(29, '920925945', 'Tidak ada Masalah', '2021-07-30 09:16:04', 'HH-102', 'Fahmi Mashuri'),
(30, '2797023737', 'Tidak ada Masalah', '2021-07-30 09:20:54', 'HH-103', 'Fahmi Mashuri'),
(31, '1718327800', 'Ada Masalah', '2021-07-30 22:51:09', 'PS-03.08', 'Siswanto nur Hadi'),
(32, '105882872', 'Tidak ada Masalah', '2021-07-30 22:51:29', 'PS-03.10', 'Siswanto nur Hadi'),
(33, '4139498744', 'Tidak ada Masalah', '2021-07-30 22:52:01', 'PS-03.17', 'Siswanto nur Hadi'),
(34, '1448486137', 'Tidak ada Masalah', '2021-07-30 22:54:07', 'A 301', 'Musthafa Mahmud A'),
(35, '372034552', 'Tidak ada Masalah', '2021-07-30 22:54:25', 'A 302', 'Musthafa Mahmud A'),
(36, '3054521849', 'Tidak ada Masalah', '2021-07-30 22:54:32', 'A 303', 'Musthafa Mahmud A'),
(37, '1994237688', 'Tidak ada Masalah', '2021-07-30 22:55:29', 'A 304', 'Musthafa Mahmud A'),
(38, '3860638712', 'Tidak ada Masalah', '2021-07-30 22:55:44', 'B 202', 'Musthafa Mahmud A'),
(39, '3060873209', 'Tidak ada Masalah', '2021-07-30 22:56:12', 'B 203', 'Musthafa Mahmud A'),
(40, '3872893944', 'Tidak ada Masalah', '2021-07-30 22:56:15', 'B 204', 'Musthafa Mahmud A'),
(41, '650455545', 'Tidak ada Masalah', '2021-07-30 22:56:21', 'B 205', 'Musthafa Mahmud A'),
(42, '639062521', 'Tidak ada Masalah', '2021-07-30 23:05:48', 'PS-04.02', 'Siswanto nur Hadi'),
(43, '3596694265', 'Tidak ada Masalah', '2021-07-30 23:06:00', 'PS-04.07', 'Siswanto nur Hadi'),
(44, '1444881657', 'Ada Masalah', '2021-07-30 23:06:53', 'PS-04.08', 'Siswanto nur Hadi'),
(45, '4128845817', 'Tidak ada Masalah', '2021-07-30 23:07:29', 'HH-101', 'Ageng Ade Nusantara'),
(46, '920925945', 'Tidak ada Masalah', '2021-07-30 23:07:42', 'HH-102', 'Ageng Ade Nusantara'),
(47, '2797023737', 'Tidak ada Masalah', '2021-07-30 23:07:55', 'HH-103', 'Ageng Ade Nusantara'),
(48, '1995126009', 'Ada Masalah', '2021-07-30 23:11:24', 'HH-104', 'Ageng Ade Nusantara'),
(49, '2521190137', 'Ada Masalah', '2021-07-30 23:11:33', 'HH-105', 'Ageng Ade Nusantara'),
(50, '1447176441', 'Ada Masalah', '2021-07-30 23:12:01', 'HH-106B', 'Ageng Ade Nusantara'),
(51, '4142413305', 'Ada Masalah', '2021-07-30 23:12:22', 'HH-106T', 'Ageng Ade Nusantara'),
(52, '3068081657', 'Ada Masalah', '2021-07-30 23:12:39', 'HH-201', 'Ageng Ade Nusantara'),
(53, '3057819896', 'Ada Masalah', '2021-07-30 23:13:29', 'PS-04.13', 'Siswanto nur Hadi'),
(54, '1718327800', 'Tidak Terdaftar', '2021-07-31 08:09:21', 'PS-03.08', 'Siswanto nur Hadi'),
(55, '1448486137', 'Tidak Terdaftar', '2021-07-31 08:09:22', 'A 301', 'Musthafa Mahmud A'),
(56, '4128845817', 'Tidak Terdaftar', '2021-07-31 08:09:25', 'HH-101', 'Ageng Ade Nusantara'),
(57, '372034552', 'Ada Masalah', '2021-07-31 08:09:28', 'A 302', 'Musthafa Mahmud A'),
(58, '3054521849', 'Ada Masalah', '2021-07-31 08:09:31', 'A 303', 'Musthafa Mahmud A'),
(59, '920925945', 'Tidak Terdaftar', '2021-07-31 08:09:37', 'HH-102', 'Ageng Ade Nusantara'),
(60, '1994237688', 'Ada Masalah', '2021-07-31 08:09:39', 'A 304', 'Musthafa Mahmud A'),
(61, '105882872', 'Tidak ada Masalah', '2021-07-31 08:09:39', 'PS-03.10', 'Siswanto nur Hadi'),
(62, '920925945', 'Tidak Terdaftar', '2021-07-31 08:09:41', 'HH-102', 'Ageng Ade Nusantara'),
(63, '3860638712', 'Ada Masalah', '2021-07-31 08:09:42', 'B 202', 'Musthafa Mahmud A'),
(64, '4139498744', 'Tidak ada Masalah', '2021-07-31 08:09:44', 'PS-03.17', 'Siswanto nur Hadi'),
(65, '4128845817', 'Tidak ada Masalah', '2021-07-31 08:09:47', 'HH-101', 'Ageng Ade Nusantara'),
(66, '1448486137', 'Ada Masalah', '2021-07-31 08:09:48', 'A 301', 'Musthafa Mahmud A'),
(67, '4139498744', 'Tidak ada Masalah', '2021-07-31 08:09:48', 'PS-03.17', 'Siswanto nur Hadi'),
(68, '372034552', 'Ada Masalah', '2021-07-31 08:09:49', 'A 302', 'Musthafa Mahmud A'),
(69, '920925945', 'Tidak ada Masalah', '2021-07-31 08:09:49', 'HH-102', 'Ageng Ade Nusantara'),
(70, '639062521', 'Tidak ada Masalah', '2021-07-31 08:09:52', 'PS-04.02', 'Siswanto nur Hadi'),
(71, '4128845817', 'Tidak ada Masalah', '2021-07-31 08:09:52', 'HH-101', 'Ageng Ade Nusantara'),
(72, '3860638712', 'Ada Masalah', '2021-07-31 08:09:52', 'B 202', 'Musthafa Mahmud A'),
(73, '639062521', 'Tidak ada Masalah', '2021-07-31 08:09:54', 'PS-04.02', 'Siswanto nur Hadi'),
(74, '3060873209', 'Ada Masalah', '2021-07-31 08:09:56', 'B 203', 'Musthafa Mahmud A'),
(75, '639062521', 'Tidak ada Masalah', '2021-07-31 08:09:56', 'PS-04.02', 'Siswanto nur Hadi'),
(76, '3872893944', 'Ada Masalah', '2021-07-31 08:09:57', 'B 204', 'Musthafa Mahmud A'),
(77, '920925945', 'Tidak ada Masalah', '2021-07-31 08:09:59', 'HH-102', 'Ageng Ade Nusantara'),
(78, '650455545', 'Ada Masalah', '2021-07-31 08:10:00', 'B 205', 'Musthafa Mahmud A'),
(79, '3872893944', 'Ada Masalah', '2021-07-31 08:10:03', 'B 204', 'Musthafa Mahmud A'),
(80, '1447176441', 'Tidak ada Masalah', '2021-07-31 08:10:06', 'HH-106B', 'Ageng Ade Nusantara'),
(81, '2521190137', 'Tidak ada Masalah', '2021-07-31 08:10:09', 'HH-105', 'Ageng Ade Nusantara'),
(82, '4128845817', 'Tidak ada Masalah', '2021-07-31 08:10:26', 'HH-101', 'Ageng Ade Nusantara'),
(83, '920925945', 'Tidak ada Masalah', '2021-07-31 08:10:28', 'HH-102', 'Ageng Ade Nusantara'),
(84, '2797023737', 'Tidak ada Masalah', '2021-07-31 08:10:30', 'HH-103', 'Ageng Ade Nusantara'),
(85, '1995126009', 'Tidak ada Masalah', '2021-07-31 08:10:32', 'HH-104', 'Ageng Ade Nusantara'),
(86, '1995126009', 'Tidak ada Masalah', '2021-07-31 08:10:35', 'HH-104', 'Ageng Ade Nusantara'),
(87, '1995126009', 'Tidak ada Masalah', '2021-07-31 08:10:38', 'HH-104', 'Ageng Ade Nusantara'),
(88, '1447176441', 'Tidak Terdaftar', '2021-07-31 08:11:05', 'HH-106B', 'Ageng Ade Nusantara'),
(89, '1995126009', 'Tidak ada Masalah', '2021-07-31 08:11:15', 'HH-104', 'Ageng Ade Nusantara'),
(90, '920925945', 'Tidak ada Masalah', '2021-07-31 08:11:22', 'HH-102', 'Ageng Ade Nusantara'),
(91, '920925945', 'Tidak ada Masalah', '2021-07-31 08:11:23', 'HH-102', 'Ageng Ade Nusantara'),
(92, '3068081657', 'Tidak ada Masalah', '2021-07-31 08:11:27', 'HH-201', 'Ageng Ade Nusantara'),
(93, '3068081657', 'Tidak ada Masalah', '2021-07-31 08:11:29', 'HH-201', 'Ageng Ade Nusantara'),
(94, '4142413305', 'Tidak ada Masalah', '2021-07-31 08:12:15', 'HH-106T', 'Ageng Ade Nusantara'),
(95, '3596694265', 'Tidak ada Masalah', '2021-07-31 08:14:25', 'PS-04.07', 'Siswanto nur Hadi'),
(96, '1444881657', 'Tidak ada Masalah', '2021-07-31 08:14:28', 'PS-04.08', 'Siswanto nur Hadi'),
(97, '3057819896', 'Tidak ada Masalah', '2021-07-31 08:14:30', 'PS-04.13', 'Siswanto nur Hadi');

-- --------------------------------------------------------

--
-- Table structure for table `data_pinjaman`
--

CREATE TABLE `data_pinjaman` (
  `id` int(30) NOT NULL,
  `ruang` varchar(255) NOT NULL,
  `keperluan` varchar(255) NOT NULL,
  `waktu1` time(6) NOT NULL,
  `waktu2` time(6) NOT NULL,
  `nama` varchar(255) NOT NULL,
  `nrp` varchar(30) NOT NULL,
  `no_hp` varchar(30) NOT NULL,
  `tanggal_dipinjam` date NOT NULL,
  `tanggal_masuk` date NOT NULL DEFAULT current_timestamp(),
  `status` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `data_pinjaman`
--

INSERT INTO `data_pinjaman` (`id`, `ruang`, `keperluan`, `waktu1`, `waktu2`, `nama`, `nrp`, `no_hp`, `tanggal_dipinjam`, `tanggal_masuk`, `status`) VALUES
(5, 'GG-214F', 'acara HIMA', '20:25:00.000000', '23:26:00.000000', 'Fahmi Mashuri', '1103181001', '081234225506', '2021-07-14', '2021-07-27', 0),
(6, 'GG-214F', 'Acara HIMA', '06:04:00.000000', '08:08:00.000000', 'Adriansyah putra', '1103181021', '', '2021-07-28', '2021-07-28', 0),
(7, 'GG-214F', 'Acara HIMA', '09:28:00.000000', '01:31:00.000000', 'Adriansyah putra', '1103181021', '09217309429', '2021-07-29', '2021-07-29', 0),
(8, 'GG-214F', 'Acara HIMA', '09:28:00.000000', '01:31:00.000000', 'Adriansyah putra', '1103181021', '09217309429', '2021-07-29', '2021-07-29', 0),
(9, 'GG-214F', 'Acara HIMA', '09:46:00.000000', '00:45:00.000000', 'CPRAS1', '1103181021', '08117309429', '2021-07-30', '2021-07-30', 0);

-- --------------------------------------------------------

--
-- Table structure for table `data_presensi`
--

CREATE TABLE `data_presensi` (
  `id` int(10) NOT NULL,
  `u_id` varchar(11) NOT NULL,
  `nama` varchar(255) NOT NULL,
  `posisi` varchar(255) NOT NULL,
  `date` varchar(30) NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `data_presensi`
--

INSERT INTO `data_presensi` (`id`, `u_id`, `nama`, `posisi`, `date`) VALUES
(1, '1233646553', 'Tanner Hatfield', 'Advertising', '2021-06-19 16:30:25'),
(3, '1103181001', 'Erica Nanda', 'satpam', '2021-07-25 10:07:38'),
(5, '1103181001', 'Fahmi Mashuri', 'Satpam', '2021-07-26 00:28:17'),
(6, '1103181001', 'Erica Nanda', 'satpam', '2021-07-27 15:23:28'),
(7, '1233646553', 'Tanner Hatfield painem', 'Advertising', '2021-07-27 15:51:19'),
(8, '1103181001', 'Fahmi Mashuri', 'Satpam', '2021-07-28 04:35:05'),
(9, '1233646553', 'Tanner Hatfield painem', 'Advertising', '2021-07-28 11:05:23'),
(10, '1103181001', 'Fahmi Mashuri', 'Satpam', '2021-07-29 08:38:38'),
(14, '1103181016', 'Musthafa Mahmud A', 'Satpam', '2021-07-31 05:42:49'),
(15, '1103181028', 'Siswanto nur Hadi', 'Satpam', '2021-07-31 05:45:26'),
(16, '1103181009', 'Ageng Ade Nusantara', 'Satpam', '2021-07-31 05:47:01');

-- --------------------------------------------------------

--
-- Table structure for table `data_satpam_new`
--

CREATE TABLE `data_satpam_new` (
  `u_id` mediumint(255) NOT NULL,
  `rfid` varchar(255) DEFAULT NULL,
  `nip` varchar(255) DEFAULT NULL,
  `nama` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  `pass` varchar(255) DEFAULT NULL,
  `posisi` varchar(255) DEFAULT NULL,
  `alamat` varchar(255) DEFAULT NULL,
  `umur` mediumint(9) DEFAULT NULL,
  `tanggal_masuk` varchar(255) DEFAULT NULL,
  `nomor_hp` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `data_satpam_new`
--

INSERT INTO `data_satpam_new` (`u_id`, `rfid`, `nip`, `nama`, `email`, `pass`, `posisi`, `alamat`, `umur`, `tanggal_masuk`, `nomor_hp`) VALUES
(13, '1396664322', '1103181028', 'Siswanto nur Hadi', 'siswanto@satpm.pens.ac.id', '123456', 'Satpam', 'Keputih gang makan no12 Sukolilo Surabay', 34, NULL, '08123768765'),
(14, '958353195', '1103181016', 'Musthafa Mahmud A', 'Musthofa@satpm.pens.ac.id', '123456', 'Satpam', 'JL Gebang Putih No 13', 35, NULL, '083221394589'),
(15, '1754235690', '1103181009', 'Ageng Ade Nusantara', 'Agengade@satpm.pens.ac.id', '123456', 'Satpam', 'JL Gebang Lor No 19 Sukolilo Surabaya', 38, NULL, '0812346598');

-- --------------------------------------------------------

--
-- Table structure for table `data_tugas_new`
--

CREATE TABLE `data_tugas_new` (
  `id` int(11) NOT NULL,
  `ruang` varchar(255) NOT NULL,
  `nip` varchar(11) NOT NULL,
  `satpam` varchar(255) NOT NULL,
  `rfid` varchar(11) NOT NULL,
  `tanggal` date NOT NULL DEFAULT current_timestamp(),
  `status` int(2) NOT NULL,
  `status_ruangan` varchar(255) NOT NULL,
  `waktu_cek` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `data_tugas_new`
--

INSERT INTO `data_tugas_new` (`id`, `ruang`, `nip`, `satpam`, `rfid`, `tanggal`, `status`, `status_ruangan`, `waktu_cek`) VALUES
(72, 'PS-03.08', '1103181028', 'Siswanto nur Hadi', '1718327800', '2021-07-31', 1, 'Tidak Terdaftar', '2021-07-31 08:15:05'),
(73, 'PS-03.10', '1103181028', 'Siswanto nur Hadi', '105882872', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(74, 'PS-03.17', '1103181028', 'Siswanto nur Hadi', '4139498744', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(75, 'PS-04.02', '1103181028', 'Siswanto nur Hadi', '639062521', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(76, 'PS-04.07', '1103181028', 'Siswanto nur Hadi', '3596694265', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(77, 'PS-04.08', '1103181028', 'Siswanto nur Hadi', '1444881657', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(78, 'PS-04.13', '1103181028', 'Siswanto nur Hadi', '3057819896', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(79, 'A 301', '1103181016', 'Musthafa Mahmud A', '1448486137', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(80, 'A 302', '1103181016', 'Musthafa Mahmud A', '372034552', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(81, 'A 303', '1103181016', 'Musthafa Mahmud A', '3054521849', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(82, 'A 304', '1103181016', 'Musthafa Mahmud A', '1994237688', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(83, 'B 202', '1103181016', 'Musthafa Mahmud A', '3860638712', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(84, 'B 203', '1103181016', 'Musthafa Mahmud A', '3060873209', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(85, 'B 204', '1103181016', 'Musthafa Mahmud A', '3872893944', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(86, 'B 205', '1103181016', 'Musthafa Mahmud A', '650455545', '2021-07-31', 1, 'Ada Masalah', '2021-07-31 08:15:05'),
(87, 'HH-101', '1103181009', 'Ageng Ade Nusantara', '4128845817', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(88, 'HH-102', '1103181009', 'Ageng Ade Nusantara', '920925945', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(89, 'HH-103', '1103181009', 'Ageng Ade Nusantara', '2797023737', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(90, 'HH-104', '1103181009', 'Ageng Ade Nusantara', '1995126009', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(91, 'HH-105', '1103181009', 'Ageng Ade Nusantara', '2521190137', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(92, 'HH-106B', '1103181009', 'Ageng Ade Nusantara', '1447176441', '2021-07-31', 1, 'Tidak Terdaftar', '2021-07-31 08:15:05'),
(93, 'HH-106T', '1103181009', 'Ageng Ade Nusantara', '4142413305', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05'),
(94, 'HH-201', '1103181009', 'Ageng Ade Nusantara', '3068081657', '2021-07-31', 1, 'Tidak ada Masalah', '2021-07-31 08:15:05');

-- --------------------------------------------------------

--
-- Table structure for table `ruang`
--

CREATE TABLE `ruang` (
  `id_ruang` int(10) NOT NULL,
  `ruang` varchar(10) NOT NULL,
  `keterangan` varchar(255) DEFAULT NULL,
  `date` date NOT NULL DEFAULT current_timestamp(),
  `rfid_ruang` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `ruang`
--

INSERT INTO `ruang` (`id_ruang`, `ruang`, `keterangan`, `date`, `rfid_ruang`) VALUES
(0, 'GG-214F', 'Ruang Penjaminan Mutu & PSI', '2021-06-17', '2860360981'),
(339, 'HH-102', 'Ruang Kuliah', '2021-07-27', '920925945'),
(340, 'HH-103', 'Ruang Kuliah', '2021-07-27', '2797023737'),
(341, 'HH-104', 'Ruang Kuliah', '2021-07-27', '1995126009'),
(342, 'HH-105', 'Ruang Kuliah', '2021-07-27', '2521190137'),
(343, 'HH-106B', 'Ruang Kuliah', '2021-07-27', '1447176441'),
(344, 'HH-106T', 'Ruang Kuliah', '2021-07-27', '4142413305'),
(346, 'HH-201', 'Ruang Kuliah', '2021-07-27', '3068081657'),
(347, 'HH-202', 'Peraga Bahasa Inggris 2 D3', '2021-07-27', '103986937'),
(348, 'HH-204T', 'Ruang Kuliah', '2021-07-27', '2532924409'),
(349, 'JJ-101', 'Perancangan Sistem Elektronika', '2021-07-27', '1187074297'),
(350, 'JJ-102', 'Kendaraan Robotika D3', '2021-07-27', '638264569'),
(351, 'JJ-103', 'Lab Digital', '2021-07-27', '3058055161'),
(352, 'JJ-105', 'Ruang/Kamar Gelap (PCB)', '2021-07-27', '2251142648'),
(353, 'JJ-106', 'Teknik Sistem Tenaga D3', '2021-07-27', '1717456121'),
(354, 'JJ-107', 'Ruang Persiapan TST', '2021-07-27', '1983469049'),
(355, 'JJ-108', 'Ruang Riset Dosen', '2021-07-27', '647124985'),
(356, 'JJ-109', 'Pengukuran Listrik D3', '2021-07-27', '1996396536'),
(357, 'HH-101', 'Teater D3', '2021-07-27', '4128845817'),
(358, 'A 301', 'Classroom 11', '2021-07-27', '1448486137'),
(359, 'A 302', 'Classroom 12', '2021-07-27', '372034552'),
(360, 'A 303', 'Classroom 13', '2021-07-27', '3054521849'),
(361, 'A 304', 'Classroom 14', '2021-07-27', '1994237688'),
(362, 'B 202', 'Classroom 2', '2021-07-27', '3860638712'),
(363, 'B 203', 'Classroom 3', '2021-07-27', '3060873209'),
(364, 'B 204', 'Classroom 4', '2021-07-27', '3872893944'),
(365, 'B 205', 'Classroom 5', '2021-07-27', '650455545'),
(366, 'B 301', 'Classroom 6', '2021-07-27', '2516606457'),
(367, 'B 302', 'Classroom 7', '2021-07-27', '1913748643'),
(368, 'B 303', 'Classroom 8', '2021-07-27', '106143736'),
(369, 'B 304', 'Classroom 9', '2021-07-27', '3255074723'),
(370, 'B 305', 'Classroom 10', '2021-07-27', '3065092088'),
(371, 'C 303', 'Computer Vision D4', '2021-07-27', '2991892821'),
(372, 'D 105', 'Lab D4', '2021-07-27', '1655945302'),
(373, 'D 204', 'Lab D4', '2021-07-27', '317371477'),
(374, 'D 205', 'Lab D4', '2021-07-27', '1648835747'),
(375, 'D 305', 'Lab D4', '2021-07-27', '4138706424'),
(376, 'PS-03.04', 'Ruang Kuliah Pascasarjana Lt. 3', '2021-07-27', '14546135752'),
(377, 'PS-03.08', 'Ruang Kuliah Pascasarjana Lt. 3', '2021-07-27', '1718327800'),
(378, 'PS-03.10', 'Ruang Sidang Gedung Pascasarjana Lt.3', '2021-07-27', '105882872'),
(379, 'PS-03.17', 'PS-03.17', '2021-07-27', '4139498744'),
(380, 'PS-04.02', 'PS-04.02', '2021-07-27', '639062521'),
(381, 'PS-04.07', 'PS-04.07', '2021-07-27', '3596694265'),
(382, 'PS-04.08', 'PS-04.08', '2021-07-27', '1444881657'),
(383, 'PS-04.13', 'Pascasarjana', '2021-07-27', '3057819896'),
(384, 'PS-04.15', 'Pascasarjana', '2021-07-27', '1459443193'),
(385, 'PS-05.04', 'Ruang Kuliah Lt. 5 Ruang 4', '2021-07-27', '1225772331'),
(386, 'PS-05.05', 'Ruang Kuliah 5 S2 Lt.5', '2021-07-27', '381368057'),
(387, 'PS-05.08', 'PS-05.08', '2021-07-27', '2719740757'),
(388, 'PS-05.12', 'PS-05.12', '2021-07-27', '1459576313'),
(389, 'PS-05.13', 'S2 Lt.5 Ruang 13', '2021-07-27', '3604566521'),
(390, 'PS-09.02', 'PS-09.02', '2021-07-27', '880255261'),
(391, 'PS-09.05', 'Ruang Kuliah 5 Lt.9 S2', '2021-07-27', '1225772331'),
(392, 'PS-09.07', 'Ruang Kuliah 7 Lt.9', '2021-07-27', '1396664322'),
(393, 'CPRAS1', '1', '2021-07-28', '2208452640'),
(394, 'CPRAS2', '2', '2021-07-28', '2360568713'),
(395, 'CPRAS3', '3', '2021-07-28', '2860360981'),
(396, 'CPRAS4', '4', '2021-07-28', '1795525922');

-- --------------------------------------------------------

--
-- Table structure for table `tbl_user`
--

CREATE TABLE `tbl_user` (
  `user_id` int(10) UNSIGNED NOT NULL,
  `user_name` varchar(20) NOT NULL DEFAULT '',
  `password` varchar(128) NOT NULL DEFAULT '',
  `user_email` varchar(25) NOT NULL DEFAULT '',
  `created_at` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `user_is_admin` tinyint(1) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `tbl_user`
--

INSERT INTO `tbl_user` (`user_id`, `user_name`, `password`, `user_email`, `created_at`, `updated_at`, `user_is_admin`) VALUES
(9, 'Fahmimashuri', 'TAsatpampens', 'admin@mail.com', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1),
(10, 'admin', '123456', 'admin@mail.com', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `data_masuk`
--
ALTER TABLE `data_masuk`
  ADD PRIMARY KEY (`id_data`);

--
-- Indexes for table `data_pinjaman`
--
ALTER TABLE `data_pinjaman`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `data_presensi`
--
ALTER TABLE `data_presensi`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `data_satpam_new`
--
ALTER TABLE `data_satpam_new`
  ADD PRIMARY KEY (`u_id`);

--
-- Indexes for table `data_tugas_new`
--
ALTER TABLE `data_tugas_new`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `ruang`
--
ALTER TABLE `ruang`
  ADD PRIMARY KEY (`id_ruang`);

--
-- Indexes for table `tbl_user`
--
ALTER TABLE `tbl_user`
  ADD PRIMARY KEY (`user_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `data_masuk`
--
ALTER TABLE `data_masuk`
  MODIFY `id_data` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=98;

--
-- AUTO_INCREMENT for table `data_pinjaman`
--
ALTER TABLE `data_pinjaman`
  MODIFY `id` int(30) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `data_presensi`
--
ALTER TABLE `data_presensi`
  MODIFY `id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `data_satpam_new`
--
ALTER TABLE `data_satpam_new`
  MODIFY `u_id` mediumint(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `data_tugas_new`
--
ALTER TABLE `data_tugas_new`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=95;

--
-- AUTO_INCREMENT for table `ruang`
--
ALTER TABLE `ruang`
  MODIFY `id_ruang` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=397;

--
-- AUTO_INCREMENT for table `tbl_user`
--
ALTER TABLE `tbl_user`
  MODIFY `user_id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
