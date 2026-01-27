<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

/*
 INTENTIONALLY VULNERABLE LOGIN
 CTF PURPOSES ONLY
*/

$conn = new mysqli("localhost", "ctfuser", "ctfpass", "Summit");

if ($conn->connect_error) {
    die("Database connection failed");
}

$username = $_POST['username'] ?? '';
$password = $_POST['password'] ?? '';

// ❌ NO sanitization — intentional SQLi
$sql = "SELECT * FROM users WHERE username='$username' AND password='$password'";

// Uncomment this line temporarily if you want to SEE the query
// echo "<pre>$sql</pre>";

$result = $conn->query($sql);

if ($result && $result->num_rows > 0) {
    echo "<h2>Login Successful</h2>";
    echo "<p>Welcome, authorized user.</p>";
    echo "<p><strong>Summit{ThisWasEasy}</strong></p>";
} else {
    echo "<h2>Login Failed</h2>";
    echo "<p>Invalid employee credentials.</p>";
}
?>
