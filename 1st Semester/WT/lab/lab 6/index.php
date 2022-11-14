<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conditional Billing</title>
    <!---------------------------- Bootstrap CDN ---------------------------->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-u1OknCvxWvY5kfmNBILK2hRnQC3Pr17a+RTT6rIHI7NnikvbZlHgTPOOmMi466C8" crossorigin="anonymous" defer></script>
    <!---------------------------- End Bootstrap CDN ---------------------------->
</head>

<body class="container-fluid p-4">
    <div class="display-3 row justify-content-center mb-5">Electricity Bill Calculation</div>
    <div class="row justify-content-center align-items-center">
        <div class="card" style="width:50%">
            <div class="card-body">
                <h5 class="card-title">Enter the Units to calculate price</h5>
                <p class="card-text">
                <div class="h5">Electricity Rates</div>
                <table class="table table-responsive table-striped">
                    <thead class="table-primary">
                        <tr>
                            <th>Units (kWHr)</th>
                            <th>Charge (Rs./unit)</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                            <td>0 - 50</td>
                            <td>3.50</td>
                        </tr>
                        <tr>
                            <td>50 - 150</td>
                            <td>4.00</td>
                        </tr>
                        <tr>
                            <td>150 - 250</td>
                            <td>5.20</td>
                        </tr>
                        <tr>
                            <td>250 and above</td>
                            <td>6.50</td>
                        </tr>
                    </tbody>
                </table>

                <form id="electricity-form" method="get" action="index.php">
                    <label class="from-label row justify-contents-between align-items-center mb-2">
                        <span class="col">Units of Electricity</span>
                        <span class="col text-end">kWHr</span>
                    </label>
                    <input name="units" id="units" class="form-control" placeholder="Units of Energy eg: 150" type="number" required />
                </form>

                <!-- Output -->
                <div class="my-4 row text-start align-items-center">
                    <span class="text-success col">Bill (Rs.) : </span>
                    <span>
                        <?php
                        if ($_GET['units'] <= 50) {
                            echo $_GET['units'] * 3.50;
                        } else if ($_GET['units'] > 50 && $_GET['units'] <= 150) {
                            echo $_GET['units'] * 4;
                        } else if ($_GET['units'] > 150 && $_GET['units'] <= 250) {
                            echo $_GET['units'] * 4;
                        } else {
                            echo $_GET['units'] * 6.50;
                        }
                        ?>
                    </span>
                </div>

                </p>
                <button class="btn btn-block btn-primary card-link" formaction="submit" form="electricity-form">Calculate</a>
            </div>
        </div>
    </div>
</body>

</html>