## COMP0019 CW5 Grade Report
Report for commit SHA: 7c3a9f14a92372117e62e198afde3c9edc3dc91a

### Output


    
      CLEAN 
      COMPILE sh0019.c
    sh0019.c: In function command_free:
    sh0019.c:54:14: warning: unused variable nextSaved [-Wunused-variable]
         command *nextSaved;
                  ^
    sh0019.c: In function start_command:
    sh0019.c:103:9: warning: unused variable status [-Wunused-variable]
         int status;
             ^
    sh0019.c: In function run_list:
    sh0019.c:146:9: warning: unused variable runningStatus [-Wunused-variable]
         int runningStatus;
             ^
    sh0019.c:143:9: warning: unused variable childFork [-Wunused-variable]
         int childFork;
             ^
    sh0019.c: In function eval_line:
    sh0019.c:212:14: warning: unused variable myHead [-Wunused-variable]
         command* myHead = c;
                  ^
    sh0019.c:207:9: warning: unused variable flag [-Wunused-variable]
         int flag = 0;
             ^
      COMPILE helpers.c
      LINK sh0019 
    
    Test SIMPLE1: passed
    Test SIMPLE2: passed
    Test SIMPLE3: passed
    Test SIMPLE4: passed
    Test BG1: passed
    Test BG2: FAILED in 0.209 sec
        command  `sh -c "sleep 0.2; test -r fBG2b.txt && rm -f fBG2a.txt" &`
        expected `Still here`
        got      `cat: fBG2a.txt: No such file or directory`
    Test BG3: passed
    Test LIST1: passed
    Test LIST2: passed
    Test LIST3: passed
    Test LIST4: passed
    Test LIST5: passed
    Test LIST6: FAILED in 0.242 sec
        command  `../sh0019 -q cmdLIST6.sh &`
        expected `Hello 1`
        got      `Hello 0`
    Test LIST7: FAILED in 0.001 sec
        command  `../sh0019 -q cmdLIST7.sh`
        expected `Hello Bye 1`
        got      `Bye Hello 1`
    Test LIST8: passed
    Test COND1: passed
    Test COND2: passed
    Test COND3: passed
    Test COND4: passed
    Test COND5: passed
    Test COND6: passed
    Test COND7: passed
    Test COND8: FAILED in 0.102 sec
        command  `sleep 0.2 && echo Second & sleep 0.1 && echo First`
        expected `First Second`
        got      `First`
    Test COND9: passed
    Test COND10: FAILED in 0.004 sec
        command  `false && echo no && echo no && echo no && echo no || echo yes`
        expected `yes`
        got      `no no no`
    Test COND11: FAILED in 0.003 sec
        command  `true || echo no || echo no || echo no || echo no && echo yes`
        expected `yes`
        got      `no no yes`
    Test PIPE1: FAILED in 0.002 sec
        command  `echo Pipe | wc -c`
        expected `5`
        got      `Pipe | wc -c`
    Test PIPE2: FAILED in 0.002 sec
        command  `echo Good | grep -n G`
        expected `1:Good`
        got      `Good | grep -n G`
    Test PIPE3: FAILED in 0.002 sec
        command  `echo Bad | grep -c G`
        expected `0`
        got      `Bad | grep -c G`
    Test PIPE4: FAILED in 0.002 sec
        command  `echo Line | cat | wc -l`
        expected `1`
        got      `Line | cat | wc -l`
    Test PIPE5: FAILED in 0.004 sec
        command  `../sh0019 -q cmdPIPE5.sh; ps | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `Hello Bye 1`
        got      `Bye Hello error: garbage option Usage: ps [options] Try 'ps --help <simple|l...`
    Test PIPE6: FAILED in 0.002 sec
        command  `echo GoHangASalamiImALasagnaHog | rev | rev | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      `GoHangASalamiImALasagnaHog | rev | rev | rev`
    Test PIPE7: FAILED in 0.014 sec
        command  `rev fPIPE7.txt | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      `rev: cannot open |: No such file or directory rev: cannot open rev: No such ...`
    Test PIPE8: FAILED in 0.002 sec
        command  `cat fPIPE8.txt | tr [A-Z] [a-z] | /usr/bin/md5sum | tr -d -`
        expected `8e21d03f7955611616bcd2337fe9eac1`
        got      `cat: invalid option -- 'd' Try 'cat --help' for more information.`
    Test PIPE9: FAILED in 0.003 sec
        command  `rev fPIPE9.txt | /usr/bin/md5sum | tr [a-z] [A-Z] | tr -d -`
        expected `502B109B37EC769342948826736FA063`
        got      `rev: invalid option -- 'd' Usage: rev [options] [file ...] Reverse lines cha...`
    Test PIPE10: FAILED in 0.206 sec
        command  `sleep 2 & sleep 0.2; ps T | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `1`
        got      `error: garbage option Usage: ps [options] Try 'ps --help <simple|list|output...`
    Test PIPE11: FAILED in 0.004 sec
        command  `echo Sedi | tr d m ; echo Calan | tr a o`
        expected `Semi Colon`
        got      `Sedi | tr d m Calan | tr a o`
    Test PIPE12: FAILED in 0.003 sec
        command  `echo Ignored | echo Desired`
        expected `Desired`
        got      `Ignored | echo Desired`
    Test PIPE13: FAILED in 0.190 sec
        command  `../sh0019 -q cmdPIPE13.sh &`
        expected `Hello 1`
        got      `Hello error: garbage option Usage: ps [options] Try 'ps --help <simple|list|...`
    Test PIPE14: passed
    Test PIPE15: FAILED in 0.003 sec
        command  `true | echo True || echo False`
        expected `True`
        got      ``
    Test PIPE16: FAILED in 0.004 sec
        command  `false | echo True || echo False`
        expected `True`
        got      `False`
    Test PIPE17: FAILED in 0.003 sec
        command  `echo Hello | grep -q X || echo NoXs`
        expected `NoXs`
        got      `Hello | grep -q X`
    Test PIPE18: FAILED in 0.004 sec
        command  `echo Yes | grep -q Y && echo Ys`
        expected `Ys`
        got      `Yes | grep -q Y Ys`
    Test PIPE19: FAILED in 0.003 sec
        command  `echo Hello | grep -q X || echo poqs | tr pq NX`
        expected `NoXs`
        got      `Hello | grep -q X`
    Test PIPE20: FAILED in 0.003 sec
        command  `echo Yes | grep -q Y && echo fs | tr f Y`
        expected `Ys`
        got      `Yes | grep -q Y fs | tr f Y`
    Test PIPE21: passed
    Test PIPE22: FAILED in 0.004 sec
        command  `false && echo unexpected && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      `vnexpected | tr v u expected`
    Test PIPE23: KILLED by segmentation fault
      FAILED in 0.319 sec
        command  `sleep 0.2 | wc -c | sed s/0/Second/ & sleep 0.1 | wc -c | sed s/0/First/`
        expected `First Second`
        got      `sleep: invalid option -- 'c' Try 'sleep --help' for more information. sleep:...`
    Test ZOMBIE1: passed
    Test ZOMBIE2: passed
    Test REDIR1: FAILED in 0.002 sec
        command  `echo Start ; echo File > fREDIR1.txt`
        expected `Start File`
        got      `Start File > fREDIR1.txt cat: fREDIR1.txt: No such file or directory`
    Test REDIR2: FAILED in 0.002 sec
        command  `tr pq Fi < fREDIR2.txt ; echo Done`
        expected `File Done`
        got      `tr: extra operand < Try 'tr --help' for more information. Done`
    Test REDIR3: FAILED in 0.005 sec
        command  `perl -e 'print STDERR 1856' 2> fREDIR3.txt ; grep '^[1-9]' fREDIR3.txt | wc -l ; rm -f fREDIR3.txt`
        expected `1`
        got      `1856grep: |: No such file or directory grep: wc: No such file or directory`
    Test REDIR4: FAILED in 0.009 sec
        command  `perl -e 'print STDERR 1856; print STDOUT "X"' > fREDIR4a.txt 2> fREDIR4b.txt ; grep '^[1-9]' fREDIR4a.txt | wc -l ; grep '^[1-9]' fREDIR4b.txt | wc -l ; cmp -s fREDIR4a.txt fREDIR4b.txt || echo Different`
        expected `0 1 Different`
        got      `1856Xgrep: fREDIR4a.txt: No such file or directory grep: |: No such file or ...`
    Test REDIR5: FAILED in 0.003 sec
        command  `tr hb HB < fREDIR5.txt | sort | ../sh0019 -q cmdREDIR5.sh`
        expected `Bye Hello First Good`
        got      `tr: extra operand < Try 'tr --help' for more information.`
    Test REDIR6: FAILED in 0.014 sec
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
        got      `> /tmp/directorydoesnotexist/foo`
    Test REDIR10: FAILED in 0.003 sec
        command  `echo Hello < nonexistentREDIR10.txt`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR10.txt`
    Test REDIR11: FAILED in 0.004 sec
        command  `echo Hello < nonexistentREDIR11.txt && echo Unwanted`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR11.txt Unwanted`
    Test REDIR12: FAILED in 0.003 sec
        command  `echo Hello < nonexistentREDIR12.txt || echo Wanted`
        expected `No such file or directory Wanted`
        got      `Hello < nonexistentREDIR12.txt`
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
    Test INTR1: FAILED in 0.205 sec
        command  `echo a && sleep 0.2 && echo b`
        expected `a`
        got      `a b`
    Test INTR2: FAILED in 0.206 sec
        command  `echo start && sleep 0.2 && echo undesired  \n  echo end`
        expected `start end`
        got      `start undesired end`
    Test INTR3: FAILED in 0.206 sec
        command  `sleep 0.3 && echo yes & sleep 0.2 && echo no`
        expected `yes`
        got      `no`
    Test INTR4: FAILED in 1.004 sec
        command  `sleep 1`
        should have completed in 0.150 sec
    Test INTR5: FAILED in 1.006 sec
        command  `../sh0019 -q cmdINTR5.sh`
        expected ``
        got      `undesired`
        should have completed in 0.150 sec
    Test CD1: FAILED in 0.010 sec
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
    Test CD5: FAILED in 0.004 sec
        command  `echo go ; cd /doesnotexist 2> /dev/null > /dev/null && pwd`
        expected `go`
        got      `go /home/user/grade/cd: 2: cd: can't cd to /doesnotexist`
    Test CD6: FAILED in 0.004 sec
        command  `cd /doesnotexist 2> /dev/null > /dev/null || echo does not exist`
        expected `does not exist`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist does not exist`
    Test CD7: FAILED in 0.005 sec
        command  `cd /tmp && cd / && pwd`
        expected `/`
        got      `/home/user/out`
    Test CD8: FAILED in 0.005 sec
        command  `cd / ; cd /doesnotexist 2> /dev/null > /dev/null ; pwd`
        expected `/`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist /home/user/out`
    Test ADVPIPE1: FAILED in 0.302 sec
        command  `yes | head -n 5`
        expected `y y y y y`
        got      `| head -n 5 | head -n 5 | head -n 5 | head -n 5 | head -n 5 | head -n 5 | he...`
      output file size 165347328, expected <= 1000
    Test ADVBGCOND1: FAILED in 0.002 sec
        command  `sleep 0.2 && echo second & echo first`
        expected `first second`
        got      `first`
    Test ADVBGCOND2: FAILED in 0.007 sec
        command  `echo first && sleep 0.1 && echo third & sleep 0.05 ; echo second ; sleep 0.1 ; echo fourth`
        expected `first second third fourth`
        got      `third first second fourth`
    
    24 of 83 tests passed


### Marking

Total score: (29/100)

