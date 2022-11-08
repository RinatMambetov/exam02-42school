gcc -Wall -Werror -Wextra orig/get_next_line_orig.c orig/main_orig.c -o orig/get_next_line_orig
./orig/get_next_line_orig < subject.en.txt > orig/original_.res
cat -e orig/original_.res > orig/original.res

gcc -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line
./get_next_line < subject.en.txt > yours_.res
cat -e yours_.res > yours.res

diff -y --suppress-common-line orig/original.res yours.res

rm -rf orig/original.res orig/original_.res yours_.res yours.res
rm -f orig/get_next_line_orig get_next_line
