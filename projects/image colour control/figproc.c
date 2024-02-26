#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void int_to_ascii(int value) {    //me auth th sunarthsh pairnw enan ari8mo ,ton antistrefw kai tupwnw ta pshfia toy 1 pros 1 
    int ans = 0;                 //xreiazetai na ton antistrepsw giati an den to kanw 8a typwsw ta pshfia me anti8eth seira apo thn opoia moy xreiazetai
    int l = 0;                   //auth th sunarthsh th xrhsimopoiw sto p2_p1
    int m = 0;

    if (value == 0) {
        putchar(48);
        return;
    }

    if (value < 0) {
        fprintf(stderr, "value is: %d \n", value);
        exit(5);
    }

    while (value > 0) {
        int mod = value % 10;

        ans = ans * 10 + mod;

        value = value / 10;
        l++;
    }

    while (ans > 0) {
        int mod = ans % 10; //split last digit from number
        putchar(mod + 48);

        ans = ans / 10; //divide num by 10. num /= 10 also a valid one 
        m++;
    }

    while (m < l) {
        putchar(48);
        m++;
    }
}

int power(int base, int exp) { //aplh sunarthsh poy ypologizei dunamy(thn xrhsimopoiw gia ta bonus erwthmata)
    int k = 1;

    for (int i = 0; i < exp; i++) {
        k = k*base;
    }
    return k;
}

void p2_p1() {
    int width = 0, height = 0, pixels = 0;
    char buffer;

    fprintf(stderr, "Converting P2 to P1, ASCII greyscale to ASCII black and white \n");

    putchar('P');    //typwnw ton magic number kai allagh grammhs
    putchar('1');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {       //me th metablhth buffer briskw posa rows (seires) yparxoun sto protypo arxeio, ystera to typwnw sto diko moy gia na exoun tis idies diastaseis
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns                    
    while ((buffer = getchar()) != '\n') {      //kanw to idio kai gia ta columns(steiles)
        char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    int depth = 0;

    while ((buffer = getchar()) != '\n') {   //briskw to ba8os xrwmatos
        char number = buffer - 48;
        depth = depth * 10 + number;
    }

    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Depth   : %d \n", depth);
    fprintf(stderr, "Pixels  : %d \n", pixels);      //ola ta parapanw xrhsimopoiountai se oles tis metatropes , se oles tis sunarthseis void poy exw dhmiourghsei

    for (int i = 0; i < pixels; i++) {    //"scannarw" olous tous ari8mous , dhladh ola ta pixels tou protupou
        int value = 0;

        while ((buffer = getchar()) != ' ') {    // an sunanthsw keno bazw keno
            char number = buffer - 48;
            value = value * 10 + number;
        }
        if (buffer == EOF) {
            break;
        }

        if (value < (depth + 1) / 2) {  //apo to greyscale briskw ton ari8mo kai an einai mikroteros tou misou toy ba8os xrwmatos ton kanw 0, alliws 1
            putchar('1');
        } else {
            putchar('0');
        }

        putchar(' ');

        if (i % width == 0 && i > 0) { //an ftasw sto telos mia grammhs,bazw allagh grammhs
            putchar('\n');
        }
    }

    putchar('\n');
}

void p3_p2() {
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    fprintf(stderr, "Converting P3 to P2, ASCII color to ASCII grayscale \n");

    putchar('P');
    putchar('2');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    // ignore depth
    int depth = 0;

    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        depth = depth * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Depth   : %d \n", depth);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0; i < pixels; i++) {    //scannarw ola ta pixels ths protuphs eikonas ksana, mono poy edw ka8e pixel exei 3 ari8mous , gia red , green kai blue antistoixa
        int red = 0, green = 0, blue = 0;

        while ((buffer = getchar()) != ' ') {
            unsigned char number = buffer - 48;
            red = red * 10 + number;
        }
        if (buffer == EOF) {
            fprintf(stderr, "corrupted file\n");
            exit(1);
        }

        while ((buffer = getchar()) != ' ') {
            unsigned char number = buffer - 48;
            green = green * 10 + number;
        }
        if (buffer == EOF) {
            fprintf(stderr, "corrupted file\n");
            exit(1);
        }

        while ((buffer = getchar()) != ' ') {
            unsigned char number = buffer - 48;
            blue = blue * 10 + number;
        }
        if (buffer == EOF) {
            fprintf(stderr, "corrupted file\n");
            exit(1);
        }

        int value = (299 * red + 587 * green + 114 * blue) / 1000; // [0, ... depth]  , xrhsimopoiw th sunarthsh ths ekfwnhshs gia na metatrepsw tous 3 ari8mous apo red , green kai blue antistoixa se enan ari8mo pou 8a dhlwnei greyscale

        int_to_ascii(value);

        putchar(' ');

        if (i % width == 0 && i > 0) {
            getchar();
            putchar('\n');
        }
    }

    putchar('\n');
}

void p4_p3() {     //auth h metatroph den zhteitai kan ws bonus erwthma , aplws ekana eksaskhsh
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    fprintf(stderr, "Converting P4 to P3, BIN black and white to ASCII color \n");

    putchar('P');
    putchar('3');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    putchar('2');
    putchar('5');
    putchar('5');
    putchar('\n');

    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0, q = 0; i < height; i++) {
        int row_bytes = width / 8;
        if (width % 8 > 0) {
            row_bytes++;
        }

        for (int j = 0; j < row_bytes; j++) {
            int byte = getchar();
            int bits = 0;

            if (j != row_bytes - 1) {
                bits = 8;
            } else {
                bits = width % 8;
            }

            for (int k = 0; k < bits; k++) {
                int value = (byte >> (7 - k)) % 2;

                if (value == 0) {
                    putchar('2');
                    putchar('5');
                    putchar('5');
                    putchar(' ');
                    putchar('2');
                    putchar('5');
                    putchar('5');
                    putchar(' ');
                    putchar('2');
                    putchar('5');
                    putchar('5');
                    putchar(' ');
                } else {
                    putchar('0');
                    putchar(' ');
                    putchar('0');
                    putchar(' ');
                    putchar('0');
                    putchar(' ');
                }

                q++;

                if (q == width && q > 0) {
                    putchar('\n');
                }
            }
        }
    }

    putchar('\n');
}

