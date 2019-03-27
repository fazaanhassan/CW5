## COMP0019 CW5 Grade Report
Report for commit SHA: 8cb23c9a81b5908a956967878a41befdee334022

### Output


    
      CLEAN 
      COMPILE sh0019.c
    sh0019.c: In function command_free:
    sh0019.c:55:14: warning: unused variable nextSaved [-Wunused-variable]
         command *nextSaved;
                  ^
    sh0019.c: In function start_command:
    sh0019.c:86:9: warning: unused variable status [-Wunused-variable]
         int status;
             ^
    sh0019.c: In function run_list:
    sh0019.c:154:9: warning: unused variable childFork [-Wunused-variable]
         int childFork;
             ^
    sh0019.c: In function eval_line:
    sh0019.c:245:14: warning: unused variable myHead [-Wunused-variable]
         command* myHead = c;
                  ^
    sh0019.c:241:9: warning: unused variable flag [-Wunused-variable]
         int flag = 0;
             ^
    sh0019.c: In function start_command:
    sh0019.c:102:5: warning: ignoring return value of pipe, declared with attribute warn_unused_result [-Wunused-result]
         pipe(firstPfds);
         ^
    sh0019.c:104:9: warning: ignoring return value of pipe, declared with attribute warn_unused_result [-Wunused-result]
             pipe(secondPfds);
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
    Test BG3: FAILED in 2.003 sec
        command  `sleep 2 &`
        expected `1`
        got      `0`
    Test LIST1: passed
    Test LIST2: passed
    Test LIST3: passed
    Test LIST4: passed
    Test LIST5: passed
    Test LIST6: FAILED in 0.238 sec
        command  `../sh0019 -q cmdLIST6.sh &`
        expected `Hello 1`
        got      `Hello 0`
    Test LIST7: FAILED in 0.002 sec
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
    Test COND8: FAILED in 0.110 sec
        command  `sleep 0.2 && echo Second & sleep 0.1 && echo First`
        expected `First Second`
        got      `First`
    Test COND9: passed
    Test COND10: passed
    Test COND11: passed
    Test PIPE1: passed
    Test PIPE2: passed
    Test PIPE3: passed
    Test PIPE4: FAILED in 0.002 sec
        command  `echo Line | cat | wc -l`
        expected `1`
        got      ``
    Test PIPE5: FAILED in 0.020 sec
        command  `../sh0019 -q cmdPIPE5.sh; ps | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `Hello Bye 1`
        got      `Bye Hello`
    Test PIPE6: FAILED in 0.002 sec
        command  `echo GoHangASalamiImALasagnaHog | rev | rev | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      ``
    Test PIPE7: passed
    Test PIPE8: FAILED in 0.003 sec
        command  `cat fPIPE8.txt | tr [A-Z] [a-z] | /usr/bin/md5sum | tr -d -`
        expected `8e21d03f7955611616bcd2337fe9eac1`
        got      ``
    Test PIPE9: FAILED in 0.004 sec
        command  `rev fPIPE9.txt | /usr/bin/md5sum | tr [a-z] [A-Z] | tr -d -`
        expected `502B109B37EC769342948826736FA063`
        got      ``
    Test PIPE10: FAILED in 0.223 sec
        command  `sleep 2 & sleep 0.2; ps T | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `1`
        got      ``
    Test PIPE11: FAILED in 0.004 sec
        command  `echo Sedi | tr d m ; echo Calan | tr a o`
        expected `Semi Colon`
        got      `Colon Semi`
    Test PIPE12: passed
    Test PIPE13: FAILED in 0.178 sec
        command  `../sh0019 -q cmdPIPE13.sh &`
        expected `Hello 1`
        got      `Hello`
    Test PIPE14: passed
    Test PIPE15: passed
    Test PIPE16: passed
    Test PIPE17: FAILED in 0.003 sec
        command  `echo Hello | grep -q X || echo NoXs`
        expected `NoXs`
        got      ``
    Test PIPE18: passed
    Test PIPE19: FAILED in 0.004 sec
        command  `echo Hello | grep -q X || echo poqs | tr pq NX`
        expected `NoXs`
        got      ``
    Test PIPE20: passed
    Test PIPE21: FAILED in 0.002 sec
        command  `false && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      ``
    Test PIPE22: FAILED in 0.002 sec
        command  `false && echo unexpected && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      ``
    Test PIPE23: FAILED in 0.005 sec
        command  `sleep 0.2 | wc -c | sed s/0/Second/ & sleep 0.1 | wc -c | sed s/0/First/`
        expected `First Second`
        got      ``
    Test ZOMBIE1: passed
    Test ZOMBIE2: passed
    Test REDIR1: FAILED in 0.007 sec
        command  `echo Start ; echo File > fREDIR1.txt`
        expected `Start File`
        got      `Start File > fREDIR1.txt cat: fREDIR1.txt: No such file or directory`
    Test REDIR2: FAILED in 0.002 sec
        command  `tr pq Fi < fREDIR2.txt ; echo Done`
        expected `File Done`
        got      `tr: extra operand < Try 'tr --help' for more information. Done`
    Test REDIR3: FAILED in 0.003 sec
        command  `perl -e 'print STDERR 1854' 2> fREDIR3.txt ; grep '^[1-9]' fREDIR3.txt | wc -l ; rm -f fREDIR3.txt`
        expected `1`
        got      `18540`
    Test REDIR4: FAILED in 0.008 sec
        command  `perl -e 'print STDERR 1854; print STDOUT "X"' > fREDIR4a.txt 2> fREDIR4b.txt ; grep '^[1-9]' fREDIR4a.txt | wc -l ; grep '^[1-9]' fREDIR4b.txt | wc -l ; cmp -s fREDIR4a.txt fREDIR4b.txt || echo Different`
        expected `0 1 Different`
        got      `1854Xgrep: fREDIR4a.txt: No such file or directory grep: fREDIR4b.txt: No su...`
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
    Test REDIR10: FAILED in 0.002 sec
        command  `echo Hello < nonexistentREDIR10.txt`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR10.txt`
    Test REDIR11: FAILED in 0.003 sec
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
        got      `cat: '<': No such file or directory Wanted`
    Test REDIR14: FAILED in 0.003 sec
        command  `cat < wanted.txt | cat > output.txt`
        expected `output.txt is Wanted`
        got      `cat: '>': No such file or directory cat: output.txt: No such file or directo...`
    Test REDIR15: FAILED in 0.003 sec
        command  `cat < xoqted.txt | tr xoq Wan | cat > output.txt`
        expected `output.txt is Wanted`
        got      `cat: '>': No such file or directory cat: output.txt: No such file or directo...`
    Test REDIR16: FAILED in 0.003 sec
        command  `echo Ignored | cat < lower.txt | tr A-Z a-z`
        expected `lower`
        got      `cat: '<': No such file or directory lower`
    Test INTR1: FAILED in 0.205 sec
        command  `echo a && sleep 0.2 && echo b`
        expected `a`
        got      `a b`
    Test INTR2: FAILED in 0.205 sec
        command  `echo start && sleep 0.2 && echo undesired  \n  echo end`
        expected `start end`
        got      `start undesired end`
    Test INTR3: FAILED in 0.204 sec
        command  `sleep 0.3 && echo yes & sleep 0.2 && echo no`
        expected `yes`
        got      `no`
    Test INTR4: FAILED in 1.005 sec
        command  `sleep 1`
        should have completed in 0.150 sec
    Test INTR5: FAILED in 1.006 sec
        command  `../sh0019 -q cmdINTR5.sh`
        expected ``
        got      `undesired`
        should have completed in 0.150 sec
    Test CD1: FAILED in 0.014 sec
        command  `cd / ; pwd`
        expected `/`
        got      `/home/user/out`
    Test CD2: FAILED in 0.004 sec
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
    Test CD8: FAILED in 0.004 sec
        command  `cd / ; cd /doesnotexist 2> /dev/null > /dev/null ; pwd`
        expected `/`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist /home/user/out`
    Test ADVPIPE1: passed
    Test ADVBGCOND1: FAILED in 0.003 sec
        command  `sleep 0.2 && echo second & echo first`
        expected `first second`
        got      `first`
    Test ADVBGCOND2: FAILED in 0.007 sec
        command  `echo first && sleep 0.1 && echo third & sleep 0.05 ; echo second ; sleep 0.1 ; echo fourth`
        expected `first second third fourth`
        got      `third first second fourth`
    
    34 of 83 tests passed


### Marking

Total score: (41/100)

