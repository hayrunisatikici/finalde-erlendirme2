Sistem Günlük (Log) Yönetim Sistemi
Bu proje, bir bilgisayar sisteminde oluşan olay kayıtlarını (log) düzenli bir şekilde hafızada tutmak, eski verileri temizlemek ve güncel zaman damgalarıyla yeniden yapılandırmak amacıyla geliştirilmiş bir yazılım simülasyonudur.

Projenin Amacı
Sistemler tarafından üretilen ham veriler genellikle karmaşık ve okunması zor formatlardadır.
Bu çalışma, bu karmaşık verileri alır; içindeki gereksiz kısımları ayıklar ve her bir kaydı "Bağlı Liste" adı verilen esnek bir zincir yapısına ekleyerek kullanıcıya düzenli bir rapor sunar.

Çalışma Mantığı
Veri Ayrıştırma: Sisteme giren ham metinler taranır. Mesajın başındaki eski veya hatalı tarih bilgileri sistem tarafından otomatik olarak budanır.
Akıllı Zaman Damgası: Temizlenen mesajın yanına, işlemin gerçekleştiği andaki gerçek sistem saati; gün, ay, yıl ve saat detaylarıyla (Türkçe formatta) eklenir.
Esnek Bellek Kullanımı: Sabit bir kapasite yerine, her yeni kayıt için bilgisayar hafızasında özel bir alan açılır. Bu sayede sistem, sadece ihtiyaç duyduğu kadar kaynak tüketir.
Hafıza Temizliği (RAM Yönetimi): Program görevini tamamladığında, oluşturulan tüm kayıtlar hafızadan güvenli bir şekilde silinerek bilgisayarın yorulması önlenir.

Temel Bileşenler
Kayıt Düğümü: Her bir log mesajını ve ona ait zaman bilgisini taşıyan temel birim.
Bağlı Liste Zinciri: Kayıtların birbirine görünmez bağlarla eklenerek oluşturduğu dinamik sıra.
Zamanlayıcı Motoru: Standart sistem saatini alıp okunabilir bir metne dönüştüren modül.

Kullanım Senaryosu
Program çalıştırıldığında şu adımları izler:
Önceden tanımlanmış 5 adet ham log mesajını sıraya alır.
Her bir mesajın içeriğini ayıklar ve üzerine "13 Mart 2026, Cuma" gibi güncel bilgileri işler.
Tüm listeyi görsel bir tablo düzeninde ekrana yazdırır.
İşlem bitince kullanılan tüm sistem kaynaklarını serbest bırakır.
