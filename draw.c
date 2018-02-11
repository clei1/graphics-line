#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int octant = 0;
    
  int A = y1 - y0; int B = x0 - x1;
  printf("A: %d B: %d\n", A, B);
  int x = x0; int y = y0; int d;

  if( A > 0){ // top
    if( A + B > 0 ){ octant = 2; } //means slope is > 1
    else { octant = 1; }
  }
  else{//assuming plot left to right, meaning negative slope is negative change in y
    if ( A < B ){ octant = 7; } //means slope is < -1
    else { octant = 8; }
  }

  printf("slope: %f\n", A * -1.0 / B);
  printf("octant: %d\n", octant);
  
  switch (octant)
    {
    case 1:
      d = 2 * A + B;
      while (x < x1){
	plot(s, c, x, y);
	x ++;
	if (d > 0){
	  y ++;
	  d += 2 * B;
	}
	d += 2 * A;
      } 
      break;
    case 2:
      d = A + 2 * B;
      while (x < x1){
	plot(s, c, x, y);
	y ++;
	if (d < 0){
	  x ++;
	  d += 2 * A;
	}
	d += 2 * B;
      } 
      break;
    case 7:
      d = A - 2 * B;
      while (x < x1){
	plot(s, c, x, y);
	y --;
	if (d > 0){
	  x ++;
	  d += 2 * A;
	}
	d -= 2 * B;
      }
      break;
    case 8:
      d = 2 * A - B;
      while (x < x1){
	plot(s, c, x, y);
	x ++;
	if (d < 0){
	  y --;
	  d -= 2 * B;
	}
	d += 2 * A;
      } 
      break;
    }





}
