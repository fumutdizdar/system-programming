#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int i = 1919;

void* foo(void* gelenPointer){

  //void pointer geldiğinden, compilera bu gelen void pointerın
  //aslında int pointer olduğunu söylüyoruz
  int* intPtr = (int*)gelenPointer;
  //int pointerın gösterdiği yerdeki veriyi alıyoruz
  int bellektekiDeger = *intPtr;
  printf("thread çalışıyor. %d sn bekleyecek\n", bellektekiDeger);

  //bu yukarıdaki 3 satır aşağıdaki yerine
  //1 satır kullanılabilirdi.
  //printf("thread çalışıyor. %d sn bekleyecek\n", *((int *)gelenPointer));
  
  //global değişkenleri değiştirebilir iş parçacıkları
  i = 1923;
  
  //fonksiyona gelen parametre kadar uyu
  sleep(bellektekiDeger); 
  pthread_exit(0);
}

int main(void){
  pthread_t threadNumarasi;

  int fonksiyonParametresi = 3;
  pthread_create(&threadNumarasi, NULL, foo, &fonksiyonParametresi);

  printf("Ana program simdi threadin bitmesini bekleyecek\n");
  //aşağıdaki kod threadin tamamlanmasını bekler
  pthread_join(threadNumarasi, NULL);

  printf("Thread bitti. Global değeri %d olarak değiştirdi\nŞimdi de ana program bitiyor..",i);
}
