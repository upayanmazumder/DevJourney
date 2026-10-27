# Priority Scheduling (Preemptive)

At each time unit, run the arrived process with the highest priority value. A higher priority process preempts the current one.

```mermaid
flowchart TD
    A([Start]) --> B[/"Read n, PID, AT, BT, priority"/]
    B --> C{"completed < n?"}
    C -- Yes --> D["Pick arrived process with highest priority"]
    D --> E{"Process found?"}
    E -- No --> F["IDLE, time++"]
    F --> C
    E -- Yes --> G["Run 1 unit, remaining--, time++"]
    G --> H{"remaining == 0?"}
    H -- Yes --> I["CT = time, completed++"]
    H -- No --> C
    I --> C
    C -- No --> J["Compute TAT, WT, print table"]
    J --> K([End])
```
