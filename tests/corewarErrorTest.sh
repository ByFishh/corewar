#!/bin/bash

echo -e "
\e[34mAuto-Test Corewar Error:\e[39m
"

exit_status=0
output="Usage: ./corewar [-g] [-dump cycle_nb] [[-a load_addr] [-n prog_nb] prog.cor] ..."
returnCall=$(../corewar/corewar 2>&1)
if ([[ $? != 84 ]])
then
        echo -e "\e[31mInvalide return output/code for no file : \"$?\" : \"$returnCall\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for no file \e[39m"
fi

output="Usage: ./corewar [-g] [-dump cycle_nb] [[-a load_addr] [-n prog_nb] prog.cor] ..."
returnCall=$(../corewar/corewar "champions/42.cor" 2>&1)
if ([[ $? != 84 ]])
then
        echo -e "\e[31mInvalide return output/code for 1 file : \"$?\" : \"$returnCall\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for 1 file  \e[39m"
fi

output="Error in function open: No such file or directory."
returnCall=$(../corewar/corewar "eaezaeazaze" 2>&1)
if ([[ $? != 84 ]] || [[ $returnCall != $output ]])
then
        echo -e "\e[31mInvalide return output/code for invalide file : \"$?\" : \"$returnCall\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for invalide file  \e[39m"
fi

output="The number of champion load is above the limit."
returnCall=$(../corewar/corewar champions/42.cor champions/42.cor champions/42.cor champions/42.cor champions/42.cor 2>&1)
if ([[ $? != 84 ]] || [[ $returnCall != $output ]])
then
        echo -e "\e[31mInvalide return output/code for too much file : \"$?\" : \"$returnCall\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for too much file \e[39m"
fi
exit $exit_status