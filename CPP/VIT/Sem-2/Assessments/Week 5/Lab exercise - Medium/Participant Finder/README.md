# Single File Programming Question

## Problem Statement

An event management company wants to keep track of the participants attending their events. They need a program that allows them to input participant details and search for a specific participant based on their ID. Additionally, the program should keep track of the total number of participants registered.

You are tasked with implementing a program that uses the Event class to manage participant information. The class should have:

A static member variable totalParticipants to store the total number of participants.
A member function setParticipant to set the participant's ID (which should be unique) and name.
A member function getParticipantID to retrieve a participant's ID.
A member function display to print a participant's ID and name.
A static member function getTotalParticipants to return the total number of participants registered.

### Input format :

The first line contains an integer n, representing the number of participants.

The next n lines contain two inputs:

The first input is an integer participantID, which is the unique identifier for the participant.
The second input is a string participantName, which is the name of the participant.
The last line contains an integer searchID, representing the ID of the participant to search for.

### Output format :

If the participant with searchID is found, print "Participant found: " followed by the participant's ID and name.

If the participant is not found, print "Participant with ID searchID not found.".

Refer to the sample output for the formatting specifications.

### Code constraints :

1 ≤ n ≤ 25

1 ≤ participantID ≤ 105

### Sample test cases :

#### Input 1 :

3
1
John Doe
2
Jane Smith
3
Alex Johnson
2

#### Output 1 :

Participant found: Participant ID: 2, Name: Jane Smith

#### Input 2 :

5
101
Alice
102
Bob
103
Charlie
104
David
105
Eve
106

#### Output 2 :

Participant with ID 106 not found.
