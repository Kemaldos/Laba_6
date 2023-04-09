#include "Base.h"

void DrawScreen(){                      //  Drawing Screen
    int graphdriver = DETECT, graphmode;
    initgraph(&graphdriver, &graphmode,"");
    setfillstyle(1,3);                  // Drawing Back-Ground
    bar(0,0,640,480);
    DrawTable();
    printbuttons(11,15,15,15);          // Drawing buttons
}

void DrawTable(){                      // Function for clean table
    int i;
    setfillstyle(1,3);              // Drawing Back-Ground
    setcolor(15);
    bar(0,0,630,415);
    bar(150,410,200,430);
    setlinestyle(0,1,2);            // Drawing a table
    rectangle(10,10,630,400);
    for(i=134;i<600;i=i+124){       // Vertical lines
        line(i,10,i,400);
    }
    for(i=49;i<390;i=i+39){         // Gorizontal lines
        line(10,i,630,i);
    }
}

void title(){                  // Titles for groups
    setbkcolor(3);
    setcolor(15);
    outtextxy(53,20,"NAME");
    outtextxy(180,20,"CITY");
    outtextxy(295,20,"MONEY");
    outtextxy(427,20,"DATA");
    outtextxy(545,20,"HEIGHT");
}

void Warning(){
    readimagefile("winda.gif",150,30,450,450);
    delay(2000);
}

void button(int x1,int y1,int x2,int y2,int color,char *text){      // Function for Drawing button
    setfillstyle(1,color);
    setlinestyle(0,1,3);
    setcolor(13);
    bar(x1,y1,x2,y2);
    rectangle(x1,y1,x2,y2);
    setbkcolor(color);
    setcolor(0);
    outtextxy(x1+30,y1+17,text);
}
void button2(int x1,int y1,int x2,int y2,int color,char *text){     // Function for Drawing other type button
    setfillstyle(1,color);
    setlinestyle(0,1,3);
    setcolor(13);
    bar(x1,y1,x2,y2);
    rectangle(x1,y1,x2,y2);
    setbkcolor(color);
    setcolor(0);
    outtextxy(x1+45,y1+5,text);
}

void printbuttons(int color1,int color2,int color3,int color4){     // Drawing 4 start button(open,save,sort,exit)
    button(50,415,150,465,color1,"Open");
    button(200,415,300,465,color2,"Save");
    button(345,415,445,465,color3,"Sort");
    button(490,415,590,465,color4,"Exit");
}

void PrintOpenButtons(int c1,int c2,int c3){                    // Drawing subbuttons of "Open" button
    button(50,265,200,315,c1,"Proizvolnyi File");
    button(50,315,200,365,c2,"Textovyi File");
    button(50,365,200,415,c3,"Ishodnyi File");
}

void PrintSaveButtons(int c1,int c2){                       //  Drawing subbuttons of "Save" button
    button(200,315,350,365,c1,"Proizvolnyi File");
    button(200,365,350,415,c2,"Textovyi File");
}

void PrintSortButton(int c1,int c2,int c3,int c4,int c5){   // Drawing subbuttons of "Sort" button
    button2(345,290,445,315,c1,"1");
    button2(345,315,445,340,c2,"2");
    button2(345,340,445,365,c3,"3");
    button2(345,365,445,390,c4,"4");
    button2(345,390,445,415,c5,"5");
}

void PrintTypeSort(int c1,int c2){                          // Drawing subbuttons of subbuttons of "Sort" button
    button2(445,325,570,350,c1,"Vozrastanie");
    button2(445,350,570,375,c2,"Ubivanie");
}

