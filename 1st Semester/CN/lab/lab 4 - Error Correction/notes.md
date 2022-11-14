# Error Correction <!-- omit in toc -->

---

# Contents <!-- omit in toc -->

- [Hamming Code Algorithm](#hamming-code-algorithm)
- [CRC - Error Detection](#crc---error-detection)
  - [Given](#given)
  - [Calculate](#calculate)
  - [Receiver](#receiver)

---

## Hamming Code Algorithm

- Used to transfer data bits

1001  $\rarr$ Data Bits

$2^r \ge$ m + r + 1 $\rarr$ number of data bits to be added to data for encoding of the data

Parity bits $\rarr P_1, P_2$

| Decimal | Binary                    |
| :-----: | :------------------------ |
|    1    | 001 $\rarr P_1$           |
|    2    | 010 $\rarr P_2$           |
|    3    | 011 $\rarr P_1, P_2$      |
|    4    | 100  $\rarr P_4$          |
|    5    | 101  $\rarr P_1, P_4$     |
|    6    | 110  $\rarr P_2, P_4$     |
|    7    | 111 $\rarr P_1, P_2, P_4$ |

$P_1 = 1, 3, 5, 7$
$P_2 = 2, 3, 6, 7$
$P_4 = 4, 5, 6, 7$

| Position  | Parity Bit |
| :-------: | :--------: |
| $2^0 = 1$ |     P1     |
| $2^1 = 2$ |     P2     |
| $2^2 = 4$ |     P4     |

|   7   |   6   |   5   |   4   |   3   |   2   |   1   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   1   |   0   |   0   | $P_4$ |   1   | $P_2$ | $P_1$ |

Even Parity Encoding $\rArr$ Make the parity bit zero if even number of 1's

$P_1 = P_1 101 \rArr 0$

|   7   |   6   |   5   |   4   |   3   |   2   |   1   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   1   |  --   |   0   |  --   |   1   |  --   | $P_1$ |

$P_2 = P_2 101 \rArr 0$

|   7   |   6   |   5   |   4   |   3   |   2   |   1   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
|   1   |   0   |   0   | $P_4$ |  --   |  --   |  --   |

$P_4 = P_4 100 \rArr 1$

Encoded Data

|   7   |   6   |   5   |          4           |   3   |          2           |          1           |
| :---: | :---: | :---: | :------------------: | :---: | :------------------: | :------------------: |
|   1   |   0   |   0   | $\textcolor{red}{1}$ |   1   | $\textcolor{red}{0}$ | $\textcolor{red}{0}$ |

## CRC - Error Detection

- Detects the error but does not know where the error is
- It cannot correct the error

### Given

1. CRC Generator $\rArr$ 101101
2. Divisor $\rArr$ 1101

### Calculate

$CRC_{Bits} = Divisor_{Bits} - 1 = 3$

Thus, that many number of bits are added to the end of the CRC Generator

Now perform binary division using XOR operations

$\begin{aligned}
    1101 &| 101101\textcolor{red}{000}\\
    -    &| 1101\downarrow\\
         &| \cancel{0}1100\downarrow\downarrow\downarrow\\
         &| 1100\downarrow\downarrow\downarrow\\
    -    &| 1101\\
         &| \cancel{000}1100\\
         &| 1100\\
    -    &| 1101\\
    -    &| 00\textcolor{blue}{010}\\
\end{aligned}$

Thus Encoded Data becomes $\rArr 101101\textcolor{blue}{010}$

### Receiver

If after the division the receiver has the remainder as zero then the message does not have any error

$\begin{aligned}
    1101 &| 101101010\\
    -    &| 1101\\
         &| \cancel{0}110\downarrow\\
         &| 1100\\
    -    &| 1101\\
         &| \cancel{000}1\downarrow\downarrow\downarrow\\
         &| 1101\\
    -    &| 1101\\
         &| \cancel{0000}\downarrow\\
         &| 0\\
\end{aligned}$
