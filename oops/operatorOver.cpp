#include<bits/stdc++.h>
using namespace std;

class Rectangle{
	public:
		int length;
		int breadth;
	public:
		Rectangle(int len , int bre){
			length = len;
			breadth = bre;
		}
		void area(){
			cout<<length*breadth<<endl;
		
		}

		void operator ++ (int){
			length++;
			breadth++;
		}
		void operator -- (int){
			length--;
			breadth--;
		}

};

int main(){
	Rectangle r(4,5);
	r.area();
         
	r++;
	r.area();
	r--;
	r.area();
	return 0;
}

