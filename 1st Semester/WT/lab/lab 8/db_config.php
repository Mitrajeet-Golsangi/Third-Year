<?php

use function PHPSTORM_META\type;

$host = "localhost";
$user = "root";
$password = "";

/**
 * Connect to the MySQL database
 * * Note : The caller function will have to close the SQL connection
 * 
 * @return mysqli connection object for the MySQL database
 */
function db_connect()
{
    $connection = new mysqli($GLOBALS['host'], $GLOBALS['user'], $GLOBALS['password']);

    if ($connection->connect_error) {
        die("Connection Failed !" . $connection->connect_error);
    }

    return $connection;
}

/**
 * Create a database with the given name
 * 
 * @param db_name : string => Name of the database that needs to be created
 */
function create_database($db_name)
{
    $conn = db_connect();

    if ($conn->query("CREATE OR REPLACE DATABASE $db_name;")) {
        return "Created database '$db_name' successfully !\n";
    } else {
        throw "Error Creating database '$db_name'" . $conn->error;
    }

    $conn->close();
}

/**
 * Create a database table with the given name
 * 
 * @param values  : string => A comma delimited string containing table name as first word and column names as rest
 */
function create_table($values)
{
    // convert delimited string to array and extract table name from it
    $arr = explode(',', $values);
    $tbl_name = array_shift($arr);

    // Create a database that is requested by the user
    create_database($tbl_name);

    // Create a SQL query from the given parameters for creation of table
    $query = "USE $tbl_name;\n CREATE OR REPLACE TABLE $tbl_name(\nid INT NOT NULL AUTO_INCREMENT PRIMARY KEY\n)";
    // foreach ($arr as $i) {
    //     $query = $query . "$i VARCHAR(100) NULL,\n";
    // }
    // $query = $query . "PRIMARY KEY id \n);";
    debug_to_console($query);

    // Connect to the database
    $conn = db_connect();

    // Try to create or replace a table
    if ($conn->query((string)$query)) {
        return "Created table '$tbl_name' successfully !\n";
    } else {
        throw "Error Creating table '$tbl_name'" . $conn->error;
    }

    $conn->close();
}

/**
 * A function to write log messages to the javascript console instead of the actual DOM
 * 
 * @param data  : any   => Data that needs to be printed to the JavaScript console
 */
function debug_to_console($data)
{
    $output = $data;
    if (is_array($output))
        $output = implode(',', $output);

    echo "<script>console.log(`Debug Objects: " . $output . "` );</script>";
}
