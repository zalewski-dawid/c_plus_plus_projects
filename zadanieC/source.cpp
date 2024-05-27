//Dawid Zalewski
#include <iostream>
using namespace std;

//1.procedura add
void Add(int a, int* zbior){
    if(a>=1&&a<=4095){
        
        //sprawdzanie czy element juz nie nalezy do zbioru
        int i=0;
        bool koniec=false;
        while(zbior[i]!=-1){
            if(zbior[i] == a){
                koniec=true;
            }
            i++;
        }//koniec while
        //kiedy zbior jest pusty
        if(zbior[0]==-1){
            zbior[0]=a;
            zbior[1]=-1;
            koniec=true;
        }
        if(koniec==false){
        zbior[i]=a;
        bool koniec_sortowania=false;
        
        //teraz sortowanie w porzadku rosnacym
        int s=0;
        while(koniec_sortowania==false){
        int k=s+1;
            while(k<=i){
            //zamiana miejscami
            if(zbior[k]<zbior[s]){
                int temp_array_s=zbior[s];
                zbior[s]=zbior[k];
                zbior[k]=temp_array_s;
            }
            k=k+1;
            }//koniec while zamiana miejscami
            s=s+1;
            if(s==i){
                koniec_sortowania=true;
            }
        }//koniec while
        zbior[i+1]=-1;//przypisanie kolejnemu miejscu wartosci -1
        }
    }//koniec warunku uniwersum
    
}//koniec add


//2.Procedura Create
void Create(int ilosc_elementow, int* array,int* zbior ){
 
 int i=0;
 int e=0;
 int ile_elementow=0;
 bool koniec=false;
 int wykonanie_petli=0;
 while(wykonanie_petli<ilosc_elementow&&koniec==false){
     wykonanie_petli++;
     if(array[i]>=1&&array[i]<=4095){
         
         bool jest=false;
         //sprawdzanie czy juz sie nie powtarza
         int k=0;
         while(k<ile_elementow){
             if(array[i]==zbior[k]){
                 jest=true;
                 
                 break;
             }
             k++;
         }
         if(jest==false){
             
             zbior[e]=array[i];
             
             e++;
             ile_elementow++;
         }
         if(ile_elementow==ilosc_elementow){
             koniec=true;
         }
         
     }
     i++;
 }//koniec while 
  zbior[ile_elementow]=-1;
  if(ile_elementow>1){
       bool koniec_sortowania=false;
        
        //teraz sortowanie w porzadku rosnacym
        int s=0;
        while(koniec_sortowania==false){
        int k=s+1;
            while(zbior[k]!=-1){
            //zamiana miejscami
            if(zbior[k]<zbior[s]){
                int temp_array_s=zbior[s];
                zbior[s]=zbior[k];
                zbior[k]=temp_array_s;
            }
            k=k+1;
            }//koniec while zamiana miejscami
            s=s+1;
            if(s==ile_elementow-1){
                koniec_sortowania=true;
            }
        }//koniec while
  }

}//koniec Create


//3.Procedura Complement
void Complement(int* zbior_dopelniany, int* zbior_dopelniajacy){
    int ilosc_elementow_A=0;
    int i=0;
    bool koniec=false;
    bool koniec_totalny=false;
    while(zbior_dopelniany[i]!=-1){
       
        ilosc_elementow_A++;
        i++;
    }
    if(zbior_dopelniany[0]==-1){
        
        for(int i=0;i<4095;i++){
            zbior_dopelniajacy[i]=i+1;
        }
        zbior_dopelniajacy[4095]=-1;
        koniec_totalny=true; 
    }
    
    if(koniec_totalny==false){
    int ilosc_elementow_B=4095-ilosc_elementow_A;
    
    int u=1;
    zbior_dopelniajacy[0]=u;
    for(int i=0;i<ilosc_elementow_B&&koniec==false;i++){
        
        zbior_dopelniajacy[i]=u;
        //sprawdzanie
        bool jest=false;
        for(int t=0;t<ilosc_elementow_A;t++){
            
            if(zbior_dopelniajacy[i]==zbior_dopelniany[t]){
                jest=true;
                i--;
                break;
            }
        }
        
        u++;
        if(u>4095){
            koniec=true;
        }
    }
    zbior_dopelniajacy[ilosc_elementow_B]=-1;
    
   
   
      }//koniec warunku if koniec_totalny
     
}//koniec Complement

