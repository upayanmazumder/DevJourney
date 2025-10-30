import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class CourseAnalyzer {
    public Map<String, String> identifyHighestAndLowestRatedCourses(Map<String, Double> courseRatings) {
        Map<String, String> result = new HashMap<>();

        if (courseRatings.isEmpty()) {
            return result;
        }

        String highestCourse = null;
        String lowestCourse = null;
        double highestRating = Double.MIN_VALUE;
        double lowestRating = Double.MAX_VALUE;

        for (Map.Entry<String, Double> entry : courseRatings.entrySet()) {
            String course = entry.getKey();
            double rating = entry.getValue();

            if (rating > highestRating) {
                highestRating = rating;
                highestCourse = course;
            }

            if (rating < lowestRating) {
                lowestRating = rating;
                lowestCourse = course;
            }
        }

        result.put("highest", highestCourse);
        result.put("lowest", lowestCourse);

        return result;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Double> courseRatings = new HashMap<>();
        CourseAnalyzer analyzer = new CourseAnalyzer();

        while (true) {
            String courseName = scanner.nextLine();
            if (courseName.equalsIgnoreCase("done")) {
                break;
            }
            double rating = Double.parseDouble(scanner.nextLine());
            courseRatings.put(courseName, rating);
        }

        Map<String, String> result = analyzer.identifyHighestAndLowestRatedCourses(courseRatings);
        System.out.println("Highest Rated Course: " + result.get("highest"));
        System.out.println("Lowest Rated Course: " + result.get("lowest"));

        scanner.close();
    }
}