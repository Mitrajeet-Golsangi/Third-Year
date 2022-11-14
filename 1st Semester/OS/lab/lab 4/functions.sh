write_file () {
    touch $1;
    echo -n "Creating file $1 in "
    pwd
    
    $2 > $1;
    echo "Written to the file succesfully !";

}

read -p "enter command to write in file : " cmd;

write_file $1 "$cmd";