//4.Procedura Union
void Union(int* zbiorA, int* zbiorB, int* zbiorC){
    
    //liczenie ilosci elementow
    int ilosc_elementow_A=0;
    int ilosc_elementow_B=0;
    bool koniec=false;
    if(zbiorA[0]==-1&&zbiorB[0]==-1){
        zbiorC[0]=-1;
        koniec=true;
    }
    if(koniec==false){
    int i=0;
    while(zbiorA[i]!=-1){
        ilosc_elementow_A++;
        i++;
    }
    i=0;
    while(zbiorB[i]!=-1){
        ilosc_elementow_B++;
        i++;
    }
    int dla_zbior_B=ilosc_elementow_A;
    int suma_elementow=ilosc_elementow_A;
    for(int i=0;i<ilosc_elementow_B ;i++){
    bool jest=false;
    
    
    for(int k=0;k<ilosc_elementow_A ;k++){
    if(zbiorB[i]==zbiorA[k]){
       
        jest=true;
        break;
    }
    }
  
    if(jest==false){
        
        suma_elementow++;
        //teraz przypisanie 
        zbiorC[dla_zbior_B]= zbiorB[i];
        dla_zbior_B++;
    }
        
    }
    
    
    for(int i=0;i<ilosc_elementow_A;i++){
        zbiorC[i]=zbiorA[i];
    }
    zbiorC[suma_elementow]=-1;
    
     bool koniec_sortowania=false;
        
        //teraz sortowanie w porzadku rosnacym
        int s=0;
        while(koniec_sortowania==false){
        int k=s+1;
            while(zbiorC[k]!=-1){
            //zamiana miejscami
            if(zbiorC[k]<zbiorC[s]){
                int temp_array_s=zbiorC[s];
                zbiorC[s]=zbiorC[k];
                zbiorC[k]=temp_array_s;
            }
            k=k+1;
            }//koniec while zamiana miejscami
            s=s+1;
            if(s==suma_elementow-1){
                koniec_sortowania=true;
            }
        }//koniec while
    
   
 }
 
 
}//koniec UNION
//5.Procedura Intersection
void Intersection(int* zbiorA, int* zbiorB, int* zbiorC){
    int i=0;
    int e=0;
    int k=0;
    bool koniec=false;
    if(zbiorA[0]==-1||zbiorB[0]==-1){
        zbiorC[0]=-1;
        koniec=true;
    }
    while(zbiorA[i]!=-1&&koniec==false){
        k=0;
        while(zbiorB[k]!=-1){
            if(zbiorA[i]==zbiorB[k]){
                zbiorC[e]=zbiorA[i];
                e++;
            }
            k++;
        }
        i++;
    }
    zbiorC[e]=-1;
    
}//Koniec Intersection
//6.Procedura Difference
void Difference(int* zbiorA,int* zbiorB,int* zbiorC){
    int e=0;
    int i=0;
    bool koniec=false;
    //obydwa puste
    if(zbiorA[0]==-1&&zbiorB[0]==-1){
       
        zbiorC[0]=-1;
        koniec=true;
    }
    //A pusty B nie pusty
    else if(zbiorA[0]==-1&&zbiorB[0]!=-1){
        
        zbiorC[0]=-1;
    koniec=true;    
    }
    //B pusty A nie pusty
    else if(zbiorB[0]==-1&&zbiorA[0]!=-1){
        
        int m=0;
        while(zbiorA[m]!=-1){
            zbiorC[m]=zbiorA[m];
            
            m++;
        }
        zbiorC[m]=-1;
    koniec=true;    
    }
    
    while(zbiorA[i]!=-1&&koniec==false){
        bool jest=false;
        int k=0;
        while(zbiorB[k]!=-1){
            if(zbiorA[i]==zbiorB[k]){
                //jesli element i z zbioru A jest rowny ktoremus z zbior B to :
                jest=true;
                break;
            }
            
            k++;
        }
        if(jest==false){
                zbiorC[e]=zbiorA[i];
                e++;
            }
        i++;
        zbiorC[e]=-1;
    }
    
    
}//koniec Difference

