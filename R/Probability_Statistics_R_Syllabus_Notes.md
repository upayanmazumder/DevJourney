# Probability & Statistics with R - Complete Syllabus Notes (Basic to Advanced)

These notes are designed for your R-based Probability and Statistics syllabus and match the topics visible in your assessments.

## 0) Fast roadmap

1. Data basics and descriptive statistics
2. Probability fundamentals and random variables
3. Important distributions and R functions
4. Sampling distributions + CLT
5. Estimation and confidence intervals
6. Hypothesis testing (Z, t, two-sample, paired)
7. Chi-square tests (independence, goodness of fit)
8. ANOVA (one-way, randomized block, Latin square)
9. Decision guide: which test to use
10. Common mistakes and interpretation tips

---

## 1) Data basics and descriptive statistics

### 1.1 Data types
- Qualitative (categorical): gender, flavor, training program
- Quantitative discrete: number of defects, number of successes
- Quantitative continuous: height, weight, time, marks

### 1.2 Core summaries
For observations $x_1, x_2, ..., x_n$:

- Mean:
$$
\bar{x} = \frac{1}{n}\sum_{i=1}^{n} x_i
$$

- Sample variance:
$$
s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(x_i - \bar{x})^2
$$

- Sample standard deviation:
$$
s = \sqrt{s^2}
$$

- Coefficient of variation:
$$
CV = \frac{s}{\bar{x}} \times 100\%
$$

### 1.3 R code template
```r
# x is numeric vector
x <- c(10, 12, 15, 9, 14)

length(x)
mean(x)
median(x)
var(x)
sd(x)
IQR(x)
summary(x)

# frequency table for categorical data
major <- c("CSE", "ECE", "CSE", "ME", "ECE")
table(major)
prop.table(table(major))

# quick plots
hist(x, main = "Histogram", xlab = "x")
boxplot(x, main = "Boxplot")
barplot(table(major), main = "Category counts")
```

---

## 2) Probability fundamentals

### 2.1 Basic rules
- $0 \le P(A) \le 1$
- $P(S)=1$, $P(\emptyset)=0$
- Complement: $P(A^c)=1-P(A)$
- Addition rule:
$$
P(A \cup B)=P(A)+P(B)-P(A\cap B)
$$

- Conditional probability:
$$
P(A\mid B)=\frac{P(A\cap B)}{P(B)}, \quad P(B)>0
$$

- Multiplication rule:
$$
P(A\cap B)=P(A\mid B)P(B)
$$

- Independence: $A,B$ independent if
$$
P(A\cap B)=P(A)P(B)
$$

- Bayes theorem:
$$
P(A_i\mid B)=\frac{P(B\mid A_i)P(A_i)}{\sum_j P(B\mid A_j)P(A_j)}
$$

### 2.2 Random variables
- Discrete RV: PMF $p(x)=P(X=x)$
- Continuous RV: PDF $f(x)$, with $P(a\le X\le b)=\int_a^b f(x)\,dx$
- CDF: $F(x)=P(X\le x)$

### 2.3 Expectation and variance
- Discrete:
$$
E(X)=\sum x p(x), \quad Var(X)=E(X^2)-[E(X)]^2
$$

- Linear transform $Y=aX+b$:
$$
E(Y)=aE(X)+b, \quad Var(Y)=a^2Var(X)
$$

---

## 3) Important distributions + R commands

R naming pattern:
- `d...` density/pmf
- `p...` cumulative probability
- `q...` quantile
- `r...` random generation

### 3.1 Binomial: $X\sim Bin(n,p)$
- PMF:
$$
P(X=x)=\binom{n}{x}p^x(1-p)^{n-x}, \quad x=0,1,...,n
$$
- Mean $np$, variance $np(1-p)$

```r
# P(X = 3) when n=10, p=0.2
dbinom(3, size = 10, prob = 0.2)

# P(X <= 3)
pbinom(3, size = 10, prob = 0.2)

# Simulate
rbinom(100, size = 10, prob = 0.2)
```

### 3.2 Poisson: $X\sim Pois(\lambda)$
- PMF:
$$
P(X=x)=e^{-\lambda}\frac{\lambda^x}{x!}
$$
- Mean = variance = $\lambda$

```r
dpois(4, lambda = 2.5)
ppois(4, lambda = 2.5)
rpois(100, lambda = 2.5)
```

