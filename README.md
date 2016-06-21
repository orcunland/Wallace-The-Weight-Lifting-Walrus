# Wallace-The-Weight-Lifting-Walrus
An algorithm for calculating the weights that wallace needs to lift

Wallace the Weightlifting Walrus is training for a contest where it will have to lift 1000 kg. Wallace has some weight plates lying around, possibly of different weights, and its goal is to add some of the plates to a bar so that it can train with a weight as close as possible to 1000 kg.

In case there exist two such numbers which are equally close to 1000 (e.g. 998 and 1002), Wallace will pick the greater one (in this case 1002).

Help Wallace the Weightlifting Walrus and tell it which weight it will have to lift.

Input
The first line of the input contains the number of plates nn (1≤n≤1000). Each of the following nn lines contains one positive integer less than or equal to 1000, denoting the weight of each plate.

Output

Output one integer, the combined weight closest to 1000.

Sample Input 1   (4, 900, 500, 498, 4)

Sample Output 1   (1002)

Sample Input 2   (1, 1)

Sample Output 2   (1)
