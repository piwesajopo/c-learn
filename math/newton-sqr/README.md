# Finding Square Root Using Newton's Method

This program uses the Newton-Raphson method to aproximate the square root of a number: 

$$
guess_{n+1} = \frac{guess_n + \frac{x}{guess_n}}{2}
$$

Where:

* $x$ is the number whose square root is being calculated.
* $guess_n$ is the current approximation (guess) at iteration $n$.
* $guess_{n+1}$ is the next approximation, which gets closer to $\sqrt{x}$.

This formula is applied iteratively until $guess_n$ converges to $\sqrt{x}$, typically when $|guess_n^2 - x|$ is smaller than a chosen precision threshold (e.g., $\epsilon = 0.000001$).
