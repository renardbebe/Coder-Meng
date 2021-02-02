class Foo {
private:
  bool firstDone, secondDone;
  mutex mtx;
  condition_variable firstCv, secondCv;
public:
  Foo() {
    firstDone = false;
    secondDone = false;
  }

  void first(function<void()> printFirst) {
    std::unique_lock<std::mutex> lk(mtx); // RAII lock
    printFirst();
    // first_done.release();
    firstDone = true;
    firstCv.notify_one();
  }

  void second(function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(mtx); // RAII lock
    firstCv.wait(lk, [=] { return firstDone; });
    firstDone = false;
    // first_done.acquire();
    printSecond();
    secondDone = true;
    secondCv.notify_one();
  }

  void third(function<void()> printThird) {
    std::unique_lock<std::mutex> lk(mtx); // RAII lock
    secondCv.wait(lk, [=] { return secondDone; });
    secondDone = false;
    // second_done.acquire();
    printThird();
  }
};