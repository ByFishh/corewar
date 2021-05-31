#!/bin/bash

exit_status=0

returncmd=$(valgrind --log-file=valg.log  asm/asm tests/champions_src/42.s)
valgrinfRes=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
if ([[ $valgrinfRes == "" ]])
then
    echo -e "\e[31mError dectected in Valgrind for Asm !!!!!!!! Warning Blisteur is watching you\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for Asm\e[39m"
fi
rm valg.log
returncmd=$(valgrind --log-file=valg.log  corewar/corewar tests/champions/42.cor tests/champions/42.cor)
valgrinfRes=$(cat valg.log | grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)")
if ([[ $valgrinfRes == "" ]])
then
    echo -e "\e[31mError dectected in Valgrind for Corewar !!!!!!!! Blisteur is watching you\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid Valgrind for Corewar\e[39m"
fi
rm valg.log

returncmd=$(valgrind --log-file=valg.log  asm/asm tests/champions_src/42.s)
valgrinfRes=$(cat valg.log | grep "All heap blocks were freed -- no leaks are possible")
if ([[ $valgrinfRes == "" ]])
then
    echo -e "\e[31mLeak dectected in Valgrind for Asm !!!!!!!! Warning Blisteur is watching you\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid free Valgrind for Asm\e[39m"
fi
rm valg.log
returncmd=$(valgrind --log-file=valg.log  corewar/corewar tests/champions/42.cor tests/champions/42.cor)
valgrinfRes=$(cat valg.log | grep "All heap blocks were freed -- no leaks are possible")
if ([[ $valgrinfRes == "" ]])
then
    echo -e "\e[31mLeak dectected in Valgrind for Corewar !!!!!!!! Blisteur is watching you\e[39m"
    exit_status=1
else
    echo -e "\e[32mValid free Valgrind for Corewar\e[39m"
fi
rm valg.log
exit $exit_status