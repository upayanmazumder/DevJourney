class Cuboid {
    protected double length;
    protected double width;
    protected double height;

    public Cuboid(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public double calculateVolume() {
        return length * width * height;
    }
}

class Cube extends Cuboid {
    public Cube(double side) {

        super(side, side, side);
    }

    @Override
    public double calculateVolume() {
        return length * length * length;
    }
}