void p5_p4() {
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    fprintf(stderr, "Converting P5 to P4, BIN grayscale to bin black and white\n");

    putchar('P');
    putchar('4');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    // depth
    int depth = 0;

    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        depth = depth * 10 + number;
    }

    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0; i < height; i++) { // for each row ...
        int row_bytes = width / 8;         //epeidh douleuw se diadiko pleon , prepei na xwrisw thn ka8e grammh(row) se 8ades

        for (int j = 0; j < row_bytes; j++) {  //o ka8e ari8mos einai se 2adiko , exei 8 pshfia 0 kai 1
            int a = getchar();                
            int b = getchar();
            int c = getchar();
            int d = getchar();
            int e = getchar();
            int f = getchar();
            int g = getchar();
            int h = getchar();

            a = (a < (depth + 1) / 2) ? 1 : 0;  //metatrepw apo greyscale se black and white me ton idio tropo opws sto p2_p1
            b = (b < (depth + 1) / 2) ? 1 : 0;
            c = (c < (depth + 1) / 2) ? 1 : 0;
            d = (d < (depth + 1) / 2) ? 1 : 0;
            e = (e < (depth + 1) / 2) ? 1 : 0;
            f = (f < (depth + 1) / 2) ? 1 : 0;
            g = (g < (depth + 1) / 2) ? 1 : 0;
            h = (h < (depth + 1) / 2) ? 1 : 0;


            int s = (a << 7) + (b << 6) + (c << 5) + (d << 4) + (e << 3) + (f << 2) + (g << 1) + (h << 0); //kanw olis8hseis kai apomonwnw mono to most significant bit kai to typwnw
            putchar(s);
        }

        int remaining_bytes = width % 8;   //oti periseuei se mia grammh apo tis 8ades pou xwrhsa parapanw

        if (remaining_bytes > 0) {
            int s = 0;

            for (int j = 0; j < remaining_bytes; j++) {
                int a = getchar();
                a = (a < (depth + 1) / 2) ? 1 : 0;

                s = s + (a << (7 - j));
            }

            putchar(s);
        }
    }

    putchar('\n');

}

