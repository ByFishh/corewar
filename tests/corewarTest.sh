#!/bin/bash

echo -e "
\e[34mAuto-Test Corewar:\e[39m
"

exit_status=0
returnCall=$(../corewar/corewar champions/42.cor champions/42.cor 2>&1)
if ([[ $? != 0 ]])
then
        echo -e "\e[31mInvalide return output/code for 2 42 : \"$?\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for 2 42 \e[39m"
fi

returnCall=$(../corewar/corewar champions/42.cor champions/abel.cor champions/bill.cor 2>&1)
if ([[ $? != 0 ]])
then
        echo -e "\e[31mInvalide return output/code for 3 file : \"$?\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for 3 file  \e[39m"
fi

returnCall=$(../corewar/corewar champions/42.cor champions/abel.cor champions/bill.cor champions/pdd.cor 2>&1)
if ([[ $? != 0 ]])
then
        echo -e "\e[31mInvalide return output/code for 4 file : \"$?\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for 4 file  \e[39m"
fi
exit $exit_status