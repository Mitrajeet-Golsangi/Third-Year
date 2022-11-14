<?php
$FILENAME = '../webtech.txt';

function append_file()
{
    $file = fopen($GLOBALS['FILENAME'], "a") or die("Cannot Open File : {$GLOBALS['FILENAME']}");
    fwrite($file, $_GET['append-text']);
    fclose($file);
}
function clear_file()
{
    $file = fopen($GLOBALS['FILENAME'], "w") or die("Cannot Open File : {$GLOBALS['FILENAME']}");
    fwrite($file, "");
    fclose($file);
}

if ($_SERVER['REQUEST_METHOD'] == "GET" and isset($_GET['append'])) append_file();
else if ($_SERVER['REQUEST_METHOD'] == "GET" and isset($_GET['clear'])) clear_file();

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Handling</title>
    <!---------------------------- Bootstrap CDN ---------------------------->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous" defer></script>
    <!---------------------------- End Bootstrap CDN ---------------------------->
</head>

<body class="container-fluid p-4">

    <div class="display-3">File Contents Are : </div>
    <hr />
    <main>
        <?php
        $file = fopen($FILENAME, "r") or die("Cannot Open File : $FILENAME");
        if (filesize($FILENAME) > 0)
            echo fread($file, filesize($FILENAME));
        else echo "File is Empty !";
        fclose($file);
        ?>
        <hr />
        <div class="display-6">Append To File :</div>
        <form method="get" action="index.php">
            <div class="form-group">
                <label class="form-label">Enter Text to append</label>
                <input class="form-control" name="append-text" />
            </div>
            <button class="btn btn-outline-primary mt-2" name="append">Submit</button>
            <button class="btn btn-outline-danger mt-2" name="clear">Clear File</button>
        </form>
    </main>
</body>

</html>