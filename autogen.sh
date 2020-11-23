#!/bin/bash

LOG=.autogen.log

function error_and_exit {
    printf "error\n"
    cat $LOG
    exit -1;
}

printf "Running libtoolize..."
libtoolize -f > $LOG >& $LOG || error_and_exit
printf "done\n"

printf "Running aclocal..."
aclocal > $LOG >& $LOG || error_and_exit
printf "done\n"

printf "Running autoconf..."
autoconf > $LOG >& $LOG || error_and_exit
printf "done\n"

printf "Running autoheader..."
autoheader > $LOG >& $LOG || error_and_exit
printf "done\n"

printf "Running automake..."
automake -a > $LOG >& $LOG || error_and_exit
printf "done\n"

printf "Autotools setup complete!\n"
