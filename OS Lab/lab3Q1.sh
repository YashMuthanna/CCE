echo "Enter file path to check"
read a
if [ -d $a ] ; then
	echo "$a is a directory"
else
	echo "$a is a file"
fi
