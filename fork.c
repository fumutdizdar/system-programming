#include <unistd.h>
int main(void)
{
    pid_t pid; //process idsi
    pid = fork();
    //Bu satır ile artık iki ayrı iş parçacığı (process)
    //oluşmuştur. Birisi parent birisi de child.
    //ikisi de aşağıdaki kodları çalıştırarak devam edecek.
    
    //iyi de, o zaman burası parent mi, child mi?
    if(pid == 0){ //pid değeri 0 ise childdır.
        printf("Child>>Hi, I am child with pid=%d\n", getpid() );
        sleep(3);
        printf("Child>>Ok I am done..\n");
    }
    
    if(pid > 0){ //processid 0 dan farklı ise parent processtir.
        printf("I am parent and will wait until that bastard %d finishes\n", pid);
        int status;
        wait(&status);
        //status değişkeni gerçek geri dönüş değerini tutuyor
        //ama bizim exit ile gönderdiğimiz sayı, 8.bitten itibaren tutuluyor
        //o yüzden 8 kez sağa kaydırıyoruz.
        printf("Finally, the child died %d", status>>8);         
    }
    //Bu geri dönüş kodunu hem parent hem de child kullanıyor.
    //yani child da geri dönerken 50, parent da çıkışta 50 değeri üretiyor
    exit(50);
}
