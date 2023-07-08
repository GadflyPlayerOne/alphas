<!-- @format -->

# Alphas

Alphas is an artificial life simulator turned into a game. Select a number and see how long you can live. You get 3 lives, but watch out for the instant death! Can your alpha make it to the end? It only needs to live for a minute to win it!

## How to build (Linux/Mac)

Build the code with the following command:

```
gcc alpha.h -o alpha
```

And run the program with:

```
./alpha
```

### Can you survive?

Can you find the best number to survive the longest?

## Sample output

Here is some sample output of the game:

```
-> % ./alpha
Enter an integer:1000

3

2

1

Go!

0: -294
*ouch* 2 lives left.
1: -796
*ouch* 1 lives left.
1: -642
*ouch* 0 lives left.


You have died. Your score was: 1
```

## Beware of the Instant Death

Beware of the instant death! Some numbers are more susceptable to it than others. You will find out.

```
-> % ./alpha
Enter an integer:55

3

2

1

Go!



You have died an instant death. Your lived: 40 seconds
```

## Try and make it to the end

Can you live long enough to win the game? Only chance will tell.

```
-> % ./alpha
Enter an integer:800

3

2

1

Go!

*ouch* 2 lives left.
*ouch* 1 lives left.
Congratulations! You lived. You won at life.

Goodbye.
```

Will luck be ever in you favor. Same numbers can have drastically different results.

```
-> % ./alpha
Enter an integer:800

3

2

1

Go!

*ouch* 2 lives left.
*ouch* 1 lives left.


You are out of lives. You lived for: 0 seconds
```
