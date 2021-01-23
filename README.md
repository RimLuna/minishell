# minishell
I don't even know how to use bash properly

nevermind fucking make one
## What the fuck
This project either sounds overly complicated or overly simple, it's a whole lot of text interpretation, AGAIN

**Take-away: parsing 'till I fucking drop dead, in a bad way**

## how bash handes input
the size of the input buffer differs dependin on systems,

### canonical vs non-canonical input mode


## bash grammar
### literal values
```
mkdir traitors
mkdir class traitors
mkdir "fucking liberals"
```
bash interprets **"fucking liberals"**,  **traitors**, and **class traitors** (the space too) as literal values.

while **mkdir**, **spaces between mkdir and the literals**, and **quotation marks** are not

*this already sounds like a fucking pain in the ass*
### quotes: just using them is a nightmare
#### double quotes
well there's the fucking nightmare of expanding *special characters* (**$** for example) because double quotes are whores

where **$var** is replaced by the value of variable var
#### single quotes
the entire text string is interpreted literally, yay
#### FUCKING spaces, I am regretting ever writing code
Starting with filenames, why would you put a space in a filename, why why why, fucking idiots, as a *stalinist*, I'd 've not allowed this, along with **80s graphics projects**
```
$ mkdir "eat the rich"
$ mkdir "I put my low
> self esteem 
> into filenames"
$ ls
'eat the rich'
'I put my low'$'\n''self esteem '$'\n''into filenames'
```
I don't know if we're supposed to interpret newlines in filenames because that's fucking stupid and a hate crime. any character is allowed in filenames but software could misinterpret it and that's ur fault

another thing would be, creating files using variables, with spaces..
```
$ filename='Landlords are parasites'
$ echo $filename 
Landlords are parasites
$ ls
are  Landlords  parasites
$ mkdir '$filename'
$ ls
'$filename'
$ mkdir "$filename" 
$ ls
'Landlords are parasites'
```
fucking hell
## line by line interpretation
command is executed after pressing Enter, unledd this interaction is explicitely changed
### split commands to multiples lines using backslashes
for readability, and to make my life hard
```
$ echo Crap\
> italism
Crapitalism
```
this works only if the **\\** is the last character in the line, kill me
### semincolons
```
$ touch file; echo "communism will win"; cat file
communism will win
```
### double ampersands &&
different from **;** in that if first command fails, the following commands will not run
```
$ ls /root && ls
ls: cannot open directory '/root': Permission denied
```
using **&&** is safer that using **;** when executing destructive commands
### heredoc strings
specify that a certain delimiter denotes start and end of string
```
$ cat <<EOF
> The history of all
> hitherto existing society
> is the history of class struggles
> EOF
The history of all
hitherto existing society
is the history of class struggles
```
there are a LOT of fucking ways to use HEREDOC, I don't know which ones we're supposed to interpret yet, cuz of course I didn't read the subject.


