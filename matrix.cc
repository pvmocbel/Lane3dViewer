#include<iostream>
#include<math.h>

#define PI 3.14159265

using namespace std;

int main()
{
   float m[3][3];
   for(int i = 0; i<3; i++)
      for(int j=0; j<3; j++)
	 m[i][j]=0.0;
      
   float in[3] = {0,0,-50};
   float out[3] = {0,0,0};
   
   float rad = 180.0, co = 0, si = 0, ang = 0;
   ang = rad*PI/180;
   co = cos(ang);
   si = sin(ang);
   //---------LINHA-1---------//
   m[0][0] = co;
   m[0][1] = -si;
   m[0][2] = si;
   //---------LINHA-2---------//
   m[1][0] = si;
   m[1][1] = co;
   m[1][2] = -si;
   //---------LINHA-3---------//
   m[2][0] = -si;
   m[2][1] = si;
   m[2][2] = co;
   
   out[0] = m[0][0]*in[0] + m[0][1]*in[1] + m[0][2]*in[2];
   out[1] = m[1][0]*in[0] + m[1][1]*in[1] + m[1][2]*in[2];
   out[2] = m[2][0]*in[0] + m[2][1]*in[1] + m[2][2]*in[2];
   
   for(int i = 0; i<3; i++)
      cout<<"out["<<i<<"] = "<<out[i]<<"\t";
   cout<<endl;
   
   return 0;
}