//7.Procedura Symmetric
void Symmetric(int* zbiorA,int* zbiorB,int* zbiorC){
    int ilosc_elementow_A=0;
    int ilosc_elementow_B=0;
    bool koniec=false;
    //liczenie ilosci elementow 
    int i=0;
    while(zbiorA[i]!=-1){
        ilosc_elementow_A++;
        i++;
    }
    i=0;
    while(zbiorB[i]!=-1){
        ilosc_elementow_B++;
        i++;
    }
    i=0;
    int k=0;
    //obydwa sa puste
    if(zbiorA[0]==-1&&zbiorB[0]==-1){
        zbiorC[0]=-1;
        koniec=true;
        
        
    }
    //A ma elementy B jest pusty
    if(zbiorA[0]!=-1&&zbiorB[0]==-1){
        
        int y=0;
        while(zbiorA[y]!=-1){
            zbiorC[y]=zbiorA[y];
            y++;
        }
        zbiorC[y]=-1;
        koniec=true;
       
    }
    
    //A jest puste B ma elementy
    if(zbiorA[0]==-1&&zbiorB[0]!=-1){
         int y=0;
        while(zbiorB[y]!=-1){
            zbiorC[y]=zbiorB[y];
            y++;
        }
        zbiorC[y]=-1;
        koniec=true;
        
    }
    
   
    
    if(koniec==false){
        
    //dodawanie do zbioruC elementow z A ktore nie sa w B
    for(int i=0;i<ilosc_elementow_A;i++){
        bool jest=false;
        for(int j=0;j<ilosc_elementow_B;j++){
            if(zbiorA[i]==zbiorB[j]){
            jest=true;
            break;
            }
        }
        if(jest==false){
            zbiorC[k]=zbiorA[i];
            k++;
            
        }
    }
    
    //dodawanie do zbioruC elementow z B ktore nie sa w A
     for(int i=0;i<ilosc_elementow_B;i++){
        bool jest=false;
        for(int j=0;j<ilosc_elementow_A;j++){
            if(zbiorB[i]==zbiorA[j]){
            jest=true;
            break;
            }
        }
        if(jest==false){
            zbiorC[k]=zbiorB[i];
            k++;
            
        }
    }
     
    if(koniec==false){
    zbiorC[k]=-1;
    }
    
   int suma_elementow=0;
   int h=0;
   while(zbiorC[h]!=-1){
      
       suma_elementow++;
       h++;
   }
   
   if(suma_elementow>1){
    bool koniec_sortowania=false;
        
        //teraz sortowanie w porzadku rosnacym
        int s=0;
        while(koniec_sortowania==false){
        int f=s+1;
            while(zbiorC[f]!=-1){
            //zamiana miejscami
            if(zbiorC[f]<zbiorC[s]){
                int temp_array_s=zbiorC[s];
                zbiorC[s]=zbiorC[f];
                zbiorC[f]=temp_array_s;
            }
            f=f+1;
            }//koniec while zamiana miejscami
            s=s+1;
            if(s==suma_elementow-1){
                koniec_sortowania=true;
            }
        }//koniec while
    }
    }
    
   
    
}//koniec Symmetric



//8.Funkcja logiczna Subset
bool Subset(int* zbiorA, int* zbiorB){
    
    int ilosc_elementow_A=0;
    int ilosc_elementow_B=0;
    //liczenie ilosci elementow 
    int i=0;
    while(zbiorA[i]!=-1){
        ilosc_elementow_A++;
        i++;
    }
    i=0;
    while(zbiorB[i]!=-1){
        ilosc_elementow_B++;
        i++;
    }
    if(ilosc_elementow_A>ilosc_elementow_B){
        return false; //jesli ilosc elementow jest wieksza to zwraca false
    }
    //sprawdzanie zawierania
    
    for(int k=0;k<=ilosc_elementow_A;k++){
    bool znaleziony=false;
    
    for(int j=0;j<=ilosc_elementow_B;j++){
        if(zbiorA[k]==zbiorB[j]){
            znaleziony=true;
            break;
        }
    }//koniec wewnetrznego for
    if(znaleziony==false){
        return false; //jesli nie znaleziono to zwroc false
    }
    }//koniec for
    
   return true; //jesli wszystkie zostaly znalezione to zwroc true
    
}//koniec Subset

