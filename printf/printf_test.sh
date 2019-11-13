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
		gcc -Wall -Werror -Wextra "$var" -D BONUS ft_test_printf.c libftprintf.a -o ft_test_printf.out  2> /dev/null
	else
		gcc -Wall -Werror -Wextra "$var" ft_test_printf.c libftprintf.a -o ft_test_printf.out 2> /dev/null
	fi
	if [ "$1" = "char" ] || [ "$2" = "char" ] || [ "$3" = "char" ] || [ "$4" = "char" ] || [ "$5" = "char" ]
	then
		./ft_test_printf.out 1 1 > result_ori.txt 2> /dev/null
		./ft_test_printf.out 2 1 > result_copy.txt 2> /dev/null
	else
		./ft_test_printf.out 1 0 > result_ori.txt 2> /dev/null
		./ft_test_printf.out 2 0 > result_copy.txt 2> /dev/null
	fi
	ORI=$(cat result_ori.txt)
	COPY=$(cat result_copy.txt)
	if [ "$ORI" = "" ] || [ "$COPY" = "" ]
	then
		printf "\n             /|_
            /  ,\     
         .-'   _,'  < \033[0;31mdoes NOT compile! o_O \t\t Shame!\033[0m
        / _   |
       /   )_ |
   ,=='\`.____)_)\n"
	else
		diff result_ori.txt result_copy.txt > results.log
		DIFF=$(diff result_ori.txt result_copy.txt)
		NUM=$(cat results.log | grep \> | wc -l | tr -d ' ')
		if [ "$NUM" = "1" ]
		then
		RES="$NUM error, almost!"
		else
		RES="$NUM errors!"
		fi
		if [ "$DIFF" = "" ]
		then
			printf "\n\t              /|_
		     /  ,\     
		  .-'   _,'  < \033[0;32mALL TESTS OK\033[0m\t\t\t\t\tQUACK!
		 / _   |
		/   )_ |
	    ,=='\`.____)_)\n"
		else
			printf "\n\t              /|_
		     /  ,\     
		  .-'   _,'  < \033[0;31mHaha! KO. $RES\tCheck results.log for details\033[0m
		 / _   |
		/   )_ |
	    ,=='\`.____)_)\n"
			if [ "$1" = "log" ] || [ "$2" = "log" ] || [ "$3" = "log" ] || [ "$4" = "log" ] || [ "$5" = "log" ]
			then
				cat results.log
			fi
		fi
			printf "\t\t\t\t\t\t\t\t\tgithub/hbaudet\n"
	fi
fi
