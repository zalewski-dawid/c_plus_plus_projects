//Dawid Zalewski
#include <iostream>
using namespace std;
int main()
{
    float wygrane_a=0, przegrane_a=0, remisy_a=0;
    float wygrane_b=0, przegrane_b=0, remisy_b=0;
    float wygrane_c=0, przegrane_c=0, remisy_c=0;
    float wygrane_d=0, przegrane_d=0, remisy_d=0;
    float wygrane_e=0, przegrane_e=0, remisy_e=0;
    bool winner=false;
    int liczba_rozgrywek=0;
    int i=0;
    cin>>liczba_rozgrywek;
    while(i<liczba_rozgrywek){
            
            char id1;
            char id2; 
            int rzut1,rzut2,rzut3,rzut4,rzut5,rzut6,rzut7,rzut8;
            int waga_1gracz=0;
            int waga_2gracz=0;
            int gracz1_triple=0;
            int gracz2_triple=0;
            int gracz1_double=0;
            int gracz2_double=0;
            winner=false; 
            
         cin>>id1>>rzut1>>rzut2>>rzut3>>rzut4>>id2>>rzut5>>rzut6>>rzut7>>rzut8;                      
       
           
        
           /*dokladnie 4 jednakowe wyniki*/
           if(rzut1 == rzut2 && rzut2 == rzut3 && rzut3 == rzut4){
               waga_1gracz=5;
           }
           if(rzut5 == rzut6 && rzut6 == rzut7 && rzut7 == rzut8){
               waga_2gracz=5;
           }
            
           /*brak jakichkolwiek powtorzen*/
            if(rzut1!=rzut2&&rzut1!=rzut3&&rzut1!=rzut4&&rzut2!=rzut3&&rzut2!=rzut4&&rzut3!=rzut4){
               waga_1gracz=4;
             
           }
           if(rzut5!=rzut6&&rzut5!=rzut7&&rzut5!=rzut8&&rzut6!=rzut7&&rzut6!=rzut8&&rzut7!=rzut8){
               waga_2gracz=4;
             
           }
           
           /*dwie rozne pary powtorzen*/
            if(rzut1==rzut2&&rzut2!=rzut3&&rzut3==rzut4||rzut1==rzut4&&rzut4!=rzut2&&rzut2==rzut3||rzut1==rzut3&&rzut3!=rzut2&&rzut2==rzut4)
               
               waga_1gracz=3;
            
            if(rzut5==rzut6&&rzut6!=rzut7&&rzut7==rzut8||rzut5==rzut8&&rzut8!=rzut6&&rzut6==rzut7||rzut5==rzut7&&rzut7!=rzut6&&rzut6==rzut8)
               
               waga_2gracz=3;
            
            
           /*dokladnie trzy jednakowe wyniki, 4 wynik rozny od reszty*/
          
                if(rzut1 == rzut2 && rzut2 == rzut3 && rzut3 != rzut4){
                   gracz1_triple=rzut1;
                   waga_1gracz=2;
               }
               if(rzut1 == rzut2 && rzut2 == rzut4 && rzut4 != rzut3){
                   gracz1_triple=rzut1;
                   waga_1gracz=2;
               }
               if(rzut1 == rzut3 && rzut3 == rzut4 && rzut4 != rzut2){
                   gracz1_triple=rzut1;
                   waga_1gracz=2;
                   
               }
               if(rzut2 == rzut3 && rzut3 == rzut4 && rzut4 != rzut1){
                   gracz1_triple=rzut2;
                   waga_1gracz=2;
               }
                
         
         
               if(rzut5 == rzut6 && rzut6 == rzut7 && rzut7 != rzut8){
                   gracz2_triple=rzut5;
                   waga_2gracz=2;
               }
               if(rzut5 == rzut6 && rzut6 == rzut8 && rzut8 != rzut7){
                   gracz2_triple=rzut5;
                   waga_2gracz=2;
               }
               if(rzut5 == rzut7 && rzut7 == rzut8 && rzut8 != rzut6){
                   gracz2_triple=rzut5;
                   waga_2gracz=2;
                   
               }
               if(rzut6 == rzut7 && rzut7 == rzut8 && rzut8 != rzut5){
                   gracz2_triple=rzut6;
                   waga_2gracz=2;
               }
         
        
        
           /*dokladnie dwa jednakowe wyniki*/
                
            if(rzut1==rzut2&&rzut2!=rzut3&&rzut2!=rzut4&&rzut3!=rzut4){
               waga_1gracz=1;
               gracz1_double=rzut2;
               
           }
           if(rzut2==rzut3&&rzut3!=rzut1&&rzut3!=rzut4&&rzut3!=rzut4){
               waga_1gracz=1;
               gracz1_double=rzut2;
           }
           if(rzut2==rzut4&&rzut4!=rzut1&&rzut4!=rzut3&&rzut3!=rzut1){
               waga_1gracz=1;
               gracz1_double=rzut2;
           }
           if(rzut1==rzut4&&rzut4!=rzut2&&rzut4!=rzut3&&rzut3!=rzut2){
               waga_1gracz=1;
               gracz1_double=rzut1;
               
           }
           if(rzut3==rzut4&&rzut4!=rzut1&&rzut4!=rzut2&&rzut1!=rzut2){
                waga_1gracz=1;
                gracz1_double=rzut3;
           }
           if(rzut1==rzut3&&rzut3!=rzut2&&rzut3!=rzut4&&rzut2!=rzut4){
               waga_1gracz=1;
               gracz1_double=rzut1;
           }
           
           
           //dla drugiego gracza 
           
           
           if(rzut5==rzut6&&rzut6!=rzut7&&rzut6!=rzut8&&rzut7!=rzut8){
               waga_2gracz=1;
               gracz2_double=rzut6;
               
           }
           if(rzut6==rzut7&&rzut7!=rzut5&&rzut7!=rzut8&&rzut7!=rzut8){
               waga_2gracz=1;
               gracz2_double=rzut6;
           }
           if(rzut6==rzut8&&rzut8!=rzut5&&rzut8!=rzut7&&rzut7!=rzut5){
              waga_2gracz=1;
               gracz2_double=rzut6;
           }
           if(rzut5==rzut8&&rzut8!=rzut6&&rzut8!=rzut7&&rzut7!=rzut6){
               waga_2gracz=1;
               gracz2_double=rzut5;
               
           }
           if(rzut7==rzut8&&rzut8!=rzut5&&rzut8!=rzut6&&rzut5!=rzut6){
                waga_2gracz=1;
                gracz2_double=rzut7;
           }
           if(rzut5==rzut7&&rzut7!=rzut6&&rzut7!=rzut8&&rzut6!=rzut8){
               waga_2gracz=1;
               gracz2_double=rzut5;
           }
           
            //przydzielanie punktow wedlug normalnej hierarchi
           if(waga_1gracz>waga_2gracz){
               winner=true;
               if(id1=='a')
                   wygrane_a++;
               
               if(id1=='b')
                   wygrane_b++;
               
               if(id1=='c')
                   wygrane_c++;
               
               if(id1=='d')
                   wygrane_d++;
               
               if(id1=='e')
                   wygrane_e++;
               
               
               //
               if(id2=='a')
                   przegrane_a++;
               
               if(id2=='b')
                   przegrane_b++;
               
               if(id2=='c')
                   przegrane_c++;
               
               if(id2=='d')
                   przegrane_d++;
               
               if(id2=='e')
                   przegrane_e++;
               
           }
           
           else if(waga_1gracz<waga_2gracz){
               winner=true;
               if(id1=='a')
                   przegrane_a++;
               
               if(id1=='b')
                   przegrane_b++;
               
               if(id1=='c')
                   przegrane_c++;
               
               if(id1=='d')
                   przegrane_d++;
               
               if(id1=='e')
                   przegrane_e++;
               
                if(id2=='a')
                   wygrane_a++;
               
               if(id2=='b')
                   wygrane_b++;
               
               if(id2=='c')
                   wygrane_c++;
               
               if(id2=='d')
                   wygrane_d++;
               
               if(id2=='e')
                   wygrane_e++;
               
           }
           
           //teraz powtorzenia gdy 1 i 2 gracz ma ta sama wage 
           
           //brak jakichkolwiek powtorzen u obu graczy
           
           if(waga_1gracz==waga_2gracz&&waga_2gracz==4){
               
               
               if((rzut1+rzut2+rzut3+rzut4)==(rzut5+rzut6+rzut7+rzut8)){
                   winner=true;
                    if(id1=='a')
                  remisy_a++;
               
               if(id1=='b')
                   remisy_b++;
               
               if(id1=='c')
                  remisy_c++;
               
               if(id1=='d')
                  remisy_d++;
               
               if(id1=='e')
                   remisy_e++;
               
               
               //
               if(id2=='a')
                   remisy_a++;
               
               if(id2=='b')
                   remisy_b++;
               
               if(id2=='c')
                   remisy_c++;
               
               if(id2=='d')
                  remisy_d++;
               
               if(id2=='e')
                  remisy_e++;
               
                   
               }
               
           }
           //uklady czworek,trojek lub dokladnie dwoch takich samych wynikow 
           
           //uklady czworek
           if(waga_1gracz==waga_2gracz&&waga_2gracz==5){
               if(rzut1>rzut5){
                   winner=true;
                   if(id1=='a')
                   wygrane_a++;
               
               if(id1=='b')
                   wygrane_b++;
               
               if(id1=='c')
                   wygrane_c++;
               
               if(id1=='d')
                   wygrane_d++;
               
               if(id1=='e')
                   wygrane_e++;
               
               
               //
               if(id2=='a')
                   przegrane_a++;
               
               if(id2=='b')
                   przegrane_b++;
               
               if(id2=='c')
                   przegrane_c++;
               
               if(id2=='d')
                   przegrane_d++;
               
               if(id2=='e')
                   przegrane_e++;
               
               }
           
               
               
               else if(rzut1<rzut5){
                   winner=true;
                   if(id1=='a')
                   przegrane_a++;
               
               if(id1=='b')
                   przegrane_b++;
               
               if(id1=='c')
                   przegrane_c++;
               
               if(id1=='d')
                   przegrane_d++;
               
               if(id1=='e')
                   przegrane_e++;
               
                if(id2=='a')
                   wygrane_a++;
               
               if(id2=='b')
                   wygrane_b++;
               
               if(id2=='c')
                   wygrane_c++;
               
               if(id2=='d')
                   wygrane_d++;
               
               if(id2=='e')
                   wygrane_e++;
               
               }
               else if(rzut1==rzut5){
                   winner=true;
                   if(id1=='a')
                   remisy_a++;
               
               if(id1=='b')
                   remisy_b++;
               
               if(id1=='c')
                   remisy_c++;
               
               if(id1=='d')
                   remisy_d++;
               
               if(id1=='e')
                   remisy_e++;
               
                if(id2=='a')
                   remisy_a++;
               
               if(id2=='b')
                   remisy_b++;
               
               if(id2=='c')
                   remisy_c++;
               
               if(id2=='d')
                   remisy_d++;
               
               if(id2=='e')
                   remisy_e++;
               
               }
           }//////
               //uklady trojek
               if(waga_1gracz==waga_2gracz&&waga_2gracz==2) {
                   
                 if(gracz1_triple>gracz2_triple){
                   winner=true;
                   
                if(id1=='a')
                 wygrane_a++;
               
               if(id1=='b')
                   wygrane_b++;
               
               if(id1=='c')
                   wygrane_c++;
               
               if(id1=='d')
                   wygrane_d++;
               
               if(id1=='e')
                   wygrane_e++;
               
               
               //
               if(id2=='a')
                   przegrane_a++;
               
               if(id2=='b')
                   przegrane_b++;
               
               if(id2=='c')
                   przegrane_c++;
               
               if(id2=='d')
                   przegrane_d++;
               
               if(id2=='e')
                   przegrane_e++;
               
               }
              
                else if(gracz1_triple<gracz2_triple){
                   winner=true;
                   if(id1=='a')
                   przegrane_a++;
               
               if(id1=='b')
                   przegrane_b++;
               
               if(id1=='c')
                   przegrane_c++;
               
               if(id1=='d')
                   przegrane_d++;
               
               if(id1=='e')
                   przegrane_e++;
               
                if(id2=='a')
                   wygrane_a++;
               
               if(id2=='b')
                   wygrane_b++;
               
               if(id2=='c')
                   wygrane_c++;
               
               if(id2=='d')
                   wygrane_d++;
               
               if(id2=='e')
                   wygrane_e++;
              
               }
               }
           //uklady dokladnie dwoch takich samych wynikow 
         if(waga_1gracz==waga_2gracz&&waga_2gracz==1){
               
              
           if (gracz1_double>gracz2_double){
               winner=true;
               
                   if(id1=='a')
                   wygrane_a++;
               
               if(id1=='b')
                   wygrane_b++;
               
               if(id1=='c')
                   wygrane_c++;
               
               if(id1=='d')
                   wygrane_d++;
               
               if(id1=='e')
                   wygrane_e++;
               
               
               //
               if(id2=='a')
                   przegrane_a++;
               
               if(id2=='b')
                   przegrane_b++;
               
               if(id2=='c')
                   przegrane_c++;
               
               if(id2=='d')
                   przegrane_d++;
               
               if(id2=='e')
                   przegrane_e++;
               
               }
               
               
               
               else if(gracz1_double<gracz2_double){
                   winner=true;
                   if(id1=='a')
                   przegrane_a++;
               
               if(id1=='b')
                   przegrane_b++;
               
               if(id1=='c')
                   przegrane_c++;
               
               if(id1=='d')
                   przegrane_d++;
               
               if(id1=='e')
                   przegrane_e++;
               
                if(id2=='a')
                   wygrane_a++;
               
               if(id2=='b')
                   wygrane_b++;
               
               if(id2=='c')
                   wygrane_c++;
               
               if(id2=='d')
                   wygrane_d++;
               
               if(id2=='e')
                   wygrane_e++;
               
               }
              
           }
           
           //uklad dwoch roznych od siebie par
           
           if(waga_1gracz==waga_2gracz && waga_2gracz==3){
               float greater1=0;
               float greater2=0;
               
               if(rzut1==rzut2&&rzut2!=rzut3&&rzut3==rzut4){
                   
                   if(rzut1>rzut3){
                      
                       greater1=rzut1;
                   }
                   if(rzut1<rzut3){
                       
                       greater1=rzut3;
                   }
               }
               
               
                if(rzut1==rzut4&&rzut4!=rzut2&&rzut2==rzut3){
                   if(rzut1>rzut2){
                       
                       greater1=rzut1;
                   }
                   if(rzut1<rzut2){
                       
                       greater1=rzut2;
                   }
               }
               
               
               if(rzut1==rzut3&&rzut3!=rzut2&&rzut2==rzut4){
                   if(rzut1>rzut2){
                      
                       greater1=rzut1;
                   }
                   if(rzut1<rzut2){
                       
                       greater1=rzut2;
                   }
               }
               
               
               //drugi gracz
                if(rzut5==rzut6&&rzut6!=rzut7&&rzut7==rzut8){
                   if(rzut5>rzut7){
                       
                       greater2=rzut5;
                   }
                   if(rzut5<rzut7){
                      
                       greater2=rzut7;
                   }
               }
               
               
               if(rzut5==rzut8&&rzut8!=rzut6&&rzut6==rzut7){
                   if(rzut5>rzut6){
                       
                       greater2=rzut5;
                   }
                   if(rzut5<rzut6){
                       
                       greater2=rzut6;
                   }
               }
               
               
                if(rzut5==rzut7&&rzut7!=rzut6&&rzut6==rzut8){
                   if(rzut5>rzut6){
                       
                       greater2=rzut5;
                   }
                   if(rzut5<rzut6){
                       
                       greater2=rzut6;
                   }
               }
          
               if(greater1>greater2){
                
                winner=true;
                if(id1=='a'){
                wygrane_a++;
                }
               if(id1=='b'){
                   wygrane_b++;
               }
               if(id1=='c'){
                   wygrane_c++;
               }
               if(id1=='d'){
                   wygrane_d++;
               }
               if(id1=='e'){
                   wygrane_e++;
               }
               
               //
               if(id2=='a'){
                   przegrane_a++;
               }
               if(id2=='b'){
                   przegrane_b++;
               }
               if(id2=='c'){
                   przegrane_c++;
               }
               if(id2=='d'){
                   przegrane_d++;
               }
               if(id2=='e'){
                   przegrane_e++;
               }
               }
               
               
               
               else if(greater1<greater2){
                   
                  winner=true;
                   if(id1=='a'){
                   przegrane_a++;
                   }
               if(id1=='b'){
                   przegrane_b++;
               }
               if(id1=='c'){
                   przegrane_c++;
               }
               if(id1=='d'){
                   przegrane_d++;
               }
               if(id1=='e'){
                   przegrane_e++;
               }
                if(id2=='a'){
                   wygrane_a++;
                }
               if(id2=='b'){
                   wygrane_b++;
               }
               if(id2=='c'){
                   wygrane_c++;
               }
               if(id2=='d'){
                   wygrane_d++;
               }
               if(id2=='e'){
                   wygrane_e++;
               }
               }
           }
           
           //POZOSTALE PRZYPADKI, CZYLI SUMA OCZEK !!!
            if(winner==false){
               float sum_1=rzut1+rzut2+rzut3+rzut4;
               float sum_2=rzut5+rzut6+rzut7+rzut8;
               
               if(sum_1>sum_2){
                   winner=true;
                    if(id1=='a'){
                   wygrane_a++;
               }
               if(id1=='b'){
                   wygrane_b++;
               }
               if(id1=='c'){
                   wygrane_c++;
               }
               if(id1=='d'){
                   wygrane_d++;
               }
               if(id1=='e'){
                   wygrane_e++;
               }
               
               //
               if(id2=='a'){
                   przegrane_a++;
               }
               if(id2=='b'){
                   przegrane_b++;
               }
               if(id2=='c'){
                   przegrane_c++;
               }
               if(id2=='d'){
                   przegrane_d++;
               }
               if(id2=='e'){
                   przegrane_e++;
               }
               }
               
               
                else if(sum_1<sum_2){
                    winner=true;
                    if(id1=='a'){
                   przegrane_a++;
               }
               if(id1=='b'){
                   przegrane_b++;
               }
               if(id1=='c'){
                   przegrane_c++;
               }
               if(id1=='d'){
                   przegrane_d++;
               }
               if(id1=='e'){
                   przegrane_e++;
               }
                if(id2=='a'){
                   wygrane_a++;
               }
               if(id2=='b'){
                   wygrane_b++;
               }
               if(id2=='c'){
                   wygrane_c++;
               }
               if(id2=='d'){
                   wygrane_d++;
               }
               if(id2=='e'){
                   wygrane_e++;
               }
               
               }
               
               else if(sum_1==sum_2){
                   winner=true;
                    if(id1=='a'){
                   remisy_a++;
               }
               if(id1=='b'){
                   remisy_b++;
               }
               if(id1=='c'){
                  remisy_c++;
               }
               if(id1=='d'){
                   remisy_d++;
               }
               if(id1=='e'){
                   remisy_e++;
               }
                if(id2=='a'){
                  remisy_a++;
               }
               if(id2=='b'){
                   remisy_b++;
               }
               if(id2=='c'){
                   remisy_c++;
               }
               if(id2=='d'){
                   remisy_d++;
               }
               if(id2=='e'){
                  remisy_e++;
               }
               }
           }  
    /*       
   cout<<wygrane_a<<endl;
   cout<<przegrane_a<<endl;
   cout<<remisy_a<<endl;
   cout<<endl;
   cout<<wygrane_b<<endl;
   cout<<przegrane_b<<endl;
   cout<<remisy_b<<endl;
   cout<<endl;
   cout<<wygrane_c<<endl;
   cout<<przegrane_c<<endl;
   cout<<remisy_c<<endl;
   cout<<endl;
   cout<<wygrane_d<<endl;
   cout<<przegrane_d<<endl;
   cout<<remisy_d<<endl;
   cout<<endl;
   cout<<wygrane_e<<endl;
   cout<<przegrane_e<<endl;
   cout<<remisy_e<<endl;
   cout<<endl;
   */
           i++; 
        //koniec petli while
}
/// bla bla
   if(wygrane_a>0||przegrane_a>0||remisy_a>0){
       cout<<"gracz a"<<endl;
       if(wygrane_a>0){
           cout<<"    wygrane: "<<(wygrane_a/(wygrane_a+przegrane_a+remisy_a))*100<<"%"<<endl;
       }
       if (remisy_a>0){
           cout<<"    remisy: "<<(remisy_a/(wygrane_a+przegrane_a+remisy_a))*100<<"%"<<endl;
           
       }
      if(przegrane_a>0){
           cout<<"    przegrane: "<<(przegrane_a/(wygrane_a+przegrane_a+remisy_a))*100<<"%"<<endl;
       }
       cout<<endl;
   }
   
  if(wygrane_b>0||przegrane_b>0||remisy_b>0){
       cout<<"gracz b"<<endl;
       if(wygrane_b>0){
           cout<<"    wygrane: "<<(wygrane_b/(wygrane_b+przegrane_b+remisy_b))*100<<"%"<<endl;
       }
       if (remisy_b>0){
           cout<<"    remisy: "<<(remisy_b/(wygrane_b+przegrane_b+remisy_b))*100<<"%"<<endl;
           
       }
      if(przegrane_b>0){
           cout<<"    przegrane: "<<(przegrane_b/(wygrane_b+przegrane_b+remisy_b))*100<<"%"<<endl;
       }
       cout<<endl;
   }
   
   if(wygrane_c>0||przegrane_c>0||remisy_c>0){
       cout<<"gracz c"<<endl;
       if(wygrane_c>0){
           cout<<"    wygrane: "<<(wygrane_c/(wygrane_c+przegrane_c+remisy_c))*100<<"%"<<endl;
       }
       if (remisy_c>0){
           cout<<"    remisy: "<<(remisy_c/(wygrane_c+przegrane_c+remisy_c))*100<<"%"<<endl;
           
       }
      if(przegrane_c>0){
           cout<<"    przegrane: "<<(przegrane_c/(wygrane_c+przegrane_c+remisy_c))*100<<"%"<<endl;
       }
       cout<<endl;
   }
   
   
   if(wygrane_d>0||przegrane_d>0||remisy_d>0){
       cout<<"gracz d"<<endl;
       if(wygrane_d>0){
           cout<<"    wygrane: "<<(wygrane_d/(wygrane_d+przegrane_d+remisy_d))*100<<"%"<<endl;
       }
       if (remisy_d>0){
           cout<<"    remisy: "<<(remisy_d/(wygrane_d+przegrane_d+remisy_d))*100<<"%"<<endl;
           
       }
      if(przegrane_d>0){
           cout<<"    przegrane: "<<(przegrane_d/(wygrane_d+przegrane_d+remisy_d))*100<<"%"<<endl;
       }
       cout<<endl;
   }
   
   
   if(wygrane_e>0||przegrane_e>0||remisy_e>0){
       cout<<"gracz e"<<endl;
       if(wygrane_e>0){
           cout<<"    wygrane: "<<(wygrane_e/(wygrane_e+przegrane_e+remisy_e))*100<<"%"<<endl;
       }
       if (remisy_e>0){
           cout<<"    remisy: "<<(remisy_e/(wygrane_e+przegrane_e+remisy_e))*100<<"%"<<endl;
           
       }
      if(przegrane_e>0){
           cout<<"    przegrane: "<<(przegrane_e/(wygrane_e+przegrane_e+remisy_e))*100<<"%"<<endl;
       }
       cout<<endl;
   }
return 0;
}
//blabla
