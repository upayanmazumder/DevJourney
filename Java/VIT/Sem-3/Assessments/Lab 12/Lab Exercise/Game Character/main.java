abstract class GameCharacter {
    abstract int attack(int attributeValue);

    abstract void defend(int defense);
}

class Warrior extends GameCharacter {
    Warrior() {
        System.out.println("Warrior Actions:");
    }

    @Override
    int attack(int strength) {
        int damage = strength * 3;
        System.out.println("Attack: Powerful sword slash for " + damage + " damage!");
        return damage;
    }

    @Override
    void defend(int defense) {
        System.out.println("Defend: Raises shield, defence boosted by " + defense + "!");
    }
}

class Wizard extends GameCharacter {
    Wizard() {
        System.out.println("Wizard Actions:");
    }

    @Override
    int attack(int magicPower) {
        int damage = magicPower * 2;
        System.out.println("Attack: Casts spell, deals " + damage + " magical damage!");
        return damage;
    }

    @Override
    void defend(int defense) {
        System.out.println("Defend: Creates magical barrier, defence boosted by " + defense + "!");
    }
}