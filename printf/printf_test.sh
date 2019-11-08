rm results.log result_ori.txt result_copy.txt ft_test_printf.out 2> /dev/null
if [ "$1" = "clean" ] || [ "$2" = "clean" ] || [ "$3" = "clean" ] || [ "$4" = "clean" ] || [ "$5" = "clean" ] || [ "$6" = "clean" ]

then
	make fclean > /dev/null
else
	make > /dev/null
	if [ "$1" = "fsan" ] || [ "$2" = "fsan" ] || [ "$3" = "fsan" ] || [ "$4" = "fsan" ] || [ "$5" = "fsan" ]
	then
		var="-fsanitize=address"
	fi
	if [ "$1" = "bonus" ] || [ "$2" = "bonus" ] || [ "$3" = "bonus" ] || [ "$4" = "bonus" ] || [ "$5" = "bonus" ]
	then
		gcc -Wall -Werror -Wextra "$var" -D BONUS ft_test_printf.c libftprintf.a -o ft_test_printf.out
	else
		gcc -Wall -Werror -Wextra "$var" ft_test_printf.c libftprintf.a -o ft_test_printf.out
	fi
	if [ "$1" = "char" ] || [ "$2" = "char" ] || [ "$3" = "char" ] || [ "$4" = "char" ] || [ "$5" = "char" ]
	then
		./ft_test_printf.out 1 1 > result_ori.txt
		./ft_test_printf.out 2 1 > result_copy.txt
	else
		./ft_test_printf.out 1 0 > result_ori.txt
		./ft_test_printf.out 2 0 > result_copy.txt
	fi
	diff result_ori.txt result_copy.txt > results.log
	DIFF=$(diff result_ori.txt result_copy.txt)
	if [ "$DIFF" = "" ]
	then
		echo -e "\033[0;32mALL TESTS OK\033[0m"
	else
		echo -e "\033[0;31m\t\t\tGRADE : KO.\n\nCheck results.log for details :\033[0m"
		cat results.log
	fi
	printf "             /|_
            /  ,\     
         .-'   _,'  < QUACK!
        / _   |
       /   )_ |
   ,=='\`.____)_)"
		printf "\t\t\t\t\t\t\t\t\tgithub/hbaudet\n"
fi
