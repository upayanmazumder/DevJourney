# Single File Programming Question

## Problem Statement

Ragul is the head of the UPSC (Union Public Service Commission) and he needs to schedule interviews for candidates applying for various government positions. The interview slots are divided into three available time slots: Slot A, Slot B, and Slot C. Additionally, each candidate can provide a preferred slot.

Implement a program that takes candidate details and schedules their interviews based on the given constraints.

Create a class called UPSCInterviewScheduler that will manage the interview scheduling process. This class will have the following methods and functionalities:

In the UPSCInterviewScheduler class, implement function overloading for the printSlot method. Create two versions of the method:

printSlot(const string& slot, const string& preferredSlot): This version of the method will be used to print the assigned slots as described above.

printSlot(const string& slot): This version of the method will be used to print a regular slot without considering the preferred slot.

### Input format :

For each candidate, The input consists of the following format:

Three available interview slots (slot1, slot2, slot3), each as a string.

The candidate's preferred slot (preferredSlot), a string.

Refer to the sample input for the formatting specifications.

### Output format :

The output displays the following format:

For each candidate, the program should output the assigned slots as follows:

If a slot is the preferred slot, it should be marked as "Preferred."

If a slot is not the preferred slot, it should be marked as a regular slot.

Refer to the sample output for the formatting specifications.

### Code constraints :

The program should be able to handle at least two candidates.

The interview slots are case-sensitive.

### Sample test cases :

#### Input 1 :

08:30AM 09:30AM 10:30AM
09:30AM
02:00PM 03:00PM 04:00PM
none

#### Output 1 :

Candidate 1:

- 08:30AM
- 09:30AM (Preferred)
- 10:30AM

Candidate 2:

- 02:00PM
- 03:00PM
- 04:00PM
