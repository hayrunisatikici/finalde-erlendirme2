#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>    

/* * YAPI (STRUCT) TANIMI: KayitDugumu
 * Log mesajlarýný ve sistem tarafýndan üretilen zaman damgasýný
 * dinamik bellekte saklamak için kullanýlan yapý.
 */
struct KayitDugumu {
    char mesajIcerigi[256];   
    char damgalananZaman[100]; 
    struct KayitDugumu* sonrakiDugum; 
};

/* * FONKSÝYON: yeniKayitOlustur
 * Amacý: Bellekte yer açmak, ham verideki eski tarih kýsmýný temizlemek
 * ve o anki gerçek zamaný düðüme iþlemek.
 */
struct KayitDugumu* yeniKayitOlustur(char* hamSatir) {
    struct KayitDugumu* yeniDugum = (struct KayitDugumu*)malloc(sizeof(struct KayitDugumu));
    
    if (yeniDugum != NULL) {
        // Ham satýrdaki ilk 16 karakterlik (örneðin: "Mar 10 08:30:15") 
        // eski zaman bilgisini atlayýp sadece mesajý alýyoruz.
        if (strlen(hamSatir) > 16) {
            strcpy(yeniDugum->mesajIcerigi, &hamSatir[16]); 
        } else {
            strcpy(yeniDugum->mesajIcerigi, hamSatir);
        }
        
        // --- GERÇEK ZAMAN HESAPLAMA ---
        time_t zamanSinyali = time(NULL); 
        struct tm *zamanDetay = localtime(&zamanSinyali); 

        char *ayIsimleri[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", 
                             "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};
        char *gunIsimleri[] = {"Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi"};

        // Veriyi formatlayarak düðüm içindeki zaman dizisine kopyalýyoruz
        sprintf(yeniDugum->damgalananZaman, "%02d %s %d, %s - %02d:%02d:%02d",
                zamanDetay->tm_mday, 
                ayIsimleri[zamanDetay->tm_mon], 
                zamanDetay->tm_year + 1900, 
                gunIsimleri[zamanDetay->tm_wday],
                zamanDetay->tm_hour, 
                zamanDetay->tm_min, 
                zamanDetay->tm_sec);

        yeniDugum->sonrakiDugum = NULL; 
    }
    return yeniDugum;
}

/* * FONKSÝYON: logListesiniEkranaYazdir
 * Baðlý listeyi baþtan sona tarayarak tüm kayýtlarý formatlý yazdýrýr.
 */
void logListesiniEkranaYazdir(struct KayitDugumu* kafa) {
    printf("\n========================================================\n");
    printf("         GUNCEL VE TEMIZLENMIS SISTEM LOGLARI          \n");
    printf("========================================================\n");
    
    struct KayitDugumu* gezgin = kafa;
    int siraNo = 1;

    while (gezgin != NULL) {
        printf("%d. KAYIT DETAYI:\n", siraNo++);
        printf("   [ZAMAN] : %s\n", gezgin->damgalananZaman);
        printf("   [MESAJ] : %s\n", gezgin->mesajIcerigi);
        printf("--------------------------------------------------------\n");
        gezgin = gezgin->sonrakiDugum; 
    }
}

int main() {
    struct KayitDugumu *listeBaslangic = NULL, *listeSonu = NULL;
    
    /* * DOSYA OKUMA YERÝNE SABÝT VERÝ SETÝ:
     * Programýn bir .txt dosyasýna baðýmlý kalmamasý için verileri 
     * kodun içerisinde bir dizi olarak tanýmladýk.
     */
    char *logVerileri[] = {
        "Mar 10 08:30:15 Sistem baslatildi.",
        "Mar 10 08:31:02 Kullanici girisi yapildi: admin",
        "Mar 10 08:45:20 Ag baglantisi kesildi.",
        "Mar 10 09:00:00 Otomatik yedekleme tamamlandi.",
        "Mar 10 10:15:45 Kritik hata: Bellek yetersiz!"
    };
    int toplamKayit = 5; 

    // 2. Döngü ile Dizideki Verileri Listeye Ekleme
    int i;
    for (i = 0; i < toplamKayit; i++) {
        struct KayitDugumu* yeniKayit = yeniKayitOlustur(logVerileri[i]);
        
        if (listeBaslangic == NULL) {
            // Liste henüz boþsa ilk elemaný oluþtur
            listeBaslangic = yeniKayit;
            listeSonu = yeniKayit;
        } else {
            // Mevcut son elemanýn arkasýna ekle ve sonu güncelle
            listeSonu->sonrakiDugum = yeniKayit;
            listeSonu = yeniKayit;
        }
    }

    // 3. Kayýtlarý Ekrana Bas
    logListesiniEkranaYazdir(listeBaslangic);

    // 4. Bellek Tahliye Ýþlemi (RAM Yönetimi)
    struct KayitDugumu* silinecek;
    while (listeBaslangic != NULL) {
        silinecek = listeBaslangic;
        listeBaslangic = listeBaslangic->sonrakiDugum;
        free(silinecek);
    }

    printf("\nIslem basariyla tamamlandi. RAM temizlendi.\n");
    
    // Konsolun kapanmasýný önlemek için
    system("pause"); 
    
    return 0;
}
