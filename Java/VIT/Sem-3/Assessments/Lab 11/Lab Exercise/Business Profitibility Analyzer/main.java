class BusinessUtility {
    public double calculateMargin(double revenue, double cost) {

        return ((revenue - cost) / revenue) * 100;
    }
}

class SeasonalBusinessUtility extends BusinessUtility {
    @Override
    public double calculateMargin(double revenue, double cost) {
        return super.calculateMargin(revenue, cost) + 10;
    }
}

class ProfitabilityChecker {
    public void checkProfitability(double regularMargin) {
        if (regularMargin >= 10) {
            System.out.println("Business is profitable.");
        } else {
            System.out.println("Business is not profitable.");
        }
    }
}
