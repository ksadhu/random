/*

Problem description (LAZER MAZE):
------------------------------------
You are standing in a rectangular room and are about to fire a laser toward the east wall.  Inside the room a certain number of prisms have been placed.  They will alter the direction of the laser beam if it hits them.  There are north-facing, east-facing, west-facing, and south-facing prisms. If the laser beam strikes an east-facing prism, its course will be altered to be East, regardless of what direction it had been going in before.  If it hits a south-facing prism, its course will be altered to be South, and so on. You are interested to know how far the laser will travel before it hits a wall.

 

INPUT

Your program must read the room description from standard input.  The room is represented as a character array.  The width and height of the array are the width and height of the room.  The characters inside the array denote the placement of the prisms and the laser's starting position. Each line of input from STDIN represents a row of the array.

The number of lines/elements will not be specified in the input, so the program will have to keep reading from STDIN until there are no more lines to read and determine the total number of elements based on the input.  However, the number of lines of input will be at most 50. Each line will contain the same number of characters.

The resulting character array will contain exactly one '@' character, representing the laser's position in the room, and any number of characters from the set {"^", "V", "<", ">", "-"}.  The first four of these represent prisms that are guaranteed to direct the laser in the direction in which they are pointing.  The "^" character directs the laser north, "<" directs it to the west, and so on.  The  "-" character represents empty space.

 

OUTPUT

Your program should print to standard out a single string, terminated by a newline, representing the distance that the laser will travel before hitting a wall.  For example, if the laser travels a distance of 14 cells before hitting a wall, then your program should print the string "14" to STDOUT.   Your program should treat the "@'"symbol the same as the "-" character, that is, as empty space.  So the laser will pass through the original location from which it was fired.

If the laser will get caught in an infinite loop, then your program should print "-1" to STDOUT.

 

Directions:

Please code this problem in Java, C++, C, or Python (all else being equal, we prefer Java) using best coding practices.

NOTE: If you download the attached .zip file of examples, and you are running Windows, do not look at them using the windows program "Notepad", because this will not show the carriage returns properly in the input files.  Look at them with WordPad.  Each input file should consist of multiple lines, each of the same length.

 

What We Are Looking For:

We are looking for clear, concise, well-documented, modular code that reflects good design, object-oriented principles, and understanding of appropriate data structures. We not only want to see code that works, but code that is as beautiful as you can make it according to your personal coding aesthetic. 

 

Examples:

Input:

@--

---

---

Output: 3

 

Input:

@-v

---

---

---

Output: 6

 

Input:

@-v-

----

--<-

Output: 7

 

Input:

@-v

---

-^<

Output: 8

 

Input: 

@-v

->-

-^<

Output: 8

 

Input:

@-v

->v

-^<

Output: -1


------------------------------------------------------------------------------------

 The basic idea/algorithm behind the problem is as follows.
 1. Read the input into 2D character array or String array.
 2. From start poistion keep scanning to right until you find an obstacle.
 3. If no obstacle was found, you hit the wall and output the distance covered till wall
    from start position. If there is obstacle, update search position to that location and
    add the distance covered to that position in the answer. Now continue searching from that
    new poistion based on its direction. 
 4. Repeat step 3 until wall is hit. If the path is repeated then we know there is loop so print -1 
*/

