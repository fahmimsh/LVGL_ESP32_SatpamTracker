<?php 
require_once(__DIR__.'/../config.php');
$user_id = $_GET['id'];
$link = mysqli_connect(DB_HOST, DB_USER, DB_PASSWORD);
if (!$link) {
	die("Cannot access db.");
}

$db = mysqli_select_db($link,DB_DATABASE);
if(!$db) {
	die("Unable to select database");
}

$res = mysqli_query($link,"SELECT * FROM tbl_user WHERE user_id=".$user_id." LIMIT 1");
$user = mysqli_fetch_assoc($res);

$ord_res = mysqli_query($link,"SELECT `tbl_order`.*,GROUP_CONCAT(`pd_name` SEPARATOR ', ') as `products`
						FROM `tbl_order`,`tbl_order_item`, `tbl_product`
						WHERE `tbl_order`.`od_id` = `tbl_order_item`.`od_id` 
						AND `tbl_product`.`pd_id` = `tbl_order_item`.`pd_id`
						AND user_id=".$user_id." GROUP BY `od_id`");


if ($ord_res->num_rows >0) {
	// output data of each row
	//echo ("[");
	while ($row = mysqli_fetch_object($ord_res)) {
		$orders[] = $row;
		$json = json_encode($orders);
		//echo $json;
		//echo (",");
	}
	//echo("]");
	
	
   } else {
	echo "0 results";
   }
   echo $json;
   $link->close();

?>