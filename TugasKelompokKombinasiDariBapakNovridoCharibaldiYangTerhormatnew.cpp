#include <iostream>
#include <string>
#include <map>
using namespace std;

// Fungsi untuk menghitung faktorial menggunakan rekursi
long long factorial(long long n) {
    if (n < 0) {
        cout << "Faktorial tidak didefinisikan untuk angka negatif.\n";
        return -1; // Indikator error
    }
    
    long long result = 1;
    for (long long i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Fungsi untuk menghitung kombinasi menggunakan faktorial
long long combination(long long n, long long k) {
    if (n < 0 || k < 0 || k > n) {
        cout << "Kombinasi tidak valid: pastikan n >= 0, k >= 0, dan k <= n.\n";
        return -1; // Indikator error
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Kombinasi tanpa pengulangan
long long combination_without_replacement(long long n, long long k) {
    return combination(n, k);
}

// Kombinasi dengan pengulangan
long long combination_with_replacement(long long n, long long k) {
    if (n <= 0 || k < 0) {
        cout << "Kombinasi tidak valid: pastikan n > 0 dan k >= 0.\n";
        return -1; // Indikator error
    }
    return combination(n + k - 1, k);
}

long long bounded_combination(long long n, long long k, long long maxPerItem) {
    long long totalWays = 0;
    
    // Periksa setiap kemungkinan jumlah elemen dari 0 hingga maxPerItem untuk setiap jenis
    for (long long i = 0; i <= maxPerItem; ++i) {
        // Menghitung cara memilih k - i elemen dari n jenis dengan batasan
        totalWays += combination_with_replacement(n, k - i);
    }
    
    return totalWays;
}

// Kombinasi dengan batasan menggunakan komplemen
long long combination_with_constraints_complement(long long n, long long k, long long total_objects) {
    if (n > total_objects || k > total_objects || n < 0 || k < 0) {
        cout << "Input tidak valid untuk kombinasi dengan batasan.\n";
        return -1; // Indikator error
    }
    long long total = combination(total_objects, k);
    long long invalid = combination(n, k);
    if (total == -1 || invalid == -1) return -1; // Jika ada kesalahan pada kombinasi
    return total - invalid;
}

// Fungsi untuk menghitung eksponensial (a^b)
double power(double base, long long exponent) {
    if (base == 0 && exponent < 0) {
        cout << "Eksponensial tidak valid: basis 0 tidak boleh dipangkatkan negatif.\n";
        return -1; // Indikator error
    }
    double result = 1.0;
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }
    for (long long i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Kombinasi dalam probabilitas
double combination_probability(long long n, long long k, long long favorable, long long total) {
    if (favorable > total || n > total || k > favorable) {
        cout << "Input tidak valid untuk probabilitas kombinasi.\n";
        return -1; // Indikator error
    }
    long long total_combinations = combination(total, n);
    long long favorable_combinations = combination(favorable, k) * combination(total - favorable, n - k);
    if (total_combinations == -1 || favorable_combinations == -1) return -1; // Cek error
    return static_cast<double>(favorable_combinations) / total_combinations;
}

// Ekspansi binomial (x + y)^n
void binomialExpansionWithExplanation(long long n, long long a, long long b, string var_a, string var_b) {
    long long coeff, term_a, term_b, result;

    if (n < 0 || a < 0 || b < 0) {
        cout << "Ekspansi binomial tidak valid: pastikan semua parameter >= 0.\n";
        return;
    }

    cout << "Ekspansi binomial (" << a << "" << var_a << " + " << b << "" << var_b << ")^" << n << ":\n";

    for (long long k = 0; k <= n; ++k) {
        coeff = combination(n, k);
        if (coeff == -1) {
            cout << "Terjadi kesalahan dalam perhitungan kombinasi.\n";
            return;
        }
        
        term_a = power(a, n - k);
        term_b = power(b, k);

        result = coeff * term_a * term_b;

        cout << result;
        if (n - k > 0) cout << "*" << var_a << "^" << (n - k);
        if (k > 0) cout << "*" << var_b << "^" << k;

        if (k < n) cout << " + ";
    }
    cout << endl;
}

long long combination_n(long long n, long long k) {
    if (k > n) {
        cout << "Kombinasi tidak valid: k tidak boleh lebih besar dari n.\n";
        return -1; // Indikator error
    }
    
    // Jika k > n/2, maka gunakan kombinasi C(n, k) = C(n, n-k)
    if (k > n - k) k = n - k;

    long long result = 1;
    
    // Hitung kombinasi C(n, k) secara langsung
    for (long long i = 1; i <= k; ++i) {
        result *= (n - k + i);
        result /= i;
    }

    return result;
}

// Menghitung koefisien binomial suku ke-k dalam (a+b)^n
long long binomialCoefficient(long long n, long long k, long long coeff_a, long long coeff_b) {
    if (n < 0 || k < 0 || k > n) {
        cout << "Koefisien binomial tidak valid: pastikan n >= 0, k >= 0, dan k <= n.\n";
        return -1; // Indikator error
    }
    return combination(n, k) * power(coeff_a, n - k) * power(coeff_b, k);
}

// Probabilitas Binomial
double binomial_probability(long long n, long long k, double p) {
    if (p < 0 || p > 1 || k < 0 || k > n) {
        cout << "Probabilitas binomial tidak valid: pastikan 0 <= p <= 1, 0 <= k <= n.\n";
        return -1; // Indikator error
    }
    return combination(n, k) * power(p, k) * power(1 - p, n - k);
}

void menuutama(){
        cout << "+---------------------------------------------------------------+" << endl;
        cout << "|                           MAIN MENU                           |" << endl;
        cout << "+---------------------------------------------------------------+" << endl;
        cout << "Silahkan Pilih Materi: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Kombinasi Tanpa Pengulangan" << endl;
        cout << "2. Kombinasi Dengan Pengulangan" << endl;
        cout << "3. Kombinasi dalam Probabilitas" << endl;
        cout << "4. Kombinasi dengan Batasan" << endl;
        cout << "5. Kombinasi dan Koefisien Binomial" << endl;
        cout << "Masukkan Pilihan Anda: ";
        
}

// menu soal 1
void menu1 (){
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "|                 Menu Kombinasi Tanpa Pengulangan              |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "Silakan Pilih Jenis Soal: " << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "1. Berapa cara memilih k buah dari keranjang berisi n buah?" << endl;
    cout << "\n2. Dari 20 bola, 8 merah dan 12 biru, berapa cara memilih 5 bola merah dan 3 bola biru?" << endl;
    cout << "\n3. Seorang pelatih bola basket akan memilih komposisi pemain yang akan diturunkan dalam suatu pertandingan. Ada n orang permain yang dapat dipilihnya. Berapa macam tim yang dapat ia bentuk?" << endl;
    cout << "\n4. Ada 6 pria dan 4 wanita. Berapa cara memilih komite 3 orang dengan setidaknya 1 wanita?" << endl;
    cout << "\n5. Ada 9 titik pada sebuah lingkaran. Berapa segitiga yang dapat dibentuk?" << endl;
    cout << "Masukkan Pilihan Anda: ";
}

long long soal1A(){
long long fruidtotal, fruidtoChoose;

    cout << "Masukkan jumlah total buah dalam keranjang: ";
    cin >> fruidtotal;

    cout << "Masukkan jumlah buah yang akan dipilih: ";
    cin >> fruidtoChoose;

    cout << "\nDalam memilih buah dari keranjang, urutan pemilihan tidak diperhatikan. \n"
        << "Jadi, yang menjadi masalah hanyalah siapa yang dipilih. \n"
        << "Tidak menjadi masalah apakah sebuah buah dipilih pertama atau terakhir.\n"
        << "Jadi, banyaknya cara untuk memilih " << fruidtoChoose 
        << " buah dari " << fruidtotal << " buah adalah kombinasi " 
        << fruidtotal << " objek yang diambil " << fruidtoChoose << " sekaligus.\n";

    cout << "\nLangkah-langkah C(" << fruidtotal << "," << fruidtoChoose << "):\n";

    // Langkah 1: Hitung faktorial dari fruidtotal
    cout << "1. Hitung faktorial dari total buah (" << fruidtotal << "!)\n";
    cout << fruidtotal << "! = ";
    for (long long i = fruidtotal; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(fruidtotal) << endl;

    // Langkah 2: Hitung faktorial dari fruidtoChoose
    cout << "\n2. Hitung faktorial dari " << fruidtoChoose << " (jumlah yang dipilih)!\n";
    cout << fruidtoChoose << "! = ";
    for (long long i = fruidtoChoose; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(fruidtoChoose) << endl;

    // Langkah 3: Hitung faktorial dari (fruidtotal - fruidtoChoose)
    cout << "\n3. Hitung faktorial dari (" << fruidtotal << " - " << fruidtoChoose << ") = " << (fruidtotal - fruidtoChoose) << "!\n";
    cout << (fruidtotal - fruidtoChoose) << "! = ";
    for (long long i = (fruidtotal - fruidtoChoose); i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(fruidtotal - fruidtoChoose) << endl;

    // Langkah 4: Hitung kombinasi C(fruidtotal, fruidtoChoose)
    cout << "\n4. Hitung kombinasi dengan rumus C(" << fruidtotal << "," << fruidtoChoose 
         << ") = " << fruidtotal << "! / (" << fruidtoChoose << "! * " << (fruidtotal - fruidtoChoose) << "!)\n";
    
    cout << "C(" << fruidtotal << "," << fruidtoChoose << ") = " 
         << factorial(fruidtotal) << " / (" << factorial(fruidtoChoose) << " * " 
         << factorial(fruidtotal - fruidtoChoose) << ") = " << combination(fruidtotal, fruidtoChoose) << endl;

    cout << "\nJadi, banyaknya cara untuk memilih " << fruidtoChoose << " buah dari " 
         << fruidtotal << " buah adalah: " << combination(fruidtotal, fruidtoChoose) << " kemungkinan.\n";

    return 0;
}

long long soal1B (){
long long totalRed, totalBlue, chooseRed, chooseBlue;

    // Penjelasan soal
    cout << "Dari 20 bola, terdiri dari 8 bola merah dan 12 bola biru.\n"
         << "Berapa cara memilih 5 bola merah dan 3 bola biru?\n\n";

    // Input jumlah bola merah dan biru
    cout << "Masukkan jumlah total bola merah: ";
    cin >> totalRed;

    cout << "Masukkan jumlah total bola biru: ";
    cin >> totalBlue;

    cout << "Masukkan jumlah bola merah yang ingin dipilih: ";
    cin >> chooseRed;

    cout << "Masukkan jumlah bola biru yang ingin dipilih: ";
    cin >> chooseBlue;

    // Menjelaskan langkah-langkah perhitungan
    cout << "\nLangkah-langkah perhitungan:\n";

    // Langkah 1: Hitung kombinasi untuk bola merah
    cout << "1. Hitung kombinasi untuk memilih " << chooseRed 
         << " bola merah dari " << totalRed << " bola merah.\n";
    cout << "C(" << totalRed << ", " << chooseRed << ") = "
         << totalRed << "! / (" << chooseRed << "! * (" 
         << totalRed - chooseRed << ")!)\n";

    cout << totalRed << "! = ";
    for (long long i = totalRed; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(totalRed) << endl;

    cout << chooseRed << "! = ";
    for (long long i = chooseRed; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(chooseRed) << endl;

    cout << "(" << totalRed - chooseRed << ")! = ";
    for (long long i = (totalRed - chooseRed); i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(totalRed - chooseRed) << endl;

    long long redCombination = combination(totalRed, chooseRed);
    cout << "C(" << totalRed << ", " << chooseRed << ") = " << redCombination << endl;

    // Langkah 2: Hitung kombinasi untuk bola biru
    cout << "\n2. Hitung kombinasi untuk memilih " << chooseBlue 
         << " bola biru dari " << totalBlue << " bola biru.\n";
    cout << "C(" << totalBlue << ", " << chooseBlue << ") = "
         << totalBlue << "! / (" << chooseBlue << "! * (" 
         << totalBlue - chooseBlue << ")!)\n";

    cout << totalBlue << "! = ";
    for (long long i = totalBlue; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(totalBlue) << endl;

    cout << chooseBlue << "! = ";
    for (long long i = chooseBlue; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(chooseBlue) << endl;

    cout << "(" << totalBlue - chooseBlue << ")! = ";
    for (long long i = (totalBlue - chooseBlue); i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(totalBlue - chooseBlue) << endl;

    long long blueCombination = combination(totalBlue, chooseBlue);
    cout << "C(" << totalBlue << ", " << chooseBlue << ") = " << blueCombination << endl;

    // Langkah 3: Hitung total kombinasi
    cout << "\n3. Total kombinasi adalah hasil perkalian kombinasi merah dan kombinasi biru.\n";
    cout << "Total kombinasi = C(" << totalRed << ", " << chooseRed << ") * C(" << totalBlue << ", " << chooseBlue << ")\n";
    cout << "Total kombinasi = " << redCombination << " * " << blueCombination 
         << " = " << (redCombination * blueCombination) << endl;

    cout << "\nJadi, total cara untuk memilih " << chooseRed 
         << " bola merah dan " << chooseBlue << " bola biru adalah: "
         << (redCombination * blueCombination) << " cara.\n";

    return 0;
}

long long soal1C(){
long long n;

    // Penjelasan soal
    cout << "Masukkan jumlah pemain yang dapat dipilih: ";
    cin >> n;

    cout << "\nDalam memilih pemain yang akan diturunkan, urutan pemilihan tidaklah diperhatikan.\n"
         << "Jadi, yang menjadi masalah hanyalah siapa yang dipilih.\n"
         << "Tidak menjadi masalah apakah seorang pemain (katakanlah A) terpilih pertama ataupun terakhir.\n"
         << "Hal ini berbeda dengan pemilihan ketua dan wakil ketua, di mana urutan memengaruhi komposisi.\n"
         << "Jadi, banyaknya tim yang dapat dibentuk oleh pelatih tersebut adalah kombinasi " << n 
         << " objek yang diambil 5 sekaligus.\n" << endl;

    // Langkah-langkah perhitungan kombinasi
    cout << "Langkah-langkah C(" << n << ", 5):\n" << endl;

    // Langkah 1: Faktorial dari n
    cout << "1. Hitung faktorial dari n atau jumlah pemain yang dipilih (" << n << "!)\n";
    cout << n << "! = ";
    for (long long i = n; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(n) << endl;

    // Langkah 2: Faktorial dari 5
    cout << "\n2. Hitung faktorial dari 5!\n";
    cout << "5! = ";
    for (long long i = 5; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(5) << endl;

    // Langkah 3: Faktorial dari (n - 5)
    cout << "\n3. Hitung faktorial dari (n - 5) yaitu (" << n << " - 5)!\n";
    cout << (n - 5) << "! = ";
    for (long long i = n - 5; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(n - 5) << endl;

    // Langkah 4: Hitung kombinasi
    cout << "\n4. Hitung kombinasi dengan rumus C(" << n << ", 5):\n";
    cout << "C(" << n << ", 5) = " << n << "! / (" << "5! * " << n - 5 << "!)\n";
    cout << "C(" << n << ", 5) = " << factorial(n) << " / (" << factorial(5) 
         << " * " << factorial(n - 5) << ")\n";
    cout << "C(" << n << ", 5) = " << combination(n, 5) << endl;

    // Hasil akhir
    cout << "\nBanyaknya tim yang dapat dibentuk oleh pelatih adalah: " 
         << combination(n, 5) << " kemungkinan.\n" << endl;

    system("pause");
    return 0;
}

long long soal1D(){
     long long men, women, total_committee, min_men, min_women, total_ways;

    // Input jumlah pria, wanita, dan ukuran komite
    cout << "Masukkan jumlah pria: ";
    cin >> men;
    cout << "Masukkan jumlah wanita: ";
    cin >> women;
    cout << "Masukkan ukuran komite yang diinginkan: ";
    cin >> total_committee;

    // Input syarat minimum pria dan wanita
    cout << "Masukkan jumlah minimum pria dalam komite: ";
    cin >> min_men;
    cout << "Masukkan jumlah minimum wanita dalam komite: ";
    cin >> min_women;

    // Validasi syarat
    if (min_men + min_women > total_committee) {
        cout << "Syarat tidak valid: jumlah minimum pria dan wanita melebihi ukuran komite!" << endl;
        return 0;
    }

    cout << "\nAda " << men << " pria dan " << women << " wanita.\n";
    cout << "Kita ingin membentuk komite yang terdiri dari " << total_committee 
         << " orang,\ndengan syarat setidaknya " << min_men << " pria dan " << min_women 
         << " wanita dalam komite.\n" << endl;

    // Hitung jumlah total kombinasi dengan syarat
    total_ways = 0;

    // Iterasi untuk menghitung kombinasi berdasarkan syarat
    for (long long men_count = min_men; men_count <= min(total_committee, men); ++men_count) {
        long long women_count = total_committee - men_count;
        if (women_count >= min_women && women_count <= women) {
            long long men_comb = combination(men, men_count);
            long long women_comb = combination(women, women_count);

            cout << "Kombinasi pria (" << men_count << " pria dari " << men 
                 << "): " << men_comb << ", Kombinasi wanita (" << women_count 
                 << " wanita dari " << women << "): " << women_comb << endl;

            total_ways += men_comb * women_comb;
        }
    }

    // Hasil akhir
    cout << "\nJadi, banyaknya cara memilih komite yang memenuhi syarat adalah: " 
         << total_ways << " kemungkinan.\n";
}

long long soal1E(){
    long long n,total_triangles;

    // Input jumlah titik
    cout << "Masukkan jumlah titik pada lingkaran: ";
    cin >> n;

    // Validasi input
    if (n < 3) {
        cout << "Jumlah titik harus lebih dari atau sama dengan 3 untuk membentuk segitiga." << endl;
        return 0;
    }

    // Menghitung jumlah segitiga yang dapat dibentuk
    total_triangles = combination(n, 3);

    // Output hasil
    cout << "Jumlah segitiga yang dapat dibentuk dari " << n << " titik pada lingkaran adalah: " 
         << total_triangles << endl;
}

void menu2(){
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "|                   Kombinasi Dengan Pengulangan                |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "Silakan Pilih Jenis Soal: " << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "1. Keranjang berisi n jenis buah: [beberapa buah]. Seorang anak ingin memilih r buah dari keranjang tersebut, dengan kemungkinan memilih buah yang sama lebih dari sekali. Berapa banyak cara anak tersebut dapat memilih buah?" << endl;
    cout << "2. Berapa cara memilih 4 huruf dari kata \"MATEMATIKA\"?" << endl;
    cout << "Masukkan Pilihan Anda: ";
}

long long soal2A(){
   long long fruidtotal, fruidtoChoose;

    // Input jumlah jenis buah dalam keranjang
    cout << "Masukkan jumlah jenis buah dalam keranjang: ";
    cin >> fruidtotal;

    // Input jumlah buah yang akan dipilih
    cout << "Masukkan jumlah buah yang akan dipilih: ";
    cin >> fruidtoChoose;

    // Menjelaskan konteks soal
    cout << "\nDalam memilih buah dari keranjang dengan pengulangan, urutan pemilihan tidak diperhatikan. \n"
         << "Artinya, setiap buah dapat dipilih lebih dari sekali.\n"
         << "Rumus kombinasi dengan pengulangan digunakan dalam kasus ini.\n";

    // Langkah-langkah menghitung kombinasi dengan pengulangan
    cout << "\nLangkah-langkah C(" << fruidtotal + fruidtoChoose - 1 << "," << fruidtoChoose << "):\n";

    // Langkah 1: Hitung faktorial dari (fruidtotal + fruidtoChoose - 1)
    cout << "1. Hitung faktorial dari (" << fruidtotal << " + " << fruidtoChoose << " - 1) = "
        << (fruidtotal + fruidtoChoose - 1) << "!\n"
        << (fruidtotal + fruidtoChoose - 1) << "! = ";
    for (long long i = fruidtotal + fruidtoChoose - 1; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(fruidtotal + fruidtoChoose - 1) << endl;

    // Langkah 2: Hitung faktorial dari fruidtoChoose
    cout << "\n2. Hitung faktorial dari " << fruidtoChoose << " (jumlah yang dipilih)!\n";
    cout << fruidtoChoose << "! = ";
    for (long long i = fruidtoChoose; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(fruidtoChoose) << endl;

    // Langkah 3: Hitung faktorial dari (fruidtotal - 1)
    cout << "\n3. Hitung faktorial dari (" << fruidtotal << " - 1) = " << (fruidtotal - 1) << "!\n";
    cout << (fruidtotal - 1) << "! = ";
    for (long long i = fruidtotal - 1; i > 1; i--) {
        cout << i << (i > 2 ? " * " : " * 1 = ");
    }
    cout << factorial(fruidtotal - 1) << endl;

    // Langkah 4: Hitung kombinasi dengan rumus C(fruidtotal + fruidtoChoose - 1, fruidtoChoose)
    cout << "\n4. Hitung kombinasi dengan rumus C(" << fruidtotal + fruidtoChoose - 1 << "," << fruidtoChoose
         << ") = (" << fruidtotal + fruidtoChoose - 1 << "! / (" << fruidtoChoose << "! * " << (fruidtotal - 1) << "!))\n";
    cout << "C(" << fruidtotal + fruidtoChoose - 1 << "," << fruidtoChoose << ") = "
         << factorial(fruidtotal + fruidtoChoose - 1) << " / (" << factorial(fruidtoChoose) << " * "
         << factorial(fruidtotal - 1) << ") = " << combination_with_replacement(fruidtotal, fruidtoChoose) << endl;

    // Output hasil
    cout << "\nJadi, banyaknya cara untuk memilih " << fruidtoChoose << " buah dari "
         << fruidtotal << " jenis buah dengan pengulangan adalah: " << combination_with_replacement(fruidtotal, fruidtoChoose) << " kemungkinan.\n";

    return 0;
}

long long soal2B() {
    string word;
    long long choose, unique_chars = 0;
    int freq[256] = {0}; 

    // Input kata dan jumlah huruf yang dipilih
    cout << "Masukkan kata: ";
    cin >> word;

    cout << "Masukkan jumlah huruf yang akan dipilih: ";
    cin >> choose;

    // Menghitung frekuensi karakter
    for (char ch : word) {
        freq[ch]++; // Increment frekuensi untuk karakter tersebut
    }

    // Menampilkan frekuensi huruf
    cout << "\nFrekuensi huruf dalam kata \"" << word << "\":\n";
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) { // Jika karakter memiliki frekuensi > 0, itu adalah karakter unik
            cout << (char)i << ": " << freq[i] << endl;
            unique_chars++; // Tambahkan ke jumlah karakter unik
        }
    }

    // Menghitung kombinasi
    cout << "\nJumlah kombinasi yang mungkin untuk memilih " << choose 
         << " huruf dari " << unique_chars << " huruf unik: ";
    cout << combination(unique_chars, choose) << endl;

    return 0;
}


void menu3(){
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "|                Menu Kombinasi dalam Probabilitas              |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "Silakan Pilih Jenis Soal: " << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "1.Sebuah kantong berisi 10 bola yang terdiri dari 4 bola merah dan 6 bola biru. Jika 4 bola diambil secara acak tanpa pengembalian, berapa probabilitas bahwa 2 bola yang terambil adalah bola merah dan 2 bola lainnya adalah bola biru?" << endl;
    cout << "2. Dari sebuah deck kartu standar yang berisi 52 kartu, berapa probabilitas untuk menarik 5 kartu yang terdiri dari 3 kartu hati dan 2 kartu wajik?" << endl;
    cout << "Masukkan Pilihan Anda: ";
}

long long soal3A(){
    long long total_bola, bola_merah, bola_biru, bola_ambil_merah, bola_ambil_biru;

    // Input jumlah total bola, bola merah, bola biru, dan bola yang ingin diambil
    cout << "Masukkan jumlah total bola: ";
    cin >> total_bola;

    cout << "Masukkan jumlah bola merah: ";
    cin >> bola_merah;

    cout << "Masukkan jumlah bola biru: ";
    cin >> bola_biru;

    // Memastikan jumlah bola merah dan biru tidak melebihi total bola
    if (bola_merah + bola_biru > total_bola) {
        cout << "Jumlah bola merah dan biru melebihi total bola yang ada. Periksa input Anda.\n";
        return 1;
    }

    cout << "Masukkan jumlah bola merah yang ingin diambil: ";
    cin >> bola_ambil_merah;

    cout << "Masukkan jumlah bola biru yang ingin diambil: ";
    cin >> bola_ambil_biru;

    // Memastikan jumlah bola merah dan biru yang ingin diambil tidak melebihi jumlah bola yang tersedia
    if (bola_ambil_merah > bola_merah || bola_ambil_biru > bola_biru) {
        cout << "Jumlah bola yang ingin diambil tidak dapat melebihi jumlah bola yang tersedia.\n";
        return 1;
    }
    long long comb_merah = combination(bola_merah, bola_ambil_merah);
    long long comb_biru = combination(bola_biru, bola_ambil_biru);
    long long comb_total = combination(total_bola, bola_ambil_merah + bola_ambil_biru);
    // Langkah 1: Hitung kombinasi memilih bola merah
    cout << "\nLangkah-langkah penyelesaian:\n";
    cout << "1. Menghitung kombinasi untuk memilih " << bola_ambil_merah << " bola merah dari " << bola_merah << " bola merah.\n";
    cout << "C(" << bola_merah << ", " << bola_ambil_merah << ") = " << comb_merah << endl;

    // Langkah 2: Hitung kombinasi memilih bola biru
    cout << "2. Menghitung kombinasi untuk memilih " << bola_ambil_biru << " bola biru dari " << bola_biru << " bola biru.\n";
    cout << "C(" << bola_biru << ", " << bola_ambil_biru << ") = " << comb_biru << endl;

    // Langkah 3: Hitung total kombinasi memilih bola dari total bola
    cout << "3. Menghitung kombinasi untuk memilih " << bola_ambil_merah + bola_ambil_biru << " bola dari " << total_bola << " total bola.\n";
    cout << "C(" << total_bola << ", " << bola_ambil_merah + bola_ambil_biru << ") = " << comb_total << endl;

    // Langkah 4: Hitung probabilitas
    double probabilitas = (double)(comb_merah * comb_biru) / comb_total;
    cout << "4. Probabilitas memilih " << bola_ambil_merah << " bola merah dan " << bola_ambil_biru << " bola biru = (C(" 
        << bola_merah << ", " << bola_ambil_merah << ") * C(" << bola_biru << ", " << bola_ambil_biru << ")) / C(" 
         << total_bola << ", " << bola_ambil_merah + bola_ambil_biru << ")\n";
    cout << "P(" << bola_ambil_merah << " merah, " << bola_ambil_biru << " biru) = " << comb_merah << " * " << comb_biru << " / " 
        << comb_total << " = " << probabilitas << endl;
    return 0;
}

long long soal3b() {
     long long total_kartu = 52;
    long long hati = 13, wajik = 13, sekop = 13, keriting = 13; // Masing-masing jenis kartu
    long long kartu_ambil_hati, kartu_ambil_wajik, kartu_ambil_sekop, kartu_ambil_keriting;
    long long total_ambil;

    // Input jumlah kartu yang ingin diambil dari masing-masing jenis
    cout << "Masukkan jumlah kartu hati yang ingin diambil: ";
    cin >> kartu_ambil_hati;

    cout << "Masukkan jumlah kartu wajik yang ingin diambil: ";
    cin >> kartu_ambil_wajik;

    cout << "Masukkan jumlah kartu sekop yang ingin diambil: ";
    cin >> kartu_ambil_sekop;

    cout << "Masukkan jumlah kartu keriting yang ingin diambil: ";
    cin >> kartu_ambil_keriting;

    // Total kartu yang ingin diambil
    total_ambil = kartu_ambil_hati + kartu_ambil_wajik + kartu_ambil_sekop + kartu_ambil_keriting;

    // Memastikan jumlah kartu yang diambil tidak melebihi jumlah kartu dari setiap jenis
    if (kartu_ambil_hati > hati || kartu_ambil_wajik > wajik || kartu_ambil_sekop > sekop || kartu_ambil_keriting > keriting) {
        cout << "Jumlah kartu yang ingin diambil tidak boleh melebihi jumlah kartu yang tersedia pada setiap jenis.\n";
        return 1;
    }

    long long comb_hati = combination(hati, kartu_ambil_hati);
    long long comb_wajik = combination(wajik, kartu_ambil_wajik);
    long long comb_sekop = combination(sekop, kartu_ambil_sekop);
    long long comb_keriting = combination(keriting, kartu_ambil_keriting);
    long long comb_total = combination_n(total_kartu, total_ambil);

    // Langkah-langkah penyelesaian
    cout << "\nLangkah-langkah penyelesaian:\n";
    cout << "1. Menghitung kombinasi untuk memilih " << kartu_ambil_hati << " kartu hati dari 13 kartu hati.\n";
    cout << "C(" << hati << ", " << kartu_ambil_hati << ") = " << comb_hati << endl;

    cout << "2. Menghitung kombinasi untuk memilih " << kartu_ambil_wajik << " kartu wajik dari 13 kartu wajik.\n";
    cout << "C(" << wajik << ", " << kartu_ambil_wajik << ") = " << comb_wajik << endl;

    cout << "3. Menghitung kombinasi untuk memilih " << kartu_ambil_sekop << " kartu sekop dari 13 kartu sekop.\n";
    cout << "C(" << sekop << ", " << kartu_ambil_sekop << ") = " << comb_sekop << endl;

    cout << "4. Menghitung kombinasi untuk memilih " << kartu_ambil_keriting << " kartu keriting dari 13 kartu keriting.\n";
    cout << "C(" << keriting << ", " << kartu_ambil_keriting << ") = " << comb_keriting << endl;

    cout << "5. Menghitung kombinasi untuk memilih " << total_ambil << " kartu dari " << total_kartu << " kartu total.\n";
    cout << "C(" << total_kartu << ", " << total_ambil << ") = " << comb_total << endl;

    // Hitung probabilitas
    double probabilitas = (double)(comb_hati * comb_wajik * comb_sekop * comb_keriting) / comb_total;
    cout << "6. Probabilitas untuk memilih " << kartu_ambil_hati << " kartu hati, " << kartu_ambil_wajik << " kartu wajik, " 
         << kartu_ambil_sekop << " kartu sekop, dan " << kartu_ambil_keriting << " kartu keriting = (C(" 
         << hati << ", " << kartu_ambil_hati << ") * C(" << wajik << ", " << kartu_ambil_wajik << ") * C(" 
         << sekop << ", " << kartu_ambil_sekop << ") * C(" << keriting << ", " << kartu_ambil_keriting 
         << ")) / C(" << total_kartu << ", " << total_ambil << ")\n";
    cout << "P(" << kartu_ambil_hati << " hati, " << kartu_ambil_wajik << " wajik, " << kartu_ambil_sekop << " sekop, " 
         << kartu_ambil_keriting << " keriting) = " << comb_hati << " * " << comb_wajik << " * " 
         << comb_sekop << " * " << comb_keriting << " / " << comb_total << " = " << probabilitas << endl;
}

void menu4(){
cout << "+---------------------------------------------------------------+" << endl;
cout << "|                   Menu Kombinasi dengan Batasan               |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "Silakan Pilih Jenis Soal: " << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "\n1. Suatu perusahaan memiliki nl karyawan laki-laki dan np karyawan wanita. \nPimpinan perusahaan akan memilih nc orang di antaranya untuk bersama-sama mengerjakan suatu proyek. \nBerapa banyak tim yang dapat ia bentuk apabila di dalam tim tersebut harus paling sedikit terdapat 1 karyawan laki-laki?" << endl;
    cout << "\n2. Suatu perusahaan memiliki nl orang karyawan laki-laki dan np karyawan wanita. \nPimpinan perusahaan akan memilih nc orang di antaranya untuk bersama-sama mengerjakan suatu proyek. \nBerapa banyak tim yang dapat ia bentuk apabila di dalam tim tersebut harus paling banyak terdapat 1 karyawan laki-laki?" << endl;
    cout << "\n3. Andi memiliki nj jenis buah, yaitu apel, jeruk, pisang, mangga, dan anggur. Tono ingin membeli nb buah dengan batasan bahwa Tono tidak boleh membeli lebih dari 3 buah dari setiap jenis." << endl;
}

long long soal4A(){
    long long totalLakiLaki, totalWanita, jumlahDipilih;
    
    // Input jumlah total laki-laki, wanita dan jumlah yang dipilih
    cout << "Masukkan jumlah total karyawan laki-laki: ";
    cin >> totalLakiLaki;
    
    cout << "Masukkan jumlah total karyawan wanita: ";
    cin >> totalWanita;
    
    cout << "Masukkan jumlah total karyawan yang akan dipilih: ";
    cin >> jumlahDipilih;
    
    long long totalTimLangsung = 0; // Menyimpan jumlah tim valid
    long long totalTimTidakLangsung;

    cout << "Ada dua cara utuk menghitung kombinasi yang mungkin untuk memilih " << jumlahDipilih << " orang dari " << totalLakiLaki << " laki-laki dan " << totalWanita << " wanita dengan syarat paling sedikit 1 Pria.\n";
    cout << "Yaitu dengan: \n\nCara Langsung dan Cara Tidak Langsung.\n\n";
    cout << "--Dengan cara langsung menggunakan aturan penjumlahan" << endl;
    cout << "--Dengan cara tidak langsung yaitu dengan menghitung komplemennya" << endl;

    cout << "Berdasarkan jumlah karyawan laki-laki, ada " << totalLakiLaki + 1 << " kemungkinan tim yang mungkin dibentuk." << totalLakiLaki << "kotak terakhir adalah tim yang memuat paling sedikit 1 karyawan laki laki" << endl;
    
    // Langkah 1: Cara Langsung
    cout << "\nLangkah-Langkah Perhitungan Cara Langsung:\n";
    for (long long lakiLakiDipilih = 1; lakiLakiDipilih <= jumlahDipilih; ++lakiLakiDipilih) {
        long long wanitaDipilih = jumlahDipilih - lakiLakiDipilih;

        if (wanitaDipilih <= totalWanita && lakiLakiDipilih <= totalLakiLaki) {
            cout << "- Memilih " << lakiLakiDipilih << " laki-laki dan " << wanitaDipilih << " wanita: ";
            long long kombinasiLakiLaki = combination(totalLakiLaki, lakiLakiDipilih);
            long long kombinasiWanita = combination(totalWanita, wanitaDipilih);
            cout << "C(" << totalLakiLaki << ", " << lakiLakiDipilih << ") * C(" 
                << totalWanita << ", " << wanitaDipilih << ") = "
                << kombinasiLakiLaki << " * " << kombinasiWanita << " = "
                << kombinasiLakiLaki * kombinasiWanita << endl;
            totalTimLangsung += kombinasiLakiLaki * kombinasiWanita;
        }
    }

    cout << "\nJumlah tim yang dapat dibentuk dengan cara langsung: " << totalTimLangsung << endl;

    // Langkah 2: Cara Tidak Langsung
    cout << "\nLangkah-Langkah Perhitungan Cara Tidak Langsung:\n";
    cout << "- Menghitung total semua kemungkinan tim tanpa syarat: ";
    long long totalSemuaTim = combination(totalLakiLaki + totalWanita, jumlahDipilih);
    cout << "C(" << totalLakiLaki + totalWanita << ", " << jumlahDipilih << ") = "
        << totalSemuaTim << endl;

    cout << "- Menghitung kemungkinan tim yang terdiri dari hanya wanita (komplemen): ";
    long long semuaWanita = combination(totalWanita, jumlahDipilih);
    cout << "C(" << totalWanita << ", " << jumlahDipilih << ") = " << semuaWanita << endl;

    totalTimTidakLangsung = totalSemuaTim - semuaWanita;
    cout << "- Jumlah tim dengan paling sedikit 1 laki-laki: "
        << totalSemuaTim << " - " << semuaWanita << " = " << totalTimTidakLangsung << endl;

    // Menampilkan hasil akhir dari kedua metode
    cout << "\nHasil Akhir:\n";
    cout << "- Total tim menggunakan cara langsung: " << totalTimLangsung << endl;
    cout << "- Total tim menggunakan cara tidak langsung: " << totalTimTidakLangsung << endl;

    return 0;
}

long long soal4B() {
    long long totalLakiLaki, totalWanita, jumlahDipilih; // Jumlah laki-laki, wanita, dan jumlah yang dipilih
    
    // Input jumlah total laki-laki, wanita, dan yang dipilih
    cout << "Masukkan jumlah total karyawan laki-laki: ";
    cin >> totalLakiLaki;
    cout << "Masukkan jumlah total karyawan wanita: ";
    cin >> totalWanita;
    cout << "Masukkan jumlah total karyawan yang akan dipilih: ";
    cin >> jumlahDipilih;

    // Perhitungan kombinasi
    long long tanpaLakiLaki = combination(totalWanita, jumlahDipilih); // Tim tanpa laki-laki
    long long satuLakiLaki = combination(totalLakiLaki, 1) * combination(totalWanita, jumlahDipilih - 1); // Tim dengan 1 laki-laki

    // Total tim dengan paling banyak 1 laki-laki
    long long totalTim = tanpaLakiLaki + satuLakiLaki;

    // Output hasil perhitungan
    cout << "\nTim yang beranggotakan paling banyak 1 karyawan laki-laki berarti tim tersebut:\n";
    
    // Output untuk tim tanpa karyawan laki-laki
    cout << "- Tanpa karyawan laki-laki: C(" << totalWanita << ", " << jumlahDipilih << ") = "
         << totalWanita << "!/(" << jumlahDipilih << "!*" << totalWanita - jumlahDipilih << "!) = " 
         << factorial(totalWanita) << "/(" << factorial(jumlahDipilih) << "*" << factorial(totalWanita - jumlahDipilih) << ") = "
         << tanpaLakiLaki << endl;

    // Output untuk tim dengan 1 karyawan laki-laki
    cout << "- Dengan 1 karyawan laki-laki (sisa wanita):\n";
    cout << "  C(" << totalLakiLaki << ", 1) = " << totalLakiLaki << "!/(" << 1 << "!*" << totalLakiLaki - 1 << "!) = "
         << factorial(totalLakiLaki) << "/(" << factorial(1) << "*" << factorial(totalLakiLaki - 1) << ") = " 
         << combination(totalLakiLaki, 1) << endl;
    cout << "  C(" << totalWanita << ", " << jumlahDipilih - 1 << ") = " << totalWanita << "!/(" 
         << jumlahDipilih - 1 << "!*" << totalWanita - (jumlahDipilih - 1) << "!) = "
         << factorial(totalWanita) << "/(" << factorial(jumlahDipilih - 1) << "*" << factorial(totalWanita - (jumlahDipilih - 1)) << ") = "
         << combination(totalWanita, jumlahDipilih - 1) << endl;
    cout << "  Hasil: " << combination(totalLakiLaki, 1) << " * " << combination(totalWanita, jumlahDipilih - 1) << " = " 
         << satuLakiLaki << endl;

    // Output total tim
    cout << "Total tim yang dapat dibentuk dengan paling banyak 1 karyawan laki-laki: " << totalTim << endl;

    return 0;
}

long long soal4C() {
    long long totalJenisBuah, jumlahDipilih, batasMaxPerJenis;
    
    // Input jumlah total jenis buah, jumlah yang dipilih, dan batasan maksimal per jenis
    cout << "Masukkan jumlah total jenis buah: ";
    cin >> totalJenisBuah;
    
    cout << "Masukkan jumlah buah yang ingin dipilih: ";
    cin >> jumlahDipilih;
    
    cout << "Masukkan batas maksimal buah per jenis: ";
    cin >> batasMaxPerJenis;

    // Menghitung kombinasi terbatas dengan pengulangan
    long long totalCara = bounded_combination(totalJenisBuah, jumlahDipilih, batasMaxPerJenis);

    // Output hasil
    cout << "Total cara memilih " << jumlahDipilih << " buah dengan batasan maksimal " 
         << batasMaxPerJenis << " buah per jenis: " << totalCara << endl;
}


void menu5(){
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "|              Menu Kombinasi dan Koefisien Binomial            |" << endl;
    cout << "+---------------------------------------------------------------+" << endl;
    cout << "Silakan Pilih Jenis Soal: " << endl;
    cout << "0. Back to Main Menu" << endl;
    cout << "1. Tentukan ekspansi dari (x+y)^n menggunakan rumus binomial." << endl;
    cout << "2. Tentukan ekspansi dari (2x+3y)^n menggunakan rumus binomial." << endl;
    cout << "2. Tentukan koefesien suku ke 2 dari (2x+3y)^n menggunakan rumus binomial." << endl;
    cout << "Masukkan Pilihan Anda: ";
}

int soal5AB(){
     long long n, coeff_x, coeff_y;
    string a_var, b_var;

    // Input untuk ekspansi binomial
    cout << "Masukkan nilai n untuk ekspansi (a + b)^n: ";
    cin >> n;
    cout << "Masukkan koefisien untuk variabel a (misalnya koefisien untuk x): ";
    cin >> coeff_x;
    cout << "Masukkan koefisien untuk variabel b (misalnya koefisien untuk y): ";
    cin >> coeff_y;
    cout << "Masukkan variabel untuk a (misalnya 'x'): ";
    cin >> a_var;
    cout << "Masukkan variabel untuk b (misalnya 'y'): ";
    cin >> b_var;

    // Menampilkan ekspansi binomial
    binomialExpansionWithExplanation(n, coeff_x, coeff_y, a_var, b_var);
}


long long soal5c() {
    long long n, coeff_a, coeff_b, k;
    string var_a, var_b;

    // Input untuk ekspansi binomial
    cout << "Masukkan nilai n untuk ekspansi (a + b)^n: ";
    cin >> n;

    cout << "Masukkan koefisien untuk variabel a (misalnya koefisien untuk x): ";
    cin >> coeff_a;

    cout << "Masukkan koefisien untuk variabel b (misalnya koefisien untuk y): ";
    cin >> coeff_b;

    cout << "Masukkan variabel untuk a (misalnya 'x'): ";
    cin >> var_a;

    cout << "Masukkan variabel untuk b (misalnya 'y'): ";
    cin >> var_b;

    // Input suku ke-k untuk mencari koefisiennya
    cout << "Masukkan suku ke-berapa yang ingin dihitung koefisiennya (k): ";
    cin >> k;

    // Validasi input
    if (k < 1 || k > n) {
        cout << "Nilai k tidak valid! Harus antara 1 dan " << n << "." << endl;
        return 1;  // Mengembalikan 1 untuk indikasi error
    }

    // Menghitung koefisien untuk suku ke-(k-1) karena binomial dimulai dari k=0
    long long coef = binomialCoefficient(n, k - 1, coeff_a, coeff_b);  // Menghitung koefisien suku ke-(k-1)

    // Menampilkan hasil koefisien
    cout << "Koefisien untuk suku ke-" << k << " dalam ekspansi (" << coeff_a << var_a << " + " << coeff_b << var_b << ")^" << n << " adalah: " << coef << endl;

    return 0;  // Mengembalikan 0 sebagai indikasi sukses
}

long long soal5D(){
    long long n, k;
    double prob;
    char event_choice;

    // Input jumlah percobaan (lemparan)
    cout << "Masukkan jumlah lemparan (n): ";
    cin >> n;

    // Input jenis event yang ingin dihitung (gambar atau kepala)
    cout << "Pilih event yang ingin dihitung probabilitasnya (g untuk gambar, k untuk kepala): ";
    cin >> event_choice;

    // Input jumlah keberhasilan yang ingin dihitung (k)
    cout << "Masukkan jumlah keberhasilan (jumlah gambar atau kepala) yang ingin dihitung: ";
    cin >> k;

    // Probabilitas gambar (p) dan kepala (1-p) secara otomatis diasumsikan 0.5
    double p = 0.5;

    // Menampilkan langkah-langkah pengerjaan
    cout << "\nLangkah-langkah perhitungan:" << endl;
    cout << "1. Tentukan parameter distribusi binomial:" << endl;
    cout << "   - n = " << n << " (jumlah lemparan)" << endl;
    cout << "   - p = " << p << " (probabilitas " << (event_choice == 'g' ? "gambar" : "kepala") << ")" << endl;
    cout << "   - k = " << k << " (jumlah " << (event_choice == 'g' ? "gambar" : "kepala") << " yang diinginkan)" << endl;

    cout << "\n2. Gunakan rumus distribusi binomial:" << endl;
    cout << "   P(X = " << k << ") = C(" << n << "," << k << ") * p^" << k << " * (1-p)^" << (n-k) << endl;

    // Menghitung kombinasi
    long long comb = combination(n, k);
    cout << "   C(" << n << "," << k << ") = " << comb << endl;

    // Menghitung probabilitas menggunakan fungsi binomial_probability
    prob = binomial_probability(n, k, p);
    cout << "   P(X = " << k << ") = " << comb << " * (" << p << ")^" << k << " * (" << (1 - p) << ")^" << (n - k) << endl;
    
    // Menampilkan hasil akhir
    cout << "\n3. Probabilitas untuk mendapatkan tepat " << k << " " << (event_choice == 'g' ? "gambar" : "kepala") << " adalah: " << prob << endl;
}

int main() {
    int chooseMateri;
    do {
        system("cls");
        menuutama();
        cin >> chooseMateri;
        switch (chooseMateri) {
            case 0:
                system("cls");
                cout << "Exit Program" << endl;
                break;

            case 1: {
                int chooseJenisSoal1;
                do {
                    system("cls");
                    menu1();
                    cin >> chooseJenisSoal1;
                    switch (chooseJenisSoal1) {
                        case 0:
                            system("cls");
                            break;

                        case 1:
                            system("cls");
                            soal1A();                        
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            soal1B();
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            soal1C();
                            system("pause");
                            break;

                        case 4:
                            system("cls");
                            soal1D();
                            system("pause");
                            break;

                        case 5:
                            system("cls");
                            soal1E();
                            system("pause");
                            break;

                        default:
                            cout << "Your choice not valid" << endl;
                            break;
                    }
                } while (chooseJenisSoal1 != 0);
                break;
            }

            case 2: {
                int chooseJenisSoal2;
                do {
                    system("cls");
                    menu2();
                    cin >> chooseJenisSoal2;
                    switch (chooseJenisSoal2) {
                        case 0:
                            break;

                        case 1:
                            system("cls");
                            soal2A();
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            soal2B();
                            system("pause");
                            break;

                        default:
                            cout << "Your choice not valid" << endl;
                            break;
                    }
                } while (chooseJenisSoal2 != 0);
                break;
            }

            case 3: {
                int chooseJenisSoal3;
                do {
                    system("cls");
                    menu3();
                    cin >> chooseJenisSoal3;
                    switch (chooseJenisSoal3) {
                        case 0:
                            system("cls");
                            break;

                        case 1:
                            system("cls");
                            soal3A();
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            soal3b();
                            system("pause");
                            break;

                        default:
                            cout << "Your choice not valid" << endl;
                            break;
                    }
                } while (chooseJenisSoal3 != 0);
                break;
            }

            case 4: {
                int chooseJenisSoal4;
                do {
                    system("cls");
                    menu4();
                    cin >> chooseJenisSoal4;
                    switch (chooseJenisSoal4) {
                        case 0:
                            system("cls");
                            break;

                        case 1:
                            system("cls");
                            soal4A();
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            soal4B();
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            soal4C();
                            system("pause");
                            break;

                        default:
                            cout << "Your choice not valid" << endl;
                            break;
                    }
                } while (chooseJenisSoal4 != 0);
                break;
            }

            case 5: {
                int chooseJenisSoal5;
                do {
                    system("cls");
                    menu5();
                    cin >> chooseJenisSoal5;
                    switch (chooseJenisSoal5) {
                        case 0:
                            system("cls");
                            break;

                        case 1:
                            system("cls");
                            soal5AB();
                            system("pause");
                            break;

                        case 2:
                            system("cls");
                            soal5AB();
                            system("pause");
                            break;

                        case 3:
                            system("cls");
                            soal5c();
                            system("pause");
                            break;

                        case 4:
                            system("cls");
                            soal5D();
                            system("pause");
                            break;

                        default:
                            cout << "Your choice not valid" << endl;
                            break;
                    }
                } while (chooseJenisSoal5 != 0);
                break;
            }

            default:
                cout << "Your choice not valid" << endl;
                break;
        }
    } while (chooseMateri != 0);

    return 0;
}