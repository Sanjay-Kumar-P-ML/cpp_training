#!/bin/bash
echo "Hello, welcome to the basic shell script!"
username="Alice"
echo "Hello, $username!"
echo "Enter a directory name:"
read dir_name
if [ -d "$dir_name" ]; then
    echo "Directory '$dir_name' exists."
    file_count=$(ls -1 "$dir_name" | wc -l)
    echo "The directory '$dir_name' contains $file_count files."
else
    echo "Directory '$dir_name' does not exist. Creating it now..."
    mkdir "$dir_name"
    echo "Directory '$dir_name' created successfully."
fi
echo "Printing numbers from 1 to 5:"
for i in {1..5}
do
    echo "Number: $i"
done
echo "Goodbye!"s
screen
