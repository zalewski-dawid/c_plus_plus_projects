//Dawid Zalewski
#include <iostream>
using namespace std;
int main() {
    int ile_sesji;
    int n=0;
    cin>>ile_sesji;
    //petla do sesji
    while( n<ile_sesji){
        int index=0;
        int dlugosc;
        cin>>dlugosc;
        int array[dlugosc];
        //petla do wczytywania danych do tablicy
        int w=0;
        
        while(w<dlugosc){
            cin>>array[w];
            w=w+1;
        }
       w=0;
       while(w<dlugosc){
           cout<<array[w]<<" ";
           w=w+1;
       }
        cout<<endl;
        char operacja;
        bool koniec_operacji=false;
        //petla do wpisywania operacji
        while(koniec_operacji==false){
                int zadana_dlugosc;
                int start_index;
                int shift;
            cin>>operacja;
            //1.odwracanie 
            if(operacja=='R'){
                
                cin>>start_index>>zadana_dlugosc;
                
                int temp_start;
                int temp_koniec;
                int ostateczny_index=start_index+dlugosc;
                int value;
                bool czy_sie_zmiesci=true;
               if(zadana_dlugosc==0||zadana_dlugosc==1){
                   czy_sie_zmiesci=false;
                   
               }
                if(zadana_dlugosc>dlugosc){
                    czy_sie_zmiesci=false;
                    
                }
                
                
                         //warunek cyklicznosci
               
                    //odwracanie w podanym fragmencie
                    temp_start=start_index;//start fragmentu
                    temp_koniec=start_index+zadana_dlugosc-1;//koniec fragmentu
                    int kolejny_start_index=start_index+zadana_dlugosc;
                   
                
                    while(czy_sie_zmiesci==true){
                        
                        
                    int index_poczatek=temp_start;
                    int index_koniec=temp_koniec;
                    if(temp_start==dlugosc){
                        index_poczatek=0;
                    }
                    
                    if(temp_koniec==-1){
                        index_koniec=dlugosc-1;
                    }
                   
                    //warunek cyklicznosci
                    if(index_poczatek<0||index_poczatek>dlugosc-1){
                    index_poczatek=(index_poczatek%dlugosc + dlugosc)%dlugosc;
                    }
                    //warunek cyklicznosci
                    if(index_koniec<0||index_koniec>dlugosc-1){
                    index_koniec=(index_koniec%dlugosc + dlugosc)%dlugosc;
                    }
                    //odwracanie
                    int value;
                    value=array[index_poczatek];
                    array[index_poczatek]=array[index_koniec];
                    array[index_koniec]=value;
                    
                    temp_start=temp_start+1;
                     temp_koniec=temp_koniec-1;
                    
                    
                    //jesli temp_start==temp_koniec na nowo definiujemy kolejny fragment
                    
                    if(temp_start==temp_koniec||temp_start>temp_koniec){
                       
                       temp_start=kolejny_start_index;
                       
                        temp_koniec=temp_start+zadana_dlugosc-1;
                      
                        kolejny_start_index=kolejny_start_index+zadana_dlugosc;
                      
                
                    }//koniec temp_start==temp_koniec
                     
                       if(temp_koniec>=ostateczny_index){
                           czy_sie_zmiesci=false;
                       }
                    
                    
                    }//czy_sie_zmiesci
                    
                  
          

                
            }   //koniec R
            
            
            
            
            
            
            
            //2.Przesuniecie
            if(operacja=='M'){
                int shift;
                cin>>start_index>>zadana_dlugosc>>shift;
                int true_koniec=start_index+zadana_dlugosc-1;
                int thc=start_index;
                int real_start_index=start_index;
                bool rosnace=true;
                bool koniec_ostateczny=false;
                bool koniec_przesuniecia=false;
                int definitywny_koniec_index=real_start_index+dlugosc;
                if(shift<0){
                    rosnace=false;
                    shift=shift*-1;
                }
                if(zadana_dlugosc==0||zadana_dlugosc==1){
                    koniec_przesuniecia=true;
                }
                //przesuniecie w prawo rosnace indeksy
                if(zadana_dlugosc>dlugosc){
                    koniec_przesuniecia=true;
                }
               
                if(rosnace==true){
                  
                    int t=0;
                    
                    while(koniec_przesuniecia==false){
                        
                    while(t<shift&&koniec_przesuniecia==false){
                        int temp_true_koniec=true_koniec;
                         int temp_true_poczatek=start_index;
                        int y=0;
                        //warunek cyklicznosci
                    if(temp_true_poczatek<0||temp_true_poczatek>dlugosc-1){
                    temp_true_poczatek=(temp_true_poczatek%dlugosc + dlugosc)%dlugosc;
                    }
                     if(temp_true_koniec<0||temp_true_koniec>dlugosc-1){
                    temp_true_koniec=(temp_true_koniec%dlugosc + dlugosc)%dlugosc;
                    }
                        int temp=array[temp_true_koniec];
                       
                        
                        
                        while(y<zadana_dlugosc-1){
                            
                        int p=start_index+zadana_dlugosc-y-1;
                        int q=start_index+zadana_dlugosc-y-2;
                        //warunek cyklicznosci
                   
                        if(q==dlugosc){
                        q=0;
                    }
                    
                    
                    
                    if(q==-1){
                        q=dlugosc-1;
                    }
                     if(p==dlugosc){
                        p=0;
                    }
                    
                    
                    
                    if(p==-1){
                        p=dlugosc-1;
                    }
                        
                        //warunek cyklicznosci
                    if(p<0||p>dlugosc-1){
                    p=(p%dlugosc + dlugosc)%dlugosc;
                    }
                     if(q<0||q>dlugosc-1){
                   q=(q%dlugosc + dlugosc)%dlugosc;
                    }
                        
                        
                        
                        array[p]=array[q];
                        y=y+1;
                        }
                        
                       
                         array[temp_true_poczatek]=temp;
                       
                        
                        
                       
                        t=t+1;
                    }
                   
                        if(koniec_ostateczny==true){
                            koniec_przesuniecia=true;
                        }
                        
                    //wyznaczanie nowego fragmentu
                    
                    if(t==shift&&koniec_ostateczny==false){
                        t=0;
                         start_index=start_index+zadana_dlugosc;
                         true_koniec=start_index+zadana_dlugosc-1;
   
   
                        //jesli nowy fragment jest krotszy niz zadana dlugosc tez podlega przesunieciu
                        
                        //jesli wykracza to wyznaczamy nowy
                    //sprawdzanie 
                    if(start_index>=definitywny_koniec_index||start_index==definitywny_koniec_index-1){
                        koniec_przesuniecia=true;
                    }
                    if(true_koniec>=definitywny_koniec_index){
                        koniec_ostateczny=true;
                        true_koniec=definitywny_koniec_index-1;
                        zadana_dlugosc=definitywny_koniec_index-start_index;
                        
                    } 
                       if(zadana_dlugosc==0||zadana_dlugosc==1){
                        koniec_przesuniecia=true;
                    }   
                        
                    }//koniec wyznaczanie nowego fragmentu
                        
                    }//koniec while
                  
                    
                }//koniec rosnace==true
                
                
                
                
                
                
                
                
                
                //przesuniecie w lewo malejace indeksy
                if(rosnace==false){
                    
                    int t=0;
                    
                    while(koniec_przesuniecia==false){
                    while(t<shift&&koniec_przesuniecia==false){
                        int temp_true_koniec=true_koniec;
                         int temp_true_poczatek=start_index;
                        int y=0;
                        //warunek cyklicznosci
                    if(temp_true_poczatek<0||temp_true_poczatek>dlugosc-1){
                    temp_true_poczatek=(temp_true_poczatek%dlugosc + dlugosc)%dlugosc;
                    }
                        int temp=array[temp_true_poczatek];
                        
                        while(y<zadana_dlugosc-1){
                            
                        int p=start_index+y;
                        int q=start_index+y+1;
                        //warunek cyklicznosci
                    if(temp_true_koniec<0||temp_true_koniec>dlugosc-1){
                    temp_true_koniec=(temp_true_koniec%dlugosc + dlugosc)%dlugosc;
                    }
                        if(q==dlugosc){
                        q=0;
                    }
                    
                    
                    
                    if(q==-1){
                        q=dlugosc-1;
                    }
                     if(p==dlugosc){
                        p=0;
                    }
                    
                    
                    
                    if(p==-1){
                        p=dlugosc-1;
                    }
                        
                        //warunek cyklicznosci
                    if(p<0||p>dlugosc-1){
                    p=(p%dlugosc + dlugosc)%dlugosc;
                    }
                     if(q<0||q>dlugosc-1){
                   q=(q%dlugosc + dlugosc)%dlugosc;
                    }
                        
                        
                        
                        array[p]=array[q];
                        y=y+1;
                        }
                        
                         array[temp_true_koniec]=temp;
                       
                        
                        
                       
                        t=t+1;
                    }
                   
                        if(koniec_ostateczny==true){
                            koniec_przesuniecia=true;
                        }
                        
                    //wyznaczanie nowego fragmentu
                    if(t==shift&&koniec_ostateczny==false){
                        t=0;
                         start_index=start_index+zadana_dlugosc;
                         true_koniec=start_index+zadana_dlugosc-1;
   
   
                        //jesli nowy fragment jest krotszy niz zadana dlugosc tez podlega przesunieciu
                        
                        //jesli wykracza to wyznaczamy nowy
                    //sprawdzanie 
                     if(start_index>=definitywny_koniec_index||start_index==definitywny_koniec_index-1){
                        koniec_przesuniecia=true;
                    }
                    if(true_koniec>=definitywny_koniec_index){
                        koniec_ostateczny=true;
                        true_koniec=definitywny_koniec_index-1;
                        zadana_dlugosc=definitywny_koniec_index-start_index;
                        
                    }
                    if(zadana_dlugosc==0||zadana_dlugosc==1){
                        koniec_przesuniecia=true;
                    } 
         
                    }//koniec wyznaczanie nowego fragmentu
                        
                    }//koniec while
                  
                    
                }//koniec rosnace==false
                
              
         
                
                
            }//koniec M
                    
            
            //3.Zamiana parami
            if(operacja=='C'){
                cin>>start_index>>zadana_dlugosc;
                
                
                int maks_temp_start1=start_index-(zadana_dlugosc*2);
                //warunek cyklicznosci
                    if(maks_temp_start1<0||maks_temp_start1>dlugosc-1){
                    maks_temp_start1=(maks_temp_start1%dlugosc + dlugosc)%dlugosc;
                    }
                int temp_start1=start_index;
                int temp_start2=start_index+zadana_dlugosc;
                int koniec_fragmentu1=temp_start1+zadana_dlugosc-1;
                int koniec_fragmentu2=temp_start2+zadana_dlugosc-1;
                int next_start=koniec_fragmentu2+1;
                int wartosc1_index;
                int wartosc2_index;
                float test=dlugosc;
                int ostatni_start=start_index+dlugosc;
                if(zadana_dlugosc==1){
                    koniec_fragmentu1=temp_start1;
                    koniec_fragmentu2=temp_start2;
                }
                
                
                bool koniec=false;
                if((test/2)<zadana_dlugosc){
                    koniec=true;
                }
                if(zadana_dlugosc==0){
                    koniec=true;
                }
                
                //zamiana w obrebie fragmentu
                while(koniec==false){
                    
                    
                    
                    if(temp_start1==dlugosc){
                        wartosc1_index=0;
                    }
                    
                    
                    
                    if(temp_start1==-1){
                        wartosc1_index=dlugosc-1;
                    }
                     if(temp_start2==dlugosc){
                        wartosc2_index=0;
                    }
                    
                    
                    
                    if(temp_start2==-1){
                        wartosc2_index=dlugosc-1;
                    }
                    
                    
                    

                    wartosc1_index=temp_start1;
                    wartosc2_index=temp_start2;
                    
                    
                    //warunek cyklicznosci
                    if(temp_start1<0||temp_start1>dlugosc-1){
                     wartosc1_index=(temp_start1%dlugosc + dlugosc)%dlugosc;
                    }
                    //warunek cyklicznosci
                    if(temp_start2<0||temp_start2>dlugosc-1){
                    wartosc2_index=(temp_start2%dlugosc + dlugosc)%dlugosc;
                    }
                    
                    
                    int wartosc1=array[wartosc1_index];
                    array[wartosc1_index]=array[wartosc2_index];
                    array[wartosc2_index]=wartosc1;
                    temp_start1=temp_start1+1;
                    temp_start2=temp_start2+1;
                    
        
                    
                    //warunek jesli fragment juz sie pozmienia to przyjmujemy kolejny fragment
                    if(temp_start1>koniec_fragmentu1&&temp_start2>koniec_fragmentu2){
                  
                    
                    
                    if(zadana_dlugosc!=1){
                    temp_start1=next_start;
                    koniec_fragmentu1=temp_start1+zadana_dlugosc-1;
                    temp_start2=temp_start1+zadana_dlugosc;
                    koniec_fragmentu2=temp_start2+zadana_dlugosc-1;
                    next_start=koniec_fragmentu2+1;
                    }
                    if(zadana_dlugosc==1){
                        next_start=koniec_fragmentu2+1;
                        
                    
                        temp_start1=next_start;
                        koniec_fragmentu1=temp_start1;
                        temp_start2=koniec_fragmentu1+1;
                        koniec_fragmentu2=temp_start2;
                       
                    }
                    
                  
                    
                    //jezeli pozostaly fragment jest mniejszy od zadanej dlugosci, to reszty juz nie obracamy i konczymy
                //warunek cyklicznosci
                   
                
                if(koniec_fragmentu2>=ostatni_start){
                    
                    koniec=true;
                }
                
                }
                
                
                    
                    
                }//koniec petli while - zamiany w obrebie fragmentu
               
                
                
            }//koniec C
            //4.Sortowanie
            if(operacja=='S'){
                cin>>start_index>>zadana_dlugosc;
                bool koniec_sortowania=false;
                bool koniec_ostateczny=false;
                bool asc;
                if(zadana_dlugosc>0){
                    asc=true;
                }
                if(zadana_dlugosc<0){
                    asc=false;
                }
                
                //wartosc bezwzgledna 
                if(zadana_dlugosc<0){
                    zadana_dlugosc=zadana_dlugosc*-1;
                }
                if(zadana_dlugosc==0||zadana_dlugosc==1){
                    koniec_sortowania=true;
                }
                if(zadana_dlugosc>dlugosc){
                    zadana_dlugosc=dlugosc;
                }
                
                int true_start=start_index;
                int true_koniec=true_start+zadana_dlugosc-1;
                int definitywny_true_koniec=start_index+dlugosc;
                
                //sortowanie w porzadku niemalejacym
                if(asc==true){
                    
                    int p=true_start;
                    
                    
                    
                    while(koniec_sortowania==false){
                        
                        int q=p+1;
                        
                        
                    while(q<=true_koniec){
                            
                            //warunek cyklicznosci
                     int true_q=q;
                     int true_p=p;
                     
                     
                     if(q==dlugosc){
                        true_q=0;
                    }
                    
                    
                    
                    if(q==-1){
                        true_q=dlugosc-1;
                    }
                     if(p==dlugosc){
                        true_p=0;
                    }
                    
                    
                    
                    if(p==-1){
                        true_p=dlugosc-1;
                    }
                     
                     
                     
                    if(true_q<0||true_q>dlugosc-1){
                    true_q=(true_q%dlugosc + dlugosc)%dlugosc;
                    }
                    
                     //warunek cyklicznosci
                    
                    if(true_p<0||true_p>dlugosc-1){
                    true_p=(true_p%dlugosc + dlugosc)%dlugosc;
                    }
                    
                   
                    
                           
                            //zamiana miejscami
                            if( array[true_q]<array[true_p] ){
                                
                                
                                int tymczasowe_true_p=array[true_p];
                                array[true_p]=array[true_q];
                                array[true_q]=tymczasowe_true_p;
                                
                                
                                
                            }
                            
                            
                            q=q+1;
                            
                        }//koniec q<=true_koniec;
                        p=p+1;
                      
                        
                        
                        
                
                        
                        //wyznaczanie nowego fragmentu !!!!!
                        if(p>true_koniec&&koniec_ostateczny==false){
                           
                            p=true_koniec+1;
                            
                            true_koniec=p+zadana_dlugosc-1;
                          
                        
                        //jesli nowy fragment jest krotszy niz zadana dlugosc to tez podlega sortowaniu !!!!
                       
                        //warunek nowego fragmentu krotszego niz zadana dlugosc
                        
                        if(p>=definitywny_true_koniec||p==definitywny_true_koniec-1){
                            koniec_sortowania=true;
                        }
                       if(true_koniec>=definitywny_true_koniec){
                           koniec_ostateczny=true;
                           true_koniec=definitywny_true_koniec-1;
                           zadana_dlugosc=definitywny_true_koniec-p;
                           
                           
                       }
                       if(zadana_dlugosc==0||zadana_dlugosc==1){
                           koniec_sortowania=true;
                       }
                        
                        
                        
                        }//koniec wyznaczenie nowego fragmentu
                        if(p>=definitywny_true_koniec&&koniec_ostateczny==true){
                            koniec_sortowania=true;
                        }
                        
                    }//koniec while
                    
                }//koniec asc==true;
                
                
                if(asc==false){
                    
                    int p=true_start;
                    
                    
                    
                    while(koniec_sortowania==false){
                        
                        int q=p+1;
                        
                        
                    while(q<=true_koniec){
                            
                            //warunek cyklicznosci
                     int true_q=q;
                     int true_p=p;
                     
                     
                     if(q==dlugosc){
                        true_q=0;
                    }
                    
                    
                    
                    if(q==-1){
                        true_q=dlugosc-1;
                    }
                     if(p==dlugosc){
                        true_p=0;
                    }
                    
                    
                    
                    if(p==-1){
                        true_p=dlugosc-1;
                    }
                     
                     
                     
                    if(true_q<0||true_q>dlugosc-1){
                    true_q=(true_q%dlugosc + dlugosc)%dlugosc;
                    }
                    
                     //warunek cyklicznosci
                    
                    if(true_p<0||true_p>dlugosc-1){
                    true_p=(true_p%dlugosc + dlugosc)%dlugosc;
                    }
                   
                    
                           
                            //zamiana miejscami
                            if( array[true_q]>array[true_p] ){
                                int tymczasowe_true_p=array[true_p];
                                array[true_p]=array[true_q];
                                array[true_q]=tymczasowe_true_p;
                                
                                
                            }
                            
                            
                            q=q+1;
                            
                        }//koniec q<=true_koniec;
                        p=p+1;
                       
                        
                        
                        
                        
                        
                        
                        
                        
                        
                        //wyznaczanie nowego fragmentu !!!!!
                        if(p>true_koniec&&koniec_ostateczny==false){
                            
                            p=true_koniec+1;
                            
                            true_koniec=p+zadana_dlugosc-1;
                          
                        
                        //jesli nowy fragment jest krotszy niz zadana dlugosc to tez podlega sortowaniu !!!!
                       
                        //warunek nowego fragmentu krotszego niz zadana dlugosc
                        
                        if(p>=definitywny_true_koniec||p==definitywny_true_koniec-1){
                            koniec_sortowania=true;
                        }
                       if(true_koniec>=definitywny_true_koniec){
                           koniec_ostateczny=true;
                           true_koniec=definitywny_true_koniec-1;
                           zadana_dlugosc=definitywny_true_koniec-p;
                           
                           
                       }
                       if(zadana_dlugosc==0||zadana_dlugosc==1){
                           koniec_sortowania=true;
                       }
                        
                        
                        }//koniec wyznaczenie nowego fragmentu
                        if(p>=definitywny_true_koniec&&koniec_ostateczny==true){
                            koniec_sortowania=true;
                        }
                        
                    }
                    
                }//koniec asc==false;
                
                
               
         
                
                
            }//koniec S
            
            //5.KONIEC OPERACJI !!!
            if(operacja=='F'){
                
                koniec_operacji=true;
                int XD=0;
         while(XD<dlugosc){
             cout<<array[XD]<<" ";
             XD=XD+1;
             
         }
         cout<<endl;
            }
            
            
            
            
            
        }
        
         
        n=n+1;
        }
       
    
    
    return 0;
}
