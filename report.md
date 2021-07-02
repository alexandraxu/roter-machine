# Report

## Complexity of the Program

The function, `encrypt`, loops through the input string once. In each iteration, it takes O(1) time to calculate the positions of the pins using mappings and offsets for inner and outer rotors. So the complexity of the encryption is O(n).

## Test Cases

Test cases are dependent. 'A' -> 'EE' -> 'Mr. Jock, TV quiz PhD, bags few lynx'

### 1

initial state:

```
inner:
0 -> 9
1 -> 21
2 -> 0
3 -> 19
4 -> 18
5 -> 6
6 -> 3
7 -> 23
8 -> 10
9 -> 16
10 -> 12
11 -> 22
12 -> 13
13 -> 14
14 -> 7
15 -> 8
16 -> 24
17 -> 20
18 -> 1
19 -> 25
20 -> 2
21 -> 17
22 -> 5
23 -> 11
24 -> 4
25 -> 15

outer:
0 -> 24
1 -> 6
2 -> 18
3 -> 7
4 -> 20
5 -> 1
6 -> 22
7 -> 15
8 -> 21
9 -> 0
10 -> 25
11 -> 17
12 -> 14
13 -> 4
14 -> 9
15 -> 12
16 -> 10
17 -> 5
18 -> 16
19 -> 11
20 -> 2
21 -> 3
22 -> 13
23 -> 23
24 -> 19
25 -> 8
```

encrypt 'A':

```
text: A
code: a
```

state after encryption:

```
inner:
25 -> 15
0 -> 9
1 -> 21
2 -> 0
3 -> 19
4 -> 18
5 -> 6
6 -> 3
7 -> 23
8 -> 10
9 -> 16
10 -> 12
11 -> 22
12 -> 13
13 -> 14
14 -> 7
15 -> 8
16 -> 24
17 -> 20
18 -> 1
19 -> 25
20 -> 2
21 -> 17
22 -> 5
23 -> 11
24 -> 4

outer:
0 -> 24
1 -> 6
2 -> 18
3 -> 7
4 -> 20
5 -> 1
6 -> 22
7 -> 15
8 -> 21
9 -> 0
10 -> 25
11 -> 17
12 -> 14
13 -> 4
14 -> 9
15 -> 12
16 -> 10
17 -> 5
18 -> 16
19 -> 11
20 -> 2
21 -> 3
22 -> 13
23 -> 23
24 -> 19
25 -> 8
```

### 2

initial state:

```bash
inner:
25 -> 15
0 -> 9
1 -> 21
2 -> 0
3 -> 19
4 -> 18
5 -> 6
6 -> 3
7 -> 23
8 -> 10
9 -> 16
10 -> 12
11 -> 22
12 -> 13
13 -> 14
14 -> 7
15 -> 8
16 -> 24
17 -> 20
18 -> 1
19 -> 25
20 -> 2
21 -> 17
22 -> 5
23 -> 11
24 -> 4

outer:
0 -> 24
1 -> 6
2 -> 18
3 -> 7
4 -> 20
5 -> 1
6 -> 22
7 -> 15
8 -> 21
9 -> 0
10 -> 25
11 -> 17
12 -> 14
13 -> 4
14 -> 9
15 -> 12
16 -> 10
17 -> 5
18 -> 16
19 -> 11
20 -> 2
21 -> 3
22 -> 13
23 -> 23
24 -> 19
25 -> 8
```

encrypt 'EE':

```bash
text: EE 
code: cs
```

state after encryption:

```
inner:
23 -> 11
24 -> 4
25 -> 15
0 -> 9
1 -> 21
2 -> 0
3 -> 19
4 -> 18
5 -> 6
6 -> 3
7 -> 23
8 -> 10
9 -> 16
10 -> 12
11 -> 22
12 -> 13
13 -> 14
14 -> 7
15 -> 8
16 -> 24
17 -> 20
18 -> 1
19 -> 25
20 -> 2
21 -> 17
22 -> 5

outer:
0 -> 24
1 -> 6
2 -> 18
3 -> 7
4 -> 20
5 -> 1
6 -> 22
7 -> 15
8 -> 21
9 -> 0
10 -> 25
11 -> 17
12 -> 14
13 -> 4
14 -> 9
15 -> 12
16 -> 10
17 -> 5
18 -> 16
19 -> 11
20 -> 2
21 -> 3
22 -> 13
23 -> 23
24 -> 19
25 -> 8
```

Is a rotor machine a monoalphabetic or polyalphabetic cipher? Comment based
on the results above.

> It is a polyalphabetic cipher.
> In this case, two 'E's in the input string have different substitution alphabets, 'c' and 's'. 

### 3

initial state:

```bash
inner:
23 -> 11
24 -> 4
25 -> 15
0 -> 9
1 -> 21
2 -> 0
3 -> 19
4 -> 18
5 -> 6
6 -> 3
7 -> 23
8 -> 10
9 -> 16
10 -> 12
11 -> 22
12 -> 13
13 -> 14
14 -> 7
15 -> 8
16 -> 24
17 -> 20
18 -> 1
19 -> 25
20 -> 2
21 -> 17
22 -> 5

outer:
0 -> 24
1 -> 6
2 -> 18
3 -> 7
4 -> 20
5 -> 1
6 -> 22
7 -> 15
8 -> 21
9 -> 0
10 -> 25
11 -> 17
12 -> 14
13 -> 4
14 -> 9
15 -> 12
16 -> 10
17 -> 5
18 -> 16
19 -> 11
20 -> 2
21 -> 3
22 -> 13
23 -> 23
24 -> 19
25 -> 8
```

encrypt 'Mr. Jock, TV quiz PhD, bags few lynx':

```bash
text: Mr. Jock, TV quiz PhD, bags few lynx
code: lq. xktv, dw fnuz tzu, vkpw ocs oifr
```

state after encryption:

```bash
inner:
23 -> 11
24 -> 4
25 -> 15
0 -> 9
1 -> 21
2 -> 0
3 -> 19
4 -> 18
5 -> 6
6 -> 3
7 -> 23
8 -> 10
9 -> 16
10 -> 12
11 -> 22
12 -> 13
13 -> 14
14 -> 7
15 -> 8
16 -> 24
17 -> 20
18 -> 1
19 -> 25
20 -> 2
21 -> 17
22 -> 5

outer:
25 -> 8
0 -> 24
1 -> 6
2 -> 18
3 -> 7
4 -> 20
5 -> 1
6 -> 22
7 -> 15
8 -> 21
9 -> 0
10 -> 25
11 -> 17
12 -> 14
13 -> 4
14 -> 9
15 -> 12
16 -> 10
17 -> 5
18 -> 16
19 -> 11
20 -> 2
21 -> 3
22 -> 13
23 -> 23
24 -> 19
```

Comment on the state of your cylinders before and after encryption. Please
provide an explanation for what you observe.

> The outer rotor has rotated one pin position and the inner rotor has made more than a complete rotation.
> The input text has 26 letters.
> For every complete rotation of the inner rotor, the outer rotor rotates one pin position.
> And for every keystroke, the inner rotor rotates one pin position.