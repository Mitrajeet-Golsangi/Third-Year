<?php
$FILENAME = 'webtech.txt'
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
        echo fread($file, filesize($FILENAME));
        fclose($file);
        ?>
    </main>
</body>

</html>