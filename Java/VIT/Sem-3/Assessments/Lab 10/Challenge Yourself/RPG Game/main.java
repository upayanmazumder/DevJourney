class Player {
    protected String name;
    protected int health;
    protected int level;

    public Player(String name, int health, int level) {
        this.name = name;
        this.health = health;
        this.level = level;
    }

    public int calculateBaseAttack() {
        return level * 10;
    }

    public int calculateDefense() {
        return level * 5;
    }
}

class Warrior extends Player {
    private int strength;
    private int armor;

    public Warrior(String name, int health, int level, int strength, int armor) {
        super(name, health, level);
        this.strength = strength;
        this.armor = armor;
    }

    public int calculateTotalAttack() {
        return calculateBaseAttack() + (strength * 3);
    }

    public int calculateCriticalHit() {
        return calculateTotalAttack() * 2;
    }

    public int calculateTotalDefense() {
        return calculateDefense() + (armor * 2);
    }

    public int calculateDamageReduction(int enemyDamage) {
        int reduced = enemyDamage - calculateTotalDefense();
        return reduced <= 0 ? 1 : reduced;
    }
}