//9.Funkcja logiczna Equal
bool Equal(int* zbiorA, int* zbiorB){
    int ilosc_elementow_A=0;
    int ilosc_elementow_B=0;
    
    //jesli sa puste to sa sobie rowne
    if(zbiorA[0]==-1&&zbiorB[0]==-1){
        
        return true;
    }
    //liczenie ilosci elementow 
    int i=0;
    while(zbiorA[i]!=-1){
        ilosc_elementow_A++;
        i++;
    }
    i=0;
    while(zbiorB[i]!=-1){
        ilosc_elementow_B++;
        i++;
    }
    if(ilosc_elementow_A!=ilosc_elementow_B){
       
        return false; //jesli ilosc elementow nie jest taka sama to zwraca false
    }
    
    int ilosc_pokrywajacych_sie=0;
    //porownywanie
    for(int i=0;i<ilosc_elementow_A;i++){
        
        for(int j=0;j<ilosc_elementow_B;j++){
            
            if(zbiorA[i]==zbiorB[j]){
                ilosc_pokrywajacych_sie++;
                break;
            }
            
        }
        
        
        
    }
    
    //sprawdzanie pokrywania sie
    if(ilosc_pokrywajacych_sie==ilosc_elementow_A){
        return true;
       
    }
     
     return false;
    
      
}//Koniec Equal


//10.Funkcja logiczna Empty
bool Empty(int* zbior){
    return (zbior[0]==-1);
} //Koniec Empty
//11.Funkcja logiczna Nonempty
bool Nonempty(int*zbior){
    return(zbior[0]!=-1);
}//Koniec Nonempty

//12.Funkcja logiczna Element
bool Element(int a, int* zbior){
    int i=0;
    
    while(zbior[i]!=-1){
        if(zbior[i]==a){
            return true;
        }
        i++;
    }
    return false;
    }//koniec Element
    
//12.Funkcja Arithmetic typu double

double Arithmetic(int* zbior){
    double suma_elementow=0;
    double ilosc_elementow=0;
    double srednia=0;
    int i=0;
    if(zbior[0]==-1){
        return 0;
    }
    while(zbior[i]!=-1){
        suma_elementow=suma_elementow+zbior[i];
        ilosc_elementow++;
        i++;
    }
    srednia=(suma_elementow/ilosc_elementow);
    return srednia;

}//koniec Arithmetic

//13.Funkcja Harmonic

double Harmonic (int* zbior){
    double ilosc_elementow=0;
    double odwrocona_wartosc=0;
    double suma_odwrocona_wartosc=0;
    
    if(zbior[0]==-1){
        return 1;
    }
    int i=0;
    while(zbior[i]!=-1){
        ilosc_elementow++;
        odwrocona_wartosc= 1.0/zbior[i];
        suma_odwrocona_wartosc=suma_odwrocona_wartosc+odwrocona_wartosc;
        i++;
    }
    
    if(ilosc_elementow==1){
        return zbior[0];
    }
    
    if(ilosc_elementow==2){
        odwrocona_wartosc=1.0/zbior[0];
        suma_odwrocona_wartosc=suma_odwrocona_wartosc+odwrocona_wartosc;
        odwrocona_wartosc=1.0/zbior[1];
        suma_odwrocona_wartosc=suma_odwrocona_wartosc+odwrocona_wartosc;
        return 2/suma_odwrocona_wartosc;
    }
    
    return ilosc_elementow/suma_odwrocona_wartosc;
    
}//koniec Harmonic

