#!/bin/bash

cd .. && git clone https://github.com/Gegel85/norminette.git && cd norminette && ./install.sh && cd .. && rm -rf norminette
norminette -i 4 -A --major 3