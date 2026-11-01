# FIFO Page Replacement

Replace the page that entered memory first.

```mermaid
flowchart TD
    A([Start]) --> B[/"Read page references and frame count"/]
    B --> C{"Next page?"}
    C -- Yes --> D{"Page in a frame?"}
    D -- Yes --> E["Hit++"]
    D -- No --> F["Fault++"]
    F --> G{"Free frame?"}
    G -- Yes --> H["Use the free frame"]
    G -- No --> I["Replace the oldest page"]
    H --> J["Load page, print frames"]
    I --> J
    E --> J
    J --> C
    C -- No --> K["Print faults and hits"]
    K --> L([End])
```