### 3.3 Normal: $X\sim N(\mu,\sigma^2)$
- Standardization:
$$
Z=\frac{X-\mu}{\sigma}
$$

```r
# P(X <= 68) for N(65, 3^2)
pnorm(68, mean = 65, sd = 3)

# x such that P(X <= x)=0.95
qnorm(0.95, mean = 65, sd = 3)

# Generate values
rnorm(100, mean = 65, sd = 3)
```

### 3.4 t distribution
Used when population sigma unknown (especially small samples).

```r
# CDF and quantile
t_prob <- pt(2.1, df = 14)
t_crit <- qt(0.975, df = 14)
```

### 3.5 Chi-square distribution
If $Z_i\sim N(0,1)$ independent, then
$$
\chi^2 = \sum_{i=1}^{k} Z_i^2 \sim \chi_k^2
$$

```r
pchisq(10.2, df = 6)
qchisq(0.95, df = 6)
```

### 3.6 F distribution
Ratio of scaled chi-square variables; appears in ANOVA.

```r
pf(3.2, df1 = 2, df2 = 18)
qf(0.95, df1 = 2, df2 = 18)
```

---

## 4) Sampling distributions and CLT

### 4.1 Mean of sample mean
If population mean is $\mu$ and variance is $\sigma^2$:
$$
E(\bar{X})=\mu, \quad Var(\bar{X})=\frac{\sigma^2}{n}
$$

Standard error:
$$
SE(\bar{X})=\frac{\sigma}{\sqrt{n}} \quad (\text{or } s/\sqrt{n})
$$

### 4.2 Central Limit Theorem (CLT)
For large $n$, sample mean is approximately normal:
$$
\bar{X} \approx N\left(\mu, \frac{\sigma^2}{n}\right)
$$

Useful for problems like: $P(a < \bar{X} < b)$, $P(\bar{X}>c)$ in your assessments.

```r
# Example: P(160 < Xbar < 165), mu=162, sigma=12, n=36
mu <- 162
sigma <- 12
n <- 36
se <- sigma / sqrt(n)
pnorm(165, mu, se) - pnorm(160, mu, se)
```

---

## 5) Estimation and confidence intervals

### 5.1 CI for mean (sigma known)
$$
\bar{x} \pm z_{\alpha/2}\frac{\sigma}{\sqrt{n}}
$$

### 5.2 CI for mean (sigma unknown)
$$
\bar{x} \pm t_{\alpha/2, n-1}\frac{s}{\sqrt{n}}
$$

### 5.3 CI for difference of means
- Known sigmas / large-sample Z:
$$
(\bar{x}_1-\bar{x}_2) \pm z_{\alpha/2}\sqrt{\frac{\sigma_1^2}{n_1}+\frac{\sigma_2^2}{n_2}}
$$

- Unknown unequal variances: Welch t interval (`t.test(..., var.equal=FALSE)`)

```r
# One-sample t CI
x <- c(10, 11, 9, 13, 12, 10)
t.test(x, conf.level = 0.95)

# Two-sample Welch CI
a <- c(56, 60, 58, 61, 57)
b <- c(52, 49, 55, 50, 53)
t.test(a, b, var.equal = FALSE, conf.level = 0.95)
```

---

## 6) Hypothesis testing

General steps:
1. Define $H_0$ and $H_1$
2. Choose significance level $\alpha$ (commonly 0.05)
3. Compute test statistic
4. Obtain p-value or critical-value decision
5. Conclude in context

### 6.1 One-sample Z test (large sample or known sigma)
$$
Z = \frac{\bar{X} - \mu_0}{\sigma/\sqrt{n}}
$$

```r
# Manual Z test
xbar <- 815
mu0 <- 800
sigma <- 90
n <- 64
z <- (xbar - mu0) / (sigma / sqrt(n))
p_value_right <- 1 - pnorm(z)
z; p_value_right
```

### 6.2 One-sample t test
$$
t = \frac{\bar{X} - \mu_0}{s/\sqrt{n}}, \quad df=n-1
$$

```r
x <- c(48, 52, 50, 47, 51, 49, 53)
t.test(x, mu = 50, alternative = "two.sided")
```

### 6.3 Two-sample Z test (known sigmas)
$$
Z = \frac{(\bar{X}_1-\bar{X}_2)-\Delta_0}{\sqrt{\sigma_1^2/n_1 + \sigma_2^2/n_2}}
$$