void p6_p5() {
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    fprintf(stderr, "Converting P6 to P5, BIN color to bin grayscale\n");

    putchar('P');
    putchar('5');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    // depth
    int depth = 0;

    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        depth = depth * 10 + number;
        putchar(buffer);
    }
    putchar('\n');


    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0; i < height; i++) { // for each row ...
        int row_bytes = width / 8;

        for (int j = 0; j < row_bytes; j++) {    //kanw to idio me to p5_p4 omws epi 3 fores giati to ka8e pixel pleon exei 3 diaforetika xrwmata ( ara kai ari8mous )
            int a_r = getchar();
            int a_g = getchar();
            int a_b = getchar();
            int b_r = getchar();
            int b_g = getchar();
            int b_b = getchar();
            int c_r = getchar();
            int c_g = getchar();
            int c_b = getchar();
            int d_r = getchar();
            int d_g = getchar();
            int d_b = getchar();
            int e_r = getchar();
            int e_g = getchar();
            int e_b = getchar();
            int f_r = getchar();
            int f_g = getchar();
            int f_b = getchar();
            int g_r = getchar();
            int g_g = getchar();
            int g_b = getchar();
            int h_r = getchar();
            int h_g = getchar();
            int h_b = getchar();

            int a = (299 * a_r + 587 * a_g + 114 * a_b) / 1000; // [0, ... depth]      h sunarthsh ths ekfwnhshs gia ka8e ari8mo apo tous 8 pou 8a tupwsoume sto greyscale arxeio
            int b = (299 * b_r + 587 * b_g + 114 * b_b) / 1000; // [0, ... depth]
            int c = (299 * c_r + 587 * c_g + 114 * c_b) / 1000; // [0, ... depth]
            int d = (299 * d_r + 587 * d_g + 114 * d_b) / 1000; // [0, ... depth]
            int e = (299 * e_r + 587 * e_g + 114 * e_b) / 1000; // [0, ... depth]
            int f = (299 * f_r + 587 * f_g + 114 * f_b) / 1000; // [0, ... depth]
            int g = (299 * g_r + 587 * g_g + 114 * g_b) / 1000; // [0, ... depth]
            int h = (299 * h_r + 587 * h_g + 114 * h_b) / 1000; // [0, ... depth]

            putchar(a);
            putchar(b);
            putchar(c);
            putchar(d);
            putchar(e);
            putchar(f);
            putchar(g);
            putchar(h);
        }

        int remaining_pixels = width % 8;

        if (remaining_pixels > 0) {
            for (int j = 0; j < remaining_pixels; j++) {
                int a_r = getchar();
                int a_g = getchar();
                int a_b = getchar();

                int a = (299 * a_r + 587 * a_g + 114 * a_b) / 1000; // [0, ... depth]

                putchar(a);
            }
        }
    }

    putchar('\n');
}

// bonus

void p4_p1() {
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    //fprintf(stderr, "Converting P4 to P1, BIN black and white to ASCII black and white\n");

    putchar('P');
    putchar('1');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar('\n');

    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0; i < height; i++) { // for each row ...
        int octets = width / 8;

        for (int j = 0; j < octets; j++) {
            int a = getchar();

            for (int k = 0; k < 8; k++) {
                int b = (a >> (7 - k)) % 2;

                if (b == 0) {
                    putchar('0');
                } else {
                    putchar('1');
                }

                putchar(' ');
            }
        }

        int remaining = width % 8;

        if (remaining > 0) {
            int a = getchar();

            for (int k = 0; k < remaining; k++) {
                int b = (a >> (7 - k)) % 2;

                if (b == 0) {
                    putchar('0');
                } else {
                    putchar('1');
                }

                putchar(' ');
            }
        }
    }

    putchar('\n');

}

