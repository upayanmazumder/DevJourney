# Operating Systems Lab Assessment 10: SRTF Scheduling

Shortest Remaining Time First (SRTF) CPU scheduling implementation in Linux C with dynamic user input.

Student Details:

- Name: Upayan Mazumder
- Registration Number: 24BDS0367

## Problem Statement

Create a LINUX C program to implement the Shortest Remaining Time First (SRTF) Scheduling Algorithm. Processes will be scheduled based on their arrival and burst time. Print the average turnaround time and average waiting time.

## Given Data

- Process P1: Burst Time = 6, Arrival Time = 2
- Process P2: Burst Time = 2, Arrival Time = 5
- Process P3: Burst Time = 8, Arrival Time = 1
- Process P4: Burst Time = 3, Arrival Time = 0
- Process P5: Burst Time = 4, Arrival Time = 4

## Execution and Build

```bash
gcc main.c -o srtf.o
./srtf.o
```

## Output Results

- Process P1: Arrival = 2, Burst = 6, Completion = 15, Turnaround = 13, Waiting = 7
- Process P2: Arrival = 5, Burst = 2, Completion = 7, Turnaround = 2, Waiting = 0
- Process P3: Arrival = 1, Burst = 8, Completion = 23, Turnaround = 22, Waiting = 14
- Process P4: Arrival = 0, Burst = 3, Completion = 3, Turnaround = 3, Waiting = 0
- Process P5: Arrival = 4, Burst = 4, Completion = 10, Turnaround = 6, Waiting = 2

- Average Turnaround Time: 9.20
- Average Waiting Time: 4.60

## Files

- main.c: Clean C source code without comments taking dynamic input.
- output-screenshot.png: Single workspace screenshot showing source code and execution output side by side.
- Assessment 10 - Upayan Mazumder - 24BDS0367.pdf: Generated assessment report document.
