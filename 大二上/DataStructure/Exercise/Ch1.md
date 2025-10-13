---
title: Ch1

---

> program prefixed macro: `#define ull unsigned long long`

### 1-5-8
---
>Write a recursive function for computing the binomial coefficient $\binom{n}{m}$ as defined in Section 1.5.2, where $\binom{n}{0} = \binom{n}{n} = 1$. Analyze the time and space requirements of your algorithm. 

>[!Note] Section 1.5.2
>$\binom{n}{m}=\binom{n-1}{m-1}+\binom{n-1}{m}$

It'll produce $\binom{n}{m}$ leaf nodes and $\binom{n}{m}$ - 1 inner nodes.
Time complexity  : O($2^n$)
Space complexity : O($n$)

```C
ull binomial(ull n, ull m){
    if(n < m) return 0;
    if(m == n || m == 0) return 1;
    return binomial(n - 1, m - 1) + binomial(n - 1, m);
}
```

### 1-5-10
---
> Ackermann's function $A(m,n)$ is defined as follows:
 >$$
A(m, n)=
\begin{cases}
	n + 1 & \text{ if } m = 0\\
	A(m-1,1) & \text{ if } n = 0\\
	A(m-1, A(m,n-1)) & \text{ if } m > 0 \text{ and } n > 0
\end{cases}
$$
>This function is studied because it grows very fast for small values of $m$ and $n$. Write a recursive function for computing this function. Then write a non-recursive algorithm for computing Ackermann's function.

Recursive Form:
```C
ull A(ull m, ull n){
    if(m == 0) return n + 1;
    else if(n == 0) return A(m - 1, 1);
    else return A(m - 1, A(m, n - 1));
}
```

Iteration Form:
```C
typedef struct stack{
        ull m;
        struct stack *next;
}stack;

bool push(stack** top, ull m){
    stack *temp = malloc(sizeof(stack));
    if(temp == NULL) return false;
    temp->m = m;
    temp->next = *top;
    *top = temp;
    return true;
}

bool pop(stack** top, ull* m){
    if(*top == NULL) return false;
    stack *temp = *top;
    *m = temp->m;
    *top = (*top)->next;
    free(temp);
    return true;
}

void clean(stack **stk){
    ull a;
    while((*stk) != NULL)
        pop(stk, &a);
    *stk = NULL;
}

ull A(ull m, ull n){
    stack *stk = NULL;
    push(&stk, m);
    while(stk != NULL){
            pop(&stk, &m);
        if(m == 0)
            n++;
        else if(n == 0){
            push(&stk, m - 1);
            n = 1;
        }
        else{
            push(&stk, m - 1);
            push(&stk, m);
            n--;
        }
    }
    return n;
}
```

### 1-5-15
---
>**\[Towers of Hanoi\]** There are three towers and sixty-four disks of different diameters placed on the first tower. The disks are in order of decreasing diameter as one scans up the tower. Monk were supposed to move the disks from tower 1 to tower 3 obeying the following rules: (a) only one disk can be moved at any time and (b) no disk can be placed on top of disk with smaller diameter. Write a recursive function that prints the sequence of moves that accomplish this task.

execute `Hanoi(64, 'A', 'B', 'C');` in `main()`

```C
void Hanoi(int n, char a, char b, char c){
    if(n <= 0) return;
    Hanoi(n - 1, a, c, b);
    printf("Move disk %d from %c to %c\n", n, a, c);
    Hanoi(n - 1, b, a, c);
}
```

### 1-7-2(b)
---
> Prove by induction:
>  $\sum_{1 \leq i \leq n}i^2 = \frac{n(n+1)(2n+1)}{6}$

**when** $i = 1$:
    left   = $1^2$ = 1
    right = $\frac{1\cdot(1 + 1)\cdot(2 \cdot 1 + 1)}{6}$ = 1
	$left = right = 1$, formula is correct at $i = 1$
**assume** $i = k$ makes $left = right$, for k under $[1, n)$:
    left   = $\sum^k_{i=1}i^2$
    right = $\frac{k \cdot (k + 1) \cdot (2k + 1)}{6}$ = $\frac{2k^3+3k^2+k}{6}$
**when** $i = k + 1$:
    left   = $\sum^{k+1}_{i=1}i^2$ = $\sum^k_{i=1}i^2$ + $(k + 1)^2$ = $\sum^k_{i=1}i^2$ + $k^2 + 2k + 1$
	right = $\frac{(k + 1) \cdot (k + 2) \cdot (2 \cdot (k + 1) + 1)}{6}$ = $\frac{2k^3+9k^2+13k+6}{6}$ = $\frac{2k^3+3k^2+k}{6} + (k^2+2k+1)$
	=> left = right
Thus, mathematical induction proves.

### 1-7-3(a)
---
>Determine the frequency counts for all statements in the following two program segments:
> 
> for(i = 1 ; i <= n ; i++)
> 	for(j = 1 ; j <= i ; j++)
> 		for(k = 1 ; k <= j ; k++)
> 			x++;

$\sum_{i=1}^n\frac{i(i+1)}{2} = \frac{1}{2}\sum_{i=1}^ni^2+\frac{1}{2}\sum_{i=1}^ni$
=> x += $\frac{n(n+1)(n+2)}{6}$


### 1-7-8(h)
---
>$\frac{6n^3}{\log{n}+1} = O(n^3)$

True, precisely for big-Oh is $O(\frac{n^3}{\log{n}})$

### 1-7-9(a)
---
>$10n^2+9=O(n)$

Incorrect, correct form is $O(n^2)$
