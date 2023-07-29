<?php
$host = '127.0.0.1';
$db   = 'homelesscredits';
$user = 'uptweet';
$pass = 'fuckthat';
$charset = 'utf8mb4';

$dsn = "mysql:host=$host;dbname=$db;charset=$charset";
$options = [
    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    PDO::ATTR_EMULATE_PREPARES   => false,
];
$pdo = new PDO($dsn, $user, $pass, $options);

$return_json_object = [];
$return_json_object["parcela_informacion_available"] = -1;
$stmt = $pdo->query('SELECT result_hash, timestamp FROM parcela ORDER BY timestamp DESC LIMIT 0,1;');
$row = $stmt->fetch();
if($stmt->rowCount() > 0)
{
    //define output
    $return_json_object["parcela_informacion_available"] = 1;
    $return_json_object["result_hash"] = $row["result_hash"];
    $return_json_object["timestamp"] = $row["timestamp"];

}else if($stmt->rowCount() == 0)
{
    $return_json_object["parcela_informacion_available"] = 0;
}

echo json_encode($return_json_object);

?>