package ua.khpi.oop.khelemendyk07;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Library {
    public static void main(String[] args) {
        List<Book> library = new ArrayList<>();
        library.add(new Book("978-316-148410-0",
                             "Приключения Тома Сойера",
                    new String[] { "Марк Твен" },
                            "Первое издание",
                             "Роман",
                      1876));

        library.add(new Book("978-316-148410-1",
                            "Рога и копыта",
                   new String[] { "Джек Лондон", "Вася Петькин" },
                           "Четвертое издание",
                            "Драма",
                     1901));
        System.out.println(library);
    }
}
