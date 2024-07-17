//Dawid Zalewski
#include <iostream>
using namespace std;
int main() {


int dlugosc;
cin>>dlugosc;
int array[dlugosc][dlugosc][dlugosc];

//wypelnianie szescianu
for (int i = 0; i < dlugosc; ++i) {
        for (int j = 0; j < dlugosc; ++j) {
            for (int k = 0; k < dlugosc; ++k) {

                cin >> array[i][j][k];
            }
        }
    }



char operacja;

while(operacja!='E'){


    cin>>operacja;

    //operacja C
    if(operacja=='C'){
        int h;
        int w;
        int d;
        int l;
        int v;
        int p;
        int suma=0;
        cin>>l>>v>>p>>h>>w>>d;



    //jesli punkty wspolrzednych beda ponad polowe to je zmieniamy
    //TO JEST BARDZO KLUCZOWE


    if (p >= dlugosc/2){
            p = p - d;
    }


    if (l >= dlugosc/2){
        l = l - h;
    }


    if (v >= dlugosc/2){
       v = v - w;
    }

    //array[glebokosc][poziom][pion] !!!!!


  // WyĹwietlanie
    for (int glebokosc=p; glebokosc<(1+p+d); glebokosc++) {
            //iteracja glebokosci
        for (int poziom = l; poziom<(1+l+h); poziom++) {
            //iteracja poziomu
            for (int pion = v; pion <(1+v+w); pion++) {
                //iteracja pionu
                //warunek
                if(glebokosc<dlugosc&&glebokosc>=0&&pion>=0&&pion<dlugosc&&poziom>=0&&poziom<dlugosc){
                    suma=suma+array[glebokosc][poziom][pion];
                }
            }
        }
    }
        cout<<suma<<endl;
    }//KONIEC C

    if(operacja=='T'){
         int l,v,p,e;
         int suma=0;
        cin>>l>>v>>p>>e;

        //jesli punkty wspolrzednych beda ponad polowe to je zmieniamy
    //TO JEST BARDZO KLUCZOWE


    if (p >= dlugosc/2){
            p= p-e;
    }


    if (l >= dlugosc/2){
        l = l- e;
    }


    if (v >= dlugosc/2){
       v=v-e;
    }

    //array[glebokosc][poziom][pion] !!!!!


        // WyĹwietlanie
    for (int glebokosc=p; glebokosc<(1+p+e); glebokosc++) {
            //iteracja glebokosci
        for (int poziom = l; poziom<(1+l+e); poziom++) {
            //iteracja poziomu
            for (int pion = v; pion <(1+v+e); pion++) {
                //iteracja pionu

                //trzy kolejne dlugosci !!!
                //oraz liczenie ich wartosci bezwzglednej
                int distA,distB,distC;
                distA=pion-v;
                if(distA<0){
                    distA=distA*-1;
                }
                distB=poziom-l;
                if(distB<0){
                    distB=distB*-1;
                }
                distC=glebokosc-p;
                if(distC<0){
                    distC=distC*-1;
                }
                int sumOfDistABC=distA+distB+distC;

                //warunek

                if(e>=sumOfDistABC){
                //drugi warunek
                if(glebokosc<dlugosc&&glebokosc>=0&&pion>=0&&pion<dlugosc&&poziom>=0&&poziom<dlugosc){
                    suma=suma+array[glebokosc][poziom][pion];
                }
            }
            }
        }
    }



        cout<<suma<<endl;

    }//KONIEC T
    if(operacja=='O'){
        int l,v,p,r;
        cin>>l>>v>>p>>r;
    }


        if(operacja=='D'){
        int i;
        char k;
        cin>>k>>i;
        //k oznacza odpowiednio l-poziom, v-pion, p-pion


        //w zaleznosci jaka plaszczyzna to tworzymy macierz i jÄ uzupeĹniamy (macierz maks 32x32)
        long long int matrix[32][32]={0};//inicjalizacja zerami
        if(k=='l'){

            for(int x=0; x<dlugosc;x++){
                for(int j=0;j<dlugosc;j++){
                 matrix[x][j]= array[x][i][j];
                }
            }

        }//koniec l

        if(k=='v'){


            for(int x=0; x<dlugosc;x++){
                for(int j=0;j<dlugosc;j++){
                 matrix[x][j]= array[j][x][i];
                }
            }



        }


        if(k=='p'){


        for(int x=0; x<dlugosc;x++){
                for(int j=0;j<dlugosc;j++){
                 matrix[x][j]= array[i][x][j];
                }
            }

        }




        //teraz liczenie wyznacznika


            // Liczenie wyznacznika metoda Bareissa
        long long int det = 1;
        for (int wiodacy_element = 0; wiodacy_element < dlugosc - 1; wiodacy_element++) {
            if (matrix[wiodacy_element][wiodacy_element] == 0) {
                // Znalezienie wiersza do zamiany
                int row_to_swap = wiodacy_element + 1;
                while (row_to_swap < dlugosc && matrix[row_to_swap][wiodacy_element] == 0) {
                    row_to_swap++;
                }
                if (row_to_swap == dlugosc) {
                    det = 0;
                    break;
                }

                // Zamiana wierszy
                for (int kolumna = 0; kolumna < dlugosc; kolumna++) {
                    long long int temp = matrix[wiodacy_element][kolumna];
                    matrix[wiodacy_element][kolumna] = matrix[row_to_swap][kolumna];
                    matrix[row_to_swap][kolumna] = temp;
                }

                det = -det; // Zmiana znaku wyznacznika
            }


             if (matrix[wiodacy_element][wiodacy_element] == 0) {
                    // Jesli wiodacy_element jest nadal zerem po zamianie, macierz jest osobliwa
                    det = 0;
                    break;
                }



            //Eleminacja
            for (int row = wiodacy_element + 1; row < dlugosc; ++row) {
                for (int kolumna = wiodacy_element + 1; kolumna < dlugosc; kolumna++) {
                    matrix[row][kolumna] = matrix[wiodacy_element][wiodacy_element] * matrix[row][kolumna] - matrix[row][wiodacy_element] * matrix[wiodacy_element][kolumna];
                    if (wiodacy_element > 0) {
                        matrix[row][kolumna] /= matrix[wiodacy_element - 1][wiodacy_element - 1];
                    }
                }
            }
        }
        if(det!=0){
            det = det* matrix[dlugosc - 1][dlugosc - 1];
        }

        cout<< det << endl;






    }//KONIEC D

}


    return 0;
}
