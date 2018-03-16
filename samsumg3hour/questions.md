# 第一个人-1  maximum number of submissions allowed was 10,
A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and the edge weights are the probabilities of the doctor going from that division to other connected division but the doctor stays 10mins at each division now there will be given time and had to find the division in which he will be staying by that time and is determined by finding division which has high probability.
## [input]
Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division in which he will be there, the edges starting point, end point, probability.
Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling time is not considered and during that 10min at 10th min he will be in next division, so be careful

# 第一个人-2  maximum number of submissions allowed was 10,
There is a source (S) and destination (D) and a spacecraft has to go from S to D. There are N number of wormholes in between which has following properties:

Each wormhole has an entry and an exit.
Each wormhole is bi-directional i.e. one can enter and exit from any of the ends.
The time to cross the wormhole is given and the spacecraft may or may not use the wormhole to reach D.
The time taken to travel outside wormhole between two points (x1, y1) and (x2, y2) is given by a formula
|x1 – x2| + |y1 – y2|
where, (x1, y1) and (x2, y2) are the coordinates of two points.

The coordinates of S and D are given and we have to find the minimum time to reach D from S.

Note: It’s not mandatory to consider all the wormholes

# 第二个人  50 test cases
There are n balloons and n bullets and each balloon is assigned with a particular number (point). Whenever a particular balloon is shot the no of points increases by 1.the multiplication of point assigned to balloon on left and that of right side.

2.point assigned to left if no right exists

3.point assigned to right if no left exists.

4.the point assigned to itself if no other balloon exists.



You have to output the maximum no of points possible.

## [Input]

1 2 3 4

## [Output]

20

There are 50 test cases and you qualify only if all the test cases i.e. all 50 of them passed.

# 第三个人    having 10 test cases   a maximum of 5 submissions
Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y) (-1<x<101, -1<y<101) . The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities.

You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of a (the) shortest path.

You don’t have to solve this problem efficiently. You could find an answer by looking up all the possible ways. If you can look up all the possibilities well, you will get a perfect score.

[Constraints]

4<N<11. Each location (x,y) is in a bounded grid, -1<x<101, -1<y<101, and x, y are integers.

[Input]

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.

[Output]

Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path. Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space.

[I/O Example]

Input (20 lines in total. In the first test case, the locations of the office and the home are (0, 0) and (100, 100) respectively, and the locations of the customers are (70, 40), (30, 10), (10, 5), (90, 70), (50, 20).)

5 (Starting test case #1)

0 0 100 100 70 40 30 10 10 5 90 70 50 20

6 (Starting test case #2)

88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14

Output (10 lines in total)

#1 200

#2 304

HINT:- Use BackTracking

