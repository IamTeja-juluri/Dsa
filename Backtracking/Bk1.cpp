/*
Ramesh and Suresh are best friends. 
They decided to play a word game.

The game rules are as follows:
	- The game board shows a word W consist of two characters only A and B.
	- You are allowed to replace a pair of neighbour letters AA with BB in W.
	- Finally, The one who failed to replace the letters will lose the game.

You can assume that Ramesh will start playing the game always.

Your task is to determine if Ramesh can guarantee a win.
Print 'true', if Ramesh guarantee a win, otherwise, print 'false'.

Input Format:
-------------
A string W, word.

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
AAABAAAA

Sample Output-1:
----------------
true

Explanation:
------------
Given word is AAABAAAA 
Ramesh -> AAABBBAA 
Now whatever the pair Suresh replaced with BB, 
one more replace is possible for Ramesh
So, there is a guarantee for Ramesh to win.

Sample Input-2:
---------------
AAAAAA

Sample Output-2:
----------------
true


Sample Input-3:
---------------
AAABAAA

Sample Output-3:
----------------
false


Test Cases:
case =1
input =ABAAAABAAAABBBAAAABBBAAAAA
output =true

case =2
input =AABAAAAABAAAABBBAAAAAABBBAAAAAA
output =true

case =3
input =AAAABAAAABAAABABAAABBAAAABAAAABB
output =false

case =4
input =AAAABBBAAAABBBAAAABBBAAAA
output =false

case =5
input =AAAABBBAAAABBBAAAABBBAAA
output =true

case =6
input =ABABABABABABABABAABABABAAB
output =false

case =7
input =BAAABAAABAAABAAABAAABAAABAA
output =true

case =8
input =BAAABAAABAAABAAABAABBABABAA
output =false

Solution:
*/

import java.util.Scanner;

class FlipGame {
    int len;
    char ss[];
	boolean canWin(String s) {
		len = s.length();
		ss = s.toCharArray();
		return canWin();
	}
	boolean canWin() {
		for (int is = 0; is <= len-2; ++is) {
			if (ss[is] == 'A' && ss[is+1] == 'A') {
				ss[is] = 'B'; ss[is+1] = 'B';
				boolean wins = !canWin(); 
				ss[is] = 'A'; ss[is+1] = 'A';
				if (wins) return true;
			}
		}
		return false;
	} 
	public static void main(String args[])
	{
		System.out.println(new FlipGame().canWin(new Scanner(System.in).next()));
	}
}




#include<bits/stdc++.h>
using namespace std;

bool game(string &s){

   for(int i=0;i<=s.size()-2;i++){
      
      if(s[i]=='A' && s[i+1]=='A'){
      	s[i]='B';
      	s[i+1]='B';
      	bool wins=!game(s);
      	s[i]='A';
      	s[i+1]='A';
      	if(wins) return true;
      }

   }

   return false;

}


int main(){

  #ifndef ONLINE_JUDGE
	freopen("inputbk.txt","r",stdin);
	freopen("outputbk.txt","w",stdout);
  #endif
 
 string s;
 cin>>s;

 cout<<game(s);


}
