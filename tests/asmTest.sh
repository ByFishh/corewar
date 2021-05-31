#!/bin/bash

echo -e "
\e[34mAuto-Test Asm:\e[39m
"

exit_status=0
if ([[ $# -eq 2 ]] && [[ $1 = "-d" ]])
then
    if ([[ -d $2 ]])
    then
        path=$2
    else
        echo "unknow directory \"$2\""
        exit 1
    fi
else
    path='champions'
fi
nb_test=$(ls $path | grep .cor | wc -l)
if ([[ $nb_test == 0 ]])
then
    echo "No \".core\" here \"$2\""
    exit 1
fi
for nb in $(ls $path | grep .cor)
do
    tmp=$nb
    tmp=$(echo $tmp | cut -f1 -d".")
    tmp+=".s"
    link="champions_src/"$tmp
    returnCall=$(../asm/asm $link 2>&1)
    if ([[ $? != 0 ]])
    then
        if ([[ $returnCall == "" ]])
        then
            echo -e "$nb : \e[31msegfault\e[39m"
            exit_status=1
        else
            echo -e "$nb : \e[31m$returnCall\e[39m"
            exit_status=1
        fi
    else
        echo -e "$nb : \e[32mCOMPILE OK\e[39m"
        diff_cor=$(diff ./$nb champions/$nb 2>&1)
        if ([[ $? != 0 ]])
        then
            echo -e "$nb : \e[31mDIFF KO\e[39m"
            exit_status=1
        else
            echo -e "$nb : \e[32mDIFF OK\e[39m"
        fi
        rm ./$nb
    fi
done
exit $exit_status
