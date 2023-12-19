#!/bin/bash

# Check if a filename is provided as a command-line argument
if [[ $# -eq 0 ]]; then
  echo "Usage: $0 <filename>"
  exit 1
fi
#Name the file good_practice.sh
#Run the file like this: "sh good_practice.sh filename.c"
#filename.c is the file you want to fix indentations and whitespace errors
# Assign the filename to a variable
filename=$1

# Remove trailing whitespaces using Vim and save changes automatically
vim -E -s "$filename" <<-EOF
  %s/\s\+$//g
  x
EOF

# Adjust indentation using Vim and save changes automatically
vim -E -s "$filename" <<-EOF
  execute 'normal! gg=G'
  x
EOF

echo "Indentation successfull"
echo "Trailing whitespaces removed successfully"

