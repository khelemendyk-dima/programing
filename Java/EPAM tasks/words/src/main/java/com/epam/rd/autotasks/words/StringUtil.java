package com.epam.rd.autotasks.words;

import java.util.Arrays;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class StringUtil {
    public static int countEqualIgnoreCaseAndSpaces(String[] words, String sample) {
        if (words == null || sample == null) {
            return 0;
        }
        int counter = 0;
        sample = sample.strip();
        for (String word : words) {
            if (sample.equalsIgnoreCase(word.strip())) {
                counter++;
            }
        }
        return counter;
    }

    public static String[] splitWords(String text) {
        if (text == null || text.equals("") || text.matches("[,.;: ?!]+")) {
            return null;
        }
        StringTokenizer tokens = new StringTokenizer(text, "[,.;: ?!]+");
        String[] res = new String[tokens.countTokens()];
        int i = 0;
        while (tokens.hasMoreTokens()) {
            res[i] = tokens.nextToken();
            i++;
        }
        return res;
    }

    public static String convertPath(String path, boolean toWin) {
        if (path == null || path.equals("") || (!isUnix(path) && !isWin(path))) {
            return null;
        }
        if (!toWin) {
            if (path.startsWith("C:\\User")) {
                path = path.replace("C:\\User", "~");
            } else if (path.startsWith("C:\\")) {
                path = path.replace("C:\\", "/");
            }
            path = path.replaceAll("\\\\", "/");
        } else {
            if (path.startsWith("~")) {
                path = path.replace("~", "C:\\User");
            } else if (path.startsWith("/")) {
                path = path.replaceFirst("/", "C:\\\\");
            }
            path = path.replaceAll("/", "\\\\");
        }
        return path;
    }
    private static boolean isWin(String path) {
        return path.matches("^(C:)?\\.?(\\\\?( )?\\w+\\.?)+\\\\?" +
                "|^(C:)?(\\\\?\\w+\\.?)+\\\\?\\.{1,2}(\\\\?\\w+\\.?)+\\\\?" +
                "|\\.+" +
                "|C:\\\\" +
                "|\\.{1,2}\\\\\\w+\\\\?" +
                "|\\.{1,2}\\\\\\w+ \\w+");
    }
    private static boolean isUnix(String path) {
        return path.matches("^~?(/?\\w+\\.?)+/?" +
                "|(/?\\w+\\.?)+/?\\.{1,2}(/?\\w+\\.?)+/?" +
                "|^~?/?" +
                "|\\.{1,2}/\\w+/?" +
                "|\\.{1,2}/\\w+ \\w+");
    }

    public static String joinWords(String[] words) {
        if (words == null) {
            return null;
        }
        int counter = 0;
        StringJoiner sj = new StringJoiner(", ");
        for (String word : words) {
            if (!word.equals("")) {
                sj.add(word);
                counter++;
            }
        }
        if (counter == 0) {
            return null;
        }
        return "[" + sj + "]";
    }

    public static void main(String[] args) {
        System.out.println("Test 1: countEqualIgnoreCaseAndSpaces");
        String[] words = new String[]{" WordS    \t", "words", "w0rds", "WOR  DS", };
        String sample = "words   ";
        int countResult = countEqualIgnoreCaseAndSpaces(words, sample);
        System.out.println("Result: " + countResult);
        int expectedCount = 2;
        System.out.println("Must be: " + expectedCount);

        System.out.println("Test 2: splitWords");
        String text = "   ,, first, second!!!! third";
        String[] splitResult = splitWords(text);
        System.out.println("Result : " + Arrays.toString(splitResult));
        String[] expectedSplit = new String[]{"first", "second", "third"};
        System.out.println("Must be: " + Arrays.toString(expectedSplit));

        System.out.println("Test 3: convertPath");
        String unixPath = "/some/unix/path";
        String convertResult = convertPath(unixPath, true);
        System.out.println("Result: " + convertResult);
        String expectedWinPath = "C:\\some\\unix\\path";
        System.out.println("Must be: " + expectedWinPath);

        System.out.println("Test 4: joinWords");
        String[] toJoin = new String[]{"go", "with", "the", "", "FLOW"};
        String joinResult = joinWords(toJoin);
        System.out.println("Result: " + joinResult);
        String expectedJoin = "[go, with, the, FLOW]";
        System.out.println("Must be: " + expectedJoin);
    }
}