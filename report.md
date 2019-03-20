## COMP0019 CW5 Grade Report
Report for commit SHA: fd2e82a2240f57cef2dadb6a4df01b33144a5a32

### Output


    
      CLEAN 
      COMPILE sh0019.c
    sh0019.c: In function run_list:
    sh0019.c:121:9: warning: unused variable child_status [-Wunused-variable]
         int child_status;
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
    Test LIST2: FAILED in 0.001 sec
        command  `echo Semi ; echo Colon`
        expected `Semi Colon`
        got      `Semi echo Colon`
    Test LIST3: FAILED in 0.001 sec
        command  `echo Semi ; echo Colon ; echo Rocks`
        expected `Semi Colon Rocks`
        got      `Semi echo Colon echo Rocks`
    Test LIST4: FAILED in 0.001 sec
        command  `echo Hello ;   echo There ; echo Who ; echo Are ; echo You ; echo ?`
        expected `Hello There Who Are You ?`
        got      `Hello echo There echo Who echo Are echo You echo ?`
    Test LIST5: FAILED in 0.001 sec
        command  `rm -f fLIST5.txt ; echo Removed`
        expected `Removed`
        got      ``
    Test LIST6: FAILED in 0.001 sec
        command  `../sh0019 -q cmdLIST6.sh &`
        expected `Hello 1`
        got      `Hello sleep 0.4 0`
    Test LIST7: FAILED in 0.001 sec
        command  `../sh0019 -q cmdLIST7.sh`
        expected `Hello Bye 1`
        got      `Hello sleep 2 echo Bye 0`
    Test LIST8: FAILED in 0.001 sec
        command  `sh -c "sleep 0.2; echo Second" & sh -c "sleep 0.15; echo First" & sleep 0.3`
        expected `First Second`
        got      ``
    Test COND1: FAILED in 0.001 sec
        command  `true && echo True`
        expected `True`
        got      ``
    Test COND2: FAILED in 0.001 sec
        command  `echo True || echo False`
        expected `True`
        got      `True || echo False`
    Test COND3: FAILED in 0.001 sec
        command  `grep -cv NotThere ../sh0019.c && echo Wanted`
        expected `235 Wanted`
        got      `../sh0019.c:235 grep: echo: No such file or directory grep: Wanted: No such ...`
    Test COND4: FAILED in 0.001 sec
        command  `grep -c NotThere ../sh0019.c && echo Unwanted`
        expected `0`
        got      `../sh0019.c:0 grep: echo: No such file or directory grep: Unwanted: No such ...`
    Test COND5: FAILED in 0.002 sec
        command  `false || echo True`
        expected `True`
        got      ``
    Test COND6: FAILED in 0.001 sec
        command  `true && false || true && echo Good`
        expected `Good`
        got      ``
    Test COND7: FAILED in 0.001 sec
        command  `echo Start && false || false && echo Bad`
        expected `Start`
        got      `Start false || false echo Bad`
    Test COND8: FAILED in 0.002 sec
        command  `sleep 0.2 && echo Second & sleep 0.1 && echo First`
        expected `First Second`
        got      `sleep: invalid time interval echo sleep: invalid time interval Seco...`
    Test COND9: FAILED in 0.002 sec
        command  `echo Start && false || false && false || echo End`
        expected `Start End`
        got      `Start false || false false || echo End`
    Test COND10: FAILED in 0.002 sec
        command  `false && echo no && echo no && echo no && echo no || echo yes`
        expected `yes`
        got      ``
    Test COND11: FAILED in 0.002 sec
        command  `true || echo no || echo no || echo no || echo no && echo yes`
        expected `yes`
        got      ``
    Test PIPE1: FAILED in 0.002 sec
        command  `echo Pipe | wc -c`
        expected `5`
        got      `Pipe | wc -c`
    Test PIPE2: FAILED in 0.004 sec
        command  `echo Good | grep -n G`
        expected `1:Good`
        got      `Good | grep -n G`
    Test PIPE3: FAILED in 0.002 sec
        command  `echo Bad | grep -c G`
        expected `0`
        got      `Bad | grep -c G`
    Test PIPE4: FAILED in 0.003 sec
        command  `echo Line | cat | wc -l`
        expected `1`
        got      `Line | cat | wc -l`
    Test PIPE5: FAILED in 0.002 sec
        command  `../sh0019 -q cmdPIPE5.sh; ps | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `Hello Bye 1`
        got      `Hello sleep 2 echo Bye`
    Test PIPE6: FAILED in 0.001 sec
        command  `echo GoHangASalamiImALasagnaHog | rev | rev | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      `GoHangASalamiImALasagnaHog | rev | rev | rev`
    Test PIPE7: FAILED in 0.002 sec
        command  `rev fPIPE7.txt | rev`
        expected `goHangasaLAmIimalaSAgnaHoG`
        got      `rev: cannot open |: No such file or directory rev: cannot open rev: No such ...`
    Test PIPE8: FAILED in 0.002 sec
        command  `cat fPIPE8.txt | tr [A-Z] [a-z] | /usr/bin/md5sum | tr -d -`
        expected `8e21d03f7955611616bcd2337fe9eac1`
        got      `cat: invalid option -- 'd' Try 'cat --help' for more information.`
    Test PIPE9: FAILED in 0.002 sec
        command  `rev fPIPE9.txt | /usr/bin/md5sum | tr [a-z] [A-Z] | tr -d -`
        expected `502B109B37EC769342948826736FA063`
        got      `rev: invalid option -- 'd' Usage: rev [options] [file ...] Reverse lines cha...`
    Test PIPE10: FAILED in 0.001 sec
        command  `sleep 2 & sleep 0.2; ps T | grep sleep | grep -v grep | head -n 1 | wc -l`
        expected `1`
        got      `sleep: invalid option -- 'v' Try 'sleep --help' for more information.`
    Test PIPE11: FAILED in 0.002 sec
        command  `echo Sedi | tr d m ; echo Calan | tr a o`
        expected `Semi Colon`
        got      `Sedi | tr d m echo Calan | tr a o`
    Test PIPE12: FAILED in 0.002 sec
        command  `echo Ignored | echo Desired`
        expected `Desired`
        got      `Ignored | echo Desired`
    Test PIPE13: FAILED in 0.001 sec
        command  `../sh0019 -q cmdPIPE13.sh &`
        expected `Hello 1`
        got      `Hello sleep 0.4 sleep: invalid option -- 'v' Try 'sleep --help' for more inf...`
    Test PIPE14: FAILED in 0.001 sec
        command  `true | true && echo True`
        expected `True`
        got      ``
    Test PIPE15: FAILED in 0.002 sec
        command  `true | echo True || echo False`
        expected `True`
        got      ``
    Test PIPE16: FAILED in 0.003 sec
        command  `false | echo True || echo False`
        expected `True`
        got      ``
    Test PIPE17: FAILED in 0.002 sec
        command  `echo Hello | grep -q X || echo NoXs`
        expected `NoXs`
        got      `Hello | grep -q X || echo NoXs`
    Test PIPE18: FAILED in 0.001 sec
        command  `echo Yes | grep -q Y && echo Ys`
        expected `Ys`
        got      `Yes | grep -q Y echo Ys`
    Test PIPE19: FAILED in 0.001 sec
        command  `echo Hello | grep -q X || echo poqs | tr pq NX`
        expected `NoXs`
        got      `Hello | grep -q X || echo poqs | tr pq NX`
    Test PIPE20: FAILED in 0.001 sec
        command  `echo Yes | grep -q Y && echo fs | tr f Y`
        expected `Ys`
        got      `Yes | grep -q Y echo fs | tr f Y`
    Test PIPE21: FAILED in 0.001 sec
        command  `false && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      ``
    Test PIPE22: FAILED in 0.002 sec
        command  `false && echo unexpected && echo vnexpected | tr v u ; echo expected`
        expected `expected`
        got      ``
    Test PIPE23: FAILED in 0.001 sec
        command  `sleep 0.2 | wc -c | sed s/0/Second/ & sleep 0.1 | wc -c | sed s/0/First/`
        expected `First Second`
        got      `sleep: invalid option -- 'c' Try 'sleep --help' for more information.`
    Test ZOMBIE1: passed
    Test ZOMBIE2: passed
    Test REDIR1: FAILED in 0.002 sec
        command  `echo Start ; echo File > fREDIR1.txt`
        expected `Start File`
        got      `Start echo File > fREDIR1.txt cat: fREDIR1.txt: No such file or directory`
    Test REDIR2: FAILED in 0.003 sec
        command  `tr pq Fi < fREDIR2.txt ; echo Done`
        expected `File Done`
        got      `tr: extra operand < Try 'tr --help' for more information.`
    Test REDIR3: FAILED in 0.003 sec
        command  `perl -e 'print STDERR 1858' 2> fREDIR3.txt ; grep '^[1-9]' fREDIR3.txt | wc -l ; rm -f fREDIR3.txt`
        expected `1`
        got      `1858`
    Test REDIR4: FAILED in 0.004 sec
        command  `perl -e 'print STDERR 1858; print STDOUT "X"' > fREDIR4a.txt 2> fREDIR4b.txt ; grep '^[1-9]' fREDIR4a.txt | wc -l ; grep '^[1-9]' fREDIR4b.txt | wc -l ; cmp -s fREDIR4a.txt fREDIR4b.txt || echo Different`
        expected `0 1 Different`
        got      `1858X`
    Test REDIR5: FAILED in 0.003 sec
        command  `tr hb HB < fREDIR5.txt | sort | ../sh0019 -q cmdREDIR5.sh`
        expected `Bye Hello First Good`
        got      `tr: extra operand < Try 'tr --help' for more information.`
    Test REDIR6: FAILED in 0.003 sec
        command  `sort < fREDIR6a.txt > fREDIR6b.txt ; tail -n 2 fREDIR6b.txt ; rm -f fREDIR6a.txt fREDIR6b.txt`
        expected `Bye Hello`
        got      `sort: cannot read: '<': No such file or directory`
    Test REDIR7: FAILED in 0.003 sec
        command  `echo > /tmp/directorydoesnotexist/foo`
        expected `No such file or directory`
        got      `> /tmp/directorydoesnotexist/foo`
    Test REDIR8: FAILED in 0.001 sec
        command  `echo > /tmp/directorydoesnotexist/foo && echo Unwanted`
        expected `No such file or directory`
        got      `> /tmp/directorydoesnotexist/foo echo Unwanted`
    Test REDIR9: FAILED in 0.002 sec
        command  `echo > /tmp/directorydoesnotexist/foo || echo Wanted`
        expected `No such file or directory Wanted`
        got      `> /tmp/directorydoesnotexist/foo || echo Wanted`
    Test REDIR10: FAILED in 0.002 sec
        command  `echo Hello < nonexistentREDIR10.txt`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR10.txt`
    Test REDIR11: FAILED in 0.002 sec
        command  `echo Hello < nonexistentREDIR11.txt && echo Unwanted`
        expected `No such file or directory`
        got      `Hello < nonexistentREDIR11.txt echo Unwanted`
    Test REDIR12: FAILED in 0.002 sec
        command  `echo Hello < nonexistentREDIR12.txt || echo Wanted`
        expected `No such file or directory Wanted`
        got      `Hello < nonexistentREDIR12.txt || echo Wanted`
    Test REDIR13: FAILED in 0.002 sec
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
    Test INTR1: FAILED in 0.002 sec
        command  `echo a && sleep 0.2 && echo b`
        expected `a`
        got      `a sleep 0.2 echo b`
    Test INTR2: FAILED in 0.003 sec
        command  `echo start && sleep 0.2 && echo undesired  \n  echo end`
        expected `start end`
        got      `end start sleep 0.2 echo undesired end`
    Test INTR3: FAILED in 0.002 sec
        command  `sleep 0.3 && echo yes & sleep 0.2 && echo no`
        expected `yes`
        got      `sleep: invalid time interval echo sleep: invalid time interval yes...`
    Test INTR4: FAILED in 1.003 sec
        command  `sleep 1`
        should have completed in 0.150 sec
    Test INTR5: FAILED in 0.003 sec
        command  `../sh0019 -q cmdINTR5.sh`
        expected ``
        got      `sleep: invalid time interval echo sleep: invalid time interval unde...`
    Test CD1: FAILED in 0.003 sec
        command  `cd / ; pwd`
        expected `/`
        got      ``
    Test CD2: FAILED in 0.003 sec
        command  `cd / ; cd /usr ; pwd`
        expected `/usr`
        got      ``
    Test CD3: FAILED in 0.003 sec
        command  `cd / ; cd /doesnotexist 2> /dev/null ; pwd`
        expected `/`
        got      ``
    Test CD4: FAILED in 0.002 sec
        command  `cd / && pwd`
        expected `/`
        got      ``
    Test CD5: FAILED in 0.002 sec
        command  `echo go ; cd /doesnotexist 2> /dev/null > /dev/null && pwd`
        expected `go`
        got      `go cd /doesnotexist 2> /dev/null > /dev/null pwd`
    Test CD6: FAILED in 0.003 sec
        command  `cd /doesnotexist 2> /dev/null > /dev/null || echo does not exist`
        expected `does not exist`
        got      `/home/user/grade/cd: 2: cd: can't cd to /doesnotexist`
    Test CD7: FAILED in 0.002 sec
        command  `cd /tmp && cd / && pwd`
        expected `/`
        got      ``
    Test CD8: FAILED in 0.003 sec
        command  `cd / ; cd /doesnotexist 2> /dev/null > /dev/null ; pwd`
        expected `/`
        got      ``
    Test ADVPIPE1: FAILED in 0.301 sec
        command  `yes | head -n 5`
        expected `y y y y y`
        got      `| head -n 5 | head -n 5 | head -n 5 | head -n 5 | head -n 5 | head -n 5 | he...`
      output file size 164760288, expected <= 1000
    Test ADVBGCOND1: FAILED in 0.002 sec
        command  `sleep 0.2 && echo second & echo first`
        expected `first second`
        got      `sleep: invalid time interval echo sleep: invalid time interval seco...`
    Test ADVBGCOND2: FAILED in 0.002 sec
        command  `echo first && sleep 0.1 && echo third & sleep 0.05 ; echo second ; sleep 0.1 ; echo fourth`
        expected `first second third fourth`
        got      `first sleep 0.1 echo third sleep 0.05 echo second sleep 0.1 echo fourth`
    
    10 of 83 tests passed


### Marking

Total score: (12/100)

