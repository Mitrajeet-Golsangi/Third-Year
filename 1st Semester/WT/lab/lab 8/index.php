<!-- Create  MySQL database table and write php scripts to read, insert & delete data 
through web interface. -->
<?php require __DIR__ . '/db_config.php' ?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Database Connection</title>

    <!---------------------------- Bootstrap CDN ---------------------------->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous" defer></script>
    <!---------------------------- End Bootstrap CDN ---------------------------->

</head>

<body class="p-5">
    <div class="display-3">MySQL Database With PHP</div>
    <hr />

    <!-- Creation of a Database -->
    <div class="display-5 my-4">Creation of a database</div>
    <form class="gap-4" action="index.php" method="post">
        <input type="text" name="values" id="values" placeholder="Enter Table name" class="form-control mb-2 w-1/2" required />
        <button class="btn btn-outline-primary col">Create Database</button>
    </form>
    <!-- Output -->
    <div id="create_output" onclick="resetVal()" class="my-2 text-info">
        <?php
        try {
            $stat = create_table($_POST['values']);
        } catch (\Throwable $th) {
            $stat = "Error ! Could not create Database ! Check console for info";
            debug_to_console($th->getMessage());
            // $stat = $th->getMessage();
        }
        echo $stat;
        ?>
        <span class="text-secondary cursor-pointer">Click to close</span>
    </div>
    <!-- Creation of a Database -->
    <table class="table">
        <thead>
            <?php

            ?>
        </thead>
        <tbody>
            <tr>
                <th scope="row">1</th>
                <td>Mark</td>
                <td>Otto</td>
                <td>@mdo</td>
            </tr>
            <tr>
                <th scope="row">2</th>
                <td>Jacob</td>
                <td>Thornton</td>
                <td>@fat</td>
            </tr>
            <tr>
                <th scope="row">3</th>
                <td colspan="2">Larry the Bird</td>
                <td>@twitter</td>
            </tr>
        </tbody>
    </table>

    <script>
        const resetVal = () => document.getElementById('create_output').innerHTML = "";
    </script>
</body>

</html>