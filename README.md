# Rotor Machine

## Compile

```bash
gcc -o rotor_machine -std=c99 rotor_machine.c
```

or

```bash
make
```

## Execute

```bash
./rotor_machine
```

## Usage

```bash
text: abcd
code: azro
```

```bash
text: hello world
code: xcoir xsjgr
```

`text` is the plaintext message that you want to encrypt and `code` is the encrypted message.

## Commands

- peek: output the current state of the rotors
- quit: exit the program
- reset: reset the rotors

When the text you enter matches any of the commands above, the program asks if it is a command to be executed (y) or a message to be encrypted (n).

```bash
is it a command? (y/n)
```

e.g. peek

```bash
text: peek
is it a command? (y/n)
y
inner:
0 -> 9
1 -> 21
2 -> 0
```

```bash
text: peek
is it a command? (y/n)
n
code: vcsy
```