void p5_p2() {
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    fprintf(stderr, "Converting P5 to P4, BIN grayscale to ASCII grayscale \n");

    putchar('P');
    putchar('2');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // depth
    int depth = 0;

    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        depth = depth * 10 + number;

        putchar(buffer);
    }
    putchar('\n');


    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0; i < height; i++) { // for each row ...
        for (int j = 0; j < width; j++) {
            int a = getchar(); // a = 240 = 00000000 00000000 00000000 11110000

            int copy = a;
            int digits = 0;

            while (copy > 0) {
                copy = copy / 10;
                digits++;
            }

            if (digits == 0) { // digits = 3
                putchar(48);
                putchar(' ');
            } else {
                copy = a; // copy = 240

                for (int k = 0; k < digits; k++) { // k=0:2  k=1:4  k=2:0
                    int out = copy / (power(10, (digits - 1 - k))) % 10;
                    out = out + 48;

                    putchar(out);
                }
                putchar(' ');
            }
        }

        putchar('\n');
    }
}

void p6_p3() {
    int width = 0, height = 0, pixels = 0;
    unsigned char buffer;

    fprintf(stderr, "Converting P5 to P4, BIN color to ASCII color \n");

    putchar('P');
    putchar('3');
    putchar('\n');

    // copy rows
    while ((buffer = getchar()) != ' ') {
        if (buffer == '#') {
            putchar('#');
            while ((buffer = getchar()) != '\n') {
                putchar(buffer);
            }
            putchar('\n');
            continue;
        }
        unsigned char number = buffer - 48;
        width = width * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // copy columns
    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        height = height * 10 + number;

        putchar(buffer);
    }
    putchar(' ');

    // depth
    int depth = 0;

    while ((buffer = getchar()) != '\n') {
        unsigned char number = buffer - 48;
        depth = depth * 10 + number;

        putchar(buffer);
    }
    putchar('\n');


    pixels = width *height;

    fprintf(stderr, "Rows    : %d \n", height);
    fprintf(stderr, "Columns : %d \n", width);
    fprintf(stderr, "Pixels  : %d \n", pixels);

    for (int i = 0; i < height; i++) { // for each row ...
        for (int j = 0; j < width; j++) {
            for (int m = 0; m < 3; m++) {
                int a = getchar(); // a = 240 = 00000000 00000000 00000000 11110000

                int copy = a;
                int digits = 0;

                while (copy > 0) {
                    copy = copy / 10;
                    digits++;
                }

                if (digits == 0) { // digits = 3
                    putchar(48);
                    putchar(' ');
                } else {
                    copy = a; // copy = 240

                    for (int k = 0; k < digits; k++) { // k=0:2  k=1:4  k=2:0
                        int out = copy / (power(10, (digits - 1 - k))) % 10;
                        out = out + 48;

                        putchar(out);
                    }
                    putchar(' ');
                }
            }
        }

        putchar('\n');
    }
}

int main(int argc, char** argv) {        //exw ftiaksei polles sunarthseis void kai me diadoxika if kanw tis periptwseis ka8e erwthmatos
    char HEADER_P, HEADER_N, newln;

    HEADER_P = getchar();        //briskw ton magic number toy protupoy arxeioy kai ystera kanw thn katallhlh metatroph
    HEADER_N = getchar();
    newln = getchar();

    if (HEADER_P != 'P') {
        fprintf(stderr, "Invalid 1st byte \n");
        return 1;
    }

    if (HEADER_N < '0' || HEADER_N > '6') {
        fprintf(stderr, "Invalid 2nd byte \n");
        return 1;
    }

    if (newln != '\n') {
        fprintf(stderr, "Invalid 3rd byte (should be newline) \n");
        return 1;
    }

    if (HEADER_N == '1') {
        fprintf(stderr, "No conversion can be applied for P1 \n");
        return 0;
    }

    if (HEADER_N == '2') {
        p2_p1();
        return 0;
    }

    if (HEADER_N == '3') {
        p3_p2();
        return 0;
    }

    if (HEADER_N == '4') {
        if (argc == 2 && strcmp(argv[1], "--bonus") == 0) {     //gia na ginei to bonus erwthma grafw --bonus sto command line mazi me to ypoloipo kommati
            p4_p1();
        } else {
            p4_p3();
        }
        return 0;
    }

    if (HEADER_N == '5') {
        if (argc == 2 && strcmp(argv[1], "--bonus") == 0) {
            p5_p2();
        } else {
            p5_p4();
        }
        return 0;
    }

    if (HEADER_N == '6') {
        if (argc == 2 && strcmp(argv[1], "--bonus") == 0) {
            p6_p3();
        } else {
            p6_p5();
        }
        return 0;
    }

    return 0;
}