```r
xbar1 <- 72; xbar2 <- 68
sigma1 <- 10; sigma2 <- 12
n1 <- 40; n2 <- 36
delta0 <- 0
z <- ((xbar1 - xbar2) - delta0) / sqrt(sigma1^2/n1 + sigma2^2/n2)
p_two <- 2 * (1 - pnorm(abs(z)))
z; p_two
```

### 6.4 Two-sample t test (unknown variances)
- Welch default in R:
```r
t.test(group1, group2, var.equal = FALSE)
```
- Equal variances assumed (pooled):
```r
t.test(group1, group2, var.equal = TRUE)
```

### 6.5 Paired t test
For paired differences $d_i = x_i - y_i$:
$$
t = \frac{\bar{d}}{s_d/\sqrt{n}}, \quad df=n-1
$$

```r
before <- c(95, 102, 98, 100, 97)
after  <- c(99, 105, 100, 103, 101)
t.test(after, before, paired = TRUE, alternative = "greater")
```

### 6.6 Type I and Type II errors
- Type I: reject true $H_0$ (probability = $\alpha$)
- Type II: fail to reject false $H_0$ (probability = $\beta$)
- Power = $1-\beta$

---

## 7) Chi-square methods

### 7.1 Chi-square test of independence (contingency table)
Used for association between two categorical variables.

$$
\chi^2 = \sum \frac{(O_{ij}-E_{ij})^2}{E_{ij}}, \quad E_{ij}=\frac{(\text{row total})(\text{col total})}{N}
$$

Degrees of freedom:
$$
(r-1)(c-1)
$$

```r
tbl <- matrix(c(20, 30, 25, 35), nrow = 2, byrow = TRUE)
chisq.test(tbl, correct = FALSE)
```

### 7.2 Goodness-of-fit (GOF)
Check whether observed counts follow a specified distribution.

$$
\chi^2 = \sum \frac{(O_i - E_i)^2}{E_i}
$$

```r
obs <- c(18, 32, 30, 20)
# expected probabilities (must sum to 1)
p <- c(0.2, 0.3, 0.3, 0.2)
chisq.test(obs, p = p)
```

### 7.3 Fitting binomial then GOF
For grouped counts over x=0,1,...,n:
1. Estimate $\hat p = \frac{\sum x f_x}{n\sum f_x}$
2. Compute expected counts: $E_x = N\cdot P(X=x; n,\hat p)$
3. Run chi-square GOF (pool tiny expected counts if needed)

```r
x <- 0:4
f <- c(8, 22, 30, 25, 15)  # observed frequencies
N <- sum(f)
n <- 4
p_hat <- sum(x * f) / (n * N)
exp_counts <- N * dbinom(x, size = n, prob = p_hat)

# Manual chi-square statistic
chi_sq <- sum((f - exp_counts)^2 / exp_counts)
chi_sq

# Approximate p-value with df = k - 1 - m
# k = number of categories, m = parameters estimated (here m=1 for p)
df <- length(x) - 1 - 1
p_value <- 1 - pchisq(chi_sq, df = df)
p_value
```

---

## 8) ANOVA and experimental designs

### 8.1 Why ANOVA
Use when comparing 3 or more means without doing many t-tests.

Hypotheses:
- $H_0$: all group means equal
- $H_1$: at least one mean differs

F statistic:
$$
F = \frac{MS_{between}}{MS_{within}}
$$

### 8.2 One-way ANOVA
Model:
$$
Y_{ij} = \mu + \tau_i + \epsilon_{ij}
$$

Assumptions:
- independent observations
- normal residuals
- equal variances

```r
# df has columns: score, group
fit <- aov(score ~ group, data = df)
summary(fit)

# Diagnostics
par(mfrow = c(2,2))
plot(fit)

# Post-hoc if significant
TukeyHSD(fit)
```

### 8.3 Randomized block / two-factor additive model
Used when one nuisance factor (block/machine/day) should be controlled.

Model:
$$
Y_{ij} = \mu + \tau_i + \beta_j + \epsilon_{ij}
$$

```r
# Example with treatment and block
fit_block <- aov(response ~ treatment + block, data = df)
summary(fit_block)
```

### 8.4 Latin Square Design (LSD)
Controls two blocking factors (rows and columns) plus treatment.

Model:
$$
Y_{ijk} = \mu + \tau_i + \rho_j + \kappa_k + \epsilon_{ijk}
$$

```r
# Columns: yield, treatment, row, col
fit_lsd <- aov(yield ~ treatment + row + col, data = df)
summary(fit_lsd)
```

