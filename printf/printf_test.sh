FLAGS='-Wall -Wextra -Werror'
CLEAN=0
CHAR=0
LOG=0
for FL in ${@}; do
  if [[ $FL == "clean" ]]; then CLEAN=1; make fclean > /dev/null; fi
  if [[ $FL == "fsan" ]]; then FLAGS="$FLAGS -fsanitize=address"; fi
  if [[ $FL == "bonus" ]]; then FLAGS="$FLAGS -D BONUS"; fi
  if [[ $FL == "leaks" ]]; then FLAGS="$FLAGS -D LEAKS" && clear && printf "To test leaks run in another terminal :\n\nleaks ft_test_printf.out"; fi
  if [[ $FL == "char" ]]; then CHAR=1; fi
  if [[ $FL == "log" ]]; then LOG=1; fi
done
if [[ $CLEAN == 1 ]]; then make fclean > /dev/null && exit; fi
make > /dev/null
gcc $FLAGS Tests/printf/ft_test_printf.c -L./ -lftprintf -o ft_test_printf.out 2> /dev/null
if [[ $CHAR == 1 ]]; then ./ft_test_printf.out 1 1 > result_ori.txt 2> /dev/null && ./ft_test_printf.out 2 1 > result_copy.txt 2> /dev/null
else
./ft_test_printf.out 1 0 > result_ori.txt 2> /dev/null; ./ft_test_printf.out 2 0 > result_copy.txt 2> /dev/null; fi
ORI=$(cat result_ori.txt)
COPY=$(cat result_copy.txt)
if [ "$ORI" = "" ] || [ "$COPY" = "" ]
then
	printf "\n             /|_
           /  ,\\
        .-'   _,'  < \033[0;31mdoes NOT compile! o_O \t\t Shame!\033[0m
       / _   |
      /   )_ |
 ,=='\`.____)_)\n"
else
	diff result_ori.txt result_copy.txt > results.log
	DIFF=$(diff result_ori.txt result_copy.txt)
	NUM=$(cat results.log | grep \> | wc -l | tr -d ' ')
	if [ "$NUM" = "1" ]; then RES="$NUM error, almost!"
	elif [ "$NUM" = "0" ]; then RES=""
	else RES="$NUM errors!"
	fi
	if [ "$DIFF" = "" ]
	then
		printf "\n\t      /|_
	     /  ,\\
	  .-'   _,'  < \033[0;32mALL TESTS OK\033[0m\t\t\t\t\tQUACK!
	 / _   |
	/   )_ |
 ,=='\`.____)_)\n"
	else
		printf "\n\t      /|_
	     /  ,\\
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
	if [ "$LOG" == "1" ]; then cat results.log; fi
fi
