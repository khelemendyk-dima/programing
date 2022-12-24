package com.efimchick.ifmo.streams.countwords;


import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Words {

    public String countWords(List<String> lines) {
        Comparator<Map.Entry<String, Long>> comparator =
                Comparator.comparingLong((Map.Entry<String, Long> o) -> o.getValue())
                        .reversed()
                        .thenComparing(Map.Entry::getKey);
        Map<String, Long> words = lines.stream()
                .flatMap(line -> Arrays.stream(line.split("[^a-zA-Zа-яА-я]+")))
                .map(String::toLowerCase)
                .filter(s -> s.length() > 3)
                .collect(Collectors.groupingBy(e -> e, Collectors.counting()));
        return words.entrySet()
                .stream()
                .filter(entry -> entry.getValue() > 9)
                .sorted(comparator)
                .map(entry -> entry.getKey() + " - " + entry.getValue())
                .collect(Collectors.joining("\n"));
    }
}
