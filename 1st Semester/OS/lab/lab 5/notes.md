# Job Scheduling Algorithms <!-- omit in toc -->

---

# Contents <!-- omit in toc -->

- [First Come First Serve](#first-come-first-serve)

---

## First Come First Serve

- To Find Waiting Time

| $P_{id}$ | Bus Time (BT) | Arrival Time (AT) | Waiting Time (WT) |  Turn Around Time (TAT = BT + WT)  |
| :------: | :------: | :----------: | :----------: | :---: |
| P1 | 24 | 0 | | |
| P2 | 3 | 1 | | |
| P3 | 3 | 2 | | |

- Primitive : Changing of the time schedules according to the priorities of jobs
- Non-primitive : No matter the priority execution order will not change

Accept process ids from user
Take AT as 0