### 8.5 Interpreting ANOVA output
- If `Pr(>F) < alpha`: reject $H_0$ for that factor
- Report in context: "There is significant evidence that mean output differs by machine."

---

## 9) Practical R workflow for exam problems

### 9.1 Reusable function for quick summary
```r
quick_stats <- function(x) {
  c(
    n = length(x),
    mean = mean(x),
    sd = sd(x),
    var = var(x),
    min = min(x),
    q1 = quantile(x, 0.25),
    median = median(x),
    q3 = quantile(x, 0.75),
    max = max(x)
  )
}
```

### 9.2 p-value to decision helper
```r
decide <- function(p, alpha = 0.05) {
  if (p < alpha) "Reject H0" else "Fail to reject H0"
}
```

### 9.3 Normality and variance checks
```r
# For ANOVA / t assumptions
shapiro.test(residuals(fit))

# Equal variances across groups (base R)
bartlett.test(score ~ group, data = df)
```

---

## 10) Which test should I use? (decision guide)

1. One sample mean vs target:
- sigma known / large n: one-sample Z
- sigma unknown: one-sample t

2. Two independent means:
- sigmas known: two-sample Z
- unknown sigmas: Welch t (default)

3. Same subjects before-after:
- paired t-test

4. Two categorical variables association:
- chi-square independence

5. Observed counts vs theoretical distribution:
- chi-square GOF

6. Compare 3+ group means:
- one-way ANOVA

7. Compare treatments with one block factor:
- randomized block ANOVA

8. Treatments with two block factors:
- Latin square ANOVA

---

## 11) Common mistakes to avoid

- Mixing up independent and paired tests
- Using Z test when sigma is unknown and sample is small
- Ignoring one-sided vs two-sided alternative
- Declaring "accept H0" (better: "fail to reject H0")
- Running many t-tests instead of ANOVA for 3+ groups
- Not checking expected counts for chi-square tests
- Forgetting to interpret results in domain context

---

## 12) High-yield exam templates

### Template A: One-sample Z test
```r
xbar <- 0; mu0 <- 0; sigma <- 1; n <- 1
z <- (xbar - mu0) / (sigma / sqrt(n))
p <- 2 * (1 - pnorm(abs(z)))
list(z = z, p_value = p)
```

### Template B: Two-sample t test (Welch)
```r
t.test(x, y, alternative = "two.sided", var.equal = FALSE, conf.level = 0.95)
```

### Template C: Paired t test
```r
t.test(after, before, paired = TRUE, alternative = "greater")
```

### Template D: Chi-square independence
```r
tab <- table(df$A, df$B)
chisq.test(tab, correct = FALSE)
```

### Template E: One-way ANOVA + Tukey
```r
fit <- aov(y ~ grp, data = df)
summary(fit)
TukeyHSD(fit)
```

### Template F: Block + treatment ANOVA
```r
fit <- aov(y ~ treatment + block, data = df)
summary(fit)
```

### Template G: Latin square
```r
fit <- aov(y ~ treatment + row + col, data = df)
summary(fit)
```

---

## 13) Final revision checklist

1. Can you identify variable type and suitable test quickly?
2. Can you write $H_0$, $H_1$ correctly (with direction)?
3. Do you know the exact R command and main output line to report?
4. Can you interpret p-value in one sentence with context?
5. Can you state assumptions and whether they are reasonable?

If you can do these five consistently, you are exam-ready for most Prob-Stats practical questions in R.

---

## 14) Topic-wise practice questions with answers (easy to advanced)

Use these as self-tests. Try each question first, then compare with the answer.

### 14.1 Descriptive statistics and data handling

Easy Q1:
Given `x <- c(5, 7, 7, 9, 12)`, find mean and median.

Answer:
- Mean = $(5+7+7+9+12)/5 = 8$
- Median = 7

R check:
```r
x <- c(5, 7, 7, 9, 12)
mean(x)
median(x)
```

Medium Q2:
For `x <- c(10, 12, 8, 9, 11, 10)`, find sample variance and SD.

Answer:
- Use $s^2 = \frac{1}{n-1}\sum (x_i-\bar{x})^2$
- Numerically: $s^2 = 2$, so $s = \sqrt{2} \approx 1.414$

R check:
```r
x <- c(10, 12, 8, 9, 11, 10)
var(x)
sd(x)
```

