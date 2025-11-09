# Game Character

## Single File Programming Question

## Problem Statement

Jessica is designing a fantasy game character system. The system includes an abstract class GameCharacter with two abstract methods: attack(int attributeValue) and defend(int defense).

Two subclasses extend GameCharacter:

Warrior implements attack(int strength), where attack damage = strength × 3, and defend(int defense), which boosts defense.
Wizard implements attack(int magicPower), where magic damage = magicPower × 2, and defend(int defense), which creates a magical barrier.

The program prompts the player to:

Choose a character type: 1 for Warrior or 2 for Wizard.

#### Input:

```
an integer representing either strength (for Warrior) or magic power (for Wizard).
```

The program dynamically instantiates the chosen character, execute the attack and defend actions, and display the corresponding messages.
#### Input:

```
format :
```

The first line of input consists of an integer, representing the choice of the character - 1 for Warrior and 2 for Wizard.

If the choice is 1, the second line consists of an integer N, representing the strength.

If the choice is 2, the second line consists of an integer M, representing the magic power.

#### Output:

```
format :
```

If the choice is 1, prints the actions of a warrior in the following format:

"Warrior Actions:

Attack: Powerful sword slash for [result] damage!

Defend: Raises shield, defence boosted by [N]!"

If the choice is 2, prints the actions of a wizard in the following format:

"Wizard Actions:

Attack: Casts spell, deals [result] magical damage!

Defend: Creates magical barrier, defence boosted by [M]!"

If any other choice is given, print "Invalid choice".

Refer to the sample output for the formatting specifications.

Code constraints :
1 ≤ M, N ≤ 107

Sample test cases :
#### Input 1:

```
1
68
Output 1 :
Warrior Actions:
Attack: Powerful sword slash for 204 damage!
Defend: Raises shield, defence boosted by 68!
Input 2 :
2
998
Output 2 :
Wizard Actions:
Attack: Casts spell, deals 1996 magical damage!
Defend: Creates magical barrier, defence boosted by 998!
Input 3 :
3
76
Output 3 :
Invalid choice
```
