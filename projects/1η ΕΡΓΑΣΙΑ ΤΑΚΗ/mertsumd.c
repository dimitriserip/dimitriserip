#include <stdio.h>
#include <stdbool.h>           //den anaferotan tipota gia thn xrhsh autoy, opote epitrepetai na to xrhsimopoihsw gia eukolia sthn anagnwsh

#define MAXEXP 8

int main() {

    int deficient_counter = 0, abundant_counter = 0;     //kai oi 2 autes oi metablhtes xrhsimopoiountai argotera      
    int min = 1;
    int max = 1;

    if (MAXEXP < 1 || MAXEXP >= 9) {
        printf("Invalid value for MAXEXP: %d \n", MAXEXP);
        return 1;
    }

    for (int i = 0; i < MAXEXP; i++) {           //xrhsimopoiw auto to for-loop gia na kanw th dunamh xwris th xrhsh ma8hmatikhs biblio8hkhs
        max = max * 10;
    }

    max = max + 9;

    printf("MAXEXP = %d \n", MAXEXP);
    printf("Range is: [%d,%d] \n", min, max);

    int count_odd = 0;
    int count_even = 0;
    int ZP = 0;

    for (int n = min; n <= max; n++) {    //8elw na brw tous square free ari8moys kai to plh8os twn prwtwn paragontwn ka8e ari8mou
        

        int k = n;
        int count_prime_factors = 0;

        if (k % 4 != 0 && k % 9 != 0) {
            int temp = k;

            

            if (temp % 2 == 0) {
                temp /= 2;
                count_prime_factors = count_prime_factors + 1;
              
            }

            if (temp % 3 == 0) {
                temp /= 3;
                count_prime_factors = count_prime_factors + 1;
            
            }

            int factor = 5;
            int square_free = 1; //true

            while (factor * factor <= temp) {
                if (temp % factor == 0) {
                    temp /= factor;
                    count_prime_factors = count_prime_factors + 1;              //kwdikas opws autos tou ma8hmatos

                    

                    if (temp % factor == 0) {
                        square_free = 0; //false
                        break;
                    }
                }

                if (factor % 6 == 5) {
                    factor += 2;
                } else {
                    factor += 4;
                }
            }

            if (temp != 1) {
               
                count_prime_factors = count_prime_factors + 1;
            }

            if (square_free == 1) { //true
                           

                if (count_prime_factors % 2 == 0) {                               //briskw me ta 2 if posoi ari8moi exoun artio kai peritto plh8os prwtwn paragontwn antistoixa
                    count_even += 1; //m(%d)=1 , sunarthsh mobius
                }

                if (count_prime_factors % 2 == 1) {
                    count_odd += 1; //m(%d)=-1 , sunarthsh mobius
                }
            }

           

        }

        int timh = count_even - count_odd;       //briskw thn timh ths mertens , enalaktikos orismos pou dinotan sthn ekfwnhsh

        if (timh == 0) {

            ZP += 1;          //briskw ta zero points (an h timh ths mertens einai 0)
        }

        bool print = false;


        for (int K = 1, base = 1; K <= MAXEXP; K++) {    //to deutero miso tou prwtou zhtoumenou, dhladh ektypwnei ekeines poy antistoixoyn stis times toy n poy briskontai sto zhtoymeno diasthma
            base = base * 10;                            //exw dhmiourghsei mia metablhth base h opoia einai to kentro tou ka8e diasthmatos ths morfhs [10K-9,10K+9], gia ka8e K sto diasthma [1,MAXEXP].
            if (n >= base - 9 && n <= base + 9) {        
                print = true;
                break;
            }
            if (n == base + 10) {            //to diasthma einai [10K-9,10K+9] ara gia base +10 einai times pou den 8elw na ektupwsw( mexri thn epomenh timh tou k) etsi me to base + 10 ektupwnw tis telitses
                printf("..........\n");
                break;
            }
        }

        if (print) {
            printf("M(%d) = %d\n", n, timh);                 //ektupwsh ths mertens gia autes tis times poy 8elw
        }
    }

    printf("\n");
    printf("Found %d zero points of the Mertens function\n", ZP);      //aples ektupwseis

    printf("\n");
    printf("Checking numbers in the range [2,%d]:\n", 1000 * ZP);        //aples ektupwseis
    printf("\n");

    for (int n = 2; n <= 1000 * ZP; n++) {             //edw einai to teleutaio zhtoumeno ths ergasias
        int sum = 1;                                   //kwdikas autousios me auton tou ma8hmatos, briskei tous deficient ari8mous  kai aplws exw pros8esei 2 if sto telos gia tous teleious(tous opoious ektupwnw) kai tous abundant
        int temp = n;
        int factor = 2;

        while (factor * factor <= temp) {
            int term = 1;

            while (temp % factor == 0) {
                term = factor * term + 1;
                temp /= factor;
            }

            sum *= term;

            if (factor == 2) {
                factor = 3;
            } else if (factor == 3) {
                factor = 5;
            } else if (factor % 6 == 5) {
                factor += 2;
            } else {
                factor += 4;
            }
        }

        if (temp != 1) {
            sum *= (1 + temp);
        }

        if (sum - n  == n) {
            printf("Found perfect number: %d\n", n);
        }

        if (sum - n < n) {
            deficient_counter = deficient_counter + 1;
        }

        if (sum - n  > n) {
            abundant_counter = abundant_counter + 1;
        }

    }

    printf("\n");

    printf("Found %d deficient numbers\n", deficient_counter);     //aples ektupwseis

    printf("Found %d abundant numbers\n", abundant_counter);

    return 0;
}
