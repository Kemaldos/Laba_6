#include "Base.h"

static int table = 0;
static int proiz;           // with this we check for empty
static int text;

struct group                //  Struct for ProizvFile (group)
{
 char name[20];
 char city[15];
 char money[10];
 int year;
 float height;
};

static struct group proizv[9];         // Array of structs
static struct group tmp;

void CheckFile(){                // Checking files for empty
    FILE *fil1,*fil2;
    fil1 = fopen("2.dat","r");
    fil2 = fopen("1.txt","r");
    fseek(fil1,0,SEEK_END);
    fseek(fil2,0,SEEK_END);
    long pos1=ftell(fil1);
    if(pos1>0) proiz = 1;
    else proiz = 0;
    long pos2=ftell(fil2);
    if(pos2>0) text = 1;
    else text = 0;
    fclose(fil1);
    fclose(fil2);
}

void SortFunction(int NumTableSort,int NumTypeSort){            // This Function Make Sort
    int i,y;
    char *filename1;
    if(table==0)        filename1 = "ishod.txt";                    // if user chose ProizvFile we sorting ProizvFile
    else if(table==1)   filename1 = "2.dat";
    else if(table==2)   filename1 = "1.txt";               // else user chose TextFile we sorting TextFile
    FILE *file1 = fopen(filename1,"r");
    for(i=0;i<9;i++){                                           // Reading File
        fscanf(file1, "%s %s %s %d %f\n", proizv[i].name,
        proizv[i].city,proizv[i].money,&proizv[i].year, &proizv[i].height);
    }
    if(NumTypeSort==1){                                         // if user chose 1 type sort - "Vozrastanie"
        switch(NumTableSort){                                   // We checking which title user chose
            case 1:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(strcmp(proizv[j].name,proizv[i].name) < 0){          // Sorting for STRING or CHAR ( strcmp(); )
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 2:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(strcmp(proizv[j].city,proizv[i].city) < 0){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 3:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(strcmp(proizv[j].money,proizv[i].money) < 0){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 4:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(proizv[j].year < proizv[i].year){       // Sorting For INTEGER or FLOAT
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 5:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(proizv[j].height < proizv[i].height){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
        }
    }else if(NumTypeSort==2){           // if user chose 2 type sort - "Ubivanie"
        switch(NumTableSort){           // We checking which title user chose
            case 1:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(strcmp(proizv[j].name,proizv[i].name) > 0){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 2:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(strcmp(proizv[j].city,proizv[i].city) > 0){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 3:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(strcmp(proizv[j].money,proizv[i].money) > 0){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 4:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(proizv[j].year > proizv[i].year){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;
            case 5:
                for(int i=0;i<10;i++){
                    for(int j=i+1;j<9;j++){
                        if(proizv[j].height > proizv[i].height){
                            tmp = proizv[j];
                            proizv[j] = proizv[i];
                            proizv[i] = tmp;
                        }
                    }
                }break;             // i dont know how to write evething above in short
         }
    }
        DrawTable();                                //  Drawing clean table
        title();
        for(y=60,i=0;i<9;i++,y=y+39){               // Printing Data of File
            char YearStr[10],CostStr[10];
            sprintf(YearStr,"%d",proizv[i].year);
            sprintf(CostStr,"%0.1f",proizv[i].height);
            outtextxy(20,y,proizv[i].name);
            outtextxy(160,y,proizv[i].city);
            outtextxy(290,y,proizv[i].money);
            outtextxy(428,y,YearStr);
            outtextxy(548,y,CostStr);
        }
        interfaces();                       // Return again (recursion)
        fclose(file1);
}

void PrintProizvFile(){                     // Function for Print Proizv File
    if(proiz != 0){              // Check for empty file
    int y,i;
    table = 1;
    DrawTable();
    title();
    struct group labr[9];
    char *filename1 = "2.dat";
    FILE *file1 = fopen(filename1,"r");
    for(y=60,i=0;i<9;i++,y=y+39){
        fscanf(file1, "%s %s %s %d %f\n", labr[i].name,labr[i].city,labr[i].money,&labr[i].year, &labr[i].height);
        char YearStr[10],CostStr[10];
        sprintf(YearStr,"%d",labr[i].year);
        sprintf(CostStr,"%0.1f",labr[i].height);
        outtextxy(20,y,labr[i].name);
        outtextxy(160,y,labr[i].city);
        outtextxy(290,y,labr[i].money);
        outtextxy(428,y,YearStr);
        outtextxy(548,y,CostStr);
    }
    fclose(file1);
    }else {                                 // if empty file
        DrawTable();
        Warning();
        DrawTable();
        interfaces();
    }
}

void PrintTextFile(){                       // Function for Print Text File
    if(text != 0){
    table = 2;
    DrawTable();
    title();
    int y,i;
    struct group labr[9];
    char *filename = "1.txt";
    FILE *file = fopen(filename,"r");
    for(y=60,i=0;i<9;i++,y=y+39){
        fscanf(file, "%s %s %s %d %f\n", labr[i].name,labr[i].city,labr[i].money,&labr[i].year, &labr[i].height);
        char YearStr[10],CostStr[10];
        sprintf(YearStr,"%d",labr[i].year);
        sprintf(CostStr,"%0.1f",labr[i].height);
        outtextxy(20,y,labr[i].name);
        outtextxy(160,y,labr[i].city);
        outtextxy(290,y,labr[i].money);
        outtextxy(428,y,YearStr);
        outtextxy(548,y,CostStr);
    }
    fclose(file);
    }else {                                 // if empty file
        DrawTable();
        Warning();
        DrawTable();
        interfaces();
    }
}

void PrintIshodFile(){                       // Function for Print Text File
    DrawTable();
    title();
    int y,i=0;
    struct group labr[9];
    char *filename = "ishod.txt";
    FILE *file = fopen(filename,"r");
    for(y=60,i=0;i<9;i++,y=y+39){
        fscanf(file, "%s %s %s %d %f\n", labr[i].name,labr[i].city,labr[i].money,&labr[i].year, &labr[i].height);
        char YearStr[10],CostStr[10];
        sprintf(YearStr,"%d",labr[i].year);
        sprintf(CostStr,"%0.1f",labr[i].height);
        outtextxy(20,y,labr[i].name);
        outtextxy(160,y,labr[i].city);
        outtextxy(290,y,labr[i].money);
        outtextxy(428,y,YearStr);
        outtextxy(548,y,CostStr);
    }
    fclose(file);
}

void IshodFile(){
    DrawTable();
    title();
    int y,i=0,table = 0;
    struct group labr[9];
    char *filename = "ishod.txt";
    FILE *file = fopen(filename,"r");
    for(y=60,i=0;i<9;i++,y=y+39){
        fscanf(file, "%s %s %s %d %f\n", labr[i].name,labr[i].city,labr[i].money,&labr[i].year, &labr[i].height);
        char YearStr[10],CostStr[10];
        sprintf(YearStr,"%d",labr[i].year);
        sprintf(CostStr,"%0.1f",labr[i].height);
        outtextxy(20,y,labr[i].name);
        outtextxy(160,y,labr[i].city);
        outtextxy(290,y,labr[i].money);
        outtextxy(428,y,YearStr);
        outtextxy(548,y,CostStr);
    }
    fclose(file);
    interfaces();
}

void SaveInFile(){
    void *buffer2;
    unsigned size2;
    size2 = imagesize(199,314,351,416);
    buffer2 = malloc(size2);
    getimage(199,314,351,416,buffer2);
    PrintSaveButtons(15,15);
    int nsv=1;
    char chsv=0;
    while(chsv != 13){
        chsv = getch();
        switch(chsv){                               // User selects subbuttons "Save"
            case 72: switch(nsv){
                        case 1: PrintSaveButtons(15,10); nsv=2; break;
                        case 2: PrintSaveButtons(10,15); nsv=1; break;
                        }break;
            case 80: switch(nsv){
                        case 1: PrintSaveButtons(15,10); nsv=2; break;
                        case 2: PrintSaveButtons(10,15); nsv=1; break;
                        }break;
        }if(chsv == 27) break;
      }
    if(chsv==27){
        putimage(199,314,buffer2,COPY_PUT);
        free(buffer2);
        interfaces();
    }
    char *filename1;
    if(nsv==1)       {filename1 = "2.dat"; proiz = 1;}           // if user chose ProizvFile we sorting ProizvFile
    else if(nsv==2)  {filename1 = "1.txt"; text = 1;}           // else user chose TextFile we sorting TextFile
    int i;
    FILE *file1 = fopen(filename1,"w");
    for(i=0;i<9;i++){
        fwrite(&proizv[i],sizeof(struct group),1,file1);        // We Write in File
    }
    fclose(file1);
    putimage(199,314,buffer2,COPY_PUT);             // We return area
    free(buffer2);
    interfaces();
}