Advanced Q3:
Create a summary table for a student score vector containing n, mean, sd, min, Q1, median, Q3, max.

Answer:
```r
scores <- c(68, 72, 75, 80, 81, 85, 90, 92)
c(
  n = length(scores),
  mean = mean(scores),
  sd = sd(scores),
  min = min(scores),
  q1 = quantile(scores, 0.25),
  median = median(scores),
  q3 = quantile(scores, 0.75),
  max = max(scores)
)
```

### 14.2 Probability fundamentals

Easy Q1:
If $P(A)=0.4$, find $P(A^c)$.

Answer:
- $P(A^c)=1-0.4=0.6$

Medium Q2:
If $P(A)=0.5$, $P(B)=0.6$, and $P(A\cap B)=0.3$, find $P(A\cup B)$.

Answer:
- $P(A\cup B)=P(A)+P(B)-P(A\cap B)=0.5+0.6-0.3=0.8$

Advanced Q3 (Bayes):
A machine comes from Plant 1 (60%) or Plant 2 (40%). Defect rates are 2% and 5% respectively. If an item is defective, find probability it came from Plant 2.

Answer:
$$
P(P2\mid D)=\frac{P(D\mid P2)P(P2)}{P(D\mid P1)P(P1)+P(D\mid P2)P(P2)}
=\frac{0.05\cdot0.4}{0.02\cdot0.6+0.05\cdot0.4}
=\frac{0.02}{0.032}=0.625
$$

### 14.3 Distributions

Easy Q1 (Binomial):
For $X\sim Bin(5, 0.2)$, find $P(X=1)$.

Answer:
$$
P(X=1)=\binom{5}{1}(0.2)^1(0.8)^4=0.4096
$$

R check:
```r
dbinom(1, size = 5, prob = 0.2)
```

Medium Q2 (Poisson):
If $X\sim Pois(3)$, find $P(X\le2)$.

Answer:
```r
ppois(2, lambda = 3)
```

Advanced Q3 (Normal):
If $X\sim N(70, 8^2)$, find $P(65 < X < 82)$.

Answer:
```r
pnorm(82, mean = 70, sd = 8) - pnorm(65, mean = 70, sd = 8)
```

### 14.4 Sampling distribution and CLT

Easy Q1:
Population has $\mu=50$, $\sigma=10$, sample size $n=25$. Find standard error of $\bar{X}$.

Answer:
$$
SE=\frac{\sigma}{\sqrt{n}}=\frac{10}{5}=2
$$

Medium Q2:
With same parameters, find $P(\bar{X}>53)$.

Answer:
$$
Z=\frac{53-50}{2}=1.5,\quad P(\bar{X}>53)=1-\Phi(1.5)\approx0.0668
$$

R check:
```r
1 - pnorm(53, mean = 50, sd = 2)
```

Advanced Q3:
For $\mu=200$, $\sigma=30$, find n such that $SE\le 3$.

Answer:
$$
\frac{30}{\sqrt{n}}\le 3 \Rightarrow \sqrt{n}\ge10 \Rightarrow n\ge100
$$

### 14.5 Confidence intervals

Easy Q1:
Given $\bar{x}=40$, $\sigma=12$, $n=36$, 95% CI for mean.

Answer:
$$
40 \pm 1.96\cdot\frac{12}{6}=40\pm3.92=(36.08, 43.92)
$$

Medium Q2:
Sample `x <- c(21, 20, 19, 24, 22, 23, 20, 21)`; find 95% t-CI.

Answer:
```r
x <- c(21, 20, 19, 24, 22, 23, 20, 21)
t.test(x, conf.level = 0.95)$conf.int
```

Advanced Q3:
Interpret a 95% CI `(18.2, 22.4)`.

Answer:
- We are 95% confident that the true population mean lies between 18.2 and 22.4.
- Since it excludes 20? No, 20 is inside; so evidence is not strong against $\mu=20$ at 5% level.

### 14.6 Hypothesis testing (Z, t, paired)

Easy Q1 (one-sample t):
Test $H_0: \mu=50$ vs $H_1: \mu\ne50$ for `x <- c(49, 52, 47, 51, 50, 53, 48)` at $\alpha=0.05$.

Answer:
```r
x <- c(49, 52, 47, 51, 50, 53, 48)
t.test(x, mu = 50, alternative = "two.sided")
```
Decision rule: reject $H_0$ if p-value < 0.05.

