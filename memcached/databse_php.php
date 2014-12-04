
<?php
$mem = new Memcached();
$mem->addServer("127.0.0.1",11211);

$conn = mysql_connect("127.0.0.1", "test", "testing123") or die(mysql_error());
mysql_select_db("mem_test") or die(mysql_error());

for ($i = 0; $i< 1000;$i++){
	$myArray[$i] = "This is element ".$i." in the array";
	$sql = "INSERT INTO real_data (id,name) VALUES ('$i','$myArray[$i]')";
	mysql_query($sql,$conn); 
}

//$fu = "INSERT INTO more_data (id,name) VALUES ('10','yes??')";
//mysql_query($fu,$conn);
$query = "SELECT name FROM less_data";
$result = mysql_query($query,$conn);
//while ($row = mysql_fetch_array($result)) {
//	echo "in the while loop";
//	echo $row["name"];
//}
//$row = mysql_fetch_array($result);
//echo $row["name"];

$querykey = "KEY" . md5($query);

$result = $mem->get($querykey);


if ($result) {
	echo "result found";
	echo $result;
} else {
	echo "bl-wha ";
}


?>
