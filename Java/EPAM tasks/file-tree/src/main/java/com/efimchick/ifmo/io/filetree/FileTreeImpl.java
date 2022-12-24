package com.efimchick.ifmo.io.filetree;

import java.io.File;
import java.nio.file.Path;
import java.util.*;

public class FileTreeImpl implements FileTree {
    @Override
    public Optional<String> tree(Path path) {
        File file = new File(String.valueOf(path));

        if (!file.exists()) {
            return Optional.empty();
        }
        if (file.isFile()) {
            return Optional.of(file.getName() + ' ' + file.length() + " bytes");
        }
        if (file.isDirectory()) {
            return Optional.of(getDirTree(file, new ArrayList<>()));
        }

        return Optional.empty();
    }

    private String getDirTree(File folder, List<Boolean> lastFolders) {
        StringBuilder directory = new StringBuilder();

        if (lastFolders.size() != 0)
            directory.append(!(lastFolders.get(lastFolders.size() - 1)) ? "├─ " : "└─ ");
        directory.append(folder.getName()).append(" ").append(folderSize(folder));

        File[] files = folder.listFiles();
        int count = files != null ? files.length : 0;
        files = sortFiles(files);

        for (int i = 0; i < count; i++) {
            directory.append('\n');

            for (Boolean lastFolder : lastFolders) {
                if (lastFolder) {
                    directory.append("   ");
                } else {
                    directory.append("│  ");
                }
            }

            if (files[i].isFile()) {
                directory.append(i + 1 == count ? "└" : "├").append("─ ")
                        .append(files[i].getName()).append(" ")
                        .append(files[i].length()).append(" bytes");
            } else {
                ArrayList<Boolean> list = new ArrayList<>(lastFolders);
                list.add(i+1 == count);
                directory.append(getDirTree(files[i], list));
            }
        }

        return directory.toString();
    }
    private long getFolderSize(File folder) {
        long size = 0;
        File[] files = folder.listFiles();

        assert files != null;
        for (File file : files) {
            if (file.isFile()) {
                size += file.length();
            } else {
                size += getFolderSize(file);
            }
        }

        return size;
    }
    private String folderSize(File folder) {
        return getFolderSize(folder) + " bytes";
    }
    private File[] sortFiles(File[] folder) {
        Arrays.sort(folder, (o1, o2) -> o1.getName().compareToIgnoreCase(o2.getName()));
        List<File> sorted = new ArrayList<>();

        for (File file : folder) {
            if (file.isDirectory())
                sorted.add(file);
        }

        for (File file : folder) {
            if (file.isFile())
                sorted.add(file);
        }

        return sorted.toArray(new File[0]);
    }
}