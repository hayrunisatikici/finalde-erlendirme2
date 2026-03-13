Akıllı Sistem Günlük (Log) Analiz ve Yönetim Platformu

Bu proje; sistemler tarafından üretilen karmaşık, düzensiz ve okunması zor ham log verilerini anlamlı bilgilere dönüştüren bir veri işleme mimarisidir. Yazılım, bilgisayar bilimlerinin temel taşlarından olan "Dinamik Bellek Yönetimi" ve "Bağlı Liste (Linked List)" prensiplerini kullanarak yüksek verimlilikte bir veri zinciri oluşturur.

Projenin Temel Misyonu

Modern işletim sistemleri saniyeler içinde binlerce satır log üretir. Bu projenin temel amacı, bu devasa veri akışı içinden sadece mesaj içeriğini ayıklamak, veriyi standart bir zaman formatına sokmak ve bu bilgileri sistem kaynaklarını (RAM) yormadan esnek bir şekilde hafızada muhafaza etmektir.

Mimari ve Çalışma Prensipleri

1. Dinamik Veri Yapılandırması
Geleneksel yöntemlerde veriler sabit boyutlu dizilerde tutulur, bu da hafıza israfına yol açar. Bu projede ise "Bağlı Liste" mimarisi kullanılmıştır.
Her bir kayıt, bir önceki kayda görünmez bir bağ ile tutunur.
Yeni bir hata veya mesaj geldiğinde hafızada sadece o mesaj kadar yer açılır.
Bu yöntem, sistemin ölçeklenebilir olmasını sağlar.

2. Ham Veri İşleme ve Temizleme Modülü
Sistem, girdi olarak aldığı ham metin yığınlarını bir süzgeçten geçirir. Örneğin; standart bir sistem günlüğünün başında yer alan eski tarih bilgileri (Mart 10, 08:30 gibi) otomatik olarak tespit edilir ve mesajın özünden ayrıştırılır. Böylece sadece kullanıcıyı ilgilendiren "Mesaj İçeriği" korunur.

3. Gerçek Zamanlı (Real-Time) Damgalama
Ayıklanan mesajlar, o anki sistem saatiyle yeniden eşleştirilir. Proje; saniye hassasiyetinde güncel zamanı yakalar ve bunu insan odaklı bir formatta (Örn: "13 Mart 2026, Cuma - 17:30:45") kayda işler. Bu, geçmişe dönük analizlerde yüksek doğruluk sağlar.

4. Güvenli Bellek Tahliyesi
Yazılımın en kritik özelliklerinden biri "Hafıza Sızıntısı (Memory Leak)" korumasıdır. İşlem tamamlandığında, oluşturulan tüm veri zinciri tek tek taranarak bilgisayarın RAM'inden temizlenir. Bu, uzun süreli çalışan sistemlerde şişme ve donma problemlerini önler.

İşlem Akış Şeması
Giriş: Ham log dizisinin sisteme beslenmesi.
Analiz: Mesajın başındaki gereksiz karakterlerin kırpılması.
Yapılandırma: Mesajın "Kayıt Düğümü" adı verilen dijital zarfa yerleştirilmesi.
Zamanlama: O anki takvim ve saat bilgisinin zarfa mühürlenmesi.
Bağlama: Yeni zarfın, mevcut veri zincirinin sonuna eklenmesi.
Raporlama: Tüm zincirin temiz ve sıralı bir tablo halinde kullanıcıya sunulması.
İmha: Görev bitiminde kullanılan tüm dijital kaynakların serbest bırakılması.

Teknik Avantajlar ve Verimlilik
Düşük Kaynak Tüketimi: Sadece aktif kayıtlar için hafıza harcar.
Hız: Veri ekleme işlemleri, listelerin dinamik yapısı sayesinde anlık gerçekleşir.
Esneklik: Kayıt sayısı önceden bilinmek zorunda değildir; 5 kayıt da işleyebilir, 50.000 kayıt da.
Hata Ayıklama Dostu: Formatlanmış çıktı sayesinde sistem hataları kolayca teşhis edilir.
