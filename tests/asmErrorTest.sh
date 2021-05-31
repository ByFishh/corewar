#!/bin/bash

echo -e "
\e[34mAuto-Test Asm Error:\e[39m
"

exit_status=0
output=$(cat error_case/.test)
returnCall=$(../asm/asm 2>&1)
if ([[ $? != 84 ]])
then
        echo -e "\e[31mInvalide return output/code for no file : \"$?\" : \"$returnCall\"\e[39m"
        exit_status=1
else
        echo -e "\e[32mValide return output/code for no file \e[39m"
fi
for nb in $(ls error_case/ | grep .test)
do
    tmp=$nb
    tmp=$(echo $tmp | cut -f1 -d".")
    tmp+=".s"
    link="error_case/"$tmp
    output=$(cat error_case/$nb)
    returnCall=$(../asm/asm $link 2>&1)
    if ([[ $? != 84 ]])
    then
        echo -e "\e[31mInvalide return output/code for $link : \"$output\" : \"$?\" : \"$returnCall\"\e[39m"
        exit_status=1
    else
        echo -e "\e[32mValide return output/code for $link \e[39m"
    fi
done
exit $exit_status
