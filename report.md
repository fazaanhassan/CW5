## COMP0019 CW5 Grade Report
Report for commit SHA: 3d20e3c7a78f7acee44970c814c2a6f56047343d

### Output


    
      CLEAN 
      COMPILE sh0019.c
    sh0019.c: In function start_command:
    sh0019.c:100:9: warning: unused variable status [-Wunused-variable]
         int status;
             ^
    sh0019.c: In function run_list:
    sh0019.c:156:29: warning: passing argument 2 of waitpid makes pointer from integer without a cast [-Wint-conversion]
                 waitpid(c->pid, status, 0);
                                 ^
    In file included from sh0019.c:5:0:
    /usr/include/x86_64-linux-gnu/sys/wait.h:125:16: note: expected int * but argument is of type int
     extern __pid_t waitpid (__pid_t __pid, int *__stat_loc, int __options);
                    ^
    sh0019.c:140:9: warning: unused variable childFork [-Wunused-variable]
         int childFork;
             ^
    sh0019.c: In function eval_line:
    sh0019.c:185:9: warning: unused variable flag [-Wunused-variable]
         int flag = 0;
             ^
    sh0019.c: In function run_list:
    sh0019.c:156:13: warning: status may be used uninitialized in this function [-Wmaybe-uninitialized]
                 waitpid(c->pid, status, 0);
                 ^
      COMPILE helpers.c
      LINK sh0019 
    
    Test SIMPLE1: passed
    Test SIMPLE2: passed
    Test SIMPLE3: passed
    Test SIMPLE4: passed
    Test BG1: passed
    Test BG2: passed
    Test BG3: passed
    Test LIST1: passed
    Test LIST2: passed
    Test LIST3: passed
    Test LIST4: passed
    Test LIST5: passed
    Test LIST6: passed
    Test LIST7: FAILED in 0.011 sec
        command  `../sh0019 -q cmdLIST7.sh`
        expected `Hello Bye 1`
        got      `sleep: invalid time interval echo sleep: invalid time interval Bye...`
    Test LIST8: FAILED in 0.001 sec
        command  `sh -c "sleep 0.2; echo Second" & sh -c "sleep 0.15; echo First" & sleep 0.3`
        expected `First Second`
        got      ``
    Test COND1: passed
    Test COND2: FAILED in 0.002 sec
        command  `echo True || echo False`
        expected `True`
        got      `True False`
    Test COND3: passed
    Test COND4: FAILED in 0.002 sec
        command  `grep -c NotThere ../sh0019.c && echo Unwanted`
        expected `0`
        got      `0 Unwanted`
    Test COND5: passed
    Test COND6: passed
    Test COND7: FAILED in 0.005 sec
        command  `echo Start && false || false && echo Bad`
        expected `Start`
        got      `Start Bad`
    Test COND8: FAILED in 0.002 sec
        command  `sleep 0.2 && echo Second & sleep 0.1 && echo First`
        expected `First Second`
        got      `First Second sleep 0.1`
    Test COND9: passed
    Test COND10: FAILED in 0.007 sec
        command  `false && echo no && echo no && echo no && echo no || echo yes`
        expected `yes`
        got      `no no no no yes`
    Test COND11: FAILED in 0.007 sec
        command  `true || echo no || echo no || echo no || echo no && echo yes`
        expected `yes`
        got      `no no no no yes`
    Test PIPE1: FAILED in 0.003 sec
        command  `echo Pipe | wc -c`
        expected `5`
        got      `Pipe | wc -c`
    Test PIPE2: FAILED in 0.003 sec
        command  `echo Good | grep -n G`
        expected `1:Good`
        got      `Good | grep -n G`
    Test PIPE3: FAILED in 0.003 sec
        command  `echo Bad | grep -c G`
        expected `0`
        got      `Bad | grep -c G`
    Test PIPE4: FAILED in 0.003 sec
        command  `echo Line | cat | wc -l`
        expected `1`
        got      `Line | cat | wc -l`
    Test PIPE5: FAILED in 0.007 sec
        command  `../sh0019 -q cmdPIPE5.sh; ps | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `Hello Bye 1`
        got      `sleep: invalid time interval echo sleep: invalid time interval Bye...`
    Test PIPE6: FAILED in 0.003 sec
        command  `echo GoHangASalamiImALasagnaHog | rev | rev | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      `GoHangASalamiImALasagnaHog | rev | rev | rev`
    Test PIPE7: FAILED in 0.014 sec
        command  `rev fPIPE7.txt | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      `rev: cannot open |: No such file or directory rev: cannot open rev: No such ...`
    Test PIPE8: FAILED in 0.003 sec
        command  `cat fPIPE8.txt | tr [A-Z] [a-z] | /usr/bin/md5sum | tr -d -`
        expected `8e21d03f7955611616bcd2337fe9eac1`
        got      `cat: invalid option -- 'd' Try 'cat --help' for more information.`
    Test PIPE9: FAILED in 0.003 sec
        command  `rev fPIPE9.txt | /usr/bin/md5sum | tr [a-z] [A-Z] | tr -d -`
        expected `502B109B37EC769342948826736FA063`
        got      `rev: invalid option -- 'd' Usage: rev [options] [file ...] Reverse lines cha...`
    Test PIPE10: FAILED in 0.004 sec
        command  `sleep 2 & sleep 0.2; ps T | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `1`
        got      `sleep: invalid time interval sleep Try 'sleep --help' for more informa...`
    Test PIPE11: FAILED in 0.004 sec
        command  `echo Sedi | tr d m ; echo Calan | tr a o`
        expected `Semi Colon`
        got      `Sedi | tr d m Calan | tr a o`
    Test PIPE12: FAILED in 0.003 sec
        command  `echo Ignored | echo Desired`
        expected `Desired`
        got      `Ignored | echo Desired`
    Test PIPE13: FAILED in 0.002 sec
        command  `../sh0019 -q cmdPIPE13.sh &`
        expected `Hello 1`
        got      `Hello error: garbage option Usage: ps [options] Try 'ps --help <simple|list|...`
    Test PIPE14: passed
    Test PIPE15: FAILED in 0.004 sec
        command  `true | echo True || echo False`
        expected `True`
        got      `False`
    Test PIPE16: FAILED in 0.003 sec
        command  `false | echo True || echo False`
        expected `True`
        got      `False`
    Test PIPE17: FAILED in 0.004 sec
        command  `echo Hello | grep -q X || echo NoXs`
        expected `NoXs`
        got      `Hello | grep -q X NoXs`
    Test PIPE18: FAILED in 0.003 sec
        command  `echo Yes | grep -q Y && echo Ys`
        expected `Ys`
        got      `Yes | grep -q Y Ys`
    Test PIPE19: FAILED in 0.004 sec
        command  `echo Hello | grep -q X || echo poqs | tr pq NX`
        expected `NoXs`
        got      `Hello | grep -q X poqs | tr pq NX`
    Test PIPE20: FAILED in 0.004 sec
        command  `echo Yes | grep -q Y && echo fs | tr f Y`
        expected `Ys`
        got      `Yes | grep -q Y fs | tr f Y`
    Test PIPE21: FAILED in 0.004 sec
        command  `false && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      `vnexpected | tr v u expected`
    Test PIPE22: FAILED in 0.005 sec
        command  `false && echo unexpected && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      `unexpected vnexpected | tr v u expected`
    Test PIPE23: FAILED in 0.002 sec
        command  `sleep 0.2 | wc -c | sed s/0/Second/ & sleep 0.1 | wc -c | sed s/0/First/`
        expected `First Second`
        got      `sleep: invalid option -- 'c' Try 'sleep --help' for more information.`
    Test ZOMBIE1: passed
    Test ZOMBIE2: passed
    Test REDIR1: FAILED in 0.004 sec
        command  `echo Start ; echo File > fREDIR1.txt`
        expected `Start File`
        got      `Start File > fREDIR1.txt cat: fREDIR1.txt: No such file or directory`
    Test REDIR2: FAILED in 0.004 sec
        command  `tr pq Fi < fREDIR2.txt ; echo Done`
        expected `File Done`
        got      `tr: extra operand < Try 'tr --help' for more information. Done`
    Test REDIR3: FAILED in 0.007 sec
        command  `perl -e 'print STDERR 1868' 2> fREDIR3.txt ; grep '^[1-9]' fREDIR3.txt | wc -l ; rm -f fREDIR3.txt`
        expected `1`
        got      `1868grep: |: No such file or directory grep: wc: No such file or directory`
    Test REDIR4: FAILED in 0.009 sec
        command  `perl -e 'print STDERR 1868; print STDOUT "X"' > fREDIR4a.txt 2> fREDIR4b.txt ; grep '^[1-9]' fREDIR4a.txt | wc -l ; grep '^[1-9]' fREDIR4b.txt | wc -l ; cmp -s fREDIR4a.txt fREDIR4b.txt || echo Different`
        expected `0 1 Different`
        got      `1868Xgrep: fREDIR4a.txt: No such file or directory grep: |: No such file or ...`
    Test REDIR5: FAILED in 0.003 sec
        command  `tr hb HB < fREDIR5.txt | sort | ../sh0019 -q cmdREDIR5.sh`
        expected `Bye Hello First Good`
        got      `tr: extra operand < Try 'tr --help' for more information.`
    Test REDIR6: FAILED in 0.022 sec
        command  `sort < fREDIR6a.txt > fREDIR6b.txt ; tail -n 2 fREDIR6b.txt ; rm -f fREDIR6a.txt fREDIR6b.txt`
        expected `Bye Hello`
        got      `sort: cannot read: '<': No such file or directory tail: cannot open 'fREDIR6...`
    Test REDIR7: FAILED in 0.003 sec
        command  `echo > /tmp/directorydoesnotexist/foo`
        expected `No such file or directory`
        got      `> /tmp/directorydoesnotexist/foo`
    Test REDIR8: FAILED in 0.004 sec
        command  `echo > /tmp/directorydoesnotexist/foo && echo Unwanted`
        expected `No such file or directory`
        got      `> /tmp/directorydoesnotexist/foo Unwanted`
    Test REDIR9: FAILED in 0.003 sec
        command  `echo > /tmp/directorydoesnotexist/foo || echo Wanted`
        expected `No such file or directory Wanted`
        got      `> /tmp/directorydoesnotexist/foo Wanted`
    Test REDIR10: FAILED in 0.003 sec
        command  `echo Hello < nonexistentREDIR10.txt`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR10.txt`
    Test REDIR11: FAILED in 0.004 sec
        command  `echo Hello < nonexistentREDIR11.txt && echo Unwanted`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR11.txt Unwanted`
    Test REDIR12: FAILED in 0.004 sec
        command  `echo Hello < nonexistentREDIR12.txt || echo Wanted`
        expected `No such file or directory Wanted`
        got      `Hello < nonexistentREDIR12.txt Wanted`
    Test REDIR13: FAILED in 0.003 sec
        command  `cat unwanted.txt | cat < wanted.txt`
        expected `Wanted`
        got      `Unwanted cat: '|': No such file or directory cat: cat: No such file or direc...`
    Test REDIR14: FAILED in 0.003 sec
        command  `cat < wanted.txt | cat > output.txt`
        expected `output.txt is Wanted`
        got      `cat: '<': No such file or directory Wanted cat: '|': No such file or directo...`
    Test REDIR15: FAILED in 0.003 sec
        command  `cat < xoqted.txt | tr xoq Wan | cat > output.txt`
        expected `output.txt is Wanted`
        got      `cat: '<': No such file or directory xoqted cat: '|': No such file or directo...`
    Test REDIR16: FAILED in 0.003 sec
        command  `echo Ignored | cat < lower.txt | tr A-Z a-z`
        expected `lower`
        got      `Ignored | cat < lower.txt | tr A-Z a-z`
    Test INTR1: FAILED in 0.206 sec
        command  `echo a && sleep 0.2 && echo b`
        expected `a`
        got      `a b`
    Test INTR2: FAILED in 0.206 sec
        command  `echo start && sleep 0.2 && echo undesired  \n  echo end`
        expected `start end`
        got      `start undesired end`
    Test INTR3: FAILED in 0.003 sec
        command  `sleep 0.3 && echo yes & sleep 0.2 && echo no`
        expected `yes`
        got      `no yes sleep 0.2`
    Test INTR4: FAILED in 1.004 sec
        command  `sleep 1`
        should have completed in 0.150 sec
    Test INTR5: FAILED in 1.006 sec
        command  `../sh0019 -q cmdINTR5.sh`
        expected ``
        got      `undesired`
        should have completed in 0.150 sec
    Test CD1: FAILED in 0.008 sec
        command  `cd / ; pwd`
        expected `/`
        got      `/home/user/out`
    Test CD2: FAILED in 0.005 sec
        command  `cd / ; cd /usr ; pwd`
        expected `/usr`
        got      `/home/user/out`
    Test CD3: FAILED in 0.005 sec
        command  `cd / ; cd /doesnotexist 2> /dev/null ; pwd`
        expected `/`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist /home/user/out`
    Test CD4: FAILED in 0.004 sec
        command  `cd / && pwd`
        expected `/`
        got      `/home/user/out`
    Test CD5: FAILED in 0.005 sec
        command  `echo go ; cd /doesnotexist 2> /dev/null > /dev/null && pwd`
        expected `go`
        got      `go /home/user/grade/cd: 2: cd: can't cd to /doesnotexist /home/user/out`
    Test CD6: FAILED in 0.004 sec
        command  `cd /doesnotexist 2> /dev/null > /dev/null || echo does not exist`
        expected `does not exist`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist does not exist`
    Test CD7: FAILED in 0.004 sec
        command  `cd /tmp && cd / && pwd`
        expected `/`
        got      `/home/user/out`
    Test CD8: FAILED in 0.004 sec
        command  `cd / ; cd /doesnotexist 2> /dev/null > /dev/null ; pwd`
        expected `/`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist /home/user/out`
    Test ADVPIPE1: FAILED in 0.300 sec
        command  `yes | head -n 5`
        expected `y y y y y`
        got      `| head -n 5 | head -n 5 | head -n 5 | head -n 5 | head -n 5 | head -n 5 | he...`
      output file size 168033888, expected <= 1000
    Test ADVBGCOND1: FAILED in 0.003 sec
        command  `sleep 0.2 && echo second & echo first`
        expected `first second`
        got      `second echo first`
    Test ADVBGCOND2: FAILED in 10.217 sec
        command  `echo first && sleep 0.1 && echo third & sleep 0.05 ; echo second ; sleep 0.1 ; echo fourth`
        expected `first second third fourth`
        got      ``
      timeout after 10.00s
    
    21 of 83 tests passed


### Marking

Total score: (25/100)

