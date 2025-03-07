# Simple password generator

This is just a random utility I wrote to generate strings of random characters to use as a password.
The only reason this thing is public, is so my GitHub page doesn't seem so empty while I work on other projects.

# How to use

When it asks:
```
Desired password length:
```

Input a positive integer that is > 0
I guess it could go up to 32767, but it depends on what size your compiler assigns an int to.

When it asks:
```
How many passwords to generate:
```

Do the same as above.

# Building from source

Clone the repo, and compile it with your favorite C compiler.

```
git clone https://github.com/kilobyte-disk/password-generator.git

cd password-generator

gcc src/main.c -o build/password-generator
```