Medium Q2 (two-sample Welch):
Compare two teaching methods:
`a <- c(72, 75, 78, 74, 77)`
`b <- c(69, 71, 73, 70, 72)`

Answer:
```r
a <- c(72, 75, 78, 74, 77)
b <- c(69, 71, 73, 70, 72)
t.test(a, b, var.equal = FALSE)
```

Advanced Q3 (paired):
Before and after training scores:
`before <- c(60, 62, 58, 65, 61, 59)`
`after <- c(64, 63, 61, 68, 65, 62)`
Test if training improved scores.

Answer:
```r
before <- c(60, 62, 58, 65, 61, 59)
after <- c(64, 63, 61, 68, 65, 62)
t.test(after, before, paired = TRUE, alternative = "greater")
```

### 14.7 Chi-square tests

Easy Q1 (independence):
Use table:
$$
\begin{bmatrix}
18 & 22\\
25 & 35
\end{bmatrix}
$$
Is there association?

Answer:
```r
tab <- matrix(c(18, 22, 25, 35), nrow = 2, byrow = TRUE)
chisq.test(tab, correct = FALSE)
```

Medium Q2 (GOF):
Observed counts: `c(30, 45, 25)`
Expected probabilities: `c(0.3, 0.4, 0.3)`

Answer:
```r
obs <- c(30, 45, 25)
chisq.test(obs, p = c(0.3, 0.4, 0.3))
```

Advanced Q3 (binomial fit + GOF):
Given counts for x=0..3 as `f <- c(12, 30, 38, 20)` where $n=3$ per trial, fit binomial and test GOF.

Answer:
```r
x <- 0:3
f <- c(12, 30, 38, 20)
N <- sum(f)
n <- 3
p_hat <- sum(x * f) / (n * N)
exp_counts <- N * dbinom(x, size = n, prob = p_hat)
chi_sq <- sum((f - exp_counts)^2 / exp_counts)
df <- length(x) - 1 - 1
p_value <- 1 - pchisq(chi_sq, df)
list(p_hat = p_hat, chi_sq = chi_sq, p_value = p_value)
```

### 14.8 ANOVA and design of experiments

Easy Q1 (one-way ANOVA):
Check if 3 machines have equal means.

Answer:
```r
df <- data.frame(
  y = c(21, 22, 20, 25, 24, 23, 28, 27, 29),
  machine = factor(rep(c("M1", "M2", "M3"), each = 3))
)
fit <- aov(y ~ machine, data = df)
summary(fit)
```

Medium Q2 (post-hoc):
After significant ANOVA, identify which pairs differ.

Answer:
```r
TukeyHSD(fit)
```

Advanced Q3 (block + treatment):
Analyze treatment effect controlling for block.

Answer:
```r
df2 <- data.frame(
  response = c(15, 18, 16, 17, 20, 19, 14, 16, 15, 18, 21, 19),
  treatment = factor(rep(c("T1", "T2", "T3"), times = 4)),
  block = factor(rep(c("B1", "B2", "B3", "B4"), each = 3))
)
fit_block <- aov(response ~ treatment + block, data = df2)
summary(fit_block)
```

Advanced Q4 (Latin square):
Fit a Latin square model with row and column blocks.

Answer:
```r
fit_lsd <- aov(yield ~ treatment + row + col, data = lsd_df)
summary(fit_lsd)
```

### 14.9 Mixed challenge set (exam-style)

Q1:
A sample of size 64 has mean 103. Population sigma is 16. Test $H_0: \mu=100$ vs $H_1: \mu>100$.

Answer:
$$
Z=\frac{103-100}{16/8}=1.5,\quad p=1-\Phi(1.5)\approx0.0668
$$
At $\alpha=0.05$: fail to reject $H_0$.

Q2:
You have before/after values on the same 12 people. Which test?

Answer:
- Paired t-test (`t.test(after, before, paired=TRUE)`).

Q3:
You have 4 training programs and want to compare mean output.

Answer:
- One-way ANOVA (`aov(output ~ program, data = df)`).

Q4:
Gender and flavor preference are both categorical. Which test?

Answer:
- Chi-square test of independence.

---

## 15) How to use this practice bank

1. Solve all easy questions first without seeing answers.
2. Move to medium only after scoring at least 80% on easy.
3. For advanced questions, write full interpretation sentence with p-value.
4. Re-run only incorrect questions after 24 hours (spaced revision).
5. Before exam, solve section 14.9 in one sitting under time limit.
