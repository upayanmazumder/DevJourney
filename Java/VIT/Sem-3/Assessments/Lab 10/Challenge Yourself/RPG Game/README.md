# RPG Game

## Single File Programming Question

## Problem Statement

Arjun is developing a role-playing game where players can create warrior characters with unique abilities. Each warrior inherits basic player attributes like name, health, and level, but also has additional combat-specific properties like strength and armor. The game needs to calculate various combat statistics including total attack power, critical hit damage, and damage reduction when facing enemies.

Arjun has already implemented the Player parent class with basic methods like calculateBaseAttack() and calculateDefense(), but he needs to complete the Warrior child class that extends Player functionality with methods like calculateTotalAttack(), calculateCriticalHit(), and calculateDamageReduction().

Help him to implement the task.

Formulas:

Base Attack = level × 10 (calculated by calculateBaseAttack() method in Player class)

Total Attack = Base Attack + (strength × 3) (calculated by calculateTotalAttack() method in Warrior class)

Critical Hit = Total Attack × 2 (calculated by calculateCriticalHit() method in Warrior class)

Base Defense = level × 5 (calculated by calculateDefense() method in Player class)

Total Defense = Base Defense + (armor × 2) (calculated by calculateTotalDefense() method in Warrior class)

Damage Reduction = enemyDamage - Total Defense (minimum 1 if result is 0 or negative) (calculated by calculateDamageReduction() method in Warrior class)

#### Input:

```
format :
```

The first line of input consists of a String name representing the warrior's name.

The second line of input consists of an integer health representing the warrior's health points.

The third line of input consists of an integer level representing the warrior's current level.

The fourth line of input consists of an integer strength representing the warrior's strength attribute.

The fifth line of input consists of an integer armor representing the warrior's armor rating.

The sixth line of input consists of an integer enemyDamage representing incoming damage from an enemy.

#### Output:

```
format :
```

The first line of output prints: Attack Power: <totalAttack>, where totalAttack represents the warrior's combined attack power including base attack and strength bonus.

The second line of output prints: Critical Hit: <criticalHit>, where criticalHit represents the double damage when warrior performs a critical strike.

The third line of output prints: Damage Taken: <damageReduction>, where damageReduction represents the final damage received after applying defense reduction.

Refer to the sample output for formatting specifications.

Code constraints :
The given test cases fall under the following constraints:

1 ≤ health ≤ 1000

1 ≤ level ≤ 100

1 ≤ strength ≤ 50

1 ≤ armor ≤ 50

1 ≤ enemyDamage ≤ 500

Sample test cases :
#### Input 1:

```
Arthur
100
1
10
5
20
Output 1 :
Attack Power: 40
Critical Hit: 80
Damage Taken: 5
Input 2 :
Lancelot
150
2
15
7
30
Output 2 :
Attack Power: 65
Critical Hit: 130
Damage Taken: 6
```