//14.Procedura MinMax
void MinMax(int* zbior,int *min,int  &max){
    bool koniec=false;
    int i=0;
    while(zbior[i]!=-1){
        i++;
    }
    if(zbior[0]==-1){
        koniec=true;
        
    }
    if(koniec==false){
    //najpierw sortowanie
     bool koniec_sortowania=false;
        int s=0;
        while(koniec_sortowania==false){
        int k=s+1;
            while(k<i){
            //zamiana miejscami
            if(zbior[k]<zbior[s]){
                int temp_array_s=zbior[s];
                zbior[s]=zbior[k];
                zbior[k]=temp_array_s;
            }
            k=k+1;
            }//koniec while zamiana miejscami
            s=s+1;
            if(s==i){
                koniec_sortowania=true;
            }
        }//koniec while
        
        *min=zbior[0];
        max=zbior[i-1];
         
 }
}//koniec MinMax

//15.Procedura Cardinality

void Cardinality(int* zbior,int* moc){
    int i=0;
    int ilosc_elementow=0;
    while(zbior[i]!=-1){
        ilosc_elementow++;
        i++;
    }
    *moc=ilosc_elementow;//to zadziala rowniez jesli zbior jest pusty, bo nie zadziala while
    
}

//16.Procedura  Properties
void Properties(int* zbior,char znaki[] ,double &srednia,double *harmoniczna,int &min,int *max,int &moc){
    int i=0;
    while(znaki[i]!= '\0'){
        
        if(znaki[i]=='a'){
            bool koniec=false;
            double suma_elementow=0;
    double ilosc_elementow=0;
    srednia=0;
    int i=0;
    if(zbior[0]==-1){
        srednia=0;
        koniec=true;
    }
    if(koniec==false){
    while(zbior[i]!=-1){
        suma_elementow=suma_elementow+zbior[i];
        ilosc_elementow++;
        i++;
    }
    srednia=(suma_elementow/ilosc_elementow);
        }
        }//koniec Aritmetic
        
        else if(znaki[i]=='h'){
            
            double ilosc_elementow=0;
    double odwrocona_wartosc=0;
    double suma_odwrocona_wartosc=0;
    bool koniec=false;
    if(zbior[0]==-1){
        *harmoniczna=1;
        koniec=true;
    }
    int i=0;
    if(koniec==false){
    while(zbior[i]!=-1){
        ilosc_elementow++;
        odwrocona_wartosc= 1.0/zbior[i];
        suma_odwrocona_wartosc=suma_odwrocona_wartosc+odwrocona_wartosc;
        i++;
    }
    
    if(ilosc_elementow==1){
        *harmoniczna= zbior[0];
    }
    
    if(ilosc_elementow==2){
        odwrocona_wartosc=1.0/zbior[0];
        suma_odwrocona_wartosc=suma_odwrocona_wartosc+odwrocona_wartosc;
        odwrocona_wartosc=1.0/zbior[1];
        suma_odwrocona_wartosc=suma_odwrocona_wartosc+odwrocona_wartosc;
        *harmoniczna= 2/suma_odwrocona_wartosc;
    }
    
    *harmoniczna=ilosc_elementow/suma_odwrocona_wartosc;
    }  
        }//koniec Harmonic
        
    else if(znaki[i]=='m'){
           bool koniec=false;
    int i=0;
    while(zbior[i]!=-1){
        i++;
    }
    if(zbior[0]==-1){
        koniec=true;
        
    }
    if(koniec==false){
    //najpierw sortowanie
     bool koniec_sortowania=false;
        int s=0;
        while(koniec_sortowania==false){
        int k=s+1;
            while(k<i){
            //zamiana miejscami
            if(zbior[k]<zbior[s]){
                int temp_array_s=zbior[s];
                zbior[s]=zbior[k];
                zbior[k]=temp_array_s;
            }
            k=k+1;
            }//koniec while zamiana miejscami
            s=s+1;
            if(s==i){
                koniec_sortowania=true;
            }
        }//koniec while
        
        min=zbior[0];
        *max=zbior[i-1];
         
 }
        
    }//koniec MinMax
    
    else if(znaki[i]=='c'){
        
         int i=0;
    int ilosc_elementow=0;
    while(zbior[i]!=-1){
        ilosc_elementow++;
        i++;
    }
    moc=ilosc_elementow;//to zadziala rowniez jesli zbior jest pusty, bo nie zadziala while
    
        
    }
        
        
        
        i++;
    }//koniec While
    
}//koniec Properties
