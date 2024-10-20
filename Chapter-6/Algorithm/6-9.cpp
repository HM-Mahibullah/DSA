#include<iostream>
using namespace std;

void towerOfHanoi(int n, char beg, char aux, char end) {
    if (n==1) {
        cout << beg << " -> " << end << "\n";
        return;
    }
    towerOfHanoi(n-1, beg, end, aux);
    towerOfHanoi(1, beg, aux, end);                //   ২ টি চাকতি বা চাকার কথা মনে রাখলে কোডটি সহজে মনে রা্খা যায়.
    towerOfHanoi(n-1, aux, beg, end);
}

int main() {
    towerOfHanoi(4, 'A', 'B', 'C');
}
/*
n=4, the goal is to move 4 disks from rod 'A' (beg) to rod 'C' (end) using rod 'B' (aux).

Explanation:
First Call: towerOfHanoi(4, 'A', 'B', 'C')

Since 
n=4, this does not trigger the base case. The function continues with recursive calls.
We need to move the top 3 disks from 'A' to 'B' using 'C'. This triggers:

Second Call: towerOfHanoi(3, 'A', 'C', 'B')


n=3, so we need to move the top 2 disks from 'A' to 'C' using 'B'. This triggers:
Third Call: towerOfHanoi(2, 'A', 'B', 'C')


n=2, so we need to move the top 1 disk from 'A' to 'B' using 'C'. This triggers:
Fourth Call: towerOfHanoi(1, 'A', 'C', 'B')


n=1 triggers the base case. The smallest disk (Disk 1) is moved from 'A' to 'B'. Output:  A -> B
Back to Third Call: towerOfHanoi(2, 'A', 'B', 'C')   এটি ২ নং এর  ফাংশন towerOfHanoi(1, beg, aux, end);  তাই সরাসরি প্রিন্ট করবে.
Now we move Disk 2 from 'A' to 'C'. Output:  A -> C

Then move Disk 1 from 'B' to 'C' (recursive call). Output:  B -> C

Back to Second Call: towerOfHanoi(3, 'A', 'C', 'B')

Now move Disk 3 from 'A' to 'B'. Output:    A -> B

We now need to move the 2 disks from 'C' to 'B' using 'A'. This triggers:

Fifth Call: towerOfHanoi(2, 'C', 'A', 'B')

We need to move Disk 1 from 'C' to 'A'. Output:  C -> A

Then move Disk 2 from 'C' to 'B'. Output:     C -> B   //এটি ২ নং এর  ফাংশন towerOfHanoi(1, beg, aux, end);  তাই সরাসরি প্রিন্ট করবে.

Finally, move Disk 1 from 'A' to 'B'. Output: A -> B

Back to First Call: towerOfHanoi(4, 'A', 'B', 'C')

Now move Disk 4 from 'A' to 'C'. Output:  A -> C//এটি ২ নং এর  ফাংশন towerOfHanoi(1, beg, aux, end);  তাই সরাসরি প্রিন্ট করবে.


Now move the 3 disks from 'B' to 'C' using 'A'. This triggers:

Sixth Call: towerOfHanoi(3, 'B', 'A', 'C')

We need to move the top 2 disks from 'B' to 'A' using 'C'. This triggers:

Seventh Call: towerOfHanoi(2, 'B', 'C', 'A')

Move Disk 1 from 'B' to 'C'. Output:  B -> C

Move Disk 2 from 'B' to 'A'. Output:  B -> A //এটি ২ নং এর  ফাংশন towerOfHanoi(1, beg, aux, end);  তাই সরাসরি প্রিন্ট করবে.

Move Disk 1 from 'C' to 'A'. Output:   C -> A

Back to Sixth Call: towerOfHanoi(3, 'B', 'A', 'C')

Now move Disk 3 from 'B' to 'C'. Output:  B -> C  //এটি ২ নং এর  ফাংশন towerOfHanoi(1, beg, aux, end);  তাই সরাসরি প্রিন্ট করবে.

Now move the 2 disks from 'A' to 'C' using 'B'. This triggers:
Eighth Call: towerOfHanoi(2, 'A', 'B', 'C')

Move Disk 1 from 'A' to 'B'. Output:  A -> B

Move Disk 2 from 'A' to 'C'. Output:  A -> C  //এটি ২ নং এর  ফাংশন towerOfHanoi(1, beg, aux, end);  তাই সরাসরি প্রিন্ট করবে.

Move Disk 1 from 'B' to 'C'. Output:  B -> C

Final Output:
After all recursive calls are resolved, the output would be the following sequence of moves:

A -> B
A -> C
B -> C
A -> B
C -> A
C -> B
A -> B
A -> C
B -> C
B -> A
C -> A
B -> C
A -> B
A -> C
B -> C
This is the sequence for moving 4 disks from 'A' to 'C' using 'B'.
*/
