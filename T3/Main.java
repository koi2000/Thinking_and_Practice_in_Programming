//package com.programming.t3;


import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static class Pair<K, V> implements Comparable<Pair<K, V>> {
        public K key;
        public V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }


        @Override
        public int compareTo(Pair<K, V> o) {
            Pair<Integer, Integer> pair1 = (Pair<Integer, Integer>) this;
            Pair<Integer, Integer> pair2 = (Pair<Integer, Integer>) o;
            if (pair1.key.equals(pair2.key)) {
                return pair1.value > pair2.value ? 1 : -1;
            }
            return pair1.key > pair2.key ? 1 : -1;
        }
    }

    static class notebook {
        public LinkedList<StringBuilder> content;
        public LinkedList<String> choosed;
        public LinkedList<String> copy;
        public Pair<Integer, Integer> his;
        public Pair<Integer, Integer> now;
        public boolean isShift = false;
        public boolean isChoose = false;

        public notebook() {
            his = new Pair<>(-1, -1);
            now = new Pair<>(0, 0);
            content = new LinkedList<>();
            content.add(new StringBuilder());
            choosed = new LinkedList<>();
            copy = new LinkedList<>();
        }

        public void handleChoose() {
            // 提取出当前被选中的段
            // 可能的情况有三种，第一种情况，只有一行，第二种情况，最后一行
            Pair<Integer, Integer> min;
            Pair<Integer, Integer> max;
            if (his.compareTo(now) > 0) {
                min = now;
                max = his;
            } else {
                min = his;
                max = now;
            }
            // 创建一个被选中的list
            choosed = new LinkedList<>();

            if (max.key.equals(min.key)) {
                String substring = content.get(min.key).substring(min.value, max.value);
                choosed.add(substring);
                return;
            }
            // 找到所有选中的字
            for (int i = min.key; i <= max.key; i++) {
                if (i == min.key) {
                    // 截取第一行的片段
                    String substring = content.get(i).substring(min.value);
                    choosed.add(substring);
                } else if (i == max.key) {
                    // 截取最后一行的片段
                    String substring = content.get(i).substring(0, max.value);
                    choosed.add(substring);
                } else {
                    // 添加片段
                    choosed.add(content.get(i).toString());
                }
            }
        }

        public void handleInsert(String comd) {
            if (isChoose) {
                removeChoosed();
            }
            if (comd.equals("Char")) {
                String str = next();
                Integer key = now.key;
                Integer value = now.value;
                content.get(key).insert(value, str);
                now.value = now.value + str.length();
            }
            if (comd.equals("Enter")) {
                Integer row = now.key;
                Integer value = now.value;
                StringBuilder stringBuilder = new StringBuilder();
                // 获取到当前行
                String line = content.get(row).toString();
                // 截取得到第一段
                String part1 = line.substring(0, now.value);
                content.set(now.key, new StringBuilder(part1));
                // 截取得到第二段
                String part2 = line.substring(now.value);
                stringBuilder.append(part2);
                // 将后半段放入新的行
                content.add(now.key + 1, stringBuilder);
                now = new Pair<>(now.key + 1, 0);
            }
            if (comd.equals("Space")) {
                content.get(now.key).insert(now.value, " ");
                now = new Pair<>(now.key, now.value + 1);
            }
            if (comd.equals("Paste")) {
                // 粘贴一行
                if (copy.size() == 1) {
                    content.get(now.key).insert(now.value, copy.get(0));
                    now.value += copy.get(0).length();
                } else if (copy.size() > 1) {
                    // TODO：粘贴多行
                    // TODO: 考虑这样一种情况，粘贴在某一行的中间，这种情况需要首先将这两段拆开
                    // 将复制的内容加入，然后更新光标位置
                    StringBuilder nowLine = content.get(now.key);
                    int length = nowLine.length();
                    // 后半段
                    String lastPart = nowLine.substring(now.value, length);
                    // 删去后半段
                    content.get(now.key).delete(now.value, length);
                    // 新增一行，表明拆成了两段
                    content.add(now.key + 1, new StringBuilder(lastPart));
                    for (int i = 0; i < copy.size(); i++) {
                        if (i == 0) {
                            // 第一行
                            content.get(now.key).insert(now.value, copy.get(0));
                            // 实时更新光标位置
                            now.value = content.get(now.key).length();
                        } else if (i == copy.size() - 1) {
                            now.key++;

                            if (now.key >= content.size()) {
                                content.add(new StringBuilder(copy.get(i)));
                                now.value = copy.get(i).length();
                            } else {
                                content.get(now.key).insert(0, copy.get(i));
                                now.value = copy.get(i).length();
                            }
                        } else {
                            // 更新光标的位置
                            now.key++;
                            content.add(now.key, new StringBuilder(copy.get(i)));
                            now.value = content.get(now.key).length();
                        }
                    }
                }
            }
        }

        public void handleMove(String comd) {
            // 移动后退出选中状态
            if (isChoose) {
                isChoose = false;
            }
            if (comd.equals("Home")) {
                now.value = 0;
            }
            if (comd.equals("End")) {
                // 得到当前行的大小
                int size = content.get(now.key).length();
                now.value = size;
            }
            if (comd.equals("Up")) {
                if (now.key != 0) {
                    // 得到上一行的大小
                    int capacity = content.get(now.key - 1).length();
                    // 首先更新了行
                    now.key = now.key - 1;
                    // 然后更新列，大的时候更新即可，小的时候不用更新
                    if (now.value > capacity) {
                        now.value = capacity;
                    }
                }
            }
            if (comd.equals("Down")) {
                // 获取到当前所有的行
                int size = content.size();
                // 最后一行，不操作
                if (now.key != size - 1) {
                    // 得到上一行的大小
                    int capacity = content.get(now.key + 1).length();
                    now.key = now.key + 1;
                    if (now.value > capacity) {
                        now.value = capacity;
                    }
                }
            }
            if (comd.equals("Left")) {
                if (now.key == 0 && now.value == 0) {
                } else if (now.value == 0) {
                    int capacity = content.get(now.key - 1).length();
                    now.key--;
                    now.value = capacity;
                } else {
                    now.value--;
                }
            }
            if (comd.equals("Right")) {
                int size = content.size() - 1;
                int capacity = content.get(size).length();
                int nowSize = content.get(now.key).length();
                if (now.key == size && now.value == capacity) {
                } else if (now.value == nowSize) {
                    now.key++;
                    now.value = 0;
                } else {
                    now.value++;
                }
            }
        }

        public void removeChoosed() {
            // TODO：检查是否在删除时有问题，
            isChoose = false;
            Pair<Integer, Integer> min;
            Pair<Integer, Integer> max;
            if (his.compareTo(now) > 0) {
                min = now;
                max = his;
            } else {
                min = his;
                max = now;
            }
            // 分三种情况，第一种为两个在同一行，这种情况直接删除中间即可
            if (max.key.equals(min.key)) {
                content.get(min.key).delete(min.value, max.value);
                now.key = min.key;
                now.value = min.value;
                return;
            }
            // TODO：两种情况，一是最后一行为完整的一行，这时直接删除最后一行，否则删除一部分并于上一行相连
            // 删除选中的段，涉及到换行的问题，这里需要处理一下
            for (int i = 0; i <= max.key - min.key; i++) {
                // 第一行删除后面的元素
                if (i == 0) {
                    content.get(min.key).delete(min.value, content.get(min.key).length());
                } else if (i == max.key - min.key) {
                    // 取出最后一行
                    // 如果最后一行被删除的什么也不剩了，就可以把这一行删了
                    String substring = content.get(min.key + 1).substring(max.value);
                    if (substring.length() > 0) {
                        content.get(min.key).append(substring);
                        content.remove(min.key + 1);
                    } else {
                        content.remove(min.key + 1);
                    }

                    //content.get(min.key+1).delete(0,max.value);
                } else {
                    // 中间行全部删除
                    content.remove(min.key + 1);
                }
            }
            now.key = min.key;
            now.value = min.value;
        }

        public void handleRemove(String comd) {
            // 如果当前为选中状态，首先删去选中的内容
            if (isChoose) {
                removeChoosed();
            } else {
                if (comd.equals("Del")) {
                    // 得到最后一行的信息
                    int size = content.size() - 1;
                    int capacity = content.get(size).length();
                    int nowSize = content.get(now.key).length();
                    // 最后一行，最后一位不用操作
                    if (now.key == size && now.value == nowSize) {
                    } else if (now.value == nowSize) {
                        StringBuilder nextLine = content.get(now.key + 1);
                        // 将下一行的内容放到这一行
                        content.get(now.key).append(nextLine);
                        // 删去下一行
                        content.remove(now.key + 1);
                    } else {
                        // 删除后面一个字符
                        content.get(now.key).deleteCharAt(now.value);
                    }
                }
                if (comd.equals("Backspace")) {
                    if (now.key == 0 && now.value == 0) {
                    } else if (now.value == 0) {
                        // 与上一行合并
                        StringBuilder nowLine = content.get(now.key);
                        int capacity = content.get(now.key - 1).length();
                        content.get(now.key - 1).append(nowLine);
                        content.remove(now.key.intValue());
                        now.key--;
                        now.value = capacity;
                    } else {
                        content.get(now.key).deleteCharAt(now.value - 1);
                        now.value--;
                    }
                }
            }
        }

        public void print() {
            for (StringBuilder stringBuilder : content) {
                out.println(stringBuilder.toString());
            }
            out.flush();
        }

        public void handleCount() {
            int sum = 0;
            if (isChoose) {
                handleChoose();
                for (String s : choosed) {
                    sum += s.replace(" ", "").length();
                }
            } else {
                for (StringBuilder stringBuilder : content) {
                    String s = stringBuilder.toString();
                    sum += s.replace(" ", "").length();
                }
            }

            out.println(sum);
            out.flush();
        }

        public void handleCopy() {
            if (isChoose) {
                handleChoose();
                copy = new LinkedList<>();
                copy.addAll(choosed);
            } else {
                if (content.get(now.key).length() != 0) {
                    copy = new LinkedList<>();
                    copy.add(content.get(now.key).toString());
                }
            }
        }

        public void handleFind(String word) {
            // 计算出现的次数
            int count = 0;
            if (isChoose) {
                handleChoose();
                for (String str : choosed) {
                    int index = 0;
                    while ((index = str.indexOf(word, index)) != -1) {
                        //System.out.print(str.charAt(index) + " ");
                        index++;
                        count++;
                    }
                }
            } else {
                for (StringBuilder stringBuilder : content) {
                    String str = stringBuilder.toString();
                    int index = 0;
                    while ((index = str.indexOf(word, index)) != -1) {
                        //System.out.print(str.charAt(index) + " ");
                        index++;
                        count++;
                    }
                }
            }
            out.println(count);
            out.flush();
        }
    }


    public static void main(String[] args) {
        //System.out.println(12222);
        int n = nextInt();
        notebook nb = new notebook();
        //System.out.println(n);
        for (int i = 0; i < n; i++) {
            String cmd = next();
            if (cmd.equals("MOVE")) {
                String comd = next();
                nb.handleMove(comd);
            }
            if (cmd.equals("INSERT")) {
                String comd = next();
                nb.handleInsert(comd);
            }
            if (cmd.equals("PRINT")) {
                nb.print();
            }
            if (cmd.equals("REMOVE")) {
                String comd = next();
                nb.handleRemove(comd);
            }
            if (cmd.equals("COUNT")) {
                nb.handleCount();
            }
            if (cmd.equals("COPY")) {
                nb.handleCopy();
            }
            if (cmd.equals("FIND")) {
                String word = next();
                nb.handleFind(word);
            }
            if (cmd.equals("SHIFT")) {
                // 当前处于选中状态，再次点击shift，退出选中状态，并开启shift功能
                if (nb.isChoose) {
                    nb.isChoose = false;
                    nb.isShift = true;
                } else {
                    // 若当前开启粘滞功能，结束时会判断是否进入选中状态
                    if (nb.isShift) {
                        nb.isShift = false;
                        // 判断位置是否相同
                        if (!(nb.now.key.equals(nb.his.key) && nb.now.value.equals(nb.his.value))) {
                            nb.isChoose = true;
                        }
                    } else {
                        // 未开启则开启
                        nb.isShift = true;
                        // 记录当前位置为记录点
                        nb.his = new Pair<>(nb.now.key, nb.now.value);
                    }
                }
            }
        }
        out.flush();
    }


    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tok;

    static String next() {
        hasNext();
        return tok.nextToken();
    }

    static String nextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            return null;
        }
    }

    static long nextLong() {
        return Long.parseLong(next());
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static boolean hasNext() {
        while (tok == null || !tok.hasMoreTokens()) try {
            tok = new StringTokenizer(in.readLine());
        } catch (Exception e) {
            return false;
        }
        return true;
    }
}