void interfaces(){                // Main function
    CheckFile();
    printbuttons(11,15,15,15);
    char ch=1;
    int nb=1;
    while(ch != 13){
        ch = getch();
        switch(ch){               // User selects Button
        case 77: if(nb==1){
                    printbuttons(15,11,15,15);
                    nb++;}
                  else if(nb==2){
                    printbuttons(15,15,11,15);
                    nb++;}
                  else if(nb==3){
                    printbuttons(15,15,15,11);
                    nb=4;}
                  else if(nb==4){
                    printbuttons(11,15,15,15);
                    nb=1;}
                  break;
        case 75:  if(nb==1){
                    printbuttons(15,15,15,11);
                    nb=4;}
                  else if(nb==2){
                    printbuttons(11,15,15,15);
                    nb--;}
                  else if(nb==3){
                    printbuttons(15,11,15,15);
                    nb--;}
                  else if(nb==4){
                    printbuttons(15,15,11,15);
                    nb--;}
                  break;
        }
    }

    if(nb==1){                          // if User chose "Open"
        void *buffer1;
        unsigned size1;
        size1 = imagesize(49,264,201,416);          // We save area
        buffer1 = malloc(size1);
        getimage(49,264,201,416,buffer1);

        PrintOpenButtons(15,15,15);
        int no=1;
        char cho=0;
        cho = getch();
        while(cho != 13){
            cho = getch();
            switch(cho){                        // User selects subbuttons of "Open"
                case 72: switch(no){
                            case 1: PrintOpenButtons(15,15,10); no=3; break;
                            case 2: PrintOpenButtons(10,15,15); no=1; break;
                            case 3: PrintOpenButtons(15,10,15); no=2; break;
                            }break;
                case 80: switch(no){
                            case 1: PrintOpenButtons(15,10,15); no=2; break;
                            case 2: PrintOpenButtons(15,15,10); no=3; break;
                            case 3: PrintOpenButtons(10,15,15); no=1; break;
                            }break;
            }
            if(cho == 27) break;
        }
        if(cho==27){                            // if User press Esc, we return again
            putimage(49,264,buffer1,COPY_PUT);
            free(buffer1);
            interfaces();
            }

        if(no==1){                              // if User chose "Proizv File" button
            PrintProizvFile();
            interfaces();
        }
        else if(no==2){                         // if User chose "Text File" button
            PrintTextFile();
            interfaces();
        }
        else if(no==3){                         // if User chose "Ishod File" button
                IshodFile();
            }
        }

    else if(nb==2){                     // if User chose "Save"
        SaveInFile();
    }
    else if(nb==3){                     // if User chose "Sort"
        void *buffer3;
        unsigned size3;
        size3 = imagesize(344,289,571,416);
        buffer3 = malloc(size3);
        getimage(344,289,571,416,buffer3);
        PrintSortButton(15,15,15,15,15);
        int ns=1;
        char chs=0;
        while(chs != 13){
        chs = getch();
        switch(chs){                                // User selects subbuttons of "Sort"
            case 72: switch(ns){
                        case 1: PrintSortButton(15,15,15,15,10); ns=5; break;
                        case 2: PrintSortButton(10,15,15,15,15); ns=1; break;
                        case 3: PrintSortButton(15,10,15,15,15); ns=2; break;
                        case 4: PrintSortButton(15,15,10,15,15); ns=3; break;
                        case 5: PrintSortButton(15,15,15,10,15); ns=4; break;
                        }break;
            case 80: switch(ns){
                        case 1: PrintSortButton(15,10,15,15,15); ns=2; break;
                        case 2: PrintSortButton(15,15,10,15,15); ns=3; break;
                        case 3: PrintSortButton(15,15,15,10,15); ns=4; break;
                        case 4: PrintSortButton(15,15,15,15,10); ns=5; break;
                        case 5: PrintSortButton(10,15,15,15,15); ns=1; break;
                        }break;
            }if(chs==27) break;
        }
        if(chs==27){
            putimage(344,289,buffer3,COPY_PUT);
            free(buffer3);
            interfaces();
        }
        PrintTypeSort(13,15);
        int nstp=1;
        char chstp=0;
        while(chstp != 13){
        chstp = getch();
        switch(chstp){                          // User selects "Vosrastanie" or "Ubivanie"
            case 72: switch(nstp){
                        case 1: PrintTypeSort(15,13); nstp=2; break;
                        case 2: PrintTypeSort(13,15); nstp=1; break;
                        }break;
            case 80: switch(nstp){
                        case 1: PrintTypeSort(15,13); nstp=2; break;
                        case 2: PrintTypeSort(13,15); nstp=1; break;
                        }break;
            }if(chstp==27) break;
        }

        if(chstp==27){
            putimage(344,289,buffer3,COPY_PUT);
            free(buffer3);
            interfaces();
            }
        SortFunction(ns,nstp);
    }
    else if(nb==4) { closegraph(); }                  // if User chose "Exit" we return to main() and close graph
}
