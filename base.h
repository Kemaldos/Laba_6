#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

#include <conio.h>
#include <graphics.h>
#include <unistd.h>
#include <stdio.h>

void SortFunction(int NumTableSort,int NumTypeSort);
void DrawTable();
void title();
void Warning();
void DrawScreen();
void button(int x1,int y1,int x2,int y2,int color,char *text);
void button2(int x1,int y1,int x2,int y2,int color,char *text);
void printbuttons(int color1,int color2,int color3,int color4);
void PrintOpenButtons(int c1,int c2,int c3);
void PrintSaveButtons(int c1,int c2);
void PrintSortButton(int c1,int c2,int c3,int c4,int c5);
void PrintTypeSort(int c1,int c2);
void interfaces();
void IshodFile();
void PrintTextFile();           // Function Prototypes
void PrintProizvFile();
void CheckFile();
void PrintIshodFile();
void SaveInFile();

#endif // BASE_H_INCLUDED