/*
 
 Author: Kumar Sadhu
 License: This problem was given to me on iterviewstreet as a coding challenge for an interview process.
 Please refer to the code below after you have tried the problem yourself. This program is not guaranteed
 to be bug free although I tested it for multiple testcases.
 
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;
int count=0;
int height=0;
int width=0;
map <pair<int, int>, int> visited;
void find(string* room, int x, int y, char dir, bool blocked){
	if(!blocked){
		return;
	}
	else{
		pair<int, int> pos(x,y);
		if(visited.find(pos)==visited.end() and room[x][y]!='@' and room[x][y]!='-'){
			visited.insert(make_pair(make_pair(x,y),1));
		}
		else if(visited.find(pos)!=visited.end() and (room[x][y]=='V' or room[x][y]=='^' or room[x][y]=='>' or room[x][y]=='<')){
			//		check_map.insert(make_pair(make_pair(start,end),1));
			//	if(room[x][y]!='@'){
			count = -1;
			return;
			//	}
		}
		//		cout<< "in else! : "<<x<<" "<<y<<endl;
		bool temp=false;
		if(dir == '>'){// go right
			//		cout<< "in >!"<<endl;
			int i;
			for(i=y+1;i<width;i++){
				if(room[x][i]=='>' or room[x][i]=='V' or room[x][i]=='<' or room[x][i]=='^'){
					count = count+i-y;
					cout<<" count in for loop in  > --- "<<count<<endl;
					//cout<< "count in > : "<<count<<endl;
					temp = true;
					find(room,x,i,room[x][i],true);
					break;
				}
			}
			if(!temp){
				count = count + width-y;
				cout<<" count in if cond in  > --- "<<count<<endl;
				find(room,x,y,dir,false);
			}
		}
		if(dir == 'V'){// go down
		//cout<< "in V!"<<endl;
			int i;
			for (i=x+1; i<height; i++){
//				cout<<" in for loop in  V "<<endl;
				if(room[i][y]=='>' or room[i][y]=='V' or room[i][y]=='<' or room[i][y]=='^'){
					count = count+i-x;
					cout<<" count in for loop in  V --- "<<count<<endl;
					temp = true;
					find(room,i,y,room[i][y],true);
					break;
				}
			}
			if(!temp){
//				cout<<" in if cond in  V "<<endl;
				count = count + height-x;
				cout<<" count in if cond in  V --- "<<count<<endl;
				find(room,x,y,dir,false);
			}
		}
		if(dir == '<'){// go left
		//cout<< "in <!"<<endl;
			int i;
			for(i=y-1;i>=0;i--){
				if(room[x][i]=='>' or room[x][i]=='V' or room[x][i]=='<' or room[x][i]=='^'){
					count = count+y-i;
					cout<<" count in for loop in  < --- "<<count<<endl;
					temp = true;
					find(room,x,i,room[x][i],true);
					break;
				}
			}
			if(!temp){
				count = count+y+1;
				cout<<" count in if cond in  < --- "<<count<<endl;
				find(room,x,y,dir,false);
			}
		}
		if(dir == '^'){// go up
		//cout<< "in ^!"<<endl;
			int i;
			for(i=x-1; i>=0; i--){
				if(room[i][y]=='>' or room[i][y]=='V' or room[i][y]=='<' or room[i][y]=='^'){
					count = count+x-i;
					cout<<" count in for loop in  ^ --- "<<count<<endl;
					temp = true;
					find(room,i,y,room[i][y],true);
					break;
				}
			}
			if(!temp){
				count = count+x+1;
				cout<<" count in if cond in  ^ --- "<<count<<endl;
				find(room,x,y,dir,false);
			}
		}
	}
}
int main() {
	std::string* room;
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int i=0;
	while(1){
		if(i==0){
			string s;
			std::getline(cin, s);
			width=s.length();
			room=new string [50*width];
			room[i]=s;
		}
		else{
			std::getline(cin, room[i]);
			if(room[i].empty()){
				break;
			}
			//	else
			//		room[i]=new char [width];
		}
		i++;
	}
	height=i;
	int si,sj;
	int check=0;
	char ini;
	/*for(i=0;i<height;i++)
		for(int j=0;j<room[i].length();j++){
			if(room[i][j]=='@'){
				si=i;
				sj=j;
			}
			if(room[i][j]=='V' or room[i][j]=='^' or room[i][j]=='>' or room[i][j]=='<'){
				check=1;
				//ini = 
			}
		}
	if(check==0){
		cout<<width-sj<<endl;
	}*/
	cout<<"width : "<<width<<endl;
	cout<<"height : "<<height<<endl;
	find(room,0,0,'>',true);
	cout<<count<<endl;

	/*int ans=0;
	for(i=si;i<height;i++){
		for(int j=sj;j<room[i].length();j++){
			
			 Depending on the first charater we encounter, we update the coordinates in that direction.
			 
	//		int dpos=room[i].find('V');
	//		int rpos=room[i].find(">");
	//		int lpos=room[i].find("<");
	//		int upos=room[i].find("^");
			// get the least among these positions
			// add the path length till 'V'
	//		ans= ans+dpos-sj;
			// update new start position to the 'V' coordinates
	//		j=sj;
			// continue searching from this position.
		}
	}
	if(check!=0)
		cout<<ans<<endl;*/
	return 0;
}

