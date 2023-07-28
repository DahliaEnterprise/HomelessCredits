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


$stmt = $pdo->query('SELECT result_hash, timestamp FROM parcela ORDER BY timestamp DESC LIMIT 0,1;');
while ($row = $stmt->fetch())
{
    //Sanatized output TODO

    //Return sanatized output
    echo json_encode($row);
}
?>
