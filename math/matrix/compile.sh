clang -O3 -march=native -ftree-vectorize -Rpass=loop-vectorize -Rpass-missed=loop-vectorize -Rpass-analysis=loop-vectorize main.c -o matrix

# Options Explanation:
#  General options
#	•	-O3: Enables aggressive optimizations including vectorization.
#	•	-march=native: Generates code optimized for your current CPU, including vector instructions (like AVX or SSE).
#	•	-ftree-vectorize: Explicitly enables vectorization (enabled by default at -O3).
#  clang options:
#	•	-Rpass=loop-vectorize: shows successful vectorizations.
#	•	-Rpass-missed=loop-vectorize: shows missed opportunities.
#	•	-Rpass-analysis=loop-vectorize: explains why it did/didn’t vectorize.
#  gcc options:
#	•	-fopt-info-vec: Shows what loops were vectorized (use -fopt-info-vec-optimized for successful ones only).

