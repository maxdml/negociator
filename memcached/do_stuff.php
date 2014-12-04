<?php

$mem = new Memcached();
$mem->addServer("127.0.0.1",11211);

$conn = mysql_connect("127.0.0.1","test","testing123");
mysql_select_db("mem_test") or die(mysql_error());
//$fu = "INSERT INTO less_data (id,name) VALUES ('10','YES?!')";
//mysql_query($fu,$conn);

$query = "SELECT * FROM real_data" or die(mysql_error());
$querykey = "KEY" . md5($query);
//$result = mysql_query($query,$conn);

/*while ($row = mysql_fetch_array($result)) {
	echo $row["name"] . "\xA";
}*/

//echo $querykey;
$cosmos = $mem->get($querykey);
//var_dump($cosmos);

$result2 = mysql_query($query,$conn);

if ($cosmos) {
//	echo "Now it's in cache" . "\xA";
//	var_dump($cosmos);
//	echo $cosmos[0] . "\xA";
	foreach($cosmos as $value){
	echo "the value is ".$value ."\n";
}
} else {
	while ($row = mysql_fetch_array($result2)) {
//		echo 'the row id is ' .$row["id"] . "\n"; 
		$temp[$row["id"]] = $row["name"];
	//	echo $row["name"] . "\n";
	}
		$mem->set($querykey,$temp,10);

}
?>
